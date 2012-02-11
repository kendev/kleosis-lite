<?php
// $Id$

/**
 * @file
 *  kleosis Class Schedule create form
 *  Provides the create form for a Class schedule
 */

function kleosis_class_schedule_create_form($form, &$form_state) {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('administer kleosis classes')) ) {
    drupal_set_message(t("You currently do not have permissions to create class schedules."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Classes'), 'kleosis/classes');
  $breadcrumb[] = l(t('Class Schedule'), 'kleosis/classes/schedule');
  $breadcrumb[] = t('Add to Schedule');

  drupal_set_breadcrumb($breadcrumb);
  drupal_set_title(t('Add Class Schedule'));

  $classid = isset($_SESSION['kleosis_class_selected_class']['classid']) ? $_SESSION['kleosis_class_selected_class']['classid'] : 0;
  $classname = isset($_SESSION['kleosis_class_selected_class']['classname']) ? $_SESSION['kleosis_class_selected_class']['classname'] : '';

  if ($classid == 0) {
    drupal_set_message(t('Please select a class from the Classes List page'));
    drupal_goto('kleosis/classes', array());
  }

  $ks_libpath = drupal_get_path('module', 'kleosis');
  $kslib = $ks_libpath . '/includes/kleosis_lib.inc';
  require_once($kslib);

  $defaults = TRUE;
  //$uid = $_SESSION['student']['id'];
  //$username = $_SESSION['student']['name'];

  $query = db_select('ks_class_schedule', 'ksclss');
  $query->innerJoin('node', 'n', 'n.nid = ksclss.kccls_id_fk');
  $query->innerJoin('ks_class_schedule_status_desc', 'ksclsss', 'ksclss.period_status = ksclsss.kclsss_id');
  $query->addField('n', 'title');
  $query->addField('ksclss', 'kclss_id');
  $query->addField('ksclss', 'kccls_id_fk');
  $query->addField('ksclss', 'period_start_datetime');  // M-D-Y part is the class start date (not currently used)
  $query->addField('ksclss', 'period_end_datetime');    // M-D-Y part is the class start date (not currently used)
  $query->addField('ksclss', 'period_day');             // Day of the week (ISO-8601)
  $query->addField('ksclss', 'period_hour');            // not currently used
  $query->addField('ksclss', 'period_length');          // not currently used
  $query->addField('ksclss', 'period_status');
  $query->addField('ksclss', 'classroom');
  $query->addField('ksclss', 'period_lead');
  $query->addField('ksclss', 'period_sub');

  $query->condition('ksclss.' . 'kccls_id_fk', $classid, '=');
  $query->orderBy('ksclss.period_day', 'ASC');
//  $query->orderBy('ksclss.period_start_datetime', 'ASC');

  $period_record = $query->execute()->fetchAll();

//  dpm($period_record);
//  dpm($classid);
//  dpm($classname);

  $form['classname'] = array(
      '#markup' => t('Weekly schedule for class: @class', array('@class' => $classname)),
      '#weight' => -10,
      '#prefix' => '<div style="float: left;clear: left;width:640px" ><br/><strong><p>',
      '#suffix' => '</strong></p></div>',
    );
/*
  $form['class_schedule_entry_record'] = array(  // fieldset for schedule
      '#type' => 'fieldset',
      '#title' => t('Class Periods'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -5,
    );
*/

  // provide a header row for the period schedule columns

  $form['class_schedule_entry_record']['day_of_week'] = array(
    '#markup' =>    'Day',
    '#prefix' => '<div style="float: left;clear: left;width:190px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['period duration'] = array(
    '#markup' =>    'Period Duration',
    '#prefix' => '<div style="float: left;width:170px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['Room'] = array(
    '#markup' =>    'Room',
    '#prefix' => '<div style="float: left;width:150px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['instructor_lead'] = array(
    '#markup' =>    'Instructor',
    '#prefix' => '<div style="float: left;width:140px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['instructor_sub'] = array(
    '#markup' =>    'Sub',
    '#prefix' => '<div style="float: left;width:80px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['spacer2'] = array(
    '#markup' =>    '&nbsp;',
    '#prefix' => '<div style="float: left;clear: left;width:60px"><strong>',
    '#suffix' => '</strong></div>',
  );

  $i = 1;
  foreach ($period_record as $period) {

//  dpm($period);
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
      '#disabled' => TRUE,
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
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_start_minute_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Min'),
      '#options' =>  kleosis_minutes_values(),
      '#default_value' => $pstartd->format('i'),
      '#disabled' => TRUE,
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
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_end_minute_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Min'),
      '#options' =>  kleosis_minutes_values(),
      '#default_value' => $pendd->format('i'),
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:120" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['classroom_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Classroom'),
      '#options' =>  ks_get_classrooms(),
      '#default_value' => $period->classroom,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:150px" >',
      '#suffix' => '</div>',
    );
/*
    $form['class_schedule_entry_record']['period_status_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Status'),
      '#options' =>  ks_schedule_period_status_values(),
      '#default_value' => $period->period_status,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:110" >',
      '#suffix' => '</div><br/>',
    );
*/
    $form['class_schedule_entry_record']['period_lead_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Lead instructor'),
      '#options' =>  array(0 => t('no instructor')) + ks_get_instructor_names(),
      '#default_value' => $period->period_lead,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:140px" >',
      '#suffix' => '</div><br/>',
    );
    $form['class_schedule_entry_record']['period_sub_' . $i] = array(
      '#type' => 'select',
//      '#title' => t('Sub instructor'),
      '#options' =>  array(0 => t('no sub')) + ks_get_instructor_names(),
      '#default_value' => $period->period_sub,
      '#disabled' => TRUE,
      '#prefix' => '<div style="float: left;width:140px" >',
      '#suffix' => '</div>',
    );

    $i += 1;

    } // end foreach()


// Now, display a blank period

    $pstartd = new DateTime('now');
    $pendd = new DateTime('now');
    $inew = 'new';

    $form['class_schedule_entry_record']['hr_' . $inew] = array(
      '#markup' => '-------------------------------------------------',
      '#prefix' => '<br/><div style="float: left;clear: left;">',
      '#suffix' => '</div><br/>',
    );

    $form['class_schedule_entry_record']['kclss_id_' . $inew] = array(
      '#type' => 'hidden',
      '#title' => t('(id)'),
      '#size' => 20,
      '#maxlength' => 30,
      '#disabled' => TRUE,
      '#default_value' => 0,
      '#prefix' => '<div style="float: left;clear: left;width:240px" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['kccls_id_fk_' . $inew] = array(
      '#type' => 'hidden',
      '#title' => t('(classid)'),
      '#default_value' => $classid,
      '#prefix' => '<div style="float: left;clear: left;width:60px" >',
      '#suffix' => '</div>',
    );

  $form['class_schedule_entry_record']['period_' . $inew] = array(
      '#markup' => t('New period') . ': ',
      '#prefix' => '<div style="float: left;clear: left;width:260px" ><strong><em>',
      '#suffix' => '</em></strong></div>',
    );
/*    $form['class_schedule_entry_record']['period_start_datetime_' . $inew] = array(
      '#type' => 'hidden',
//      '#title' => t('Period'),
      '#default_value' => array(
         'month' => $class_start_date->format('n'),
         'day' => $class_start_date->format('j'),
         'year' => $class_start_date->format('Y'),
        ),
      '#prefix' => '<div style="float: left;width:200px" >',
      '#suffix' => '</div>',
    );
*/
    $form['class_schedule_entry_record']['period_day_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Day'),
      '#options' =>  kleosis_dayofweek_values(),
      '#default_value' => 1,
      '#prefix' => '<div style="float:left;clear:left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['from_' . $inew] = array(
      '#markup' => t('from:'),
      '#prefix' => '<div style="float: left;width:60px" >&nbsp;&nbsp;<strong><em>',
      '#suffix' => '</em></strong>&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['period_start_hour_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Hour'),
      '#options' =>  kleosis_hours_values(),
      '#default_value' => $pstartd->format('H'),
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_start_minute_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Min'),
      '#options' =>  kleosis_minutes_values(),
      '#default_value' => $pstartd->format('i'),
      '#prefix' => '<div style="float: left;width:100" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['to_' . $inew] = array(
      '#markup' => t('to:'),
      '#prefix' => '<div style="float: left;width:40px" >&nbsp;&nbsp;<strong><em>',
      '#suffix' => '</em></strong>&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['period_end_hour_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Hour'),
      '#options' =>  kleosis_hours_values(),
      '#default_value' => $pendd->format('H'),
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_end_minute_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Min'),
      '#options' =>  kleosis_minutes_values(),
      '#default_value' => $pendd->format('i'),
      '#prefix' => '<div style="float: left;width:120" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['classroom_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Room'),
      '#options' =>  ks_get_classrooms(),
      '#default_value' => 1,
      '#disabled' => FALSE,
      '#prefix' => '<div style="float: left;width:150px" >',
      '#suffix' => '</div>',
    );
/*
    $form['class_schedule_entry_record']['period_status_' . $inew] = array(
      '#type' => 'select',
//      '#title' => t('Status'),
      '#options' =>  ks_schedule_period_status_values(),
      '#default_value' => 1,
      '#prefix' => '<div style="float: left;width:110" >',
      '#suffix' => '</div>',
    );
*/
    $form['class_schedule_entry_record']['period_lead_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Lead Instructor'),
      '#options' =>  array(0 => t('no instructor')) + ks_get_instructor_names(),
      '#default_value' => 0,
      '#prefix' => '<div style="float: left;width:140px" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_sub_' . $inew] = array(
      '#type' => 'select',
      '#title' => t('Sub Instructor'),
      '#options' =>  array(0 => t('no sub')) + ks_get_instructor_names(),
      '#default_value' => 0,
      '#prefix' => '<div style="float: left;width:140px" >',
      '#suffix' => '</div>',
    );
// end of blank period


    $form['class_schedule_entry_record']['spacer'] = array(
      '#markup' =>    '&nbsp;',
      '#prefix' => '<div style="float: left;clear: left;width:1px">',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['add'] = array(
      '#type' => 'submit',
      '#value' => t('Add'),
      '#weight' => 20,
      '#prefix' => '<div style="float: left;clear:left; width:125px" ><p>',
      '#suffix' => '</p></div>',
    );

    $form['class_schedule_entry_record']['cancel'] = array(
      '#type' => 'submit',
      '#value' => t('Cancel'),
      '#weight' => 25,
      '#prefix' => '<div style="float: left; width:125px" ><p>',
      '#suffix' => '</p></div>',
    );

  return $form;
}

/*
* Validate function for the kleosis_class_schedule_create_form
*/

  function kleosis_class_schedule_create_form_validate($form, &$form_state) {

//    dpm('inside kleosis_class_schedule_create_form_submit');
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
* Submit function for the kleosis_class_schedule_create_form
*/
function kleosis_class_schedule_create_form_submit($form, &$form_state) {

//  dpm('inside kleosis_class_schedule_create_form_submit');
//  dpm($form_state['values']);
//  dpm($form_state['input']['op']);

  if ($form_state['input']['op'] == 'Cancel') {

   $form_state['redirect'] = 'kleosis/classes/schedule';
    drupal_redirect_form($form_state);
  }

  $theclass = node_load($form_state['values']['kccls_id_fk_new']);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $schedule_record = array();
  $schedule_record['kclss_id'] = $form_state['values']['kclss_id_new'];
  $schedule_record['kccls_id_fk'] = $form_state['values']['kccls_id_fk_new'];
  $schedule_record['period_start_datetime']['year'] = $class_start_date->format('Y');
  $schedule_record['period_start_datetime']['month'] = $class_start_date->format('n');
  $schedule_record['period_start_datetime']['day'] = $class_start_date->format('j');
  $schedule_record['period_day'] = $form_state['values']['period_day_new'];
  $schedule_record['period_start_hour'] = $form_state['values']['period_start_hour_new'];
  $schedule_record['period_start_minute'] = $form_state['values']['period_start_minute_new'];
  $schedule_record['period_end_hour'] = $form_state['values']['period_end_hour_new'];
  $schedule_record['period_end_minute'] = $form_state['values']['period_end_minute_new'];
  $schedule_record['classroom'] = $form_state['values']['classroom_new'];
//  $schedule_record['period_status'] = $form_state['values']['period_status_new'];
  $schedule_record['period_status'] = 1;  // for Kleosis Lite
  $schedule_record['period_lead'] = $form_state['values']['period_lead_new'];
  $schedule_record['period_sub'] = $form_state['values']['period_sub_new'];

  $ok = ks_insert_schedule_record($schedule_record);

// dpm($schedule_record);
// dpm($ok);

  $form_state['redirect'] = 'kleosis/classes/schedule/create';

}
