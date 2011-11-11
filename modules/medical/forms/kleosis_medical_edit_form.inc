<?php
// $Id$

/**
 * @file
 *  kleosis Medical edit form
 *  Provides the edit form for the additional medical info fields from the custom tables
 */

$category = 2;
$illnesses = ks_get_med_subject_record($med_nid, $category);
//dpm($illnesses);
$insert = !empty($illnesses) ? TRUE : FALSE;

  $form['content']['illnesses'] = array(
    '#type' => 'fieldset',
    '#title' => t('Illnesses'),
    '#weight' => -200,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['content']['illnesses']['il_chicken_pox_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[0]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => 'Chicken Pox',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_chicken_pox'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[0]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_details_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_chicken_pox'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[0]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_german_measles_rubella_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[1]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_german_measles_rubella'] = array(
    '#type' => 'markup',
    '#markup' => 'German Measles-Rubella',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_german_measles_rubella'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[1]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_german_measles_rubella'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_german_measles_rubella'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[1]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_hepatitis_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[2]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_hepatitis'] = array(
    '#type' => 'markup',
    '#markup' => 'Hepatitis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_hepatitis'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[2]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_hepatitis'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_hepatitis'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[2]->description :'',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_measles_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[3]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_measles'] = array(
    '#type' => 'markup',
    '#markup' => 'Measles',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_measles'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[3]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_measles'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_measles'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[3]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_mumps_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[4]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_mumps'] = array(
    '#type' => 'markup',
    '#markup' => 'Mumps',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_mumps'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[4]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_mumps'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_mumps'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[4]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_poliomyelitis_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[5]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_poliomyelitis'] = array(
    '#type' => 'markup',
    '#markup' => 'Poliomyelitis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_poliomyelitis'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[5]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_poliomyelitis'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_poliomyelitis'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[5]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_tuberculosis_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[6]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => 'Tuberculosis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_tuberculosis'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[6]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_details_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_tuberculosis'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[6]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_typhoid_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[7]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => 'Typhoid',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_typhoid'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[7]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_details_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_typhoid'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[7]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_whooping_cough_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[8]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => 'Whooping Cough',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_whooping_cough'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[8]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_details_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_whooping_cough'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[8]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['illnesses']['il_others_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $illnesses[9]->ksmi_id : 0,
  );
  $form['content']['illnesses']['il_others'] = array(
    '#type' => 'markup',
    '#markup' => 'Others',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_yes_no_others'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $illnesses[9]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_if_yes_details_others'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['illnesses']['il_details_others'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $illnesses[9]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );

/***********************/

$category = 3;
$health_problems = ks_get_med_subject_record($med_nid, $category);
//dpm($health_problems);
$insert = !empty($health_problems) ? TRUE : FALSE;

  $form['content']['health_problems'] = array(
    '#type' => 'fieldset',
    '#title' => t('Health Problems'),
    '#weight' => -190,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['content']['health_problems']['hp_allergies_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[0]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_allergies'] = array(
    '#type' => 'markup',
    '#markup' => 'Allergies',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_allergies'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[0]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_allergies'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_allergies'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[0]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );

  $form['content']['health_problems']['hp_asthma_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[1]->ksmi_id : 0,
  );
  $form['content']['health_problems']['hp_asthma'] = array(
    '#type' => 'markup',
    '#markup' => 'Asthma',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_asthma'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[1]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_asthma'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_asthma'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[1]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_congenital_abnormalities_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[2]->ksmi_id : 0,
  );
  $form['content']['health_problems']['hp_congenital_abnormalities'] = array(
    '#type' => 'markup',
    '#markup' => 'Congenital Abnormalities',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_congenital_abnormalities'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[2]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_congenital_abnormalities'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_congenital_abnormalities'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[2]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_convulsions_epilepsy_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[3]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_convulsions_epilepsy'] = array(
    '#type' => 'markup',
    '#markup' => 'Convulsions/Epilepsy',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_convulsions_epilepsy'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[3]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_convulsions_epilepsy'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_convulsions_epilepsy'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[3]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_diabetes_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[4]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_diabetes'] = array(
    '#type' => 'markup',
    '#markup' => 'Diabetes',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_diabetes'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[4]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_diabetes'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_diabetes'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[4]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_frequent_headaches_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[5]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_frequent_headaches'] = array(
    '#type' => 'markup',
    '#markup' => 'Frequent Headaches',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_frequent_headaches'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[5]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_frequent_headaches'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_frequent_headaches'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[5]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_hearing_difficulties_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[6]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_hearing_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'Hearing Difficulties',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_hearing_difficulties'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[6]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_hearing_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_hearing_difficulties'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[6]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_speech_difficulties_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[7]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_speech_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'Speech Difficulties',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_speech_difficulties'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[7]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_speech_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_speech_difficulties'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[7]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_sight_difficulties_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[8]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_sight_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'Sight Difficulties',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_sight_difficulties'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[8]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_sight_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_sight_difficulties'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[8]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_heart_condition_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[9]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_heart_condition'] = array(
    '#type' => 'markup',
    '#markup' => 'Heart Condition',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_heart_condition'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[9]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_heart_condition'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_heart_condition'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[9]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_surgery_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[10]->ksmi_id :0,
  );
  $form['content']['health_problems']['vi_surgery'] = array(
    '#type' => 'markup',
    '#markup' => 'Surgery',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_surgery'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[10]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_surgery'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_surgery'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[10]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['health_problems']['hp_others_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $health_problems[11]->ksmi_id :0,
  );
  $form['content']['health_problems']['hp_others'] = array(
    '#type' => 'markup',
    '#markup' => 'Others',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_yes_no_others'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $health_problems[11]->yes_no : 1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_if_yes_details_others'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['health_problems']['hp_details_others'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $health_problems[11]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );

/***********************/

$category = 4;
$vaccination_history = ks_get_med_subject_record($med_nid, $category);
//dpm($vaccination_history);
$insert = !empty($vaccination_history) ? TRUE : FALSE;

  $form['content']['vaccination_history'] = array(
    '#type' => 'fieldset',
    '#title' => t('Vaccination History'),
    '#weight' => -170,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['content']['vaccination_history']['vi_bcg_tuberculosis_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[0]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_bcg_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => 'BCG - Tuberculosis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_bcg_tuberculosis'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[0]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_bcg_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_bcg_tuberculosis'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[0]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_chicken_pox_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[1]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => 'Chicken Pox',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_chicken_pox'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[1]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_chicken_pox'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[1]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_dtp_whooping_cough_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[2]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_dtp_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => 'DTP - Whooping Cough',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_dtp_whooping_cough'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[2]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_dtp_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_dtp_whooping_cough'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[2]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_hepatitis_a_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[3]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_hepatitis_a'] = array(
    '#type' => 'markup',
    '#markup' => 'Hepatitis A',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_hepatitis_a'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[3]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_hepatitis_a'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_hepatitis_a'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[3]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_hepatitis_b_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[4]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_hepatitis_b'] = array(
    '#type' => 'markup',
    '#markup' => 'Hepatitis B',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_hepatitis_b'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[4]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_hepatitis_b'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_hepatitis_b'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[4]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_hib_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[5]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_hib'] = array(
    '#type' => 'markup',
    '#markup' => 'HIB',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_hib'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[5]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_hib'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_hib'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[5]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_japanese_b_encephalitis_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[6]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_japanese_b_encephalitis'] = array(
    '#type' => 'markup',
    '#markup' => 'Japanese B encephalitis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_japanese_b_encephalitis'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[6]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_japanese_b_encephalitis'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_japanese_b_encephalitis'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[6]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_measles_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[7]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_measles'] = array(
    '#type' => 'markup',
    '#markup' => 'Measles',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_measles'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[7]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_measles'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_measles'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[7]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_mumps_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[8]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_mumps'] = array(
    '#type' => 'markup',
    '#markup' => 'Mumps',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_mumps'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[8]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_mumps'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_mumps'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[8]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_opv_polio_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[9]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_opv_polio'] = array(
    '#type' => 'markup',
    '#markup' => 'OPV - Polio',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_opv_polio'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[9]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_opv_polio'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_opv_polio'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[9]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_rubella_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[10]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_rubella'] = array(
    '#type' => 'markup',
    '#markup' => 'Rubella',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_rubella'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[10]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_rubella'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_rubella'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[10]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_typhoid_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[11]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => 'Typhoid',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_typhoid'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[11]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_typhoid'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[11]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );
  $form['content']['vaccination_history']['vi_others_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $vaccination_history[12]->ksmi_id :0,
  );
  $form['content']['vaccination_history']['vi_others'] = array(
    '#type' => 'markup',
    '#markup' => 'Others',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_yes_no_others'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $vaccination_history[12]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_if_yes_details_others'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['vaccination_history']['vi_details_others'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $vaccination_history[12]->description : '',
    '#prefix' => '<div style="float:left;width:400px" >',
    '#suffix' => '</div><br/>',
  );

$category = 5;
$additional_info = ks_get_med_subject_record($med_nid, $category);
//dpm($additional_info);
$insert = !empty($additional_info) ? TRUE : FALSE;

  $form['content']['additional_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Info'),
    '#weight' => -150,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['content']['additional_info']['ai_med_allergies_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $additional_info[0]->ksmi_id :0,
  );
  $form['content']['additional_info']['ai_med_allergies'] = array(
    '#type' => 'markup',
    '#markup' => 'Are you aware of any medication to which your child has adverse reactions?',
    '#prefix' => '<div style="float: left;clear:left;width:600px" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_yes_no_med_allergies'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $additional_info[0]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_if_yes_details_med_allergies'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;clear:left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_details_med_allergies'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $additional_info[0]->description : '',
    '#prefix' => '<div style="float:left;width:600px" >',
    '#suffix' => '</div><br/>',
  );

  $form['content']['additional_info']['ai_meds_now_taking_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $additional_info[1]->ksmi_id :0,
  );
  $form['content']['additional_info']['ai_meds_now_taking'] = array(
    '#type' => 'markup',
    '#markup' => 'Is your child under medical care, or routinely taking medicine prescribed by a doctor?',
    '#prefix' => '<div style="float: left;clear:left;width:600px" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_yes_no_meds_now_taking'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $additional_info[1]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_if_yes_details_meds_now_taking'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;clear:left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_details_meds_now_taking'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $additional_info[1]->description : '',
    '#prefix' => '<div style="float:left;width:600px" >',
    '#suffix' => '</div><br/>',
  );

  $form['content']['additional_info']['ai_med_extra_info_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $additional_info[2]->ksmi_id :0,
  );
  $form['content']['additional_info']['ai_med_extra_info'] = array(
    '#type' => 'markup',
    '#markup' => 'Is there any other medical information you would like the school to be aware of?',
    '#prefix' => '<div style="float: left;clear:left;width:600px" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_yes_no_med_extra_info'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $additional_info[2]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_if_yes_details_med_extra_info'] = array(
    '#type' => 'markup',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;clear:left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['additional_info']['ai_details_med_extra_info'] = array(
    '#type' => 'textfield',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $additional_info[2]->description : '',
    '#prefix' => '<div style="float:left;width:600px" >',
    '#suffix' => '</div><br/>',
  );


$category = 1;
$administrative = ks_get_med_subject_record($med_nid, $category);
//dpm($additional_info);
$insert = !empty($administrative) ? TRUE : FALSE;

  $form['content']['administrative'] = array(
    '#type' => 'fieldset',
    '#title' => t('Administrative'),
    '#weight' => -140,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['content']['administrative']['ad_med_can_take_ksmi_id'] = array(
    '#type' => 'hidden',
    '#value' => ($insert) ? $administrative[0]->ksmi_id :0,
  );
  $form['content']['administrative']['ad_med_can_take'] = array(
    '#type' => 'markup',
    '#markup' => 'Our policy is to avoid giving medication to students in school, although some mild, non-prescription remedies will be available. ' .
    'Please specify whether your child can receive any medication. ',
    '#prefix' => '<div style="float: left;clear:left;width:585px" >',
    '#suffix' => '</div>',
  );
  $form['content']['administrative']['ad_yes_no_med_can_take'] = array(
    '#type' => 'radios',
    '#options' => array(t('Yes'), t('No')),
    '#default_value' => ($insert) ? $administrative[0]->yes_no :1,
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;padding-left: 15px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );
  $form['content']['administrative']['ad_if_yes_details_med_can_take'] = array(
    '#type' => 'hidden',
    '#markup' => 'If yes, details:',
    '#prefix' => '<div style="float: left;clear:left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['content']['administrative']['ad_details_med_can_take'] = array(
    '#type' => 'hidden',
    '#size' => 80,
    '#maxlength' => 120,
    '#default_value' => ($insert) ? $administrative[0]->description : '',
    '#prefix' => '<div style="float:left;width:600px" >',
    '#suffix' => '</div><br/>',
  );

