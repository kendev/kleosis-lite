<?php
// $Id$

/**
 * @file
 * Wrapper functions for the OK Tech webservices layer to Moodle
 */

require_once ('kleosis_db_lib.inc');

$kwspath = drupal_get_path('module', 'kleosis');
$kws = $kwspath . '/kws/MoodleWS.php';
require_once ($kws);

/**
 * Retrieve the Moodle user's info for a single user
 *
 * @param $uid
 *   The Moodle users id
 * @param $uid_field
 *   The Moodle field for the user id search (examples: 'id', 'username', 'lastname', etc.)
 * @return
 *   Array of user's info for a single user
 */
function ws_get_user($uid, $uid_field='id') {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  try {
    $userids = array($uid);

    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);

    $res = $moodle->get_users($lr->getClient(), $lr->getSessionKey(), $userids, $uid_field);

    $rowsa = array();

    // should only be one
    foreach ($res->users as $le_user) {

      $rowsa[] = array('id' => $le_user->id, 'username' => $le_user->username, 'firstname' => $le_user->firstname, 'lastname' => $le_user->lastname);
    }

    $moodle->logout($lr->getClient(), $lr->getSessionKey());
  }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_user returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
  }

//  return $rowsa[0];
  return $rowsa;
}

/**
 * Retrieve the Moodle users info for all users
 *
 * @param $userids
 *   Array of Moodle users ids
 * @param $userfield
 *   The Moodle users table field for the Moodle users id(s)
 * @return
 *   Array of Moodle users info for all users
 */
function ws_get_users($userids = array(), $userfield = '') {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);

    // blank array returns all users...
    $userids = array();
    $res = $moodle->get_users($lr->getClient(), $lr->getSessionKey(), $userids, '');

    $rowsa = array();

    foreach ($res->users as $le_user) {

      $rowsa[] = array('id' => $le_user->id, 'username' => $le_user->username, 'firstname' => $le_user->firstname, 'lastname' => $le_user->lastname);
    }

    $moodle->logout($lr->getClient(), $lr->getSessionKey());
    }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_users returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
   }

  return $rowsa;
}

/**
 * Retrieve all of the roles defined in Moodle
 *
 * @return
 *   Array of all the roles defined in Moodle
 */
function ws_get_roles() {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);

    $res = $moodle->get_roles($lr->getClient(), $lr->getSessionKey());
    $rolesa = array();

    foreach ($res->roles as $le_role) {

      $rolesa[] = array('id' => $le_role->id, 'name' => $le_role->name, 'description' => $le_role->description);
    }

    $moodle->logout($lr->getClient(), $lr->getSessionKey());
    }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_roles returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
    }

    return $rolesa;
}

/**
 * Update the Moodle user's info for a single user
 *
 * @param $form_values
 *   From the Edit Users form
 * @return
 *   Users name if successfully updated, othewise the error message
 */
function ws_users_edit_form_submit_values($form_values) {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  $id        = $form_values['userid'];
  $username  = $form_values['username'];
  $firstname = $form_values['firstname'];
  $lastname  = $form_values['lastname'];

  $le_student = new userRecord();

  $le_student->id = $id;
  $le_student->username = $username;
  $le_student->firstname = $firstname;
  $le_student->lastname = $lastname;
  // 717c8e26117dd902dcbb441f123234cc
  $le_student->password = '';
  // 's01
  //'717c8e26117dd902dcbb441f123234cc';
  $le_student->passwordmd5 = '';
  $le_student->action = 'update';

  $le_students = array();
  $le_students[] = $le_student;

  $le_users = new editUsersInput();
  $le_users->setUsers($le_students);
  //  dpm("Input to moodle->edit_user: ");
  //  dpm($leUsers);

try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);

  $res = $moodle->edit_users($lr->getClient(), $lr->getSessionKey(), $le_users);
  //  dpm('Output from moodle->edit_user: ');
  //  dpm($res);

  $moodle->logout($lr->getClient(), $lr->getSessionKey());

  }
catch (Exception $e) {
  drupal_set_message(t('webservices->edit_users returned an error = %errormessage. %tryagain',
  array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
  return NULL;
  }
  return;  // todo: update this with a return value
}

/**
 * Create a new Moodle user
 *
 * @param $duser
 *   Simple record with drp_uid, username, firstname, lastname, email
 * @return
 *   Moodle Users id if successfully updated, otherwise the error message
 */
function ws_add_user($duser) {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  $drp_uid   = $duser['drp_uid'];
  $username  = $duser['username'];
  $firstname = $duser['firstname'];
  $lastname  = $duser['lastname'];
  $email  = $duser['email'];

  $le_student = new userRecord();

  $le_student->username = $username;
  $le_student->firstname = $firstname;
  $le_student->lastname = $lastname;
  $le_student->email = $email;

  $le_student->auth = 'manual';
  $le_student->confirmed = 1;
  $le_student->policyagreed = 0;
  $le_student->deleted = 0;
  $le_student->mnethostid = 1;
  $le_student->icq = $drp_uid;
  $le_student->idnumber = $username;


  $le_student->password = '';
  $le_student->passwordmd5 = md5($username);

  $le_student->action = 'add';

  $le_students = array();
  $le_students[] = $le_student;

  $le_users = new editUsersInput();
//  $le_users = new userDatum();
  $le_users->setUsers($le_students);
//  dpm("Input to moodle->edit_users: ");
//  dpm($le_users);

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);

    $res = $moodle->edit_users($lr->getClient(), $lr->getSessionKey(), $le_users);
    //  dpm('Output from moodle->edit_user: ');
    //  dpm($res);

    $moodle->logout($lr->getClient(), $lr->getSessionKey());

  }
  catch (Exception $e) {
    drupal_set_message(t('webservices->edit_users returned an error on adding a user: %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
  }

  return $res;
}

/**
 * Retrieve the Moodle course info for all courses
 *
 * @return
 *   Array of Moodle course info for all course
 */
function ws_get_courses() {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);

    $courseids=array();
    $res=$moodle->get_courses($lr->getClient(), $lr->getSessionKey(), $courseids, '');

    $coursesa = array();
    foreach ($res->courses as $le_course) {

      $coursesa[] = array('id' => $le_course->id, 'shortname' => $le_course->shortname, 'fullname' => $le_course->fullname, 'summary' => $le_course->summary);
    }

    $moodle->logout($lr->getClient(), $lr->getSessionKey());
  }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_courses returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
  }

  return $coursesa;
}

/**
 * Retrieve the Moodle course info for a specific user
 *
 * @param $ks_user
 *   mdl_uid of the user whose courses to get (optional)
 * @return
 *   Array of Moodle course info for the user's courses
 */
function ws_get_my_courses($ks_user = '') {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  $ks_user = ($ks_user) ? $ks_user : $res['mdl_uid'];

  $coursesa = array();
  if (!$ks_user) { //user does not exist in Moodle
    return $coursesa;
  }

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);

    $courseids=array();
    $res=$moodle->get_my_courses($lr->getClient(), $lr->getSessionKey(), $ks_user, '');
//    $res=$moodle->get_my_courses($lr->getClient(), $lr->getSessionKey(), $ws_mdl_uid, '');
    foreach ($res->courses as $le_course) {

      $coursesa[] = array('id' => $le_course->id, 'shortname' => $le_course->shortname, 'fullname' => $le_course->fullname, 'summary' => $le_course->summary);
    }

    $moodle->logout($lr->getClient(), $lr->getSessionKey());
  }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_courses returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
  }

  return $coursesa;
}

/**
 * Retrieve all of the assignments
 *
 * @return
 *   Array of all the assignments defined in Moodle
 */
function ws_get_assignments($course = '') { // todo: complete this...

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);
    $assgtsa = array();

    $res = $moodle->get_all_assignments($lr->getClient(), $lr->getSessionKey(), '', '');
    $assgtsoa = $res->getAssignments();

    foreach ($assgtsoa as $le_assgt) {

      $assgtsa[] = array('id' => $le_assgt->id, 'course' => $le_assgt->course, 'name' => $le_assgt->name);
    }
    $moodle->logout($lr->getClient(), $lr->getSessionKey());
    }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_ass_assignments returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
    }

    return $assgtsa;
}

/**
 * Retrieve all grades for a user from moodle, using the student mdl_uid
 *
 * @param $ks_user
 *   mdl_uid of the user whose grades to get (optional)
 * @return
 *   Array of all the grades for the logged-in user from moodle
 */
function ws_get_grades($ks_user = '') {

  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS
  $ks_user = ($ks_user) ? $ks_user : $res['mdl_uid'];

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);
    $gradesa = array();

    $res = $moodle->get_user_grades($lr->getClient(), $lr->getSessionKey(), $ks_user, 'id');  // todo: look into this...

    $gradessoa = $res->getGrades();

    foreach ($gradessoa as $le_grade) {
      $gradesa[] = array('error' => $le_grade->error, 'itemid' => $le_grade->itemid, 'grade' => $le_grade->grade, 'str_grade' => $le_grade->str_grade, 'feedback' => $le_grade->feedback);
    }
    $moodle->logout($lr->getClient(), $lr->getSessionKey());
    }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_grades returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
    }

    return $gradesa;
}


/**
 * Retrieve all grades for a user from moodle, using the student username
 *
 * @param $ks_user
 *   username of the user whose courses to get (optional)
 * @return
 *   Array of all the grades for the logged-in user from moodle
 */
function ws_get_grades_by_username($ks_user = '') {

  global $user;
  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS
  $ks_user = ($ks_user) ? $ks_user : $user->name;

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);
    $gradesa = array();

    $res = $moodle->get_user_grades($lr->getClient(), $lr->getSessionKey(), $ks_user, 'idnumber');  // todo: look into this...

    $gradessoa = $res->getGrades();

    foreach ($gradessoa as $le_grade) {
      $gradesa[] = array('error' => $le_grade->error, 'itemid' => $le_grade->itemid, 'grade' => $le_grade->grade, 'str_grade' => $le_grade->str_grade, 'feedback' => $le_grade->feedback);
    }
    $moodle->logout($lr->getClient(), $lr->getSessionKey());
    }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_grades returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
    }

    return $gradesa;
}

/**
 * Retrieve all grades from a specific moodle course
 *
 * @param $coursename
 *   short coursename of the course
 * @return
 *   Array of all the grades in the course from moodle
 */
function ws_get_course_grades($coursename) {

//  global $user;
  $res = get_mdl_login();   // get the login username and password for this ws call (todo: maybe redesign this)
  $margs = get_wsdl_uri();  // get the params for MoodleWS
//  $ks_user = ($ks_user) ? $ks_user : $user->name;

  try {
    $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);
    $lr = $moodle->login($res['username'], $res['password']);
    $gradesa = array();

    $res = $moodle->get_course_grades($lr->getClient(), $lr->getSessionKey(), $coursename, 'shortname');  // todo: look into this...

    $gradessoa = $res->getGrades();

    foreach ($gradessoa as $le_grade) {
      $gradesa[] = array('error' => $le_grade->error, 'itemid' => $le_grade->itemid, 'grade' => $le_grade->grade, 'str_grade' => $le_grade->str_grade, 'feedback' => $le_grade->feedback);
    }
    $moodle->logout($lr->getClient(), $lr->getSessionKey());
    }
  catch (Exception $e) {
    drupal_set_message(t('webservices->get_grades returned an error = %errormessage. %tryagain',
    array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
    return NULL;
    }

    return $gradesa;
}

/**
 * Set the Moodle login name and password and user's mdl_uid for ws function calls
 *
 * @return
 *   Array: username, password, mdl_uid
 */
function get_mdl_login() {

  global $user;

  $username = variable_get('kleosis_moodle_username','admin');     // set username and password here
  $password = variable_get('kleosis_moodle_password','moodle');   // todo: can encrypt or get from db...
  $mdl_uid = 0;

  if (user_is_logged_in()) {
    if (isset($user->mdl_uid)) {
      $mdl_uid = $user->mdl_uid;
//dpm('$user->mdl_uid is set!');
    }
    else {
      // look in ks_students table
      $is_ks_student = ks_check_exists_userrecord('ks_student', $user->uid);
      if ( (isset($is_ks_student['mdl_uid_fk']) ) && (!empty($is_ks_student['mdl_uid_fk'])) ) {
         $mdl_uid = $is_ks_student['mdl_uid_fk'];
//dpm('user is a ks_student');
//dpm($mdl_uid);
      }
      else {
      // look in ks_users table
      $is_ks_user = ks_check_exists_userrecord('ks_any', $user->uid);
      if ( (isset($is_ks_user['mdl_uid_fk']) ) && (!empty($is_ks_user['mdl_uid_fk'])) ) {
         $mdl_uid = $is_ks_user['mdl_uid_fk'];
//dpm('user is a ks_user');
//dpm($mdl_uid);
      }
    }

  if (!$mdl_uid) {
    // if not in ks tables, then get mdl_uid from moodle
    // then set $user->mdl_uid

// dpm('$user is not in a ks_user table!');

    try {
      $userids = array($user->name);
      $margs = get_wsdl_uri();  // get the params for MoodleWS
      $moodle = new MoodleWS($margs['wsdl'],$margs['uri']);

      $lr = $moodle->login($username, $password);
      $res = $moodle->get_users($lr->getClient(), $lr->getSessionKey(), $userids, 'username');

      $rowsa = array();
      // should only be one
      foreach ($res->users as $le_user) {
        $rowsa[] = array('id' => $le_user->id, 'username' => $le_user->username, 'firstname' => $le_user->firstname, 'lastname' => $le_user->lastname);
      }
      $moodle->logout($lr->getClient(), $lr->getSessionKey());
    }
    catch (Exception $e) {
      drupal_set_message(t('webservices->get_user returned an error = %errormessage. %tryagain',
      array('%errormessage' => $e->getMessage(), '%tryagain' => '  Please try again or contact your System Administrator.')), 'error');
      return NULL;
    }

    if ( isset($rowsa[0]['id']) ) {
      $mdl_uid = $rowsa[0]['id'];  // for testing: 3 = kendev, 21 = student9001
    }

    $user->mdl_uid = $mdl_uid;
//dpm('user found in moodle');
//dpm($mdl_uid);

  }
    }
  }

  $login_user = array('username' => $username, 'password' => $password, 'mdl_uid' => $mdl_uid);

  return $login_user;
}
/**
 * Set the Moodle wsdl and uri parameters for ws function calls
 *
 * @return
 *   Array wsdl, uri
 */
function get_wsdl_uri() {

      $moodle_url = variable_get('kleosis_moodle_url','http://localhost/moodle');
      $moodle_version = variable_get('kleosis_moodle_version','2.x');
//      $local = ($moodle_version[0] == 2) ? '/local' : '';
      $local = '';
      $uri = $moodle_url . $local . '/wspp/wsdl';
      $wsdl = $moodle_url . $local .'/wspp/wsdl_pp.php';

  return array('wsdl' => $wsdl, 'uri' => $uri);

}

/************************************************************************************************************/
/**
 * Retrieve a sample list of users defined in Moodle - this is a legacy test function
 *
 * @return
 *   Array of users defined in Moodle
 */
function lms_sample_user_data() {

  $users   = array();
  $users[] = array('id' => 2, 'username' => 'admin', 'firstname' => 'Admin', 'lastname' => 'User');
  $users[] = array('id' => 14, 'username' => 'redondo', 'firstname' => 'Redondo', 'lastname' => 'Sumpter');
  $users[] = array('id' => 5, 'username' => 'dave', 'firstname' => 'David', 'lastname' => 'Heuring');
  $users[] = array('id' => 7, 'username' => 'visitor', 'firstname' => 'Gnu', 'lastname' => 'Visitor');
  $users[] = array('id' => 10, 'username' => 'instructor01', 'firstname' => 'Instructor', 'lastname' => 'One');
  $users[] = array('id' => 11, 'username' => 'instructor02', 'firstname' => 'Instructor', 'lastname' => 'Two');
  $users[] = array('id' => 12, 'username' => 'instructor03', 'firstname' => 'Instructor', 'lastname' => 'Three');
  $users[] = array('id' => 3, 'username' => 'kendev', 'firstname' => 'Ken', 'lastname' => 'DeVellis');
  $users[] = array('id' => 22, 'username' => 'mrand', 'firstname' => 'Mi', 'lastname' => 'Rand');
  $users[] = array('id' => 19, 'username' => 'philc', 'firstname' => 'Phil', 'lastname' => 'Cozens');
  $users[] = array('id' => 8, 'username' => 'student01', 'firstname' => 'Student', 'lastname' => 'One');
  $users[] = array('id' => 9, 'username' => 'student02', 'firstname' => 'Student', 'lastname' => 'Two');

  return $users;
}
