<?php
// $Id$

/**
 * @file
 *  kleosis Student Biodata view form
 *  Provides the view form for the additional student fields from the custom tables
 */

function build_ks_user_student_view($account, $view_mode, $langcode) {

  $ks_usertype = 'ks_student';
  $ks_user = ks_get_student_record($account->uid);
  if (empty($ks_user)) {
      $message = array('@user' => $account->name, '@notregistered' => t('is not registered in Kleosis'));
      drupal_set_message(t('Student @user @notregistered', $message));
      return FALSE;
  }
  $ks_primary_guardian_id = get_student_primary_guardian($account->uid);
  if (empty($ks_primary_guardian_id)) {
     // $message = array('@user' => $account->name, '@notregistered' => t('is not registered in Kleosis'));
     // drupal_set_message(t('Student @user @notregistered', $message));
      $guardian = FALSE;
  }
  else {
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
/*
  $dob = (!empty($ks_user['date_of_birth'])) ?
          DateTime::createFromFormat('Y-m-d H:i:s', $ks_user['date_of_birth']) :
            DateTime::createFromFormat('Y-m-d H:i:s', '1900-01-01 0:0:00');
*/
  $defaults = TRUE;  // will allow the form fields to show the user data

  $account->content['student_biodata'] = array(  // fieldset for biodata
      '#type' => 'fieldset',
      '#title' => t('Student Biodata for:') . ' ' . ks_get_usernames_for_display($account->uid),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -50,
/*
      '#attached' => array(
        'js' => array(
          'misc/form.js',
          'misc/collapse.js',
          ),
        ),
      '#attributes' => array(
          'class' => array('collapsible', 'collapsed'),
        ),
*/
    );
  $account->content['ks_user_type'] = array(  // this will not be shown on the form
      '#type' => 'value',
      '#value' => (isset($ks_usertype)) ? $ks_usertype : 'applicant'
    );

  $account->content['student_biodata']['username'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Username'),
    '#markup' => ($defaults)? l($account->name , 'user/' . $account->uid . '/edit', array('query' => array())) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['student_biodata']['identity_id'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Identity ID'),
    '#markup' => ($defaults)? $ks_user['identity_id'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['student_biodata']['gender'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Gender'),
    '#markup' => ($defaults)? (($ks_user['gender'] == 0) ? 'Male' : 'Female') : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['student_biodata']['fullname'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Full Name'),
    '#markup' => ($defaults)? $ks_user['fullname']: '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['student_biodata']['friendlyname'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Friendly Name'),
    '#markup' => ($defaults)? $ks_user['friendlyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['familyname'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Family Name'),
    '#markup' => ($defaults)? $ks_user['familyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
/*
  if (!(empty($fullname_t))) {
  $account->content['student_biodata']['fullname_t'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Name (national)'),
    '#markup' => ($defaults)? $ks_user['fullname_t'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
}
  if (!(empty($friendlyname_t))) {
  $account->content['student_biodata']['friendlyname_t'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Friendly Name (national)'),
    '#markup' => ($defaults)? $ks_user['friendlyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
}
  if (!(empty($familyname_t))) {
  $account->content['student_biodata']['familyname_t'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Family Name (national)'),
    '#markup' => ($defaults)? $ks_user['familyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
}
*/
  $account->content['student_biodata']['nationality'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Nationality'),
    '#markup' => ($defaults)? $ks_user['nationality'] : 0,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['student_biodata']['date_of_birth'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Date of Birth'),
    '#markup' => ($defaults)? $dob->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['student_biodata']['religion'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Religion'),
    '#markup' => ($defaults)? $ks_user['religion'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['language_at_home'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Language at Home'),
    '#markup' => ($defaults)? $ks_user['language_at_home'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['email'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Email'),
    '#markup' => ($defaults)? $account->mail : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['mobile_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Mobile Phone'),
    '#markup' => ($defaults)? $ks_user['mobile_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['home_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Home Phone'),
    '#markup' => ($defaults)? $ks_user['home_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['other_phone_1'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Other Phone 1'),
    '#markup' => ($defaults)? $ks_user['other_phone_1'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['other_phone_2'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Other Phone 2'),
    '#markup' => ($defaults)? $ks_user['other_phone_2'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['passport_no'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Passport No.'),
    '#markup' => ($defaults)? $ks_user['passport_no'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['passport_expiry_dt'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Passport Expiry Date'),
    '#markup' => ($defaults)? $pped->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['passport_place_of_issue'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Passport Place of Issue'),
    '#markup' => ($defaults)? $ks_user['passport_place_of_issue'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_1'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Address 1'),
    '#markup' => ($defaults)? $ks_user['address_1'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_2'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Address 2'),
    '#markup' => ($defaults)? $ks_user['address_2'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_3'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Address 3'),
    '#markup' => ($defaults)? $ks_user['address_3'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_city'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('City'),
    '#markup' => ($defaults)? $ks_user['address_city'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_region_state'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Region-State'),
    '#markup' => ($defaults)? $ks_user['address_region_state'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_province'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Province'),
    '#markup' => ($defaults)? $ks_user['address_province'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_country'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Country'),
    '#markup' => ($defaults)? $ks_user['address_country'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['address_zip_postalcode'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Zip-Postal Code'),
    '#markup' => ($defaults)? $ks_user['address_zip_postalcode'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_biodata']['remarks'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Remarks'),
    '#markup' => ($defaults)? $ks_user['remarks'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  $account->content['student_admin_info'] = array(  // fieldset for admin info
      '#type' => 'fieldset',
      '#title' => t('Student Admin Info'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -45,
 /*
      '#attached' => array(
        'js' => array(
          'misc/form.js',
          'misc/collapse.js',
          ),
        ),
      '#attributes' => array(
          'class' => array('collapsible', 'collapsed'),
        ),
 */
    );

  $account->content['student_admin_info']['curr_status'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Current Status'),
    '#markup' => ($defaults)? get_student_status_desc($ks_user['curr_status']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['curr_gradelevel'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Current Grade Level'),
    '#markup' => ($defaults)? get_gradelevel_desc($ks_user['curr_gradelevel']) : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</span></div><br/>',
  );
  $account->content['student_admin_info']['curr_campus'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Current Campus'),
    '#markup' => ($defaults)? get_campus_desc($ks_user['curr_campus']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</span></div><br/>',
  );
  $account->content['student_admin_info']['curr_main_program'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Current Main Program'),
    '#markup' => ($defaults)? get_program_desc($ks_user['curr_main_program']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['curr_other_program'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Current Other Program'),
    '#markup' => ($defaults)? get_program_desc($ks_user['curr_other_program']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['acceptance_date'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Acceptance Date'),
    '#markup' => ($defaults)? $accd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['anticipated_start_date'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Anticipated Start Date'),
    '#markup' => ($defaults)? $asd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['application_date'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Application Date'),
    '#markup' => ($defaults)? $appd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['reg_no'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Registration No.'),
    '#markup' => ($defaults)? $ks_user['reg_no'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</span></div><br/>',
  );
  $account->content['student_admin_info']['application_forms_signed'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Application Forms Signed'),
    '#markup' => ($defaults)? (($ks_user['application_forms_signed'] == 1) ? 'Yes' : 'No') : 'No',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['entrance_exam_date'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Entrance Exam Date'),
    '#markup' => ($defaults)? $eexd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['entrance_exam_results'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Entrance Exams Results'),
    '#markup' => ($defaults)? $ks_user['entrance_exam_results'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['english_level_at_acceptance'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('English Level at Acceptance'),
    '#markup' => ($defaults)? get_english_level_desc($ks_user['english_level_at_acceptance']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['living_with'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Residing with'),
    '#markup' => ($defaults)? get_residing_desc($ks_user['living_with']) : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['transportation'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Transportation'),
    '#markup' => ($defaults)? get_transportation_type_desc($ks_user['transportation']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['graduation_date'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Graduation Date'),
    '#markup' => ($defaults)? $grdd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_admin_info']['special_needs'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Special Needs'),
    '#markup' => ($defaults)? $ks_user['special_needs'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  if (!$guardian) {
  $account->content['student_guardian_info'] = array(  // fieldset for guardian info
      '#type' => 'fieldset',
      '#title' => t('Student Guardian Info'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -40,
      '#attached' => array(
        'js' => array(
          'misc/form.js',
          'misc/collapse.js',
          ),
        ),
      '#attributes' => array(
          'class' => array('collapsible', 'collapsed'),
        ),
    );
  $account->content['student_guardian_info']['grd_set_guardian'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Primary Guardian for this student has not been set.'),
 //   '#markup' => l('Set Primary Guardian' , 'kleosis/processes/devcode/' , array('query' => array())),
    '#markup' => '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
    );

  }
  else {
  $account->content['student_guardian_info'] = array(  // fieldset for guardian info
      '#type' => 'fieldset',
      '#title' => t('Student Guardian Info'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -40,
      '#attached' => array(
        'js' => array(
          'misc/form.js',
          'misc/collapse.js',
          ),
        ),
      '#attributes' => array(
          'class' => array('collapsible', 'collapsed'),
        ),
    );

  $account->content['student_guardian_info']['grd_fullname'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Name'),
    '#markup' => ($guardian)? l($ks_primary_guardian['fullname'] , 'user/' . $ks_primary_guardian_id, array('query' => array())) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
    );
/*
  $account->content['student_guardian_info']['grd_relationship'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Relationship'),
    '#markup' => ($guardian)? '$relationship' : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</span></div><br/>',
  );
*/
  $account->content['student_guardian_info']['grd_nationality'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Nationality'),
    '#markup' => ($guardian)? $ks_primary_guardian['nationality'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_guardian_info']['grd_email'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Email'),
    '#markup' => ($guardian)? '$email' : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_guardian_info']['grd_mobile_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Mobile Phone'),
    '#markup' => ($guardian)? $ks_primary_guardian['mobile_phone'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_guardian_info']['grd_home_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Home Phone'),
    '#markup' => ($guardian)? $ks_primary_guardian['home_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_guardian_info']['grd_other_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Other Phone'),
    '#markup' => ($guardian)? $ks_primary_guardian['other_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
/*
  $account->content['student_guardian_info']['details_link'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Guardian details link'),
    '#markup' => ($guardian)? 'details' : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
*/
}  // end if_guardian

  $account->content['student_networking_info'] = array(  // fieldset for networking info
    '#type' => 'fieldset',
    '#title' => t('Student Networking Info'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -35,
      '#attached' => array(
        'js' => array(
          'misc/form.js',
          'misc/collapse.js',
          ),
        ),
      '#attributes' => array(
          'class' => array('collapsible', 'collapsed'),
        ),
  );

  $account->content['student_networking_info']['website'] = array(
    '#type' => 'link',
    '#title' => ($defaults)? $ks_user['website'] : '',
    '#href' => ($defaults)? $ks_user['website'] : '',
    //'#options' => array('query' => array('target' => '_blank')),
    '#prefix' => '<div style="float:left;width:275px"><strong>Website</strong><br/>',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_networking_info']['sni_facebook'] = array(
    '#type' => 'link',
    '#title' => t('facebook'),
    '#href' => 'http://www.facebook.com',
    //'#options' => $uri['options'],  // url options go here
    '#prefix' => '<div style="float:left;clear:left;width:275px"><strong>facebook</strong><br/>',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_networking_info']['sni_twitter'] = array(
    '#type' => 'link',
    '#title' => t('twitter'),
    '#href' => 'http://www.twitter.com',
    //'#options' => $uri['options'],  // url options go here
    '#prefix' => '<div style="float:left;width:275px"><strong>twitter</strong><br/>',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_networking_info']['sni_social_network_3'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Social Network 3'),
    '#markup' => ($defaults)? 'social_network_3_link' : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['student_networking_info']['sni_social_network_4'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Social Network 4'),
    '#markup' => ($defaults)? 'social_network_4_link' : '',
    '#prefix' => '<div style="float:left;width:275px">',
    '#suffix' => '</div><br/>',
  );

}



