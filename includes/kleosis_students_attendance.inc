<?php

/**
 * @file
 *   Kleosis Students Attendance on-screen reports
 *
*/

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
    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page.'));
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

  global $user;

  $academic_year = isset($_SESSION['ks_student_attnd_acyt_select']['academic_year']) ? $_SESSION['ks_student_attnd_acyt_select']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['ks_student_attnd_acyt_select']['term']) ? $_SESSION['ks_student_attnd_acyt_select']['term'] : variable_get('kleosis_academic_term', 'fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term,
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $build['acy_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  $academic_year,
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => $term,    // todo: maybe filter this to only show terms that exist for the attendance classes in the academic year
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 5,
    '#disabled' => !in_array('administrator', $user->roles),
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );

  $usernames = ks_get_usernames_for_display($uid);  // get the display names for this user
  $text = t('Current daily attendance totals for Student <strong>@name</strong>' . ': ', array('@name' => $usernames));

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

  $academic_year = isset($_SESSION['ks_student_attnd_acyt_select']['academic_year']) ? $_SESSION['ks_student_attnd_acyt_select']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['ks_student_attnd_acyt_select']['term']) ? $_SESSION['ks_student_attnd_acyt_select']['term'] : variable_get('kleosis_academic_term', 'fy');

  $student = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  global $base_root;
  global $user;

  if ( ($academic_year == 'all') ) {
    return array();
  }

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

//  get the "Attendance class" nids for the selected student, academic year, and term (term is currently ignored)
  $attendance_class_nids = ks_get_attendance_classes($student, $academic_year, $term);

  if (empty($attendance_class_nids)) {
    $text = t('Student <strong>@name</strong> is not enrolled in a Homework-Attendance class.', array('@name' => $name));

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

  if ($dateforviews != '_') { // $dateforviews will be an underscore if no terms actually exist for the selected academic year and term
    $build['attnd_details_view'] = array(
      '#type' => 'markup',
      '#markup' =>  views_embed_view('kleosis_attendance_totals_1', $display_id = 'default', $student, $dateforviews),
    );
  }

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

      $_SESSION['ks_student_attnd_acyt_select'] = array(
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                        );

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
function ks_get_attendance_classes($student, $academic_year, $term) {

  if ( ($academic_year == 'all') ) {
    return array();
  }

//  $daterange = ks_get_acy_term_dates($academic_year, $term);
//  $startdate = $daterange[0];
//  $enddate = $daterange[1];

  $nids_courses = array();
  $nids_classes = array();

  /* first - get students gradelevel - not currently used */

  $studentrec = ks_get_student_record($student);
  $gradelevel = $studentrec['curr_gradelevel'];

  /* next, get all Courses with course_type 'Attendance' */ // todo: just get courses for the selected academic year
  $attnda = array_keys(ks_get_course_types(), 'Attendance');  // get the Attendance course key

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'course')
  ->fieldCondition('ks_course_type', 'value', $attnda[0], '=');  // course_type = 'Attendance' from the ks_course_type_description table
//  ->fieldCondition('ks_course_gradelevel', 'value', $gradelevel, '=');  // todo: review this

  $result = $query->execute();

  if ( !empty($result) ) {
    $nids_courses = array_keys($result['node']);  // these nids will be used to filter the following query:
  }
  else {
    drupal_set_message(t('There are no attendance courses defined.'));
    return array();
  }

  /* then, get Classes referenced to Courses with course_type 'Attendance' */

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
//  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_course_ref', 'nid', $nids_courses, 'IN', 0)
  ->propertyCondition('status', 1);  // not needed, just an example...

  $result = $query->execute();

  if ( !empty($result) ) {
    $nids_classes = array_keys($result['node']);  // these nids are all the Attendance classes in the selected academic year
  }

  return $nids_classes;
}

/**
 * Provides absentee periods on-screen report (when using daily attendance)
 *
 * @return
 *   absentee periods display form
 */

function kleosis_student_absentee_periods($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = l(t('Attendance'), 'kleosis/students/attendance');
  $breadcrumb[] = t('Student Absentee Periods');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Absentee Periods'));

  $page_desc = <<<EOT
    <br/>Student absentee periods on-screen report will be provided here when using daily attendance (tbd)
        - see the Kleosis documentation for more information.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info
  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Student Absentee Periods'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );

  return $form;
}

/**
 * Provides period attendance on-screen report
 *
 * @return
 *   periods attendance display form
 */

function kleosis_student_period_attendance($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = l(t('Attendance'), 'kleosis/students/attendance');
  $breadcrumb[] = t('Student Period Attendance');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Period Attendance'));

  $page_desc = <<<EOT
    <br/>Student period attendance on-screen report will be provided here (tbd)
        - see the Kleosis documentation for more information.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info
  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Student Period Attendance'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );

  return $form;
}
