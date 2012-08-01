<?php

/**
 * @file
 * Proides functionality for the MyPortal features
 *
 * Callbacks for the Kleosis MyPortal menu such as Class Schedules, Assignments, Grades etc. are here
 */

	require_once('kleosis_lib.inc');
	require_once('kleosis_db_lib.inc');

/**
 * Page callback form for the Kleosis MyPortal introduction menu entry.
 *  (not currently used)
 *
 * @return
 *  form with intro message
 */
function kleosis_myportal_intro_form($form, &$form_state) {

 drupal_set_title(t('Kleosis MyPortal'));

$page_desc = <<<EOT
  <p><h1><strong>Welcome to the Kleosis MyPortal page</strong></h1></p>

  This is the <strong>Kleosis</strong> MyPortal test page.
  <br/><br/>
	Located in the ..includes/kleosis_myportal.inc file.
  <br/><br/>
EOT;

// add a fieldset for the page info

$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Kleosis MyPortal page'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );

return $form;
}
//------------------------------------------------------------------------
/**
 * Page callback form for the Kleosis MyPortal Class Schedule menu entry.
 *
 * @return
 *  form containing the logged in user's schedule
 */
function kleosis_myportal_class_schedule_form($form, &$form_state) {

	drupal_set_title(t('MyPortal Class Schedule'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Class Schedule');

  drupal_set_breadcrumb($breadcrumb);

	global $user;
	require_once('kleosis_students.inc');

	$form = array();
	$form['pageheader'] = array(
    '#markup' => '<br>',
  );

  $form['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  variable_get('kleosis_academic_year', '2011-2012'),
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => -21,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $form['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => variable_get('kleosis_academic_term', 'fy'),
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => -20,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '<br/></div>',
  );

	if (!in_array('student', $user->roles) && !in_array('instructor', $user->roles)  && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Class schedules are available for students, instructors, or parent_guardians only'));
		return array();
	}

	if (in_array('student', $user->roles)) {  // then display the student's class schedule
  	$_SESSION['student']['id'] = $user->uid;
		$_SESSION['student']['name'] = $user->name;

		$form['myportal'] = array(  // fieldset for class schedule
			'#type' => 'fieldset',
			'#title' => t('Class Schedule List for:') . ' ' . ks_get_usernames_for_display($user->uid),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
			'#weight' => -5,
			'#prefix' => '<div style="float:left;clear:left;width:880px" >',
			'#suffix' => '</div>',
			);

			$form['myportal']['class_schedule'] = kleosis_student_class_schedule_list();
	}  // end in_array('student'...

	if (in_array('parent_guardian', $user->roles)) {

		$pg_students = kleosis_parent_guardian_students($user->uid);  // get the pguardian's students

		if (empty($pg_students)) {
			drupal_set_message(t('No students have class schedules for parent_guardian') . ': ' . get_ks_username_by_id($user->uid));
		}
		$form['myportalpg'] = array(  // fieldset for class schedule
			'#type' => 'fieldset',
			'#title' => t('Class Schedule(s) for student(s) under parent_guardian') . ': ' . get_ks_username_by_id($user->uid),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
			'#weight' => -5,
			'#prefix' => '<div style="float:left;clear:left;width:880px" >',
			'#suffix' => '</div>',
			);

		foreach($pg_students as $key=>$value) {
			$studentname = get_ks_username_by_id($value);
	  	$_SESSION['student']['id'] = $value;
			$_SESSION['student']['name'] = $studentname;

			$form['myportalpg']['class_schedule'][$studentname] = array(
				'#markup' => t('Class Schedule for ') . ks_get_usernames_for_display($value) .':',
			);

			$form['myportalpg']['class_schedule'][] = kleosis_student_class_schedule_list();

		}
	}  // end in_array('parent_guardian'...

	if (in_array('instructor', $user->roles)) {  // then display the assigned classes for the instructor

	if (empty($user->roles)) {  // change this!!!
		drupal_set_message(t('No classes are scheduled for') . ': ' . get_ks_username_by_id($user->uid));
	}
		$form['myportalinst'] = array(  // fieldset for instructor's classes
			'#type' => 'fieldset',
			'#title' => t('Classes assigned to instructor') . ': ' . get_ks_username_by_id($user->uid),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
			'#weight' => -5,
			'#prefix' => '<div style="float:left;clear:left;width:880px" >',
			'#suffix' => '</div>',
			);

  $header = array(
    'classname' => array('data' => t('Classname'), ),
  );

	$academic_year = variable_get('kleosis_academic_year', '2011-2012');
	$term = variable_get('kleosis_academic_term', 'fy');

  $daterange = ks_get_acy_term_dates($academic_year, $term);

  $query = db_select('ks_class_schedule', 'ksclss');
  $query->addField('ksclss', 'kclss_id');
  $query->addField('ksclss', 'kccls_id_fk');
  $query->addField('ksclss', 'period_start_datetime');  // M-D-Y part is the class start date
  $query->addField('ksclss', 'period_end_datetime');    // M-D-Y part is also the class start date
  $query->addField('ksclss', 'period_day');             // Day of the week (ISO-8601)
  $query->addField('ksclss', 'period_hour');            // not currently used
  $query->addField('ksclss', 'period_length');          // not currently used
  $query->addField('ksclss', 'period_status');
  $query->addField('ksclss', 'classroom');
  $query->addField('ksclss', 'period_lead');

  $query->condition('ksclss.' . 'period_lead', $user->uid, '=');
  $query->condition('ksclss.' . 'period_start_datetime', $daterange, 'BETWEEN');

  $schedule_records = $query->execute()->fetchAll();  // get the classes where the instructor is the period_lead

	$multiclassids = array();

	foreach($schedule_records as $aclass) {
		$multiclassids[] = $aclass->kccls_id_fk;
	}
	$theclassids = array_unique($multiclassids);

	$theclasses = node_load_multiple($theclassids);

	$options = array();
	foreach($theclasses as $theclass) {
		$options[$theclass->nid] = array(
			'classname' => l($theclass->title, 'kleosis/classes/schedule', array('query' => array('ksopid' => $theclass->nid, 'ksop' => $theclass->title, 'destination' => 'kleosis/students/classes/class_schedule')))
			);
	}

	$form['myportalinst']['main_classes'] = array(
		'#markup' => t('Main classes') . ': ',
	);
  $form['myportalinst']['mclasses'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => t('There are no classes scheduled for this instructor'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );
  $form['myportalinst']['pager'] = array('#markup' => theme('pager'));

  $sheader = array(
    'classname' => array('data' => t('Classname'), ),
  );

  $query = db_select('ks_class_schedule', 'ksclss');
  $query->addField('ksclss', 'kclss_id');
  $query->addField('ksclss', 'kccls_id_fk');
  $query->addField('ksclss', 'period_start_datetime');  // M-D-Y part is the class start date
  $query->addField('ksclss', 'period_end_datetime');    // M-D-Y part is also the class start date
  $query->addField('ksclss', 'period_day');             // Day of the week (ISO-8601)
  $query->addField('ksclss', 'period_hour');            // not currently used
  $query->addField('ksclss', 'period_length');          // not currently used
  $query->addField('ksclss', 'period_status');
  $query->addField('ksclss', 'classroom');
  $query->addField('ksclss', 'period_sub');

  $query->condition('ksclss.' . 'period_sub', $user->uid, '=');
  $query->condition('ksclss.' . 'period_start_datetime', $daterange, 'BETWEEN');

	$schedule_records = $query->execute()->fetchAll();  // get the classes where the instructor is the period_sub

	$multiclassids = array();

	foreach($schedule_records as $aclass) {
		$multiclassids[] = $aclass->kccls_id_fk;
	}
	$theclassids = array_unique($multiclassids);

	$theclasses = node_load_multiple($theclassids);

	$soptions = array();
	foreach($theclasses as $theclass) {
		$soptions[$theclass->nid] = array(
			'classname' => l($theclass->title, 'kleosis/classes/schedule', array('query' => array('ksopid' => $theclass->nid, 'ksop' => $theclass->title, 'destination' => 'kleosis/students/classes/class_schedule')))
			);
	}

	$form['myportalinst']['subst_classes'] = array(
		'#markup' => t('Substitute classes') . ': ',
	);
  $form['myportalinst']['sclasses'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $soptions,   // used for table
    '#empty' => t('There are no substitute classes scheduled for this instructor'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );
  $form['myportalinst']['spager'] = array('#markup' => theme('pager'));

	}  // end in_array('instructor'...

return $form;

}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Attendance menu entry.
 *
 * @return
 *  form containing the attendance details for a student or parent_guardian's students
 */
function kleosis_myportal_atendance() {

	global $user;

	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Class attendance reports are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}

	require_once('kleosis_students_attendance.inc');

	drupal_set_title(t('MyPortal Attendance'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Attendance');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );

	if (in_array('student', $user->roles)) {  // then display the student's current attendance
  	$_SESSION['student']['id'] = $user->uid;
		$_SESSION['student']['name'] = $user->name;

		$build['myportal_sattend'] = array(  // fieldset for student attendance
			'#type' => 'fieldset',
			'#title' => t('Student attendance'),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
			'#weight' => -5,
			'#prefix' => '<div style="float:left;clear:left;width:880px" >',
			'#suffix' => '</div>',
			);
		$usernames = ks_get_usernames_for_display($user->uid);  // get the display names for this user
		$text = t('Current daily attendance totals for Student <strong>@name</strong>' . ': ', array('@name' => $usernames));

		$build['myportal_sattend']['theclasses'] = array(
      '#markup' => $text,
      '#prefix' => '',
      '#suffix' => '<br/>',
    );

		$build['myportal_sattend']['attendance'] = kleosis_students_attendance_list();
	}
	if (in_array('parent_guardian', $user->roles)) {

		$pg_students = kleosis_parent_guardian_students($user->uid);  // get the pguardian's students

		if (empty($pg_students)) {
			drupal_set_message(t('No students have attendance reports for parent_guardian') . ': ' . get_ks_username_by_id($user->uid));
		}

		$build['myportal_pg'] = array(  // fieldset for student attendance
			'#type' => 'fieldset',
			'#title' => t('Atendance report(s) for student(s) under parent_guardian') . ': ' . get_ks_username_by_id($user->uid),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
			'#weight' => -5,
			'#prefix' => '<div style="float:left;clear:left;width:880px" >',
			'#suffix' => '</div>',
			);

		foreach($pg_students as $key=>$value) {
			$studentname = get_ks_username_by_id($value);
	  	$_SESSION['student']['id'] = $value;
			$_SESSION['student']['name'] = $studentname;

			$build['myportal_pg']['attendance'][$studentname] = array(
				'#markup' => t('Attendance report for ') . ks_get_usernames_for_display($value) .':',
			);

			$build['myportal_pg']['attendance'][] = kleosis_students_attendance_list();
			$build['myportal_pg']['attendance']['attnd' . $value] = array(
				'#markup' => '.....',
				'#prefix' => '',
				'#suffix' => '<br/>',
			);

		}
	}  // end in_array('parent_guardian'...

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Grades menu entry.
 *
 * @return
 *  form containing the current grades for a student or parent_guardian's students
 */
function kleosis_myportal_grades() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Student grades are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal Grades'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Grades');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_grades'] = array(  // fieldset for student grades
		'#type' => 'fieldset',
		'#title' => t('Student grades'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_grades']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal Grades feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Assignments menu entry.
 *
 * @return
 *  form containing the assignments for a student or parent_guardian's students
 */
function kleosis_myportal_assignments() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Class assignments are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal Assignments'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Assignments');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_assignments'] = array(  // fieldset for student assignments
		'#type' => 'fieldset',
		'#title' => t('Student assignments'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_assignments']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal Assignments feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Transcript menu entry.
 *
 * @return
 *  form containing the transcript for a student or parent_guardian's students
 */
function kleosis_myportal_transcript() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Student transcripts are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal Transcript'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Transcript');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_transcript'] = array(  // fieldset for student transcript
		'#type' => 'fieldset',
		'#title' => t('Student transcript'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_transcript']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal Transcript feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Profile menu entry.
 *
 * @return
 *  form containing the profile for a student or parent_guardian's students
 */
function kleosis_myportal_profile() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Student profiles are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal Profile'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Profile');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_profile'] = array(  // fieldset for student profiles
		'#type' => 'fieldset',
		'#title' => t('Student profile'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_profile']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal Profile feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Calendar menu entry.
 *
 * @return
 *  form containing the calendar for a student or parent_guardian's students
 */
function kleosis_myportal_calendar() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Student calendars are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal Calendar'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Calendar');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_calendar'] = array(  // fieldset for student calendars
		'#type' => 'fieldset',
		'#title' => t('Student calendar'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_calendar']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal Calender feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal School News menu entry.
 *
 * @return
 *  form containing the school news
 */
function kleosis_myportal_school_news() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('School news is available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal School News'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('School News');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_school_news'] = array(  // fieldset for the school news
		'#type' => 'fieldset',
		'#title' => t('School News'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_school_news']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal School News feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Student Resources menu entry.
 *
 * @return
 *  form containing the student resources
 */
function kleosis_myportal_student_resources() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Student resources are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal Student Resources'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Student Resources');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_student_resources'] = array(  // fieldset for student resources
		'#type' => 'fieldset',
		'#title' => t('Student Resources'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_student_resources']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal Student Resources feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal Parent Resources menu entry.
 *
 * @return
 *  form containing the parent resources
 */
function kleosis_myportal_parent_resources() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('Parent resources are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal Parent Resources'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('Parent Resources');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_parent_resources'] = array(  // fieldset for parent resources
		'#type' => 'fieldset',
		'#title' => t('Parent Resources'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_parent_resources']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal Parent Resources feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal My Sites menu entry.
 *
 * @return
 *  form containing the student sites of interest
 */
function kleosis_myportal_my_sites() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('My Sites are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal My Sites'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('My Sites');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_my_sites'] = array(  // fieldset for my sites
		'#type' => 'fieldset',
		'#title' => t('My Sites'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_my_sites']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal My Sites feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------
/**
 * Page callback for the Kleosis MyPortal My Messages menu entry.
 *
 * @return
 *  form containing the student messages
 */
function kleosis_myportal_my_messages() {

	global $user;
/*
	if (!in_array('student', $user->roles) && !in_array('parent_guardian', $user->roles)) {
		drupal_set_message(t('My Messages are available for students and parent_guardians only'));
    $options = array('query' => array('destination' => 'kleosis_myportal') );
    drupal_goto('myportalmp', $options, $http_response_code = 302); // return to myportalmp
	}
*/
	drupal_set_title(t('MyPortal My Messages'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('MyPortal'), 'myportalmp');
  $breadcrumb[] = t('My Messages');

  drupal_set_breadcrumb($breadcrumb);

	$build = array();

	$build['pageheader'] = array(
    '#markup' => '<br>',
  );
	$build['myportal_my_messages'] = array(  // fieldset for my messages
		'#type' => 'fieldset',
		'#title' => t('My Messages'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#weight' => -5,
		'#prefix' => '<div style="float:left;clear:left;width:880px" >',
		'#suffix' => '</div>',
		);

	$build['myportal_my_messages']['not_yet'] = array(
		'#type' => 'markup',
		'#markup' => 'The MyPortal My Messages feature is currently being developed...',
		'#prefix' => '<br/><div style="float:left">',
		'#suffix' => '</div><br/><br/>',
	);

	return $build;
}
//------------------------------------------------------------------------

/**
 * Page callback for testing new menu entries. The arguments it
 * receives determine what it outputs.
 *
 * @param $content
 *   The base content to output.
 * @param $arg1
 *   First additional argument from the path used to access the menu
 * @param $arg2
 *   Second additional argument.
 */
function _menu_test_menu_page($content = NULL, $arg1 = NULL, $arg2 = NULL) {
  $output =  '<div>' . $content . '</div>';

  if (!empty($arg1)) {
    $output .= '<div>' . t('Argument 1=%arg', array('%arg' => $arg1)) . '</div>';
  }
  if (!empty($arg2)) {
    $output .= '<div>' . t('Argument 2=%arg', array('%arg' => $arg2)) . '</div>';
  }
  return $output;
}

/**
 * Function to determine the students for a parent_guardian
 * (todo: move this to kleosis_lib.inc)
 *
 * @param $pg_uid
 *   parent_guardian uid
 *
 * @return
 *   array of student uids
 */
 function kleosis_parent_guardian_students($pg_uid) {

  global $user;
	$roles = array();

	if (!$pg_uid) {
		return FALSE;
	}

  $students = array();

  $query = db_select('ks_user_relationships', 'ksur');
  $query->addField('ksur', 'kusr_id_fk');
  $query->condition('ksur.kusr_rel_id_fk', $pg_uid, '=');
  $query->condition('ksur.relationship', '1', '=');

  $results = $query->execute()->fetchAll();
  foreach ($results as $row) {
    $students[] = $row->kusr_id_fk;
  }

	return $students;
}
