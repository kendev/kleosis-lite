<?php

/**
 * @file
 * Kleosis general development code, experimentations, and examples
 */

/**
 *
 *  This code file is not for public display :)
 *
 */

//require_once ('kleosis_ws.inc');  // webservices wrapper functions

$kleosispath = drupal_get_path('module', 'kleosis');
$kwspath = $kleosispath . '/kws/MoodleWS.php';
$libpath = $kleosispath . '/includes/kleosis_lib.inc';
require_once ($kwspath);
require_once ($libpath);

/**
 * Provides a quick page for developing code
 * New dev code can go here for testing
 *
 * @param $callback_arg
 *    from hook_menu
 * @return
 *    zippo - up to dev code...
 */
function kleosis_processes_devcode_page_a($callback_arg = '') {

  drupal_set_title(t('Test - Dev Code A'));
  drupal_set_message(t('This is a development function...'));

  $lepath = drupal_get_path('module', 'kleosis');
  global $base_url;

/****************  begin dev code  ***************

Note: the following are test code snippets left here for instructional purposes

$academic_year = variable_get('kleosis_academic_year','2011-2012');
$term = variable_get('kleosis_academic_term','fy');

// get all class nids for the selected academic year and term:

$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'node')
->entityCondition('bundle', 'class')
->fieldCondition('ks_class_term', 'value', $term, '=')
->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
->fieldCondition('ks_class_status', 'value', 'active', '=')
->propertyCondition('status', 1)  // not needed, just an example...
// ->propertyCondition('title', '%' . 'Kleosis sample Math ' . '%', 'like')  // this works
// ->propertyCondition('title', 'Kleosis sample English 101 Class - Section 1')  // not needed, just an example...
// ->fieldCondition('example_field_date', 'value', array('2011-03-01', '2011-03-31'), 'BETWEEN')    // not needed, just an example...
// ->fieldCondition('example_other_field', 'state', (array) $states, 'IN', 0);   // not needed, just an example.
->fieldOrderBy('ks_class_academic_year', 'value', 'ASC');

$result = $query->execute();

//$nids = array();

if ( !empty($result) ) {

  $nids = array_keys($result['node']);

//  dpm($nids);

//  foreach ($result as $theclass) {
//    dpm($theclass->title);
//  }

  $nodes = entity_load('node', array_keys($result['node']));

//  foreach ($nodes as $node) {
//   dpm($node->title);
//   dpm($node->ks_class_academic_year);
//  }

$samplestudent = '854';

// get the grades from the classes that the student has taken during the selected academic year and term

  $query = db_select('ks_student_course_classes', 'ksstuclass');
  $query->innerJoin('ks_student_course_class_grades', 'ksstugrades', 'ksstugrades.ksccl_id_fk = ksstuclass.ksccl_id');
  $query->addField('ksstuclass', 'ksccl_id');
  $query->addField('ksstuclass', 'kstu_id_fk');
  $query->addField('ksstuclass', 'kccls_id_fk');
  $query->addField('ksstugrades', 'final_grade');
  $query->addField('ksstugrades', 'final_grade_str');
  $query->addField('ksstugrades', 'remarks');

  $query->condition('ksstuclass.' . 'kstu_id_fk', $samplestudent, '=');
  $query->condition('ksstuclass.' . 'kccls_id_fk', $nids, 'IN');

  $grade_records = $query->execute()->fetchAll();

//dpm($grade_records);

 foreach($grade_records as $record) {
//dpm($record->kstu_id_fk);
dpm($record->kccls_id_fk);

    // the course name from the class
    $class_node = node_load($record->kccls_id_fk);
    $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
    $course_node = node_load($node_course_ref);
    $coursetitle = $course_node->title;
    $node_course_no =   $course_node->ks_course_no['und'][0]['value'];
//dpm($node_course_no);


dpm($record->final_grade);
dpm($record->final_grade_str);
 }
}

*/

//$theweights = kleosis_get_grade_item_weights2(472);
//dpm($theweights['few']);


//global $user;

//dpm($user);

//  $moodle_url = variable_get('kleosis_moodle_url','http://localhost/moodle');
//  $courses = ws_get_my_courses();
//  $items = array();
//  foreach ($courses as $key => $val) {
//    if ($val['id'] != 1) {
//      $items[$val['id']] = l($val['shortname'], $moodle_url . '/course/view.php', array('query' => array('id' => $val['id']), 'attributes' => array('target' => '_blank')));
//    }
//  }
//      return array('#markup' => theme('item_list', array('items' => $items)));  // this is ok, but should return a renderable array
//      return array('#theme' => 'item_list', '#items' => $items,); // this is better because it is a render array
//      return array('#theme' => 'item_list', '#items' => $items, '#attached' => array('css' => drupal_get_path('module','kleosis') . '/css/kleosis_lms_direct_block.css'));  // this is cool - added some css...
//  dpm($items);

/*
  $grades = ws_get_grades();

  drupal_set_message('sizeof get_grades return array: ' . sizeof($grades));

  for($i=0;$i<sizeof($grades);$i++) {

    drupal_set_message($grades[$i]['error']);
    drupal_set_message($grades[$i]['itemid']);
    drupal_set_message($grades[$i]['grade']);
    drupal_set_message($grades[$i]['str_grade']);
    drupal_set_message($grades[$i]['feedback']);

  }

  dpm($grades);
*/


//  $rec_count = db_query('SELECT count(*) FROM {ks_organization_desc}' )->fetchField();
//  drupal_set_message('The number of records found is: ' . $rec_count);

//  $cnt_deleted = db_delete('ks_organization_desc')->execute();
//  drupal_set_message('ks_organization_desc table entries have been removed');

//register_shutdown_function('shutdown');

/****************  end dev code  ***************/


/****************  new dev code can go here:  ***************/









 return array('#markup' => 'Development code goes here...');
}


/**
 * function to write a record into the the ks_class_schedule table
 * uses ks_insert_schedule_record() in ks_db_lib.inc
 *
 */
/*function kleosis_dev_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i) {
  $schedule_record = array();
//  $schedule_record['kclss_id'] = $id;
  $schedule_record['kccls_id_fk'] = $classid;
  $schedule_record['period_start_datetime']['year'] = $class_start_date->format('Y');
  $schedule_record['period_start_datetime']['month'] = $class_start_date->format('n');
  $schedule_record['period_start_datetime']['day'] = $class_start_date->format('j');
  $schedule_record['period_day'] = $p_d;
  $schedule_record['period_start_hour'] = $p_s_h;
  $schedule_record['period_start_minute'] = $p_s_m;
  $schedule_record['period_end_hour'] = $p_e_h;
  $schedule_record['period_end_minute'] = $p_e_m;
  $schedule_record['classroom'] = $cl_rm;
  $schedule_record['period_status'] = 1;  // for Kleosis Lite
  $schedule_record['period_lead'] = $p_l_i;
  $schedule_record['period_sub'] = 0;

  $ok = ks_insert_schedule_record($schedule_record);
}
*/
/**
 * function to return the class id for a specific class
 *
 * @param  $class_title
 * @param  $academic_year
 *
 * @return the class id
 *
 */
/*function kleosis_sample_get_classid($class_title, $academic_year) {

  $nids = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_status', 'value', 1, '=') // 'active'
  ->propertyCondition('title', $class_title);

  $result = $query->execute();

    if ( !empty($result) ) {
      $nids = array_keys($result['node']);
    }
    else {
        $nids = array(0);
  }
  return $nids;
}
*/

// force logout of current user
function force_logout() {
  drupal_set_message(t('logging out current user.'));
  global $user;
  $tmp = NULL;
  session_destroy();
  user_module_invoke('logout', $tmp, $user);
  $user = drupal_anonymous_user();
}

// new functions development can be placed here and called by above dev code...
/*
function shutdown() {
 if (($error = error_get_last())) {
   ob_clean();
   # report the event, send email etc.
//   header("Location: http://localhost/error-capture");
   header("Location: http://localhost/kleoport/kleosis");
   # from /error-capture, you can use another redirect, to e.g. home page
  }
}
*/
/*
function kleosis_get_grade_item_weights2($classid) {

  $theclass = node_load($classid);
  $thecourse = node_load($theclass->ks_class_course_ref['und'][0]['nid']);
dpm($theclass);
dpm($thecourse);

  $cgw = isset($thecourse->field_ks_course_grade_weight['und'][0]['value']) ? $thecourse->field_ks_course_grade_weight['und'][0]['value'] : 0.0;
  $few = isset($thecourse->field_ks_final_exam_weight['und'][0]['value']) ? $thecourse->field_ks_final_exam_weight['und'][0]['value'] : 0.0;
  $giaw = isset($thecourse->field_ks_grade_item_a_weight['und'][0]['value']) ? $thecourse->field_ks_grade_item_a_weight['und'][0]['value'] : 0.0;
  $gibw = isset($thecourse->field_ks_grade_item_b_weight['und'][0]['value']) ? $thecourse->field_ks_grade_item_b_weight['und'][0]['value'] : 0.0;
  $gicw = isset($thecourse->field_ks_grade_item_c_weight['und'][0]['value']) ? $thecourse->field_ks_grade_item_c_weight['und'][0]['value'] : 0.0;

  $weights = array('cgw' => $cgw, 'few' => $few, 'giaw' => $giaw, 'gibw' => $gibw, 'gicw' => $gicw);

  return $weights;
}
*/
/*
function get_dayofweek($pTimezone) {

    $userDateTimeZone = new DateTimeZone($pTimezone);
    $UserDateTime = new DateTime("now", $userDateTimeZone);

    $offsetSeconds = $UserDateTime->getOffset();
    //echo $offsetSeconds;

    return gmdate("l", time() + $offsetSeconds);
}
*/

/**
 * Experimental code for syncing users...
 *
 * @param $callback_arg
 *    from hook_menu
 * @return
 *    tbd
 */
function kleosis_processes_devcode_sync_users($callback_arg = '') {

  drupal_set_title(t('Synchronize all users'));

  if ((isset($_POST['op']) && $_POST['op'] == t('Sync')) || !empty($_POST['confirm'])) {
    return drupal_get_form('kleosis_sync_users_confirm'); // This is the confirmation form for the user to confirm the synchronization
  }
   return drupal_get_form('kleosis_processes_devcode_sync_users_form');
 }

/**
 * Form with message to synchronize users
 *
 */
function kleosis_processes_devcode_sync_users_form($form, &$form_state) {

$process_summary_desc = <<<EOT
This process will synchronize users.
    <ul>
      <li>The users in Moodle will be updated/created from Drupal (the central repository for user data).</li>
      <li>Any users in Moodle that are not already in Drupal will be created in Drupal.</li>
    </ul>
EOT;
$process_details_desc = <<<EOT
The synchronize details are as follows for the Drupal to Moodle direction:
    <ul>
      <li>The users in Moodle will be updated/created from Drupal (the central repository for user data).</li>
      <li>This process is already integrated in the Drupal People Administrative page. Administrators can synchronize Drupal users with Moodle by the following steps:</li>
        <ul>
            <li>Select the 'People' menu item from the Drupal Administration menu. (You must have permissions to view this menu)</li>
            <li>Display the users you want to synchronize by using the 'Show only users where' filter.</li>
            <li>Select all the requested users by checking the checkbox in the displayed table header.</li>
            <li>Select 'Register the selected T-Prep users' from the 'Update Options' select box./li>
            <li>Click on the 'Update' button.</li>
        </ul>
      <li>The users will be created/updated in Moodle</li>
   </ul>
An optimized batch process for the Drupal to Moodle synchronization is currently being developed.<br/><br/>
The synchronization of Moodle users into Drupal is also currently under development.
    <ul>
      <li>User roles in Moodle will need to be addressed...</li>
      <li>Primary vs. multiple roles prioritization...</li>
      <li>Optimized batch process option...</li>
      <li>More...</li>
   </ul>
EOT;

  // add a fieldset for the page desc
  $form['blurb'] = array(
      '#type' => 'fieldset',
      '#title' => t('Sync Users'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
  $form['blurb']['pageinfo'] = array(
      '#markup' => $process_summary_desc,
    );
  $form['blurb']['inner_help'] = array(
      '#type' => 'fieldset',
      '#title' => t('Synchronization Details'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
  $form['blurb']['inner_help']['help_details'] = array(
      '#markup' => $process_details_desc,
    );
  $form['blurb']['sync_direction'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Sync Direction'),
    '#options' => array('drupal_to_moodle' => t('Drupal to Moodle'), 'moodle_to_drupal' => t('Moodle to Drupal')),
    '#description' => t('Select one or both directions'),
    '#prefix' => '<div style="float:left;clear:left;width:300px" >',
    '#suffix' => '</div>',
  );

  $form['blurb']['actions']['sync'] = array(
    '#type' => 'submit',
    '#value' => t('Sync'),
    '#weight' => '10',
    '#prefix' => '<div style="float:left;clear:left;width:300px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

// Implements hook_submit
function kleosis_processes_devcode_sync_users_form_submit($form, &$form_state) {

  if ($form_state['values']['op'] == 'Sync') {
      drupal_set_message(t('Sync !'));
    //  Very interesting: this submit is NOT called when the Sync button is clicked - the confirm one is called instead...

  }
  elseif ($form_state['values']['op'] == 'Cancel') {
    //  drupal_set_message('Cancel !');  // this does get called

  }
  else {
    //  drupal_set_message('Value = ' .$form_state['values']['op'] );
  }

}

// Implement the confirm form
function kleosis_sync_users_confirm($form, &$form_state) {

  $drupal_to_moodle = isset($form_state['input']['sync_direction']['drupal_to_moodle']) ? 1 : 0;
  $moodle_to_drupal = isset($form_state['input']['sync_direction']['moodle_to_drupal']) ? 1 : 0;

  $sync_desc_b = 'The action(s) about to occur is: <ul>';
  $sync_desc1 = '<li>The users in Moodle will be updated/created from Drupal (the central source of all user data is from Drupal).</li>';
  $sync_desc2 = '<li>Any users in Moodle that are not already in Drupal will be created in Drupal.</li>';
  $sync_desc_e = '</ul>This action cannot be undone.';
  $sync_desc_empty = 'Please select a sync direction.';

  $sync_desc = $sync_desc_b;
  if ($drupal_to_moodle) {
    $sync_desc .= $sync_desc1;
  }
  if ($moodle_to_drupal) {
    $sync_desc .= $sync_desc2;
  }
  $sync_desc .= $sync_desc_e;
  if ((!$drupal_to_moodle  && !$moodle_to_drupal)) {
    $sync_desc = $sync_desc_empty;
  }

    $form['confirm'] = array(
      '#type' => 'hidden',
      '#value' => 1,
    );
    $form['drupal_to_moodle'] = array(
      '#type' => 'hidden',
      '#value' => $drupal_to_moodle,
    );
    $form['moodle_to_drupal'] = array(
      '#type' => 'hidden',
      '#value' => $moodle_to_drupal,
    );

  return confirm_form($form,
                      t('Are you sure you want to synchronize all users?'),
                      'kleosis/processes/devcode_b', $sync_desc,
                      t('Confirm'), t('Cancel'));

  // todo: make the above message translatable:
}

// hook_submit for the above confirm form
function kleosis_sync_users_confirm_submit($form, &$form_state) {

  $drupal_to_moodle = $form_state['input']['drupal_to_moodle'];
  $moodle_to_drupal = $form_state['input']['moodle_to_drupal'];

  // Very interesting: this submit is called instead of the submit from the original form...
  // So, all the syncing logic should be done here.
/**********************************************************************************************************************************/
/****************************************     Here's the sync code for Drupul users to Moodle    **********************************/

/* Procedure:
    Read all Drupal users into an array
    Read all Moodle users into an array
    Build an array of ids (aDrupal_to_Moodle) of missing users in Moodle that are in the Drupal array
    Create the appropriate users in Moodle
*/

/*******************************************      End of sync code      ************************************************************/
/***********************************************************************************************************************************/

//  $aDrupal_users = array();
//  $aMoodle_users = array();
//  $aDrupal_to_Moodle = array();
//  $aMoodle_users = ws_get_users();
//  dpm($aMoodle_users);

$sync_message1 = 'Drupal users can be currently be synchronized to Moodle via the main Drupal administration menu.  Please see the "Creating and Registering New Users" section in the Kleosis Documentation.';
/**********************************************************************************************************************************/
/****************************************     Here's the sync code for Moodle users to Drupal    **********************************/

/* Procedure:
    Read all Drupal users into an array
    Read all Moodle users into an array
    Build an array of of ids (aMoodle_to_Drupal) of missing users in Drupal that are in the Moodle array
    Build an array of roles for the users in aMoodle_to_Drupal. The role is the "primary role" for the Moodle user that will become the users Dupal role
    Create the appropriate users in Drupal along with the role
*/

$sync_message2 = 'The synchronization of Moodle users into Drupal is currently under development...';
/*******************************************      End of sync code      ************************************************************/
/***********************************************************************************************************************************/
  $sync_message = '';
  if ($drupal_to_moodle) {
    $sync_message .= $sync_message1;
  }
  if ($moodle_to_drupal) {
    $sync_message .= $sync_message2;
  }
  drupal_set_message(check_plain($sync_message));

  $form_state['redirect'] = 'kleosis/processes/devcode_b';

  return;
}

/**
 * Provides a quick logout option
 *
 * @param $callback_arg
 *    from hook_menu
 * @return
 *    tbd
 */
function kleosis_processes_devcode_force_logout($callback_arg = '') {

  drupal_set_title(t('Force Logout'));
////////////////////////////            //////////////////////////////
///////////////////////////   Yuk !!!   //////////////////////////////
////////////////////////////            //////////////////////////////
//  Ken is here  -  workaround: drupal 7.0 logout problem
    module_load_include('pages.inc', 'user', 'user');
    user_logout();
//  Ken was here
////////////////////////////            //////////////////////////////
///////////////////////////   Yuk !!!   //////////////////////////////
////////////////////////////            //////////////////////////////

  return array('#markup' => 'This message never displays...');

}

/*
function kleosis_processes_devcode_b_form($form, &$form_state) {

drupal_set_title(t('Test - Dev Code B'));

$page_desc = <<<EOT
    <br/>This form allows a placeholder for code development.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info
$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page Description'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );

return $form;
}
*/
/************************************    more sample and early test code   **************************************************/
/*
//$result = ks_get_enroll_records($drupaluserid, $unenroll_is_null = TRUE, $class_id = '', $enrol_date = '') {
$result = ks_get_enroll_records(368, TRUE, 249);
//$result = ks_delete_enroll_record(1);
if (empty($result)) {
  drupal_set_message('empty..........................');
}else {
  drupal_set_message('found student in class....');
}
dpm($result);
$maybe_now = new DateTime('now');

dpm($maybe_now);
dpm($maybe_now->date);

$ok = user_access('administer kleosis');
if ($ok) {
  drupal_set_message('user has this permission');
}
else {
  drupal_set_message('user does NOT have this permission');
}


drupal_goto($path = 'kleosis/students', $options = array());


//   $accd = (!empty($ks_user['acceptance_date'])) ? new DateTime($ks_user['acceptance_date']) : new DateTime('1901-01-01 0:0:00');

$thedate = new DateTime('now');
$theday = date('D',$thedate->getTimestamp());
dpm($theday);
$thenewdate = new DateTime($thedate->format('Y') . '-' .$thedate->format('n') . '-' . $thedate->format('j') .
' ' . $thedate->format('H') . ':' . $thedate->format('i') . ':' . $thedate->format('s') );
$thenewdatetz = new DateTime($thedate->format('Y') . '-' .  $thedate->format('n') . '-' . $thedate->format('j') .
'T' . $thedate->format('H') . ':' . $thedate->format('i') . ':' . $thedate->format('s') );

dpm($thenewdate);
dpm($thenewdatetz);

$dow = get_dayofweek('America/New_York');
dpm($dow);

$aclass = node_load(270);
dpm($aclass);
dpm($aclass->ks_class_start_end_date['und'][0]['value']);

$class_start_date = $aclass->ks_class_start_end_date['und'][0]['value'];

$start_date = new DateTime($class_start_date);

dpm($start_date);
*/
/**************************************************************************************/

//$instrs = ks_get_instructor_names();
//$withfirst = array(0 => t('none'));
//$newarray = $withfirst + $instrs;
//dpm($newarray);


//$academic_year = '2011-2012';
//$term = 1;
/*$term_start_field = 'term' . $term . '_startdate';
$term_end_field = 'term' . $term . '_enddate';

//dpm($term_start_field);
//dpm($term_end_field);

$academic_year = '2011-2012';
$term = 2;
$term_start_field = 'term' . $term . '_startdate';
$term_end_field = 'term' . $term . '_enddate';

//dpm($term_start_field);
//dpm($term_end_field);
*/
/*
$tdate = new DateTime('now');
$tz = $tdate->getTimezone();
dpm($tz);
$theday = gmdate("l", time());
dpm($theday);
dpm(date_default_timezone_get());



$classes = ks_get_schedule_records(881, '2011-2012', 1);

$theclasses = get_classes_from_schedule_records($classes);
dpm($theclasses);
$thedays = get_days_from_schedule_records($classes);
dpm($thedays);
$theperiods = get_periods_from_schedule_records($classes);
dpm($theperiods);

$adate = new DateTime('2011-08-15');
$weekday = date('l', strtotime($adate->format('Y-m-d')));
$weekdayint = date('N', strtotime($adate->format('Y-m-d')));
//dpm($weekdayint);
//dpm($weekday);

$theday = get_dayofweek('default');
//dpm($theday);

$dayint = ks_get_day_int('Friday');
//dpm($dayint);

$students = ks_get_students_in_a_class(346);
//dpm($students);

$hma = get_hour_and_minute_from_period('08:19-20:21');
//dpm($hma['start_hour']);
//dpm($hma['start_minute']);
//dpm($hma['end_hour']);
//dpm($hma['end_minute']);

$absencea = ks_get_excused_absence_reasons();
//dpm($absencea);
*/

/*
dpm(base_path()); // /kleoport/
dpm(request_uri());  // /kleoport/kleosis/processes/devcode_a

dpm(l(t('Students'), 'kleosis/students'));
dpm(l(t('here'), 'kleosis/processes/devcode_a'));
//dpm(menu_get_active_trail());

$hey =  (variable_get('kleosis_course_grade_item_3_weight', '00.00') <> '00.00') ? 'textfield' : 'hidden';

dpm(variable_get('kleosis_course_grade_item_3_weight', '0'));
dpm($hey);

*/
/**
 *
 * Retrieve the current user name from the session variable
 *
 * @param $uid
 *   The user id from the url
 *
 *  return user's uid
 */
/*function kleosis_student_to_arg($uarg){

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : '');
  dpm('inside kleosis_student_to_arg');
  dpm($uarg);

  if ( isset( $_GET['ksopid'] ) && !empty( $_GET['ksopid'] )) {
    dpm('here is the ksopid:');
    dpm($_GET['ksopid']);

  }
  dpm($uid);

  if ( isset( $_GET['ksopid'] ) && !empty( $_GET['ksopid'] )) {
  $uid = $uid . '?ksopid=' . $uid;
  }
  if ( isset( $_GET['kssid'] ) && !empty( $_GET['kssid'] )) {
  $uid = $uid . '&kssid=' . $_GET['kssid'];
  }
  if ( isset( $_GET['ksop'] ) && !empty( $_GET['ksop'] )) {
  $uid = $uid . '&ksop=' . $_GET['ksop'];
  }
  dpm('here is the returning param');
  dpm($uid);

  return $uid;
}
*/
/**************************************************************************************/

