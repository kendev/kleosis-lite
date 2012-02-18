<?php

/**
 * @file
 *   Kleosis Users functions (Moodle)
 *
 * most of this is early legacy code to demonstrate Moodle API
 * access via the webservices layer
 *
 * needs to be rewritten/updated or possibly removed :)
 */

require_once ('kleosis_ws.inc');  // webservices wrapper functions

/**
 * Display the (Moodle) Edit User form for kleosis.
 *
 * @param $optarg
 *   An optional argument placeholder (not used yet)
 * @return
 *   The Edit Users form for kleosis
 */
function kleosis_users_edit($optarg) {

  drupal_set_title(t('Edit Moodle User Data - demo'));

  return drupal_get_form('kleosis_users_edit_form');
}

/**
 * Display the User Roles list
 *
 * @return
 *   The User Roles list (HTML)
 */
function kleosis_roles() {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('LMS Direct'), 'kleosis/lms_direct');
  $breadcrumb[] = t('List Roles');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  //  return show_rtable('kleosis_log',5);

  return show_rtable();
}

/**
 * Fill the searchuser select box
 *
 * @return
 *    An array of items to select
 */
function fill_searchuser_items() {

  $le_array = array(
    'item1' => t('Username'),
    'item2' => t('Firstname'),
    'item3' => t('Lastname'),
  );
  return $le_array;
}

/**
 * Define the Users List form
 *
 * @return
 *    Users List form
 */
function kleosis_users_list_form($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('LMS Direct'), 'kleosis/lms_direct');
  $breadcrumb[] = t('List Users');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Moodle Users List - demo'));

  $form = array();

  $form['searchuser'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search User'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['searchuser']['s1name'] = array(
    '#type' => 'select',
    '#title' => t('Where'),
    '#options' => fill_searchuser_items(),
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['searchuser']['oper'] = array(
  '#type' => 'select',
    '#title' => t('Operator'),
  '#options' =>  array('item1' => t('is')),
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );
  $form['searchuser']['thename'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter name'),
    '#size' => 30,
    '#maxlength' => 64,
    '#default_value' => !empty($form_state['input']['thename']) ? $form_state['input']['thename'] : '',
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $form['searchuser']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
//    '#submit' => kleosis_users_list_form_submit($form, &$form_state),
    '#submit' => kleosis_users_list_form_submit($form, $form_state),
    '#prefix' => '<div style="float: right;width:200px" >',
    '#suffix' => '</div>',
  );

/*
  $form['searchuser']['Clear'] = array(
    '#type' => 'button',
    '#value' => t('Clear name'),
      '#weight' => 19,
      '#prefix' => '<div style="float: right;width:250px" >',
      '#suffix' => '</div>',
  );
*/
  $therows = array();
  if (!empty($form_state['input']['thename'])) {
    $therows = ws_get_user($form_state['input']['thename'], 'username');
  }
  else {
    $therows = ws_get_users();
  }

//  dpm($therows);

  if ($therows) {
    foreach ($therows as $data) {

      $options[$data['id']] = '';
      $form[$data['id']]['lid'] = array('#value' => l(t('edit'), 'kleosis/users/edit', array('query' => array('id' => $data['id']))));
      $form[$data['id']]['username'] = array('#value' => stripslashes($data['username']));
      $form[$data['id']]['firstname'] = array('#value' => stripslashes($data['firstname']));
      $form[$data['id']]['lastname'] = array('#value' => stripslashes($data['lastname']));
    }


    $form['selected'] = array(
      '#type' => 'checkboxes',
      '#options' => $options,
      );
  }
  return $form;
}

/**
 *
 * This function is the main form for listing Moodle users
 *
 * @param $form
 *
 */
function theme_kleosis_users_list_form($form) {
  $rows = array();
  //  dpm('<br/> inside function theme_kleosis_users_list_form <br/>');
  $the_data = $form;

  foreach (element_children($the_data['form']) as $key) {
    $row = array();

    if (isset($the_data['form'][$key]['lid'])) {

      $cbselect = array('data' => $the_data['form']['selected'][$key]);
      $row[] = array('data' => $cbselect, 'class' => 'checkbox');
      $row[] = array('data' => $the_data['form'][$key]['username']['#value']);
      $row[] = array('data' => $the_data['form'][$key]['firstname']['#value']);
      $row[] = array('data' => $the_data['form'][$key]['lastname']['#value']);
      $row[] = '' . $the_data['form'][$key]['lid']['#value'] . '';

      $rows[] = $row;
    }
  }

  // Individual table headers.
  $header = array();
  $header[] = array('data' => t('Select'), 'class' => 'checkbox');
  $header[] = t('Username');
  $header[] = t('Firstname');
  $header[] = t('Lastname');
  $header[] = t('Operations');

  $output = drupal_render($form['form']['searchuser']);

  $t_username =  (isset($rows[0][1]['data']))? (string)$rows[0][1]['data']: '';  // if this element is empty, then no user rows were found

  if (empty($t_username)) {
    $output .= t('No user was found with that Search criteria.');
  }
  else {
    $output .= '<p>' . t('Requested features: Click on a column title to sort by that column and implement paging...') . '</p>';
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array(), 'caption' => NULL, 'colgroups' => array(), 'sticky' => TRUE));
  }
  return $output;
}

/**
 *
 * Implementation of hook_submit() for the Users List form.
 *
 */
function kleosis_users_list_form_submit($form, &$form_state) {

//  Nothing to do really...
}

/**
 *
 * Implementation of hook_validate() for the Users List form.
 *
 */
function kleosis_users_list_form_validate($form, &$form_state) {

//  No validation yet...
}

/**
 * Define the Edit Users form
 *
 * @return
 *    The Edit Users form
 */
function kleosis_users_edit_form($form, &$form_state) {

  global $user;
  $form = array();
  $uid  = $_GET['id'];
  $urow = ws_get_user($uid, 'id');
  $form['actions'] = array('#type' => 'actions');

  $form['userid'] = array(
    '#type' => 'hidden',
    '#title' => t('Userid'),
    '#default_value' => $urow[0]['id'],
  );
  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#size' => 24,
    '#maxlength' => 64,
    '#disabled' => TRUE,
    '#default_value' => $urow[0]['username'],
    '#prefix' => '<div style="float:left;clear:left;width:300px" >',
    '#suffix' => '</div>',
  );
  $form['firstname'] = array(
    '#type' => 'textfield',
    '#title' => t('Firstname'),
    '#size' => 30,
    '#maxlength' => 64,
    '#disabled' => (in_array('administrator', $user->roles))  || (user_access('administer nodes')) ? FALSE : TRUE,
    '#default_value' => $urow[0]['firstname'],
    '#prefix' => '<div style="float:left;clear:left;width:300px" >',
    '#suffix' => '</div>',

  );
  $form['lastname'] = array(
    '#type' => 'textfield',
    '#title' => t('Lastname'),
    '#size' => 30,
    '#maxlength' => 64,
    '#disabled' => (in_array('administrator', $user->roles))  || (user_access('administer nodes')) ? FALSE : TRUE,
    '#default_value' => $urow[0]['lastname'],
    '#prefix' => '<div style="float: left;width:300px" >',
    '#suffix' => '</div><br/>',

  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#prefix' => '<div style="float:left;clear:left;width:300px" >',
    '#suffix' => '</div>',
  );

//  todo: make this work when cancelled (it currently also calls the Submit function)
//  $form['actions']['cancel'] = array(
//    '#type' => 'submit',
//    '#value' => t('Cancel'),
//    '#submit' => kleosis_users_edit_form_cancel($form, &$form_state),
//    '#prefix' => '<div style="float: right;width:550px" >',
//    '#suffix' => '</div>',
//  );

  $form['actions']['cancel'] = array(
    '#type' => 'item',
    '#markup' => l(t('Cancel'), 'kleosis/lms_direct/list', array()),
    '#prefix' => '<div style="float:left;width:300px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 *
 * Implementation of hook_submit() for the Users Edit form.
 *
 * Call another function in kleosis_ws.inc (keeps the ws calls in one file)
 *
 */
  function kleosis_users_edit_form_submit($form, &$form_state) {

 // todo: make this work when cancelled with the Cancel Button in the form

  if ($form_state['clicked_button']['#value'] == 'Cancel') {

      drupal_set_message(t('The clicked-button value was set.'));
  }

  ws_users_edit_form_submit_values($form_state['values']);  // pass the data to kleosis_ws.inc

  $message = array('@user' => $form_state['values']['username'], '@updated' => t('successfully updated.'));
  drupal_set_message(t('User @user @updated', $message));

  $form_state['redirect'] = 'kleosis/lms_direct/list';   // d7:

  return;
}

/**
 *
 * Implementation of hook_validate() for the Users Edit form.
 *
 */
function kleosis_users_edit_form_validate($form, &$form_state) {

//  drupal_set_message('User '.$form_state['values']['username'].' has been validated.');  // todo: update this with real validation...
}

/**
 *
 * Cancel from the edit_users form Cancel Button
 *
 */
  function kleosis_users_edit_form_cancel($form, &$form_state) {

 // todo: make this work when called with the Cancel Button in the form (it currently also calls the Submit function)

//  drupal_set_message('the triggering_element: ' . $form['triggering_element']);
//  drupal_goto($path = 'kleosis/users/list', $options = array(), $http_response_code = 302);

  return;
}

/**
 * Create the User Roles list
 *
 * @return
 *   The User Roles list (HTML)
 */
function show_rtable($table = NULL, $rows_per_page = 3) {
  $header[0] = array(
    'data' => 'Id',
    'field' => '`' . 'id' . '`',
  );
  $header[1] = array(
    'data' => 'Name',
    'field' => '`' . 'name' . '`',
  );
  $header[2] = array(
    'data' => 'Description',
    'field' => '`' . 'description' . '`',
  );

  $rolesa = ws_get_roles();  // from kleosis_ws.inc

  drupal_set_title(t('Moodle User Roles - demo'));

  $output = '<p>' . t('Requested feature: Click on a column title to sort by that column...') . '</p><br/>';
  $output .= theme('table', array('header' => $header, 'rows' => $rolesa, 'attributes' => array(), 'caption' => NULL, 'colgroups' => array(), 'sticky' => TRUE));

  return $output;
}

/*****************************************************************************
  *
  * Legacy development and sample code for d6 - kept for reference (or amusement)?
  *
*****************************************************************************/

/**
 * Implementation of hook_form_alter().
 *
 * The function is named modulename_form_alter.

 function kleosis_form_alter(&$form, $form_state, $form_id) {
 // Normally a switch is used because you may want to alter more than
 // one form and it is easy to add a new case for each form.
 // dpm('<br/> inside function kleosis_form_alter <br/>');
 switch ($form_id) {
 // This is our form ID.
 case 'kleosis_form':
 // Our kickin' mods go here.
 //    return print_r($form);
 }
 }

 */

/**
 * The callback function (form constructor) that creates the HTML form for kleosis_roles().
 *
 * @return form an array of form data.

 function kleosis_roles_form() {
 $form['kleosis_roles'] = array(
 '#type' => 'textarea',
 '#title' => t('Roles'),
 '#default_value' => variable_get('kleosis_roles', 'Test roles'),
 '#cols' => 50,
 '#rows' => 5,
 '#description' => t("Enter a test message..."),
 );

 //Submit button:
 $form['submit'] = array(
 '#type' => 'submit',
 '#value' => t('Save Message'),
 );

 return $form;
 }
 */

/**
 * Form validation for the roles form
 *
 * @param form an array that contains the roles form
 * @param form_state an array that contains roles form settings

 function kleosis_roles_form_validate($form, &$form_state) {
 $kleosis_roles = $form_state['values']['kleosis_roles'];
 if (isset($kleosis_roles)) {
 if (!is_string($kleosis_roles) || $kleosis_roles == '') {
 form_set_error('kleosis_roles', t('Please enter a test message.'));
 }
 }
 }
 */

/**
 * Form submission for user data in the roles form.
 *
 * @param form an array that contains user data
 * @param form_state an array that contains user data

 function kleosis_roles_form_submit($form, &$form_state) {

 /*    $test_roles = $form_state['values']['kleosis_roles'];
 $exe_query = db_query("INSERT INTO {kleosis_log} (timestamp, message) VALUES(%d, '%s')", time(), $test_roles);

 $last_id = db_last_insert_id('{kleosis_log}','id');
 if ($exe_query !== false) {
 $msg = 'Added message to log: %id';
 $vars = array('%id'=>$last_id);
 watchdog('kleosis', $msg, $vars, WATCHDOG_INFO);
 drupal_set_roles(t('Added message to log: ').strval($last_id));
 } else {
 $msg = 'Could not add message to log: ';
 $vars = array();
 watchdog('kleosis', $msg, $vars, WATCHDOG_ERROR);
 drupal_set_roles(t('Could not add message to log.'));
 }

 $form_state['redirect'] = 'kleosis';
 }
 */

