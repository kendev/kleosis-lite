<?php
// $Id$
/**
 * @file
 * kleosis View Attendance
 *
 * The kleosis_attendance_view_form provides the display of class attendance
 *
 */
$ks_libpath = drupal_get_path('module', 'kleosis');
$kslib = $ks_libpath . '/includes/kleosis_lib.inc';
require_once ($kslib);

/**
 * Build the Attendance Viewform.
 *
 * Returned form has a class selection form and a list of student/class periods for attendance
 *
 */
function kleosis_attendance_view_form($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = t('View Attendance');

  drupal_set_breadcrumb($breadcrumb);

  $build['instructor_filter'] = ks_attnd_view_instructor_filter_form($form, $form_state);
  $build['class_selection'] = ks_attnd_view_class_selection_form($form, $form_state);
  $build['attendance_input'] = kleosis_attendance_input_form($form, $form_state);
  $build['#submit'][] = 'ks_attnd_view_class_selection_form_submit';
  //$build['#submit'][] = 'ks_attnd_view_input_form_submit';
  return $build;
}

/**
 *
 * Instructor filter - filters by instructor, academic year, and term
 *
 */

function ks_attnd_view_instructor_filter_form($form, &$form_state) {

/*///////////////////////////////////
  drupal_set_message('inside ks_attnd_view_instructor_filter_form');
*/////////////////////////////////////

  // get the instructor, academic year, and term from the session variable (if any) and set the default values accordingly

  global $user;
  $instructorid = 0;
  if ( !isset($_SESSION['ks_atnd_instructor_filter']['instructorid']) ) {  // if not set, then this is the first time into this screen - set default sesion variables

    if (in_array('instructor', $user->roles)) {
      $instructorid = $user->uid;
      $_SESSION['ks_atnd_instructor_filter'] = array('instructorid' => $instructorid,
                                        'instructorname' => get_ks_username_by_id($instructorid),
                                        'academic_year' => variable_get('kleosis_academic_year', '2011-2012'),
                                        'term' => variable_get('kleosis_academic_term', 'fy'),
                                        'toggle_classes' => 'inactive',
                                        'toggle_attnd' => 'inactive',
                                       );
      }
  }

  $attnd_filter_instructorid = isset($_SESSION['ks_atnd_instructor_filter']['instructorid']) ? $_SESSION['ks_atnd_instructor_filter']['instructorid'] : 0;
  $attnd_filter_instructorname = isset($_SESSION['ks_atnd_instructor_filter']['instructorname']) ? $_SESSION['ks_atnd_instructor_filter']['instructorname'] : 'No instructor selected';
  $attnd_filter_academic_year = isset($_SESSION['ks_atnd_instructor_filter']['academic_year']) ? $_SESSION['ks_atnd_instructor_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $attnd_filter_term = isset($_SESSION['ks_atnd_instructor_filter']['term']) ? $_SESSION['ks_atnd_instructor_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

  $academic_year_values = kleosis_academic_year_values();
  unset($academic_year_values['all']);

  // create a fieldset with filter elements
  $form['instructor_filter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Instructor filter:') . ' ' . $attnd_filter_instructorname . '&nbsp; &nbsp; &nbsp; ' .
      ' Academic Year: ' . $attnd_filter_academic_year . '&nbsp; &nbsp; &nbsp; ' . 'Term: ' . $attnd_filter_term,
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['instructor_filter']['instructor'] = array(
    '#type' => 'select',
    '#title' => t('Instructor'),
    '#options' =>  array(0 => t('no instructor')) + ks_get_instructor_names(),
//    '#default_value' => $attnd_filter_instructorid ? $attnd_filter_instructorid : 0,
    '#default_value' => $attnd_filter_instructorid ? $attnd_filter_instructorid : ($instructorid ? $instructorid : 0),
    '#DANGEROUS_SKIP_CHECK' => FALSE,
    '#validated' => TRUE,
    '#disabled' => ( !in_array('instructor', $user->roles) ||  (! in_array('administrator', $user->roles)  )  ),
    '#weight' => 1,
    '#prefix' => '<div style="float: left;width:360px" >',
    '#suffix' => '</div>',
  );
  $form['instructor_filter']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  $academic_year_values,
    '#default_value' =>  !empty($attnd_filter_academic_year) ? $attnd_filter_academic_year : variable_get('kleosis_academic_year', '2011-2012'),
    '#DANGEROUS_SKIP_CHECK' => FALSE,
    '#validated' => TRUE,
    '#weight' => 9,
    '#prefix' => '<div style="float: left;width:130px" >',
    '#suffix' => '</div>',
  );
  $form['instructor_filter']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => kleosis_academic_term_values(),
    '#default_value' => !empty($attnd_filter_term) ? $attnd_filter_term : variable_get('kleosis_academic_term', 'fy'),
    '#DANGEROUS_SKIP_CHECK' => FALSE,
    '#validated' => TRUE,
    '#weight' => 11,
    '#prefix' => '<div style="float: left;width:80px" >',
    '#suffix' => '</div>',
  );
  $form['instructor_filter']['apply_instructor'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 15,
    '#prefix' => '<div style="float: right;width:200px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 *
 * Classes filters form - filters by attendance date, class, day, and period
 *
 */
function ks_attnd_view_class_selection_form($form, &$form_state) {

  $today = new DateTime('now');
  if (!isset($_SESSION['ks_atnd_class_select']['attnd_year'])) {  // if not set, then this is the first time into this screen - set default sesion variables

        $_SESSION['ks_atnd_class_select'] = array('day' => $today->format('N'),
                                          'attnd_year' => $today->format('Y'),
                                          'attnd_month' => $today->format('n'),
                                          'attnd_day' => $today->format('j'),
                                          'toggle_classes' => 'active',
                                          'toggle_attnd' => 'inactive',
                                          );
  }

  // get the instructor, academic year, and term from the session variable (if any) and set the default values accordingly
  // this is the same as in the above attnd_instructor_filter_form() - need to duplicate because the session-populated variables are local

  $attnd_filter_instructorid = isset($_SESSION['ks_atnd_instructor_filter']['instructorid']) ? $_SESSION['ks_atnd_instructor_filter']['instructorid'] : 0;
  $attnd_filter_instructorname = isset($_SESSION['ks_atnd_instructor_filter']['instructorname']) ? $_SESSION['ks_atnd_instructor_filter']['instructorname'] : 'No instructor selected';
  $attnd_filter_academic_year = isset($_SESSION['ks_atnd_instructor_filter']['academic_year']) ? $_SESSION['ks_atnd_instructor_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $attnd_filter_term = isset($_SESSION['ks_atnd_instructor_filter']['term']) ? $_SESSION['ks_atnd_instructor_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

  // get the class, day, and period values from the session variable (if any) and set the default values accordingly

  $attnd_date_year = isset($_SESSION['ks_atnd_class_select']['attnd_year']) ? $_SESSION['ks_atnd_class_select']['attnd_year'] : 1900;
  $attnd_date_month = isset($_SESSION['ks_atnd_class_select']['attnd_month']) ? $_SESSION['ks_atnd_class_select']['attnd_month'] : 01;
  $attnd_date_day = isset($_SESSION['ks_atnd_class_select']['attnd_day']) ? $_SESSION['ks_atnd_class_select']['attnd_day'] : 01;

  $attnd_select_classid = isset($_SESSION['ks_atnd_class_select']['classid']) ? $_SESSION['ks_atnd_class_select']['classid'] : 0;
//  $attnd_select_classname = isset($_SESSION['ks_atnd_class_select']['classname']) ? $_SESSION['ks_atnd_class_select']['classname'] : 'No class selected';
  $attnd_select_classname = isset($_SESSION['ks_atnd_class_select']['classname']) ? $_SESSION['ks_atnd_class_select']['classname'] : '';
  $attnd_select_day = isset($_SESSION['ks_atnd_class_select']['day']) ? $_SESSION['ks_atnd_class_select']['day'] : $today->format('N');
//  $attnd_select_period = isset($_SESSION['ks_atnd_class_select']['period']) ? $_SESSION['ks_atnd_class_select']['period'] : 'none';
  $attnd_select_period = isset($_SESSION['ks_atnd_class_select']['period']) ? $_SESSION['ks_atnd_class_select']['period'] : '';

  // get toggles

  $attnd_select_toggle_attnd = isset($_SESSION['ks_atnd_class_select']['toggle_attnd']) ? $_SESSION['ks_atnd_class_select']['toggle_attnd'] : 'inactive';
  $attnd_select_toggle_classes = isset($_SESSION['ks_atnd_class_select']['toggle_classes']) ? $_SESSION['ks_atnd_class_select']['toggle_classes'] : 'inactive';

  // Algorithm - for the logged-on instructor:
  //  - Look up all classes taught (all for admin) and load the Class select box
  //  - Look up the period hours taught for all classes and load the period-hours select box..
  //
  //if ($attnd_select_toggle_classes == 'active') {

    $class_records_lead = ks_get_attendance_schedule_records($attnd_filter_instructorid, $attnd_filter_academic_year, $attnd_filter_term, $attnd_select_day);
    $class_records_sub = ks_get_attendance_schedule_records_sub($attnd_filter_instructorid, $attnd_filter_academic_year, $attnd_filter_term, $attnd_select_day);

    if (!empty($class_records_lead)) {
      $classes_lead = get_classes_from_schedule_records($class_records_lead); // get the class names and class ids for the class select box from the Class node(s)
      $days_lead = get_days_from_schedule_records($class_records_lead);  // todo: maybe change this - should be the day from the selected attendance date
      $periods_lead = get_periods_from_schedule_records($class_records_lead);  // e.g an Attendance class normally has only one period - the same one, for all days.
                                                                               // if an instructor is assigned to two Attendance classes, then expect two periods (times)
    }
    else {
      $classes_lead = array();
      $days_lead = array();
      $periods_lead = array();
    }
    if (!empty($class_records_sub)) {
      $classes_sub = get_classes_from_schedule_records($class_records_sub); // get the class names and class ids for the class select box from the Class node(s)
      $days_sub = get_days_from_schedule_records($class_records_sub);  // todo: maybe change this - should be the day from the selected attendance date
      $periods_sub = get_periods_from_schedule_records($class_records_sub);  // e.g an Attendance class normally has only one period - the same one, for all days.
                                                                             // if an instructor is assigned to two Attendance classes, then expect two periods (times)
    }
    else {
      $classes_sub = array();
      $days_sub = array();
      $periods_sub = array();
    }

    $classes = $classes_lead + $classes_sub;
    $days = $days_lead + $days_sub;
    $periods = $periods_lead + $periods_sub;

//    dpm($classes);
//    dpm($days);
//    dpm($periods);

//}

  $default_period = 'none';
  if (sizeof($periods) == 1) { // then just get the period from the only period for the class
    foreach ($periods as $period) {
      $default_period = $period;
    }
  }

// create a datetime object from the selected attendance date, then
// get the day from the datetime object...
  $pattendd = new DateTime('now');

  $fsclassname = $attnd_select_classname;
  $fsyear = $attnd_date_year ? $attnd_date_year : $pattendd->format('Y');
  $fsmonth = $attnd_date_month ? $attnd_date_month : $pattendd->format('n');
  $fsday = $attnd_date_day ? $attnd_date_day : $pattendd->format('j');
  $fsdaystr = ks_get_day_string($attnd_select_day);
//  $fsdaystr = $pattendd->format('l');
  $fsperiod = $attnd_select_period;

  // create a fieldset with search elements
  $form['class_selection'] = array(
    '#type' => 'fieldset',
    '#title' => t('Class selection:') . ' ' . substr($fsclassname, 0, 42) . '&nbsp; &nbsp; &nbsp; ' .
    $fsmonth . '/' . $fsday . '/' . $fsyear . '&nbsp; &nbsp; &nbsp; ' .
      ' Day: ' . $fsdaystr . '&nbsp; &nbsp; &nbsp; ' . 'Period: ' . $fsperiod,
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
    $form['class_selection']['period_attnd_date'] = array(
      '#type' => 'date',
      '#title' => t('Attendance Date'),
      '#default_value' => array(
         'month' => $attnd_date_month ? $attnd_date_month : $pattendd->format('n'),
         'day' => $attnd_date_day ? $attnd_date_day : $pattendd->format('j'),
         'year' => $attnd_date_year ? $attnd_date_year : $pattendd->format('Y'),
        ),
    '#DANGEROUS_SKIP_CHECK' => FALSE,
    '#validated' => TRUE,
    '#weight' => -7,
      '#prefix' => '<div style="float: left;clear: left;width:200px" >',
      '#suffix' => '</div>',
    );

  $form['class_selection']['get_classes'] = array(
    '#type' => 'submit',
    '#value' => t('Set Date'),
    '#weight' => '-6',
    '#prefix' => '<div style="float:left;width:130px"><br/>',
    '#suffix' => '</div>',
  );

  $form['class_selection']['classes'] = array(
    '#type' => 'select',
    '#title' => t('Attendance Class'),
    '#options' =>  (($attnd_select_toggle_classes == 'active') && $classes) ? $classes : array(0 => 'no classes are scheduled for this instructor-day'),
    '#default_value' => $attnd_select_classid ? $attnd_select_classid : 0,
    '#DANGEROUS_SKIP_CHECK' => FALSE,
    '#validated' => TRUE,
    '#weight' => -4,
    '#prefix' => '<div style="float: left;clear:left;width:420px" >',
    '#suffix' => '</div>',
  );
  $form['class_selection']['dayofweek'] = array(
    '#type' => 'select',
    '#title' => t('Day'),
    '#options' =>  kleosis_dayofweek_values(),
    '#default_value' =>  $attnd_select_day ? $attnd_select_day : $pattendd->format('j'),
    '#disabled' => TRUE,
    '#DANGEROUS_SKIP_CHECK' => FALSE,
    '#validated' => TRUE,
    '#weight' => -3,
    '#prefix' => '<div style="float: left;width:130px" >',
    '#suffix' => '</div>',
  );
  $form['class_selection']['period'] = array(
    '#type' => 'select',
    '#title' => t('Period'),
    '#options' => array('none' => 'none') + $periods,
    //  '#default_value' => $attnd_select_period ? $attnd_select_period : 'none',
    '#default_value' => (sizeof($classes) == 1) ? $default_period : ($attnd_select_period ? $attnd_select_period : 'none'),
    '#DANGEROUS_SKIP_CHECK' => FALSE,
    '#validated' => TRUE,
    '#disabled' => TRUE,
    '#weight' => -1,
    '#prefix' => '<div style="float: left;width:160px" >',
    '#suffix' => '</div>',
  );
  $form['class_selection']['get_students'] = array(
    '#type' => 'submit',
    '#value' => t('Get Students'),
    '#weight' => '0',
    '#prefix' => '<div style="float:left;width:140px" ><br/>',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 *
 * Attendance input form - filters by course
 *
 */

function kleosis_attendance_input_form($form, &$form_state) {

  drupal_set_title(t('View Attendance'));

  $attnd_toggle = isset($_SESSION['ks_atnd_class_select']['toggle_attnd']) ? $_SESSION['ks_atnd_class_select']['toggle_attnd'] : 'inactive';

  if ($attnd_toggle == 'inactive') {
        $form['attendance_input']['nothing'] = array(
          '#type' => 'hidden',
          '#default_value' => 'inactive',
        );
    return $form;
  }

  $attnd_select_classid = isset($_SESSION['ks_atnd_class_select']['classid']) ? $_SESSION['ks_atnd_class_select']['classid'] : 0;
  $attnd_select_classname = isset($_SESSION['ks_atnd_class_select']['classname']) ? $_SESSION['ks_atnd_class_select']['classname'] : 'No class selected';

  if ($attnd_select_classid == 0) {
//    drupal_set_message('Please select a class from the Classes select box');
//    drupal_goto('kleosis/attendance', array());  le loop forever...
  }

  $ks_libpath = drupal_get_path('module', 'kleosis');
  $kslib = $ks_libpath . '/includes/kleosis_lib.inc';
  require_once($kslib);

// build the attendance date to the hour and period
  $attnd_select_period = isset($_SESSION['ks_atnd_class_select']['period']) ? $_SESSION['ks_atnd_class_select']['period'] : 'none';

  $hma = get_hour_and_minute_from_period($attnd_select_period);
  $attnd_select_hour = isset($hma['start_hour']) ? $hma['start_hour'] : '00';
  $attnd_select_minute = isset($hma['start_minute']) ? $hma['start_minute'] : '00';

  $attnd_select_year = isset($_SESSION['ks_atnd_class_select']['attnd_year']) ? $_SESSION['ks_atnd_class_select']['attnd_year'] : '1900';
  $attnd_select_month = isset($_SESSION['ks_atnd_class_select']['attnd_month']) ? $_SESSION['ks_atnd_class_select']['attnd_month'] : '01';
  $attnd_select_day = isset($_SESSION['ks_atnd_class_select']['attnd_day']) ? $_SESSION['ks_atnd_class_select']['attnd_day'] : '01';

  $pattnd = new DateTime($attnd_select_year . '-' . $attnd_select_month . '-' . $attnd_select_day . ' ' . $attnd_select_hour . ':' . $attnd_select_minute . ':' . '00');

  $students = ks_get_students_in_a_class($attnd_select_classid);

  if( empty($students) ) {
    $form['no_students'] = array(
      '#markup' =>    'There are no students enrolled in this attendance course.',
      '#prefix' => '<div style="float: left;clear: left;width:550px"><strong>',
      '#suffix' => '</strong></div>',
    );
    return $form;
  }

  $attnd_recs = ks_get_attendance_taken($attnd_select_classid, $pattnd);
  $attendance_is_taken = !empty($attnd_recs) ? 1 : 0;

// provide a header row for the attendance input fields

  $form['attendance_input'][' attendance_is_taken'] = array(
    '#type' => 'checkbox',
    '#title' => t('Attendance is taken'),
    '#default_value' => $attendance_is_taken,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:300px" >',
    '#suffix' => '</div>',
  );
  $form['attendance_input']['student_name'] = array(
    '#markup' =>    'Student Name',
    '#prefix' => '<div style="float: left;clear: left;width:350px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['attendance_input']['absence_type'] = array(
    '#markup' =>    'Absence Type',
    '#prefix' => '<div style="float: left;width:115px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['attendance_input']['excuse_reason'] = array(
    '#markup' =>    'Excuse Reason',
    '#prefix' => '<div style="float: left;width:140px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['attendance_input']['instructor_remarks'] = array(
    '#markup' =>    'Instructor Remarks',
    '#prefix' => '<div style="float: left;width:190px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['attendance_input']['counselor_remarks'] = array(
    '#markup' =>    'Cnslr Rem',
    '#prefix' => '<div style="float: left;width:80px"><strong>',
    '#suffix' => '</strong></div><br/><br/>',
  );
  $form['attendance_input']['spacer'] = array(
    '#markup' =>    '&nbsp;',
    '#prefix' => '<div style="float: left;clear: left;width:60px"><strong>',
    '#suffix' => '</strong></div>',
  );

// for each student in students, call function ks_get_attendance_records($studentid, $classid, $attendance_date)

  $i = 1;
  foreach ($students as $student) {

  $attnd_rec =  ks_get_attendance_records($student->kstu_id_fk, $attnd_select_classid, $pattnd);
  $student_names = ks_get_usernames_for_display($student->kstu_id_fk);

    $form['attendance_input']['ksatnd_id_' . $i] = array(
      '#type' => 'hidden',
      '#default_value' => isset($attnd_rec['ksatnd_id']) ? $attnd_rec['ksatnd_id'] : 0,
      '#prefix' => '<div style="float: left;clear: left;width:240px">',
      '#suffix' => '</div>',
    );
    $form['attendance_input']['kstu_id_fk_' . $i] = array(
      '#type' => 'hidden',
//      '#default_value' =>  isset($attnd_rec['kstu_id_fk']) ? $attnd_rec['kstu_id_fk'] : 0,
      '#default_value' =>  $student->kstu_id_fk,
      '#prefix' => '<div style="float: left;clear: left;width:60px">',
      '#suffix' => '</div>',
    );
    $form['attendance_input']['kclss_id_fk_' . $i] = array(
      '#type' => 'hidden',
//      '#default_value' => isset($attnd_rec['kclss_id_fk']) ? $attnd_rec['kclss_id_fk'] : 0,
      '#default_value' => $attnd_select_classid,  // kleosis lite uses the class id here instead of the class schedule id.
                                                  // kleosis campus will use the real kclss_id_fk
      '#prefix' => '<div style="float: left;clear: left;width:60px">',
      '#suffix' => '</div>',
    );
    $form['attendance_input']['student_name_' . $i] = array(
//      '#markup' =>    $student->name,
      '#markup' => l($student_names, 'kleosis/students/attendance', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
      '#prefix' => '<div style="float: left;clear: left;width:350px">',
      '#suffix' => '</div>',
    );
    $form['attendance_input']['absence_type_' . $i] = array(
      '#type' => 'select',
      '#options' =>  ks_get_absence_types(),
      '#default_value' =>  isset($attnd_rec['abs_type']) ? $attnd_rec['abs_type'] : 0,
      '#DANGEROUS_SKIP_CHECK' => FALSE,
      '#validated' => TRUE,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:110px" >',
      '#suffix' => '</div>',
    );
    $form['attendance_input']['excuse_reason_' . $i] = array(
      '#type' => 'select',
      '#options' =>  ks_get_excused_absence_reasons(),
      '#default_value' =>  isset($attnd_rec['excuse_reason']) ? $attnd_rec['excuse_reason'] : 0,
      '#DANGEROUS_SKIP_CHECK' => FALSE,
      '#validated' => TRUE,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:145px">',
      '#suffix' => '</div>',
    );
    $form['attendance_input']['instructor_remarks_' . $i] = array(
      '#type' => 'textfield',
      '#default_value' =>   isset($attnd_rec['remarks_instructor']) ? $attnd_rec['remarks_instructor'] : '',
      '#size' => 25,
      '#maxlength' => 120,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:200px">',
      '#suffix' => '</div>&nbsp;',
    );
    $form['attendance_input']['counselor_remarks_' . $i] = array(
      '#type' => 'textfield',
      '#default_value' =>   isset($attnd_rec['remarks_counselor']) ? $attnd_rec['remarks_counselor'] : '',
      '#size' => 5,
      '#disabled' => TRUE,
      '#maxlength' => 120,
      '#prefix' => '<div style="float: left;width:60px">',
      '#suffix' => '</div>',
    );

    $i += 1;

  } // end foreach()

  $form['attendance_input']['student_count'] = array(
    '#type' => 'hidden',
    '#default_value' => $i-1,
  );

  $_SESSION['ks_atnd_class_select']['toggle_attnd'] = 'inactive';

return $form;

}

function ks_attnd_view_class_selection_form_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Clear':
      $_SESSION['ks_atnd_class_select'] = array();
      $_SESSION['ks_atnd_instructor_filter'] = array();
      break;
    case 'Apply':
      if ($form_state['input']['op'] == 'Update') {  // insert or update attendance records

        // build a datetime object for the selected attendance date
        $hma = get_hour_and_minute_from_period($form_state['values']['period']);
        $attnd_select_hour = isset($hma['start_hour']) ? $hma['start_hour'] : '00';
        $attnd_select_minute = isset($hma['start_minute']) ? $hma['start_minute'] : '00';

        $attendance_date = new DateTime($form_state['values']['period_attnd_date']['year'] . '-' . $form_state['values']['period_attnd_date']['month'] . '-' .
        $form_state['values']['period_attnd_date']['day'] . ' ' . $attnd_select_hour . ':' . $attnd_select_minute . ':' . '00');

        // now, find the day for the selected attendance date for display
        $theday = $attendance_date->format('N');
        $node = node_load($form_state['values']['classes']);

        // store current selection in session variables
        $_SESSION['ks_atnd_class_select'] = array('classid' => $form_state['values']['classes'],
                                          'classname' => $node->title,
                                          'day' => $theday,
                                          'period' => $form_state['values']['period'],
                                          'attnd_year' => $form_state['values']['period_attnd_date']['year'],
                                          'attnd_month' => $form_state['values']['period_attnd_date']['month'],
                                          'attnd_day' => $form_state['values']['period_attnd_date']['day'],
                                          'toggle_classes' => 'active',
                                          'toggle_attnd' => 'inactive',
                                          );

        // prepare $ks_attendance_record for insert or update into the ks_student_attendance table

      for ($i = 1; $i <= $form_state['input']['student_count']; $i++) {
        $ks_attendance_record = array();
        $ks_attendance_record['ksatnd_id'] = $form_state['input']['ksatnd_id_' . $i];
        $ks_attendance_record['kstu_id_fk'] = $form_state['input']['kstu_id_fk_' . $i];
        $ks_attendance_record['kclss_id_fk'] = $form_state['input']['kclss_id_fk_' . $i];
        $ks_attendance_record['atnd_date'] = $attendance_date;
        $ks_attendance_record['period_day'] = 0; // not currently used
        $ks_attendance_record['period_hour'] = 0; // not currently used
        $ks_attendance_record['abs_type'] = $form_state['input']['absence_type_' . $i];
        $ks_attendance_record['excused_abs'] = $form_state['input']['excuse_reason_' . $i];
        $ks_attendance_record['excuse_reason'] = $form_state['input']['ksatnd_id_' . $i];
        $ks_attendance_record['remarks_instructor'] = $form_state['input']['instructor_remarks_' . $i];
        $ks_attendance_record['remarks_counselor'] = $form_state['input']['counselor_remarks_' . $i];

        if ($ks_attendance_record['ksatnd_id']) {
//          $res = ks_update_attendance_record($ks_attendance_record);
        }
        else {
//          $res = ks_insert_attendance_record($ks_attendance_record);
        }
     }  // end for

      break;
      }
      else {  // store the selected instructor, academic year, and term into session variables
        $_SESSION['ks_atnd_instructor_filter'] = array('instructorid' => $form_state['values']['instructor'],
                                          'instructorname' => get_ks_username_by_id($form_state['values']['instructor']),
                                          'academic_year' => $form_state['values']['academic_year'],
                                          'term' => $form_state['values']['term'],
                                          'toggle_classes' => 'inactive',
                                          'toggle_attnd' => 'inactive',
                                         );
        $today = new DateTime('now');
        $_SESSION['ks_atnd_class_select'] = array('day' => $today->format('N'),
                                          'attnd_year' => $today->format('Y'),
                                          'attnd_month' => $today->format('n'),
                                          'attnd_day' => $today->format('j'),
                                          'toggle_classes' => 'active',
                                          'toggle_attnd' => 'inactive',
                                          );
      }
      break;
    case 'Set Date':

      $attendance_date = new DateTime();
      $attendance_date->setDate($form_state['values']['period_attnd_date']['year'], $form_state['values']['period_attnd_date']['month'], $form_state['values']['period_attnd_date']['day']);
      // now, find the day for the selected attendance date in prep for getting the classes...
      $theday = $attendance_date->format('N');
//      $theday = date('N', strtotime($attendance_date->format('Y-m-d')));  // alternate technique

      $_SESSION['ks_atnd_class_select'] = array('day' => $theday,
                                        'attnd_year' => $form_state['values']['period_attnd_date']['year'],
                                        'attnd_month' => $form_state['values']['period_attnd_date']['month'],
                                        'attnd_day' => $form_state['values']['period_attnd_date']['day'],
                                        'toggle_classes' => 'active',
                                        'toggle_attnd' => 'inactive',
                                        );
      break;
    case 'Get Students':
/*
      if ($form_state['input']['period'] == 'none') {
        drupal_set_message(t('Please select a valid Class and Period.'));
        break;
      }
      $attendance_date = new DateTime();
      $attendance_date->setDate($form_state['values']['period_attnd_date']['year'], $form_state['values']['period_attnd_date']['month'], $form_state['values']['period_attnd_date']['day']);
      // now, find the day for the selected attendance date in prep for getting the classes...
      $theday = $attendance_date->format('N');
      $node = node_load($form_state['values']['classes']);

      $_SESSION['ks_atnd_class_select'] = array('classid' => $form_state['values']['classes'],
                                        'classname' => $node->title,
                                        'day' => $theday,
                                        'period' => $form_state['values']['period'],
                                        'attnd_year' => $form_state['values']['period_attnd_date']['year'],
                                        'attnd_month' => $form_state['values']['period_attnd_date']['month'],
                                        'attnd_day' => $form_state['values']['period_attnd_date']['day'],
                                        'toggle_classes' => 'active',
                                        'toggle_attnd' => 'active',
                                        );

      break;
*/

      // check for proper class/period selection and set period select box accordingly (for multiple classes)

      $node = node_load($form_state['values']['classes']);  // get the classid from the select box

      // then get all the scheduled Attendance classes assigned to the instructor(s) for the selected acy&t and day

      $attnd_filter_instructorid = isset($_SESSION['ks_atnd_instructor_filter']['instructorid']) ? $_SESSION['ks_atnd_instructor_filter']['instructorid'] : 0;
      $attnd_filter_academic_year = isset($_SESSION['ks_atnd_instructor_filter']['academic_year']) ? $_SESSION['ks_atnd_instructor_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
      $attnd_filter_term = isset($_SESSION['ks_atnd_instructor_filter']['term']) ? $_SESSION['ks_atnd_instructor_filter']['term'] : variable_get('kleosis_academic_term', 'fy');
      $attnd_select_day = isset($_SESSION['ks_atnd_class_select']['day']) ? $_SESSION['ks_atnd_class_select']['day'] : $today->format('N');

      $class_records_lead = ks_get_attendance_schedule_records($attnd_filter_instructorid, $attnd_filter_academic_year, $attnd_filter_term, $attnd_select_day);
      $class_records_sub = ks_get_attendance_schedule_records_sub($attnd_filter_instructorid, $attnd_filter_academic_year, $attnd_filter_term, $attnd_select_day);

      if (!empty($class_records_lead)) {

        foreach ($class_records_lead as $theclass) {   // look for the selected class to get it's period_starttime
                                                  // Attendance classes must have the same start time for each day of the week
          if ($theclass->kccls_id_fk == $form_state['values']['classes']) {
            // then get the period for just this class
            $theperiod = get_periods_from_schedule_records(array('0' => $theclass));
            // set the period selectbox to the actual period of the Attendance class
            $form_state['values']['period'] = key($theperiod);
          }
        }
      }

      if (!empty($class_records_sub)) {

        foreach ($class_records_sub as $theclass) {   // look for the selected class to get it's period_starttime
                                                  // Attendance classes must have the same start time for each day of the week
          if ($theclass->kccls_id_fk == $form_state['values']['classes']) {
            // then get the period for just this class
            $theperiod = get_periods_from_schedule_records(array('0' => $theclass));
            // set the period selectbox to the actual period of the Attendance class
            $form_state['values']['period'] = key($theperiod);
          }
        }
      }

      // set session variables so when this function returns, the form will refresh and get the proper students
      $attendance_date = new DateTime();
      $attendance_date->setDate($form_state['values']['period_attnd_date']['year'], $form_state['values']['period_attnd_date']['month'], $form_state['values']['period_attnd_date']['day']);
      // find the day for the selected attendance date in prep for getting the classes...
      $theday = $attendance_date->format('N');
      $node = node_load($form_state['values']['classes']);

      $_SESSION['ks_atnd_class_select'] = array('classid' => $form_state['values']['classes'],
                                        'classname' => $node->title,
                                        'day' => $theday,
                                        'period' => $form_state['values']['period'],
                                        'attnd_year' => $form_state['values']['period_attnd_date']['year'],
                                        'attnd_month' => $form_state['values']['period_attnd_date']['month'],
                                        'attnd_day' => $form_state['values']['period_attnd_date']['day'],
                                        'toggle_classes' => 'active',
                                        'toggle_attnd' => 'active',
                                        );
//dpm($_SESSION['ks_atnd_class_select']['classid']);

     break;
    case 'Update':
//    dpm('Hey - update!'); // This case never happens - see case Apply
      $attendance_date = new DateTime();
      $attendance_date->setDate($form_state['values']['period_attnd_date']['year'], $form_state['values']['period_attnd_date']['month'], $form_state['values']['period_attnd_date']['day']);
      // now, find the day for the selected attendance date in prep for getting the classes...
      $theday = $attendance_date->format('N');
      $node = node_load($form_state['values']['classes']);

      $_SESSION['ks_atnd_class_select'] = array('classid' => $form_state['values']['classes'],
                                        'classname' => $node->title,
                                        'day' => $theday,
                                        'period' => $form_state['values']['period'],
                                        'attnd_year' => $form_state['values']['period_attnd_date']['year'],
                                        'attnd_month' => $form_state['values']['period_attnd_date']['month'],
                                        'attnd_day' => $form_state['values']['period_attnd_date']['day'],
                                        'toggle_classes' => 'inactive',
                                        'toggle_attnd' => 'inactive',
                                        );
      break;
  }

}

function ks_attnd_view_input_form_submit($form, &$form_state) {

//  dpm('inside kleosis_attendance_input_form_submit()');
//  dpm($form);
//  dpm($form_state);

}

function ks_attnd_view_form_submit($form, &$form_state) {

//  dpm('inside kleosis_attendance_form_submit()');
//  dpm($form);
//  dpm($form_state);

}

