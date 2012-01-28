<?php

/**
 * @file
 * Manage the loading and unloading of Kleosis sample data (user initiated after install)
 */
/**
 * Build the forms for loading the sample data
 *
 */
function kleosis_processes_sample_data_page() {

  drupal_set_title(t('Sample Data'));

  $build['filter'] = drupal_get_form('kleosis_sample_data_form');
  $build['#submit'][] = 'kleosis_sample_data_form_submit';

  return $build;
}

/**
 * Load Kleosis sample courses and classes
 */
function kleosis_sample_data_form() {

 // create a fieldset for the load and unloading sample data
  $form['loadem'] = array(
    '#type' => 'fieldset',
    '#title' => t('Kleosis Sample Data'),
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['loadem']['load_desc'] = array(
    '#type' => 'submit',
    '#value' => t('Populate decription tables'),
    '#weight' => '1',
    '#prefix' => '<br/><div style="float: left;clear:left;width:340px" >',
    '#suffix' => '</div>',
  );
  $form['loadem']['remove_desc'] = array(
    '#type' => 'submit',
    '#value' => t('Unpopulate decription tables'),
//    '#disabled' => TRUE,
    '#weight' => '2',
    '#prefix' => '<div style="float: left;width:300px" >',
    '#suffix' => '</div>',
  );
  $form['loadem']['load_sample_data'] = array(
    '#type' => 'submit',
    '#value' => t('Load sample data'),
    '#weight' => '3',
    '#prefix' => '<br/><div style="float: left;clear:left;width:340px" >',
    '#suffix' => '</div>',
  );
  $form['loadem']['remove_sample_data'] = array(
    '#type' => 'submit',
    '#value' => t('Remove sample data*'),
//    '#disabled' => TRUE,
    '#weight' => '4',
    '#prefix' => '<div style="float: left;width:300px" >',
    '#suffix' => '</div>',
  );
  $form['notes_1'] = array(
      '#markup' => t('Instructions for loading the sample data:'),
      '#weight' => 12,
      '#prefix' => '<div style="float: left;clear: left;width:640px" ><strong><p>',
      '#suffix' => '</strong></p></div>',
    );
$use_desc = <<<EOT
    <strong>Populate description tables</strong> - This step is required and should be performed immediately after the Kleosis install. Maintenance screens for the inidividual
    description tables are not available yet, so modifications to the data entries can be accomplished by editing the kleosis_populate_description_tables.inc file &nbsp; (<strong><em>carefully</em></strong>). <br/><br/>

    <strong>Unpopulate description tables</strong> - Should be performed before any changes are made to the kleosis_populate_description_tables.inc file and before the tables are re-populated.<br/><br/>

    <strong>Load sample data</strong> - Loads sample users, courses, classes, class schedule, and enrollments.  This step should be performed after the description tables are populated. (The loading process may take a few minutes...)<br/><br/>
    <strong>Remove sample data*</strong> - Will remove the sample data <em>as well as any user-entered data</em> - <strong><em>use with caution!</em></strong> &nbsp;  This step should be performed prior to entering in new school data or re-loading the sample data again.
 <br/><br/>

EOT;

  $form['notes_2'] = array(
      '#markup' => $use_desc,
      '#weight' => 13,
      '#prefix' => '<div style="float: left;clear: left;width:832px" >',
      '#suffix' => '</div>',
    );
  return $form;
}

/**
 *
 * Implementation of hook_submit() for the sample data form.
 *
 */
function kleosis_sample_data_form_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Populate decription tables':
      drupal_set_message(t('Description tables are being populated...'));
       require_once('kleosis_populate_description_tables.inc');
      drupal_set_message(t('Description tables have been populated...'));

      break;

    case 'Unpopulate decription tables':
      drupal_set_message(t('Description tables are being unpopulated...'));
      require_once('kleosis_unpopulate_description_tables.inc');
      drupal_set_message(t('Description tables have been unpopulated...'));

      break;

    case 'Load sample data':
      $already_loaded = variable_get('kleosis_sample_data', FALSE);
      if (!$already_loaded) {
//        drupal_set_message(t('Sample users are being loaded...'));
        require_once('kleosis_create_sample_users.inc');
        drupal_set_message(t('Sample users have been loaded'));

//        drupal_set_message(t('Creating sample courses and classes...'));
        require_once('kleosis_create_sample_courses_and_classes.inc');
        drupal_set_message(t('Sample courses and classes have been created'));

//        drupal_set_message(t('Sample class schedule is being loaded...'));
        require_once('kleosis_create_sample_schedule.inc');
        drupal_set_message(t('Sample class schedule is now loaded'));

//        drupal_set_message(t('Sample enrollments are being loaded...'));
        require_once('kleosis_create_sample_enrollments.inc');
        drupal_set_message(t('Sample enrollments are now loaded'));

        variable_set('kleosis_sample_data', TRUE);
      }
      else {
        drupal_set_message(t('Sample data has already been loaded.'));
      }
      break;

    case 'Remove sample data*':
// todo: can improve this process by deleting only the sample data related records
//      drupal_set_message(t('Sample enrollments are now being removed...'));
      $cnt_deleted = db_delete('ks_student_course_classes')->execute();
      drupal_set_message(t('Enrollments have been removed.'));

//      drupal_set_message(t('Class schedule is now being removed...'));
      $cnt_deleted = db_delete('ks_class_schedule')->execute();
      drupal_set_message(t('Class schedule has been removed.'));

//      drupal_set_message(t('Removing sample classes...'));
      $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title like :kleosis';
      $result = db_query($sql, array(':type' => 'class', ':kleosis' => '%Kleosis%'));
      $nids = array();
      foreach ($result as $row) {
        $nids[] = $row->nid;
      }
      // Delete all the nodes at once
      node_delete_multiple($nids);
      drupal_set_message(t('Sample classes have been removed'));

//      drupal_set_message(t('Removing sample courses...'));
      $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title like :kleosis';
      $result = db_query($sql, array(':type' => 'course', ':kleosis' => '%Kleosis%'));
      $nids = array();
      foreach ($result as $row) {
        $nids[] = $row->nid;
      }
      // Delete all the nodes at once
      node_delete_multiple($nids);
      drupal_set_message(t('Sample courses have been removed'));

//      drupal_set_message(t('Sample users are being removed...'));
      require_once('kleosis_delete_sample_users.inc');
      drupal_set_message(t('Sample users have been deleted.'));

      variable_set('kleosis_sample_data', FALSE);

      break;
  }
}
