<?php

/**
 * @file
 *   kleosis DB Library functions
 */

/**
 * Retrieve the student current status as a string
 *
 * @param $intstatus
 *   The student current status as an integer
 * @return
 *   the student current status as a string
 */
function get_student_status_desc($intstatus) {

//  can do dynamic query instead:
//  $query = db_select('ks_student_status_desc', 'kstat');
//  $query->addField('kstat', 'status');
//  $query->condition('ksts_id', $intstatus, '=');
//  $curr_status = $query->execute()->fetchColumn();

  $curr_status = db_query('SELECT status FROM {ks_student_status_desc} WHERE ksts_id = :ksts_id',
                            array(':ksts_id' => $intstatus))->fetchField();
  return $curr_status;
}

/**
 * Get all student statuses
 *
 * @return
 *    options - an array of student statuses
 */
function get_student_statuses() {

  $options = array();
  $results = db_query('SELECT ksts_id, status FROM {ks_student_status_desc}' )->fetchAll();
  foreach ($results as $istatus) {
    $options[$istatus->ksts_id] = $istatus->status;
  }
  return $options;
}

/**
 *
 * update a student curr_status
 *
 * @param $uid
 *   The student uid
 * @param $intstatus
 *   The student current status as an integer
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function set_student_status($uid, $intstatus) {

  $cnt = db_update('ks_students')
         ->condition('drp_uid_fk', $uid, '=')
         ->fields(array('curr_status' => $intstatus ) )
          ->execute();

  return $cnt;
}
/**
 * Get all ks_students
 *
 * @return
 *    options - an array of students (key and value)
 */
function get_all_students() {

  $students = array();
  $query = db_select('users', 'u');
  $query->innerJoin('ks_students', 'kstu', 'kstu.drp_uid_fk = u.uid');
  $query->addField('u', 'name');
  $query->addField('kstu', 'drp_uid_fk');
  $query->orderBy('u.name', 'ASC');
  $results = $query->execute()->fetchAll();
  foreach ($results as $lestudent) {
    $students[$lestudent->drp_uid_fk] = $lestudent->name;
  }
  return $students;
}

/**
 * Get all ks_users
 *
 * @param $ks_int_usertype
 *    usertype as an integer (optional)
 * @return
 *    options - an array of ks_users (key and value)
 */
function get_all_ks_users($ks_int_usertype = 0) {

  $ks_users = array();
  $query = db_select('users', 'u');
  $query->innerJoin('ks_users', 'kusr', 'kusr.drp_uid_fk = u.uid');
  $query->addField('u', 'name');
  $query->addField('kusr', 'drp_uid_fk');
  if ($ks_int_usertype) {
    $query->condition('usertype', $ks_int_usertype, '=');
  }
  $query->orderBy('u.name', 'ASC');
  $results = $query->execute()->fetchAll();
  foreach ($results as $leuser) {
    $ks_users[$leuser->drp_uid_fk] = $leuser->name;
  }
  return $ks_users;
}
/**
 * Get ks_username by id
 *
 * @param $ks_drp_uid
 *   The ks_users drp_uid
 * @return
 *   the ks_users username
 */
function get_ks_username_by_id($ks_drp_uid) {

    $drp_username = db_query('SELECT name FROM {users} WHERE uid = :uid',
                            array(':uid' => $ks_drp_uid))->fetchField();
  return $drp_username;
}

/**
 * Get all instructors names and uids
 *
 * @return
 *    options - an array of instructors
 */
function ks_get_instructor_names() {

  $options = array();

  $query = db_select('users', 'u');
  $query->innerJoin('users_roles', 'ur', 'u.uid = ur.uid');
  $query->innerJoin('role', 'r', 'ur.rid = r.rid');
  $query->addField('u', 'uid');
  $query->addField('u', 'name');
  $query->condition('r.name', 'instructor', '=');
  $query->orderBy('u.name', 'ASC');

  $results = $query->execute()->fetchAll();

  foreach ($results as $instructor) {
    $options[$instructor->uid] = $instructor->name;
  }
  return
  $options;
}
/**
 * Retrieve the instructor current status as a string
 *
 * @param $intstatus
 *   The instructor current status as an integer
 * @return
 *   the instructor current status as a string
 */
function get_instructor_status_desc($intstatus) {

  $curr_status = db_query('SELECT status FROM {ks_instructor_status_desc} WHERE kinsts_id = :kinsts_id',
                            array(':kinsts_id' => $intstatus))->fetchField();
  return $curr_status;
}

/**
 * Get all instructor statuses
 *
 * @return
 *    options - an array of instructor statuses
 */
function get_instructor_statuses() {

  $options = array();
  $results = db_query('SELECT kinsts_id, status FROM {ks_instructor_status_desc}' )->fetchAll();
  foreach ($results as $istatus) {
    $options[$istatus->kinsts_id] = $istatus->status;
  }
  return $options;
}
/**
 * Retrieve the usertype name as a string
 *
 * @param $intusertype
 *   The usertype as an integer
 * @return
 *   the usertype as a string
 */
function get_usertype_desc($intusertype) {

  $usertype = db_query('SELECT usertype FROM {ks_usertypes_desc} WHERE kutyp_id = :kutyp_id',
                            array(':kutyp_id' => $intusertype))->fetchField();
  return $usertype;
}

/**
 * Get all usertypes
 *
 * @return
 *    options - an array of usertypes
 */
function get_usertypes() {

  $options = array();
  $results = db_query('SELECT kutyp_id, usertype FROM {ks_usertypes_desc}' )->fetchAll();
  foreach ($results as $iusertype) {
    $options[$iusertype->kutyp_id] = $iusertype->usertype;
  }
  return $options;
}
/**
 * Retrieve the usertype name as an integer
 *
 * @param $strusertype
 *   The usertype as an string
 * @return
 *   the usertype as an integer
 */
function get_usertype_str_desc($strusertype) {

  $usertype = db_query('SELECT kutyp_id FROM {ks_usertypes_desc} WHERE usertype = :usertype',
                            array(':usertype' => $strusertype))->fetchField();
  return $usertype;
}

/**
 * Get the academic years
 *
 * @return
 *    options - an array of academic years
 */
function ks_get_academic_years() {

  $options = array('all' => t('All'), );
  $results = db_query('SELECT academic_year FROM {ks_academic_year_desc}' )->fetchAll();
  foreach ($results as $iac_year) {
    $options[$iac_year->academic_year] = $iac_year->academic_year;
  }

  return $options;
}

/**
 * Retrieve the country name as a string
 *
 * @param $intcntry
 *   The country name as an integer
 * @return
 *   the country name as a string
 */
function get_country_name_desc($intcntry) {

  $country_name = db_query('SELECT country_name FROM {ks_countries_desc} WHERE kcntry_id = :kcntry_id',
                            array(':kcntry_id' => $intcntry))->fetchField();
  return $country_name;
}

/**
 * Get all country names
 *
 * @return
 *    options - an array of country names
 */
function get_country_names() {

  $options = array();
  $results = db_query('SELECT kcntry_id, name FROM {ks_countries_desc}' )->fetchAll();
  foreach ($results as $country) {
    $options[$country->kcntry_id] = $country->name;
  }
  return $options;
}
/**
 * Retrieve the country code_2 as a string
 *
 * @param $intcntry
 *   The country name as an integer
 * @return
 *   the country code_2 as a string
 */
function get_country_code_2_desc($intcntry) {

  $code_2 = db_query('SELECT code_2 FROM {ks_countries_desc} WHERE kcntry_id = :kcntry_id',
                            array(':kcntry_id' => $intcntry))->fetchField();
  return $code_2;
}

/**
 * Get all country code_2 names
 *
 * @return
 *    options - an array of country code_2 names
 */
function get_country_code_2_names() {

  $options = array();
  $results = db_query('SELECT kcntry_id, code_2 FROM {ks_countries_desc}' )->fetchAll();
  foreach ($results as $country) {
    $options[$country->kcntry_id] = $country->code_2;
  }
  return $options;
}

/**
 * Retrieve the residing person or place as a string
 *
 * @param $intreside
 *   The residing as an integer
 * @return
 *   the residing as a string
 */
function get_residing_desc($intreside) {

  $reside = db_query('SELECT residing_with FROM {ks_residings_desc} WHERE kres_id = :kres_id',
                            array(':kres_id' => $intreside))->fetchField();
  return $reside;
}

/**
 * Get all residing persons or places
 *
 * @return
 *    options - an array of residing persons or places
 */
function get_residing_names() {

  $options = array();
  $results = db_query('SELECT kres_id, residing_with FROM {ks_residings_desc}' )->fetchAll();
  foreach ($results as $residing) {
    $options[$residing->kres_id] = $residing->residing_with;
  }
  return $options;
}

/**
 * Retrieve the relationship as a string
 *
 * @param $intrelationship
 *   The relationship as an integer
 * @return
 *   the relationship as a string
 */
function get_user_relationship_desc($intrelationship) {

  $relationship = db_query('SELECT relationship FROM {ks_user_relationships_desc} WHERE kurel_id = :kurel_id',
                            array(':kurel_id' => $intrelationship))->fetchField();
  return $relationship;
}

/**
 * Get all user relationships
 *
 * @return
 *    options - an array of user relationships
 */
function get_user_relationships() {

  $options = array();
  $results = db_query('SELECT kurel_id, relationship FROM {ks_user_relationships_desc}' )->fetchAll();
  foreach ($results as $relationship) {
    $options[$relationship->kurel_id] = $relationship->relationship;
  }
  return $options;
}

/**
 * Retrieve the primary guardian id for a student
 *
 * @param $stu_uid
 *   The students ks_uid
 * @return
 *   the drupal id of the primary parent_guardian
 */
function get_student_primary_guardian($stu_uid) {

  // todo: look up (join) for the 'Primary Guardian' id
  $drp_uid = db_query('SELECT kusr_rel_id_fk FROM {ks_user_relationships} WHERE kusr_id_fk = :kusr_id_fk AND relationship = :relationship',
                            array(':relationship' => 5, ':kusr_id_fk' => $stu_uid))->fetchField();
  return $drp_uid;
}

/**
 * Retrieve the gradelevel as a string
 *
 * @param $intglevel
 *   The gradelevel as an integer
 * @return
 *   the gradelevel as a string
 */
function get_gradelevel_desc($intglevel) {

  $gradelevel = db_query('SELECT gradelevel FROM {ks_gradelevel_desc} WHERE kgrdl_id = :kgrdl_id',
                            array(':kgrdl_id' => $intglevel))->fetchField();
  return $gradelevel;
}

/**
 * Get all gradelevels
 *
 * @return
 *    options - an array of gradelevels
 */
function ks_get_gradelevels() {

  $options = array();
  $results = db_query('SELECT kgrdl_id, gradelevel FROM {ks_gradelevel_desc}' )->fetchAll();
  foreach ($results as $gradelevel) {
    $options[$gradelevel->kgrdl_id] = $gradelevel->gradelevel;
  }
  return $options;
}
/**
 * Get all organizations
 *
 * @return
 *    options - an array of organizations
 */
function ks_get_organizations() {

  $options = array();
  $results = db_query('SELECT korg_id, organization FROM {ks_organization_desc}' )->fetchAll();
  foreach ($results as $organization) {
    $options[$organization->korg_id] = $organization->organization;
  }
  return $options;
}
/**
 * Retrieve the organization as a string
 *
 * @param $intorg
 *   The organization as an integer
 * @return
 *   the organization as a string
 */
function ks_get_organization_desc($intorg) {

  $organization = db_query('SELECT organization FROM {ks_organization_desc} WHERE korg_id = :korg_id',
                            array(':korg_id' => $intorg))->fetchField();
  return $organization;
}

/**
 * Retrieve the program as a string
 *
 * @param $intprogram
 *   The program as an integer
 * @return
 *   the program as a string
 */
function get_program_desc($intprogram) {

  $program = db_query('SELECT program FROM {ks_program_desc} WHERE kpgm_id = :kpgm_id',
                        array(':kpgm_id' => $intprogram))->fetchField();
  return $program;
}

/**
 * Get all programs
 *
 * @return
 *    options - an array of programs
 */
function ks_get_programs() {

  $options = array();
  $results = db_query('SELECT kpgm_id, program FROM {ks_program_desc}' )->fetchAll();
  foreach ($results as $program) {
    $options[$program->kpgm_id] = $program->program;
  }
  return $options;
}

/**
 * Get all departments
 *
 * @return
 *    options - an array of departments
 */
function ks_get_departments() {

  $options = array();
  $results = db_query('SELECT kdept_id, department FROM {ks_department_desc}' )->fetchAll();
  foreach ($results as $department) {
    $options[$department->kdept_id] = $department->department;
  }
  return $options;
}

/**
 * Retrieve the IB Level as a string
 *
 * @param $int_ib_level
 *   The ib_level as an integer
 * @return
 *   the ib_level as a string
 */
function ks_get_ib_level_desc($int_ib_level) {

  $ib_level = db_query('SELECT ib_level FROM {ks_ib_level_desc} WHERE kibl_id = :kibl_id',
                        array(':kibl_id' => $int_ib_level))->fetchField();
  return $ib_level;
}

/**
 * Get all IB Levels
 *
 * @return
 *    options - an array of ib_levels
 */
function ks_get_ib_levels() {

  $options = array();
  $results = db_query('SELECT kibl_id, ib_level FROM {ks_ib_level_desc}' )->fetchAll();
  foreach ($results as $ib_level) {
    $options[$ib_level->kibl_id] = $ib_level->ib_level;
  }
  return $options;
}
/**
 * Retrieve the campus as a string
 *
 * @param $intcampus
 *   The campus as an integer
 * @return
 *   the campus as a string
 */
function get_campus_desc($intcampus) {

  $campus = db_query('SELECT campus FROM {ks_campus_desc} WHERE kcmps_id = :kcmps_id',
                        array(':kcmps_id' => $intcampus))->fetchField();
  return $campus;
}

/**
 * Get all campuses
 *
 * @return
 *    options - an array of campuses
 */
function get_campuses() {

  $options = array();
  $results = db_query('SELECT kcmps_id, campus FROM {ks_campus_desc}' )->fetchAll();
  foreach ($results as $campus) {
    $options[$campus->kcmps_id] = $campus->campus;
  }
  return $options;
}
/**
 * Get all course statuses
 *
 * @return
 *    options - an array of course statuses
 */
function ks_get_course_statuses() {

  $options = array();
  $results = db_query('SELECT kcsts_id, status FROM {ks_course_status_desc}' )->fetchAll();
  foreach ($results as $status) {
    $options[$status->kcsts_id] = $status->status;
  }
  return $options;
}
/**
 * Get all course types
 *
 * @return
 *    options - an array of course types
 */
function ks_get_course_types() {

  $options = array();
  $results = db_query('SELECT kcrsty_id, course_type FROM {ks_course_type_desc}' )->fetchAll();
  foreach ($results as $type) {
    $options[$type->kcrsty_id] = $type->course_type;
  }
  return $options;
}
/**
 * Get all class statuses
 *
 * @return
 *    options - an array of class statuses
 */
function ks_get_class_statuses() {

  $options = array();
  $results = db_query('SELECT kclsts_id, status FROM {ks_class_status_desc}' )->fetchAll();
  foreach ($results as $status) {
    $options[$status->kclsts_id] = $status->status;
  }
  return $options;
}
/**
 * Get all class types
 *
 * @return
 *    options - an array of class types
 */
function ks_get_class_types() {

  $options = array();
  $results = db_query('SELECT kclsty_id, class_type FROM {ks_class_type_desc}' )->fetchAll();
  foreach ($results as $type) {
    $options[$type->kclsty_id] = $type->class_type;
  }
  return $options;
}
/**
 * Get all room types
 *
 * @return
 *    options - an array of room types
 */
function ks_get_room_types() {

  $options = array();
  $results = db_query('SELECT krmtyp_id, room_type FROM {ks_room_type_desc}' )->fetchAll();
  foreach ($results as $type) {
    $options[$type->krmtyp_id] = $type->room_type;
  }
  return $options;
}
/**
 * Get all lab types
 *
 * @return
 *    options - an array of lab types
 */
function ks_get_lab_types() {

  $options = array();
  $results = db_query('SELECT klabty_id, lab_type FROM {ks_lab_type_desc}' )->fetchAll();
  foreach ($results as $type) {
    $options[$type->klabty_id] = $type->lab_type;
  }
  return $options;
}
/**
 * Get all classrooms
 *
 * @return
 *    options - an array of classrooms
 */
function ks_get_classrooms() {

  $options = array();
  $results = db_query('SELECT kclsr_id, room_name FROM {ks_classroom_desc}' )->fetchAll();
  foreach ($results as $classroom) {
    $options[$classroom->kclsr_id] = $classroom->room_name;
  }
  return $options;
}
/**
 * Retrieve the classroom as a string
 *
 * @param $intclassroom
 *   The classroom as an integer
 * @return
 *   the classroom as a string
 */
function ks_get_classroom($intclassroom) {

  $classroom = db_query('SELECT room_name FROM {ks_classroom_desc} WHERE kclsr_id = :kclsr_id',
                        array(':kclsr_id' => $intclassroom))->fetchField();
  return $classroom;
}

/**
 * Get all schedule statuses
 *
 * @return
 *    options - an array of statuses
 */
function ks_schedule_period_status_values() {

  $options = array();
  $results = db_query('SELECT kclsss_id, status FROM {ks_class_schedule_status_desc}')->fetchAll();
  foreach ($results as $status) {
    $options[$status->kclsss_id] = $status->status;
  }
  return $options;
}
/**
 * Get all absence types
 *
 * @return
 *    options - an array of absence types
 */
function ks_get_absence_types() {

  $options = array();
  $results = db_query('SELECT kabsty_id, absence_type FROM {ks_absence_type_desc}' )->fetchAll();
  foreach ($results as $type) {
    $options[$type->kabsty_id] = $type->absence_type;
  }
  return $options;
}

/**
 * Get all excused absence reasons
 *
 * @return
 *    options - an array of excused absence reasons
 */
function ks_get_excused_absence_reasons() {

  $options = array();
  $results = db_query('SELECT kexcr_id, excuse_reason FROM {ks_excused_absence_reason_desc}' )->fetchAll();
  foreach ($results as $reason) {
    $options[$reason->kexcr_id] = $reason->excuse_reason;
  }
  return $options;
}
/**
 * Get all excused absence reasons
 *
 * @return
 *    options - an array of excused absence descriptions
 */
function ks_get_excused_absence_descriptions() {

  $options = array();
  $results = db_query('SELECT kexcr_id, description FROM {ks_excused_absence_reason_desc}' )->fetchAll();
  foreach ($results as $description) {
    $options[$description->kexcr_id] = $description->description;
  }
  return $options;
}
/**
 * Get all excused absence excused
 *
 * @return
 *    options - an array of excused absence excused
 */
function ks_get_excused_absence_excused() {

  $options = array();
  $results = db_query('SELECT kexcr_id, excused FROM {ks_excused_absence_reason_desc}' )->fetchAll();
  foreach ($results as $excused) {
    $options[$excused->kexcr_id] = $excused->excused;
  }
  return $options;
}
/**
 * Retrieve the schedule_period_status as a string
 *
 * @param $intstatus
 *   The period_status as an integer
 * @return
 *   the period_status as a string
 */
function get_schedule_period_status($intstatus) {

  $status = db_query('SELECT status FROM {ks_class_schedule_status_desc} WHERE kclsss_id = :kclsss_id',
                        array(':kclsss_id' => $intstatus))->fetchField();
  return $status;
}

/**
 *
 * get term startdate and enddate for an academic year
 *
 * @param $academic_year
 * @param $term
 * @return
 *    an array of two values: term_startdate and term_enddate
 */
function ks_get_acy_term_dates($academic_year, $term) {

    // get termcount
  $termcount = 6;
  $rec = db_query('SELECT * FROM {ks_academic_year_desc} LIMIT 1' )->fetchAll();
  if (empty($rec[0]->term1_enddate)) {
    $termcount = 0;
  }
  elseif (empty($rec[0]->term2_enddate)) {
    $termcount = 1;
  }
  elseif (empty($rec[0]->term3_enddate)) {
    $termcount = 2;
  }
  elseif (empty($rec[0]->term4_enddate)) {
    $termcount = 3;
  }
  elseif (empty($rec[0]->term5_enddate)) {
    $termcount = 4;
  }
  elseif (empty($rec[0]->term6_enddate)) {
    $termcount = 5;
  }

  $term_startdate =  ($term == 'fy') ? 'term1' . '_startdate' : 'term' . $term . '_startdate';
  $term_enddate =  ($term == 'fy') ? 'term' . $termcount . '_enddate' : 'term' . $term . '_enddate';

  $query = db_select('ks_academic_year_desc', 'kacy');
  $query->addField('kacy', $term_startdate);
  $query->addField('kacy', $term_enddate);

  $query->condition('academic_year', $academic_year, '=');
  $result = $query->execute()->fetch(PDO::FETCH_ASSOC);

  $term_daterange = array($result[$term_startdate], $result[$term_enddate]);

  return $term_daterange;
}

/**
 * Retrieve the english level as a string
 *
 * @param $intenglishlevel
 *   The english level as an integer
 * @return
 *   the english level as a string
 */
function get_english_level_desc($intenglishlevel) {

  $english_level = db_query('SELECT english_level FROM {ks_english_level_desc} WHERE kelvl_id = :kelvl_id',
                        array(':kelvl_id' => $intenglishlevel))->fetchField();
  return $english_level;
}

/**
 * Get all english levels
 *
 * @return
 *    options - an array of english levels
 */
function get_english_levels() {

  $options = array();
  $results = db_query('SELECT kelvl_id, english_level FROM {ks_english_level_desc}' )->fetchAll();
  foreach ($results as $english_level) {
    $options[$english_level->kelvl_id] = $english_level->english_level;
  }
  return $options;
}
/**
 * Retrieve the transportation type as a string
 *
 * @param $inttransportation
 *   The transportation type as an integer
 * @return
 *   the transportation type as a string
 */
function get_transportation_type_desc($inttransportation) {

  $transportation = db_query('SELECT transportation FROM {ks_transportation_desc} WHERE ktrns_id = :ktrns_id',
                        array(':ktrns_id' => $inttransportation))->fetchField();
  return $transportation;
}

/**
 * Get all transportation types
 *
 * @return
 *    options - an array of transportation types
 */
function get_transportation_types() {

  $options = array();
  $results = db_query('SELECT ktrns_id, transportation FROM {ks_transportation_desc}' )->fetchAll();
  foreach ($results as $transportation_type) {
    $options[$transportation_type->ktrns_id] = $transportation_type->transportation;
  }
  return $options;
}

/**
 *
 * get a student user record from the ks_students custom table
 *
 * @param $drupaluserid
 *    is the drupal uid. exists as drp_uid_fk in either table
 * @return
 *    a single user record as an associative array
 */
function ks_get_student_record($drupaluserid) {

  $query = db_select('ks_students', 'ksuser');
  $query->addField('ksuser', 'kstu_id');
  $query->addField('ksuser', 'drp_uid_fk');
  $query->addField('ksuser', 'mdl_uid_fk');
//  $query->addField('ksuser', 'parent_grd_id_fk');
//  $query->addField('ksuser', 'medical_rcds_id_fk');
//  $query->addField('ksuser', 'scholarship_id_fk');
//  $query->addField('ksuser', 'boarding_id_fk');
  $query->addField('ksuser', 'identity_id');
  $query->addField('ksuser', 'reg_no');
  $query->addField('ksuser', 'fullname');
  $query->addField('ksuser', 'familyname');
  $query->addField('ksuser', 'friendlyname');
  $query->addField('ksuser', 'fullname_t');
  $query->addField('ksuser', 'familyname_t');
  $query->addField('ksuser', 'friendlyname_t');
  $query->addField('ksuser', 'gender');
  $query->addField('ksuser', 'religion');
  $query->addField('ksuser', 'date_of_birth');
  $query->addField('ksuser', 'nationality');
  $query->addField('ksuser', 'language_at_home');
  $query->addField('ksuser', 'mobile_phone');
  $query->addField('ksuser', 'home_phone');
  $query->addField('ksuser', 'other_phone_1');
  $query->addField('ksuser', 'other_phone_2');
  $query->addField('ksuser', 'address_1');
  $query->addField('ksuser', 'address_2');
  $query->addField('ksuser', 'address_3');
  $query->addField('ksuser', 'address_city');
  $query->addField('ksuser', 'address_region_state');
  $query->addField('ksuser', 'address_province');
  $query->addField('ksuser', 'address_country');
  $query->addField('ksuser', 'address_zip_postalcode');
  $query->addField('ksuser', 'living_with');
  $query->addField('ksuser', 'passport_no');
  $query->addField('ksuser', 'passport_expiry_dt');
  $query->addField('ksuser', 'passport_place_of_issue');
  $query->addField('ksuser', 'curr_status');
  $query->addField('ksuser', 'curr_gradelevel');
  $query->addField('ksuser', 'curr_main_program');
  $query->addField('ksuser', 'curr_other_program');
  $query->addField('ksuser', 'curr_campus');
  $query->addField('ksuser', 'curr_other');
  $query->addField('ksuser', 'application_date');
  $query->addField('ksuser', 'application_forms_signed');
  $query->addField('ksuser', 'anticipated_start_date');
  $query->addField('ksuser', 'acceptance_date');
  $query->addField('ksuser', 'graduation_date');
  $query->addField('ksuser', 'entrance_exam_date');
  $query->addField('ksuser', 'entrance_exam_results');
  $query->addField('ksuser', 'english_level_at_acceptance');
  $query->addField('ksuser', 'special_needs');
  $query->addField('ksuser', 'transportation');
  $query->addField('ksuser', 'website');
  $query->addField('ksuser', 'remarks');

  $query->condition('drp_uid_fk', $drupaluserid, '=');
  $result = $query->execute()->fetch(PDO::FETCH_ASSOC);

  return $result;
}
/**
 *
 * update a student user record in the ks_students custom table
 *
 * @param &$edit
 *    contains all the form field values from the student_edit_form
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_student_record(&$edit) {

  $dob = new DateTime();
  $pped = new DateTime();
  $appd = new DateTime();
  $asd = new DateTime();
  $accd = new DateTime();
  $grdd = new DateTime();
  $eexd = new DateTime();
  $dob->setDate($edit['date_of_birth']['year'], $edit['date_of_birth']['month'], $edit['date_of_birth']['day']);
  $pped->setDate($edit['passport_expiry_dt']['year'], $edit['passport_expiry_dt']['month'], $edit['passport_expiry_dt']['day']);
  $appd->setDate($edit['application_date']['year'], $edit['application_date']['month'], $edit['application_date']['day']);
  $asd->setDate($edit['anticipated_start_date']['year'], $edit['anticipated_start_date']['month'], $edit['anticipated_start_date']['day']);
  $accd->setDate($edit['acceptance_date']['year'], $edit['acceptance_date']['month'], $edit['acceptance_date']['day']);
  $grdd->setDate($edit['graduation_date']['year'], $edit['graduation_date']['month'], $edit['graduation_date']['day']);
  $eexd->setDate($edit['entrance_exam_date']['year'], $edit['entrance_exam_date']['month'], $edit['entrance_exam_date']['day']);

//dpm($edit);
  $cnt = db_update('ks_students')
         ->condition('drp_uid_fk', $edit['original']->uid)
         ->fields(array('identity_id' => $edit['identity_id'],
                        'reg_no' => $edit['reg_no'],
                        'fullname' => $edit['fullname'],
                        'familyname' => $edit['familyname'],
                        'friendlyname' => $edit['std_friendlyname'],
//                        'fullname_t' => $edit['fullname_t'],
//                        'familyname_t' => $edit['familyname_t'],
//                        'friendlyname_t' => $edit['friendlyname_t'],
                        'gender' => $edit['gender'],
                        'religion' => $edit['religion'],
                        'date_of_birth' => $dob->format('Y-m-d'),
//                        'nationality' => $edit['nationality'],
                        'nationality' => $edit['std_nationality'],
                        'language_at_home' => $edit['language_at_home'],
                        'mobile_phone' => $edit['mobile_phone'],
                        'home_phone' => $edit['home_phone'],
                        'other_phone_1' => $edit['other_phone_1'],
 //                       'other_phone_2' => $edit['other_phone_2'],
                        'address_1' => $edit['address_1'],
                        'address_2' => $edit['address_2'],
                        'address_3' => $edit['address_3'],
                        'address_city' => $edit['address_city'],
                        'address_region_state' => $edit['address_region_state'],
                        'address_province' => $edit['address_province'],
                        'address_country' => $edit['address_country'],
                        'address_zip_postalcode' => $edit['address_zip_postalcode'],
                        'living_with' => $edit['living_with'],
                        'passport_no' => $edit['passport_no'],
                        'passport_expiry_dt' => $pped->format('Y-m-d'),
                        'passport_place_of_issue' => $edit['passport_place_of_issue'],
                        'curr_status' => $edit['curr_status'],
                        'curr_gradelevel' => $edit['curr_gradelevel'],
                        'curr_main_program' => $edit['curr_main_program'],
                        'curr_other_program' => $edit['curr_other_program'],
                        'curr_campus' => $edit['curr_campus'],
//                        'curr_other' => $edit['curr_other'],
                        'application_date' => $appd->format('Y-m-d'),
                        'application_forms_signed' => $edit['application_forms_signed'][1],
                        'anticipated_start_date' => $asd->format('Y-m-d'),
                        'acceptance_date' => $accd->format('Y-m-d'),
                        'graduation_date' => $grdd->format('Y-m-d'),
                        'entrance_exam_date' => $eexd->format('Y-m-d'),
                        'entrance_exam_results' => $edit['entrance_exam_results'],
                        'english_level_at_acceptance' => $edit['english_level_at_acceptance'],
                        'special_needs' => $edit['special_needs'],
                        'transportation' => $edit['transportation'],
                        'website' => $edit['website'],
                        'remarks' => $edit['remarks'] ) )
          ->execute();

  return $cnt;
}
/**
 *
 * insert a user record in either the ks_students or ks_users custom table
 *
 * @param $ks_usertype
 *    ks_student, ks_parent_guardian, ks_instructor, ks_staff, or ks_guest (as a string)
 * @param $drp_uid
 *    the Drupal uid
 * @param $mdl_uid
 *    the Moodle uid
 * @return
 *    $cnt - the count of records inserted
 */
function ks_insert_user_record($ks_usertype, $drp_uid, $mdl_uid) {

  if ($ks_usertype == 'ks_student') {
      $cnt = db_insert('ks_students')
          ->fields(array('drp_uid_fk' => $drp_uid,
                          'mdl_uid_fk' => $mdl_uid) )
          ->execute();
  }
  else {
     $intusertype = get_usertype_str_desc($ks_usertype);
     if ( empty($intusertype) ) {
       drupal_set_message(t('User type not found - please check proper role setting.'));
       return 0;
     }
    $cnt = db_insert('ks_users')
        ->fields(array('drp_uid_fk' => $drp_uid,
                        'mdl_uid_fk' => $mdl_uid,
                        'usertype' => $intusertype) )
        ->execute();
    }
    return $cnt;
}

/**
 *
 * get a instructor user record from the ks_users custom table
 *
 * @param $drupaluserid
 *    is the drupal uid. exists as drp_uid_fk in either table
 * @return
 *    a single user record as an associative array
 */
function ks_get_instructor_record($drupaluserid) {

  $query = db_select('ks_users', 'ksuser');
  $query->addField('ksuser', 'ksu_id');
  $query->addField('ksuser', 'drp_uid_fk');
  $query->addField('ksuser', 'mdl_uid_fk');
//  $query->addField('ksuser', 'kstu_id_fk');
  $query->addField('ksuser', 'usertype');
  $query->addField('ksuser', 'identity_id');
  $query->addField('ksuser', 'relationship');
  $query->addField('ksuser', 'fullname');
  $query->addField('ksuser', 'familyname');
  $query->addField('ksuser', 'friendlyname');
  $query->addField('ksuser', 'fullname_t');
  $query->addField('ksuser', 'familyname_t');
  $query->addField('ksuser', 'friendlyname_t');
  $query->addField('ksuser', 'nationality');
  $query->addField('ksuser', 'occupation');
  $query->addField('ksuser', 'mobile_phone');
  $query->addField('ksuser', 'home_phone');
  $query->addField('ksuser', 'office_phone');
  $query->addField('ksuser', 'other_phone');
  $query->addField('ksuser', 'address_1');
  $query->addField('ksuser', 'address_2');
  $query->addField('ksuser', 'address_3');
  $query->addField('ksuser', 'address_city');
  $query->addField('ksuser', 'address_region_state');
  $query->addField('ksuser', 'address_province');
  $query->addField('ksuser', 'address_country');
  $query->addField('ksuser', 'address_zip_postalcode');
  $query->addField('ksuser', 'curr_status');
  $query->addField('ksuser', 'began_date');
  $query->addField('ksuser', 'end_date');
  $query->addField('ksuser', 'remarks');
  $query->condition('drp_uid_fk', $drupaluserid, '=');
  $result = $query->execute()->fetch(PDO::FETCH_ASSOC);

  return $result;
}
/**
 *
 * update an instructor user record in the ks_users custom table
 *
 * @param &$edit
 *    contains all the form field values from the instructor_edit_form
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_instructor_record(&$edit) {

  $bgnd = new DateTime();
  $endd = new DateTime();
  $bgnd->setDate($edit['began_date']['year'], $edit['began_date']['month'], $edit['began_date']['day']);
  $endd->setDate($edit['end_date']['year'], $edit['end_date']['month'], $edit['end_date']['day']);

$cnt = db_update('ks_users')
          ->condition('drp_uid_fk', $edit['original']->uid)
          ->condition('usertype', 1)
          ->fields(array(//'kstu_id_fk' => $edit['kstu_id_fk'],
                        'identity_id' => $edit['identity_id'],
                        'fullname' => $edit['fullname'],
                        'familyname' => $edit['familyname'],
                        'friendlyname' => $edit['instr_friendlyname'],
//                        'fullname_t' => $edit['fullname_t'],
//                        'familyname_t' => $edit['familyname_t'],
//                        'friendlyname_t' => $edit['friendlyname_t'],
                        'nationality' => $edit['instr_nationality'],
                        'occupation' => $edit['occupation'],
                        'mobile_phone' => $edit['mobile_phone'],
                        'home_phone' => $edit['home_phone'],
                        'office_phone' => $edit['office_phone'],
                        'other_phone' => $edit['other_phone'],
                        'address_1' => $edit['address_1'],
                        'address_2' => $edit['address_2'],
                        'address_3' => $edit['address_3'],
                        'address_city' => $edit['address_city'],
                        'address_region_state' => $edit['address_region_state'],
                        'address_province' => $edit['address_province'],
                        'address_country' => $edit['address_country'],
                        'address_zip_postalcode' => $edit['address_zip_postalcode'],
                        'curr_status' => $edit['curr_status'],
                        'began_date' => $bgnd->format('Y-m-d'),
                        'end_date' => $endd->format('Y-m-d'),
                        'remarks' => $edit['remarks'] ) )
          ->execute();

  return $cnt;
}
/**
 *
 * get a parent_guardian user record from the ks_users custom table
 *
 * @param $drupaluserid
 *    is the drupal uid. exists as drp_uid_fk in either table
 * @return
 *    a single user record as an associative array
 */
function ks_get_parent_guardian_record($drupaluserid) {

  $query = db_select('ks_users', 'ksuser');
  $query->addField('ksuser', 'ksu_id');
  $query->addField('ksuser', 'drp_uid_fk');
  $query->addField('ksuser', 'mdl_uid_fk');
//  $query->addField('ksuser', 'kstu_id_fk');
  $query->addField('ksuser', 'usertype');
  $query->addField('ksuser', 'identity_id');
  $query->addField('ksuser', 'relationship');
  $query->addField('ksuser', 'fullname');
  $query->addField('ksuser', 'familyname');
  $query->addField('ksuser', 'friendlyname');
  $query->addField('ksuser', 'fullname_t');
  $query->addField('ksuser', 'familyname_t');
  $query->addField('ksuser', 'friendlyname_t');
  $query->addField('ksuser', 'nationality');
  $query->addField('ksuser', 'occupation');
  $query->addField('ksuser', 'mobile_phone');
  $query->addField('ksuser', 'home_phone');
  $query->addField('ksuser', 'office_phone');
  $query->addField('ksuser', 'other_phone');
  $query->addField('ksuser', 'address_1');
  $query->addField('ksuser', 'address_2');
  $query->addField('ksuser', 'address_3');
  $query->addField('ksuser', 'address_city');
  $query->addField('ksuser', 'address_region_state');
  $query->addField('ksuser', 'address_province');
  $query->addField('ksuser', 'address_country');
  $query->addField('ksuser', 'address_zip_postalcode');
  $query->addField('ksuser', 'curr_status');
  $query->addField('ksuser', 'began_date');
  $query->addField('ksuser', 'end_date');
  $query->addField('ksuser', 'remarks');
  $query->condition('drp_uid_fk', $drupaluserid, '=');
  $result = $query->execute()->fetch(PDO::FETCH_ASSOC);

  return $result;
}
/**
 *
 * update a parent-guardian user record in the ks_users custom table
 *
 * @param &$edit
 *    contains all the form field values from the parent_guardian_edit_form
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_parent_guardian_record(&$edit) {

  $bgnd = new DateTime();
  $endd = new DateTime();
  $bgnd->setDate($edit['began_date']['year'], $edit['began_date']['month'], $edit['began_date']['day']);
  $endd->setDate($edit['end_date']['year'], $edit['end_date']['month'], $edit['end_date']['day']);

//dpm($edit);
   $cnt = db_update('ks_users')
          ->condition('drp_uid_fk', $edit['original']->uid)
          ->condition('usertype', 2)
          ->fields(array(//'kstu_id_fk' => $edit['kstu_id_fk'],
                        'identity_id' => $edit['identity_id'],
                        'fullname' => $edit['fullname'],
                        'familyname' => $edit['familyname'],
                        'friendlyname' => $edit['pgrd_friendlyname'],
//                        'fullname_t' => $edit['fullname_t'],
//                        'familyname_t' => $edit['familyname_t'],
//                        'friendlyname_t' => $edit['friendlyname_t'],
                        'nationality' => $edit['pgrd_nationality'],
                        'occupation' => $edit['occupation'],
                        'mobile_phone' => $edit['mobile_phone'],
                        'home_phone' => $edit['home_phone'],
                        'office_phone' => $edit['office_phone'],
                        'other_phone' => $edit['other_phone'],
                        'address_1' => $edit['address_1'],
                        'address_2' => $edit['address_2'],
                        'address_3' => $edit['address_3'],
                        'address_city' => $edit['address_city'],
                        'address_region_state' => $edit['address_region_state'],
                        'address_province' => $edit['address_province'],
                        'address_country' => $edit['address_country'],
                        'address_zip_postalcode' => $edit['address_zip_postalcode'],
                        'curr_status' => $edit['curr_status'],
                        'began_date' => $bgnd->format('Y-m-d'),
                        'end_date' => $endd->format('Y-m-d'),
                        'remarks' => $edit['remarks'] ) )
          ->execute();

  return $cnt;
}

/**
 *
 * update the Moodle id in a custom table (mdl_uid_fk)
 *
 * @param $ks_usertype
 *    the type of user (as a string)
 * @param $dpl_uid
 *    the Drupal uid
 * @param $mdl_uid
 *    the Moodle uid
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_moodle_uid($ks_usertype, $dpl_uid, $mdl_uid) {

    if ($ks_usertype == 'ks_student') {
      $cnt = db_update('ks_students')
          ->condition('drp_uid_fk', $dpl_uid)
          ->fields(array('mdl_uid_fk' => $mdl_uid ) )
          ->execute();
    }
    else {
      $cnt = db_update('ks_users')
          ->condition('drp_uid_fk', $dpl_uid)
          ->fields(array('mdl_uid_fk' => $mdl_uid ) )
          ->execute();
    }
  return $cnt;
}
/**
 *
 * check if the user record exists in either the ks_students or ks_users custom table
 *
 * @param $ks_usertype
 *    ks_student, ks_instructor, ks_parent_guardian (as a string)
 * @param $drp_uid
 *    the Drupal uid and Moodle uid
 * @return
 *    $ks_usertype - empty if not exists
 */
function ks_check_exists_userrecord($ks_usertype, $drp_uid ) {

  if ($ks_usertype == 'ks_student') {
    $query = db_select('ks_students', 'ksuser');
    $query->addField('ksuser', 'drp_uid_fk');
    $query->addField('ksuser', 'mdl_uid_fk');
    $query->condition('drp_uid_fk', $drp_uid, '=');
    $result = $query->execute()->fetch(PDO::FETCH_ASSOC);
  }
  elseif ($ks_usertype == 'ks_instructor') {
    $query = db_select('ks_users', 'ksuser');
    $query->addField('ksuser', 'drp_uid_fk');
    $query->addField('ksuser', 'mdl_uid_fk');
    $query->condition('drp_uid_fk', $drp_uid, '=');
    $query->condition('usertype', 1, '=');
    $result = $query->execute()->fetch(PDO::FETCH_ASSOC);
  }
  elseif ($ks_usertype == 'ks_parent_guardian') {
    $query = db_select('ks_users', 'ksuser');
    $query->addField('ksuser', 'drp_uid_fk');
    $query->addField('ksuser', 'mdl_uid_fk');
    $query->condition('drp_uid_fk', $drp_uid, '=');
    $query->condition('usertype', 2, '=');
    $result = $query->execute()->fetch(PDO::FETCH_ASSOC);
  }
  elseif ($ks_usertype == 'ks_any') {
    $query = db_select('ks_users', 'ksuser');
    $query->addField('ksuser', 'drp_uid_fk');
    $query->addField('ksuser', 'mdl_uid_fk');
    $query->condition('drp_uid_fk', $drp_uid, '=');
    $result = $query->execute()->fetch(PDO::FETCH_ASSOC);
  }
  else {
    $result = NULL;
  }
  return $result;
}

/**
 *
 * insert a role in the Drupal roles table and return the role id (rid)
 *
 * @param $rolename
 *    Name of the role as a string (must be lowercase)
 * @return
 *    $rid - the role id
 */
function ks_create_new_role($rolename) {

  // check if the role already exists
  $role_exists = db_query('SELECT rid FROM {role} WHERE name = :name',
                            array(':name' => $rolename))->fetchField();
  if ($role_exists > 0) {
    return $role_exists;
  }
  else{
      $weight = db_query('SELECT MAX(weight) FROM {role}' )->fetchField();
      $weight = $weight + 1;
      $ret = db_insert('role')
        ->fields(array('name' => $rolename,
                       'weight' => $weight) )
        ->execute();
      $newroleid = db_query('SELECT rid FROM {role} WHERE name = :name',
                            array(':name' => $rolename))->fetchField();

    return $newroleid;
  }
}

/**
 *
 * assign a new role for an existing Drupal user
 *
 * @param $drupaluserid
 *    the Drupal uid
 * @param $rolename
 *    Name of the role as a string (must be lowercase)
 * @return
 *    zippo
 */
function ks_assign_new_role_($drupaluserid, $rolename) {

  // check if the role exists, otherwise create it
  $role_id = ks_create_new_role($rolename);

  // check if the user already has the role
  $theuser = user_load($drupaluserid);
  if ( !(in_array($rolename, $theuser->roles))  ) {
  // assign the role to the user
   $ret = db_insert('users_roles')
          ->fields(array('uid' => $drupaluserid,
                         'rid' => $role_id ) )
          ->execute();
  }
}

/**
 *
 * copy a students record to the ks_users custom table
 *
 * @param $ks_student_id
 *    Drupal id of the student
 * @param $ks_usertype
 *    the usertype for the ks_user record
 * @return
 *    $cnt - the count of records inserted
 */
function ks_copy_ks_student_to_ks_user($ks_student_id, $ks_usertype) {

  $intusertype = get_usertype_str_desc($ks_usertype);
//   if( empty($intusertype) ) {
//     drupal_set_message('User type not found - please check proper role setting.');
//     return 0;
//   }

  $ks_student = ks_get_student_record($ks_student_id);  // todo: error checking...
//dpm($ks_student);
    $cnt = db_insert('ks_users')
        ->fields(array('drp_uid_fk' => $ks_student['drp_uid_fk'],
                        'mdl_uid_fk' => $ks_student['mdl_uid_fk'],
                        'usertype' => $intusertype,
                        'identity_id' => $ks_student['identity_id'],
                        'fullname' => $ks_student['fullname'],
                        'familyname' => $ks_student['familyname'],
                        'friendlyname' => $ks_student['friendlyname'],
                        'fullname_t' => $ks_student['fullname_t'],
                        'familyname_t' => $ks_student['familyname_t'],
                        'friendlyname_t' => $ks_student['friendlyname_t'],
                        'nationality' => $ks_student['nationality'],
                        'mobile_phone' => $ks_student['mobile_phone'],
                        'home_phone' => $ks_student['home_phone'],
                        'office_phone' => $ks_student['other_phone_1'],
                        'other_phone' => $ks_student['other_phone_2'],
                        'address_1' => $ks_student['address_1'],
                        'address_2' => $ks_student['address_2'],
                        'address_3' => $ks_student['address_3'],
                        'address_city' => $ks_student['address_city'],
                        'address_region_state' => $ks_student['address_region_state'],
                        'address_province' => $ks_student['address_province'],
                        'address_country' => $ks_student['address_country'],
                        'address_zip_postalcode' => $ks_student['address_zip_postalcode'],
                        'remarks' => t('Record created via role assign - biodata update needed.')) )
        ->execute();

    return $cnt;
}

/**
 *
 * copy a users record to the ks_students custom table
 *
 * @param $ks_user_id
 *    Drupal id of the user
 * @return
 *    $cnt - the count of records inserted
 */
function ks_copy_ks_user_to_ks_student($ks_user_id, $ks_usertype) {

  if ($ks_usertype == 'ks_instructor') {
    $ks_user = ks_get_instructor_record($ks_user_id);  // todo: error checking...
  }
  elseif ($ks_usertype == 'ks_parent_guardian') {
    $ks_user = ks_get_parent_guardian_record($ks_user_id);  // todo: error checking...
  }
  else {
    return FALSE;
  }
//dpm($ks_user);
    $cnt = db_insert('ks_students')
        ->fields(array('drp_uid_fk' => $ks_user['drp_uid_fk'],
                        'mdl_uid_fk' => $ks_user['mdl_uid_fk'],
                        'identity_id' => $ks_user['identity_id'],
                        'fullname' => $ks_user['fullname'],
                        'familyname' => $ks_user['familyname'],
                        'friendlyname' => $ks_user['friendlyname'],
                        'fullname_t' => $ks_user['fullname_t'],
                        'familyname_t' => $ks_user['familyname_t'],
                        'friendlyname_t' => $ks_user['friendlyname_t'],
                        'nationality' => $ks_user['nationality'],
                        'mobile_phone' => $ks_user['mobile_phone'],
                        'home_phone' => $ks_user['home_phone'],
                        'other_phone_1' => $ks_user['office_phone'],
                        'other_phone_2' => $ks_user['other_phone'],
                        'address_1' => $ks_user['address_1'],
                        'address_2' => $ks_user['address_2'],
                        'address_3' => $ks_user['address_3'],
                        'address_city' => $ks_user['address_city'],
                        'address_region_state' => $ks_user['address_region_state'],
                        'address_province' => $ks_user['address_province'],
                        'address_country' => $ks_user['address_country'],
                        'address_zip_postalcode' => $ks_user['address_zip_postalcode'],
                        'remarks' => t('Record created via role assign - biodata update needed.')) )
        ->execute();

    return $cnt;
}


/**
 *
 * copy a users record from ks_user custom tableto the ks_user custom table
 *
 * @param $ks_user_id
 *    Drupal id of the user
 * @param $to_ks_usertype
 *    ks usertype for the new record
 * @return
 *    $cnt - the count of records inserted
 */
function ks_copy_ks_user_to_ks_user($ks_user_id, $to_ks_usertype) {

  if ($to_ks_usertype == 'ks_parent_guardian') {
    $ks_user = ks_get_instructor_record($ks_user_id);  // todo: error checking...
  }
  elseif ($to_ks_usertype == 'ks_instructor') {
    $ks_user = ks_get_parent_guardian_record($ks_user_id);  // todo: error checking...
  }
  else {
    return FALSE;
  }
  $ks_usertype_int = get_usertype_str_desc($to_ks_usertype);
//dpm($ks_user);
    $cnt = db_insert('ks_users')
        ->fields(array('drp_uid_fk' => $ks_user['drp_uid_fk'],
                        'mdl_uid_fk' => $ks_user['mdl_uid_fk'],
                        'identity_id' => $ks_user['identity_id'],
                        'usertype' => $ks_usertype_int,
                        'fullname' => $ks_user['fullname'],
                        'familyname' => $ks_user['familyname'],
                        'friendlyname' => $ks_user['friendlyname'],
                        'fullname_t' => $ks_user['fullname_t'],
                        'familyname_t' => $ks_user['familyname_t'],
                        'friendlyname_t' => $ks_user['friendlyname_t'],
                        'nationality' => $ks_user['nationality'],
                        'occupation' => $ks_user['occupation'],
                        'mobile_phone' => $ks_user['mobile_phone'],
                        'home_phone' => $ks_user['home_phone'],
                        'office_phone' => $ks_user['office_phone'],
                        'other_phone' => $ks_user['other_phone'],
                        'address_1' => $ks_user['address_1'],
                        'address_2' => $ks_user['address_2'],
                        'address_3' => $ks_user['address_3'],
                        'address_city' => $ks_user['address_city'],
                        'address_region_state' => $ks_user['address_region_state'],
                        'address_province' => $ks_user['address_province'],
                        'address_country' => $ks_user['address_country'],
                        'address_zip_postalcode' => $ks_user['address_zip_postalcode'],
                        'remarks' => t('Record created via role assign - biodata update needed.')) )
        ->execute();

    return $cnt;
}

/**
 *
 * get enrolment record(s) from the ks_student_course_classes table
 *
 * @param $drupaluserid
 *    is the drupal uid
 * @return
 *    an array of enrollment records that match the criteria as associative arrays
 */
function ks_get_enroll_records($drupaluserid, $unenroll_is_null = TRUE, $class_id = '', $enrol_date = '') {

  $query = db_select('ks_student_course_classes', 'ksenr');
  $query->addField('ksenr', 'ksccl_id');
  $query->addField('ksenr', 'kstu_id_fk');
  $query->addField('ksenr', 'kccls_id_fk');
  $query->addField('ksenr', 'ib_level');
  $query->addField('ksenr', 'class_auth');
  $query->addField('ksenr', 'enrol_status');
  $query->addField('ksenr', 'enrol_date');
  $query->addField('ksenr', 'unenrol_date');
  $query->addField('ksenr', 'completed');
  $query->addField('ksenr', 'final_grade');
  $query->addField('ksenr', 'final_attendance');
  $query->addField('ksenr', 'final_other');
  $query->addField('ksenr', 'remarks');


  $query->condition('kstu_id_fk', $drupaluserid, '=');
  if ($unenroll_is_null) {
    $query->isNull('unenrol_date');
  }
  else {
    $query->isNotNull('unenrol_date');
  }
  if (!empty($class_id) ) {
    $query->condition('kccls_id_fk', $class_id, '=');
  }
  if (!empty($enrol_date ) ) {
    $query->condition('enrol_date', $enrol_date, '=');
  }
  $result = $query->execute()->fetch(PDO::FETCH_ASSOC);

  return $result;
}

/**
 *
 * insert an enrolment record into the ks_student_course_classes table
 *
 * @param $ks_enroll_record
 *    Enrollment record
 * @return
 *    $cnt - the count of records inserted
 */
function ks_insert_enroll_record($ks_enroll_record) {

  $enrd = new DateTime();
  $uenrd = new DateTime();
  $enrd->setDate($ks_enroll_record['enrol_date']['year'], $ks_enroll_record['enrol_date']['month'], $ks_enroll_record['enrol_date']['day']);
  $uenrd->setDate($ks_enroll_record['unenrol_date']['year'], $ks_enroll_record['unenrol_date']['month'], $ks_enroll_record['unenrol_date']['day']);

  $cnt = db_insert('ks_student_course_classes')
      ->fields(array( 'kstu_id_fk' => $ks_enroll_record['drp_uid'],
                      'kccls_id_fk' => $ks_enroll_record['class_nid'],
                      'ib_level' => $ks_enroll_record['ib_level'],
                      'class_auth' => $ks_enroll_record['class_auth'],
                      'enrol_status' => $ks_enroll_record['enrol_status'],
                      'enrol_date' => $enrd->format('Y-m-d'),
//                      'unenrol_date' => $uenrd->format('Y-m-d'),
                      'completed' => $ks_enroll_record['completed'],
                      'final_grade' => $ks_enroll_record['final_grade'],
                      'final_attendance' => $ks_enroll_record['final_attendance'],
                      'final_other' => $ks_enroll_record['final_other'],
                      'remarks' => $ks_enroll_record['remarks'], ) )
      ->execute();

  return $cnt;
}

/**
 *
 * update an enrolment record in the ks_student_course_classes table
 *
 * @param $ks_enroll_record
 *    Enrollment record
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_enroll_record($ks_enroll_record) {

  $enrd = new DateTime();
  $enrd->setDate($ks_enroll_record['enrol_date']['year'], $ks_enroll_record['enrol_date']['month'], $ks_enroll_record['enrol_date']['day']);
  $uenrd = new DateTime();
  $uenrd->setDate($ks_enroll_record['unenrol_date']['year'], $ks_enroll_record['unenrol_date']['month'], $ks_enroll_record['unenrol_date']['day']);
  if ($ks_enroll_record['unenrol_date']['year'] == '1900') {
    $uenrd = NULL;
  }

  $cnt = db_update('ks_student_course_classes')
      ->condition('ksccl_id', $ks_enroll_record['ksccl_id'])
      ->fields(array('kstu_id_fk' => $ks_enroll_record['drp_uid'],
                      'kccls_id_fk' => $ks_enroll_record['class_nid'],
                      'ib_level' => $ks_enroll_record['ib_level'],
                      'class_auth' => $ks_enroll_record['class_auth'],
                      'enrol_status' => $ks_enroll_record['enrol_status'],
                      'enrol_date' => $enrd->format('Y-m-d'),
                      'unenrol_date' => (isset($uenrd)) ? $uenrd->format('Y-m-d') : NULL,
                      'completed' => $ks_enroll_record['completed'],
                      'final_grade' => $ks_enroll_record['final_grade'],
                      'final_attendance' => $ks_enroll_record['final_attendance'],
                      'final_other' => $ks_enroll_record['final_other'],
                      'remarks' => $ks_enroll_record['remarks'], ) )
      ->execute();

  return $cnt;
}

/**
 *
 * delete an enrolment record from the ks_student_course_classes table
 *
 * @param $primary_key
 *    is the primary_key for the table
 * @return
 *    TRUE is ok, FALSE is not :)
 */
function ks_delete_enroll_record($primary_key) {

  $cnt_deleted = db_delete('ks_student_course_classes')
            ->condition('ksccl_id', $primary_key, '=')
            ->execute();

  return $cnt_deleted;
}

/**
 *
 * get students in a class
 *
 * @param $classid
 *    class id
 * @return
 *    array of students
 */
function ks_get_students_in_a_class($classid) {

  $query = db_select('ks_student_course_classes', 'ksscc');
  $query->innerJoin('users', 'u', 'u.uid = ksscc.kstu_id_fk');
  $query->addField('ksscc', 'kstu_id_fk');
  $query->addField('u', 'name');

  $query->condition('ksscc.' . 'kccls_id_fk', $classid, '=');
  $query->isNull('unenrol_date');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  $results = $query->execute()->fetchAll();

  return $results;
}

/**
 *
 * get period schedule records from the ks_class_schedule table
 *
 * @param $instructorid
 *    instructor id
 * @param $academic_year
 *    academic_year
 * @param $term
 *    term
 * @return
 *    array of schedule records
 */

// Note: this function has been superceded by ks_get_attendance_schedule_records() - plan to rewrite for period attendance feature
/*
function ks_get_schedule_records($instructorid, $academic_year, $term, $day = 0) {

if (($academic_year == 'all') || ($term == 'all') ) {
  return NULL;
}
$daterange = ks_get_acy_term_dates($academic_year, $term);

$startdate = $daterange[0];
$enddate = $daterange[1];

  $query = db_select('ks_class_schedule', 'ksclss');
//  $query->innerJoin('node', 'n', 'n.nid = ksclss.kccls_id_fk');
//  $query->innerJoin('ks_class_schedule_status_desc', 'ksclsss', 'ksclss.period_status = ksclsss.kclsss_id');
//  $query->addField('n', 'title');
  $query->addField('ksclss', 'kclss_id');
  $query->addField('ksclss', 'kccls_id_fk');
  $query->addField('ksclss', 'period_start_datetime');  // M-D-Y part is the class start date
  $query->addField('ksclss', 'period_end_datetime');    // M-D-Y part is also the class start date
  $query->addField('ksclss', 'period_day');             // Day of the week (ISO-8601)
  $query->addField('ksclss', 'period_hour');            // not currently used
  $query->addField('ksclss', 'period_length');          // not currently used
  $query->addField('ksclss', 'period_status');
  $query->addField('ksclss', 'classroom');
  $query->addField('ksclss', 'period_lead');

  $query->condition('ksclss.' . 'period_lead', $instructorid, '=');
  $query->condition('ksclss.' . 'period_start_datetime', $daterange, 'BETWEEN');
  if($day) {
    $query->condition('ksclss.' . 'period_day', $day, '=');
  }

//  $query->orderBy('ksclss.period_day', 'ASC');
//  $query->orderBy('ksclss.period_start_datetime', 'ASC');

  $schedule_records = $query->execute()->fetchAll();

  return $schedule_records;
}
*/
/**
 *
 * get daily attendance schedule records from the ks_class_schedule table
 *
 * @param $instructorid
 *    instructor id
 * @param $academic_year
 *    academic_year
 * @param $term
 *    term
 * @return
 *    array of schedule records
 */
function ks_get_attendance_schedule_records($instructorid, $academic_year, $term, $day = 0) {

  if (($academic_year == 'all') || ($term == 'all') ) {
    return NULL;
  }
  $daterange = ks_get_acy_term_dates($academic_year, $term);

  $startdate = $daterange[0];
  $enddate = $daterange[1];

  /* first, get Courses with course_type 'Attendance' */
  $attnda = array_keys(ks_get_course_types(), 'Attendance');  // get the Attendance course key

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'course')
//  ->fieldCondition('ks_course_type', 'value', '4', '='); // todo: get the actual value for 'Attendance' from the ks_course_type_description table
  ->fieldCondition('ks_course_type', 'value', $attnda[0], '=');

  $result = $query->execute();

  $nids_courses = array(0);

  if ( !empty($result) ) {
    $nids_courses = array_keys($result['node']);  // these nids will be used to filter the following query:
  }

  /* then, get Classes referenced to Courses with course_type 'attendance' */
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_course_ref', 'nid', $nids_courses, 'IN', 0)
  ->propertyCondition('status', 1);  // not needed, just an example...

  $result = $query->execute();

  $nids_classes = array(0);
  if ( !empty($result) ) {
    $nids_classes = array_keys($result['node']);  // these nids will be used to filter the following query:
  }

  /* lastly, get Classes scheduled for the selected instructor, acyt, and day */

  $query = db_select('ks_class_schedule', 'ksclss');
  $query->addField('ksclss', 'kclss_id');
  $query->addField('ksclss', 'kccls_id_fk');
  $query->addField('ksclss', 'period_start_datetime');  // M-D-Y part is the class start date
  $query->addField('ksclss', 'period_end_datetime');    // M-D-Y part is also the class start date
  $query->addField('ksclss', 'period_day');             // Day of the week (ISO-8601)
  $query->addField('ksclss', 'period_hour');            // not currently used
  $query->addField('ksclss', 'period_length');          // not currently used
  $query->addField('ksclss', 'period_status');
  $query->addField('ksclss', 'classroom');
  $query->addField('ksclss', 'period_lead');

  $query->condition('ksclss.' . 'period_lead', $instructorid, '=');
  $query->condition('ksclss.' . 'period_start_datetime', $daterange, 'BETWEEN');
  $query->condition('ksclss.' . 'kccls_id_fk', $nids_classes, 'IN');
  if  ($day) {
    $query->condition('ksclss.' . 'period_day', $day, '=');
  }

//  $query->orderBy('ksclss.period_day', 'ASC');
//  $query->orderBy('ksclss.period_start_datetime', 'ASC');

  $schedule_records = $query->execute()->fetchAll();

  return $schedule_records;
}

/**
 *
 * insert a class schedule record into the ks_class_schedule table
 *
 * @param $ks_schedule_record
 *    Schedule record
 * @return
 *    $cnt - the count of records inserted
 */
function ks_insert_schedule_record($ks_schedule_record) {

  $pstartd = new DateTime($ks_schedule_record['period_start_datetime']['year'] . '-' . $ks_schedule_record['period_start_datetime']['month'] . '-' .
  $ks_schedule_record['period_start_datetime']['day'] . ' ' . $ks_schedule_record['period_start_hour'] . ':' .
  $ks_schedule_record['period_start_minute'] . ':' . '00');

  $pendd = new DateTime($ks_schedule_record['period_start_datetime']['year'] . '-' . $ks_schedule_record['period_start_datetime']['month'] . '-' .
  $ks_schedule_record['period_start_datetime']['day'] . ' ' . $ks_schedule_record['period_end_hour'] . ':' .
  $ks_schedule_record['period_end_minute'] . ':' . '00');

  $cnt = db_insert('ks_class_schedule')
      ->fields(array( 'kccls_id_fk' => $ks_schedule_record['kccls_id_fk'],
                      'period_start_datetime' => $pstartd->format('Y-m-d H:i:s'),
                      'period_end_datetime' => $pendd->format('Y-m-d H:i:s'),
                      'period_day' => $ks_schedule_record['period_day'],
                      'period_hour' => 0,   // $ks_schedule_record['period_hour'],
                      'period_length' => 0,   //$ks_schedule_record['period_length'],
                      'period_status' => $ks_schedule_record['period_status'],
                      'classroom' => $ks_schedule_record['classroom'],
                      'period_lead' => $ks_schedule_record['period_lead'], ) )
      ->execute();

  return $cnt;
}

/**
 *
 * update a period schedule record in the ks_class_schedule table
 *
 * @param $ks_schedule_record
 *    Schedule record
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_schedule_record($ks_schedule_record) {

  $pstartd = new DateTime($ks_schedule_record['period_start_datetime']['year'] . '-' . $ks_schedule_record['period_start_datetime']['month'] . '-' .
  $ks_schedule_record['period_start_datetime']['day'] . ' ' . $ks_schedule_record['period_start_hour'] . ':' .
  $ks_schedule_record['period_start_minute'] . ':' . '00');

  $pendd = new DateTime($ks_schedule_record['period_start_datetime']['year'] . '-' . $ks_schedule_record['period_start_datetime']['month'] . '-' .
  $ks_schedule_record['period_start_datetime']['day'] . ' ' . $ks_schedule_record['period_end_hour'] . ':' .
  $ks_schedule_record['period_end_minute'] . ':' . '00');

  $cnt = db_update('ks_class_schedule')
      ->condition('kclss_id', $ks_schedule_record['kclss_id'])
      ->fields(array( 'kccls_id_fk' => $ks_schedule_record['kccls_id_fk'],
                      'period_start_datetime' => $pstartd->format('Y-m-d H:i:s'),
                      'period_end_datetime' => $pendd->format('Y-m-d H:i:s'),
                      'period_day' => $ks_schedule_record['period_day'],
                      'period_hour' => 0,   // $ks_schedule_record['period_hour'],
                      'period_length' => 0,   //$ks_schedule_record['period_length'],
                      'period_status' => $ks_schedule_record['period_status'],
                      'classroom' => $ks_schedule_record['classroom'],
                      'period_lead' => $ks_schedule_record['period_lead'], ) )
      ->execute();

  return $cnt;
}

/**
 *
 * delete a class schedule record from the ks_class_schedule table
 *
 * @param $primary_key
 *    is the primary_key for the table
 * @return
 *    TRUE is ok, FALSE is not :)
 */
function ks_delete_schedule_record($primary_key) {

  $cnt_deleted = db_delete('ks_class_schedule')
            ->condition('kclss_id', $primary_key, '=')
            ->execute();

  return $cnt_deleted;
}


/**
 *
 * get a student attendance record from the ks_student_attendance table
 *
 * @param $studentid
 *    studentid id
 * @param $classid
 *    class id
 * @param $attendance_date
 *    attendance date
 * @return
 *    a student attendance record
 */
function ks_get_attendance_records($studentid, $classid, $attendance_date) {


  $query = db_select('ks_student_attendance', 'ksatnd');
//  $query->innerJoin('node', 'n', 'n.nid = ksclss.kccls_id_fk');
//  $query->innerJoin('ks_class_schedule_status_desc', 'ksclsss', 'ksclss.period_status = ksclsss.kclsss_id');
//  $query->addField('n', 'title');
//  $query->innerJoin('ks_absence_type_desc', 'ksabsty', 'ksatnd.abs_type = ksabsty.kabsty_id');
//  $query->innerJoin('ks_excused_absence_reason_desc', 'ksexcr', 'ksatnd.excuse_reason = ksexcr.kexcr_id');
  $query->addField('ksatnd', 'ksatnd_id');
  $query->addField('ksatnd', 'kstu_id_fk');
  $query->addField('ksatnd', 'kclss_id_fk');
  $query->addField('ksatnd', 'atnd_date');  // $pendd->format('Y-m-d H:i:s'),
  $query->addField('ksatnd', 'period_day');             // Day of the week (ISO-8601)
  $query->addField('ksatnd', 'period_hour');            // not currently used
  $query->addField('ksatnd', 'abs_type');
//  $query->addField('ksabsty', 'absence_type');
  $query->addField('ksatnd', 'excused_abs');
  $query->addField('ksatnd', 'excuse_reason');
//  $query->addField('ksexcr', 'excuse_reason');
  $query->addField('ksatnd', 'remarks_instructor');
  $query->addField('ksatnd', 'remarks_counselor');

  $query->condition('ksatnd.' . 'kstu_id_fk', $studentid, '=');
  $query->condition('ksatnd.' . 'kclss_id_fk', $classid, '=');  // kleosis lite uses the class id here instead of the class schedule id.
                                                                // kleosis campus will use the real kclss_id_fk
  $query->condition('ksatnd.' . 'atnd_date', $attendance_date->format('Y-m-d H:i:s'), '=');

  $attendance_record = $query->execute()->fetch(PDO::FETCH_ASSOC);

return $attendance_record;

}


/**
 *
 * check attendance taken by getting record(s) from the ks_student_attendance table
 *
 * @param $classid
 *    class id
 * @param $attendance_date
 *    attendance date
 * @return
 *    a student attendance record
 */
function ks_get_attendance_taken($classid, $attendance_date) {


  $query = db_select('ks_student_attendance', 'ksatnd');
  $query->addField('ksatnd', 'ksatnd_id');
  $query->addField('ksatnd', 'kstu_id_fk');
  $query->addField('ksatnd', 'kclss_id_fk');
  $query->addField('ksatnd', 'atnd_date');  // $pendd->format('Y-m-d H:i:s'),
  $query->addField('ksatnd', 'period_day');             // Day of the week (ISO-8601)
  $query->addField('ksatnd', 'period_hour');            // not currently used
  $query->addField('ksatnd', 'abs_type');
  $query->addField('ksatnd', 'excused_abs');
  $query->addField('ksatnd', 'excuse_reason');
  $query->addField('ksatnd', 'remarks_instructor');
  $query->addField('ksatnd', 'remarks_counselor');

  $query->condition('ksatnd.' . 'kclss_id_fk', $classid, '=');  // kleosis lite uses the class id here instead of the class schedule id.
                                                                // kleosis campus will use the real kclss_id_fk
  $query->condition('ksatnd.' . 'atnd_date', $attendance_date->format('Y-m-d H:i:s'), '=');

  $attendance_record = $query->execute()->fetch(PDO::FETCH_ASSOC);

return $attendance_record;

}


/**
 *
 * insert an attendance record into the ks_student_attendance table
 *
 * @param $ks_attendance_record
 *    Attendance record
 * @return
 *    $cnt - the count of records inserted
 */
function ks_insert_attendance_record($ks_attendance_record) {

  $cnt = db_insert('ks_student_attendance')
      ->fields(array( 'kstu_id_fk' => $ks_attendance_record['kstu_id_fk'],
                      'kclss_id_fk' => $ks_attendance_record['kclss_id_fk'],
                      'atnd_date' => $ks_attendance_record['atnd_date']->format('Y-m-d H:i:s'),
                      'period_day' => $ks_attendance_record['period_day'],
                      'period_hour' => $ks_attendance_record['period_hour'],
                      'abs_type' => $ks_attendance_record['abs_type'],
                      'excused_abs' => $ks_attendance_record['excused_abs'],
                      'excuse_reason' => $ks_attendance_record['excuse_reason'],
                      'remarks_instructor' => $ks_attendance_record['remarks_instructor'],
                      'remarks_counselor' => $ks_attendance_record['remarks_counselor'], ) )
      ->execute();

  return $cnt;
}

/**
 *
 * update an attendance record in the ks_student_attendance table
 *
 * @param $ks_attendance_record
 *    Attendance record
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_attendance_record($ks_attendance_record) {

  $cnt = db_update('ks_student_attendance')
      ->condition('ksatnd_id', $ks_attendance_record['ksatnd_id'])
      ->fields(array( 'kstu_id_fk' => $ks_attendance_record['kstu_id_fk'],
                      'kclss_id_fk' => $ks_attendance_record['kclss_id_fk'],
                      'atnd_date' => $ks_attendance_record['atnd_date']->format('Y-m-d H:i:s'),
                      'period_day' => $ks_attendance_record['period_day'],
                      'period_hour' => $ks_attendance_record['period_hour'],
                      'abs_type' => $ks_attendance_record['abs_type'],
                      'excused_abs' => $ks_attendance_record['excused_abs'],
                      'excuse_reason' => $ks_attendance_record['excuse_reason'],
                      'remarks_instructor' => $ks_attendance_record['remarks_instructor'],
                      'remarks_counselor' => $ks_attendance_record['remarks_counselor'], ) )
      ->execute();

  return $cnt;

}

/**
 * Get a grade record for a specific student in a specific class
 *
 * @param $studentid
 *    The student id
 * @param $classid
 *    The node id of the specific class
 *
 * @return
 *    Result set containing the student grade record
 */
function kleosis_get_student_final_grade_record($studentid, $classid) {

  $query = db_select('ks_student_course_class_grades', 'ksgrd');
  $query->innerJoin('ks_student_course_classes', 'ksccl', 'ksccl.ksccl_id = ksgrd.ksccl_id_fk');
  $query->innerJoin('users', 'u', 'u.uid = ksccl.kstu_id_fk');
  $query->addField('u', 'uid');
  $query->addField('u', 'name');
  $query->addField('ksgrd', 'kcclg_id');
  $query->addField('ksgrd', 'ksccl_id_fk');
  $query->addField('ksgrd', 'current_grade');
  $query->addField('ksgrd', 'current_grade_str');
  $query->addField('ksgrd', 'final_exam_grade');
  $query->addField('ksgrd', 'final_exam_grade_str');
  $query->addField('ksgrd', 'course_grade');
  $query->addField('ksgrd', 'course_grade_str');
  $query->addField('ksgrd', 'grade_item_1');
  $query->addField('ksgrd', 'grade_item_2');
  $query->addField('ksgrd', 'grade_item_3');
  $query->addField('ksgrd', 'final_grade');
  $query->addField('ksgrd', 'final_grade_str');
  $query->addField('ksgrd', 'remarks');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  // adjust the query according to the filter values (class_id)
  $query->condition('ksccl.' . 'kstu_id_fk', $studentid, '=');
  $query->condition('ksccl.' . 'kccls_id_fk', $classid, '=');

//  $query = $query->extend('PagerDefault')->limit(variable_get('kleosis_pager_rows', 16));
//  $query = $query->extend('TableSort');
//  $query->orderByHeader($header);

  $results = $query->execute()->fetchAll();

  return $results;
}

/**
 *
 * insert an final grade record into the ks_student_course_class_grades table
 *
 * @param $ks_final_grade_record
 *    Final grade record
 * @return
 *    $cnt - the count of records inserted
 */
function ks_insert_final_grade_record($ks_final_grade_record) {

  $cnt = db_insert('ks_student_course_class_grades')
      ->fields(array( 'ksccl_id_fk' => $ks_final_grade_record['ksccl_id_fk'],
//                      'current_grade' => $ks_final_grade_record['current_grade'],
//                      'current_grade_str' => $ks_final_grade_record['current_grade_str'],
//                      'final_exam_grade' => $ks_final_grade_record['final_exam_grade'],
//                      'final_exam_grade_str' => $ks_final_grade_record['final_exam_grade_str'],
//                      'course_grade' => $ks_final_grade_record['course_grade'],
//                      'course_grade_str' => $ks_final_grade_record['course_grade_str'],
//                      'grade_item_1' => $ks_final_grade_record['grade_item_1'],
//                      'grade_item_2' => $ks_final_grade_record['grade_item_2'],
//                      'grade_item_3' => $ks_final_grade_record['grade_item_3'],
                      'final_grade' => $ks_final_grade_record['final_grade'],
                      'final_grade_str' => $ks_final_grade_record['final_grade_str'],
                      'remarks' => $ks_final_grade_record['remarks'], ) )
      ->execute();

  return $cnt;
}

/**
 *
 * update an final grade record in the ks_student_course_class_grades table
 *
 * @param $ks_final_grade_record
 *    Final grade record
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_final_grade_record($ks_final_grade_record) {

  $cnt = db_update('ks_student_course_class_grades')
      ->condition('kcclg_id', $ks_final_grade_record['kcclg_id'])
      ->fields(array( 'ksccl_id_fk' => $ks_final_grade_record['ksccl_id_fk'],
//                      'current_grade' => $ks_final_grade_record['current_grade'],
//                      'current_grade_str' => $ks_final_grade_record['current_grade_str'],
//                      'final_exam_grade' => $ks_final_grade_record['final_exam_grade'],
//                      'final_exam_grade_str' => $ks_final_grade_record['final_exam_grade_str'],
//                      'course_grade' => $ks_final_grade_record['course_grade'],
//                      'course_grade_str' => $ks_final_grade_record['course_grade_str'],
//                      'grade_item_1' => $ks_final_grade_record['grade_item_1'],
//                      'grade_item_2' => $ks_final_grade_record['grade_item_2'],
//                      'grade_item_3' => $ks_final_grade_record['grade_item_3'],
                      'final_grade' => $ks_final_grade_record['final_grade'],
                      'final_grade_str' => $ks_final_grade_record['final_grade_str'],
                      'remarks' => $ks_final_grade_record['remarks'], ) )
      ->execute();

  return $cnt;

}

/**
 *
 * insert an final grade record into the ks_student_course_class_grades table (for LIST)
 *
 * @param $ks_final_grade_record
 *    Final grade record
 * @return
 *    $cnt - the count of records inserted
 */
function ks_insert_final_grade_ls_record($ks_final_grade_record) {

  $cnt = db_insert('ks_student_course_class_grades')
      ->fields(array( 'ksccl_id_fk' => $ks_final_grade_record['ksccl_id_fk'],
//                      'current_grade' => $ks_final_grade_record['current_grade'],
                      'final_exam_grade' => $ks_final_grade_record['final_exam_grade'],
                      'course_grade' => $ks_final_grade_record['course_grade'],
                      'grade_item_1' => $ks_final_grade_record['grade_item_1'],
                      'grade_item_2' => $ks_final_grade_record['grade_item_2'],
                      'grade_item_3' => $ks_final_grade_record['grade_item_3'],
                      'final_grade' => $ks_final_grade_record['final_grade'],
                      'remarks' => $ks_final_grade_record['remarks'], ) )
      ->execute();

  return $cnt;
}

/**
 *
 * update an final grade record in the ks_student_course_class_grades table (for LIST)
 *
 * @param $ks_final_grade_record
 *    Final grade record
 * @return
 *    $cnt - the count of records updated (normally 1, but will be 0 if no changes...
 */
function ks_update_final_grade_ls_record($ks_final_grade_record) {

  $cnt = db_update('ks_student_course_class_grades')
      ->condition('kcclg_id', $ks_final_grade_record['kcclg_id'])
      ->fields(array( 'ksccl_id_fk' => $ks_final_grade_record['ksccl_id_fk'],
//                      'current_grade' => $ks_final_grade_record['current_grade'],
                      'final_exam_grade' => $ks_final_grade_record['final_exam_grade'],
                      'course_grade' => $ks_final_grade_record['course_grade'],
                      'grade_item_1' => $ks_final_grade_record['grade_item_1'],
                      'grade_item_2' => $ks_final_grade_record['grade_item_2'],
                      'grade_item_3' => $ks_final_grade_record['grade_item_3'],
                      'final_grade' => $ks_final_grade_record['final_grade'],
                      'remarks' => $ks_final_grade_record['remarks'], ) )
      ->execute();

  return $cnt;

}

