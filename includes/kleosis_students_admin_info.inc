<?php
// $Id$
/**
 * @file
 * kleosis Students admin info
 * Provides more kleosis Students functions
*/

/**
 * Set the relationships for students
 *
 * @return
 *   Form for the rendered list
 */

function kleosis_student_setrelations($callback_arg = '') {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis student info')) ) {
    drupal_set_message(t("You currently do not have permissions to view Kleosis student details."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  $krelid = isset($_GET['krelid']) ? $_GET['krelid'] : $callback_arg;
  $ksop = isset($_GET['ksop']) ? $_GET['ksop'] : $callback_arg;

  if ( ($ksop == 'remove_link') && (!empty($krelid)) ) {
    return drupal_get_form('ks_user_rel_delete_confirm', $krelid);
  }
  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = l(t('Student Summary'), 'kleosis/students/summary');
  $breadcrumb[] = t('Student Relationships');

  drupal_set_breadcrumb($breadcrumb);

  $build['ks_rel_edit'] = drupal_get_form('kleosis_student_relationships_edit_form');
  $build['#submit'][] = 'kleosis_student_relationships_edit_form_submit';
  $build['ks_rel_list'] = drupal_get_form('kleosis_student_relationships_list');

  return $build;
}

function kleosis_student_relationships_edit_form() {

//  get the filter values from the session variable (if any) and set the default values accordingly
//  $student = isset($_SESSION['student_relationships']['student']) ? $_SESSION['student_relationships']['student'] : '';
  $student = isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : arg(4);
  $relationship = isset($_SESSION['student_relationships']['relationship']) ? $_SESSION['student_relationships']['relationship'] : '';
  $user_student = isset($_SESSION['student_relationships']['user_student']) ? $_SESSION['student_relationships']['user_student'] : '';

  $student = isset($_GET['ksid']) ? $_GET['ksid'] : $student;   // ksid if coming from edit student...

  $pguard = array_keys(ks_get_user_relationships(), 'Primary Guardian');  // get the Primary Guardian key

  // create a fieldset with relationship elements
  $form['setrelation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Set Relationships for Student') . ': ' . ks_get_usernames_for_display($student),
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['setrelation']['student'] = array(
    '#type' => 'select',
    '#title' => t('Student'),
    '#options' =>  ks_get_all_students(),
    '#default_value' => !empty($student) ? $student : 1,
    '#prefix' => '<div style="float: left; clear:left;width:250px" >',
    '#disabled' => TRUE,
    '#suffix' => '</div>',
  );
  $form['setrelation']['relationship'] = array(
    '#type' => 'select',
    '#title' => t('Relationship'),
    '#options' =>  ks_get_user_relationships(),
//    '#default_value' => !empty($relationship) ? $relationship : $pguard[0],
    '#default_value' => !empty($relationship) ? $relationship : 0,
    '#prefix' => '<div style="float:left;width:175px" >',
    '#suffix' => '</div>',
  );
  $form['setrelation']['user_student'] = array(
    '#type' => 'select',
    '#title' => t('User/Student'),
//    '#options' =>  array('student01_key' => t('student01_value'),'student02_key' => t('student02_value')),
//    '#default_value' => 'student02_key',
    '#options' =>  ks_get_all_ks_users() + ks_get_all_students(),
    '#default_value' => !empty($user_student) ? $user_student : 1,
    '#prefix' => '<div style="float:left;width:150px" >',
    '#suffix' => '</div>',
  );
/*
  $form['setrelation']['getrel'] = array(
    '#type' => 'submit',
    '#value' => t('Get Relationships'),
    '#weight' => '9',
    '#prefix' => '<div style="float: left;clear:left;width:300px" >',
    '#suffix' => '</div>',
  );
*/
  $form['setrelation']['setrel'] = array(
    '#type' => 'submit',
    '#label' => t('Action'),
    '#value' => t('Add New Relationship'),
    '#weight' => '10',
    '#prefix' => '<div style="float:right;width:225px" >',
    '#suffix' => '</div>',
  );
/*
  $form['setrelation']['student_summary'] = array(
    '#type' => 'item',
    '#title' => t('View Student Summary'),
    '#markup' => l('Student Summary' , 'kleosis/students/summary', array()),
    '#weight' => '12',
    '#prefix' => '<div style="float:left;clear:left;width:600px" ><hr/>',
    '#suffix' => '</div>',
    );
*/
  drupal_add_library('system', 'drupal.form');
  return $form;

}
function kleosis_student_relationships_edit_form_submit($form, &$form_state) {

    $_SESSION['student_relationships'] = array('student' => $form_state['values']['student'],
                                    'relationship' => $form_state['values']['relationship'],
                                    'user_student' => $form_state['values']['user_student'], );

    if ($form_state['values']['op'] == 'Get Relationships') {
      // drupal_set_message('Will get relationships now...');
    }
    elseif ($form_state['values']['op'] == 'Add New Relationship') {

    //  check if already exists!

      $query = db_select('ks_user_relationships', 'kurels');
      $query->addField('kurels', 'kusr_id_fk');
      $query->addField('kurels', 'relationship');
      $query->addField('kurels', 'kusr_rel_id_fk');
      $query->condition('kusr_id_fk', $form_state['values']['student'], '=');
      $query->condition('relationship', $form_state['values']['relationship'], '=');
      $query->condition('kusr_rel_id_fk', $form_state['values']['user_student'], '=');
      $results = $query->execute()->fetchAll();

      if (!empty($results)) {
         drupal_set_message(t('Student relationship already exists.'));
       }
       else {

        $cnt = db_insert('ks_user_relationships')
            ->fields(array( 'kusr_id_fk' => $form_state['values']['student'],
                            'kusr_rel_id_fk' => $form_state['values']['user_student'],
                            'relationship' => $form_state['values']['relationship'],
                            'description' => '') )
            ->execute();

       // drupal_set_message('Student '.$form_state['values']['student'].' new relationship was added.');
       drupal_set_message(t('New relationship was successfully added.'));
       }
    }
}

/**
 * Provides a list of student relationships
 *
 * @return
 *   tbd
 */

function kleosis_student_relationships_list() {

  drupal_set_title(t('Student Relationships'));

  $form = array();

  // get the filter values from the session variable (if any) and set the default values accordingly
//  $student = isset($_SESSION['student_relationships']['student']) ? $_SESSION['student_relationships']['student'] : '';
  $student = isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : arg(4);
  $student_name = isset($_SESSION['student_relationships']['student']) ? $_SESSION['student_relationships']['student']['value'] : '';
  $relationship = isset($_SESSION['student_relationships']['relationship']) ? $_SESSION['student_relationships']['relationship'] : '';
  $user_student = isset($_SESSION['student_relationships']['user_student']) ? $_SESSION['student_relationships']['user_student'] : '';

  // the header contains all the fields that will be displayed in the tableselect list
  $header = array(
    'name' => array('data' => t(''), 'field' => 'u.name'),
    'relationship' => array('data' => t('has a relation'), 'field' => 'reldesc.relationship'),
    'kusr_rel_id_fk' => array('data' => t('with User/Student'), 'field' => 'kurels.kusr_rel_id_fk'),
    'operations' => array('data' => t('Ops')),
  );
  $query = db_select('ks_user_relationships', 'kurels');
  $query->innerJoin('users', 'u', 'u.uid = kurels.kusr_id_fk');
  $query->innerJoin('ks_user_relationships_desc', 'reldesc', 'reldesc.kurel_id = kurels.relationship');
  $query->addField('u', 'name');
  $query->addField('kurels', 'krel_id');
  $query->addField('kurels', 'kusr_id_fk');
  $query->addField('reldesc', 'relationship');
  $query->addField('kurels', 'kusr_rel_id_fk');  // for now

  $student = isset($_GET['ksid']) ? $_GET['ksid'] : $student;   // coming from edit student...
  if (!isset($student)) {
    $student = 0;
  }

  $query->condition('kusr_id_fk', $student, '=');
  $query = $query->extend('PagerDefault')->limit(variable_get('kleosis_pager_rows', 16));
  $query = $query->extend('TableSort');
  $query->orderByHeader($header);

//  $query->setCountQuery($count_query); // this breaks the pager...

  $options = array();

  $results = $query->execute()->fetchAll();

  $studentname = '';
  foreach ($results as $relation) {
    $studentname = $relation->name;   // todo: get this a better way
    $options[$relation->krel_id] = array(
//      'name' => l($relation->name , 'user/' . $relation->kusr_id_fk, array('query' => array('destination' => 'kleosis/students/setrelations'))),
//      'name' => l($relation->name , 'kleosis/students/summary', array('query' => array('a' => $relation->kusr_id_fk, 'b' => $relation->name))),
      'name' => $relation->name,
      'relationship' =>  $relation->relationship,
      'kusr_rel_id_fk' => l(get_ks_username_by_id($relation->kusr_rel_id_fk) , 'user/' . $relation->kusr_rel_id_fk, array('query' => array('destination' => 'kleosis/students/setrelations'))),
      'operations' => l(t('remove'), 'kleosis/students/summary/setrelations/' . $student, array('query' => array('krelid' => $relation->krel_id, 'ksop' => 'remove_link', 'destination' => 'kleosis/students/summary/setrelations/' . $student)))
    );
  }
  if (!empty($studentname)) {
    $studentname = ' for ' . $studentname;
  }
  $form['relations'] = array(
        '#type' => 'tableselect',
        '#theme' => 'tableselect',
        '#header' => $header,
        '#options' => $options,
        '#empty' => t('No relationships are defined') . $studentname,
        '#multiple' => TRUE,
        '#js_select' => TRUE,
      );
  $form['pager'] = array('#markup' => theme('pager'));

return $form;
}

/**
 * Removes a student relationship link
 *
 * @param $ksid
 *   The ks_user_relationships table primary key
 * @return
 *   zippo
 */
function ks_remove_rel_link($krelid) {

    db_delete('ks_user_relationships')
      ->condition('krel_id', $krelid)
      ->execute();

    drupal_set_message(t('Relationship was successfully removed.'));
}

// Implement the delete relationship confirm form
function ks_user_rel_delete_confirm($form, &$form_state, $krelid) {

  // todo: get this working...

    $form['confirm'] = array(
      '#type' => 'hidden',
      '#value' => 1,
    );
    $form['rel_id'] = array(
      '#type' => 'hidden',
      '#value' => $krelid,
    );
  return confirm_form($form,
                      t('Are you sure you want to remove this user relationship?'),
                      'kleosis/students/summary/setrelations', t('This action cannot be undone.'),
                      t('Remove'), t('Cancel'));
}

// hook_submit for the above confirm form
function ks_user_rel_delete_confirm_submit($form, &$form_state) {

  // Very interesting: this submit is called instead of the original form one...
  // So, all the removing logic should be done here.

  ks_remove_rel_link($form_state['values']['rel_id']);

  $form_state['redirect'] = 'kleosis/students/summary/setrelations';

  return;
}

/**
 * Add or delete a status change for a student
 *
 * @return
 *   Form for the rendered list
 */

function kleosis_student_set_status($callback_arg = '') {


  $kssid = isset($_GET['kssid']) ? $_GET['kssid'] : $callback_arg;
  $ksop = isset($_GET['ksop']) ? $_GET['ksop'] : $callback_arg;

  if ( ($ksop == 'remove_status') && (!empty($kssid)) ) {
   // dpm('ksop and kssid were passed and received...');
    return drupal_get_form('ks_student_status_delete_confirm', $kssid);
 }
  if (  (isset($_GET['ksid'])) && (!empty($_GET['ksid']))  ) {

      $_SESSION['student']['id'] = $_GET['ksid'];  // todo: store the name too...
      $_SESSION['student']['name']  = get_ks_username_by_id($_GET['ksid']);
}
  $build['ks_ss_detail_edit'] = drupal_get_form('kleosis_student_status_details_edit_form');
  $build['#submit'][] = 'kleosis_student_status_details_edit_form_submit';
  $build['ks_ss_detail_list'] = drupal_get_form('kleosis_student_status_details_list');

  return $build;
}

function kleosis_student_status_details_edit_form() {
//  get the filter values from the session variable (if any) and set the default values accordingly
//  $student = isset($_SESSION['student_status']['student']) ? $_SESSION['student_status']['student'] : '';
  $student = isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : arg(4);
  $student = isset($_GET['ksid']) ? $_GET['ksid'] : $student; // $ksid if coming from student edit form...

  $studentrec = ks_get_student_record($student);
  $stdt = new DateTime("now");

  // create a fieldset with status detail elements
  $form['status_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status Details for Student: ') . ' ' . ks_get_usernames_for_display($student),
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['status_details']['student'] = array(
    '#type' => 'select',
    '#title' => t('Student'),
    '#options' =>  ks_get_all_students(),
    '#default_value' => !empty($student) ? $student : 1,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left; clear:left;width:250px" >',
    '#suffix' => '</div>',
  );
  $form['status_details']['status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' =>  ks_get_student_statuses(),
    '#default_value' => $studentrec['curr_status'],
    '#prefix' => '<div style="float:left;width:150px" >',
    '#suffix' => '</div>',
  );
  $form['status_details']['status_reason'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter reason'),
    '#size' => 30,
    '#maxlength' => 64,
    '#default_value' => '',
    '#prefix' => '<div style="float: left;width:200px" >',
    '#suffix' => '</div>',
  );
  $form['status_details']['status_date'] = array(
    '#type' => 'date',
    '#title' => t('Enter Date'),
    '#default_value' => array(
       'month' => $stdt->format('n'),
       'day' => $stdt->format('j'),
       'year' => $stdt->format('Y'),
      ),
    '#prefix' => '<div style="float: left;clear:left;width:250px" >',
    '#suffix' => '</div>',
  );
  $form['status_details']['gradelevel'] = array(
    '#type' => 'select',
    '#title' => t('Gradelevel'),
    '#options' => ks_get_gradelevels(),
    '#default_value' => $studentrec['curr_gradelevel'],
    '#prefix' => '<div style="float:left;width:150px" >',
    '#suffix' => '</div><br/>',
  );
   $form['status_details']['remarks'] = array(
    '#type' => 'textarea',
    '#title' => t('Remarks'),
    '#cols' => 80,
    '#rows' => 1,
    '#default_value' => '',
    '#resizeable' => TRUE,
    '#prefix' => '<div style="float:left;width:200px" >',
    '#suffix' => '</div><br/>',
  );
/*
$form['status_details']['getstatuses'] = array(
    '#type' => 'submit',
    '#value' => t('Get Statuses'),
    '#weight' => '9',
    '#prefix' => '<div style="float: left;clear:left;width:250px" >',
    '#suffix' => '</div>',
  );
*/
  $form['status_details']['addstatus'] = array(
    '#type' => 'submit',
    '#value' => t('Add New Status'),
    '#weight' => '10',
    '#prefix' => '<div style="float:right;width:225px" >',
    '#suffix' => '</div>',
  );

  drupal_add_library('system', 'drupal.form');

  return $form;
}

function kleosis_student_status_details_edit_form_submit($form, &$form_state) {

    $_SESSION['student_status'] = array('student' => $form_state['values']['student']);

    if ($form_state['values']['op'] == 'Get Statuses') {
      // drupal_set_message('Will get statuses now...');
    }
    elseif ($form_state['values']['op'] == 'Add New Status') {

      $stdt = new DateTime();
      $stdt->setDate($form_state['values']['status_date']['year'], $form_state['values']['status_date']['month'], $form_state['values']['status_date']['day']);

      $cnt = db_insert('ks_student_status_details')
          ->fields(array( 'kstu_id_fk' => $form_state['values']['student'],
                          'ksts_id_fk' => $form_state['values']['status'],
                          'status_reason' => $form_state['values']['status_reason'],
                          'status_date' => $stdt->format('Y-m-d'),
                          'gradelevel' => $form_state['values']['gradelevel'],
                          'remarks' => $form_state['values']['remarks'],
                          ) )
          ->execute();

      $cnt = ks_set_student_status($form_state['values']['student'], $form_state['values']['status']);  // update the current status in the students record

     drupal_set_message(t('New student status was successfully added.'));
    }
}

/**
 * Provides a list of student statuses
 *
 * @return
 *   tbd
 */

function kleosis_student_status_details_list() {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis student info')) ) {
    drupal_set_message(t("You currently do not have permissions to view Kleosis student details."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }
  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = l(t('Student Summary'), 'kleosis/students/summary');
  $breadcrumb[] = t('Status Details');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Status Details'));

  $form = array();

  // get the filter values from the session variable (if any) and set the default values accordingly
//  $student = isset($_SESSION['student_status']['student']) ? $_SESSION['student_status']['student'] : '';
  $student = isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : arg(4);

  // the header contains all the fields that will be displayed in the tableselect list
  $header = array(
    'name' => array('data' => t(''), 'field' => 'u.name'),
    'status' => array('data' => t('Status'), 'field' => 'stsdesc.status'),
//    'status_date' => array('data' => t('Status Date'), 'field' => 'kssd.status_date'),  //  $stdt->format('d-M-Y')
    'status_date' => array('data' => t('Status Date')),
//    'status_reason' => array('data' => t('Reason')),
    'status_reason' => array('data' => t('Reason'), 'field' => 'kssd.status_reason'),
    'gradelevel' => array('data' => t('Gradelevel'), 'field' => 'grdldesc.gradelevel'),
    'remarks' => array('data' => t('Remarks'), 'field' => 'kssd.remarks'),
    'operations' => array('data' => t('Ops')),
  );
  $query = db_select('ks_student_status_details', 'kssd');
  $query->innerJoin('users', 'u', 'u.uid = kssd.kstu_id_fk');
  $query->innerJoin('ks_student_status_desc', 'stsdesc', 'stsdesc.ksts_id = kssd.ksts_id_fk');
  $query->innerJoin('ks_gradelevel_desc', 'grdldesc', 'grdldesc.kgrdl_id = kssd.gradelevel');
  $query->addField('u', 'name');
  $query->addField('kssd', 'kssd_id');
  $query->addField('kssd', 'kstu_id_fk');
  $query->addField('stsdesc', 'status');
  $query->addField('kssd', 'status_reason');
  $query->addField('kssd', 'status_date');
  $query->addField('grdldesc', 'gradelevel');
  $query->addField('kssd', 'remarks');  // for now

  $student = isset($_GET['ksid']) ? $_GET['ksid'] : $student;   // coming from edit student...
  if (!isset($student)) {
    $student = 0;
  }

  $query->condition('kstu_id_fk', $student, '=');
  $query->orderBy('kssd.status_date', 'DESC');
  $query->orderBy('kssd.kssd_id', 'DESC');
  $query = $query->extend('PagerDefault')->limit(10);
  $query = $query->extend('TableSort');
  $query->orderByHeader($header);

//  $query->setCountQuery($count_query); // this breaks the pager...

  $options = array();

  $results = $query->execute()->fetchAll();

  $studentname = '';
  foreach ($results as $statusdetail) {
    $studentname = $statusdetail->name;   // todo: get this a better way
    $options[$statusdetail->kssd_id] = array(
//      'name' => l($statusdetail->name , 'kleosis/students/summary', array('query' => array('a' => $statusdetail->kstu_id_fk, 'b' => $statusdetail->name))),
      'name' => $statusdetail->name,
      'status' =>  $statusdetail->status,
      'status_date' =>  $statusdetail->status_date,
      'status_reason' =>  $statusdetail->status_reason,
      'gradelevel' =>  $statusdetail->gradelevel,
      'remarks' =>  $statusdetail->remarks,
//      'operations' => l(t('delete status'), 'kleosis/students/summary/setstatus/' . $student, array('query' => array('ksopid' => $student, 'kssid' => $statusdetail->kssd_id, 'ksop' => 'remove_status', 'destination' => 'kleosis/students/summary/setstatus/' . $student)))
      'operations' => l(t('delete status'), 'kleosis/students/summary/setstatus/' . $student, array('query' => array('kssid' => $statusdetail->kssd_id, 'ksop' => 'remove_status', 'destination' => 'kleosis/students/summary/setstatus/' . $student)))
    );
  }
  if (!empty($studentname)) {
    $studentname = ' for ' . $studentname;
  }
  $form['statusdetails'] = array(
        '#type' => 'tableselect',
        '#theme' => 'tableselect',
        '#header' => $header,
        '#options' => $options,
        '#empty' => t('No status details defined') . $studentname,
        '#multiple' => TRUE,
        '#js_select' => TRUE,
      );
  $form['pager'] = array('#markup' => theme('pager'));

return $form;
}

/**
 * Removes a student status detail
 *
 * @param $ksid
 *   The ks_student_status_details table primary key
 * @return
 *   zippo
 */
function ks_remove_status_detail($kssid) {

//    drupal_set_message(t('Note: deleting a student status detail has been temporarily disabled until the process is further defined....'));

    db_delete('ks_student_status_details')
      ->condition('kssd_id', $kssid)
      ->execute();

    drupal_set_message(t('Student status detail was successfully removed.'));
}

// Implement the delete student status confirm form
function ks_student_status_delete_confirm($form, &$form_state, $kssid) {

  // todo: review this...

    $form['confirm'] = array(
      '#type' => 'hidden',
      '#value' => 1,
    );
    $form['status_id'] = array(
      '#type' => 'hidden',
      '#value' => $kssid,
    );
  return confirm_form($form,
                      t('Are you sure you want to delete this student status?'),
                      'kleosis/students/summary/setstatus', t('This action cannot be undone.'),
                      t('Delete'), t('Cancel'));
}

// hook_submit for the above confirm form
function ks_student_status_delete_confirm_submit($form, &$form_state) {

  // Very interesting: this submit is called instead of the original form one...
  // So, all the removing logic should be done here.

  ks_remove_status_detail($form_state['values']['status_id']);

  $form_state['redirect'] = 'kleosis/students/summary/setstatus';

  return;
}

/**
 * View biodata details for a student
 *
 * @return
 *   Redirects to the node/% page
 */
/*
function kleosis_biodata_details_view($callback_arg = '') {

  if ($callback_arg) {
    $path = 'user/' . $callback_arg;
    $options = array('destination' => 'kleosis/students');
    drupal_goto($path, $options, $http_response_code = 302);
    }
}
*/
function kleosis_biodata_details_view($callback_arg = '') {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis student info')) ) {
    drupal_set_message(t("You currently do not have permissions to view Kleosis student details."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = l(t('Student Summary'), 'kleosis/students/summary');
  $breadcrumb[] = t('Student Biodata Details');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Biodata Details'));

  $build = array();

  if ($callback_arg) {
    $account = user_load($callback_arg);
    $build['account'] = user_view($account);
    }
  return $build;
}

/*
//////////////////////This is just a bunch of early test code:  ////////////////////////

//  $roles = user_roles();
//  $rolesarray = array(array_search('student', $roles) => 4);
//   drupal_set_message('rolesarray_search returned: ' . array_search('student', $roles));
//   drupal_set_message('rolesarray returned: ' . $rolesarray[4]);

    $rolename = 'student';
    $role_id = ks_create_new_role($rolename);
    drupal_set_message('Role  '. $rolename . ' has rid of ' . $role_id);

   $user = array(
        'name' => 'student9904',
        'pass' => 'student9904',
        'mail' => 'student9904@student9904.com',
        'status' => 1,
        'roles' => array($role_id => $role_id)
    );

    try {

      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e)

    {
      drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

    if (!isset($newuser)) {

      drupal_set_message('User created already...');

    }else{

      drupal_set_message('User created and returned: ' . $newuser->uid);
    }
    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();

      drupal_set_message('User id is: ' . $drp_uid);

//    user_delete($drupal_uid_goes_here);

///////////////////////////////////////////////////////////////////////
*/
