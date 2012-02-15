<?php
// $Id: kleosis.install.inc,v 1.2 2011/03/29 01:53:21 kendev Exp $

/**
 * @file
 * Default entries for kleosis tables during install.
 */

/**
 * Implements hook_install().
 *
 * In Drupal 7, there is no need to install schema using this hook, the schema
 * is already installed before this hook is called.
 *
 * Kleosis roles and variables are created here
 *
 * @see hook_install()
 */

function kleosis_install() {

  $kleosis_roles = array('student', 'instructor', 'parent_guardian');  // kleosis roles

  foreach ($kleosis_roles as $kleosis_role) {
    $role = user_role_load_by_name($kleosis_role);
    $role_exists = ($role) ? TRUE : FALSE;
    variable_set('kleosis_' . $kleosis_role . '_role_exists', $role_exists);
  }
// create the kleosis roles first

  $role_id_student = ks_create_new_role('student');  // will not create the role if exists already
  $role_id_instructor = ks_create_new_role('instructor');
  $role_id_parent_guardian = ks_create_new_role('parent_guardian');

  variable_set('kleosis_organization', '1');
  variable_set('kleosis_sample_users', FALSE);
  variable_set('kleosis_sample_data', FALSE);
  variable_set('kleosis_academic_year', '2011-2012');
  variable_set('kleosis_academic_term', 'fy');
  variable_set('kleosis_last_term_in_fy','0');
  variable_set('kleosis_starting_dow', '1');
  variable_set('kleosis_moodle_url', 'http://localhost/moodle');
  variable_set('kleosis_moodle_version', '2.x');
  variable_set('kleosis_moodle_username', 'admin');
  variable_set('kleosis_moodle_password', 'moodle');
  variable_set('kleosis_odtreports_path', '/tmp');
  variable_set('kleosis_pager_rows', '16');

  variable_set('kleosis_morn_break_start_hour', '00');
  variable_set('kleosis_morn_break_start_min', '00');
  variable_set('kleosis_morn_break_end_hour', '00');
  variable_set('kleosis_morn_break_end_min', '00');
  variable_set('kleosis_lunch_start_hour', '00');
  variable_set('kleosis_lunch_start_min', '00');
  variable_set('kleosis_lunch_end_hour', '00');
  variable_set('kleosis_lunch_end_min', '00');
  variable_set('kleosis_aft_break_start_hour', '00');
  variable_set('kleosis_aft_break_start_min', '00');
  variable_set('kleosis_aft_break_end_hour', '00');
  variable_set('kleosis_aft_break_end_min', '00');

/*
  variable_set('kleosis_final_exam_weight','25.00');
  variable_set('kleosis_course_grade_weight','75.00');
  variable_set('kleosis_course_grade_item_1_name','Item 1 grade');
  variable_set('kleosis_course_grade_item_1_weight','00.00');
  variable_set('kleosis_course_grade_item_2_name','Item 2 grade');
  variable_set('kleosis_course_grade_item_2_weight','00.00');
  variable_set('kleosis_course_grade_item_3_name','Item 3 grade');
  variable_set('kleosis_course_grade_item_3_weight','00.00');
*/
}

