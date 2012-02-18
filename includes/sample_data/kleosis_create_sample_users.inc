<?php

/**
 * @file
 *  Default entries for Kleosis users after install
 *
 *  Creates Kleosis sample students, instructors, and parent_guardians
 */

  $role_id_student = ks_create_new_role('student');  // will not create the role if exists already
  $role_id_instructor = ks_create_new_role('instructor');
  $role_id_parent_guardian = ks_create_new_role('parent_guardian');

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9000',
        'pass' => 'student9000',
        'mail' => 'student9000@student9000.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436B',
    'reg_no' => '256',
    'fullname' => 'student9000-fullname',
    'familyname' => 'std9000-ln',
    'friendlyname' => 'Ninerzero',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-09-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-01-23',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-04-01',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9001',
        'pass' => 'student9001',
        'mail' => 'student9001@student9001.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436Z',
    'reg_no' => '267',
    'fullname' => 'student9001-fullname',
    'familyname' => 'std9001-ln',
    'friendlyname' => 'Ninerzero1',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1992-08-14',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2014-02-22',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-03-17',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-04-05',
    'graduation_date' => '2018-06-01',
    'entrance_exam_date' => '2010-03-21',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9002',
        'pass' => 'student9002',
        'mail' => 'student9002@student9002.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436G',
    'reg_no' => '154',
    'fullname' => 'student9002-fullname',
    'familyname' => 'std9002-ln',
    'friendlyname' => 'Ninerzero2',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-06-12',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2017-07-12',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-16',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-05',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-09',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9003',
        'pass' => 'student9003',
        'mail' => 'student9003@student9003.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436W',
    'reg_no' => '319',
    'fullname' => 'student9003-fullname',
    'familyname' => 'std9003-ln',
    'friendlyname' => 'Ninerzero3',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1997-09-29',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2017-11-03',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-15',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-11',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-09',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9004',
        'pass' => 'student9004',
        'mail' => 'student9004@student9004.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436S',
    'reg_no' => '106',
    'fullname' => 'student9004-fullname',
    'familyname' => 'std9004-ln',
    'friendlyname' => 'Ninerzero4',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-09-10',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-03-23',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-18',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-21',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-31',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);



// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9005',
        'pass' => 'student9005',
        'mail' => 'student9005@student9005.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436X',
    'reg_no' => '146',
    'fullname' => 'student9005-fullname',
    'familyname' => 'std9005-ln',
    'friendlyname' => 'Ninerzero5',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-08-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2014-01-23',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-12',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-01',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9006',
        'pass' => 'student9006',
        'mail' => 'student9006@student9006.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436E',
    'reg_no' => '216',
    'fullname' => 'student9006-fullname',
    'familyname' => 'std9006-ln',
    'friendlyname' => 'Ninerzero6',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-10-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-07-23',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-01-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-02-01',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-02-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);



// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9007',
        'pass' => 'student9007',
        'mail' => 'student9007@student9007.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436R',
    'reg_no' => '156',
    'fullname' => 'student9007-fullname',
    'familyname' => 'std9007-ln',
    'friendlyname' => 'Ninerzero7',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-11-10',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2019-01-10',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-22',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-21',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9008',
        'pass' => 'student9008',
        'mail' => 'student9008@student9008.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436F',
    'reg_no' => '236',
    'fullname' => 'student9008-fullname',
    'familyname' => 'std9008-ln',
    'friendlyname' => 'Ninerzero8',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-01-25',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-06-13',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-04-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-05-01',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-05-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9009',
        'pass' => 'student9009',
        'mail' => 'student9009@student9009.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436V',
    'reg_no' => '206',
    'fullname' => 'student9009-fullname',
    'familyname' => 'std9009-ln',
    'friendlyname' => 'Ninerzero9',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1996-04-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2019-03-23',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-18',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-02',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9010',
        'pass' => 'student9010',
        'mail' => 'student9010@student9010.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436T',
    'reg_no' => '157',
    'fullname' => 'student9010-fullname',
    'familyname' => 'std9010-ln',
    'friendlyname' => 'Ninerzero10',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-12-11',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-02-23',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-05-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-06-01',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-06-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9011',
        'pass' => 'student9011',
        'mail' => 'student9011@student9011.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954334',
    'reg_no' => '156',
    'fullname' => 'student9011-fullname',
    'familyname' => 'std9011-ln',
    'friendlyname' => 'Ninerzero11',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-08-30',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2017-12-25',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-03-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-04-01',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);



// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9012',
        'pass' => 'student9012',
        'mail' => 'student9012@student9012.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436Y',
    'reg_no' => '306',
    'fullname' => 'student9012-fullname',
    'familyname' => 'std9012-ln',
    'friendlyname' => 'Ninerzero12',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1996-01-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-01-24',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-03-13',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-04-01',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-04-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9013',
        'pass' => 'student9013',
        'mail' => 'student9013@student9013.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436H',
    'reg_no' => '246',
    'fullname' => 'student9013-fullname',
    'familyname' => 'std9013-ln',
    'friendlyname' => 'Ninerzero13',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1996-01-01',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-07-01',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-01-10',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-04',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9014',
        'pass' => 'student9014',
        'mail' => 'student9014@student9014.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954334',
    'reg_no' => '156',
    'fullname' => 'student9014-fullname',
    'familyname' => 'std9014-ln',
    'friendlyname' => 'Ninerzero14',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1996-02-25',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2019-01-27',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-02-12',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-21',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-09',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);



// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9015',
        'pass' => 'student9015',
        'mail' => 'student9015@student9015.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436N',
    'reg_no' => '136',
    'fullname' => 'student9015-fullname',
    'familyname' => 'std9015-ln',
    'friendlyname' => 'Ninerzero15',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1996-01-12',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2015-07-27',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 12,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2010-03-29',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2010-08-18',
    'acceptance_date' => '2010-03-23',
    'graduation_date' => '2015-06-01',
    'entrance_exam_date' => '2010-03-09',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 12);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9016',
        'pass' => 'student9016',
        'mail' => 'student9016@student9016.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436U',
    'reg_no' => '456',
    'fullname' => 'student9016-fullname',
    'familyname' => 'std9016-ln',
    'friendlyname' => 'Ninerzero16',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-03-03',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2019-01-01',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-15',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-03-03',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9017',
        'pass' => 'student9017',
        'mail' => 'student9017@student9017.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954334',
    'reg_no' => '023',
    'fullname' => 'student9017-fullname',
    'familyname' => 'std9017-ln',
    'friendlyname' => 'Ninerzero17',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-06-12',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2017-01-20',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-03-23',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);



// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9018',
        'pass' => 'student9018',
        'mail' => 'student9018@student9018.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436J',
    'reg_no' => '156',
    'fullname' => 'student9018-fullname',
    'familyname' => 'std9018-ln',
    'friendlyname' => 'Ninerzero18',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1993-09-29',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2018-06-23',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-01-12',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-03-05',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-04',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9019',
        'pass' => 'student9019',
        'mail' => 'student9019@student9019.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436M',
    'reg_no' => '056',
    'fullname' => 'student9019-fullname',
    'familyname' => 'std9019-ln',
    'friendlyname' => 'Ninerzero19',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-03-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2018-09-13',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-28',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-03-17',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9020',
        'pass' => 'student9020',
        'mail' => 'student9020@student9020.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954334',
    'reg_no' => '159',
    'fullname' => 'student9020-fullname',
    'familyname' => 'std9020-ln',
    'friendlyname' => 'Ninerzero20',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-08-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2017-03-23',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-03-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9021',
        'pass' => 'student9021',
        'mail' => 'student9021@student9021.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436I',
    'reg_no' => '056',
    'fullname' => 'student9021-fullname',
    'familyname' => 'std9021-ln',
    'friendlyname' => 'Ninerzero21',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-06-20',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2017-05-05',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-10',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-03-12',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9022',
        'pass' => 'student9022',
        'mail' => 'student9022@student9022.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436K',
    'reg_no' => '026',
    'fullname' => 'student9022-fullname',
    'familyname' => 'std9022-ln',
    'friendlyname' => 'Ninerzero22',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-09-15',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2019-03-03',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9023',
        'pass' => 'student9023',
        'mail' => 'student9023@student9023.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436O',
    'reg_no' => '012',
    'fullname' => 'student9023-fullname',
    'familyname' => 'std9023-ln',
    'friendlyname' => 'Ninerzero23',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-10-25',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2018-04-30',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-03-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-21',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9024',
        'pass' => 'student9024',
        'mail' => 'student9024@student9024.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436L',
    'reg_no' => '006',
    'fullname' => 'student9024-fullname',
    'familyname' => 'std9024-ln',
    'friendlyname' => 'Ninerzero24',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-09-25',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2018-01-22',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-17',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9025',
        'pass' => 'student9025',
        'mail' => 'student9025@student9025.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A71295436P',
    'reg_no' => '212',
    'fullname' => 'student9025-fullname',
    'familyname' => 'std9025-ln',
    'friendlyname' => 'Ninerzero25',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-08-14',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2017-06-24',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-03-10',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-21',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9026',
        'pass' => 'student9026',
        'mail' => 'student9026@student9026.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954A6B',
    'reg_no' => '259',
    'fullname' => 'student9026-fullname',
    'familyname' => 'std9026-ln',
    'friendlyname' => 'Ninerzero26',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-07-12',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Rio de Janeiro',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Brazil',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2019-01-02',
    'passport_place_of_issue' => 'Sao Paulo',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-03-29',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-30',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9027',
        'pass' => 'student9027',
        'mail' => 'student9027@student9027.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954B34',
    'reg_no' => '333',
    'fullname' => 'student9027-fullname',
    'familyname' => 'std9027-ln',
    'friendlyname' => 'Ninerzero27',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-12-01',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2018-04-01',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-20',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9028',
        'pass' => 'student9028',
        'mail' => 'student9028@student9028.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954D34',
    'reg_no' => '045',
    'fullname' => 'student9028-fullname',
    'familyname' => 'std9028-ln',
    'friendlyname' => 'Ninerzero28',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-08-09',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2018-01-29',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-01-19',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-03-30',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9029',
        'pass' => 'student9029',
        'mail' => 'student9029@student9029.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954E34',
    'reg_no' => '101',
    'fullname' => 'student9029-fullname',
    'familyname' => 'std9029-ln',
    'friendlyname' => 'Ninerzero29',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1995-01-31',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2019-05-21',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-10',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-03-27',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-15',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);

// 1 - create a new student in Drupal

   $user = array(
        'name' => 'student9030',
        'pass' => 'student9030',
        'mail' => 'student9030@student9030.com',
        'status' => 1,
        'roles' => array($role_id_student => 'student')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'student');  // set the role again in case user already exists

// 3 - create the student in the ks_students table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'identity_id' => 'A712954F34',
    'reg_no' => '078',
    'fullname' => 'student9030-fullname',
    'familyname' => 'std9030-ln',
    'friendlyname' => 'Ninerzero30',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'gender' => 0,
    'religion' => 'Frisbiterian',
    'date_of_birth' => '1994-12-10',
    'nationality' =>  'Earthling',
    'language_at_home' => 'Swahili',
    'mobile_phone' => '+97150 682-2567',
    'home_phone' => '+0101 777-2323',
    'other_phone_1' => '',
    'other_phone_2' => '',
    'address_1' => '923 Elm St',
    'address_2' => 'Suite 23',
    'address_3' => '',
    'address_city' => 'Caracas',
    'address_region_state' => '',
    'address_province' => '',
    'address_country' => 'Argentina',
    'address_zip_postalcode' => 'SambaSamba',
    'living_with' => 1,
    'passport_no' => '',
    'passport_expiry_dt' => '2018-04-07',
    'passport_place_of_issue' => 'Caracas',
    'curr_status' => 1,
    'curr_gradelevel' => 13,
    'curr_main_program' => 1,
    'curr_other_program' => 2,
    'curr_campus' => 1,
    'curr_other' => '',
    'application_date' => '2007-02-14',
    'application_forms_signed' => 1,
    'anticipated_start_date' => '2007-08-18',
    'acceptance_date' => '2007-04-01',
    'graduation_date' => '2014-06-01',
    'entrance_exam_date' => '2007-03-01',
    'entrance_exam_results' => 'very good',
    'english_level_at_acceptance' => 3,
//    'special_needs' => '',
    'transportation' => 1,
    'website' => 'http:/www.google.com',
    'remarks' => 'Yes',
  );
  db_insert('ks_students')
    ->fields($fields)
    ->execute();

//  4 - create a student status details record with status 'student'

  kleosis_set_student_status_details($drp_uid, 13);


// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8400',
        'pass' => 'instructor8400',
        'mail' => 'instructor8400@instructor8400.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567B',
    'relationship' => 0,
    'fullname' => 'instructor8400-fullname',
    'familyname' => 'instr8400-ln',
    'friendlyname' => 'Nikk',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8400 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8401',
        'pass' => 'instructor8401',
        'mail' => 'instructor8401@instructor8401.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567R',
    'relationship' => 0,
    'fullname' => 'instructor8401-fullname',
    'familyname' => 'instr8401-ln',
    'friendlyname' => 'Nikk1',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8401 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8402',
        'pass' => 'instructor8402',
        'mail' => 'instructor8402@instructor8402.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567D',
    'relationship' => 0,
    'fullname' => 'instructor8402-fullname',
    'familyname' => 'instr8402-ln',
    'friendlyname' => 'Nikk2',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8402 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8403',
        'pass' => 'instructor8403',
        'mail' => 'instructor8403@instructor8403.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567C',
    'relationship' => 0,
    'fullname' => 'instructor8403-fullname',
    'familyname' => 'instr8403-ln',
    'friendlyname' => 'Nikk',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8403 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8404',
        'pass' => 'instructor8404',
        'mail' => 'instructor8404@instructor8404.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567I',
    'relationship' => 0,
    'fullname' => 'instructor8404-fullname',
    'familyname' => 'instr8404-ln',
    'friendlyname' => 'Nikk',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8404 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8405',
        'pass' => 'instructor8405',
        'mail' => 'instructor8405@instructor8405.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567K',
    'relationship' => 0,
    'fullname' => 'instructor8405-fullname',
    'familyname' => 'instr8405-ln',
    'friendlyname' => 'Nikk5',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8405 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8406',
        'pass' => 'instructor8406',
        'mail' => 'instructor8406@instructor8406.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567Y',
    'relationship' => 0,
    'fullname' => 'instructor8406-fullname',
    'familyname' => 'instr8406-ln',
    'friendlyname' => 'Nikk6',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8406 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();

// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8407',
        'pass' => 'instructor8407',
        'mail' => 'instructor8407@instructor8407.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567H',
    'relationship' => 0,
    'fullname' => 'instructor8407-fullname',
    'familyname' => 'instr8407-ln',
    'friendlyname' => 'Nikk7',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8407 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();

// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8408',
        'pass' => 'instructor8408',
        'mail' => 'instructor8408@instructor8408.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567V',
    'relationship' => 0,
    'fullname' => 'instructor8408-fullname',
    'familyname' => 'instr8408-ln',
    'friendlyname' => 'Nikk8',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8408 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();

// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8409',
        'pass' => 'instructor8409',
        'mail' => 'instructor8409@instructor8409.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567N',
    'relationship' => 0,
    'fullname' => 'instructor8409-fullname',
    'familyname' => 'instr8409-ln',
    'friendlyname' => 'Nikk9',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8409 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();

// 1 - create a new instructor in Drupal

   $user = array(
        'name' => 'instructor8410',
        'pass' => 'instructor8410',
        'mail' => 'instructor8410@instructor8410.com',
        'status' => 1,
        'roles' => array($role_id_instructor => 'instructor')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'instructor');  // set the role again in case user already exists

// 3 - create the instructor in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 1,
    'identity_id' =>  'A1234567M',
    'relationship' => 0,
    'fullname' => 'instructor8410-fullname',
    'familyname' => 'instr8410-ln',
    'friendlyname' => 'Nikk10',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Diplomat',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Stonegate Rd.',
    'address_2' =>  'Suite 75',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '50210',
    'curr_status' => 1,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'instructor8410 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7500',
        'pass' => 'pguardian7500',
        'mail' => 'pguardian7500@pguardian7500.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482X',
    'relationship' => 0,
    'fullname' => 'pguardian7500-fullname',
    'familyname' => 'pg7500-ln',
    'friendlyname' => 'pgSeven',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7500 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7501',
        'pass' => 'pguardian7501',
        'mail' => 'pguardian7501@pguardian7501.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482P',
    'relationship' => 0,
    'fullname' => 'pguardian7501-fullname',
    'familyname' => 'pg7501-ln',
    'friendlyname' => 'pgSeven1',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7501 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7502',
        'pass' => 'pguardian7502',
        'mail' => 'pguardian7502@pguardian7502.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482I',
    'relationship' => 0,
    'fullname' => 'pguardian7502-fullname',
    'familyname' => 'pg7502-ln',
    'friendlyname' => 'pgSeven2',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7502 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7503',
        'pass' => 'pguardian7503',
        'mail' => 'pguardian7503@pguardian7503.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482Y',
    'relationship' => 0,
    'fullname' => 'pguardian7503-fullname',
    'familyname' => 'pg7503la3stname',
    'friendlyname' => 'pgSeven3',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7503 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7504',
        'pass' => 'pguardian7504',
        'mail' => 'pguardian7504@pguardian7504.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482T',
    'relationship' => 0,
    'fullname' => 'pguardian7504-fullname',
    'familyname' => 'pg7504la3stname',
    'friendlyname' => 'pgSeven4',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7504 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7505',
        'pass' => 'pguardian7505',
        'mail' => 'pguardian7505@pguardian7505.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482R',
    'relationship' => 0,
    'fullname' => 'pguardian7505-fullname',
    'familyname' => 'pg7505-ln',
    'friendlyname' => 'pgSeven5',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7505 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7506',
        'pass' => 'pguardian7506',
        'mail' => 'pguardian7506@pguardian7506.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482E',
    'relationship' => 0,
    'fullname' => 'pguardian7506-fullname',
    'familyname' => 'pg7506-ln',
    'friendlyname' => 'pgSeven6',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7506 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7507',
        'pass' => 'pguardian7507',
        'mail' => 'pguardian7507@pguardian7507.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482W',
    'relationship' => 0,
    'fullname' => 'pguardian7507-fullname',
    'familyname' => 'pg7507-ln',
    'friendlyname' => 'pgSeven7',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7507 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7508',
        'pass' => 'pguardian7508',
        'mail' => 'pguardian7508@pguardian7508.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482K',
    'relationship' => 0,
    'fullname' => 'pguardian7508-fullname',
    'familyname' => 'pg7508-ln',
    'friendlyname' => 'pgSeven8',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7508 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7509',
        'pass' => 'pguardian7509',
        'mail' => 'pguardian7509@pguardian7509.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482J',
    'relationship' => 0,
    'fullname' => 'pguardian7509-fullname',
    'familyname' => 'pg7509-ln',
    'friendlyname' => 'pgSeven9',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7509 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();


// 1 - create a new parent_guardian in Drupal

   $user = array(
        'name' => 'pguardian7510',
        'pass' => 'pguardian7510',
        'mail' => 'pguardian7510@pguardian7510.com',
        'status' => 1,
        'roles' => array($role_id_parent_guardian => 'parent_guardian')
    );
    try {
      $newuser = user_save('', $user, $category = 'account');
    }
    catch (Exception $e) {
      //drupal_set_message('User already exists message: ' . $e->getMessage() );
    }

// 2 - get the Drupal uid of the newly created (or already existing) user

    $drp_uid = db_query('SELECT uid FROM {users} WHERE name = :name',
                            array(':name' => $user['name']))->fetchField();
    if (!isset($drp_uid)) {
        $drp_uid = 0;
    }
    $res = ks_assign_new_role_($drp_uid, 'parent_guardian');  // set the role again in case user already exists

// 3 - create the parent_guardian in the ks_users table

  $fields = array(
    'drp_uid_fk' => $drp_uid,
    'mdl_uid_fk' => 0,
    'usertype' => 2,
    'identity_id' =>  'Z777123482H',
    'relationship' => 0,
    'fullname' => 'pguardian7510-fullname',
    'familyname' => 'pg7510-ln',
    'friendlyname' => 'pgSeven10',
    'fullname_t' => '',
    'familyname_t' => '',
    'friendlyname_t' => '',
    'nationality' => 'Earthling',
    'occupation' => 'Teacher',
    'mobile_phone' => '+6689 555-7253',
    'home_phone' => '+6653 444-2339',
    'office_phone' => '+01210 555-1212',
    'other_phone' =>  '+01502 769-3232',
    'address_1' =>  '4315 Gatestone Rd.',
    'address_2' =>  'Suite 99',
    'address_3' =>  '',
    'address_city' => 'Chiang Mai',
    'address_region_state' => '',
    'address_province' => 'Chiang Mai',
    'address_country' => 'Thailand',
    'address_zip_postalcode' =>  '502122',
    'curr_status' => 0,
//    'began_date' => '',
//    'end_date' => '',
    'remarks' =>  'pguardian7510 checking in...',
  );
  db_insert('ks_users')
    ->fields($fields)
    ->execute();

/*
 * function to create a student_status_details record with status of student
 *
 */
function kleosis_set_student_status_details($ssd_drp_uid, $ssd_gradelevel) {

        $stdt = new DateTime('now');

        $cnt = db_insert('ks_student_status_details')
            ->fields(array( 'kstu_id_fk' => $ssd_drp_uid,
                            'ksts_id_fk' => 1,
                            'status_reason' => 'Student application approved.',
                            'status_date' => $stdt->format('Y-m-d'),
                            'gradelevel' => $ssd_gradelevel,
                            'remarks' => '',
                            ) )
            ->execute();
}