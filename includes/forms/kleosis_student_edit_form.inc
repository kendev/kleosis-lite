<?php
// $Id$

/**
 * @file
 *  kleosis Student Biodata edit form
 *  Provides the edit form for the additional student fields from the custom tables
 */

function build_ks_user_student_edit($theuser) {

  global $user;

  $ks_usertype = 'ks_student';
  $ks_user = ks_get_student_record($theuser->uid);

  if (empty($ks_user)) {
      $message = array('@user' => $theuser->name, '@notregistered' => t('is not registered in Kleosis'));
      drupal_set_message(t('Student @user @notregistered', $message));
      return FALSE;
  }
  $ks_primary_guardian_id = get_student_primary_guardian($theuser->uid);
  if (empty($ks_primary_guardian_id)) {
      //$message = array('@user' => $theuser->name, '@notregistered' => t('is not registered in Kleosis'));
      //drupal_set_message(t('Student @user @notregistered', $message));
      $guardian = FALSE;
  }
  else{
      $ks_primary_guardian = ks_get_parent_guardian_record($ks_primary_guardian_id);
      $guardian = TRUE;
  }

  $dob = (!empty($ks_user['date_of_birth'])) ? new DateTime($ks_user['date_of_birth']) : new DateTime('1900-01-01 0:0:00');
  $pped = (!empty($ks_user['passport_expiry_dt'])) ? new DateTime($ks_user['passport_expiry_dt']) : new DateTime('1900-01-01 0:0:00');
  $appd = (!empty($ks_user['application_date'])) ? new DateTime($ks_user['application_date']) : new DateTime('1900-01-01 0:0:00');
  $asd = (!empty($ks_user['anticipated_start_date'])) ? new DateTime($ks_user['anticipated_start_date']) : new DateTime('1900-01-01 0:0:00');
  $accd = (!empty($ks_user['acceptance_date'])) ? new DateTime($ks_user['acceptance_date']) : new DateTime('1900-01-01 0:0:00');
  $grdd = (!empty($ks_user['graduation_date'])) ? new DateTime($ks_user['graduation_date']) : new DateTime('1900-01-01 0:0:00');
  $eexd = (!empty($ks_user['entrance_exam_date'])) ? new DateTime($ks_user['entrance_exam_date']) : new DateTime('1900-01-01 0:0:00');

  $defaults = TRUE;  // will allow the form fields to show the user data

  $form['student_biodata'] = array(  // fieldset for biodata
      '#type' => 'fieldset',
      '#title' => t('Student Biodata'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -5,
    );

  $form['ks_user_type'] = array(  // this will not be shown on the form
      '#type' => 'value',
      '#value' => (isset($ks_usertype)) ? $ks_usertype : 'applicant'
    );
  $form['ks_student_type'] = array(  // this will not be shown on the form
      '#type' => 'value',
      '#value' => 'student',
    );
  $form['student_biodata']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $theuser->name : '',
    '#prefix' => '<div style="float: left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['identity_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Identity Id'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['identity_id'] : '',
    '#prefix' => '<div style="float: left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['gender'] = array(
    '#type' => 'radios',
    '#title' => t('Gender'),
    '#options' => array(t('Male'), t('Female')),
    '#default_value' => ($defaults)? $ks_user['gender'] : '',
    '#prefix' => '<div style="float: left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['fullname'] = array(
    '#type' => 'textfield',
    '#title' => t('Full Name'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['fullname']: '',
    '#prefix' => '<div style="float: left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['std_friendlyname'] = array(
    '#type' => 'textfield',
    '#title' => t('Friendly Name'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['friendlyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['familyname'] = array(
    '#type' => 'textfield',
    '#title' => t('Family Name'),
    '#size' => 30,
    '#maxlength' => 40,
    '#default_value' => ($defaults)? $ks_user['familyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
/*
  $form['student_biodata']['fullname_t'] = array(
    '#type' => 'textfield',
    '#title' => t('Name (national)'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['fullname_t']: '',
    '#prefix' => '<div style="float: left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['friendlyname_t'] = array(
    '#type' => 'textfield',
    '#title' => t('Friendly Name (national)'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['friendlyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['familyname_t'] = array(
    '#type' => 'textfield',
    '#title' => t('Family Name (national)'),
    '#size' => 30,
    '#maxlength' => 40,
    '#default_value' => ($defaults)? $ks_user['familyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
*/
  $form['student_biodata']['std_nationality'] = array(
    '#type' => 'textfield',
    '#title' => t('Nationality'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['nationality'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['date_of_birth'] = array(
    '#type' => 'date',
    '#title' => t('Date of birth'),
    '#default_value' => array(
       'month' => $dob->format('n'),
       'day' => $dob->format('j'),
       'year' => $dob->format('Y'),
      ),
    '#prefix' => '<div style="float: left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['religion'] = array(
    '#type' => 'textfield',
    '#title' => t('Religion'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['religion'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['student_biodata']['language_at_home'] = array(
    '#type' => 'textfield',
    '#title' => t('Language at Home'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['language_at_home'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['mobile_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Phone'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['mobile_phone'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['home_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Home Phone'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['home_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['other_phone_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Phone 1'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['other_phone_1'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

$form['student_biodata']['other_phone_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Phone 2'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['other_phone_2'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

$form['student_biodata']['passport_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Passport No.'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['passport_no'] : '',
    '#prefix' => '<div style="float:left;;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['passport_expiry_dt'] = array(
    '#type' => 'date',
    '#title' => t('Passport Expiry Date'),
    '#default_value' => array(
       'month' => $pped->format('n'),
       'day' => $pped->format('j'),
       'year' => $pped->format('Y'),
      ),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['passport_place_of_issue'] = array(
    '#type' => 'textfield',
    '#title' => t('Passport Place of Issue'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['passport_place_of_issue'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 1'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_1'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 2'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_2'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 3'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_3'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_city'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_region_state'] = array(
    '#type' => 'textfield',
    '#title' => t('Region-State'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_region_state'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_province'] = array(
    '#type' => 'textfield',
    '#title' => t('Province'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['address_province'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_country'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['address_country'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['address_zip_postalcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip-Postal Code'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['address_zip_postalcode'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_biodata']['remarks'] = array(
    '#type' => 'textarea',
    '#title' => t('Remarks'),
    '#cols' => 80,
    '#rows' => 3,
    '#default_value' => ($defaults)? $ks_user['remarks'] : '',
    '#resizeable' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  $form['student_admin_info'] = array(  // fieldset for admin info
      '#type' => 'fieldset',
      '#title' => t('Student Admin Info'),
      '#access' => ((in_array('administrator', $user->roles)) || (in_array('instructor', $user->roles))),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -4,
    );

  $form['student_admin_info']['curr_status'] = array(
    '#type' => 'select',
    '#title' => t('Current Status'),
    '#options' => get_student_statuses(),
    '#default_value' => ($defaults)? $ks_user['curr_status'] : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
   $form['student_admin_info']['set_curr_status'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Student Status'),
    '#markup' => l(t('Change Student Status'), 'kleosis/students/summary/setstatus/' . $ks_user['drp_uid_fk'], array('query' => array('ksid' => $ks_user['drp_uid_fk'], 'destination' => 'kleosis/students/summary'))),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
    );

  $form['student_admin_info']['curr_gradelevel'] = array(
    '#type' => 'select',
    '#title' => t('Current Grade Level'),
    '#options' => get_gradelevels(),
    '#default_value' => ($defaults)? $ks_user['curr_gradelevel'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['curr_campus'] = array(
    '#type' => 'select',
    '#title' => t('Current Campus'),
    '#options' => get_campuses(),
    '#default_value' => ($defaults)? $ks_user['curr_campus'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['curr_main_program'] = array(
    '#type' => 'select',
    '#title' => t('Current Main Program'),
    '#options' => ks_get_programs(),
    '#default_value' => ($defaults)? $ks_user['curr_main_program'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['curr_other_program'] = array(
    '#type' => 'select',
    '#title' => t('Current Other Program'),
    '#options' => ks_get_programs(),
    '#default_value' => ($defaults)? $ks_user['curr_other_program'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['acceptance_date'] = array(
    '#type' => 'date',
    '#title' => t('Acceptance Date'),
    '#default_value' => array(
       'month' => $accd->format('n'),
       'day' => $accd->format('j'),
       'year' => $accd->format('Y'),
      ),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['anticipated_start_date'] = array(
    '#type' => 'date',
    '#title' => t('Anticipated Start Date'),
    '#default_value' => array(
       'month' => $asd->format('n'),
       'day' => $asd->format('j'),
       'year' => $asd->format('Y'),
      ),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['application_date'] = array(
    '#type' => 'date',
    '#title' => t('Application Date'),
    '#default_value' => array(
       'month' => $appd->format('n'),
       'day' => $appd->format('j'),
       'year' => $appd->format('Y'),
      ),
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['reg_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Registration No.'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['reg_no'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['application_forms_signed'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Application Forms Signed'),
    '#options' => array('1' => ''),
    '#default_value' => array(  (!empty($ks_user['application_forms_signed'] )) ? $ks_user['application_forms_signed']  : 0),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['entrance_exam_date'] = array(
    '#type' => 'date',
    '#title' => t('Entrance Exam Date'),
    '#default_value' => array(
       'month' => $eexd->format('n'),
       'day' => $eexd->format('j'),
       'year' => $eexd->format('Y'),
      ),
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['entrance_exam_results'] = array(
    '#type' => 'textarea',
    '#title' => t('Entrance Exam Results'),
    '#cols' => 40,
    '#rows' => 3,
    '#default_value' => ($defaults)? $ks_user['entrance_exam_results'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['english_level_at_acceptance'] = array(
    '#type' => 'select',
    '#title' => t('English Level at Acceptance'),
    '#options' => get_english_levels(),
    '#default_value' => ($defaults)? $ks_user['english_level_at_acceptance'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['living_with'] = array(
    '#type' => 'select',
    '#title' => t('Residing with'),
    '#options' => get_residing_names(),
    '#default_value' => ($defaults)? $ks_user['living_with'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['transportation'] = array(
    '#type' => 'select',
    '#title' => t('Transportation'),
    '#options' => get_transportation_types(),
    '#default_value' => ($defaults)? $ks_user['transportation'] : 1,
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['graduation_date'] = array(
    '#type' => 'date',
    '#title' => t('Graduation Date'),
    '#default_value' => array(
       'month' => $grdd->format('n'),
       'day' => $grdd->format('j'),
       'year' => $grdd->format('Y'),
      ),
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_admin_info']['special_needs'] = array(
    '#type' => 'textarea',
    '#title' => t('Special Needs'),
    '#cols' => 80,
    '#rows' => 3,
    '#default_value' => ($defaults)? $ks_user['special_needs'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  $form['student_guardian_info'] = array(  // fieldset for guardian info
    '#type' => 'fieldset',
    '#title' => t('Student Guardian Info'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -3,
  );

  $form['student_guardian_info']['grd_fullname'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($guardian)? $ks_primary_guardian['fullname'] : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_guardian_info']['grd_set_guardian'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Primary Guardian'),
//    '#markup' => l(t('Set Primary Guardian'), 'kleosis/students/summary/setrelations/' . $ks_user['drp_uid_fk'], array('query' => array('destination' => 'user/' . $ks_user['drp_uid_fk'] . '/edit'))),
//    '#markup' => l(t('Set Primary Guardian'), 'kleosis/students/summary/setrelations/' . $ks_user['drp_uid_fk'], array('query' => array('ksid' => $ks_user['drp_uid_fk'], 'destination' => 'kleosis/students/summary'))),
    '#markup' => l(t('Set Primary Guardian'), 'kleosis/students/summary/setrelations/' . $ks_user['drp_uid_fk'], array('query' => array('ksid' => $ks_user['drp_uid_fk']))),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
    );

/*
  $form['student_guardian_info']['grd_relationship'] = array(
    '#type' => 'textfield',
    '#title' => t('Relationship'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($guardian)? get_user_relationship_desc($ks_primary_guardian['relationship']) : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</span></div><br/>',
  );
*/
  $form['student_guardian_info']['grd_nationality'] = array(
    '#type' => 'textfield',
    '#title' => t('Nationality'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($guardian)? $ks_primary_guardian['nationality'] : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_guardian_info']['grd_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($guardian)? '$email' : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_guardian_info']['grd_mobile_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Phone'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($guardian)? $ks_primary_guardian['mobile_phone'] : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_guardian_info']['grd_home_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Home Phone'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($guardian)? $ks_primary_guardian['home_phone'] : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_guardian_info']['grd_other_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Phone'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($guardian)? $ks_primary_guardian['other_phone'] : '',
    '#disabled' => TRUE,
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  $form['student_networking_info'] = array(  // fieldset for networking info
      '#type' => 'fieldset',
      '#title' => t('Student Networking Info'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => -2,
    );

  $form['student_networking_info']['website'] = array(
    '#type' => 'textfield',
    '#title' => t('Website'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['website'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  $form['student_networking_info']['sni_facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('facebook'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? 'http://www.facebook.com' : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</span></div><br/>',
  );
  $form['student_networking_info']['sni_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('twitter'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? 'http://www.twitter.com' : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_networking_info']['sni_social_network_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Social Network 3'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? 'social_network_3_link' : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['student_networking_info']['sni_social_network_4'] = array(
    '#type' => 'textfield',
    '#title' => t('Social Network 4'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? 'social_network_4_link' : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  return $form;
}
