<?php
// $Id$

/**
 * @file
 *  kleosis Class Schedule edit form
 *  Provides the edit form for a Class schedule
 */

function kleosis_class_schedule_edit_form($form, &$form_state) {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('administer kleosis classes')) ) {
    drupal_set_message(t("You currently do not have permissions to edit class schedules."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Classes'), 'kleosis/classes');
  $breadcrumb[] = l(t('Class Schedule'), 'kleosis/classes/schedule');
  $breadcrumb[] = t('Edit Schedule');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title('Edit Class Schedule');

  $classid = isset($_SESSION['kleosis_class_selected_class']['classid']) ? $_SESSION['kleosis_class_selected_class']['classid'] : 0;
  $classname = isset($_SESSION['kleosis_class_selected_class']['classname']) ? $_SESSION['kleosis_class_selected_class']['classname'] : '';

  if ($classid == 0) {
    drupal_set_message('Please select a class from the Classes List page');
    drupal_goto('kleosis/classes', array());
  }

  $ks_libpath = drupal_get_path('module', 'kleosis');
  $kslib = $ks_libpath . '/includes/kleosis_lib.inc';
  require_once ($kslib);

  $defaults = TRUE;
  //$uid = $_SESSION['student']['id'];
  //$username = $_SESSION['student']['name'];

  $query = db_select('ks_class_schedule', 'ksclss');
  $query->innerJoin('node', 'n', 'n.nid = ksclss.kccls_id_fk');
  $query->innerJoin('ks_class_schedule_status_desc', 'ksclsss', 'ksclss.period_status = ksclsss.kclsss_id');
  $query->addField('n', 'title');
  $query->addField('ksclss', 'kclss_id');
  $query->addField('ksclss', 'kccls_id_fk');
  $query->addField('ksclss', 'period_start_datetime');
  $query->addField('ksclss', 'period_end_datetime');
  $query->addField('ksclss', 'period_day');
  $query->addField('ksclss', 'period_hour');
  $query->addField('ksclss', 'period_length');
  $query->addField('ksclss', 'period_status');
  $query->addField('ksclss', 'classroom');
  $query->addField('ksclss', 'period_lead');

  $query->condition('ksclss.' . 'kccls_id_fk', $classid, '=');
  $query->orderBy('ksclss.period_day', 'ASC');
//  $query->orderBy('ksclss.period_start_datetime', 'ASC');

  $period_record = $query->execute()->fetchAll();

//  dpm($period_record);
//  dpm($classid);
//  dpm($classname);

  if(empty($period_record)) {
    $form['no_schedule'] = array(
        '#markup' => t('There is no schedule defined for class: @class', array('@class' => $classname)),
        '#weight' => -10,
        '#prefix' => '<div style="float: left;clear: left;width:640px" ><br/><strong><p>',
        '#suffix' => '</strong></p><br/></div>',
      );
    return $form;
  }
  else {
    $form['weekly_schedule'] = array(
        '#markup' => t('Weekly schedule for class: @class', array('@class' => $classname)),
        '#weight' => -10,
        '#prefix' => '<div style="float: left;clear: left;width:640px" ><br/><strong><p>',
        '#suffix' => '</strong></p></div>',
      );
  }
/*
  $form['class_schedule_entry_record'] = array(  // fieldset for schedule
      '#type' => 'fieldset',
      '#title' => t('Class Periods'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -5,
    );
*/
  $i = 1;
  foreach ($period_record as $period) {

//    dpm($period);
    $pstartd = !empty($period->period_start_datetime) ? new DateTime($period->period_start_datetime) : new DateTime('1900-01-02 03:04:05');
    $pendd = !empty($period->period_end_datetime) ? new DateTime($period->period_end_datetime) : new DateTime('1900-01-02 03:04:05');

    $form['class_schedule_entry_record']['kclss_id_' . $i] = array(
      '#type' => 'hidden',
      '#title' => t('(id)'),
      '#size' => 20,
      '#maxlength' => 30,
      '#disabled' => TRUE,
      '#default_value' => $period->kclss_id,
      '#prefix' => '<div style="float: left;clear: left;width:240px" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['kccls_id_fk_' . $i] = array(
      '#type' => 'hidden',
      '#title' => t('(classid)'),
      '#default_value' => $period->kccls_id_fk,
      '#prefix' => '<div style="float: left;clear: left;width:60px" >',
      '#suffix' => '</div>',
    );
/*    $form['class_schedule_entry_record']['period_start_datetime_' . $i] = array(
      '#type' => 'date',
//      '#title' => t('Period'),
      '#default_value' => array(
         'month' => $pstartd->format('n'),
         'day' => $pstartd->format('j'),
         'year' => $pstartd->format('Y'),
        ),
      '#prefix' => '<div style="float: left;width:200px" >',
      '#suffix' => '</div>',
    );
*/
    $form['class_schedule_entry_record']['period_day_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Day'),
      '#options' =>  kleosis_dayofweek_values(),
      '#default_value' => $period->period_day,
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['from_' . $i] = array(
      '#markup' => t('from'),
      '#prefix' => '<div style="float: left;width:50px" >&nbsp;&nbsp;<strong><em>',
      '#suffix' => '</em></strong>&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['period_start_hour_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Hour'),
      '#options' =>  kleosis_hours_values(),
      '#default_value' => $pstartd->format('H'),
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_start_minute_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Min'),
      '#options' =>  kleosis_minutes_values(),
      '#default_value' => $pstartd->format('i'),
      '#prefix' => '<div style="float: left;width:100" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['to_' . $i] = array(
      '#markup' => t('to'),
      '#prefix' => '<div style="float: left;width:30px" >&nbsp;&nbsp;<strong><em>',
      '#suffix' => '</em></strong>&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['period_end_hour_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Hour'),
      '#options' =>  kleosis_hours_values(),
      '#default_value' => $pendd->format('H'),
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_end_minute_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Min'),
      '#options' =>  kleosis_minutes_values(),
      '#default_value' => $pendd->format('i'),
      '#prefix' => '<div style="float: left;width:120" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['classroom_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Classroom'),
      '#options' =>  ks_get_classrooms(),
      '#default_value' => $period->classroom,
      '#disabled' => FALSE,
      '#prefix' => '<div style="float: left;width:200px" >',
      '#suffix' => '</div>',
    );
/*
    $form['class_schedule_entry_record']['period_status_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Status'),
      '#options' =>  ks_schedule_period_status_values(),
      '#default_value' => $period->period_status,
      '#prefix' => '<div style="float: left;width:110" >',
      '#suffix' => '</div>',
    );
*/
    $form['class_schedule_entry_record']['period_lead_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Lead Instructor'),
      '#options' =>  array(0 => t('no instructor')) + get_instructor_names(),
      '#default_value' => $period->period_lead,
      '#prefix' => '<div style="float: left;width:110" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['delete_' . $i] = array(
      '#markup' => l(t('delete'), 'kleosis/classes/schedule/delete', array('query' => array('ksopid' => $period->kclss_id, 'ksop' => 'delete', 'destination' => 'kleosis/classes/schedule/edit' ))),
      '#prefix' => '<div style="float: left;width:60px" >&nbsp;&nbsp;',
      '#suffix' => '&nbsp;&nbsp;</div>',
    );

    $i += 1;

    } // end foreach()

    $form['class_schedule_entry_record']['num_periods'] = array(
      '#type' => 'hidden',
      '#value' => $i - 1,
    );

    $form['class_schedule_entry_record']['spacer'] = array(
      '#markup' =>    '&nbsp;',
      '#prefix' => '<div style="float: left;clear: left;width:1px">',
      '#suffix' => '</div>',
    );

    $form['class_schedule_entry_record']['update'] = array(
      '#type' => 'submit',
      '#value' => t('Update'),
      '#weight' => 20,
      '#prefix' => '<div style="float: left;clear:left; width:125px" >',
      '#suffix' => '</div>',
    );

    $form['class_schedule_entry_record']['cancel'] = array(
      '#type' => 'submit',
      '#value' => t('Cancel'),
      '#weight' => 25,
      '#prefix' => '<div style="float: left; width:125px" >',
      '#suffix' => '</div>',
    );
//dpm($form);
//dpm($form_state);

  return $form;
}

/*
* Validate function for the kleosis_class_schedule_edit_form
*/

  function kleosis_class_schedule_edit_form_validate($form, &$form_state) {

//    dpm('inside kleosis_class_schedule_edit_form_validate');
//   dpm($form);
//   dpm($form_state);
//    form_set_error('validate_category','this is a test error message from the validate function ' .
//      ' - will cause a return to edit form with no call to the submit function');
/*
  $formdup = $form;
  $formstatedup = $form_state;

  $period0 = $form['class_schedule_entry_record']['0'];
  $period1 = $form['class_schedule_entry_record']['1'];
  $period2 = $form['class_schedule_entry_record']['2'];
  $period3 = $form['class_schedule_entry_record']['3'];
*/

}

/*
* Submit function for the kleosis_class_schedule_edit_form
*/
function kleosis_class_schedule_edit_form_submit($form, &$form_state) {


//  $formd_temp = $form;
//  $formstate_temp = $form_state;
//  dpm('inside kleosis_class_schedule_edit_form_submit');
//  dpm($form_state['values']);
//  dpm($form_state['input']['op']);

  $num_recs = $form_state['values']['num_periods'] ;
  if ($form_state['input']['op'] == 'Cancel') {
    $form_state['redirect'] = 'kleosis/classes/schedule';
  }
  elseif($num_recs == 0) {
    $form_state['redirect'] = 'kleosis/classes/schedule';
  }
  else {

    $theclass = node_load($form_state['values']['kccls_id_fk_1']);  // get the class start date from the class
    $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
    $class_start_date = new DateTime($start_date);  // create a datetime object for new period

    for($i=1; $i<=$num_recs; $i++) {

      $schedule_record = array();
      $schedule_record['kclss_id'] = $form_state['values']['kclss_id_' . $i];
      $schedule_record['kccls_id_fk'] = $form_state['values']['kccls_id_fk_' . $i];
      $schedule_record['period_start_datetime']['year'] = $class_start_date->format('Y');
      $schedule_record['period_start_datetime']['month'] = $class_start_date->format('n');
      $schedule_record['period_start_datetime']['day'] = $class_start_date->format('j');
      $schedule_record['period_day'] = $form_state['values']['period_day_' . $i];
      $schedule_record['period_start_hour'] = $form_state['values']['period_start_hour_' . $i];
      $schedule_record['period_start_minute'] = $form_state['values']['period_start_minute_' . $i];
      $schedule_record['period_end_hour'] = $form_state['values']['period_end_hour_' . $i];
      $schedule_record['period_end_minute'] = $form_state['values']['period_end_minute_' . $i];
      $schedule_record['classroom'] = $form_state['values']['classroom_' . $i];
//      $schedule_record['period_status'] = $form_state['values']['period_status_' . $i];
      $schedule_record['period_status'] = 1;  // for Kleosis Lite
      $schedule_record['period_lead'] = $form_state['values']['period_lead_' . $i];

      $ok = ks_update_schedule_record($schedule_record);
//    dpm($schedule_record);
    }
    $form_state['redirect'] = 'kleosis/classes/schedule/edit';
  }
}

/**
 * Menu callback; get confirm form for deleting schedule periods
 */
function kleosis_class_schedule_delete_page() {
  return drupal_get_form('kleosis_class_schedule_delete_confirm');
}


/**
 * Build a confirm form for deletion of schedule periods
 */
function kleosis_class_schedule_delete_confirm($form, &$form_state) {
  $caption = '<p>' . t('This action cannot be undone.') . '</p>';
  $heading = t('Are you sure you want to delete the selected schedule period?');
  $cancel_path = 'kleosis/classes/schedule/edit';
  $yes = t('Delete period');
  $no = t('Cancel');
  return confirm_form($form, $heading, $cancel_path, $caption, $yes, $no);
}


/**
 * Submit function for the confirm deletion form.
 */
function kleosis_class_schedule_delete_confirm_submit($form, &$form_state) {
  $kclss_id = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : 0;
  $ksop = isset( $_GET['ksop'] ) ? $_GET['ksop'] : '';

  $res = ks_delete_schedule_record($kclss_id);

  if ($res) {
    drupal_set_message('The period was successfully deleted.');
  }
  else {
    drupal_set_message('The period was not deleted.');
  }
}
