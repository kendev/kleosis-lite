<?php

/**
 * @file
 *  Provide Views data for the Kleosis module
 *
 *  This file has been updated/rewritten to work with the current schema
 *  as well as Views 3.
 */

/**
 * Implementation of hook_views_handlers().
 */
function kleosis_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'kleosis') . '/includes', // path to view files
    ),
    'handlers' => array(
      // register our custom filter, with the class/file name and parent class
      'views_handler_filter_custom_numeric' => array(
        'parent' => 'views_handler_filter',
      ),
      'views_handler_filter_custom_datetime' => array(
        'parent' => 'views_handler_filter_custom_numeric',
      ),
      'views_handler_argument_custom_numeric' => array(
        'parent' => 'views_handler_argument',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */

function kleosis_views_data() {

  $data = array();

/******************************************************************************
 *                        ks_students table
 ******************************************************************************/

/*  // Define the ks_students table as a base table
    //  not needed as this table joins with the Drupal Users table
  $data['ks_students']['table']['base'] = array(
    'field' => 'kstu_id',
    'title' => t('kleosis Students'),
    'help' => t('kleosis Students defines the ks_students table as a base table'),
  );
*/
  $data['ks_students']['table']['group'] = t('Kleosis');


  // Join to the Drupal users table - this will allow the ks_students fields to
  // appear in Views when using Users as the View type, as well as allowing fields from
  // other custom tables to when joining to this table from other custom tables

  $data['ks_students']['table']['join'] = array(
    'users' => array(
    'left_field' => 'uid',
    'field' => 'drp_uid_fk',
    ),
  );

  $data['ks_students']['kstu_id'] = array(
    'title' => t('ks_students kstu_id'),
    'help' => t('ks_students table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

/*  $data['ks_students']['drp_uid_fk'] = array(
    'title' => t('ks_students: Link to Drupal (Student) Users'),
    'help' => t('Relationship from the ks_students table foreign key (drp_uid_fk) to the Drupal users table primary key (uid).'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  //not needed (yet) as this table is joined with the Drupal users table already.
      'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Drupal User id'),
   ),

  );
*/
  $data['ks_students']['mdl_uid_fk'] = array(
    'title' => t('ks_students mdl_uid_fk'),
    'help' => t('ks_students table: Moodle User uid'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_students']['fullname'] = array(
    'title' => t('ks_students fullname'),
    'help' => t('ks_students table: fullname'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_students']['friendlyname'] = array(
    'title' => t('ks_students friendlyname'),
    'help' => t('ks_students table: friendlyname'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['ks_students']['mobile_phone'] = array(
    'title' => t('ks_students mobile_phone'),
    'help' => t('ks_students table: mobile_phone'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_students']['home_phone'] = array(
    'title' => t('ks_students home_phone'),
    'help' => t('ks_students table: home_phone'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_students']['curr_status'] = array(
    'title' => t('ks_students status'),
    'help' => t('ks_students table: curr_status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),

    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'ks_student_status_desc',
    'base field' => 'ksts_id',
    'label' => t('Student Status'),
    ),
  );


/******************************************************************************
 *                        ks_users table
 ******************************************************************************/
/*
  // Define the ks_users table as a base table
  //  not needed as this table joins with the Drupal Users table

  $data['ks_users']['table']['base'] = array(
    'field' => 'ksu_id',
    'title' => t('kleosis User'),
    'help' => t('kleosis User defines the ks_users table as a base table'),
  );
*/
  $data['ks_users']['table']['group'] = t('Kleosis');

  // Join to the Drupal users table - this will allow the ks_users fields to
  // appear in Views when using Users as the View type, as well as allowing fields from
  // other custom tables to when joining to this table from other custom tables

  $data['ks_users']['table']['join'] = array(
    'users' => array(
    'left_field' => 'uid',
    'field' => 'drp_uid_fk',
    ),
    /* BTW, another table can be joined to from here...
    'another_table' => array(
    'left_field' => 'id',
    'field' => 'userid',
    ),*/
  );

  $data['ks_users']['ksu_id'] = array(
    'title' => t('ks_user ksu_id'),
    'help' => t('ks_users table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

/*
  $data['ks_users']['drp_uid_fk'] = array(
    'title' => t('ks_user: Link to Drupal User'),
    'help' => t('Relationship from the ks_users table foreign key (drp_uid_fk) to the Drupal users table primary key (uid).'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
     'filter' => array(
          'handler' => 'views_handler_filter_numeric',
     ),

  // This relationship will appear when linking to this table from the link table
  // as well as when using this table as the View type
          'relationship' => array(
          'handler' => 'views_handler_relationship',
          'base' => 'users',
          'field' => 'uid',
          'label' => t('Drupal User id'),
        ),
  );
*/
  $data['ks_users']['mdl_uid_fk'] = array(
    'title' => t('ks_user mdl_uid_fk'),
    'help' => t('ks_users table: Moodle User uid'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_users']['fullname'] = array(
    'title' => t('ks_users fullname'),
    'help' => t('ks_users table: fullname'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_users']['friendlyname'] = array(
    'title' => t('ks_users friendlyname'),
    'help' => t('ks_users table: friendlyname'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['ks_users']['mobile_phone'] = array(
    'title' => t('ks_users mobile_phone'),
    'help' => t('ks_users table: mobile_phone'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_users']['office_phone'] = array(
    'title' => t('ks_users office_phone'),
    'help' => t('ks_users table: office_phone'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_users']['curr_status'] = array(
    'title' => t('ks_user status'),
    'help' => t('ks_users table: curr_status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),

    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'ks_instructor_status_desc',
    'base field' => 'kinsts_id',
    'label' => t('Kleosis User Status'),
    ),
  );

  $data['ks_users']['usertype'] = array(
    'title' => t('ks_user usertype'),
    'help' => t('ks_users table: usertype'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

/******************************************************************************
 *                        ks_student_course_classes table
 ******************************************************************************/

  $data['ks_student_course_classes']['table']['group'] = t('Kleosis');

  // Join to the Drupal users table - this will allow the ks_student_course_classes fields to
  // appear in Views when using Users as the View type, as well as allowing fields from
  // other custom tables to when joining to this table from other custom tables

  $data['ks_student_course_classes']['table']['join'] = array(
    'users' => array(
    'left_field' => 'uid',
    'field' => 'kstu_id_fk',
    ),
  );

  $data['ks_student_course_classes']['ksccl_id'] = array(
    'title' => t('ksccl ksccl_id'),
    'help' => t('ks_std_crs_cls table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_course_classes']['kccls_id_fk'] = array(
    'title' => t('ksccl class'),
    'help' => t('ks_student_course_classes table: kccls_id_fk'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'node',
    'base field' => 'nid',
    'label' => t('Kleosis (Course) Class'),
    ),
  );

  $data['ks_student_course_classes']['ib_level'] = array(
    'title' => t('ksccl ib_level'),
    'help' => t('ks_student_course_classes table: ib_level'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'ks_ib_level_desc',
    'base field' => 'kibl_id',
    'label' => t('IB Level'),   // This shows up in the Configure field form when adding the ksccl (ib_level) field
                                // from the ks_ib_level_desc table.  The 'IB Level' appears in the Relationship select box.
                                // When this relationship is added in Views, all of the ks_ib_level_desc table fields
                                // conveniently appear in the Add field block!
    ),
  );

  $data['ks_student_course_classes']['class_auth'] = array(
    'title' => t('ksccl class auth'),
    'help' => t('ks_student_course_classes table: class auth'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_course_classes']['enrol_status'] = array(
    'title' => t('ksccl enrol_status'),
    'help' => t('ks_student_course_classes table: enrol_status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_course_classes']['enrol_date'] = array(
    'title' => t('ksccl enrol date'),
    'help' => t('ks_student_course_classes table: enrol date'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_custom_datetime',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['ks_student_course_classes']['unenrol_date'] = array(
    'title' => t('ksccl unenrol date'),
    'help' => t('ks_student_course_classes table: unenrol date'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_custom_datetime',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['ks_student_course_classes']['completed'] = array(
    'title' => t('ksccl completed'),
    'help' => t('ks_student_course_classes table: completed'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_course_classes']['final_grade'] = array(
    'title' => t('ksccl final grade'),
    'help' => t('ks_student_course_classes table: final grade'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_course_classes']['final_attendance'] = array(
    'title' => t('ksccl final attendance'),
    'help' => t('ks_student_course_classes table: final attendance'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_course_classes']['final_other'] = array(
    'title' => t('ksccl final other'),
    'help' => t('ks_student_course_classes table: final other'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_course_classes']['remarks'] = array(
    'title' => t('ksccl remarks'),
    'help' => t('ks_student_course_classes table: remarks'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

/******************************************************************************
 *                        ks_student_attendance table definitions
 ******************************************************************************/

  $data['ks_student_attendance']['table']['group'] = t('Kleosis');

 // Define the ks_student_attendance table as a base table

  $data['ks_student_attendance']['table']['base'] = array(
    'field' => 'ksatnd_id',
    'title' => t('Kleosis Attendance'),
    'help' => t('kleosis Attendance defines the ks_students table as a base table'),
  );

  $data['ks_student_attendance']['kstu_id_fk'] = array(
    'title' => t('ks_std_atnd: Link to Student'),
    'help' => t('Relationship from the ks_student_attendance foreign key (kstu_id_fk) to the Drupal users table primary key (uid).'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
      'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base_field' => 'uid',
      'label' => t('Drupal User id'),
   ),
  );

  $data['ks_student_attendance']['ksatnd_id'] = array(
    'title' => t('ksatnd ksatnd_id'),
    'help' => t('ks_student_attendance table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_attendance']['kccls_id_fk'] = array(
    'title' => t('ksatnd class'),
    'help' => t('ks_student_attendance table: kccls_id_fk'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),

    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'node',
    'base field' => 'nid',
    'label' => t('Kleosis (Atnd) Class'),
    ),
  );

  $data['ks_student_attendance']['atnd_date'] = array(
    'title' => t('ksatnd atnd date'),
    'help' => t('ks_student_attendance table: atnd date'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_custom_datetime',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_custom_numeric',
    ),
  );

  $data['ks_student_attendance']['period_day'] = array(
    'title' => t('ksatnd period day'),
    'help' => t('ks_student_attendance table: period_day'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_attendance']['period_hour'] = array(
    'title' => t('ksatnd period hour'),
    'help' => t('ks_student_attendance table: period hour'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_attendance']['abs_type'] = array(
    'title' => t('ksatnd absent type'), // this shows up in the Relationships block in Views
    'help' => t('ks_student_attendance table: abs type'), // this shows up in the Add Relationship form in Views
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'ks_absence_type_desc',
    'base field' => 'kabsty_id',
    'label' => t('Abs type'), // This shows up in the Configure field form when adding the absence_type field
                              // from the ks_absence_type_desc table.  The 'Abs type' appears in the Relationship select box.
                              // When this relationship is added in Views, all of the ks_absence_type_desc table fields
                              // conveniently appear in the Add field block!
    ),
  );

  $data['ks_student_attendance']['excused_abs'] = array(
    'title' => t('ksatnd excused abs'),
    'help' => t('ks_student_attendance table: excused abs'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['ks_student_attendance']['excuse_reason'] = array(
    'title' => t('ksatnd excuse reason'),
    'help' => t('ks_student_attendance table: excuse reason'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'ks_excused_absence_reason_desc',
    'base field' => 'kexcr_id',
    'label' => t('Exc Reason'), // This shows up in the Configure field form when adding the excuse_reason field
                                // from the ks_excused_absence_reason_desc table.  The 'Exc Reason' appears in the Relationship select box.
                                // When this relationship is added in Views, all of the ks_excused_absence_reason_desc table fields
                                // conveniently appear in the Add field block!
    ),
  );
  $data['ks_student_attendance']['remarks_instructor'] = array(
    'title' => t('ksatnd remarks instructor'),
    'help' => t('ks_student_attendance table: remarks instructor'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_attendance']['remarks_counselor'] = array(
    'title' => t('ksatnd remarks counselor'),
    'help' => t('ks_student_attendance table: remarks counselor'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

/******************************************************************************
 *                        ks_absence_type_desc table
 ******************************************************************************/

  $data['ks_absence_type_desc']['table']['group'] = t('Kleosis');

  // Note: Can optionally use this join instead of the 'relationship' definition from the ['ks_student_attendance']['abs_type'] field.
  // There is no difference in performance, only a minor alias name change in the generated query.  I think Kleosis convention
  // should use the relationship definition for all 'description' fields...
/*
  $data['ks_absence_type_desc']['table']['join'] = array(
    'ks_student_attendance' => array(
    'left_field' => 'abs_type',
    'field' => 'kabsty_id',
    ),
  );
*/
  $data['ks_absence_type_desc']['kabsty_id'] = array(
    'title' => t('katndesc kabsty_id'),
    'help' => t('ks_absence_type_desc table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_absence_type_desc']['absence_type'] = array(
    'title' => t('katndesc absence_type'),  //  this appears on the Fields block in Views like this:
                                            //  Kleosis: katndesc absence_type (katndesc absence_type)
    'help' => t('ks_absence_type_desc table: Absence type'),  // This appears in the Add fields form in Views like this:
                                                              // Kleosis: katndesc absence_type
                                                              // ks_absence_type_desc table: Absence type
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

/******************************************************************************
 *                        ks_excused_absence_reason_desc table
 ******************************************************************************/

  $data['ks_excused_absence_reason_desc']['table']['group'] = t('Kleosis');

/*
  $data['ks_excused_absence_reason_desc']['table']['join'] = array(
    'ks_student_attendance' => array(
    'left_field' => 'excuse_reason',
    'field' => 'kexcr_id',
    ),
  );
*/
  $data['ks_excused_absence_reason_desc']['kexcr_id'] = array(
    'title' => t('kexcrdesc kexcr_id'),
    'help' => t('ks_excused_absence_reason_desc table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_excused_absence_reason_desc']['excuse_reason'] = array(
    'title' => t('kexcrdesc excuse_reason'),  //  this appears on the Fields block in Views like this:
                                              //  Kleosis: kexcrdesc excuse_reason (kexcrdesc excuse_reason)
    'help' => t('ks_excused_absence_reason_desc table: Excuse reason'),  // This appears in the Add fields form in Views like this:
                                                              // Kleosis: kexcrdesc excuse_reason
                                                              // ks_absence_type_desc table: Excuse reason
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

/******************************************************************************
 *                        ks_class_schedule table definitions
 ******************************************************************************/

  $data['ks_class_schedule']['table']['group'] = t('Kleosis');

 // Define the ks_class_schedule table as a base table

  $data['ks_class_schedule']['table']['base'] = array(
    'field' => 'kclss_id',
    'title' => t('Kleosis Class Schedule'),
    'help' => t('Kleosis Class Schedule defines the ks_class_schedule table as a base table'),
  );

  $data['ks_class_schedule']['kclss_id'] = array(
    'title' => t('ks_cls_sched kclss_id'),
    'help' => t('ks_class_schedule table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_class_schedule']['kccls_id_fk'] = array(
    'title' => t('ks_cls_sched class'),
    'help' => t('ks_class_schedule table: kccls_id_fk'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),

    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'node',
    'base field' => 'nid',
    'label' => t('Kleosis (Atnd) Class'),
    ),
  );

  $data['ks_class_schedule']['period_start_datetime'] = array(
    'title' => t('ks_cls_sched start datetime'),
    'help' => t('ks_class_schedule table: start datetime'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_custom_datetime',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_custom_numeric',
    ),
  );

  $data['ks_class_schedule']['period_end_datetime'] = array(
    'title' => t('ks_cls_sched end datetime'),
    'help' => t('ks_class_schedule table: end datetime'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_custom_datetime',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_custom_numeric',
    ),
  );

  $data['ks_class_schedule']['period_day'] = array(
    'title' => t('ks_cls_sched period day'),
    'help' => t('ks_class_schedule table: period_day'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_class_schedule']['period_hour'] = array(
    'title' => t('ks_cls_sched period hour'),
    'help' => t('ks_class_schedule table: period hour'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_class_schedule']['period_length'] = array(
    'title' => t('ks_cls_sched period length'),
    'help' => t('ks_class_schedule table: period length'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_class_schedule']['period_status'] = array(
    'title' => t('ks_cls_sched period status'),
    'help' => t('ks_class_schedule table: period status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'ks_class_schedule_status_desc',
    'base field' => 'kclsss_id',
    'label' => t('Period Status'), // This shows up in the Configure field form when adding the excuse_reason field
                                  // from the ks_class_schedule_status_desc table.  The 'Period Status' appears in the Relationship select box.
                                  // When this relationship is added in Views, all of the ks_class_schedule_status_desc table fields
                                  // conveniently appear in the Add field block!
    ),
  );

  $data['ks_class_schedule']['classroom'] = array(
    'title' => t('ks_cls_sched classroom'),
    'help' => t('ks_class_schedule table: classroom'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
         'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
    'handler' => 'views_handler_relationship',
    'base' => 'ks_classroom_desc',
    'base field' => 'kclsr_id',
    'label' => t('Classroom'),  // This shows up in the Configure field form when adding the room_name (classroom) field
                                // from the ks_classroom_desc table.  The 'Classroom' appears in the Relationship select box.
                                // When this relationship is added in Views, all of the ks_classroom_desc table fields
                                // conveniently appear in the Add field block!
    ),
  );

  $data['ks_class_schedule']['period_lead'] = array(
    'title' => t('ks_cls_sched: Link to Instructor'),
    'help' => t('Relationship from the ks_class_schedule foreign key (period_lead) to the Drupal users table primary key (uid).'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
      'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base_field' => 'uid',
      'label' => t('Drupal User id'),
   ),
  );

  $data['ks_class_schedule']['period_sub'] = array(
    'title' => t('ks_cls_sched: Link to Sub'),
    'help' => t('Relationship from the ks_class_schedule foreign key (period_sub) to the Drupal users table primary key (uid).'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
      'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base_field' => 'uid',
      'label' => t('Drupal User id'),
   ),
  );

/******************************************************************************
 *                        ks_class_schedule_status_desc table
 ******************************************************************************/

  $data['ks_class_schedule_status_desc']['table']['group'] = t('Kleosis');

  $data['ks_class_schedule_status_desc']['kclsss_id'] = array(
    'title' => t('kclsrmdesc kclsss_id'),
    'help' => t('ks_class_schedule_status_desc table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_class_schedule_status_desc']['status'] = array(
    'title' => t('kclsscheddesc status'),   //  this appears on the Fields block in Views like this:
                                            //  Kleosis: kclsscheddesc status (kclsscheddesc status)
    'help' => t('ks_class_schedule_status_desc table: Status'),  // This appears in the Add fields form in Views like this:
                                                                 // Kleosis: kclsscheddesc status
                                                                  // ks_class_schedule_status_desc table: status
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

/******************************************************************************
 *                        ks_classroom_desc table
 ******************************************************************************/

  $data['ks_classroom_desc']['table']['group'] = t('Kleosis');

  $data['ks_classroom_desc']['kclsr_id'] = array(
    'title' => t('kclsrmdesc kclsr_id'),
    'help' => t('ks_classroom_desc table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_classroom_desc']['room_name'] = array(
    'title' => t('kclsrmdesc classroom'),   //  this appears on the Fields block in Views like this:
                                            //  Kleosis: kclsrmdesc classroom (kclsrmdesc classroom)
    'help' => t('ks_classroom_desc table: Classroom'),  // This appears in the Add fields form in Views like this:
                                                        // Kleosis: kclsrmdesc classroom
                                                        // ks_classroom_desc table: classroom
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


/******************************************************************************
 *                        ks_student_status_desc table
 ******************************************************************************/
/*
  $data['ks_student_status_desc']['table']['base'] = array( // no need to make this a base table because it's
    'field' => 'ksts_id',                                   // linked via a relationship
    'title' => t('Student Status'),
    'help' => t('The student status description table is a base table'),
  );

  $data['ks_student_status_desc']['table']['join'] = array(
    'ks_students' => array(
      'left_field' => 'kstu_id',
      'field' => 'ksts_id',
    ),
  );
*/

  $data['ks_student_status_desc']['table']['group'] = t('Kleosis');

  $data['ks_student_status_desc']['ksts_id'] = array(
    'title' => t('ks_student_status_desc ksts_id'),
    'help' => t('ks_student_status_desc table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_status_desc']['status'] = array(
    'title' => t('ks_student_status_desc status'),
    'help' => t('ks_student_status_desc table: status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_student_status_desc']['description'] = array(
    'title' => t('ks_student_status_desc description'),
    'help' => t('ks_student_status_desc table: description'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

/******************************************************************************
 *                        ks_instructor_status_desc table
 ******************************************************************************/
/*
  $data['ks_instructor_status_desc']['table']['base'] = array( // no need to make this a base table because it's
    'field' => 'kinsts_id',                                   // linked via a relationship
    'title' => t('Kleosis User Status'),
    'help' => t('The student status description table is a base table'),
  );

  $data['ks_instructor_status_desc']['table']['join'] = array(
    'ks_students' => array(
      'left_field' => 'kstu_id',
      'field' => 'kinsts_id',
    ),
  );
*/

  $data['ks_instructor_status_desc']['table']['group'] = t('Kleosis');

  $data['ks_instructor_status_desc']['kinsts_id'] = array(
    'title' => t('ks_instructor_status_desc kinsts_id'),
    'help' => t('ks_instructor_status_desc table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_instructor_status_desc']['status'] = array(
    'title' => t('ks_instructor_status_desc status'),
    'help' => t('ks_instructor_status_desc table: status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_instructor_status_desc']['description'] = array(
    'title' => t('ks_instructor_status_desc description'),
    'help' => t('ks_instructor_status_desc table: description'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

/******************************************************************************
 *                        ks_ib_level_desc table
 ******************************************************************************/

  $data['ks_ib_level_desc']['table']['group'] = t('Kleosis');

  $data['ks_ib_level_desc']['kibl_id'] = array(
    'title' => t('kiblvldesc kibl_id'),
    'help' => t('ks_ib_level_desc table: Primary key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['ks_ib_level_desc']['ib_level'] = array(
    'title' => t('kiblvldesc ib_level'),    //  this appears on the Fields block in Views like this:
                                            //  Kleosis: kiblvldesc ib_level (kiblvldesc ib_level)
    'help' => t('ks_ib_level_desc table: ib_level'),  // This appears in the Add fields form in Views like this:
                                                      // Kleosis: kiblvldesc ib_level
                                                      // ks_ib_level_desc table: ib_level
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  return $data;
}

/*

// legacy development comments and ideas...

// to  do this:

LEFT JOIN table_b
ON table_a.field1 = table_b.field1
AND table_a.field2 = table_b.field2

// do this:

  $data['table_b']['table']['join'] = array(
    // table_a joins to table_b through field1 and field2.
    'table_a' => array(
      'left_field' => 'field1',
      'field' => 'field1',
      // adds extra fields to the join
      'extra' => 'table_a.field2 = table_b.field2',
      // Can use AND or OR, not really needed here since it defaults to AND
      'extra type' => 'AND',
    ),
  );

$data['allocations']['table']['join'] = array(
  'node' => array(
    'left_table' => 'allocated_nodes',
    'left_field' => 'student_uid', //this field is in the allocated_nodes table
    'field' => 'student_uid', //this field is in the allocations table
    ),
  );

// also see this: http://drupal.org/node/235062
// or this: http://state68.com/content/joining-multiple-tables-node-table-views-api

*/


