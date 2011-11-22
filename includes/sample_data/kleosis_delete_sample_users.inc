<?php
// $Id: kleosis_delete_users.inc,v 1.8 2011/11/21 01:55:21 kendev Exp $

/**
 * @file
 * Remove the Kleosis sample users and their data in related tables
 */

 // remove enrollments first // todo: can improve this by deleting only the sample students related enrollments
  drupal_set_message('Removing all enrollments...');
  $cnt_deleted = db_delete('ks_student_course_classes')->execute();
  drupal_set_message('Enrollments have been removed');

  drupal_set_message('Removing sample students...');
  $kleosis_users = array('student9000', 'student9001', 'student9002', 'student9003', 'student9004',
                        'student9005', 'student9006', 'student9007', 'student9008', 'student9009',
                        'student9010', 'student9011', 'student9012', 'student9013', 'student9014', 'student9015',
                        'student9016', 'student9017', 'student9018', 'student9019', 'student9020', 'student9021',
                        'student9022', 'student9023', 'student9024', 'student9025', 'student9026', 'student9027',
                        'student9028', 'student9029', 'student9030',
                        'instructor8400', 'instructor8401', 'instructor8402', 'instructor8403', 'instructor8404',
                        'instructor8405', 'instructor8406', 'instructor8407', 'instructor8408', 'instructor8409',
                        'instructor8410',
                        'pguardian7500', 'pguardian7501', 'pguardian7502', 'pguardian7503', 'pguardian7504',
                        'pguardian7505', 'pguardian7506', 'pguardian7507', 'pguardian7508', 'pguardian7509',
                        'pguardian7510', );

  foreach ($kleosis_users as $kleosis_user) { // delete the sample kleosis users
    $leuser = user_load_by_name($kleosis_user);
    if ($leuser) {
     user_delete($leuser->uid);
    }
  }

// todo: delete from the following tables only the records belonging to the sample students, instructors, and parent-guardians

  $cnt_deleted = db_delete('ks_students')->execute();

  $cnt_deleted = db_delete('ks_users')->execute();

  $cnt_deleted = db_delete('ks_attendance_taken')->execute();
  $cnt_deleted = db_delete('ks_class_schedule')->execute();
  $cnt_deleted = db_delete('ks_course_grades')->execute();
  $cnt_deleted = db_delete('ks_instructor_attendance')->execute();
  $cnt_deleted = db_delete('ks_instructor_class_schedule')->execute();
  $cnt_deleted = db_delete('ks_medical_info')->execute();
  $cnt_deleted = db_delete('ks_student_attendance')->execute();
  $cnt_deleted = db_delete('ks_student_course_class_grades')->execute();
  $cnt_deleted = db_delete('ks_student_course_classes')->execute();
  $cnt_deleted = db_delete('ks_student_groups')->execute();
  $cnt_deleted = db_delete('ks_student_status_details')->execute();
  $cnt_deleted = db_delete('ks_user_relationships')->execute();
  $cnt_deleted = db_delete('ks_user_urls')->execute();

