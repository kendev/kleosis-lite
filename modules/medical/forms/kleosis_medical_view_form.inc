<?php

/**
 * @file
 *  Kleosis Medical view form
 *
 *  Provides the view form for the additional medical info fields from the custom tables
 */

  $yes_no = 0;

  $category = 2;  // illnesses
  $illnesses = ks_get_med_subject_record($med_nid, $category);

/****************/

  $node->content['illnesses'] = array(
    '#type' => 'fieldset',
    '#title' => t('Illnesses'),
    '#weight' => -200,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $node->content['illnesses']['chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => 'Chicken Pox',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[0]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[0]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[0]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['german_measles_rubella'] = array(
    '#type' => 'markup',
    '#markup' => 'German Measles-Rubella',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_german_measles_rubella'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[1]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_german_measles_rubella'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[1]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[1]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['hepatitis'] = array(
    '#type' => 'markup',
    '#markup' => 'Hepatitis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_hepatitis'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[2]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_hepatitis'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[2]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[2]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['measles'] = array(
    '#type' => 'markup',
    '#markup' => 'Measles',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_measles'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[3]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_measles'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[3]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[3]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['mumps'] = array(
    '#type' => 'markup',
    '#markup' => 'Mumps',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_mumps'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[4]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_mumps'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[4]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[4]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['poliomyelitis'] = array(
    '#type' => 'markup',
    '#markup' => 'Poliomyelitis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_poliomyelitis'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[5]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_poliomyelitis'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[5]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[5]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => 'Tuberculosis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[6]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[6]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[6]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['typhoid'] = array(
    '#type' => 'markup',
    '#markup' => 'Thyphoid',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[7]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[7]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[7]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => 'Whooping Cough',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[8]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[8]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[8]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['others'] = array(
    '#type' => 'markup',
    '#markup' => 'Others',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['yes_no_others'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[9]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['illnesses']['details_others'] = array(
    '#type' => 'markup',
    '#markup' => ($illnesses[9]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $illnesses[9]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );

/****************/

  $category = 3;  // health problems
  $health_problems = ks_get_med_subject_record($med_nid, $category);

  $node->content['health_problems'] = array(
    '#type' => 'fieldset',
    '#title' => t('Health Problems'),
    '#weight' => -190,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $node->content['health_problems']['allergies'] = array(
    '#type' => 'markup',
    '#markup' => 'Allergies',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_allergies'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[0]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_allergies'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[0]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[0]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['asthma'] = array(
    '#type' => 'markup',
    '#markup' => 'Asthma',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_asthma'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[1]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_asthma'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[1]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[1]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['congenital_abnormalities'] = array(
    '#type' => 'markup',
    '#markup' => 'Congenital Abnormalities',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_congenital_abnormalities'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[2]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_congenital_abnormalities'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[2]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[2]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['convulsions_epilepsy'] = array(
    '#type' => 'markup',
    '#markup' => 'Convulsions/Epilepsy',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_convulsions_epilepsy'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[3]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_convulsions_epilepsy'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[3]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[3]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['diabetes'] = array(
    '#type' => 'markup',
    '#markup' => 'Diabetes',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_diabetes'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[4]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_diabetes'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[4]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[4]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['frequent_headaches'] = array(
    '#type' => 'markup',
    '#markup' => 'Frequent Headaches',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_frequent_headaches'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[5]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_frequent_headaches'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[5]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[5]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['hearing_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'Hearing Difficulties',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_hearing_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[6]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_hearing_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[6]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[6]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['speech_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'Speech Difficulties',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_speech_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[7]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_speech_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[7]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[7]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['sight_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => 'Sight Difficulties',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_sight_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[8]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_sight_difficulties'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[8]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[8]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['heart_condition'] = array(
    '#type' => 'markup',
    '#markup' => 'Heart Condition',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_heart_condition'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[9]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_heart_condition'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[9]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[9]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['surgery'] = array(
    '#type' => 'markup',
    '#markup' => 'Surgery',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_surgery'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[10]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_surgery'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[10]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[10]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['others'] = array(
    '#type' => 'markup',
    '#markup' => 'Others',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['yes_no_others'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[11]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['health_problems']['details_others'] = array(
    '#type' => 'markup',
    '#markup' => ($health_problems[11]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $health_problems[11]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );

/****************/

  $category = 4;  // vaccination history
  $vaccination_history = ks_get_med_subject_record($med_nid, $category);

  $node->content['vaccination_history'] = array(
    '#type' => 'fieldset',
    '#title' => t('Vaccination History'),
    '#weight' => -170,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $node->content['vaccination_history']['bcg_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => 'BCG - Tuberculosis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_bcg_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[0]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_bcg_tuberculosis'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[0]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[0]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => 'Chicken Pox',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[1]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_chicken_pox'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[1]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[1]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['dtp_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => 'DTP - Whooping Cough',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_dtp_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[2]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_dtp_whooping_cough'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[2]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[2]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['hepatitis_a'] = array(
    '#type' => 'markup',
    '#markup' => 'Hepatitis A',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_hepatitis_a'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[3]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_hepatitis_a'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[3]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[3]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['hepatitis_b'] = array(
    '#type' => 'markup',
    '#markup' => 'Hepatitis B',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_hepatitis_b'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[4]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_hepatitis_b'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[4]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[4]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['hib'] = array(
    '#type' => 'markup',
    '#markup' => 'HIB',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_hib'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[5]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_hib'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[5]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[5]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['japanese_b_encephalitis'] = array(
    '#type' => 'markup',
    '#markup' => 'Japanese B encephalitis',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_japanese_b_encephalitis'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[6]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_japanese_b_encephalitis'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[6]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[6]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['measles'] = array(
    '#type' => 'markup',
    '#markup' => 'Measles',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_measles'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[7]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_measles'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[7]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[7]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['mumps'] = array(
    '#type' => 'markup',
    '#markup' => 'Mumps',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_mumps'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[8]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_mumps'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[8]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[8]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['opv_polio'] = array(
    '#type' => 'markup',
    '#markup' => 'OPV - Polio',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_opv_polio'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[9]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_opv_polio'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[9]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[9]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['rubella'] = array(
    '#type' => 'markup',
    '#markup' => 'Rubella',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_rubella'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[10]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_rubella'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[10]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[10]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['typhoid'] = array(
    '#type' => 'markup',
    '#markup' => 'Typhoid',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[11]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_typhoid'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[11]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[11]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['others'] = array(
    '#type' => 'markup',
    '#markup' => 'Others',
    '#prefix' => '<div style="float: left;clear:left;width:190px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['yes_no_others'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[12]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['vaccination_history']['details_others'] = array(
    '#type' => 'markup',
    '#markup' => ($vaccination_history[12]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $vaccination_history[12]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );

$category = 5;
$additional_info = ks_get_med_subject_record($med_nid, $category);

  $node->content['additional_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Info'),
    '#weight' => -150,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $node->content['additional_info']['med_allergies'] = array(
    '#type' => 'markup',
    '#markup' => 'Are you aware of any medication to which your child has adverse reactions?',
    '#prefix' => '<div style="float: left;clear:left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['additional_info']['yes_no_med_allergies'] = array(
    '#type' => 'markup',
    '#markup' => ($additional_info[0]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['additional_info']['details_med_allergies'] = array(
    '#type' => 'markup',
    '#markup' => ($additional_info[0]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $additional_info[0]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );

  $node->content['additional_info']['meds_now_taking'] = array(
    '#type' => 'markup',
    '#markup' => 'Is your child under medical care, or routinely taking medicine prescribed by a doctor?',
    '#prefix' => '<div style="float: left;clear:left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['additional_info']['yes_no_meds_now_taking'] = array(
    '#type' => 'markup',
    '#markup' => ($additional_info[1]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['additional_info']['details_meds_now_taking'] = array(
    '#type' => 'markup',
    '#markup' => ($additional_info[1]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $additional_info[1]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );

  $node->content['additional_info']['med_extra_info'] = array(
    '#type' => 'markup',
    '#markup' => 'Is there any other medical information you would like the school to be aware of?',
    '#prefix' => '<div style="float: left;clear:left;width:600px" >',
    '#suffix' => '</div>',
  );
  $node->content['additional_info']['yes_no_med_med_extra_info'] = array(
    '#type' => 'markup',
    '#markup' => ($additional_info[2]->yes_no == 0) ? 'Yes' : 'No',
    '#prefix' => '<div style="float: left;width:50px" >',
    '#suffix' => '</div>',
  );
  $node->content['additional_info']['details_med_med_extra_info'] = array(
    '#type' => 'markup',
    '#markup' => ($additional_info[2]->yes_no == 0) ? 'Details: &nbsp;&nbsp;' . $additional_info[2]->description : '',
    '#prefix' => '<div style="float: left;width:600px" >',
    '#suffix' => '</div>',
  );

$category = 1;
$administrative = ks_get_med_subject_record($med_nid, $category);

  $node->content['administrative'] = array(
    '#type' => 'fieldset',
    '#title' => t('Administrative'),
    '#weight' => -140,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $node->content['administrative']['med_can_take'] = array(
    '#type' => 'markup',
    '#markup' => 'Our policy is to avoid giving medication to students in school, although some mild, non-prescription remedies will be available. ' .
    'Please specify whether your child can receive any medication ',
    '#prefix' => '<div style="float: left;clear:left;width:585px" >',
    '#suffix' => '</div>',
  );
  $node->content['administrative']['yes_no_med_can_take'] = array(
    '#type' => 'markup',
    '#markup' => ($administrative[0]->yes_no == 0) ? 'Yes' : 'No',
//    '#prefix' => '<div style="float: left;clear:left;width:50px" >',
    '#prefix' => '<div style="display:inline-container;padding-right: 7px;padding-left: 15px;float: left;width:60px;" >',
    '#suffix' => '</div>',
  );


