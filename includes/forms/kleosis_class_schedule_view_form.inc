<?php

/**
 * @file
 *  Kleosis Class Schedule view form
 *
 *  Provides the view form for a Class schedule
 */

function kleosis_class_schedule_view_form($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Classes'), 'kleosis/classes');
  $breadcrumb[] = t('View Schedule');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Class Schedule'));

  $classid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['kleosis_class_selected_class']['classid']) ? $_SESSION['kleosis_class_selected_class']['classid'] : 0);
  $classname = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['kleosis_class_selected_class']['classname']) ? $_SESSION['kleosis_class_selected_class']['classname'] : '');

  if ($classid == 0) {
    drupal_set_message(t('Please select a class from the Classes List page'));
    drupal_goto('kleosis/classes', array());
  }

  if ( isset( $_GET['ksopid'] )  ) {  // then arrived here from student class schedule, so update the class session variables
    $_SESSION['kleosis_class_selected_class']['classid'] = $classid;
    $_SESSION['kleosis_class_selected_class']['classname'] = $classname;
  }

  $ks_libpath = drupal_get_path('module', 'kleosis');
  $kslib = $ks_libpath . '/includes/kleosis_lib.inc';
  require_once($kslib);

  $defaults = TRUE;
//  $uid = $_SESSION['student']['id'];
//  $username = $_SESSION['student']['name'];

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
  $query->orderBy('ksclss.period_start_datetime', 'ASC');

  $period_record = $query->execute()->fetchAll();

  $class_node = node_load($classid);
  $acy =   $class_node->ks_class_academic_year['und'][0]['value'];
  $term =   $class_node->ks_class_term['und'][0]['value'];
  $classname_acyt = ' ' . $acy . ', ' . $term;

  if (empty($period_record)) {
    $form['no_schedule'] = array(
        '#markup' => t('There is no schedule defined for class: @class', array('@class' => $classname)),
        '#weight' => -10,
        '#prefix' => '<div style="float: left;clear: left;width:700px" ><br/><strong>',
        '#suffix' => '</strong><br/></div>',
      );
    $form['no_schedule_acyt'] = array(
        '#markup' => t('Academic Year and Term: @class', array('@class' => $classname_acyt)),
        '#weight' => -8,
        '#prefix' => '<div style="float: left;clear: left;width:700px" ><strong><p>',
        '#suffix' => '</strong></p></div>',
      );
    return $form;
  }
  else {
    $form['weekly_schedule'] = array(
        '#markup' => t('Weekly schedule for class: @class', array('@class' => $classname)),
        '#weight' => -10,
        '#prefix' => '<div style="float: left;clear: left;width:700px" ><br/><strong>',
        '#suffix' => '</strong></div>',
      );
    $form['weekly_schedule_acyt'] = array(
        '#markup' => t('Academic Year and Term: @class', array('@class' => $classname_acyt)),
        '#weight' => -8,
        '#prefix' => '<div style="float: left;clear: left;width:700px" ><strong><p>',
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

  // provide a header row for the period schedule columns

  $form['class_schedule_entry_record']['day_of_week'] = array(
    '#markup' =>    'Day',
    '#prefix' => '<div style="float: left;clear: left;width:105px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['period duration'] = array(
    '#markup' =>    'Period Duration',
    '#prefix' => '<div style="float: left;width:170px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['Room'] = array(
    '#markup' =>    'Room',
    '#prefix' => '<div style="float: left;width:125px"><strong>',
    '#suffix' => '</strong></div>',
  );
  $form['class_schedule_entry_record']['instructor_lead'] = array(
    '#markup' =>    'Instructor',
    '#prefix' => '<div style="float: left;width:155px"><strong>',
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

//    dpm($period);
    $pstartd = !empty($period->period_start_datetime) ? new DateTime($period->period_start_datetime) : new DateTime('1900-01-02 03:04:05');
    $pendd = !empty($period->period_end_datetime) ? new DateTime($period->period_end_datetime) : new DateTime('1900-01-02 03:04:05');

    $form['class_schedule_entry_record']['kclss_id_' . $i] = array(
      '#type' => 'hidden',
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
    $form['class_schedule_entry_record']['period_day_' . $i] = array(
      '#markup' => ks_get_day_string($period->period_day),
      '#prefix' => '<div style="float: left;clear: left;width:100px" ><strong><em>',
      '#suffix' => '</em></strong></div>',
    );
/*    $form['class_schedule_entry_record']['period_start_datetime_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Period'),
      '#markup' => ($defaults)? $pstartd->format('d-M-Y') : '',
      '#prefix' => '<div style="float: left;width:100px" >',
      '#suffix' => '</div>',
    );
*/
    $form['class_schedule_entry_record']['from_' . $i] = array(
      '#markup' => t('from'),
      '#prefix' => '<div style="float: left;width:50px" >&nbsp;&nbsp;<strong><em>',
      '#suffix' => '</em></strong>&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['period_start_hour_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Hour'),
      '#markup' => ($defaults)? $pstartd->format('H') : '',
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['c1_' . $i] = array(
      '#markup' => ':',
      '#prefix' => '<div style="float: left;width:6px" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_start_minute_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Min'),
      '#markup' => ($defaults)? $pstartd->format('i') : '',
      '#prefix' => '<div style="float: left;width:100" >',
      '#suffix' => '</div>',
    );
  $form['class_schedule_entry_record']['to_' . $i] = array(
      '#markup' => t('to'),
      '#prefix' => '<div style="float: left;width:25px" >&nbsp;&nbsp;<strong><em>',
      '#suffix' => '</em></strong>&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['period_end_hour_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Hour'),
      '#markup' => ($defaults)? $pendd->format('H') : '',
      '#prefix' => '<div style="float: left;width:80" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['c2_' . $i] = array(
      '#markup' => ':',
      '#prefix' => '<div style="float: left;width:6px" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['period_end_minute_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Min'),
      '#markup' => ($defaults)? $pendd->format('i') : '',
      '#prefix' => '<div style="float: left;width:120" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['spacer1_' . $i] = array(
      '#markup' => '&nbsp;&nbsp;',
      '#prefix' => '<div style="float: left;width:25px" >&nbsp;&nbsp;',
      '#suffix' => '&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['classroom_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Classroom'),
      '#markup' => ($defaults)? ks_get_classroom($period->classroom) : '',
      '#disabled' => FALSE,
      '#prefix' => '<div style="float: left;width:125px" >',
      '#suffix' => '</div>',
    );
/*    $form['class_schedule_entry_record']['period_status_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Status'),
      '#markup' => ($defaults)? get_schedule_period_status($period->period_status) : '',
      '#prefix' => '<div style="float: left;width:100" >',
      '#suffix' => '</div>',
    );
*/
    $form['class_schedule_entry_record']['period_lead_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Status'),
      '#markup' =>  ($defaults) ? (get_ks_username_by_id($period->period_lead) ? get_ks_username_by_id($period->period_lead) : 'no instructor') : '',
      '#prefix' => '<div style="float: left;width:130px" >',
      '#suffix' => '</div>',
    );
    $form['class_schedule_entry_record']['spacer2_' . $i] = array(
      '#markup' => '&nbsp;&nbsp;',
      '#prefix' => '<div style="float: left;width:25px" >&nbsp;&nbsp;',
      '#suffix' => '&nbsp;&nbsp;</div>',
    );
    $form['class_schedule_entry_record']['period_sub_' . $i] = array(
      '#type' => 'item',
//      '#title' => t('Status'),
      '#markup' =>  ($defaults) ? (get_ks_username_by_id($period->period_sub) ? get_ks_username_by_id($period->period_sub) : 'no sub') : '',
      '#prefix' => '<div style="float: left;width:100" >',
      '#suffix' => '</div>',
    );

    $i += 1;

    } // end foreach()

  return $form;
}

