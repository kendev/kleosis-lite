<?php
// $Id$
/**
* @file
* kleosis Faculty
*/

/**
 * Provides Faculty functions available in kleosis available in kleosis (callback function)
 *
 * @return
 *   tbd
 */

function kleosis_faculty_page($form, &$form_state) {

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Faculty functions.
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

