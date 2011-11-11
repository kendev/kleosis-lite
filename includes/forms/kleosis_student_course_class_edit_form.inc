<?php
// $Id$

/**
 * @file
 *  kleosis Student Course-Class edit form
 *  Provides the edit form for a record in the student course class list table
 */

function kleosis_student_course_class_edit_form($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = l(t('Student Classes'), 'kleosis/students/classes');
  $breadcrumb[] = t('Enrollment Edit');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title('Student class enrollment entry edit');

/*
  $form['edit_return'] = array(
   '#type' => 'markup',
   '#markup' => '<p><br/>' . t('This is the kleosis_student_course_class_edit_form - tbd') . '</p>',
      );
*/
  $erid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : 0;

 if ($erid == 0) {
//    drupal_set_message('Please select a class from the Students Classes page');
//    drupal_goto('kleosis/students/classes', array());
  }

  $defaults = TRUE;  // will allow the form fields to show the user data

  $uid = $_SESSION['student']['id'];
  $username = $_SESSION['student']['name'];

  $query = db_select('ks_student_course_classes', 'ksscc');
  $query->innerJoin('users', 'u', 'u.uid = ksscc.kstu_id_fk');
  $query->addField('ksscc', 'ksccl_id');
  $query->addField('ksscc', 'kstu_id_fk');
  $query->addField('ksscc', 'kccls_id_fk');
  $query->addField('ksscc', 'class_auth');
  $query->addField('ksscc', 'enrol_date');
  $query->addField('ksscc', 'unenrol_date');
  $query->addField('ksscc', 'completed');
  $query->addField('ksscc', 'final_grade');
  $query->addField('ksscc', 'final_attendance');
  $query->addField('ksscc', 'final_other');
  $query->addField('ksscc', 'remarks');

  $query->condition('ksscc.' . 'ksccl_id', $erid, '=');
  $query->condition('ksscc.' . 'kstu_id_fk', $uid, '=');
//  $query->isNull('unenrol_date');

//todo: determine academic year and term and filter accordingly....

  $cerecord = $query->execute()->fetch(PDO::FETCH_ASSOC);

  $enrd = (!empty($cerecord['enrol_date'])) ? new DateTime($cerecord['enrol_date']) : new DateTime('1900-01-01 0:0:00');
//  $uenrd = (!empty($cerecord['unenrol_date'])) ? new DateTime($cerecord['unenrol_date']) : new DateTime('now');
  $uenrd = (!empty($cerecord['unenrol_date'])) ? new DateTime($cerecord['unenrol_date']) : new DateTime('1900-01-01 0:0:00');

  $node = node_load($cerecord['kccls_id_fk']);
  $form['class_entry_record'] = array(  // fieldset for biodata
      '#type' => 'fieldset',
      '#title' => t('Class Enrollment Record'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -5,
    );

  $form['class_entry_record']['ksccl_id'] = array(
//    '#type' => 'hidden',
    '#type' => 'textfield',
    '#title' => t('(id)'),
    '#size' => 20,
    '#maxlength' => 30,
    '#disabled' => TRUE,
    '#default_value' => ($defaults)? $cerecord['ksccl_id'] : '',
    '#prefix' => '<div style="float: left;clear: left;width:240px" >',
    '#suffix' => '</div>',
  );
  $form['class_entry_record']['kstu_id_fk'] = array(
    '#type' => 'select',
    '#title' => t('Student'),
    '#options' =>  array($uid => $username),
    '#default_value' => $uid,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;width:240px" >',
    '#suffix' => '</div>',
  );
  $form['class_entry_record']['classname'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#size' => 55,
    '#maxlength' => 75,
    '#disabled' => TRUE,
    '#default_value' => $node->title,
    '#prefix' => '<div style="float: left;width:320px" >',
    '#suffix' => '</div>',
  );
  $form['class_entry_record']['kccls_id_fk'] = array(
    '#type' => 'hidden',
    '#size' => 45,
    '#maxlength' => 64,
    '#disabled' => TRUE,
    '#default_value' => ($defaults)? $cerecord['kccls_id_fk'] : '',
    '#prefix' => '<div style="float: left;width:320px" >',
    '#suffix' => '</div>',
  );
  $form['class_entry_record']['class_auth'] = array(
    '#type' => 'textfield',
    '#title' => t('Class Authorization'),
    '#size' => 20,
    '#maxlength' => 30,
    '#default_value' => ($defaults)? $cerecord['class_auth'] : '',
    '#prefix' => '<div style="float: left;clear: left;width:240px" >',
    '#suffix' => '</div><br/>',
  );
  $form['class_entry_record']['enrol_date'] = array(
    '#type' => 'date',
    '#title' => t('Enrol Date'),
    '#default_value' => array(
       'month' => $enrd->format('n'),
       'day' => $enrd->format('j'),
       'year' => $enrd->format('Y'),
      ),
    '#prefix' => '<div style="float: left;width:240px" >',
    '#suffix' => '</div><br/>',
  );
  $form['class_entry_record']['unenrol_date'] = array(
    '#type' => 'date',
    '#title' => t('Unenrol Date'),
    '#default_value' => array(
       'month' => $uenrd->format('n'),
       'day' => $uenrd->format('j'),
       'year' => $uenrd->format('Y'),
      ),
    '#prefix' => '<div style="float: left;width:240px" >',
    '#suffix' => '</div><br/>',
  );
  $form['class_entry_record']['completed'] = array(
    '#type' => 'select',
    '#title' => t('Completed'),
    '#options' =>  array('0' => 'No', '1' => 'Yes',),
    '#default_value' => ($defaults)? $cerecord['completed'] : '',
    '#prefix' => '<div style="float:left;clear: left;width:240px" >',
    '#suffix' => '</div><br/>',
  );
/*
  $form['class_entry_record']['final_grade'] = array(
    '#type' => 'textfield',
    '#title' => t('Grade'),
    '#size' => 30,
    '#maxlength' => 40,
    '#default_value' => ($defaults)? $cerecord['final_grade'] : '',
    '#prefix' => '<div style="float: left;width:240px" >',
    '#suffix' => '</div><br/>',
  );

  $form['class_entry_record']['final_attendance'] = array(
    '#type' => 'textfield',
    '#title' => t('Attendance'),
    '#size' => 20,
    '#maxlength' => 24,
    '#default_value' => ($defaults)? $cerecord['final_attendance'] : '',
    '#prefix' => '<div style="float: left;width:240px" >',
    '#suffix' => '</div>',
  );
*/
  $form['class_entry_record']['final_other'] = array(
    '#type' => 'textfield',
    '#title' => t('Other'),
    '#size' => 26,
    '#maxlength' => 26,
    '#default_value' => ($defaults)? $cerecord['final_other']: '',
    '#prefix' => '<div style="float: left;width:240px" >',
    '#suffix' => '</div>',
  );
  $form['class_entry_record']['remarks'] = array(
    '#type' => 'textarea',
    '#title' => t('Remarks'),
    '#cols' => 120,
    '#rows' => 3,
    '#default_value' => ($defaults)? $cerecord['remarks'] : '',
    '#resizeable' => TRUE,
    '#prefix' => '<div style="float: left;clear:left;width:480px" >',
    '#suffix' => '</div>',
  );
  $form['class_entry_record']['update'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#weight' => 20,
    '#prefix' => '<div style="float: left;clear:left; width:125px" >',
    '#suffix' => '</div>',
  );

  $form['class_entry_record']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#weight' => 25,
    '#prefix' => '<div style="float: left; width:125px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/*
* Validate function for the kleosis_student_course_class_edit_form
*/

  function kleosis_student_course_class_edit_form_validate($form, &$form_state) {

  if ($form_state['values']['op'] == 'Cancel') {
    return;
  }
  if( empty($form_state['input']['class_auth']) ) {
      form_set_error('class_auth', t('Course Authorization must be an integer number.'), $limit_validation_errors = NULL);
    }
  if( !is_numeric($form_state['input']['class_auth']) ) {
      form_set_error('class_auth', t('Course Authorization must be an integer number.'), $limit_validation_errors = NULL);
    }
}

/*
* Submit function for the kleosis_student_course_class_edit_form
*/
function kleosis_student_course_class_edit_form_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Cancel':
      break;

    case 'Update':

      $uenrd = new DateTime('now');

      $enroll_record = array();
      $enroll_record['ksccl_id'] = $form_state['values']['ksccl_id'];
      $enroll_record['drp_uid'] = $form_state['values']['kstu_id_fk'];
      $enroll_record['class_nid'] = $form_state['values']['kccls_id_fk'];
      $enroll_record['class_auth'] = $form_state['input']['class_auth'];
      $enroll_record['enrol_date']['year'] = $form_state['input']['enrol_date']['year'];
      $enroll_record['enrol_date']['month'] = $form_state['input']['enrol_date']['month'];
      $enroll_record['enrol_date']['day'] = $form_state['input']['enrol_date']['day'];
      $enroll_record['unenrol_date']['year'] = $form_state['input']['unenrol_date']['year'];
      $enroll_record['unenrol_date']['month'] = $form_state['input']['unenrol_date']['month'];
      $enroll_record['unenrol_date']['day'] = $form_state['input']['unenrol_date']['day'];
      $enroll_record['completed'] = $form_state['input']['completed'];
  //    $enroll_record['final_grade'] = $form_state['input']['final_grade'];
      $enroll_record['final_grade'] = 0.0;
  //    $enroll_record['final_attendance'] = $form_state['input']['final_attendance'];
      $enroll_record['final_attendance'] = 0.0;
      $enroll_record['final_other'] = $form_state['input']['final_other'];
      $enroll_record['remarks'] = $form_state['input']['remarks'];

      $ok = ks_update_enroll_record($enroll_record);

      break;
    }
      $form_state['redirect'] = 'kleosis/students/classes';

}