<?php

/**
 * @file
 *   Kleosis Courses functions
 */

/**
 * Provides Courses functions for Kleosis (not currently used)
 *
 * @return
 *   currently a form with descriptive text
 */
function kleosis_courses_page($form, &$form_state) {

$page_desc = <<<EOT
  <br/>This is the base page for the kleosis Courses functions. <br/><br/>
  A description of the Courses functions accessable from the above tabs will go here...<br/><br/>
  List All Courses - will list all current courses in Moodle at this site.  An edit link (tbd) will allow editing the course info.<br/><br/>
  <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
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
