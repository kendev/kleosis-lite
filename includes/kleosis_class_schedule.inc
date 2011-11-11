<?php
// $Id$
/**
* @file
* kleosis Class Schedule
*/

/**
 * Provides Class Schedule functions available in kleosis (callback function)
 *
 * @return
 *   tbd
 */

function kleosis_class_schedule_page($form, &$form_state) {

$page_desc = <<<EOT
    <br/>This is the base page for the kleosis Class Schedule functions.
    A description of the Class Schedule functions accessable from above tabs will go here.<br/><br/>
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

