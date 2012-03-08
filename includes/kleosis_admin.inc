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

drupal_set_title(t('Class Generation'));

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Admin EOT Class Generation functions (currently being developed).
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

