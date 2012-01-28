
<?php
// $Id$

/**
 * @file
 *  kleosis User Login and Registration functions
 *  Provides the forms and functionality for the additional user fields from the custom tables
 */

require_once ('kleosis_ws.inc');  // webservices wrapper functions
require_once ('kleosis_db_lib.inc');  // lib functions

/**
 *
 * Implementation of hook_form_alter()
 *
 */
function kleosis_form_alter(&$form, &$form_state, $form_id) {

  // check to see if the form is the user registration or user profile form
  // if not, then just return...

  if (!($form_id == 'user_register_form' || $form_id == 'user_profile_form')) {
      return;
    }
  //dpm($form_id);

  $defaults = FALSE;  // will blank all fields on the form
  if ($form_id == 'user_profile_form') {
  // then prepare to create the additional form fields from the custom tables if conditions are met
  $thename = $form_state['build_info']['args'][0]->name;  // get the users name from the $form_state
  if (!empty($thename)) {  //  if $thename is empty, then do nothing.
    // load the user object and determine the user's role(s)
    $theuser = user_load($form_state['build_info']['args'][0]->uid);

    // read the ks_students or ks_users custom table and populate defaults for editing

    $ks_usertype = '';
    if ( (in_array('student', $theuser->roles)) ) {
      $ks_usertype = 'ks_student';
      require_once('forms/kleosis_student_edit_form.inc');
      $form['account'][] = build_ks_user_student_edit($theuser);

    /***---------------------------------------------------------------------------------------------------------***/
    /*------------------------     example code to edit abother node in the biodata page:     ---------------------*/
    /***---------------------------------------------------------------------------------------------------------***/

            //     $node = node_load(19);  // node 19 needs to exist (demo)     // this works
            //     field_attach_form('node', $node, &$form, &$form_state);      // with this

            //     $form['account']['a_node_fieldset'] = array(    // todo: try to get this working :)
            //       '#type' => 'fieldset',
            //       '#title' => 'le node fieldset title',
            //     );

    /***---------------------------------------------------------------------------------------------------------***/
    /***---------------------------------------------------------------------------------------------------------***/

    }
    if ((in_array('instructor', $theuser->roles)) ) {
        $ks_usertype = 'ks_instructor';
        require_once('forms/kleosis_instructor_edit_form.inc');
        $form['account'][] = build_ks_user_instructor_edit($theuser);
    }
    if ((in_array('parent_guardian', $theuser->roles)) ) {
        $ks_usertype = 'ks_parent_guardian';
        require_once('forms/kleosis_parent_guardian_edit_form.inc');
        $form['account'][] = build_ks_user_parent_guardian_edit($theuser);
    }
    //  else {
    //      drupal_set_message(t('User does not have an SIS role.'));
    //      return;
    //  }

    // add a new validate function for the Users SIS Info
    // $form['#validate'][] = 'kleosis_user_profile_form_validate';
    array_unshift($form['#validate'], 'kleosis_user_profile_form_validate');
    // todo: review this function's functionality...

    // add a new submit function for the Users SIS Info
    // $form['#submit'][] = 'kleosis_user_profile_form_submit';
    array_unshift($form['#submit'], 'kleosis_user_profile_form_submit');
    // todo: review this function's functionality...

    } // end of if !empty($thename))
} // end of if user_profile_form

  if ($form_id == 'user_register_form') { // this will be displayed when a user first creates an account

    $form['account']['new_applicant_type'] = array(
      '#type' => 'fieldset',
      '#title' => t('Account Type'),
      );
    $form['account']['new_applicant_type']['appl_type'] = array(
      '#type' => 'radios',
      '#description' => t('Select the type of user account you are applying for.'),
      '#default_value' => 5,
      '#options' => array(t('Student'), t('Instructor'), t('Parent_Guardian'), t('Other'))
      );
    $form['account']['new_applicant_type']['appl_phones'] = array(
      '#type' => 'textarea',
      '#description' => t('Please enter phone numbers that you can be contacted with.'),
      '#title' => t('Contact phone numbers'),
      '#cols' => 40,
      '#rows' => 3,
      '#default_value' => '',
      '#resizeable' => TRUE,
      '#prefix' => '<div style="float:left;clear:left;width:350px" >',
      '#suffix' => '</div><br/>'
      );
    $form['account']['new_applicant_type']['demo_message'] = array(
      '#markup' => 'Note to Kleosis demo users: the Account Type radio buttons and Contact phone numbers textarea on the left are examples demonstrating that input fields can be added to this registration form.',
      '#prefix' => '<div style="float:left;width:350px" >',
      '#suffix' => '</div><br/>'
      );
    }
} // end of kleosis_form_alter()

/**
 *
 * Implementation of form_validate() for the Users SIMS Info data.
 *
 */
function kleosis_user_profile_form_validate($form, &$form_state) {

//  todo: possibly implement this...
//  watchdog('user', 'kleosis_user_profile_form_validate($form, &$form_state) ');
}

/**
 *
 * Implementation of form_submit() for the Users SIMS Info data.
 *
 */
function kleosis_user_profile_form_submit($form, &$form_state) {

//  todo: possibly expand this...
//  watchdog('user', 'kleosis_user_profile_form_submit($form, &$form_state) ');
//    $form_state['redirect'] = 'user';
}

/**
 *
 * Implementation of hook_user_insert() for the Users SIMS Info data.
 *
 */
function kleosis_user_insert(&$edit, $account, $category) {

//   todo: rework and expand this functionality when the registration process is better defined.
//   for example, can set role to Applicant and store any additional info from registration form

  if ( (isset($edit['appl_type']) ) && (isset($edit['appl_phones'])) ) { // not set during install of test users...

     $applicant_type = 'Other';
     switch ($edit['appl_type']) {
         case 0:
             $applicant_type = 'Student';
             break;
         case 1:
             $applicant_type = 'Instructor';
             break;
         case 2:
             $applicant_type = 'Parent_Guardian';
             break;
         case 3:
             $applicant_type = 'Other';
             break;
    }
    //  can optionally assign the 'applicant' role now.  todo: review this.  if activated, it currently suppresses the auto email...
    //  ks_assign_new_role_($edit['uid'], 'applicant');

    watchdog('Applicant', 'New Applicant Request: %name Applicant Type: (%appl_type) Phone Numbers: %phonenos ', array('%name' => $edit['name'], '%appl_type' => $applicant_type, '%phonenos' => $edit['appl_phones']));
  }

}

/**
 *
 * Implementation of hook_user_update() for the Kleosis biodata
 *
 */
function kleosis_user_update(&$edit, $account, $category) {

  // todo: maybe also update the user in moodle - if user does not exist, maybe create the user as well...


  if (!(isset($edit['ks_user_type']) )) {
    // then probably arrived here from the people administration page after a role assign or unassign,
    // and need to do the following:
    //    determine if the user has more than one kleosis role, if not, then just return
    //      because initial registration into Kleosis is done thru hook_user_operations, not here
    //    if more than one kleosis role, then determine if the user already exists in the ks_students
    //      and ks_users tables with those roles.
    //    if yes, then just return - nothing to do
    //    if not, then add the user's info from the populated table to the unpopulated one and
    //        set the usertype in the ks_users table (if appropriate)
    //    return

//dpm('inside user_update()');
    if (!ks_user_has_multiple_roles($account)) {
        return;
    }

    $ks_student_exists = ks_check_exists_userrecord('ks_student', $account->uid);
    $ks_instructor_exists = ks_check_exists_userrecord('ks_instructor', $account->uid);
    $ks_parent_guardian_exists = ks_check_exists_userrecord('ks_parent_guardian', $account->uid);

    if ( $ks_student_exists && $ks_instructor_exists && $ks_parent_guardian_exists ) {
        return;
    }

    /* Here begins a fun logic tree - need to determine what user record to copy where... */

    // obtain the newly selected role from $edit
    $newrolea = array();
    $newrole = array_diff($edit['roles'], $edit['original']->roles);
    foreach ($newrole as $key => $value) {  //  should only be one
          $newrolea[] = $value;;
    }
   if (!(count($newrolea))) {
     return;
   }
   $newrole = $newrolea[0];

  if ($newrole == 'student') {
    if ($ks_instructor_exists && !$ks_student_exists) {
      $message = array('@user' => $account->name, '@added' => t('will be added as a ks_student.'));
      drupal_set_message(t('Instructor @user @added', $message));
      $ret = ks_copy_ks_user_to_ks_student($account->uid, 'ks_instructor');
    }
    elseif ($ks_parent_guardian_exists && !$ks_student_exists) {
      $message = array('@user' => $account->name, '@added' => t('will be added as a ks_student.'));
      drupal_set_message(t('Parent_Guardian @user @added', $message));
      $ret = ks_copy_ks_user_to_ks_student($account->uid, 'ks_parent_guardian');
    }
  }
  if ($newrole == 'instructor') {
    if ($ks_parent_guardian_exists && !$ks_instructor_exists) {
      $message = array('@user' => $account->name, '@added' => t('will be added as a ks_instructor.'));
      drupal_set_message(t('Parent_Guardian @user @added', $message));
      $ret = ks_copy_ks_user_to_ks_user($account->uid, 'ks_instructor');
    }
    elseif ($ks_student_exists && !$ks_instructor_exists) {
      $message = array('@user' => $account->name, '@added' => t('will be added as a ks_instructor.'));
      drupal_set_message(t('Student @user @added', $message));
      $ret = ks_copy_ks_student_to_ks_user($account->uid, 'ks_instructor');
    }
  }
  if ($newrole == 'parent_guardian') {
    if ($ks_instructor_exists && !$ks_parent_guardian_exists) {
      $message = array('@user' => $account->name, '@added' => t('will be added as a ks_parent_guardian.'));
      drupal_set_message(t('Instructor @user @added', $message));
      $ret = ks_copy_ks_user_to_ks_user($account->uid, 'ks_parent_guardian');
    }
    elseif ($ks_student_exists && !$ks_parent_guardian_exists) {
      $message = array('@user' => $account->name, '@added' => t('will be added as a ks_parent_guardian.'));
      drupal_set_message(t('Parent Guardian @user @added', $message));
      $ret = ks_copy_ks_student_to_ks_user($account->uid, 'ks_parent_guardian');
    }
  }

     return;
  }

//dpm($edit);

  if (isset($edit['ks_student_type'])) {
//    $cnt = ks_update_student_record(&$edit);
    $cnt = ks_update_student_record($edit);
    $le_name = (isset($edit['name'])) ? $edit['name'] : '';
    $message = array('@user' => $le_name, '@updated' => t('has been updated.'));
    drupal_set_message(t('Student @user @updated', $message));
  }

  if (isset($edit['ks_instructor_type'])) {
//    $cnt = ks_update_instructor_record(&$edit);
    $cnt = ks_update_instructor_record($edit);
    $le_name = (isset($edit['name'])) ? $edit['name'] : '';
    $message = array('@user' => $le_name, '@updated' => t('has been updated.'));
    drupal_set_message(t('Instructor @user @updated', $message));
  }

  if (isset($edit['ks_parent_guardian_type'])) {
//    $cnt = ks_update_parent_guardian_record(&$edit);
    $cnt = ks_update_parent_guardian_record($edit);
    $le_name = (isset($edit['name'])) ? $edit['name'] : '';
    $message = array('@user' => $le_name, '@updated' => t('has been updated.'));
    drupal_set_message(t('Parent_Guardian @user @updated', $message));
  }
}

/**
 *
 * Implementation of hook_user_operations()
 *
 */
function kleosis_user_operations()  {

  $operations = array(
    'ks_add_new_user' => array(
      'label' => t('Register the selected users into Kleosis'),
      'callback' => 'kleosis_user_operations_reg_new_user',
    ),
   );
  return $operations;
}

/**
 *
 *  Callback function for hook_user_operations()
 *  Creates the new user in the ks_users or ks_students table
 *  as well as in moodle
 *
 *  @param - $cusers, and array of drupal user ids
 *
 */
function kleosis_user_operations_reg_new_user($cusers)  {
//  drupal_set_message('kleosis_user_operations_reg_new_user() has been called... ');

  foreach ($cusers as $cuser) {
 // determine the user role - student, instructor, or parent-guardian
    $theuser = user_load($cuser);
    $has_multiple_roles = ks_user_has_multiple_roles($theuser);
    if ($has_multiple_roles) {
      $message = array('@user' => $theuser->name, '@onename' => t('should only have one Kleosis role assigned during user registration. Please temporarily assign only the users primary role.'));
      drupal_set_message(t('User @user @onename', $message));
      return;
      }
    if ( (in_array('applicant', $theuser->roles)) ) {  // todo: determine if the applicant role should exist
      // todo: review whether the moodle user should be created here:
      $mdl_uid = ks_create_moodleuser($theuser);  // create user in moodle ( ok if user already exists in moodle)
     // drupal_set_message('User '. $theuser->name . ' is an Applicant - cannot be registered until this role is changed.');
      return;
      }
    // if  only an authenticated user, then return
    if ( (in_array('student', $theuser->roles)) ) {
          $ks_usertype = 'ks_student';
      }
      elseif ((in_array('instructor', $theuser->roles)) ) {
          $ks_usertype = 'ks_instructor';
      }
      elseif ((in_array('parent_guardian', $theuser->roles)) ) {
          $ks_usertype = 'ks_parent_guardian';
      }
      elseif ((in_array('authenticated user', $theuser->roles)) && (count($theuser->roles == 1) ) ) {
          $message = array('@user' => $theuser->name, '@assignrole' => t('must be assigned a kleosis role to be registered. Please contact the administrator to assign a role.'));
          drupal_set_message(t('User @user @assignrole', $message));
          return;
      }

    $mdl_uid = ks_create_moodleuser($theuser);  // create user in moodle ( ok if user already exists in moodle)

    // determine if user already exists in the user extension tables
    $result = ks_check_exists_userrecord($ks_usertype, $theuser->uid);
    //  dpm($result);
    if (!empty($result) ) {
      ks_update_moodle_uid($ks_usertype, $cuser, $mdl_uid);
      $message = array('@user' => $theuser->name, '@updated' => t('has been successfully updated.'));
      drupal_set_message(t('User @user @updated', $message));
//      return;
    }
    else {
      // create the user in a kleosis user extension table
      $ret = ks_insert_user_record($ks_usertype, $theuser->uid, $mdl_uid);  // todo: verify this
      $message = array('@user' => $theuser->name, '@registered' => t('has been successfully registered.'));
      drupal_set_message(t('User @user @registered', $message));
    }
  }
}

/**
 *
 * Create a new user in moodle
 *
 *  @param
 *    $auser: user object
 *
 *  @return
 *    the new user's mdl_uid
 *
 */
function ks_create_moodleuser($auser) {

  $muser = ws_get_user($auser->name, 'username');
  if ((isset($muser[0]['id'])) && ($muser[0]['id'] > 0) ) {
    $mdl_uid = $muser[0]['id']; // moodle user exists already, get the id
  }
  else {
    $newuser = array('drp_uid' => $auser->uid,    // todo: determine other user fields to send to moodle
                  'username' => $auser->name,
                  'firstname' => $auser->name . '-fn',
                  'lastname' => $auser->name . '-ln',
                  'email' => $auser->mail);
    $muser = ws_add_user($newuser);  // todo: error checking
    $mdl_uid = $muser->users[0]->id;

    if ($mdl_uid > 0) {
      $message = array('@user' => $auser->name, '@created' => t('has been successfully created in moodle.'));
      drupal_set_message(t('User @user @created', $message));
    }
  }
  return $mdl_uid;
}

/**
 *
 * Implementation of hook_user_view() for the users kleosis biodata.
 *
 */
function kleosis_user_view($account, $view_mode, $langcode) {

  $defaults = FALSE;  // will blank all fields on the form
  $ks_usertype = '';

  if (ks_user_has_multiple_roles($account)) {
      $message = array('@user' => $account->name, '@multipleroles' => t("has multiple roles."));
      drupal_set_message(t('User @user @multipleroles', $message));
  }

  // read the kleosis_student or ks_users custom table and populate defaults for viewing

  if ((in_array('student', $account->roles))) {
      $ks_usertype = 'ks_student';
      require_once('forms/kleosis_student_view_form.inc');
      build_ks_user_student_view($account, $view_mode, $langcode);
  }
  if ((in_array('instructor', $account->roles)) ) {
      $ks_usertype = 'ks_instructor';
      require_once('forms/kleosis_instructor_view_form.inc');
      build_ks_user_instructor_view($account, $view_mode, $langcode);
  }
  if ((in_array('parent_guardian', $account->roles)) ) {
      $ks_usertype = 'ks_parent_guardian';
      require_once('forms/kleosis_parent_guardian_view_form.inc');
      $account->content[] = build_ks_user_parent_guardian_view($account, $view_mode, $langcode);
  }

  /***---------------------------------------------------------------------------------------------------------***/
  /*-----------------------     example code to show another node in the biodata page:     ----------------------*/
  /***---------------------------------------------------------------------------------------------------------***/

          //  $node = node_load(19);  // node 19 needs to exist (demo)  // this works
          //  $account->content['another_node'] = node_view($node);     // with this - (try to wrap with fieldset)

  /***---------------------------------------------------------------------------------------------------------***/
  /***---------------------------------------------------------------------------------------------------------***/

}

/**
 *
 * Determine if user has multiple kleosis roles
 *
 *  @param
 *    $theuser: user account
 *
 *  @return
 *    TRUE or FALSE
 *
 */
function ks_user_has_multiple_roles($theuser) {

  if ( (in_array('student', $theuser->roles)) && ( (in_array('instructor', $theuser->roles)) || (in_array('parent_guardian', $theuser->roles)) )) {
    return TRUE;
  }
  if ( (in_array('instructor', $theuser->roles)) && ( (in_array('student', $theuser->roles)) || (in_array('parent_guardian', $theuser->roles)) )) {
    return TRUE;
  }
  if ( (in_array('parent_guardian', $theuser->roles)) && ( (in_array('student', $theuser->roles)) || (in_array('instructor', $theuser->roles)) )) {
    return TRUE;
  }
  return FALSE;
}