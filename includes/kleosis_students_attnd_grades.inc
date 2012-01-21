<?php
// $Id$
/**
 * @file
 * kleosis Students Attendance and Grades on-screen reports
 * Provides kleosis Students functions
*/

/**
 * Defines a student current grades placeholder tab
 *
 * @return
 *    a markup blurb...
 */
function kleosis_current_grades($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades'), 'kleosis/student/grades');
  $breadcrumb[] = t('Current Grades');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

 drupal_set_title(t('Student Current Grades'));


$page_desc = <<<EOT
    <br/>This is the kleosis_student_current_grades form.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student Current Grades'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );
drupal_goto($path = 'kleosis/student/grades/current_grades', $options = array());
return $form;
}

/**
 * Provides the daily attendance report for a student
 *
 */

function kleosis_students_attendance($form, &$form_state) {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis attendance')) ) {
    drupal_set_message(t("You currently do not have permissions to view Kleosis attendance."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message('Please select a Student by clicking on a Student link.from the Student List page.');
    drupal_goto($path = 'kleosis/students', $options = array());
  }

  $_SESSION['student']['id'] = $uid;
  $_SESSION['student']['name'] = $name;

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Attendance');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Daily Attendance'));

  $build['filter'] = kleosis_student_attnd_acyt_select_form();
  $build['#submit'][] = 'kleosis_student_attnd_acyt_select_form_submit';
  $build['list'] = kleosis_students_attendance_list();
  return $build;
}

/**
 *
 * Academic year and term selection for the Students Attendance List form
 *
 */

function kleosis_student_attnd_acyt_select_form() {

  $academic_year = variable_get('kleosis_academic_year','2011-2012');
  $term = variable_get('kleosis_academic_term','fy');
  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') .': ' . $term,
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $build['acy_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  $academic_year,
    '#disabled' => TRUE,
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => $term,
    '#disabled' => TRUE,
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 5,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );

  $text = t('Current Daily Attendance Totals for student <strong>@name</strong>: ', array('@name' => $name));

  $build['theclasses'] = array(
      '#markup' => $text,
      '#prefix' => '',
      '#suffix' => '<br/>',
    );

  return $build;
}

/**
 *
 * Students attendance list form
 *
 */

function kleosis_students_attendance_list() {

  $academic_year = variable_get('kleosis_academic_year','2011-2012');
  $term = variable_get('kleosis_academic_term','fy');
  $student = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  global $base_root;
  global $user;

  $daterange = ks_get_acy_term_dates($academic_year, $term);

  $startdate = $daterange[0];
  $enddate = $daterange[1];
  $dateforviews = $startdate . '_' . $enddate;  // append together to send to views as one argument

  $term_length = 180; // todo:  review this

  $header = array(
    'absent_reason' => 'Absent Reason',
    'total' => 'Total',
    'description' => 'Description',
  );

//  get the "attendance class" nids for the selected student, academic year, and term
//  for testing: $attendance_class_nids = array(0 => 1076);  //  Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1
  $attendance_class_nids = ks_get_attendance_class_by_gradelevel($student, $academic_year, $term);

  if (empty($attendance_class_nids)) {
    $text = t('Student <strong>@name</strong> is not enrolled in a Homework-Attendance class ', array('@name' => $name));

     $build['theclasses'] = array(
        '#markup' => $text,
        '#prefix' => '',
        '#suffix' => '<br/><br/>',
      );
    return $build;
  }

  $absence_reason = ks_get_excused_absence_reasons(); // reason id + reason
  $description = ks_get_excused_absence_descriptions(); // reason id + description
  $abs_type = 2;  // todo: look this value up (abs_type = late)
  $all_unexcused_absences_total = ks_get_student_atttendance_unexcused_absences($student, $attendance_class_nids, $daterange);
  $all_excused_absences_total = ks_get_student_atttendance_excused_absences($student, $attendance_class_nids, $daterange);
  $all_late_attendance_total = ks_get_student_atttendance_absences_by_type($student, $attendance_class_nids, $daterange, $abs_type);
  $rows = array();

  $rows[0] = array('absent_reason' => 'Unexcused absences', 'total' => $all_unexcused_absences_total, 'description' => 'Total for all unexcused absences');
  $rows[1] = array('absent_reason' => 'Excused absences', 'total' => $all_excused_absences_total, 'description' => 'Total for all excused absences');
  $rows[2] = array('absent_reason' => 'Late attendance', 'total' => $all_late_attendance_total, 'description' => 'Total for all late attendances');
  $rows[3] = array('absent_reason' => '<center>-------------------------------------------------</center>', 'total' => '<center>---------</center>', 'description' => '<center>----------------------------------------------------------------------------</center>');  // spacer row

  foreach ($absence_reason as $key => $value) {

    // get totals for each excuse reason
    $total = ks_get_student_atttendance_absences_by_reason($student, $attendance_class_nids, $daterange, $key);

    if ($total <> 0) {  // don't include if none exist
      $rows[$key+4]['absent_reason'] = ($key == 0) ? 'no reason given' : $value;
      $rows[$key+4]['total'] = $total;
      $rows[$key+4]['description'] = $description[$key];
    }
  }

  // add more totals rows

  $options = array();
  $options = $rows;

  $build['absences'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => t('There are no attendance records for this student in any class for the selected system academic year and term.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );
  $build['pager'] = array('#markup' => theme('pager'));

  $build['attnd_details_history'] = array(
    '#type' => 'markup',
    '#markup' => 'Daily Attendance details. &nbsp;&nbsp;Day column legend: &nbsp;Mon(1), Tue(2), Wed(3), Thu(4), Fri(5)',
    '#prefix' => '<br/><div style="float:left">',
    '#suffix' => '</div><br/>',
  );

  $build['attnd_details_view'] = array(
    '#type' => 'markup',
    '#markup' =>  views_embed_view('kleosis_attendance_totals_1', $display_id = 'default', $student, $dateforviews),
  );

  $build['attnd_details_edit_link'] = array(
    '#type' => 'link',
    '#title' => 'edit view :)',
    '#access' => ((in_array('administrator', $user->roles))),
    '#href' => $base_root . url('kleosis-attendance-totals-1/' . $student, array('query' => array('destination' => 'kleosis/students/summary/' . $student, array('target' => '_blank') ))),
    '#prefix' => '<div style="float:right;clear:right;width:90px">',
    '#suffix' => '</div>',
  );

 $build['attnd_details_w_filters'] = array(
    '#type' => 'link',
    '#title' => 'view with filters',
    '#access' => ((in_array('administrator', $user->roles))),
    '#href' => $base_root . url('kleosis-attendance-totals-2/' . $student, array('query' => array('destination' => 'kleosis/students/summary/' . $student, array('target' => '_blank') ))),
    '#prefix' => '<div style="float:right;width:150px">',
    '#suffix' => '</div>',
  );

  return $build;
}

/**
 *
 * Implementation of hook_submit() for the Students Attendance List form.
 *
 */
function kleosis_student_attnd_acyt_select_form_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Apply':

//      $_SESSION['ks_student_attnd_acyt_select'] = array(
//                                        'class_id' => 0,
//                                        'academic_year' => $form_state['values']['academic_year'],
//                                        'term' => $form_state['values']['term'],
//                                        );

      break;
  }
}

/**
 *
 * Get the count of each absence type
 *
 */
function ks_get_student_atttendance_absences_by_type($student, $classnids, $daterange, $abs_type) {

  $query = db_select('ks_student_attendance', 'ksstda');
  $query->addExpression('COUNT(abs_type)', 'abs_type_count');

  $query->condition('ksstda.' . 'kstu_id_fk', $student, '=');
//  $query->condition('ksstda.' . 'kclss_id_fk', (array)$classnids, 'IN');
  $query->condition('ksstda.' . 'kclss_id_fk', $classnids, 'IN');
  $query->condition('ksstda.' . 'atnd_date', $daterange, 'BETWEEN');
  $query->condition('ksstda.' . 'abs_type', $abs_type, '=');

  $thecount = $query->execute()->fetchField();

  return $thecount;
}

/**
 *
 * Get the count of each excuse_reason
 *
 */
function ks_get_student_atttendance_absences_by_reason($student, $classnids, $daterange, $excuse_reason) {

  $query = db_select('ks_student_attendance', 'ksstda');
  $query->addExpression('COUNT(excuse_reason)', 'excuse_reason_count');

  $query->condition('ksstda.' . 'kstu_id_fk', $student, '=');
//  $query->condition('ksstda.' . 'kclss_id_fk', (array)$classnids, 'IN');
  $query->condition('ksstda.' . 'kclss_id_fk', $classnids, 'IN');
  $query->condition('ksstda.' . 'atnd_date', $daterange, 'BETWEEN');
  $query->condition('ksstda.' . 'abs_type', 0, '<>'); // present
  $query->condition('ksstda.' . 'excuse_reason', $excuse_reason, '=');
//  $query->condition('ksstda.' . 'abs_type', 2, '<>'); // todo: look this value up (abs_type = late)

  $thecount = $query->execute()->fetchField();

  return $thecount;
}

/**
 *
 * Get the count of excused absences
 *
 */
function ks_get_student_atttendance_excused_absences($student, $classnids, $daterange) {

  $query = db_select('ks_student_attendance', 'ksstda');
  $query->addExpression('COUNT(excused_abs)', 'excused_abs_count');

  $query->condition('ksstda.' . 'kstu_id_fk', $student, '=');
//  $query->condition('ksstda.' . 'kclss_id_fk', (array)$classnids, 'IN');
  $query->condition('ksstda.' . 'kclss_id_fk', $classnids, 'IN');
  $query->condition('ksstda.' . 'atnd_date', $daterange, 'BETWEEN');
  $query->condition('ksstda.' . 'abs_type', 0, '<>'); // present
  $query->condition('ksstda.' . 'excused_abs', 0, '>');
  $query->condition('ksstda.' . 'abs_type', 2, '<>'); // todo: look this value up (abs_type = late)

  $thecount = $query->execute()->fetchField();

  return $thecount;
}

/**
 *
 * Get the count of unexcused absences
 *
 */
function ks_get_student_atttendance_unexcused_absences($student, $classnids, $daterange) {

  $query = db_select('ks_student_attendance', 'ksstda');
  $query->addExpression('COUNT(excused_abs)', 'excused_abs_count');

  $query->condition('ksstda.' . 'kstu_id_fk', $student, '=');
//  $query->condition('ksstda.' . 'kclss_id_fk', (array)$classnids, 'IN');
  $query->condition('ksstda.' . 'kclss_id_fk', $classnids, 'IN');
  $query->condition('ksstda.' . 'atnd_date', $daterange, 'BETWEEN');
  $query->condition('ksstda.' . 'excused_abs', 0, '=');
  $query->condition('ksstda.' . 'abs_type', 0, '<>'); // present
  $query->condition('ksstda.' . 'abs_type', 2, '<>'); // todo: look this value up (abs_type = late)

  $thecount = $query->execute()->fetchField();

  return $thecount;
}

/**
 *
 * Get the "attendance class" nids for the selected student, academic year, and term
 *
 */
function ks_get_attendance_class_by_gradelevel($student, $academic_year, $term){

  if (($academic_year == 'all') || ($term == 'all') ) {
    return array();
  }
  $daterange = ks_get_acy_term_dates($academic_year, $term);

  $startdate = $daterange[0];
  $enddate = $daterange[1];

  $nids_courses = array();
  $nids_classes = array();

  /* first - get students gradelevel  */

  $studentrec = ks_get_student_record($student);
  $gradelevel = ks_map_ks_gradelevel_to_drp($studentrec['curr_gradelevel']);  // this is too silly...

  /* next, get Courses with course_type 'attendance' */

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'course')
  ->fieldCondition('ks_course_type', 'value', 'attendance', '=') // todo: change the field name ks_course_type next reinstall...
  ->fieldCondition('ks_course_gradelevel', 'value', $gradelevel, '=');

  $result = $query->execute();

  if ( !empty($result) ) {
    $nids_courses = array_keys($result['node']);  // these nids will be used to filter the following query:
  }
  else {
    drupal_set_message(t('There are no attendance courses defined.'));
    return '';
}

  /* then, get Classes referenced to Courses with course_type 'attendance' */

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_course_ref', 'nid', $nids_courses, 'IN', 0)
  ->propertyCondition('status', 1);  // not needed, just an example...

  $result = $query->execute();

  if ( !empty($result) ) {
    $nids_classes = array_keys($result['node']);  // these nids are the 'attendance classes'
  }

//  return array(0 => 1076, 1 => 991);  // test...
  return $nids_classes;
}

/**
 * Defines a student grades placeholder tab
 *
 * @return
 *    a markup blurb...
 */
function kleosis_student_grades($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Grades');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

 drupal_set_title(t('Student Grades'));


$page_desc = <<<EOT
    <br/>This is the kleosis_student_grades form.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student Grades'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );
drupal_goto($path = 'kleosis/students/grades/current_grades', $options = array());
return $form;
}

/**
 * Provides the current grades for a student
 *
 * @return
 *   build of current grades from moodle
 */

function kleosis_student_current_grades($form, &$form_state) {

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message('Please select a Student by clicking on a Student link.from the Student List page.');
    drupal_goto($path = 'kleosis/students', $options = array());
  }

  $_SESSION['student']['id'] = $uid;
  $_SESSION['student']['name'] = $name;

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Grades');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Current Grades'));

  $build['filter'] = kleosis_student_grades_acyt_select_form();
  $build['#submit'][] = 'kleosis_student_grades_acyt_select_form_submit';
//  $build['list'] = kleosis_student_current_grades_list();

  return $build;

}

/**
 *
 * Academic year and term selection for the Students Current Grades List form
 *
 */

function kleosis_student_grades_acyt_select_form() {

  // check permissions
  global $user;
  $view_grades = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis grades')) ) {
    $view_grades = FALSE;
  }

  $academic_year = variable_get('kleosis_academic_year','2011-2012');
  $term = variable_get('kleosis_academic_term','fy');
  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  if ( !isset($_SESSION['ks_student_grades_acyt_select']['toggle_grades']) ) {  // if not set, then this is the first time into this screen - set default sesion variables

    $_SESSION['ks_student_grades_acyt_select']['toggle_grades'] = 'inactive';
  }

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term . '&nbsp; &nbsp; &nbsp; ' . t('Student') . ': ' . $name,
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $build['acy_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  $academic_year,
    '#disabled' => TRUE,
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => $term,
    '#disabled' => TRUE,
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 5,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );

  $build['grades_from_moodle'] = array(
    '#type' => 'submit',
    '#value' => t('Get current grades from Moodle gradebook'),
    '#disabled' => !$view_grades,
    '#prefix' => '<div style="float: left;clear:left; width:225px" >',
    '#suffix' => '</div>',
  );

  $grades_toggle = isset($_SESSION['ks_student_grades_acyt_select']['toggle_grades']) ? $_SESSION['ks_student_grades_acyt_select']['toggle_grades'] : 'inactive';

  if ( $grades_toggle == 'active' ) {  // get the grades from moodle

    $text = t('Current grades for student <strong>@name</strong>: ', array('@name' => $name));

    $build['thegrades'] = array(
      '#markup' => $text,
      '#prefix' => '<div style="float: left;clear:left; width:375px" >',
      '#suffix' => '</div>',
      );

    $header = array(
      'name' => array('data' => t('Username')),
      'course' => array('data' => t('Course'),),
      'grade' => array('data' => t('Current Grade (decimal)'),),
      'str_grade' => array('data' => t('Current Grade (letter)'),),
      'operations' => array('data' => t('Ops')),
    );

        $moodle_url = variable_get('kleosis_moodle_url','http://localhost/moodle');
        $grades = ws_get_grades_by_username($name);  // todo: evolve this function

        $options = array();
        $i = 0;
        if ( !empty($grades) ) {
        foreach ($grades as $key => $val) {
            if ( empty($val['error']) ) {
              $options[$i] = array('name' => $name,
                            'course' => $val['itemid'],
                            'grade' => $val['grade'],
                            'str_grade' => $val['str_grade'],
                            'operations' => 'details',
                            );
              $i++;
            }
          }
        }
        asort($options);

    $build['grades'] = array(
          '#type' => 'table',       // used for table
  //        '#type' => 'tableselect',   // used for tableselect
          '#theme' => 'table',      // used only for table
          '#header' => $header,
  //        '#options' => $options,   // used for tableselect
          '#rows' => $options,   // used for table
          '#empty' => t('No current grades are available.'),
          '#multiple' => TRUE,
          '#js_select' => TRUE,
        );
    $_SESSION['ks_student_grades_acyt_select']['toggle_grades'] = 'inactive';
  }

  return $build;
}

/**
 *
 * Implementation of hook_submit() for the Students Grades List form.
 *
 */
function kleosis_student_grades_acyt_select_form_submit($form, &$form_state) {

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];
  switch ($form_state['values']['op']) {

    case 'Apply':

//      $_SESSION['ks_student_grades_acyt_select'] = array(
//                                        'class_id' => 0,
//                                        'academic_year' => $form_state['values']['academic_year'],
//                                        'term' => $form_state['values']['term'],
//                                        'toggle_grades' => 'active',
//                                        );

      break;
    case 'Get current grades from Moodle gradebook':

      $_SESSION['ks_student_grades_acyt_select']['toggle_grades'] = 'active';
  }
}

/**
 * Provides the final grades for a student
 *
 * @return
 *   tbd
 */

function kleosis_student_final_grades($form, &$form_state) {

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message('Please select a Student by clicking on a Student link.from the Student List page.');
    drupal_goto($path = 'kleosis/students', $options = array());
  }

  $_SESSION['student']['id'] = $uid;
  $_SESSION['student']['name'] = $name;

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Final Grades');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Final Grades'));

  $build['filter'] = kleosis_student_final_grades_acyt_select_form();
  $build['#submit'][] = 'kleosis_student_final_grades_acyt_select_form_submit';
  $build['list'] = kleosis_student_final_grades_list();

  return $build;
}

/**
 *
 * Academic year and term selection for the Students Final Grades List form
 *
 */

function kleosis_student_final_grades_acyt_select_form() {

  $academic_year = isset($_SESSION['ks_student_final_grades_select_filter']['academic_year']) ? $_SESSION['ks_student_final_grades_select_filter']['academic_year'] : variable_get('kleosis_academic_year','2011-2012');
  $term = isset($_SESSION['ks_student_final_grades_select_filter']['term']) ? $_SESSION['ks_student_final_grades_select_filter']['term'] : variable_get('kleosis_academic_term','fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term . '&nbsp; &nbsp; &nbsp; ' . t('Student') . ': ' . $name,
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $build['acy_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  $academic_year,
    '#disabled' => FALSE,
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => $term,
    '#disabled' => FALSE,
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 5,
    '#disabled' => FALSE,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );

  return $build;
}


/**
 *
 * Implementation of hook_submit() for the Students Final Grades List form.
 *
 */
function kleosis_student_final_grades_acyt_select_form_submit($form, &$form_state) {

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  switch ($form_state['values']['op']) {

    case 'Apply':
//dpm('inside submit');
//dpm($form);
//dpm($form_state

      $_SESSION['ks_student_final_grades_select_filter'] = array(
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                       );
      break;
  }
}

/**
 * Provides the final grades for a student
 *
 * @return
 *   build of final grades
 */

function kleosis_student_final_grades_list() {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis grades')) ) {
    drupal_set_message(t("You currently do not have permissions to view Kleosis grades."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  $academic_year = isset($_SESSION['ks_student_final_grades_select_filter']['academic_year']) ? $_SESSION['ks_student_final_grades_select_filter']['academic_year'] : variable_get('kleosis_academic_year','2011-2012');
  $term = isset($_SESSION['ks_student_final_grades_select_filter']['term']) ? $_SESSION['ks_student_final_grades_select_filter']['term'] : variable_get('kleosis_academic_term','fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // the header contains all the fields that will be displayed in the tableselect list
  $header = array(
    'name' => array('data' => t('Username'), $name),
    'title' => 'Course',
    'final_grade' => array('data' => t('Final Grade (decimal)'), 'field' => 'ksstugrades.final_grade'),
    'final_grade_str' => array('data' => t('Final Grade (letter)'), 'field' => 'ksstugrades.final_grade_str'),
    'remarks' => array('data' => t('Remarks'), 'field' => 'ksstugrades.remarks'),
    'operations' => array('data' => t('Ops')),
  );

//  $classid = $_SESSION['kleosis_class_selected_class']['classid'];

// get all class nids for the selected academic year and term:

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_status', 'value', 'active', '=')
  ->propertyCondition('status', 1)  // not needed, just an example...
  ->fieldOrderBy('ks_class_academic_year', 'value', 'ASC');

  $result = $query->execute();

  $build = array();
  $options = array();

  if ( !empty($result) ) {

    $nids = array_keys($result['node']);
    $nodes = entity_load('node', array_keys($result['node']));

    // get the grades from the classes that the student has taken during the selected academic year and term

    $query = db_select('ks_student_course_classes', 'ksstuclass');
//    $query->innerJoin('ks_student_course_class_grades', 'ksstugrades', 'ksstugrades.ksccl_id_fk = ksstuclass.ksccl_id');
    $query->leftJoin('ks_student_course_class_grades', 'ksstugrades', 'ksstugrades.ksccl_id_fk = ksstuclass.ksccl_id');
    $query->addField('ksstuclass', 'ksccl_id');
    $query->addField('ksstuclass', 'kstu_id_fk');
    $query->addField('ksstuclass', 'kccls_id_fk');
    $query->addField('ksstugrades', 'kcclg_id');  //
    $query->addField('ksstugrades', 'final_grade');
    $query->addField('ksstugrades', 'final_grade_str');
    $query->addField('ksstugrades', 'remarks');

    $query->condition('ksstuclass.' . 'kstu_id_fk', $uid, '=');
    $query->condition('ksstuclass.' . 'kccls_id_fk', $nids, 'IN');

    $grade_records = $query->execute()->fetchAll();

    foreach($grade_records as $record) {

      $class_node = node_load($record->kccls_id_fk);
      $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
      $course_node = node_load($node_course_ref);
      $coursetitle = $course_node->title;
      $node_course_no =   $course_node->ks_course_no['und'][0]['value'];

      $options[$record->kccls_id_fk] = array(
      'name' => l($name, 'kleosis/students/summary', array('query' => array('ksopid' => $uid, 'ksop' => $name))),
      'title' =>  $node_course_no,
      'final_grade' =>  $record->final_grade,
      'final_grade_str' =>  $record->final_grade_str,
      'remarks' =>  $record->remarks,
    //   the following link re-uses the final_grades_edit_form in kleosis_grades.inc - cool!
    //   see also: kleosis_final_grades_list() in the same .inc
      'operations' => l(t('edit'), 'kleosis/grades/final_grades_edit', array('query' => array('ksopgid' => $record->kcclg_id, 'ksopcclid' => $record->ksccl_id, 'ksopcid' => $record->kccls_id_fk, 'ksopsid' => $uid, 'ksopsn' => $name, 'destination' => 'kleosis/students/grades/final_grades')))

      );
    }
  }
  asort($options);
  $build['students'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => t('No grades exist for the student for the selected academic year and term.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );

  $build['pager'] = array('#markup' => theme('pager'));

  return $build;
}