<?php

/**
 * @file
 *  Kleosis Parent_Guardian Biodata edit form
 *
 *  Provides the edit form for the additional parent_guardian fields from the custom tables
 */

function build_ks_user_parent_guardian_edit($theuser) {

  global $user;

  $ks_usertype = 'ks_parent_guardian';
  $ks_user = ks_get_parent_guardian_record($theuser->uid);

  if (empty($ks_user)) {
      $message = array('@user' => $theuser->name, '@notregistered' => t('is not registered in Kleosis'));
      drupal_set_message(t('Parent_Guardian @user @notregistered', $message));
      return FALSE;
  }

  $bgnd = (!empty($ks_user['began_date'])) ? new DateTime($ks_user['began_date']) : new DateTime('1900-01-01 0:0:00');
  $endd = (!empty($ks_user['end_date'])) ? new DateTime($ks_user['end_date']) : new DateTime('1900-01-01 0:0:00');

  $defaults = TRUE;  // will allow the form fields to show the user data

  $form['parent_guardian_biodata'] = array(  // fieldset for biodata
      '#type' => 'fieldset',
      '#title' => t('Parent_Guardian Biodata'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -5,
    );
  $form['ks_user_type'] = array(  // this will not be shown on the form
      '#type' => 'value',
      '#value' => (isset($ks_usertype)) ? $ks_usertype : 'applicant',
    );
  $form['ks_parent_guardian_type'] = array(  // this will not be shown on the form
      '#type' => 'value',
      '#value' => 'parent_guardian',
    );

  $form['parent_guardian_biodata']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $theuser->name : '',
    '#prefix' => '<div style="float: left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['parent_guardian_biodata']['identity_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Identity Id'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['identity_id'] : '',
    '#prefix' => '<div style="float: left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['parent_guardian_biodata']['fullname'] = array(
    '#type' => 'textfield',
    '#title' => t('Full Name'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['fullname'] : '',
    '#prefix' => '<div style="float: left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['parent_guardian_biodata']['pgrd_friendlyname'] = array(
    '#type' => 'textfield',
    '#title' => t('Friendly Name'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['friendlyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['familyname'] = array(
    '#type' => 'textfield',
    '#title' => t('Family Name'),
    '#size' => 30,
    '#maxlength' => 40,
    '#default_value' => ($defaults)? $ks_user['familyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
/*
  $form['parent_guardian_biodata']['fullname_t'] = array(
    '#type' => 'textfield',
    '#title' => t('Name (national)'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['fullname_t']: '',
    '#prefix' => '<div style="float: left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['parent_guardian_biodata']['friendlyname_t'] = array(
    '#type' => 'textfield',
    '#title' => t('Friendly Name (national)'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['friendlyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['familyname_t'] = array(
    '#type' => 'textfield',
    '#title' => t('Family Name (national)'),
    '#size' => 30,
    '#maxlength' => 40,
    '#default_value' => ($defaults)? $ks_user['familyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
*/
  $form['parent_guardian_biodata']['pgrd_nationality'] = array(
    '#type' => 'textfield',
    '#title' => t('Nationality'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['nationality'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['parent_guardian_biodata']['occupation'] = array(
    '#type' => 'textfield',
    '#title' => t('Occupation'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['occupation'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['parent_guardian_biodata']['mobile_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Phone'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['mobile_phone']: '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['home_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Home Phone'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['home_phone'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['office_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Office Phone'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['office_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['other_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Phone'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['other_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 1'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_1'] : '',
    '#prefix' => '<div style="float:left;clear:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['address_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 2'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_2'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['address_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 3'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_3'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['address_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_city'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['address_region_state'] = array(
    '#type' => 'textfield',
    '#title' => t('Region-State'),
    '#size' => 35,
    '#maxlength' => 48,
    '#default_value' => ($defaults)? $ks_user['address_region_state'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
    $form['parent_guardian_biodata']['address_province'] = array(
    '#type' => 'textfield',
    '#title' => t('Province'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['address_province'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['address_country'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#size' => 24,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $ks_user['address_country'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['address_zip_postalcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip-Postal Code'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $ks_user['address_zip_postalcode'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_biodata']['remarks'] = array(
    '#type' => 'textarea',
    '#title' => t('Remarks'),
    '#cols' => 80,
    '#rows' => 3,
    '#default_value' => ($defaults)? $ks_user['remarks'] : '',
    '#resizeable' => TRUE,
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
////////////////////////////////////////////////////////////
  $form['parent_guardian_admin_info'] = array(  // fieldset for admin info
      '#type' => 'fieldset',
      '#title' => t('Parent_Guardian Admin Info'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -4,
    );
  $form['parent_guardian_admin_info']['curr_status'] = array(
    '#type' => 'select',
    '#title' => t('Current Status'),
    '#options' => get_instructor_statuses(),
    '#default_value' => ($defaults)? $ks_user['curr_status'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_admin_info']['began_date'] = array(
    '#type' => 'date',
    '#title' => t('Date Started'),
    '#default_value' => array(
       'month' => $bgnd->format('n'),
       'day' => $bgnd->format('j'),
       'year' => $bgnd->format('Y'),
      ),
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['parent_guardian_admin_info']['end_date'] = array(
    '#type' => 'date',
    '#title' => t('Date Ended'),
    '#default_value' => array(
       'month' => $endd->format('n'),
       'day' => $endd->format('j'),
       'year' => $endd->format('Y'),
      ),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

//  $form[] = ks_pg_get_formcat_common();

  return $form;
}

/*
// experimental....
function ks_pg_get_formcat_common() {

  $formcat = array();
  $formcat['lecategory01']['country'] = array(
      '#type' => 'user_profile_category',
      '#title' => t('Country'),
    );
  $formcat['lecategory02']['planet'] = array(
      '#type' => 'user_profile_category',
      '#title' => t('Planet'),
    );
  return $formcat;
}
*/
