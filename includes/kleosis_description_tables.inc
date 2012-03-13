<?php

/**
* @file
*   Kleosis Description Tables
*/

/**
 * Provides a form with Kleosis description tables lists
 *
 * @return
 *   a form with description tables lists
 */
function kleosis_get_desc_tables() {

  $form = array();

  $form += ks_absence_type_desc_list();
  $form += ks_excused_absence_reason_desc_list();
  $form += ks_campus_desc_list();
  $form += ks_class_status_desc_list();
  $form += ks_class_type_desc_list();
  $form += ks_classroom_desc_list();
  $form += ks_class_schedule_status_desc_list();
  $form += ks_course_auth_desc_list();
  $form += ks_course_status_desc_list();
  $form += ks_course_type_desc_list();
  $form += ks_department_desc_list();
  $form += ks_english_level_desc_list();
  $form += ks_gradelevel_desc_list();
  $form += ks_ib_level_desc_list();
  $form += ks_instructor_class_role_desc_list();
  $form += ks_instructor_lms_role_desc_list();
  $form += ks_instructor_status_desc_list();
  $form += ks_lab_type_desc_list();
  $form += ks_organization_desc_list();
  $form += ks_program_desc_list();
  $form += ks_residings_desc_list();
  $form += ks_room_type_desc_list();
  $form += ks_student_group_desc_list();
  $form += ks_student_status_desc_list();
  $form += ks_transportation_desc_list();
  $form += ks_user_relationships_desc_list();
  $form += ks_academic_year_desc_list_a();
  $form += ks_academic_year_desc_list_b();

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Absence Type description table
 *
 * @return
 *   a form with list of entries
 */
function ks_absence_type_desc_list() {

  $form['ks_absence_type_desc'] = array(
      '#type' => 'fieldset',
      '#title' => t('Absence Types &nbsp;(ks_absence_type_desc)'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );
  $header = array(
    'kabsty_id' => array('data' => t('Id'), 'field' => 'kabsty_id'),
    'absence_type' => array('data' => t('Absence Type'), 'field' => 'absence_type'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kabsty_id, absence_type, description FROM {ks_absence_type_desc}' )->fetchAll();
  foreach ($results as $absence_type) {
    $options[$absence_type->kabsty_id] = array(
      'kpgm_id' => $absence_type->kabsty_id,
      'absence_type' => $absence_type->absence_type,
      'description' => $absence_type->description,
    );
  }
  $form['ks_absence_type_desc']['list'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Excused Absence Reasons description table
 *
 * @return
 *   a form with list of entries
 */
function ks_excused_absence_reason_desc_list() {

  $form['ks_excused_absence_reason_desc'] = array(
      '#type' => 'fieldset',
      '#title' => t('Excused Absence Reasons &nbsp;(ks_excused_absence_reason_desc)'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );
  $header = array(
    'kexcr_id' => array('data' => t('Id'), 'field' => 'kexcr_id'),
    'excuse_reason' => array('data' => t('Excuse Reason'), 'field' => 'excuse_reason'),
    'excused' => array('data' => t('Excused'), 'field' => 'excused'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kexcr_id, excuse_reason, excused, description FROM {ks_excused_absence_reason_desc}' )->fetchAll();
  foreach ($results as $excuse_reason) {
    $options[$excuse_reason->kexcr_id] = array(
      'kexcr_id' => $excuse_reason->kexcr_id,
      'excuse_reason' => $excuse_reason->excuse_reason,
      'excused' => $excuse_reason->excused,
      'description' => $excuse_reason->description,
    );
  }
  $form['ks_excused_absence_reason_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Campus description table
 *
 * @return
 *   a form with list of entries
 */
function ks_campus_desc_list() {

  $form['ks_campus_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Campuses &nbsp;(ks_campus_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kcmps_id' => array('data' => t('Id'), 'field' => 'kcmps_id'),
    'campus' => array('data' => t('Campus'), 'field' => 'campus'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kcmps_id, campus, description FROM {ks_campus_desc}' )->fetchAll();
  foreach ($results as $campus) {
    $options[$campus->kcmps_id] = array(
      'kpgm_id' => $campus->kcmps_id,
      'campus' => $campus->campus,
      'description' => $campus->description,
    );
  }
  $form['ks_campus_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Class Schedule Status description table
 *
 * @return
 *   a form with list of entries
 */
function ks_class_schedule_status_desc_list() {

  $form['ks_class_schedule_status_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Class Schedule Statuses &nbsp;(ks_class_schedule_status_desc)'),
    '#disabled' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kclsss_id' => array('data' => t('Id'), 'field' => 'kclsss_id'),
    'status' => array('data' => t('Status'), 'field' => 'status'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kclsss_id, status, description FROM {ks_class_schedule_status_desc}' )->fetchAll();
  foreach ($results as $status) {
    $options[$status->kclsss_id] = array(
      'kclsss_id' => $status->kclsss_id,
      'status' => $status->status,
      'description' => $status->description,
    );
  }
  $form['ks_class_schedule_status_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Class Status description table
 *
 * @return
 *   a form with list of entries
 */
function ks_class_status_desc_list() {

  $form['ks_class_status_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Class Statuses &nbsp;(ks_class_status_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kclsts_id' => array('data' => t('Id'), 'field' => 'kclsts_id'),
    'status' => array('data' => t('Status'), 'field' => 'status'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kclsts_id, status, description FROM {ks_class_status_desc}' )->fetchAll();
  foreach ($results as $status) {
    $options[$status->kclsts_id] = array(
      'kclsts_id' => $status->kclsts_id,
      'status' => $status->status,
      'description' => $status->description,
    );
  }
  $form['ks_class_status_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Class Type description table
 *
 * @return
 *   a form with list of entries
 */
function ks_class_type_desc_list() {

  $form['ks_class_type_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Class Types &nbsp;(ks_class_type_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kclsty_id' => array('data' => t('Id'), 'field' => 'kclsty_id'),
    'class_type' => array('data' => t('Class Type'), 'field' => 'class_type'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kclsty_id, class_type, description FROM {ks_class_type_desc}' )->fetchAll();
  foreach ($results as $class_type) {
    $options[$class_type->kclsty_id] = array(
      'kclsty_id' => $class_type->kclsty_id,
      'class_type' => $class_type->class_type,
      'description' => $class_type->description,
    );
  }
  $form['ks_class_type_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Classroom description table
 *
 * @return
 *   a form with list of entries
 */
function ks_classroom_desc_list() {

  $form['ks_classroom_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Classrooms &nbsp;(ks_classroom_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kclsr_id' => array('data' => t('Id'), 'field' => 'kclsr_id'),
    'room_name' => array('data' => t('Room Name'), 'field' => 'room_name'),
    'room_type' => array('data' => t('Room Type'), 'field' => 'room_type'),
    'room_building' => array('data' => t('Room Building'), 'field' => 'room_building'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kclsr_id, room_name, room_type, room_building, description FROM {ks_classroom_desc}' )->fetchAll();
  foreach ($results as $classroom) {
    $options[$classroom->kclsr_id] = array(
      'kclsr_id' => $classroom->kclsr_id,
      'room_name' => $classroom->room_name,
      'room_type' => $classroom->room_type,
      'room_building' => $classroom->room_building,
      'description' => $classroom->description,
    );
  }
  $form['ks_classroom_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Course Auth description table
 *
 * @return
 *   a form with list of entries
 */
function ks_course_auth_desc_list() {

  $form['ks_course_auth_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course Authorization &nbsp;(ks_course_auth_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kcauth_id' => array('data' => t('Id'), 'field' => 'kcauth_id'),
    'course_auth' => array('data' => t('Course Auth'), 'field' => 'course_auth'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kcauth_id, course_auth, description FROM {ks_course_auth_desc}' )->fetchAll();
  foreach ($results as $course_auth) {
    $options[$course_auth->kcauth_id] = array(
      'kcauth_id' => $course_auth->kcauth_id,
      'course_auth' => $course_auth->course_auth,
      'description' => $course_auth->description,
    );
  }
  $form['ks_course_auth_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Course Status description table
 *
 * @return
 *   a form with list of entries
 */
function ks_course_status_desc_list() {

  $form['ks_course_status_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course Statuses &nbsp;(ks_course_status_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kcsts_id' => array('data' => t('Id'), 'field' => 'kcsts_id'),
    'status' => array('data' => t('Status'), 'field' => 'status'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kcsts_id, status, description FROM {ks_course_status_desc}' )->fetchAll();
  foreach ($results as $status) {
    $options[$status->kcsts_id] = array(
      'kcsts_id' => $status->kcsts_id,
      'status' => $status->status,
      'description' => $status->description,
    );
  }
  $form['ks_course_status_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}
/**
 * Provides a list of the entries in Kleosis Course Type description table
 *
 * @return
 *   a form with list of entries
 */
function ks_course_type_desc_list() {

  $form['ks_course_type_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course Types &nbsp;(ks_course_type_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kcrsty_id' => array('data' => t('Id'), 'field' => 'kcrsty_id'),
    'course_type' => array('data' => t('Course Type'), 'field' => 'course_type'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kcrsty_id, course_type, description FROM {ks_course_type_desc}' )->fetchAll();
  foreach ($results as $course_type) {
    $options[$course_type->kcrsty_id] = array(
      'kcrsty_id' => $course_type->kcrsty_id,
      'course_type' => $course_type->course_type,
      'description' => $course_type->description,
    );
  }
  $form['ks_course_type_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Departments description table
 *
 * @return
 *   a form with list of entries
 */
function ks_department_desc_list() {

  $form['ks_department_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Departments &nbsp;(ks_department_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kdept_id' => array('data' => t('Id'), 'field' => 'kdept_id'),
    'department' => array('data' => t('Department'), 'field' => 'department'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kdept_id, department, description FROM {ks_department_desc}' )->fetchAll();
  foreach ($results as $department) {
    $options[$department->kdept_id] = array(
      'kdept_id' => $department->kdept_id,
      'department' => $department->department,
      'description' => $department->description,
    );
  }
  $form['ks_department_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis English Level description table
 *
 * @return
 *   a form with list of entries
 */
function ks_english_level_desc_list() {

  $form['ks_english_level_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('English Levels &nbsp;(ks_english_level_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kelvl_id' => array('data' => t('Id'), 'field' => 'kelvl_id'),
    'english_level' => array('data' => t('English Level'), 'field' => 'english_level'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kelvl_id, english_level, description FROM {ks_english_level_desc}' )->fetchAll();
  foreach ($results as $english_level) {
    $options[$english_level->kelvl_id] = array(
      'kelvl_id' => $english_level->kelvl_id,
      'english_level' => $english_level->english_level,
      'description' => $english_level->description,
    );
  }
  $form['ks_english_level_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Gradelevel description table
 *
 * @return
 *   a form with list of entries
 */
function ks_gradelevel_desc_list() {

  $form['ks_gradelevel_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Grade Levels &nbsp;(ks_gradelevel_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kgrdl_id' => array('data' => t('Id'), 'field' => 'kgrdl_id'),
    'gradelevel' => array('data' => t('Gradelevel'), 'field' => 'gradelevel'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kgrdl_id, gradelevel, description FROM {ks_gradelevel_desc}' )->fetchAll();
  foreach ($results as $gradelevel) {
    $options[$gradelevel->kgrdl_id] = array(
      'kgrdl_id' => $gradelevel->kgrdl_id,
      'gradelevel' => $gradelevel->gradelevel,
      'description' => $gradelevel->description,
    );
  }
  $form['ks_gradelevel_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis IB Level description table
 *
 * @return
 *   a form with list of entries
 */
function ks_ib_level_desc_list() {

  $form['ks_ib_level_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('IB Levels &nbsp;(ks_ib_level_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kibl_id' => array('data' => t('Id'), 'field' => 'kibl_id'),
    'ib_level' => array('data' => t('IB Level'), 'field' => 'ib_level'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kibl_id, ib_level, description FROM {ks_ib_level_desc}' )->fetchAll();
  foreach ($results as $ib_level) {
    $options[$ib_level->kibl_id] = array(
      'kibl_id' => $ib_level->kibl_id,
      'ib_level' => $ib_level->ib_level,
      'description' => $ib_level->description,
    );
  }
  $form['ks_ib_level_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Instructor Class Role description table
 *
 * @return
 *   a form with list of entries
 */
function ks_instructor_class_role_desc_list() {

  $form['ks_instructor_class_role_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Instructor Class Roles &nbsp;(ks_instructor_class_role_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kiclsr_id' => array('data' => t('Id'), 'field' => 'kiclsr_id'),
    'rolename' => array('data' => t('Rolename'), 'field' => 'rolename'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kiclsr_id, rolename, description FROM {ks_instructor_class_role_desc}' )->fetchAll();
  foreach ($results as $rolename) {
    $options[$rolename->kiclsr_id] = array(
      'kiclsr_id' => $rolename->kiclsr_id,
      'rolename' => $rolename->rolename,
      'description' => $rolename->description,
    );
  }
  $form['ks_instructor_class_role_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Instructor LMS Role description table
 *
 * @return
 *   a form with list of entries
 */
function ks_instructor_lms_role_desc_list() {

  $form['ks_instructor_lms_role_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Instructor LMS Roles &nbsp;(ks_instructor_lms_role_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'klmsr_id' => array('data' => t('Id'), 'field' => 'klmsr_id'),
    'rolename' => array('data' => t('Rolename'), 'field' => 'rolename'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT klmsr_id, rolename, description FROM {ks_instructor_lms_role_desc}' )->fetchAll();
  foreach ($results as $rolename) {
    $options[$rolename->klmsr_id] = array(
      'klmsr_id' => $rolename->klmsr_id,
      'rolename' => $rolename->rolename,
      'description' => $rolename->description,
    );
  }
  $form['ks_instructor_lms_role_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Instructor Status description table
 *
 * @return
 *   a form with list of entries
 */
function ks_instructor_status_desc_list() {

  $form['ks_instructor_status_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Instructor Statuses &nbsp;(ks_instructor_status_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kinsts_id' => array('data' => t('Id'), 'field' => 'kinsts_id'),
    'status' => array('data' => t('Status'), 'field' => 'status'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kinsts_id, status, description FROM {ks_instructor_status_desc}' )->fetchAll();
  foreach ($results as $instructor) {
    $options[$instructor->kinsts_id] = array(
      'kinsts_id' => $instructor->kinsts_id,
      'status' => $instructor->status,
      'description' => $instructor->description,
    );
  }
  $form['ks_instructor_status_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Lab Type description table
 *
 * @return
 *   a form with list of entries
 */
function ks_lab_type_desc_list() {

  $form['ks_lab_type_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Lab Types &nbsp;(ks_lab_type_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'klabty_id' => array('data' => t('Id'), 'field' => 'klabty_id'),
    'lab_type' => array('data' => t('Lab Type'), 'field' => 'lab_type'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT klabty_id, lab_type, description FROM {ks_lab_type_desc}' )->fetchAll();
  foreach ($results as $lab_type) {
    $options[$lab_type->klabty_id] = array(
      'klabty_id' => $lab_type->klabty_id,
      'lab_type' => $lab_type->lab_type,
      'description' => $lab_type->description,
    );
  }
  $form['ks_lab_type_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Programs description table
 *
 * @return
 *   a form with list of entries
 */
function ks_program_desc_list() {

  $form['ks_program_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Programs &nbsp;(ks_program_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kpgm_id' => array('data' => t('Id'), 'field' => 'kpgm_id'),
    'program' => array('data' => t('Program'), 'field' => 'program'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kpgm_id, program, description FROM {ks_program_desc}' )->fetchAll();
  foreach ($results as $program) {
    $options[$program->kpgm_id] = array(
      'kpgm_id' => $program->kpgm_id,
      'program' => $program->program,
      'description' => $program->description,
    );
  }
  $form['ks_program_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Organizations description table
 *
 * @return
 *   a form with list of entries
 */
function ks_organization_desc_list() {

  $form['ks_organization_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Organizations &nbsp;(ks_organization_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'korg_id' => array('data' => t('Id'), 'field' => 'korg_id'),
    'organization' => array('data' => t('Organization'), 'field' => 'organization'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT korg_id, organization, description FROM {ks_organization_desc}' )->fetchAll();
  foreach ($results as $organization) {
    $options[$organization->korg_id] = array(
      'korg_id' => $organization->korg_id,
      'organization' => $organization->organization,
      'description' => $organization->description,
    );
  }
  $form['ks_organization_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Residings description table
 *
 * @return
 *   a form with list of entries
 */
function ks_residings_desc_list() {

  $form['ks_residings_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Residing With &nbsp;(ks_residings_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kres_id' => array('data' => t('Id'), 'field' => 'kres_id'),
    'residing_with' => array('data' => t('Residing With'), 'field' => 'residing_with'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kres_id, residing_with, description FROM {ks_residings_desc}' )->fetchAll();
  foreach ($results as $residing_with) {
    $options[$residing_with->kres_id] = array(
      'kres_id' => $residing_with->kres_id,
      'residing_with' => $residing_with->residing_with,
      'description' => $residing_with->description,
    );
  }
  $form['ks_residings_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Room Type description table
 *
 * @return
 *   a form with list of entries
 */
function ks_room_type_desc_list() {

  $form['ks_room_type_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Room Types &nbsp;(ks_room_type_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'krmtyp_id' => array('data' => t('Id'), 'field' => 'krmtyp_id'),
    'room_type' => array('data' => t('Room Type'), 'field' => 'room_type'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT krmtyp_id, room_type, description FROM {ks_room_type_desc}' )->fetchAll();
  foreach ($results as $room_type) {
    $options[$room_type->krmtyp_id] = array(
      'krmtyp_id' => $room_type->krmtyp_id,
      'room_type' => $room_type->room_type,
      'description' => $room_type->description,
    );
  }
  $form['ks_room_type_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Student Groupa description table
 *
 * @return
 *   a form with list of entries
 */
function ks_student_group_desc_list() {

  $form['ks_student_group_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student Groups &nbsp;(ks_student_group_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'ksgrpd_id' => array('data' => t('Id'), 'field' => 'ksgrpd_id'),
    'groupname' => array('data' => t('Group Name'), 'field' => 'groupname'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT ksgrpd_id, groupname, description FROM {ks_student_group_desc}' )->fetchAll();
  foreach ($results as $groupname) {
    $options[$groupname->ksgrpd_id] = array(
      'ksgrpd_id' => $groupname->ksgrpd_id,
      'groupname' => $groupname->groupname,
      'description' => $groupname->description,
    );
  }
  $form['ks_student_group_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Student Status description table
 *
 * @return
 *   a form with list of entries
 */
function ks_student_status_desc_list() {

  $form['ks_student_status_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student Statuses &nbsp;(ks_student_status_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'ksts_id' => array('data' => t('Id'), 'field' => 'ksts_id'),
    'status' => array('data' => t('Status'), 'field' => 'status'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT ksts_id, status, description FROM {ks_student_status_desc}' )->fetchAll();
  foreach ($results as $instructor) {
    $options[$instructor->ksts_id] = array(
      'ksts_id' => $instructor->ksts_id,
      'status' => $instructor->status,
      'description' => $instructor->description,
    );
  }
  $form['ks_student_status_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Transportation description table
 *
 * @return
 *   a form with list of entries
 */
function ks_transportation_desc_list() {

  $form['ks_transportation_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Transportation &nbsp;(ks_transportation_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'ktrns_id' => array('data' => t('Id'), 'field' => 'ktrns_id'),
    'transportation' => array('data' => t('Transportation'), 'field' => 'transportation'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT ktrns_id, transportation, description FROM {ks_transportation_desc}' )->fetchAll();
  foreach ($results as $transportation) {
    $options[$transportation->ktrns_id] = array(
      'ktrns_id' => $transportation->ktrns_id,
      'transportation' => $transportation->transportation,
      'description' => $transportation->description,
    );
  }
  $form['ks_transportation_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis User Relationships description table
 *
 * @return
 *   a form with list of entries
 */
function ks_user_relationships_desc_list() {

  $form['ks_user_relationships_desc'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Relationships &nbsp;(ks_user_relationships_desc)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'kurel_id' => array('data' => t('Id'), 'field' => 'kurel_id'),
    'relationship' => array('data' => t('Relationship'), 'field' => 'relationship'),
    'description' => array('data' => t('Description'), 'field' => 'description'),
  );
  $options = array();
  $results = db_query('SELECT kurel_id, relationship, description FROM {ks_user_relationships_desc}' )->fetchAll();
  foreach ($results as $relationship) {
    $options[$relationship->kurel_id] = array(
      'kurel_id' => $relationship->kurel_id,
      'relationship' => $relationship->relationship,
      'description' => $relationship->description,
    );
  }
  $form['ks_user_relationships_desc']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Provides a list of the entries in Kleosis Academic Year description table for terms 1 - 3
 *
 * @return
 *   a form with list of entries
 */
function ks_academic_year_desc_list_a() {

  $form['ks_academic_year_desc_list_a'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year Terms 1 - 3 &nbsp;(ks_academic_year_desc_list)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'academic_year' => array('data' => t('Academic Year'), 'field' => 'academic_year'),
    'term1_startdate' => array('data' => t('Term 1 Start Date'), 'field' => 'term1_startdate'),
    'term1_enddate' => array('data' => t('Term 1 End Date'), 'field' => 'term1_enddate'),
    'term2_startdate' => array('data' => t('Term 2 Start Date'), 'field' => 'term2_startdate'),
    'term2_enddate' => array('data' => t('Term 2 End Date'), 'field' => 'term2_enddate'),
    'term3_startdate' => array('data' => t('Term 3 Start Date'), 'field' => 'term3_startdate'),
    'term3_enddate' => array('data' => t('Term 3 End Date'), 'field' => 'term3_enddate'),
  );
  $options = array();
  $results = db_query('SELECT kayr_id, academic_year, term1_startdate, term1_enddate, term2_startdate, term2_enddate, term3_startdate, term3_enddate  FROM {ks_academic_year_desc}' )->fetchAll();
  foreach ($results as $ayear) {
    $options[$ayear->kayr_id] = array(
      'academic_year' => $ayear->academic_year,
      'term1_startdate' => $ayear->term1_startdate,
      'term1_enddate' => $ayear->term1_enddate,
      'term2_startdate' => $ayear->term2_startdate,
      'term2_enddate' => $ayear->term2_enddate,
      'term3_startdate' => $ayear->term3_startdate,
      'term3_enddate' => $ayear->term3_enddate,
    );
  }
  $form['ks_academic_year_desc_list_a']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}
/**
 * Provides a list of the entries in Kleosis Academic Year description table for terms 4 - 6
 *
 * @return
 *   a form with list of entries
 */
function ks_academic_year_desc_list_b() {

  $form['ks_academic_year_desc_list_b'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year Terms 4 - 6 &nbsp;(ks_academic_year_desc_list)'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $header = array(
    'academic_year' => array('data' => t('Academic Year'), 'field' => 'academic_year'),
    'term4_startdate' => array('data' => t('Term 4 Start Date'), 'field' => 'term4_startdate'),
    'term4_enddate' => array('data' => t('Term 4 End Date'), 'field' => 'term4_enddate'),
    'term5_startdate' => array('data' => t('Term 5 Start Date'), 'field' => 'term5_startdate'),
    'term5_enddate' => array('data' => t('Term 5 End Date'), 'field' => 'term5_enddate'),
    'term6_startdate' => array('data' => t('Term 6 Start Date'), 'field' => 'term6_startdate'),
    'term6_enddate' => array('data' => t('Term 6 End Date'), 'field' => 'term6_enddate'),
  );
  $options = array();
  $results = db_query('SELECT kayr_id, academic_year, term4_startdate, term4_enddate, term5_startdate, term5_enddate, term6_startdate, term6_enddate  FROM {ks_academic_year_desc}' )->fetchAll();
  foreach ($results as $ayear) {
    $options[$ayear->kayr_id] = array(
      'academic_year' => $ayear->academic_year,
      'term4_startdate' => $ayear->term4_startdate,
      'term4_enddate' => $ayear->term4_enddate,
      'term5_startdate' => $ayear->term5_startdate,
      'term5_enddate' => $ayear->term5_enddate,
      'term6_startdate' => $ayear->term6_startdate,
      'term6_enddate' => $ayear->term6_enddate,
    );
  }
  $form['ks_academic_year_desc_list_b']['list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No entries for this description table exists.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}
