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
    <br/>This is the base page for the Kleosis Admin functions.
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

