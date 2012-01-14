<?php
// $Id$
/**
* @file
* kleosis Enrollment
*/

/**
 * Render a filtered list of students for enrollment
 *
 * @see db_select()
 *
 */
//function kleosis_enrollment_page($form, &$form_state) {
function kleosis_enrollment_page() {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = t('Student Enrollments');

  drupal_set_breadcrumb($breadcrumb);

  $build['enroll_actions'] = kleosis_students_enrollments_actions_form();
  $build['enrollments_filter'] = kleosis_students_enrollments_filter_form();
  $build['#submit'][] = 'kleosis_students_enrollments_filter_form_submit';
  $build['list'] = kleosis_enrollments_students_list();

  return $build;
}
/**
 *
 * Students filters form
 *
 */

//function kleosis_students_enrollments_filter_form($form, &$form_state) {
function kleosis_students_enrollments_filter_form() {

  // get the filter values from the session variable (if any) and set the default values accordingly
  $field = isset($_SESSION['kleosis_enrollments_filter']['field']) ? $_SESSION['kleosis_enrollments_filter']['field'] : '';
  $oper = isset($_SESSION['kleosis_enrollments_filter']['oper']) ? $_SESSION['kleosis_enrollments_filter']['oper'] : '';
  $thename = isset($_SESSION['kleosis_enrollments_filter']['thename']) ? $_SESSION['kleosis_enrollments_filter']['thename'] : '';

  $filter = ( ( ($field == 'username') || (empty($field)) ) && ( ($oper == 'is') || (empty($oper)) ) && (empty($thename)) ) ? '' : ' - ON';
  // create a fieldset with search elements
  $form['searchuser'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student filter') . $filter,
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['searchuser']['field'] = array(
    '#type' => 'select',
    '#title' => t('Where'),
    '#options' =>  fill_searchuser_items(),
    '#default_value' => !empty($field) ? $field : 'username',
    '#prefix' => '<div style="float: left;width:150px" >',
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
    '#title' => t('Enter value'),
    '#size' => 30,
    '#maxlength' => 64,
    '#default_value' => !empty($thename) ? $thename : '',
    '#prefix' => '<div style="float: left;width:300px" >',
    '#suffix' => '</div>',
  );

  $form['searchuser']['search'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => '10',
    '#prefix' => '<div style="float: left;width:125px" ><p>',
    '#suffix' => '</p></div>',
  );

  $form['searchuser']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Clear'),
    '#weight' => '15',
    '#prefix' => '<div style="float: left;width:125px" ><p>',
    '#suffix' => '</p></div>',
  );
/*
  $form['searchuser']['enroll'] = array(
    '#type' => 'submit',
    '#value' => t('Enroll Selected Students'),
    '#weight' => 20,
    '#prefix' => '<div style="float: left;clear:left; width:225px" >',
    '#suffix' => '</div>',
  );

  $form['searchuser']['unenroll'] = array(
    '#type' => 'submit',
    '#value' => t('Unenroll Selected Students'),
    '#weight' => 25,
    '#prefix' => '<div style="float: left; width:225px" >',
    '#suffix' => '</div>',
  );
*/
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
    'curr_gradelevel' => t('Gradelevel'),
    'username' => t('Username'),
    'curr_main_program' => t('Program'),
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
 *
 * Enrollments actions form
 *
 */

function kleosis_students_enrollments_actions_form() {

  // get the course value from the session variable (if any) and set the default value accordingly
  $class_from_filter = isset($_SESSION['ks_enrollments_class_filter']['class']) ? $_SESSION['ks_enrollments_class_filter']['class'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_enrollments_class_filter']['class_name']) ? $_SESSION['ks_enrollments_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_enrollments_class_filter']['academic_year']) ? $_SESSION['ks_enrollments_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_enrollments_class_filter']['term']) ? $_SESSION['ks_enrollments_class_filter']['term'] : 'fy';

  $sql = 'SELECT nid, title FROM {node} n WHERE n.type = :type AND n.status = :status ORDER BY n.title' ;
  $results = db_query($sql, array(':type' => 'class', ':status' => 1,) );
  $options = array();
  foreach ($results as $class) {
    $node = node_load($class->nid);
    $node_term =   $node->ks_class_term['und'][0]['value'];
    $node_academic_year =   $node->ks_class_academic_year['und'][0]['value'];
    if ( ($node_academic_year == $class_academic_year) || ($class_academic_year == 'all') ) { // iff year
     if ( ($node_term == $class_term) || ($class_term == 'all') ) { // iff term
        $options[$class->nid] = $class->title;
      } // iff term
    } // iff year
  }
  if (sizeof($options) == 0) {
//    drupal_set_message('empty result set');
    $options = array('0' => t('No classes exist for selected year and term'),);
  }
  // create a fieldset for the actions
  $form['enroll_actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select a class'),
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['enroll_actions']['class'] = array(
  '#type' => 'select',
    '#title' => t('Class'),
    '#options' =>  $options,
    '#default_value' => $class_from_filter,
    '#weight' => 1,
    '#prefix' => '<div style="float: left;width:420px" >',
    '#suffix' => '</div>',
  );
  $form['enroll_actions']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  !empty($class_academic_year) ? $class_academic_year : variable_get('kleosis_academic_year','2011-2012'),
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:130px" >',
    '#suffix' => '</div>',
  );
  $form['enroll_actions']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => !empty($class_term) ? $class_term : variable_get('kleosis_academic_term','fy'),
    '#weight' => 5,
    '#prefix' => '<div style="float: left;width:80px" >',
    '#suffix' => '</div>',
  );

  $form['enroll_actions']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Set year and term'),
    '#weight' => 10,
    '#prefix' => '<div style="float: right;width:200px" >',
    '#suffix' => '</div>',
  );

  return $form;
}
/**
 * Provides a searchable list of students
 *
 * @return
 *   tbd
 */

function kleosis_enrollments_students_list() {

  // check permissions
  global $user;
  $allow_enrollments = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('administer kleosis enrollments')) ) {
    $allow_enrollments = FALSE;
  }

  drupal_set_title(t('Student Enrollments'));

  $form = array();

  // get the filter values from the session variable (if any) and set the default form values accordingly

  $field = isset($_SESSION['kleosis_enrollments_filter']['field']) ? $_SESSION['kleosis_enrollments_filter']['field'] : '';
  $oper = isset($_SESSION['kleosis_enrollments_filter']['oper']) ? $_SESSION['kleosis_enrollments_filter']['oper'] : '';
  $thename = isset($_SESSION['kleosis_enrollments_filter']['thename']) ? $_SESSION['kleosis_enrollments_filter']['thename'] : '';

  $form['ib_level'] = array(
  '#type' => 'select',
    '#title' => t('IB Level'),
    '#options' =>  array('0' => ('0')),
    '#options' =>  ks_get_ib_levels(),
//    '#default_value' => $ib_level_from_filter,
    '#default_value' => 0,
    '#weight' => 0,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

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
    '#submit' => array('kleosis_enrollments_students_list_submit'),
  );
*/
  // the header contains all the fields that will be displayed in the tableselect list
  $header = array(
    'name' => array('data' => t('Username'), 'field' => 'u.name'),
//      'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
//    'drp_uid_fk' => array('data' => t('Student id'), 'field' => 'kstu.drp_uid_fk'),
    'identity_id' => array('data' => t('Identity id'), 'field' => 'kstu.identity_id'),
    'fullname' => array('data' => t('Fullname'), 'field' => 'kstu.fullname'),
    'program' => array('data' => t('Program'), 'field' => 'kpgm.program'),
    'gradelevel' => array('data' => t('Gradelevel'), 'field' => 'kgrdl.gradelevel'),
    'status' => array('data' => t('Status'), 'field' => 'ksts.status'),
    'operations' => array('data' => t('Ops')),
  );

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
//  $query->addField('kstu', 'friendlyname');
  $query->addField('kpgm', 'program');
  $query->addField('kgrdl', 'gradelevel');
  $query->addField('ksts', 'status');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  // adjust the query according to the filter values
  if (($field <> 'username') && (!empty($field)))  {
    $thename_key = kleosis_get_enrollment_filter_key($field, $thename);
    if (($oper == 'like') && (!empty($thename_key)) ){
        $query->condition('kstu.' . $field, $thename_key . '%', 'like');
    }
    else{
       $query->condition('kstu.' . $field, $thename_key, '=');
    }
  }

  if (($field == 'username') && (!empty($thename)) )  {
    if ($oper == 'is') {
       $query->condition('u.' . 'name', $thename, '=');
    }
    else{
        $query->condition('u.' . 'name', $thename . '%', 'like');
    }
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
    $options[$student->drp_uid_fk] = array(
      'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->drp_uid_fk, 'ksop' => $student->name))),
//      'drp_uid_fk' =>  $student->drp_uid_fk,
      'identity_id' => $student->identity_id,
      'fullname' => $student->fullname,
      'program' => $student->program,
      'gradelevel' => $student->gradelevel,
      'status' =>  $student->status,
      'operations' =>  l(t('Enrolled classes'), 'kleosis/students/classes/enrolled_classes', array('query' => array('ksopid' => $student->drp_uid_fk, 'ksop' => $student->name)))
//      'operations' => l(t('edit'), 'user/' . $student->drp_uid_fk . '/edit', array('query' => array('destination' => 'kleosis/students/list')))
//      'operations' => l(t('edit'), 'kleosis/std/summary/' . $student->drp_uid_fk, array('query' => array('destination' => 'kleosis/students/list')))
//      'operations' =>  l(t('Summary'), 'kleosis/students/summary', array('query' => array('ksopid' => $student->drp_uid_fk, 'ksop' => $student->name)))

    );
  }

  $form['students'] = array(
//        '#type' => 'table',       // used for table
        '#type' => 'tableselect',   // used for tableselect
//        '#theme' => 'table',      // used only for table
        '#header' => $header,
        '#options' => $options,   // used for tableselect
//        '#rows' => $options,   // used for table
        '#empty' => t('No students are defined for the selected filter values.'),
        '#multiple' => TRUE,
        '#js_select' => TRUE,
      );
  $form['pager'] = array('#markup' => theme('pager'));

  $form['searchuser']['enroll'] = array(
    '#type' => 'submit',
    '#value' => t('Enroll Selected Students'),
    '#weight' => 20,
    '#disabled' => !$allow_enrollments,
    '#prefix' => '<div style="float: left;clear:left; width:225px" >',
    '#suffix' => '</div>',
  );

  $form['searchuser']['unenroll'] = array(
    '#type' => 'submit',
    '#value' => t('Unenroll Selected Students'),
    '#weight' => 25,
    '#disabled' => !$allow_enrollments,
    '#prefix' => '<div style="float: left; width:225px" >',
    '#suffix' => '</div>',
  );
return $form;

}
/**
 *
 * function to return the program or gradelevel key from the filter name
 */
function kleosis_get_enrollment_filter_key($field, $thename) {

  if ($field == 'curr_main_program') {

  $thekey = db_query('SELECT kpgm_id FROM {ks_program_desc} WHERE program like :program',
                   array(':program' => $thename . '%'))->fetchField();
  }
  elseif ($field == 'curr_gradelevel') {

  $thekey = db_query('SELECT kgrdl_id FROM {ks_gradelevel_desc} WHERE gradelevel = :gradelevel',
                   array(':gradelevel' => $thename))->fetchField();
  }
  else {
    $thekey = '';
  }
  return $thekey;
}

/**
 *
 * Implementation of hook_submit() for the Students List form.
 *  - not used yet - sample code iterates thru the checked students...
 *
 */
/*
function kleosis_enrollments_students_list_submit($form, &$form_state) {

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
*/
/**
 *
 * Implementation of hook_submit() for the Students List form.
 *   - main purpose is to store the selected student, operation, and user into session variables
 *
 */
function kleosis_students_enrollments_filter_form_submit($form, &$form_state) {

//dpm('inside kleosis_students_enrollments_filter_form_submit()');
//dpm($form_state);

  switch ($form_state['values']['op']) {

    case 'Clear':
        $_SESSION['kleosis_enrollments_filter'] = array();
      break;

    case 'Apply':
        $_SESSION['kleosis_enrollments_filter'] = array('field' => $form_state['values']['field'],
                                        'oper' => $form_state['values']['oper'],
                                        'thename' => $form_state['values']['thename'],
                                        );
      break;

    case 'Set year and term':
      $_SESSION['ks_enrollments_class_filter'] = array('class' => $form_state['values']['class'],
                                        'class_name' => isset($form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']]) ? $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] : '',
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                        );
      break;

    case 'Enroll Selected Students':
      $_SESSION['ks_enrollments_class_filter'] = array('class' => $form_state['values']['class'],
                                        'class_name' => isset($form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']]) ? $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] : '',
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                        );
//      kleosis_enroll_students_from_list($form, &$form_state);
      kleosis_enroll_students_from_list($form, $form_state);
      break;

    case 'Unenroll Selected Students':
      $_SESSION['ks_enrollments_class_filter'] = array('class' => $form_state['values']['class'],
                                        'class_name' => isset($form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']]) ? $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] : '',
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                        );
//      kleosis_unenroll_students_from_list($form, &$form_state);
      kleosis_unenroll_students_from_list($form, $form_state);
      break;
  }
}
/*
  * Function to iterate through the selected students and enroll them in a class
  *
*/
function kleosis_enroll_students_from_list($form, &$form_state) {

//  drupal_set_message('Enroll clicked, and now in function kleosis_enroll_students_from_list()');
      $enrd = new DateTime('now');

  foreach($form_state['values']['students'] as $key => $value) {

    if (!empty($value)) {

      $enroll_record = array();
      $enroll_record['drp_uid'] = $value;
      $enroll_record['class_nid'] = $form_state['values']['class'];
      $enroll_record['ib_level'] = $form_state['values']['ib_level'];
      $enroll_record['class_auth'] = 1;
      $enroll_record['enrol_status'] = 1;
      $enroll_record['enrol_date']['year'] = $enrd->format('Y');
      $enroll_record['enrol_date']['month'] = $enrd->format('n');
      $enroll_record['enrol_date']['day'] = $enrd->format('j');
      $enroll_record['unenrol_date']['year'] = '1900';
      $enroll_record['unenrol_date']['month'] = '01';
      $enroll_record['unenrol_date']['day'] = '01';
      $enroll_record['completed'] = 0;
      $enroll_record['final_grade'] = 0;
      $enroll_record['final_attendance'] = '';
      $enroll_record['final_other'] = '';
      $enroll_record['remarks'] = 'Sample Test enroll into class ' . $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']];

      $there_already = ks_get_enroll_records($value, TRUE, $form_state['values']['class']);
      $there_but_unenrolled = ks_get_enroll_records($value, FALSE, $form_state['values']['class']);

      if  ( (empty($there_already)) &&  (empty($there_but_unenrolled)) ){
        $newrec_id = ks_insert_enroll_record($enroll_record);
        drupal_set_message('Student: ' . $value . ' was enrolled into class: ' . $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] . ' (class id:) ' .  $form_state['values']['class'] . ')');
      }
      else {
        $enroll_record['ksccl_id'] = $there_but_unenrolled['ksccl_id'];
        $ok = ks_update_enroll_record($enroll_record);
        drupal_set_message('Student: ' . $value . ' has been re-enrolled in class: ' . $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] . ' (class id:) ' .  $form_state['values']['class'] . ')');
      }
    }
    else {
     // drupal_set_message('Student: ' . $key . ' has value: ' .  $value . ' NOT selected');
    }
  }
}

/*
  * Function to iterate through the selected students and unenroll them from a class
  *
*/
function kleosis_unenroll_students_from_list($form, &$form_state) {

//  drupal_set_message('Unenroll clicked, and now in function kleosis_unenroll_students_from_list()');

  foreach($form_state['values']['students'] as $key => $value) {

    if (!empty($value)) {

//      drupal_set_message('Student: ' . $key . ' has value: ' .  $value . ' and will be unenrolled from class: ' . $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] . ' (class id:) ' .  $form_state['values']['class'] . ')');

      $result = ks_get_enroll_records($key, TRUE, $form_state['values']['class']);
      if(!empty($result)) {
        $enrd = (!empty($result['enrol_date'])) ? new DateTime($result['enrol_date']) : new DateTime('1900-01-01 0:0:00');
        $uenrd = new DateTime('now');

        $enroll_record = array();
        $enroll_record['ksccl_id'] = $result['ksccl_id'];
        $enroll_record['drp_uid'] = $result['kstu_id_fk'];
        $enroll_record['class_nid'] = $result['kccls_id_fk'];
        $enroll_record['ib_level'] = $result['ib_level'];
        $enroll_record['class_auth'] = $result['class_auth'];
        $enroll_record['enrol_status'] = $result['enrol_status'];
        $enroll_record['enrol_date']['year'] = $enrd->format('Y');
        $enroll_record['enrol_date']['month'] = $enrd->format('n');
        $enroll_record['enrol_date']['day'] = $enrd->format('j');
        $enroll_record['unenrol_date']['year'] = $uenrd->format('Y');
        $enroll_record['unenrol_date']['month'] = $uenrd->format('n');
        $enroll_record['unenrol_date']['day'] = $uenrd->format('j');
        $enroll_record['completed'] = $result['completed'];
        $enroll_record['final_grade'] = $result['final_grade'];
        $enroll_record['final_attendance'] = $result['final_attendance'];
        $enroll_record['final_other'] = $result['final_other'];
        $enroll_record['remarks'] = $result['remarks'];

        $ok = ks_update_enroll_record($enroll_record);

        // can do something more drastic like:
        // $ok = ks_delete_enroll_record($result['ksccl_id']);
        if ($ok) {
          drupal_set_message('Student: ' . $value . ' was unenrolled from class: ' . $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] . ' (class id:) ' .  $form_state['values']['class'] . ')');
        }
        else {
          drupal_set_message('Student: ' . $value . ' was not unenrolled from class: ' . $form['enroll_actions']['enroll_actions']['class']['#options'][$form_state['values']['class']] . ' (class id:) ' .  $form_state['values']['class'] . ')');
        }
      }
    }
    else {
//      drupal_set_message('Student: ' . $key . ' has value: ' .  $value . ' NOT selected');
    }
  }  // end foreach
}

/*
* Implement the confirm form - todo:  get this working...
*
*/
function kleosis_enroll_users_confirm_form($form, &$form_state) {

  drupal_set_message('kleosis_enroll_users_confirm_form() called.');
  $caption = '<p>' . t('This is an additional note.') . '</p>';
  $heading = t('Are you sure you want to enroll these users into course --- ?');
  $cancel_path = 'kleosis/enrollment';
  $yes = t('Enroll Students');
  $no = t('Cancel');
  return confirm_form($form, $heading, $cancel_path, $caption, $yes, $no);
}

// Implement the confirm form submit
function kleosis_enroll_users_confirm_form_submit($form, &$form_state) {

  drupal_set_message('kleosis_enroll_users_confirm_form_submit() called.');

}
