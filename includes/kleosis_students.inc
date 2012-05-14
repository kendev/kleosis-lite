<?php

/**
 * @file
 *   Kleosis Students functions
 */

/**
 * Render a filtered list of students in the database.
 *
 * This can be considered as the Kleosis 'Main Page'
 *
 */
function kleosis_students_list_form() {

  $form['filter'] = kleosis_students_filter_form();
  $form['#submit'][] = 'kleosis_students_filter_form_submit';
  $form['list'] = kleosis_students_list();

  return $form;
}

/**
 *
 * Students filters form
 *
 */
function kleosis_students_filter_form() {

  // get the filter values from the session variable (if any) and set the default values accordingly
  $field = isset($_SESSION['student_filter']['field']) ? $_SESSION['student_filter']['field'] : '';
  $oper = isset($_SESSION['student_filter']['oper']) ? $_SESSION['student_filter']['oper'] : '';
  $thename = isset($_SESSION['student_filter']['thename']) ? $_SESSION['student_filter']['thename'] : '';
  $student_status = isset($_SESSION['student_filter']['student_status']) ? $_SESSION['student_filter']['student_status'] : 1;

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = t('Student List');

  drupal_set_breadcrumb($breadcrumb);

  // create a fieldset with search elements
  $form['searchuser'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student Search'),
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['searchuser']['field'] = array(
    '#type' => 'select',
    '#title' => t('Where'),
    '#options' =>  fill_searchuser_items(),
    '#default_value' => !empty($field) ? $field : 'username',
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['searchuser']['oper'] = array(
  '#type' => 'select',
    '#title' => t('Operator'),
    '#options' =>  array('is' => t('is'), 'like' => t('like')),
    '#default_value' => !empty($oper) ? $oper : 'is',
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );
  $form['searchuser']['thename'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter name'),
    '#size' => 30,
    '#maxlength' => 64,
    '#default_value' => !empty($thename) ? $thename : '',
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $form['searchuser']['student_status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
	'#options' =>  ks_get_student_statuses(),
    '#default_value' => $student_status,
    '#weight' => '15',
    '#prefix' => '<div style="float: right;width:150px" >',
    '#suffix' => '</div>',
  );
  $form['searchuser']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Clear'),
    '#weight' => '5',
    '#prefix' => '<div style="float: right;width:100px" >',
    '#suffix' => '</div>',
  );

  $form['searchuser']['search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#weight' => '10',
    '#prefix' => '<div style="float: right;width:100px" >',
    '#suffix' => '</div>',
  );

  drupal_add_library('system', 'drupal.form');
  return $form;
}

/**
 * Fill the searchuser select box for the Students List form
 *
 * @return
 *    An array of items to select
 */
function fill_searchuser_items() {

  $le_array = array(
    'username' => t('Username'),
    'fullname' => t('Fullname'),
    'friendlyname' => t('Friendlyname'),
    'gradelevel' => t('Gradelevel'),
  );
  return $le_array;
}

/**
 * Fill the Update options select box for the Students List form
 *  - this is sample code for further development...
 *
 * @return
 *    An array of items to select
 */
function fill_updateoptions_items() {

  $op_array = array(
    'operation1' => t('Operation 1'),
    'operation2' => t('Operation 2'),
    'operation3' => t('Operation 3'),
  );
  return $op_array;
}

/**
 * Provides a searchable list of students
 *
 * @return
 *   tbd
 */

function kleosis_students_list() {

drupal_set_title(t('Student List'));

  global $base_root;
  global $user;
  $form = array();

  // get the filter values from the session variable (if any) and set the default form values accordingly

  $field = isset($_SESSION['student_filter']['field']) ? $_SESSION['student_filter']['field'] : '';
  $oper = isset($_SESSION['student_filter']['oper']) ? $_SESSION['student_filter']['oper'] : '';
  $thename = isset($_SESSION['student_filter']['thename']) ? $_SESSION['student_filter']['thename'] : '';
  $student_status = isset($_SESSION['student_filter']['student_status']) ? $_SESSION['student_filter']['student_status'] : 1;

  // create another fieldset for multiple update options (tbd...)
/*
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -5,
  );
  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => fill_updateoptions_items(),
    '#default_value' => '',
  );
  $options = array();
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#submit' => array('kleosis_students_list_submit'),
  );
*/
  $nn_title = t('hide national name');
  $show_nn = TRUE;
  if( (!isset($_SESSION['kleosis_general_admin']['show_national_name'])) || ($_SESSION['kleosis_general_admin']['show_national_name'] == FALSE) ) {
    $nn_title = t('show national name');
    $show_nn = FALSE;
  }

  if( !(variable_get('kleosis_view_national_name', '1')) ) {
   $form['national_name'] = array(
    '#type' => 'link',
    '#title' => $nn_title,
    '#access' => ( in_array('administrator', $user->roles) || user_access('view kleosis student info') ),
    '#href' => $base_root . url('kleosis/admin/general', array('query' => array('ksopid' => 'national_name', 'ksop' => 'toggle', 'destination' => 'kleosis/students', ))),
    '#prefix' => '<div style="float:left;width:250px">',
    '#suffix' => '</div>',
    );
  }

  // the header contains all the fields that will be displayed in the tableselect list
  if ($show_nn) {
    $header = array(
      'name' => array('data' => t('Username'), 'field' => 'u.name'),
  //    'drp_uid_fk' => array('data' => t('Student id'), 'field' => 'kstu.drp_uid_fk'),
      'fullname' => array('data' => t('Fullname'), 'field' => 'kstu.fullname'),
      'friendlyname' => array('data' => t('Friendly Name'), 'field' => 'kstu.friendlyname'),
      'fullname_t' => array('data' => t('Fullname (National)'), 'field' => 'kstu.fullname_t'),
      'program' => array('data' => t('Program'), 'field' => 'kpgm.program'),
      'gradelevel' => array('data' => t('Gradelevel'), 'field' => 'kgrdl.gradelevel'),
      'status' => array('data' => t('Status'), 'field' => 'ksts.status'),
  //    'operations' => array('data' => t('Ops')),
    );
  }
  else {
    $header = array(
      'name' => array('data' => t('Username'), 'field' => 'u.name'),
  //    'drp_uid_fk' => array('data' => t('Student id'), 'field' => 'kstu.drp_uid_fk'),
      'fullname' => array('data' => t('Fullname'), 'field' => 'kstu.fullname'),
      'friendlyname' => array('data' => t('Friendly Name'), 'field' => 'kstu.friendlyname'),
      'program' => array('data' => t('Program'), 'field' => 'kpgm.program'),
      'gradelevel' => array('data' => t('Gradelevel'), 'field' => 'kgrdl.gradelevel'),
      'status' => array('data' => t('Status'), 'field' => 'ksts.status'),
  //    'operations' => array('data' => t('Ops')),
    );
  }
  if (($field == 'username'))  {
    $query = db_select('users', 'u');
    $query->innerJoin('ks_students', 'kstu', 'kstu.drp_uid_fk = u.uid');
  }
  else{
    $query = db_select('ks_students', 'kstu');
    $query->innerJoin('users', 'u', 'u.uid = kstu.drp_uid_fk');
  }
  $query->innerJoin('ks_program_desc', 'kpgm', 'kpgm.kpgm_id = kstu.curr_main_program');
  $query->innerJoin('ks_gradelevel_desc', 'kgrdl', 'kgrdl.kgrdl_id = kstu.curr_gradelevel');
  $query->innerJoin('ks_student_status_desc', 'ksts', 'ksts.ksts_id = kstu.curr_status');
  $query->addField('u', 'name');
  $query->addField('kstu', 'kstu_id');
  $query->addField('kstu', 'drp_uid_fk');
  $query->addField('kstu', 'identity_id');
  $query->addField('kstu', 'fullname');
  $query->addField('kstu', 'friendlyname');
  $query->addField('kstu', 'fullname_t');
  $query->addField('kpgm', 'program');
  $query->addField('kgrdl', 'gradelevel');
  $query->addField('ksts', 'status');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  // adjust the query according to the filter values
  if (($field == 'username') && (!empty($thename)) )  {
    if ($oper == 'is') {
       $query->condition('u.' . 'name', $thename, '=');
    }
    else{
        $query->condition('u.' . 'name', '%' . $thename . '%', 'like');
    }
  }
  if (($field == 'fullname') && (!empty($thename)) )  {
    if ($oper == 'is') {
       $query->condition('kstu.' . 'fullname', $thename, '=');
    }
    else{
        $query->condition('kstu.' . 'fullname', '%' . $thename . '%', 'like');
    }
  }
  if (($field == 'friendlyname') && (!empty($thename)) )  {
    if ($oper == 'is') {
       $query->condition('kstu.' . 'friendlyname', $thename, '=');
    }
    else{
        $query->condition('kstu.' . 'friendlyname', '%' . $thename . '%', 'like');
    }
  }
  if (($field == 'gradelevel') && (!empty($thename)) )  {
    if ($oper == 'is') {
       $query->condition('kgrdl.' . 'gradelevel', $thename, '=');
    }
    else{
        $query->condition('kgrdl.' . 'gradelevel', '%' . $thename . '%', 'like');
    }
  }
  if ($student_status) {
    $query->condition('kstu.' . 'curr_status', $student_status, '=');
	}
//  $count_query = clone $query;
//  $count_query->addExpression('COUNT(kstu.kstu_id)');

  $query = $query->extend('PagerDefault')->limit(variable_get('kleosis_pager_rows', 16));
  $query = $query->extend('TableSort');
  $query->orderByHeader($header);

//  $query->setCountQuery($count_query); // this breaks the pager...

  $options = array();

  $results = $query->execute()->fetchAll();

  foreach ($results as $student) {
    if ($show_nn) {
      $options[$student->drp_uid_fk] = array(
  //      'name' => l($student->name , 'user/' . $student->drp_uid_fk, array('query' => array('destination' => 'kleosis/students/list'))),
  //      'name' => $student->name,
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->drp_uid_fk, 'ksop' => $student->name))),
  //      'drp_uid_fk' =>  $student->drp_uid_fk,
        'fullname' =>  !empty($student->fullname) ? $student->fullname : '(' . $student->name . ')',
  //      'identity_id' => $student->identity_id,
        'friendlyname' => $student->friendlyname,
        'fullname_t' => $student->fullname_t,
        'program' => $student->program,
        'gradelevel' => $student->gradelevel,
        'status' =>  $student->status,
  //      'operations' => l(t('edit'), 'user/' . $student->drp_uid_fk . '/edit', array('query' => array('destination' => 'kleosis/students/list')))
  //      'operations' => l(t('edit'), 'kleosis/std/summary/' . $student->drp_uid_fk, array('query' => array('destination' => 'kleosis/students/list')))
  //      'operations' =>  l(t('Summary page'), 'kleosis/students/summary', array('query' => array('ksopid' => $student->drp_uid_fk, 'ksop' => $student->name)))
      );
    }
    else {
      $options[$student->drp_uid_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->drp_uid_fk, 'ksop' => $student->name))),
        'fullname' =>  !empty($student->fullname) ? $student->fullname : '(' . $student->name . ')',
         'friendlyname' => $student->friendlyname,
        'program' => $student->program,
        'gradelevel' => $student->gradelevel,
        'status' =>  $student->status,
      );
    }
  }
  $form['students'] = array(
        '#type' => 'table',       // used for table
//        '#type' => 'tableselect',   // used for tableselect
        '#theme' => 'table',      // used only for table
        '#header' => $header,
//        '#options' => $options,   // used for tableselect
        '#rows' => $options,   // used for table
        '#empty' => t('No students are defined for the selected filter values.'),
        '#multiple' => TRUE,
        '#js_select' => TRUE,
      );
  $form['pager'] = array('#markup' => theme('pager'));

return $form;

}

/**
 *
 * Implementation of hook_submit() for the Students List form.
 *  - not used yet - sample code iterates thru the checked students...
 *
 */
function kleosis_students_list_submit($form, &$form_state) {

  if ($form_state['values']['op'] == 'Update') {

    $checked = '';
    foreach ($form_state['values']['students'] as $key => $value) {
      if ($value <> 0) {
        $checked .= $value . ', ';
      }
    }
    $msg = "Update options '" . $form_state['values']['operation'] . "' was selected with Student id's: ";

    if (empty($checked)) {
      $checked = 'none.';
    }
    $msg .= $checked;
    drupal_set_message($msg);
  }
}
/**
 *
 * Implementation of hook_submit() for the Students List form.
 *   - main purpose is to store the selected student, operation, and user into session variables
 *
 */
function kleosis_students_filter_form_submit($form, &$form_state) {

//  dpm('todo: maybe implement session functionality like kleosis_reports_and_queries  courses_filter_form_submit');


    if ($form_state['values']['op'] == 'Clear') {
        $_SESSION['student_filter'] = array();
    }
    else {
        $_SESSION['student_filter'] = array('field' => $form_state['values']['field'],
                                        'oper' => $form_state['values']['oper'],
                                        'thename' => $form_state['values']['thename'],
                                        'student_status' => $form_state['values']['student_status'], );
    }
}

/**
 * Display the Summary Student form for kleosis
 *
 * @param $optarg
 *   An optional argument placeholder (not used yet)
 * @return
 *   The Summary Student form for Kleosis
 */
function kleosis_student_summary($optarg) {

  return drupal_get_form('kleosis_student_summary_form');
}

/**
 * Define the Student Summary form
 *
 * @return
 *    The Student Summary form
 */
function kleosis_student_summary_form($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Summary');

  drupal_set_breadcrumb($breadcrumb);

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message(t('Please select a student from the Student List'));
    $form_state['redirect'] = 'kleosis/students';
    drupal_redirect_form($form_state);
  }

  $_SESSION['student']['id'] = $uid;
  $_SESSION['student']['name'] = $name;

  drupal_set_title(t('Student Summary'));
  $defaults = FALSE;  // will allow the form fields to show the user data

  $guardian = FALSE;
  $emergency_contact = TRUE;
  $ks_usertype = 'ks_student';
  $ks_user = ks_get_student_record($uid);
  if (empty($ks_user)) {
      drupal_set_message(t('Student record is not available.'));
      return FALSE;
  }
/**********************************/
  $account = user_load($uid);
/**********************************/
  $defaults = TRUE;
  $ks_primary_guardian_id = ks_get_student_primary_guardian($uid);
  if (empty($ks_primary_guardian_id)) {
      $guardian = FALSE;
  }
  else {
      $ks_primary_guardian = ks_get_parent_guardian_record($ks_primary_guardian_id);
      $guardian = TRUE;
  }

  $ks_emergency_contact_id = ks_get_student_emergency_contact($uid);

  if (empty($ks_emergency_contact_id)) {
      $emergency_contact = FALSE;
  }
  else {
      $ks_emergency_contact = ks_get_parent_guardian_record($ks_emergency_contact_id);
      $emergency_contact = TRUE;
  }

  $accd = (!empty($ks_user['acceptance_date'])) ? new DateTime($ks_user['acceptance_date']) : new DateTime('1901-01-01 0:0:00');
  $grdd = (!empty($ks_user['graduation_date'])) ? new DateTime($ks_user['graduation_date']) : new DateTime('1901-01-01 0:0:00');
/*
  $accd = (!empty($ks_user['acceptance_date'])) ?
          DateTime::createFromFormat('Y-m-d H:i:s', $ks_user['acceptance_date']) :
            DateTime::createFromFormat('Y-m-d H:i:s', '1900-01-01 0:0:00');
  $grdd = (!empty($ks_user['graduation_date'])) ?
          DateTime::createFromFormat('Y-m-d H:i:s', $ks_user['graduation_date']) :
            DateTime::createFromFormat('Y-m-d H:i:s', '1900-01-01 0:0:00');
*/
  $form = array();

  $form['spacer'] = array(
    '#markup' => ' ',
    '#prefix' => '<br/><div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['user_biodata'] = array(  // fieldset for biodata
      '#type' => 'fieldset',
      '#title' => t('Student Summary for:') . ' ' . ks_get_usernames_for_display($uid),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -5,
    );

  $form['user_biodata']['username'] = array(
    '#type' => 'item',
    '#title' => t('Username'),
    '#markup' => ($defaults)? $name : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['user_biodata']['friendlyname'] = array(
    '#type' => 'item',
    '#title' => t('Friendly Name'),
    '#markup' => ($defaults)? $ks_user['friendlyname']: '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
/**********************************/
/*
  $form['user_biodata']['user_picture'] = array(
    '#markup' => theme('user_picture', array('account' => $account)),
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
*/
/**********************************/
  $form['user_biodata']['identity_id'] = array(
    '#type' => 'item',
    '#title' => t('Identity ID'),
    '#markup' => ($defaults)? $ks_user['identity_id'] : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['user_biodata']['fullname'] = array(
    '#type' => 'item',
    '#title' => t('Full Name'),
    '#markup' => ($defaults)? $ks_user['fullname']: '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div>',
  );
  $form['user_biodata']['curr_status'] = array(
    '#type' => 'item',
    '#title' => t('Current Status'),
    '#markup' => ($defaults)? ks_get_student_status_desc($ks_user['curr_status']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['user_biodata']['curr_main_program'] = array(
    '#type' => 'item',
    '#title' => t('Current Main Program'),
    '#markup' => ($defaults)? get_program_desc($ks_user['curr_main_program']) : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['user_biodata']['curr_gradelevel'] = array(
    '#type' => 'item',
    '#title' => t('Current Grade Level'),
    '#markup' => ($defaults)? get_gradelevel_desc($ks_user['curr_gradelevel']) : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</span></div><br/>',
  );
  $form['user_biodata']['curr_campus'] = array(
    '#type' => 'item',
    '#title' => t('Current Campus'),
    '#markup' => ($defaults)? get_campus_desc($ks_user['curr_campus']) : '',
    '#prefix' => '<div style="float:left;cwidth:275px" >',
    '#suffix' => '</span></div><br/>',
  );
  $form['user_biodata']['acceptance_date'] = array(
    '#type' => 'item',
    '#title' => t('Student since'),
    '#markup' => ($defaults)? $accd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['user_biodata']['graduation_date'] = array(
    '#type' => 'item',
    '#title' => t('Anticipated Graduation Date'),
    '#markup' => ($defaults)? $grdd->format('d-M-Y') : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['user_biodata']['grd_fullname'] = array(
    '#type' => 'item',
    '#title' => t('Primary Guardian'),
//    '#markup' => ($guardian)? l($ks_primary_guardian['fullname'] , 'user/' . $ks_primary_guardian_id, array('query' => array())) : 'not set',
    '#markup' => ($guardian)? l($ks_primary_guardian['fullname'] , 'user/' . $ks_primary_guardian_id, array('query' => array('ksopid' => $uid, 'ksop' => $name))) : 'not set',
//    '#markup' => ($guardian)? $ks_primary_guardian['fullname'] : 'not set',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
    );
  $form['user_biodata']['emergency_contact'] = array(
    '#type' => 'item',
    '#title' => t('Emergency Contact'),
    '#markup' => ($emergency_contact)? l($ks_emergency_contact['fullname'] , 'user/' . $ks_emergency_contact_id, array('query' => array('ksopid' => $uid, 'ksop' => $name))) : 'not set',
    '#prefix' => '<div style="float:left;clear:left;width:275px" >',
    '#suffix' => '</div><br/>',
    );
  $form['user_biodata']['remarks'] = array(
    '#type' => 'item',
    '#title' => t('Remarks'),
    '#markup' => ($defaults)? $ks_user['remarks'] : '',
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
 return $form;
}

/**
 *
 * Implementation of hook_validate() for the Student Summary form.
 *  - code not used at the moment, was used for an earlier editable student summary form...
 *
 */
function kleosis_student_summary_form_validate($form, &$form_state) {

//  drupal_set_message('Student '.$form_state['values']['lastname'].' has been validated.');  // todo: update this with real validation...
}

/**
 *
 * Implementation of hook_submit() for the Student Summary form.
 *  - code not used at the moment, was used for an earlier editable student summary form...
 *
 */
  function kleosis_student_summary_form_submit($form, &$form_state) {

  $txn = db_transaction();

  $count = db_update('ks_students')
            ->condition('drp_uid_fk', $form_state['values']['userid'])
            ->fields(array('fullname' => $form_state['values']['fullname'],
                'friendlyname' => $form_state['values']['friendlyname'],
                'address_city' => $form_state['values']['address_city'], ))
             ->execute();

  $countu = db_update('ks_users')
            ->condition('drp_uid_fk', $form_state['values']['userid'])
            ->fields(array('name' => $form_state['values']['username'], ))
             ->execute();

//  $_SESSION['student_filter'] = array();  // clear the session


  $message = array('@user' => $form_state['values']['fullname'], '@updated' => t('successfully updated.'));
  drupal_set_message(t('Student @user @updated', $message));

  return;
}

/**
 * Provides a list of classes that a student is currently enrolled in
 *
 * @return
 *   tbd
 */
function kleosis_students_classes($form, &$form_state) {

  // check permissions
  global $user;
  $allow_edit = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('administer kleosis classes')) ) {
    $allow_edit = FALSE;
  }

  drupal_set_title(t('Student Classes'));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Classes');

  drupal_set_breadcrumb($breadcrumb);

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {

    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page.'));
    drupal_goto($path = 'kleosis/students', $options = array());

//      $build['no_student selected'] = array(
//     '#type' => 'markup',
//     '#markup' => '<p><br/>' . t('Please select a Student by clicking on a Student link.from the Student List page.') . '</p>',
//      );
//      return $build;
  }

  $_SESSION['student']['id'] = $uid;
  $_SESSION['student']['name'] = $name;


  $academic_year = isset($_SESSION['kleosis_students_classes']['academic_year']) ? $_SESSION['kleosis_students_classes']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['kleosis_students_classes']['term']) ? $_SESSION['kleosis_students_classes']['term'] : variable_get('kleosis_academic_term', 'fy');

 // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term,
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $build['acy_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  $academic_year,
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => $term,
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 5,
    '#disabled' => !in_array('administrator', $user->roles),
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );

  $usernames = ks_get_usernames_for_display($uid);  // get the display names for this user
  $text = t('Enrolled classes for Student <strong>@name</strong>' . ': ', array('@name' => $usernames));
  $build['theclasses'] = array(
      '#markup' => $text,
      '#prefix' => '',
      '#suffix' => '<br/>',
    );

  // the header contains all the fields that will be displayed in the tableselect list
  $header = array(
//    'name' => array('data' => t('Username'), 'field' => 'u.name'),
    'title' => 'Class Name',
    'ib_level' => array('data' => t('IB Level'), 'field' => 'ksscc.ib_level'),
    'course_no' => array('data' => t('Course No'), ),
    'enrol_date' => array('data' => t('Enrol Date'), 'field' => 'ksscc.enrol_date'),
//    'completed' => array('data' => t('Completed'), 'field' => 'ksscc.completed'),
//    'final_grade' => array('data' => t('Current Grade'), 'field' => 'ksscc.final_grade'),
//    'final_attendance' => array('data' => t('Current Absences'), 'field' => 'ksscc.final_attendance'),
    'remarks' => array('data' => t('Remarks'), 'field' => 'ksscc.remarks'),
    'operations' => array('data' => t('Ops')),
  );

//  $classid = $_SESSION['kleosis_class_selected_class']['classid'];

// get the class nids for the selected academic year and term:

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_status', 'value', '1', '=')  // 'Active'
  ->propertyCondition('status', 1)  // not needed, just an example...
  // ->fieldCondition('example_field_date', 'value', array('2011-03-01', '2011-03-31'), 'BETWEEN')    // not needed, just an example...
  // ->fieldCondition('example_other_field', 'state', (array) $states, 'IN', 0);   // not needed, just an example.
  ->fieldOrderBy('ks_class_academic_year', 'value', 'ASC');

  $result = $query->execute();

  $nids = array();

  if ( !empty($result) ) {
    $nids = array_keys($result['node']);  // these nids will be used to filter the following query:
  }
  else {
    $build['no_classes'] = array(
      '#markup' => 'There are no classes defined for the selected academic year and term.',
      '#prefix' => '<br/><div style="float: left;clear: left;width:550px"><strong>',
      '#suffix' => '</strong></div>',
    );
    return $build;
  }

  $query = db_select('ks_student_course_classes', 'ksscc');
  $query->innerJoin('users', 'u', 'u.uid = ksscc.kstu_id_fk');
  $query->leftJoin('ks_ib_level_desc', 'ibl', 'ibl.kibl_id = ksscc.ib_level');
  $query->addField('u', 'name');
  $query->addField('ksscc', 'ksccl_id');
  $query->addField('ksscc', 'kstu_id_fk');
  $query->addField('ksscc', 'kccls_id_fk');
  $query->addField('ibl', 'ib_level');
  $query->addField('ksscc', 'enrol_date');
  $query->addField('ksscc', 'completed');
  $query->addField('ksscc', 'final_grade');
//  $query->addField('ksscc', 'final_attendance');
  $query->addField('ksscc', 'remarks');

  $query->condition('ksscc.' . 'kstu_id_fk', $uid, '=');
  $query->condition('ksscc.' . 'kccls_id_fk', $nids, 'IN');
  $query->isNull('unenrol_date');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  $query = $query->extend('PagerDefault')->limit(variable_get('kleosis_pager_rows', 16));
  $query = $query->extend('TableSort');
  $query->orderByHeader($header);

//  $query->setCountQuery($count_query); // this breaks the pager...

  $options = array();

  $results = $query->execute()->fetchAll();

  foreach ($results as $student) {

    $node = node_load($student->kccls_id_fk);

//  get the Course Number (short coursename)

    if ($student->kccls_id_fk) {
      $class_node = node_load($student->kccls_id_fk);
      $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
      $course_node = node_load($node_course_ref);
      $node_course_no =   $course_node->ks_course_no['und'][0]['value'];
    }
    else {
      $node_course_no =  '';
    }

    $options[$node->nid] = array(
//      'name' => l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
//      'title' =>  $node->title,
      'title' => l($node->title, 'kleosis/classes/details/' . $student->kccls_id_fk, array('query' => array('ksop' => 'view', 'destination' => 'kleosis/classes'))),
      'ib_level' =>  $student->ib_level,
      'course_no' =>  $node_course_no,
      'enrol_date' =>  $student->enrol_date,
//      'completed' =>  $student->completed,
//      'final_grade' =>  $student->final_grade,
//      'final_attendance' =>  $student->final_attendance,
      'remarks' =>  $student->remarks,
//      'operations' => l(t('edit'), 'kleosis/std/summary/' . $student->drp_uid_fk, array('query' => array('destination' => 'kleosis/students/list')))
//      'operations' =>  l(t('Summary'), 'kleosis/students/summary', array('query' => array('ksopid' => $student->drp_uid_fk, 'ksop' => $student->name)))
//      'operations' =>  l(t('Other courses'), 'kleosis/students/courses', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name)))
//      'operations' =>  l(t('edit'), 'kleosis/students/classes/details/edit', array('query' => array('ksopid' => $student->ksccl_id, 'ksop' => 'edit')))
//      'operations' =>  t('edit')
      'operations' =>  $allow_edit ? l(t('edit'), 'kleosis/students/classes/details/edit', array('query' => array('ksopid' => $student->ksccl_id, 'ksop' => 'edit'))) : t('edit')

    );
  }
  $build['students'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => t('The student is not currently enrolled in any class for the system academic year and term.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );
  $build['pager'] = array('#markup' => theme('pager'));

  return $build;

}

/**
 *
 * Implementation of hook_submit() for the Students Classes form.
 *
 */
function kleosis_students_classes_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Apply':

      $_SESSION['kleosis_students_classes'] = array('academic_year' => $form_state['values']['academic_year'],
                                                    'term' => $form_state['values']['term'],
                                                    );
      break;
  }
}

/**
 * Provides a view form for a record in the ks_student_course_classes table (not used yet...)
 *
 * @return
 *   the form
 */
function kleosis_student_course_class_view() {

  require_once('forms/kleosis_student_course_class_view_form.inc');

  return drupal_get_form('kleosis_student_course_class_view_form');
}

/**
 * Provides an edit form for a record in the ks_student_course_classes table
 *
 * @return
 *   the form
 */
function kleosis_student_course_class_edit() {

  require_once('forms/kleosis_student_course_class_edit_form.inc');

  return drupal_get_form('kleosis_student_course_class_edit_form');
}

/**
 * Defines a student classes placeholder tab
 *
 * @return
 *    a markup blurb...
 */
function kleosis_student_classes_ph($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Class Schedule');

  drupal_set_breadcrumb($breadcrumb);

 drupal_set_title(t('Student Classes'));


$page_desc = <<<EOT
    <br/>This is the kleosis_student_classes form.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Student Classes'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );
//  drupal_goto($path = 'kleosis/students/classes/enrolled_classes', $options = array());
  drupal_goto($path = 'kleosis/students/classes/class_schedule', $options = array());
  return $form;
}

/**
 * Provides the class schedule for a student
 *
 * @return
 *   The student class schedule form
 */
function kleosis_student_class_schedule($form, &$form_state) {

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page'));
    drupal_goto($path = 'kleosis/students', $options = array());
  }

  $_SESSION['student']['id'] = $uid;
  $_SESSION['student']['name'] = $name;

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Class Schedule');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Class Schedule'));

  $build['filter'] = kleosis_student_class_schedule_acyt_select_form();
  $build['#submit'][] = 'kleosis_student_class_schedule_acyt_select_form_submit';
  $build['list'] = kleosis_student_class_schedule_list();

  return $build;
}

/**
 *
 * Academic year and term selection for the Students Class Schedule List form
 *
 */
function kleosis_student_class_schedule_acyt_select_form() {

//  $academic_year = isset($_SESSION['ks_student_class_schedule_select_filter']['academic_year']) ? $_SESSION['ks_student_class_schedule_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
//  $term = isset($_SESSION['ks_student_class_schedule_select_filter']['term']) ? $_SESSION['ks_student_class_schedule_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

  $academic_year = isset($_SESSION['kleosis_students_classes']['academic_year']) ? $_SESSION['kleosis_students_classes']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['kleosis_students_classes']['term']) ? $_SESSION['kleosis_students_classes']['term'] : variable_get('kleosis_academic_term', 'fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];
  global $user;

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term . '&nbsp; &nbsp; &nbsp; ' . t('Student') . ': ' . $name,
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $build['acy_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  $academic_year,
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => $term,
    '#disabled' => !in_array('administrator', $user->roles),
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 5,
    '#disabled' => !in_array('administrator', $user->roles),
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );

  $usernames = ks_get_usernames_for_display($uid);  // get the display names for this user
  $text = t('Class schedule for Student <strong>@name</strong>' . ': ', array('@name' => $usernames));
  $build['student_schedule'] = array(
      '#markup' => $text,
      '#prefix' => '',
      '#suffix' => '<br/>',
    );

  return $build;
}

/**
 *
 * Implementation of hook_submit() for the Students Class Schedule List form.
 *
 */
function kleosis_student_class_schedule_acyt_select_form_submit($form, &$form_state) {

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  switch ($form_state['values']['op']) {

    case 'Apply':
//      $_SESSION['ks_student_class_schedule_select_filter'] = array(
//                                        'academic_year' => $form_state['values']['academic_year'],
//                                        'term' => $form_state['values']['term'],
//                                       );
      $_SESSION['kleosis_students_classes'] = array(
                                          'academic_year' => $form_state['values']['academic_year'],
                                          'term' => $form_state['values']['term'],
                                          );
      break;
  }
}

/**
 * Provides the class schedule layout for a student
 *
 * @return
 *   build of the class schedule
 */
function kleosis_student_class_schedule_list() {

//  $academic_year = isset($_SESSION['ks_student_class_schedule_select_filter']['academic_year']) ? $_SESSION['ks_student_class_schedule_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
//  $term = isset($_SESSION['ks_student_class_schedule_select_filter']['term']) ? $_SESSION['ks_student_class_schedule_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

  $academic_year = isset($_SESSION['kleosis_students_classes']['academic_year']) ? $_SESSION['kleosis_students_classes']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['kleosis_students_classes']['term']) ? $_SESSION['kleosis_students_classes']['term'] : variable_get('kleosis_academic_term', 'fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // the header contains all the fields that will be displayed in the tableselect list
  $header = array(
    'period' => array('data' => t('Period'), ),
    'monday' => array('data' => t('Monday'), ),
    'tuesday' => array('data' => t('Tuesday'), ),
    'wednesday' => array('data' => t('Wednesday'), ),
    'thursday' => array('data' => t('Thursday'), ),
    'friday' => array('data' => t('Friday'), )
  );

//  $classid = $_SESSION['kleosis_class_selected_class']['classid'];

// get all class nids for the selected academic year and term:

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_status', 'value', '1', '=')  // 'Active'
  ->propertyCondition('status', 1)  // not needed, just an example...
  ->fieldOrderBy('ks_class_academic_year', 'value', 'ASC');

  $result = $query->execute();

  $build = array();
  $options = array();

  if ( !empty($result) ) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', array_keys($result['node']));

  // get the period start and end times from the class schedule for the classes that the student has (is) taken during the selected academic year and term

  $query = db_select('ks_student_course_classes', 'ksstuclass');
  $query->innerJoin('ks_class_schedule', 'ksclsched', 'ksclsched.kccls_id_fk = ksstuclass.kccls_id_fk');
  $query->addField('ksstuclass', 'ksccl_id');
  $query->addField('ksstuclass', 'kstu_id_fk');
  $query->addField('ksstuclass', 'kccls_id_fk');
  $query->addField('ksstuclass', 'enrol_date');
  $query->addField('ksstuclass', 'unenrol_date');
  $query->addField('ksclsched', 'period_start_datetime');
  $query->addField('ksclsched', 'period_end_datetime');
  $query->addField('ksclsched', 'period_day');

  $query->condition('ksstuclass.' . 'kstu_id_fk', $uid, '=');
  $query->condition('ksstuclass.' . 'kccls_id_fk', $nids, 'IN');
//  $query->condition('ksstuclass.' . 'enrol_date', 'unenrol_date', '<');

  $schedule_records = $query->execute()->fetchAll();

  // next, build an array of periods, classes, and days.  This array contains the full class schedule for the student

  $schedule_array = array();
  foreach ($schedule_records as $period) {

    $enrol_ok = $period->enrol_date > $period->unenrol_date; // check for enrol date greater than the possible unenroll date
    if ($enrol_ok) {
      $pstartd = !empty($period->period_start_datetime) ? new DateTime($period->period_start_datetime) : new DateTime('1900-01-02 03:04:05');
      $pendd = !empty($period->period_end_datetime) ? new DateTime($period->period_end_datetime) : new DateTime('1900-01-02 03:04:05');

      $a_start_period = $pstartd->format('H') . ':' . $aperiod = $pstartd->format('i');
      $an_end_period = $pendd->format('H') . ':' . $aperiod = $pendd->format('i');
      $aperiod = $a_start_period . '-' . $an_end_period;

      // get the short course name from the course node and link it to the class schedule

      if ($period->kccls_id_fk) {
        $class_node = node_load($period->kccls_id_fk);
        $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
        $course_node = node_load($node_course_ref);
        $node_course_no =   $course_node->ks_course_no['und'][0]['value'];
        $class_link = l($node_course_no, 'kleosis/classes/schedule', array('query' => array('ksopid' => $period->kccls_id_fk, 'ksop' => $class_node->title, 'destination' => 'kleosis/students/classes/class_schedule')));
      }
      else {
        $node_course_no =  '';
      }
//      $schedule_array[] = array('period' => $aperiod, 'class' => $node_course_no, 'day' => $period->period_day, ) ;
      $schedule_array[] = array('period' => $aperiod, 'class' => $class_link, 'day' => $period->period_day, ) ;
    }
  }

  // then, build the period column (day_0) from the periods in the schedule_array and make them unique

  $day_0 = array();

  foreach ($schedule_array as $key => $value) {
    if (!in_array($value['period'], $day_0)) {
      $day_0[] = $value['period'];
    }
  }

  // get the Morning, Lunch, and Breaktimes
  //  - note this may be deprecated if the technique changes to creating classes for the breaktimes...
  $breaktimes = kleosis_schedule_breaktimes();

  if ($breaktimes[0]['period'] <> '00:00-00:00') {
    $day_0[] = $breaktimes[0]['period'];  // morning break
  }
  if ($breaktimes[1]['period'] <> '00:00-00:00') {
    $day_0[] = $breaktimes[1]['period'];  // lunch break
  }
  if ($breaktimes[2]['period'] <> '00:00-00:00') {
    $day_0[] = $breaktimes[2]['period'];  // afternoon break
  }
  sort($day_0);

  //  now, loop through the schedule_array and do the following:
  //    for each period, find the matching period in the day_0 array and place the class id
  //    in the corresponding position in the day_n array, where n = the day
  //  the day_n arrays allow up to 16 periods per day - can easily extend this if needed

  $day_1 = array(0 => '', 1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => '', 10 => '', 11 => '', 12 => '', 13 => '', 14 => '', 15 => '', );
  $day_2 = array(0 => '', 1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => '', 10 => '', 11 => '', 12 => '', 13 => '', 14 => '', 15 => '', );
  $day_3 = array(0 => '', 1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => '', 10 => '', 11 => '', 12 => '', 13 => '', 14 => '', 15 => '', );
  $day_4 = array(0 => '', 1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => '', 10 => '', 11 => '', 12 => '', 13 => '', 14 => '', 15 => '', );
  $day_5 = array(0 => '', 1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => '', 10 => '', 11 => '', 12 => '', 13 => '', 14 => '', 15 => '', );
  $day_6 = array(0 => '', 1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => '', 10 => '', 11 => '', 12 => '', 13 => '', 14 => '', 15 => '', );
  $day_7 = array(0 => '', 1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => '', 10 => '', 11 => '', 12 => '', 13 => '', 14 => '', 15 => '', );

  foreach ($schedule_array as $key => $value) {

     switch ($value['day']) {

       case 1:

          // look for period in $day_0, get it's key, and insert the class in the same position of the $day_1 array
          $pkey = array_search($value['period'], $day_0);
          $day_1[$pkey] = $value['class'];
       break;

       case 2:

          $pkey = array_search($value['period'], $day_0);
          $day_2[$pkey] = $value['class'];
        break;
       case 3:

          $pkey = array_search($value['period'], $day_0);
          $day_3[$pkey] = $value['class'];
        break;
         break;
       case 4:

          $pkey = array_search($value['period'], $day_0);
          $day_4[$pkey] = $value['class'];
        break;
         break;
       case 5:

          $pkey = array_search($value['period'], $day_0);
          $day_5[$pkey] = $value['class'];
        break;
         break;
       case 6:

          $pkey = array_search($value['period'], $day_0);
          $day_6[$pkey] = $value['class'];
        break;
         break;
       case 7:

          $pkey = array_search($value['period'], $day_0);
          $day_7[$pkey] = $value['class'];
        break;
         break;
   }

  }
  // now add the breaktimes to the $day_n arrays

  $pkey_morning = array_search($breaktimes[0]['period'], $day_0); // morning break
  $pkey_lunch = array_search($breaktimes[1]['period'], $day_0); // morning break
  $pkey_afternoon = array_search($breaktimes[2]['period'], $day_0); // morning break

  if ($pkey_morning !== FALSE) {
    $day_1[$pkey_morning] = t('BREAK') . ' &nbsp;&nbsp;&nbsp;----->';
  }
  if ($pkey_lunch !== FALSE) {
    $day_1[$pkey_lunch] = t('LUNCH') . ' &nbsp;&nbsp;&nbsp;----->';
  }
  if ($pkey_afternoon !== FALSE) {
    $day_1[$pkey_afternoon] = t('BREAK') . ' &nbsp;&nbsp;&nbsp;----->';
  }

  // lastly, build the options array from the day arrays

  $options = array();
  foreach ($day_0 as $key => $value) {

    $options[$key] = array(
      'period' => $value,
      'monday' => $day_1[$key],
      'tuesday' => $day_2[$key],
      'wednesday' => $day_3[$key],
      'thursday' => $day_4[$key],
      'friday' => $day_5[$key],
//      'saturday' => $day_6[$key],
//      'sunday' => $day_7[$key],
      );
    }
  }
  asort($options);
  $build['students'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => t('No schedule exists for the student for the selected academic year and term.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );

  $build['pager'] = array('#markup' => theme('pager'));

  return $build;
}
