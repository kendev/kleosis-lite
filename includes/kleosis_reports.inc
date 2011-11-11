<?php
// $Id$
/**
* @file
* kleosis Reports
*/

/**
 * Display a list of Reports available in kleosis (callback function)
 *
 * @return
 *   List of Reports available in kleosis
 */

function kleosis_reports_page($form, &$form_state) {

$page_desc = <<<EOT
    <br/>This is the base page for the kleosis Reports functions.
    A description of the Reports functions accessable from above tabs will go here.<br/><br/>
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

/****************************************************************************
*
*  Legacy code...
*
****************************************************************************/

/*
  //Link to the kleosis Reports page (this items code belonged in kleosis.module)
  $items['kleosis/reports'] = array(
    'title' => 'Reports',
    'description' => 'Provides SIS Reports',
    'page callback' => 'kleosis_reports',
    'file' => 'includes/kleosis_reports.inc',
    'access callback' => TRUE,
    'expanded' => TRUE,
  );

function kleosis_reports() {

//  Ken is here workaround: drupal 7 beta 2 logout problem
  //  module_load_include('pages.inc', 'user', 'user');
  //  user_logout();
//  Ken was here

  return show_rtable();
}

function show_rtable($table = NULL, $rows_per_page = 20) {

$page_desc = <<<EOT
    <br/>This is the base page for the kleosis Reports functions.
    A description of the Reports functions accessable from above tabs will go here.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  return $page_desc;
}
*/

