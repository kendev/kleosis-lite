<?php

/**
 * @file
 * Kleosis Attendance functions
 */

/**
 * Defines a Daily Attendance placeholder tab
 *
 * @return
 *    redirects to kleosis/attendance/daily/view
 */
function kleosis_attendance($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Attendance'), 'kleosis/attendance/daily/view');
  $breadcrumb[] = t('Daily Attendance');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Daily Attendance'));


$page_desc = <<<EOT
    <br/>This is the kleosis daily attendance view form.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Attendance'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );
  drupal_goto($path = 'kleosis/attendance/daily/take', $options = array());
  return $form;
}


/**
 * Provides absentee periods marking form when using daily attendance
 *
 * @return
 *   absentee periods form
 */

function kleosis_absentee_periods_mark($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Absentee Periods'), 'kleosis/attendance/absentee');
  $breadcrumb[] = t('Mark Absentee Periods');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Mark Absentee Periods'));

  $page_desc = <<<EOT
    <br/>Marking absentee periods will be provided here when using daily attendance (tbd)
        - see the Kleosis documentation for more information.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info
  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Mark Absentee Periods'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );

  return $form;
}
/**
 * Provides absentee periods viewing form when using daily attendance
 *
 * @return
 *   absentee periods form
 */

function kleosis_absentee_periods_view($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Absentee Periods'), 'kleosis/attendance/absentee');
  $breadcrumb[] = t('View Absentee Periods');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('View Absentee Periods'));

  $page_desc = <<<EOT
    <br/>Viewing absentee periods will be provided here when using daily attendance (tbd)
        - see the Kleosis documentation for more information.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info
  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('View Absentee Periods'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );

  return $form;
}

/**
 * Provides period attendance_taking form
 *
 * @return
 *   period attendance_taking form
 */

function kleosis_period_attendance_taking_form($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Period Attendance'), 'kleosis/attendance/period');
  $breadcrumb[] = t('Take Period Attendance');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Take Period Attendance'));

  $page_desc = <<<EOT
    <br/>Taking period attendance will be provided here (tbd)
        - see the Kleosis documentation for more information.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info
  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Take Period Attendance'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );

  return $form;
}
/**
 * Provides period attendance_viewing form
 *
 * @return
 *   period attendance_viewing form
 */

function kleosis_period_attendance_view_form($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Period Attendance'), 'kleosis/attendance/period');
  $breadcrumb[] = t('View Period Attendance');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('View Period Attendance'));

  $page_desc = <<<EOT
    <br/>Viewing period attendance will be provided here (tbd)
        - see the Kleosis documentation for more information.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info
  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('View Period Attendance'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );

  return $form;
}
