<?php

/**
 * @file
 *  Unpopulate the Kleosis description tables
 */

/**
 * unpopulate the ks_absence_type_desc table
 */
  $cnt_deleted = db_delete('ks_absence_type_desc')->execute();
  drupal_set_message(t('ks_absence_type_desc table entries have been removed'));

/**
 * unpopulate the ks_academic_year_desc table
 */
  $cnt_deleted = db_delete('ks_academic_year_desc')->execute();
  drupal_set_message(t('ks_academic_year_desc table entries have been removed'));

/**
 * unpopulate the ks_assessment_type_desc table
 */
  $cnt_deleted = db_delete('ks_assessment_type_desc')->execute();
  drupal_set_message(t('ks_assessment_type_desc table entries have been removed'));

/**
 * unpopulate the ks_campus_desc table
 */
  $cnt_deleted = db_delete('ks_campus_desc')->execute();
  drupal_set_message(t('ks_campus_desc table entries have been removed'));

/**
 * unpopulate the ks_class_schedule_status_desc table
 */
  $cnt_deleted = db_delete('ks_class_schedule_status_desc')->execute();
  drupal_set_message(t('ks_class_schedule_status_desc table entries have been removed'));

/**
 * unpopulate the ks_class_status_desc table
 */
  $cnt_deleted = db_delete('ks_class_status_desc')->execute();
  drupal_set_message(t('ks_class_status_desc table entries have been removed'));

/**
 * unpopulate the ks_class_type_desc table
 */
  $cnt_deleted = db_delete('ks_class_type_desc')->execute();
  drupal_set_message(t('ks_class_type_desc table entries have been removed'));

/**
 * unpopulate the ks_classroom_desc table
 */
  $cnt_deleted = db_delete('ks_classroom_desc')->execute();
  drupal_set_message(t('ks_classroom_desc table entries have been removed'));

/**
 * unpopulate the ks_countries_desc table
 */
  $cnt_deleted = db_delete('ks_countries_desc')->execute();
  drupal_set_message(t('ks_countries_desc table entries have been removed'));
/**
 * unpopulate the ks_course_auth_desc table
 */
  $cnt_deleted = db_delete('ks_course_auth_desc')->execute();
  drupal_set_message(t('ks_course_auth_desc table entries have been removed'));

/**
 * unpopulate the ks_course_status_desc table
 */
  $cnt_deleted = db_delete('ks_course_status_desc')->execute();
  drupal_set_message(t('ks_course_status_desc table entries have been removed'));

/**
 * unpopulate the ks_course_type_desc table
 */
  $cnt_deleted = db_delete('ks_course_type_desc')->execute();
  drupal_set_message(t('ks_course_type_desc table entries have been removed'));

/**
 * unpopulate the ks_department_desc table
 */
  $cnt_deleted = db_delete('ks_department_desc')->execute();
  drupal_set_message(t('ks_department_desc table entries have been removed'));

/**
 * unpopulate the ks_english_level_desc table
 */
  $cnt_deleted = db_delete('ks_english_level_desc')->execute();
  drupal_set_message(t('ks_english_level_desc table entries have been removed'));

/**
 * unpopulate the ks_excused_absence_reason_desc table
 */
  $cnt_deleted = db_delete('ks_excused_absence_reason_desc')->execute();
  drupal_set_message(t('ks_excused_absence_reason_desc table entries have been removed'));

/**
 * unpopulate the ks_gradelevel_desc table
 */
  $cnt_deleted = db_delete('ks_gradelevel_desc')->execute();
  drupal_set_message(t('ks_gradelevel_desc table entries have been removed'));

/**
 * unpopulate the ks_ib_level_desc table
 */
  $cnt_deleted = db_delete('ks_ib_level_desc')->execute();
  drupal_set_message(t('ks_ib_level_desc table entries have been removed'));

/**
 * unpopulate the ks_instructor_class_role_desc table
 */
  $cnt_deleted = db_delete('ks_instructor_class_role_desc')->execute();
  drupal_set_message(t('ks_instructor_class_role_desc table entries have been removed'));

/**
 * unpopulate the ks_instructor_lms_role_desc table
 */
  $cnt_deleted = db_delete('ks_instructor_lms_role_desc')->execute();
  drupal_set_message(t('ks_instructor_lms_role_desc table entries have been removed'));

/**
 * unpopulate the ks_instructor_status_desc table
 */
  $cnt_deleted = db_delete('ks_instructor_status_desc')->execute();
  drupal_set_message(t('ks_instructor_status_desc table entries have been removed'));

/**
 * unpopulate the ks_lab_type_desc table
 */
  $cnt_deleted = db_delete('ks_lab_type_desc')->execute();
  drupal_set_message(t('ks_lab_type_desc table entries have been removed'));

/**
 * unpopulate the ks_medical_category_desc table
 */
  $cnt_deleted = db_delete('ks_medical_category_desc')->execute();
  drupal_set_message(t('ks_medical_category_desc table entries have been removed'));

/**
 * unpopulate the ks_medical_subject_desc table
 */
  $cnt_deleted = db_delete('ks_medical_subject_desc')->execute();
  drupal_set_message(t('ks_medical_subject_desc table entries have been removed'));

/**
 * unpopulate the ks_organization_desc table
 */
  $cnt_deleted = db_delete('ks_organization_desc')->execute();
  drupal_set_message(t('ks_organization_desc table entries have been removed'));

/**
 * unpopulate the ks_program_desc table
 */
  $cnt_deleted = db_delete('ks_program_desc')->execute();
  drupal_set_message(t('ks_program_desc table entries have been removed'));

/**
 * unpopulate the ks_report_odt table
 */
  $cnt_deleted = db_delete('ks_report_odt')->execute();
  drupal_set_message(t('ks_report_odt table entries have been removed'));

/**
 * unpopulate the ks_residings_desc table
 */
  $cnt_deleted = db_delete('ks_residings_desc')->execute();
  drupal_set_message(t('ks_residings_desc table entries have been removed'));

/**
 * unpopulate the ks_room_type_desc table
 */
  $cnt_deleted = db_delete('ks_room_type_desc')->execute();
  drupal_set_message(t('ks_room_type_desc table entries have been removed'));

/**
 * unpopulate the ks_student_group_desc table
 */
  $cnt_deleted = db_delete('ks_student_group_desc')->execute();
  drupal_set_message(t('ks_student_group_desc table entries have been removed'));

/**
 * unpopulate the ks_student_status_desc table
 */
  $cnt_deleted = db_delete('ks_student_status_desc')->execute();
  drupal_set_message(t('ks_student_status_desc table entries have been removed'));

/**
 * unpopulate the ks_transportation_desc table
 */
  $cnt_deleted = db_delete('ks_transportation_desc')->execute();
  drupal_set_message(t('ks_transportation_desc table entries have been removed'));

/**
 * unpopulate the ks_user_relationships_desc table
 */
  $cnt_deleted = db_delete('ks_user_relationships_desc')->execute();
  drupal_set_message(t('ks_user_relationships_desc table entries have been removed'));

/**
 * unpopulate the ks_usertypes_desc table
 */
  $cnt_deleted = db_delete('ks_usertypes_desc')->execute();
  drupal_set_message(t('ks_usertypes_desc table entries have been removed'));



