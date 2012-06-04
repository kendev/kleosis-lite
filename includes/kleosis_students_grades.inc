<?php

/**
 * @file
 *   Kleosis Students Grades on-screen reports
 *
*/

/**
 * Defines a student current grades placeholder tab
 *
 * @return
 *    redirects to the Student Current Grades page
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
    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page.'));
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

  $academic_year = variable_get('kleosis_academic_year', '2011-2012');
  $term = variable_get('kleosis_academic_term', 'fy');
  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  if ( !isset($_SESSION['ks_student_grades_acyt_select']['toggle_grades']) ) {  // if not set, then this is the first time into this screen - set default sesion variables

    $_SESSION['ks_student_grades_acyt_select']['toggle_grades'] = 'inactive';
  }

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term . '&nbsp; &nbsp; &nbsp; ' . t('Student') . ': ' . ks_get_usernames_for_display($uid),
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


    $usernames = ks_get_usernames_for_display($uid);  // get the display names for this user
    $text = t('Current grades for student <strong>@name</strong>' . ': ', array('@name' => $usernames));

    $build['thegrades'] = array(
      '#markup' => $text,
      '#prefix' => '<div style="float: left;clear:left; width:550px" >',
      '#suffix' => '</div>',
      );
// ($record->final_grade) ? number_format($record->final_grade, 2) : '',
    $header = array(
      'name' => array('data' => t('Username')),
      'course' => array('data' => t('Course'), ),
      'grade' => array('data' => t('Current Grade (decimal)'), ),
      'str_grade' => array('data' => t('Current Grade (letter)'), ),
      'operations' => array('data' => t('Ops')),
    );

        $moodle_url = variable_get('kleosis_moodle_url', 'http://localhost/moodle');
        $grades = ws_get_grades_by_username($name);  // todo: evolve this function

        $options = array();
        $i = 0;
        if ( !empty($grades) ) {
        foreach ($grades as $key => $val) {
            if ( empty($val['error']) ) {
              $options[$i] = array('name' => $name,
                            'course' => $val['itemid'],
                            'grade' => ($val['grade']) ? number_format($val['grade'], 2) : '',
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
    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page.'));
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

  $academic_year = isset($_SESSION['ks_student_final_grades_select_filter']['academic_year']) ? $_SESSION['ks_student_final_grades_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['ks_student_final_grades_select_filter']['term']) ? $_SESSION['ks_student_final_grades_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term . '&nbsp; &nbsp; &nbsp; ' . t('Student') . ': ' . ks_get_usernames_for_display($uid),
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

  $usernames = ks_get_usernames_for_display($uid);  // get the display names for this user
  $text = t('Final grades for student <strong>@name</strong>' . ': ', array('@name' => $usernames));

  $build['thegrades'] = array(
    '#markup' => $text,
    '#prefix' => '<div style="float: left;clear:left; width:550px" >',
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

  $academic_year = isset($_SESSION['ks_student_final_grades_select_filter']['academic_year']) ? $_SESSION['ks_student_final_grades_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['ks_student_final_grades_select_filter']['term']) ? $_SESSION['ks_student_final_grades_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

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
  ->fieldCondition('ks_class_status', 'value', '1', '=')  // 'Active'
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

    $attnda = array_keys(ks_get_course_types(), 'Attendance');  // get the Attendance course type key
    $lnchbrka = array_keys(ks_get_course_types(), 'Lunch-Breaktime');  // get the Lunch-Breaktime course type key

    foreach ($grade_records as $record) {

      $class_node = node_load($record->kccls_id_fk);
      $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
      $course_node = node_load($node_course_ref);
      $coursetitle = $course_node->title;
      $node_course_no =   $course_node->ks_course_no['und'][0]['value'];
      $node_course_type =   $course_node->ks_course_type['und'][0]['value'];

      if ( ($node_course_type != $attnda[0]) && ($node_course_type != $lnchbrka[0]) ) {
        $options[$record->kccls_id_fk] = array(
        'name' => l($name, 'kleosis/students/summary', array('query' => array('ksopid' => $uid, 'ksop' => $name))),
        'title' =>  $node_course_no,
        'final_grade' =>  ($record->final_grade > 0.00000) ? number_format($record->final_grade, 2) : '',
        'final_grade_str' =>  $record->final_grade_str,
        'remarks' =>  $record->remarks,
        //   the following link re-uses the final_grades_edit_form in kleosis_grades.inc - cool. See also: kleosis_final_grades_list() in the same .inc
        'operations' => l(t('edit'), 'kleosis/grades/final_grades_edit', array('query' => array('ksopgid' => $record->kcclg_id, 'ksopcclid' => $record->ksccl_id, 'ksopcid' => $record->kccls_id_fk, 'ksopsid' => $uid, 'ksopsn' => $name, 'destination' => 'kleosis/students/grades/final_grades')))
        );
      }
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