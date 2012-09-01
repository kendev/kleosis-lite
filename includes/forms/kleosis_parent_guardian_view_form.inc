<?php

/**
 * @file
 *  Kleosis Parent_Guardian Biodata view form
 *
 *  Provides the view form for the additional parent_guardian fields from the custom tables
 */

function build_ks_user_parent_guardian_view($account, $view_mode, $langcode) {

  $ks_usertype = 'ks_parent_guardian';
  $ks_user = ks_get_parent_guardian_record($account->uid);

  if (empty($ks_user)) {
      $message = array('@user' => $account->name, '@notregistered' => t('is not registered in Kleosis'));
      drupal_set_message(t('Parent_Guardian @user @notregistered', $message));
      return FALSE;
  }

  $bgnd = (!empty($ks_user['began_date'])) ? new DateTime($ks_user['began_date']) : new DateTime('1900-01-01 0:0:00');
  $endd = (!empty($ks_user['end_date'])) ? new DateTime($ks_user['end_date']) : new DateTime('1900-01-01 0:0:00');

  $defaults = TRUE;  // will allow the form fields to show the user data

  $account->content['parent_guardian_biodata'] = array(  // fieldset for biodata
    '#type' => 'fieldset',
    '#title' => t('Parent_Guardian Biodata'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -10,
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

  $account->content['parent_guardian_biodata']['username'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Username'),
//    '#markup' => ($defaults)? $account->name : '',
    '#markup' => ($defaults)? l($account->name , 'user/' . $account->uid . '/edit', array('query' => array())) : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['parent_guardian_biodata']['identity_id'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Identity ID'),
    '#markup' => ($defaults)? $ks_user['identity_id'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['parent_guardian_biodata']['fullname'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Full Name'),
    '#markup' => ($defaults)? $ks_user['fullname'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['parent_guardian_biodata']['friendlyname'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Friendly Name'),
    '#markup' => ($defaults)? $ks_user['friendlyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  $account->content['parent_guardian_biodata']['familyname'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Family Name'),
    '#markup' => ($defaults)? $ks_user['familyname'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

/*
  if (!(empty($fullname_t))) {
  $account->content['parent_guardian_biodata']['fullname_t'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Name (national)'),
    '#markup' => ($defaults)? $ks_user['fullname_t'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
}
  if (!(empty($friendlyname_t))) {
  $account->content['parent_guardian_biodata']['friendlyname_t'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Friendly Name (national)'),
    '#markup' => ($defaults)? $ks_user['friendlyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
}
  if (!(empty($familyname_t))) {
  $account->content['parent_guardian_biodata']['familyname_t'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Family Name (national)'),
    '#markup' => ($defaults)? $ks_user['familyname_t'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
}
*/
  $account->content['parent_guardian_biodata']['email'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Email'),
    '#markup' => ($defaults)? $account->mail : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['nationality'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Nationality'),
    '#markup' => ($defaults)? $ks_user['nationality'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['parent_guardian_biodata']['occupation'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Occupation'),
    '#markup' => ($defaults)? $ks_user['occupation'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $account->content['parent_guardian_biodata']['mobile_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Mobile Phone'),
    '#markup' => ($defaults)? $ks_user['mobile_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['home_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Home Phone'),
    '#markup' => ($defaults)? $ks_user['home_phone'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['office_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Office Phone'),
    '#markup' => ($defaults)? $ks_user['office_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['other_phone'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Other Phone'),
    '#markup' => ($defaults)? $ks_user['other_phone'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_1'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Address 1'),
    '#markup' => ($defaults)? $ks_user['address_1'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_2'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Address 2'),
    '#markup' => ($defaults)? $ks_user['address_2'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_3'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Address 3'),
    '#markup' => ($defaults)? $ks_user['address_3'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_city'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('City'),
    '#markup' => ($defaults)? $ks_user['address_city'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_region_state'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Region-State'),
    '#markup' => ($defaults)? $ks_user['address_region_state'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_province'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Province'),
    '#markup' => ($defaults)? $ks_user['address_province'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_country'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Country'),
    '#markup' => ($defaults)? $ks_user['address_country'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['address_zip_postalcode'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Zip-Postal Code'),
    '#markup' => ($defaults)? $ks_user['address_zip_postalcode'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_biodata']['remarks'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Remarks'),
    '#markup' => ($defaults)? $ks_user['remarks'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );

  $account->content['parent_guardian_admin_info'] = array(  // fieldset for admin info
      '#type' => 'fieldset',
      '#title' => t('Parent_Guardian Admin Info'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => -5,
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

  $account->content['parent_guardian_admin_info']['curr_status'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Current Status'),
    '#markup' => ($defaults)? get_instructor_status_desc($ks_user['curr_status']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_admin_info']['began_date'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Date Started'),
    '#markup' => ($defaults)? $bgnd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $account->content['parent_guardian_admin_info']['end_date'] = array(
    '#type' => 'user_profile_item',
    '#title' => t('Date Completed'),
    '#markup' => ($defaults)? $endd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
}

