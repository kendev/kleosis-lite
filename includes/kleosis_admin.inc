<?php

/**
 * @file
 *   Kleosis Admin functions
 */

/**
 * Provides Admin functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_page($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = t('Admin');

  drupal_set_breadcrumb($breadcrumb);

  $page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Admin functions.  Functions such as those involved in beginning and end of term tasks, special system configuration, table maintenance, and others are placed and organized here. <br/><br/>
    The functions in above tabs are the following:<br/>
    <ul>
      <li>Beginning of Term -> import and export users biodata<br/><br/></li>
      <li>End of Term -> student rollover, new classes generation, and class enrollments<br/><br/></li>
      <li>Description Tables -> populate and maintain school-specific category and configuration data<br/><br/></li>
      <li>more tbd...<br/><br/></li>
    </ul>
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

/**
 * Provides Admin beginning of term functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_bot($form, &$form_state) {

drupal_set_title(t('Admin'));

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Admin Beginning of Term functions.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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

/**
 * Provides BOT import data functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_bot_import_data($form, &$form_state) {

drupal_set_title(t('Import Data'));

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis BOT Import Data function (currently being developed).
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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

/**
 * Provides BOT export data functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_bot_export_data($form, &$form_state) {

drupal_set_title(t('Export Data'));

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis BOT Export Data function (currently being developed).
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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

/**
 * Provides Admin end of term functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_eot($form, &$form_state) {

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Admin End of Term functions.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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

/**
 * Provides Admin end of term student rollover functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_eot_student_rollover($form, &$form_state) {

drupal_set_title(t('Student Rollover'));

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Admin EOT Student Rollover function (currently being developed).
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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

/**
 * Provides Admin end of term class generation functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_eot_class_generation($form, &$form_state) {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles)) ) {
    drupal_set_message(t("You currently do not have permissions to generate new classes."));
    $options = array('query' => array('destination' => 'kleosis/admin') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  drupal_set_title(t('Class Generation'));

  $this_acy = variable_get('kleosis_academic_year', '2012-2013');

  $this_start_year = substr($this_acy, 0, 4);
  $this_end_year = substr($this_acy, 5, 4);

  $next_start_year = $this_start_year + 1;
  $next_end_year = $this_end_year + 1;

  $next_acy = $next_start_year . '-' . $next_end_year;

  // add a fieldset for the page info

  $form['classgen'] = array(
      '#type' => 'fieldset',
      '#title' => t('Class Generation'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['classgen']['pageinfo'] = array(
      '#markup' => t('Generate new classes from the current academic year for the next academic year.'),
      '#weight' => -1,
      '#prefix' => '<div style="float: left;clear: left;width:700px" ><strong>',
      '#suffix' => '</strong><br/><br/></div>',
      );

    $form['classgen']['this_acy'] = array(
      '#type' => 'select',
      '#title' => t('Current Academic Year'),
      '#options' =>  array($this_acy => $this_acy),
      '#default_value' => $this_acy,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;clear:left;width:200px" >',
      '#suffix' => '</div>',
    );

    $form['classgen']['to'] = array(
      '#markup' => t('-->'),
      '#prefix' => '<div style="float: left;width:75px">&nbsp;<strong><em>',
      '#suffix' => '</em></strong>&nbsp;&nbsp;</div>',
    );
    $form['classgen']['next_acy'] = array(
      '#type' => 'select',
      '#title' => t('Next Academic Year'),
      '#options' =>  array($next_acy => $next_acy),
      '#default_value' => $next_acy,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:200px" >',
      '#suffix' => '</div><br/><br/><br/>',
    );
    $form['classgen']['spacer'] = array(
      '#markup' =>    '&nbsp;',
      '#prefix' => '<div style="float: left;clear: left;width:1px">',
      '#suffix' => '</div>',
    );
    $form['classgen']['generate'] = array(
      '#type' => 'submit',
      '#value' => t('Generate'),
      '#weight' => 5,
      '#prefix' => '<div style="float: left;clear:left; width:125px" >',
      '#suffix' => '</div><br/>',
    );
    $form['delete_gen'] = array(
      '#type' => 'fieldset',
      '#title' => t('Delete Class Generation'),
      '#weight' => 30,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['delete_gen']['delete_info'] = array(
      '#markup' => t('Delete all classes for the next academic year.'),
      '#prefix' => '<div style="float: left;clear: left;width:600px" ><strong>',
      '#suffix' => '</strong><br/><br/></div>',
      );
    $form['delete_gen']['del_next_acy'] = array(
      '#type' => 'select',
      '#title' => t('Next Academic Year'),
      '#options' =>  array($next_acy => $next_acy),
      '#default_value' => $next_acy,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;clear: left;width:150px" >',
      '#suffix' => '</div><br/><br/><br/>',
    );
    $form['delete_gen']['spacer2'] = array(
      '#markup' =>    '&nbsp;',
      '#prefix' => '<div style="float: left;clear: left;width:1px">',
      '#suffix' => '</div>',
    );
    $form['delete_gen']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#weight' => 5,
      '#prefix' => '<div style="float: left;clear:left; width:125px" >',
      '#suffix' => '</div><br/>',
    );

  return $form;
}

/*
 * Submit function for the kleosis_admin_eot_class_generation form
 */
function kleosis_admin_eot_class_generation_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Generate':
//      drupal_set_message(t('The Generate button called kleosis_admin_eot_class_generation_submit....'));
      $res = kleosis_generate_next_classes($form_state['values']['this_acy'], $form_state['values']['next_acy']);
      break;

    case 'Delete':
      drupal_goto($path = 'kleosis/admin/eot/class_generation/delete', $options =  array('query' => array('ksopid' => 'delete', 'ksop' => $form_state['values']['del_next_acy'], 'destination' => 'kleosis/admin/eot/class_generation')));
      break;
  }
}

/**
 * Menu callback; get confirm form for deleting the new classes
 */
function kleosis_new_classes_delete_page() {
  return drupal_get_form('kleosis_new_classes_delete_confirm');
}

/**
 * Build a confirm form for deletion of the new classes
 */
function kleosis_new_classes_delete_confirm($form, &$form_state) {
  $caption = '<p>' . t('This action cannot be undone.') . '</p>';
  $heading = t('Are you sure you want to delete the newly generated classes?');
  $cancel_path = 'kleosis/admin/eot/class_generation';
  $yes = t('Delete classes');
  $no = t('Cancel');
  return confirm_form($form, $heading, $cancel_path, $caption, $yes, $no);
}

/**
 * Submit function for the confirm new classes deletion form.
 */
function kleosis_new_classes_delete_confirm_submit($form, &$form_state) {
  $kclss_id = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : 0;
  $ksop = isset( $_GET['ksop'] ) ? $_GET['ksop'] : '';

//  dpm('ksopid = ' . $kclss_id);  // should be 'delete'
//  dpm('ksop = ' . $ksop);       // should be the academic year of deletion

  $res = kleosis_delete_classes($ksop);

  if ($res) {
    drupal_set_message(t('The classes were successfully deleted.'));
  }
  else {
    drupal_set_message(t('The classes were not deleted.'));
  }
//  $form_state['redirect'] = 'kleosis/admin/eot/class_generation';  // not needed
}

/**
 * Provides Admin end of term class enrollment functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_eot_class_enrollments($form, &$form_state) {

drupal_set_title(t('Class Enrollments'));

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Admin EOT Class Enrollment functions (currently being developed).
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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

/**
 * Provides Admin description tables maintenance functions for Kleosis (tbd...)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_admin_desc_tables($form, &$form_state) {

drupal_set_title(t('Description Tables Maintenance'));

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Description Tables maintenance functions (currently being developed).
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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

/**
 * function to delete classes for a given academic year and term
 *
 * @param  $academic_year
 * @param  $term
 *
 * @return true or false
 *
 */
function kleosis_delete_classes($academic_year, $term = 'fy') {

  $res = FALSE;
  $nids = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=');
//  ->fieldCondition('ks_class_term', 'value', $term, '=')

  $result = $query->execute();

  if ( !empty($result) ) {
    $res = TRUE;
    $nids = array_keys($result['node']);
    node_delete_multiple($nids);
  }
  return $res;
}

/**
 * function to generate new classes based on existing classes
 *
 * @param  $from_academic_year
 *    new classes will be generated from classes existing in academic year = $from_academic_year
 * @param  $to_academic_year
 *    new classes will be generated for academic year = $to_academic_year
 * @param  $term
 *
 * @return true or false
 *
 */
function kleosis_generate_next_classes($from_academic_year, $to_academic_year, $term = 'fy') {

  $res = TRUE;
  $nids = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_academic_year', 'value', $from_academic_year, '=');
//  ->fieldCondition('ks_class_term', 'value', $term, '=')

  $result = $query->execute();

  if ( !empty($result) ) {
    $res = TRUE;
    $nids = array_keys($result['node']);


    foreach($nids as $nid) {

//$nid = $nids[0];

      $this_start_year = substr($from_academic_year, 0, 4);
      $this_end_year = substr($from_academic_year, 5, 4);

      $next_start_year = substr($to_academic_year, 0, 4);
      $next_end_year = substr($to_academic_year, 5, 4);

      $excl_class = node_load($nid);

      $excl_start_year = substr($excl_class->ks_class_start_end_date['und'][0]['value'], 0, 4);
      $excl_end_year = substr($excl_class->ks_class_start_end_date['und'][0]['value2'], 0, 4);

      if ( ($excl_start_year != $this_start_year) && ($this_end_year != $this_end_year) ) {
          drupal_set_message('The existing class ' .  $excl_class->title  . ' does not have a start date inside the  ' . $from_academic_year . ' academic year');
       }
      else {

      $excl_start_year += 1;
      $excl_end_year += 1;

      settype($excl_start_year, 'string');
      settype($excl_end_year, 'string');

      $new_class = new stdClass(); // Create a new node object
      $new_class->type = "class"; // class content type
      node_object_prepare($new_class); // Set some default values

      //$new_class->title    = $excl_class->title;
      $new_class->title    = $excl_class->title . ' - ' . $to_academic_year;
      $new_class->language = $excl_class->language;
      $new_class->uid = $excl_class->uid;
      $new_class->status = 1;
      $new_class->comment = 0;
      $new_class->promote = 0;
      $new_class->sticky = 0;

      $new_class->ks_class_course_ref['und'][0]['nid'] = $excl_class->ks_class_course_ref['und'][0]['nid'];
      $new_class->ks_class_section['und'][0]['value'] = $excl_class->ks_class_section['und'][0]['value'];
      $new_class->ks_class_start_end_date['und'][0]['value'] = substr_replace($excl_class->ks_class_start_end_date['und'][0]['value'], $excl_start_year, 0, 4);
      $new_class->ks_class_start_end_date['und'][0]['value2'] = substr_replace($excl_class->ks_class_start_end_date['und'][0]['value2'], $excl_end_year, 0, 4);
      $new_class->ks_class_academic_year['und'][0]['value'] = $to_academic_year;
      $new_class->ks_class_term['und'][0]['value'] = $excl_class->ks_class_term['und'][0]['value'];
      $new_class->ks_class_type['und'][0]['value'] = $excl_class->ks_class_type['und'][0]['value'];
      $new_class->ks_class_status['und'][0]['value'] = $excl_class->ks_class_status['und'][0]['value'];
      $new_class->ks_class_remarks['und'][0]['value'] = $excl_class->ks_class_remarks['und'][0]['value'];


      if($new_class = node_submit($new_class)) { // Prepare node for saving
          node_save($new_class);
      //    drupal_set_message( 'A Class node with nid ' . $new_class->nid . ' saved!\n');
        }
      else {
      //      drupal_set_message( 'A Class node with nid ' . $new_class->nid . ' was NOT saved!\n');
        }
      }
    } // end foreach($nids as $nid)

      drupal_set_message( 'New classes succesfully created.');
  }
  return $res;
}

