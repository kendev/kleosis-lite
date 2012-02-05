<?php
// $Id: kleosis_populate_description_tables.inc,v 1.8 2011/11/21 01:55:21 kendev Exp $

/**
 * @file
 * Populate the Kleosis description tables
 */

/**
 * populate the ks_absence_type_desc table
 */
$rec_count = db_query('SELECT count(kabsty_id) FROM {ks_absence_type_desc}' )->fetchField();

if ($rec_count != 0) {
  $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
  drupal_set_message(t('Description table: ks_absence_type_desc already contains @rec_count entries. @populate', $message));
}
else {
  $fields = array(
    'kabsty_id' => 0,
    'absence_type' => '',
    'description' => 'present full period',
  );
  db_insert('ks_absence_type_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'kabsty_id' => 1,
    'absence_type' => 'absent',
    'description' => 'absent full period',
  );
  db_insert('ks_absence_type_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'kabsty_id' => 2,
    'absence_type' => 'late',
    'description' => 'late to class',
  );
  db_insert('ks_absence_type_desc')
    ->fields($fields)
    ->execute();
}

/**
 * populate the ks_academic_year_desc table
 */
$rec_count = db_query('SELECT count(academic_year) FROM {ks_academic_year_desc}' )->fetchField();

if ($rec_count != 0) {
  $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
  drupal_set_message(t('Description table: ks_academic_year_desc already contains @rec_count entries. @populate', $message));
}
else {
  $fields = array(
    'academic_year' => '2007-2008',
    'term1_startdate' => '2007-08-14 00:00:00',
    'term1_enddate' => '2007-12-21 00:00:00',
    'term2_startdate' => '2008-01-06 00:00:00',
    'term2_enddate' =>  '2008-06-24 00:00:00',
//    'term3_startdate' => '2008-04-01 00:00:00',
//    'term3_enddate' => '2008-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2008-2009',
    'term1_startdate' => '2008-08-12 00:00:00',
    'term1_enddate' => '2008-12-30 00:00:00',
    'term2_startdate' => '2009-01-03 00:00:00',
    'term2_enddate' =>  '2009-06-25 00:00:00',
//    'term3_startdate' => '2009-04-01 00:00:00',
//    'term3_enddate' => '2009-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2009-2010',
    'term1_startdate' => '2009-08-07 00:00:00',
    'term1_enddate' => '2009-12-31 00:00:00',
    'term2_startdate' => '2010-01-02 00:00:00',
    'term2_enddate' =>  '2010-06-26 00:00:00',
//    'term3_startdate' => '2010-04-01 00:00:00',
//    'term3_enddate' => '2010-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2010-2011',
    'term1_startdate' => '2010-08-01 00:00:00',
    'term1_enddate' => '2010-12-31 00:00:00',
    'term2_startdate' => '2011-01-02 00:00:00',
    'term2_enddate' =>  '2011-06-27 00:00:00',
//    'term3_startdate' => '2011-04-01 00:00:00',
//    'term3_enddate' => '2011-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2011-2012',
    'term1_startdate' => '2011-08-03 00:00:00',
    'term1_enddate' => '2011-12-27 00:00:00',
    'term2_startdate' => '2012-01-04 00:00:00',
    'term2_enddate' =>  '2012-06-26 00:00:00',
//    'term3_startdate' => '2012-04-02 00:00:00',
//    'term3_enddate' => '2012-07-29 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2012-2013',
    'term1_startdate' => '2012-08-02 00:00:00',
    'term1_enddate' => '2012-12-25 00:00:00',
    'term2_startdate' => '2013-01-05 00:00:00',
    'term2_enddate' =>  '2013-06-25 00:00:00',
//    'term3_startdate' => '2013-04-04 00:00:00',
//    'term3_enddate' => '2013-07-28 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2013-2014',
    'term1_startdate' => '2013-08-01 00:00:00',
    'term1_enddate' => '2013-12-28 00:00:00',
    'term2_startdate' => '2014-01-04 00:00:00',
    'term2_enddate' =>  '2014-06-29 00:00:00',
//    'term3_startdate' => '2014-04-02 00:00:00',
//    'term3_enddate' => '2014-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2014-2015',
    'term1_startdate' => '2014-08-02 00:00:00',
    'term1_enddate' => '2014-12-31 00:00:00',
    'term2_startdate' => '2015-01-02 00:00:00',
    'term2_enddate' =>  '2015-06-28 00:00:00',
//    'term3_startdate' => '2015-04-01 00:00:00',
//    'term3_enddate' => '2015-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2015-2016',
    'term1_startdate' => '2015-08-03 00:00:00',
    'term1_enddate' => '2015-12-29 00:00:00',
    'term2_startdate' => '2016-01-04 00:00:00',
    'term2_enddate' =>  '2016-06-26 00:00:00',
//    'term3_startdate' => '2016-04-01 00:00:00',
//    'term3_enddate' => '2016-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2016-2017',
    'term1_startdate' => '2016-08-07 00:00:00',
    'term1_enddate' => '2016-12-23 00:00:00',
    'term2_startdate' => '2017-01-03 00:00:00',
    'term2_enddate' =>  '2017-06-30 00:00:00',
//    'term3_startdate' => '2017-04-01 00:00:00',
//    'term3_enddate' => '2017-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2017-2018',
    'term1_startdate' => '2017-08-07 00:00:00',
    'term1_enddate' => '2017-12-23 00:00:00',
    'term2_startdate' => '2018-01-03 00:00:00',
    'term2_enddate' =>  '2018-06-30 00:00:00',
//    'term3_startdate' => '2018-04-01 00:00:00',
//    'term3_enddate' => '2018-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2018-2019',
    'term1_startdate' => '2018-08-07 00:00:00',
    'term1_enddate' => '2018-12-23 00:00:00',
    'term2_startdate' => '2019-01-03 00:00:00',
    'term2_enddate' =>  '2019-06-30 00:00:00',
//    'term3_startdate' => '2019-04-01 00:00:00',
//    'term3_enddate' => '2019-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2019-2020',
    'term1_startdate' => '2019-08-07 00:00:00',
    'term1_enddate' => '2019-12-23 00:00:00',
    'term2_startdate' => '2020-01-03 00:00:00',
    'term2_enddate' =>  '2020-06-30 00:00:00',
//    'term3_startdate' => '2020-04-01 00:00:00',
//    'term3_enddate' => '2020-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2020-2021',
    'term1_startdate' => '2020-08-07 00:00:00',
    'term1_enddate' => '2020-12-23 00:00:00',
    'term2_startdate' => '2021-01-03 00:00:00',
    'term2_enddate' =>  '2021-06-30 00:00:00',
//    'term3_startdate' => '2021-04-01 00:00:00',
//    'term3_enddate' => '2021-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();

  $fields = array(
    'academic_year' => '2021-2022',
    'term1_startdate' => '2021-08-07 00:00:00',
    'term1_enddate' => '2021-12-23 00:00:00',
    'term2_startdate' => '2022-01-03 00:00:00',
    'term2_enddate' =>  '2022-06-30 00:00:00',
//    'term3_startdate' => '2022-04-01 00:00:00',
//    'term3_enddate' => '2022-07-30 00:00:00',
//    'term4_startdate' => '1900-00-00 00:00:00',
//    'term4_enddate' => '1900-00-00 00:00:00',
//    'term5_startdate' => '1900-00-00 00:00:00',
//    'term5_enddate' =>  '1900-00-00 00:00:00',
//    'term6_startdate' => '1900-00-00 00:00:00',
//    'term6_enddate' => '1900-00-00 00:00:00',
  );
  db_insert('ks_academic_year_desc')
    ->fields($fields)
    ->execute();
}

/**
 * populate the ks_assessment_type_desc table
 */
  $rec_count = db_query('SELECT count(kasmt_id) FROM {ks_assessment_type_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_assessment_type_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kasmt_id' => 0,
      'assessment_type' => 'Unspecified',
      'description' => 'no assessment type',
    );
    db_insert('ks_assessment_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kasmt_id' => 1,
      'assessment_type' => 'Mid-Term Exam',
      'description' => 'Mid-Term Exam',
    );
    db_insert('ks_assessment_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kasmt_id' => 2,
      'assessment_type' => 'Final Exam',
      'description' => 'Final Exam',
    );
    db_insert('ks_assessment_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kasmt_id' => 3,
      'assessment_type' => 'Exit Test',
      'description' => 'Exit Test',
    );
    db_insert('ks_assessment_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kasmt_id' => 4,
      'assessment_type' => 'Other Test',
      'description' => 'Other Test',
    );
    db_insert('ks_assessment_type_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_campus_desc table
 */
  $rec_count = db_query('SELECT count(kcmps_id) FROM {ks_campus_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_campus_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kcmps_id' => 0,
      'campus' => '',
      'description' => 'no campus',
    );
    db_insert('ks_campus_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcmps_id' => 1,
      'campus' => 'Main Campus',
      'description' => 'Main School Campus',
    );
    db_insert('ks_campus_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcmps_id' => 2,
      'campus' => 'Satellite Campus',
      'description' => 'Satellite School Campus',
    );
    db_insert('ks_campus_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcmps_id' => 3,
      'campus' => 'Downtown Campus',
      'description' => 'Downtown School Campus',
    );
    db_insert('ks_campus_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_class_schedule_status_desc table
 */
  $rec_count = db_query('SELECT count(kclsss_id) FROM {ks_class_schedule_status_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_class_schedule_status_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kclsss_id' => 0,
      'status' => '',
      'description' => 'no status',
    );
    db_insert('ks_class_schedule_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsss_id' => 1,
      'status' => 'active',
      'description' => 'active period',
    );
    db_insert('ks_class_schedule_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsss_id' => 2,
      'status' => 'holiday',
      'description' => 'holiday period',
    );
    db_insert('ks_class_schedule_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsss_id' => 3,
      'status' => 'cancelled',
      'description' => 'cancelled period',
    );
    db_insert('ks_class_schedule_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsss_id' => 4,
      'status' => 'rescheduled',
      'description' => 'rescheduled period',
    );
    db_insert('ks_class_schedule_status_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_class_status_desc table
 */
  $rec_count = db_query('SELECT count(kclsts_id) FROM {ks_class_status_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_class_status_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kclsts_id' => 0,
      'status' => '',
      'description' => 'not set',
    );
    db_insert('ks_class_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsts_id' => 1,
      'status' => 'Active',
      'description' => 'Active',
    );
    db_insert('ks_class_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsts_id' => 2,
      'status' => 'Rescheduled',
      'description' => 'Rescheduled',
    );
    db_insert('ks_class_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsts_id' => 3,
      'status' => 'Postponed',
      'description' => 'Postponed',
    );
    db_insert('ks_class_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsts_id' => 4,
      'status' => 'Cancelled',
      'description' => 'Cancelled',
    );
    db_insert('ks_class_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsts_id' => 5,
      'status' => 'Other',
      'description' => 'Other',
    );
    db_insert('ks_class_status_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_class_type_desc table
 */
  $rec_count = db_query('SELECT count(kclsty_id) FROM {ks_class_type_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_class_type_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kclsty_id' => 0,
      'class_type' => 'Unspecified',
      'description' => 'not set',
    );
    db_insert('ks_class_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsty_id' => 1,
      'class_type' => 'Standard',
      'description' => 'Standard',
    );
    db_insert('ks_class_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsty_id' => 2,
      'class_type' => 'Online',
      'description' => 'Online',
    );
    db_insert('ks_class_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsty_id' => 3,
      'class_type' => 'Night',
      'description' => 'Night',
    );
    db_insert('ks_class_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsty_id' => 4,
      'class_type' => 'Weekend',
      'description' => 'Weekend',
    );
    db_insert('ks_class_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsty_id' => 5,
      'class_type' => 'Summer',
      'description' => 'Summer',
    );
    db_insert('ks_class_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsty_id' => 6,
      'class_type' => 'Other',
      'description' => 'Other',
    );
    db_insert('ks_class_type_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_classroom_desc table // todo: change name to ks_classroom_desc
 */
  $rec_count = db_query('SELECT count(kclsr_id) FROM {ks_classroom_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_classroom_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kclsr_id' => 0,
      'room_name' => '- none -',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'not specified',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 1,
      'room_name' => 'Room 100',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'A standard room',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 2,
      'room_name' => 'Room 101',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'A standard room',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 3,
      'room_name' => 'Room 102',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'A standard room',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 4,
      'room_name' => 'Room A1',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'Another room',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 5,
      'room_name' => 'Room A2',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'Another room',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 6,
      'room_name' => 'Studio 1',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'The Art Studio',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 7,
      'room_name' => 'PHY-1703',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'A room in the Physics Bldg',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kclsr_id' => 8,
      'room_name' => 'Auditorium',
      'room_type' => 1,
      'room_building' => 1,
      'description' => 'A big room in the auditorium',
    );
    db_insert('ks_classroom_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_countries_desc table
 */
// todo: populate entire table...
  $rec_count = db_query('SELECT count(kcntry_id) FROM {ks_countries_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_countries_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kcntry_id' => 0,
      'name' => ' ',
      'code_2' => ' ',
      'description' => 'no country',
    );
    db_insert('ks_countries_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcntry_id' => 1,
      'name' => 'Afghanistan',
      'code_2' => 'AF',
      'description' => '',
    );
    db_insert('ks_countries_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcntry_id' => 2,
      'name' => 'Albania',
      'code_2' => 'AL',
      'description' => '',
    );
    db_insert('ks_countries_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcntry_id' => 3,
      'name' => 'Algeria',
      'code_2' => 'DZ',
      'description' => '',
    );
    db_insert('ks_countries_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcntry_id' => 4,
      'name' => 'American Samoa',
      'code_2' => 'AS',
      'description' => '',
    );
    db_insert('ks_countries_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcntry_id' => 5,
      'name' => 'Andorra',
      'code_2' => 'AD',
      'description' => '',
    );
    db_insert('ks_countries_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_course_auth_desc table
 */
  $rec_count = db_query('SELECT count(kcauth_id) FROM {ks_course_auth_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_course_auth_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kcauth_id' => 0,
      'course_auth' => '',
      'description' => 'no auth set',
    );
    db_insert('ks_course_auth_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcauth_id' => 1,
      'course_auth' => 'N',
      'description' => 'New',
    );
    db_insert('ks_course_auth_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcauth_id' => 2,
      'course_auth' => 'P',
      'description' => 'Promoted',
    );
    db_insert('ks_course_auth_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcauth_id' => 3,
      'course_auth' => 'FR',
      'description' => 'Failed and Repeating',
    );
    db_insert('ks_course_auth_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcauth_id' => 4,
      'course_auth' => 'XP',
      'description' => 'Exceptionally Promoted',
    );
    db_insert('ks_course_auth_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_course_status_desc table
 */
  $rec_count = db_query('SELECT count(kcsts_id) FROM {ks_course_status_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_course_status_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kcsts_id' => 0,
      'status' => '',
      'description' => 'not set',
    );
    db_insert('ks_course_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcsts_id' => 1,
      'status' => 'Active',
      'description' => 'Active',
    );
    db_insert('ks_course_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcsts_id' => 2,
      'status' => 'Non-active',
      'description' => 'Non-active',
    );
    db_insert('ks_course_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcsts_id' => 3,
      'status' => 'Retired',
      'description' => 'Retired',
    );
    db_insert('ks_course_status_desc')
      ->fields($fields)
      ->execute();
}
/**
 * populate the ks_course_type_desc table
 */
  $rec_count = db_query('SELECT count(kcrsty_id) FROM {ks_course_type_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_course_type_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kcrsty_id' => 0,
      'course_type' => 'Unspecified',
      'description' => 'not set',
    );
    db_insert('ks_course_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcrsty_id' => 1,
      'course_type' => 'Standard',
      'description' => 'Standard',
    );
    db_insert('ks_course_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcrsty_id' => 2,
      'course_type' => 'Non-Credit',
      'description' => 'Non-Credit',
    );
    db_insert('ks_course_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcrsty_id' => 3,
      'course_type' => 'Lab',
      'description' => 'Lab',
    );
    db_insert('ks_course_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcrsty_id' => 4,
      'course_type' => 'Attendance',
      'description' => 'Attendance',
    );
    db_insert('ks_course_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcrsty_id' => 5,
      'course_type' => 'Lunch-Breaktime',
      'description' => 'Lunch-Breaktime',
    );
    db_insert('ks_course_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kcrsty_id' => 6,
      'course_type' => 'Other',
      'description' => 'Other',
    );
    db_insert('ks_course_type_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_department_desc table
 */
  $rec_count = db_query('SELECT count(kdept_id) FROM {ks_department_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_department_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kdept_id' => 0,
      'department' => 'Unspecified',
      'description' => 'not set',
    );
    db_insert('ks_department_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kdept_id' => 1,
      'department' => 'Languages',
      'description' => 'Languages Department',
    );
    db_insert('ks_department_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kdept_id' => 2,
      'department' => 'Science',
      'description' => 'Science Department',
    );
    db_insert('ks_department_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kdept_id' => 3,
      'department' => 'Art',
      'description' => 'Art Department',
    );
    db_insert('ks_department_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kdept_id' => 4,
      'department' => 'Music',
      'description' => 'Music Department',
    );
    db_insert('ks_department_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kdept_id' => 5,
      'department' => 'Mathematics',
      'description' => 'Mathematics Department',
    );
    db_insert('ks_department_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kdept_id' => 6,
      'department' => 'General',
      'description' => 'General Department',
    );
    db_insert('ks_department_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_english_level_desc table
 */
  $rec_count = db_query('SELECT count(kelvl_id) FROM {ks_english_level_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_english_level_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kelvl_id' => 0,
      'english_level' => 'Unspecified',
      'description' => 'no level',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 1,
      'english_level' => 'Level 1',
      'description' => 'English Level 1',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 2,
      'english_level' => 'Level 2',
      'description' => 'English Level 2',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 3,
      'english_level' => 'Level 3',
      'description' => 'English Level 3',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 4,
      'english_level' => 'Level 4',
      'description' => 'English Level 4',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 5,
      'english_level' => 'Level 5',
      'description' => 'English Level 5',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 6,
      'english_level' => 'Level 6',
      'description' => 'English Level 6',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 7,
      'english_level' => 'Level 7',
      'description' => 'English Level 7',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 8,
      'english_level' => 'Level 8',
      'description' => 'English Level 8',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kelvl_id' => 9,
      'english_level' => 'Level 9',
      'description' => 'English Level 9',
    );
    db_insert('ks_english_level_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_excused_absence_reason_desc table
 */
  $rec_count = db_query('SELECT count(kexcr_id) FROM {ks_excused_absence_reason_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_excused_absence_reason_desc already contains @rec_count entries. @populate', $message));
  }
  else {
  $fields = array(
      'kexcr_id' => 0,
      'excuse_reason' => '',
      'excused' => 0,
      'description' => t('absent (or late) with no reason indicated'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 1,
      'excuse_reason' => t('illness'),
      'excused' => 0,
      'description' => t('student was ill'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 2,
      'excuse_reason' => t('emergency'),
      'excused' => 0,
      'description' => t('unexpected emergency'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 3,
      'excuse_reason' => t('personal'),
      'excused' => 0,
      'description' => t('valid personal reason'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 4,
      'excuse_reason' => t('administrative'),
      'excused' => 0,
      'description' => t('administrative approved excuse'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 5,
      'excuse_reason' => t('authorized'),
      'excused' => 0,
      'description' => t('absence for acceptable reason'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 6,
      'excuse_reason' => t('unauthorized'),
      'excused' => 0,
      'description' => t('absence for unacceptable reason'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 7,
      'excuse_reason' => t('other not exc'),
      'excused' => 0,
      'description' => t('other not excused absence'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 8,
      'excuse_reason' => t('study leave (e)'),
      'excused' => 1,
      'description' => t('planned time off to study for examinations'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 9,
      'excuse_reason' => t('trip/visit (e)'),
      'excused' => 1,
      'description' => t('visit with educational value'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 10,
      'excuse_reason' => t('late < 10 min (e)'),
      'excused' => 1,
      'description' => t('late < 10 minutes'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 11,
      'excuse_reason' => t('late > 10 min (e)'),
      'excused' => 1,
      'description' => t('late > 10 minutes'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 12,
      'excuse_reason' => t('authorized (e)'),
      'excused' => 1,
      'description' => t('authorized excused absence'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kexcr_id' => 13,
      'excuse_reason' => t('other exc (e)'),
      'excused' => 1,
      'description' => t('other excused absence'),
    );
    db_insert('ks_excused_absence_reason_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_gradelevel_desc table
 */
  $rec_count = db_query('SELECT count(kgrdl_id) FROM {ks_gradelevel_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_gradelevel_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kgrdl_id' => 0,
      'gradelevel' => 'Unspecified',
      'description' => 'no gradelevel',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 1,
      'gradelevel' => 'K1',
      'description' => 'Kindegarten 1',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 2,
      'gradelevel' => 'K2',
      'description' => 'Kindegarten 2',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 3,
      'gradelevel' => 'K3',
      'description' => 'Kindegarten 3',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 4,
      'gradelevel' => '1',
      'description' => 'Gradelevel 1',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 5,
      'gradelevel' => '2',
      'description' => 'Gradelevel 2',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 6,
      'gradelevel' => '3',
      'description' => 'Gradelevel 3',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 7,
      'gradelevel' => '4',
      'description' => 'Gradelevel 4',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 8,
      'gradelevel' => '5',
      'description' => 'Gradelevel 5',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 9,
      'gradelevel' => '6',
      'description' => 'Gradelevel 6',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 10,
      'gradelevel' => '7',
      'description' => 'Gradelevel 7',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 11,
      'gradelevel' => '8',
      'description' => 'Gradelevel 8',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 12,
      'gradelevel' => '9',
      'description' => 'Gradelevel 9',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 13,
      'gradelevel' => '10',
      'description' => 'Gradelevel 10',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 14,
      'gradelevel' => '11',
      'description' => 'Gradelevel 11',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 15,
      'gradelevel' => '12',
      'description' => 'Gradelevel 12',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kgrdl_id' => 16,
      'gradelevel' => '13',
      'description' => 'Gradelevel 13',
    );
    db_insert('ks_gradelevel_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_ib_level_desc table
 */
  $rec_count = db_query('SELECT count(kibl_id) FROM {ks_ib_level_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_ib_level_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kibl_id' => 0,
      'ib_level' => '',
      'description' => 'no IB Level',
    );
    db_insert('ks_ib_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kibl_id' => 1,
      'ib_level' => 'SL',
      'description' => 'Standard Level',
    );
    db_insert('ks_ib_level_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kibl_id' => 2,
      'ib_level' => 'HL',
      'description' => 'Higher Level',
    );
    db_insert('ks_ib_level_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_instructor_class_role_desc table
 */
  $rec_count = db_query('SELECT count(kiclsr_id) FROM {ks_instructor_class_role_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_instructor_class_role_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kiclsr_id' => 0,
      'rolename' => '',
      'description' => 'not set',
    );
    db_insert('ks_instructor_class_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kiclsr_id' => 1,
      'rolename' => 'primary',
      'description' => 'Primary instructor',
    );
    db_insert('ks_instructor_class_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kiclsr_id' => 2,
      'rolename' => 'assistant',
      'description' => 'Assistant instructor',
    );
    db_insert('ks_instructor_class_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kiclsr_id' => 3,
      'rolename' => 'other',
      'description' => 'Other',
    );
    db_insert('ks_instructor_class_role_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_instructor_lms_role_desc table
 */
  $rec_count = db_query('SELECT count(klmsr_id) FROM {ks_instructor_lms_role_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_instructor_lms_role_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'klmsr_id' => 0,
      'rolename' => '',
      'description' => 'not set',
    );
    db_insert('ks_instructor_lms_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klmsr_id' => 1,
      'rolename' => 'manager',
      'description' => 'Manager',
    );
    db_insert('ks_instructor_lms_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klmsr_id' => 2,
      'rolename' => 'coursecreator',
      'description' => 'Course Creator',
    );
    db_insert('ks_instructor_lms_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klmsr_id' => 3,
      'rolename' => 'editingteacher',
      'description' => 'Teacher',
    );
    db_insert('ks_instructor_lms_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klmsr_id' => 4,
      'rolename' => 'teacher',
      'description' => 'Non-editing teacher',
    );
    db_insert('ks_instructor_lms_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klmsr_id' => 5,
      'rolename' => 'student',
      'description' => 'Student',
    );
    db_insert('ks_instructor_lms_role_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klmsr_id' => 6,
      'rolename' => 'guest',
      'description' => 'Guest',
    );
    db_insert('ks_instructor_lms_role_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_instructor_status_desc table
 */
  $rec_count = db_query('SELECT count(kinsts_id) FROM {ks_instructor_status_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_instructor_status_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kinsts_id' => 0,
      'status' => '',
      'description' => 'no status',
    );
    db_insert('ks_instructor_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kinsts_id' => 1,
      'status' => 'instructor',
      'description' => 'active instructor',
    );
    db_insert('ks_instructor_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kinsts_id' => 2,
      'status' => 'inactive',
      'description' => 'inactive instructor',
    );
    db_insert('ks_instructor_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kinsts_id' => 3,
      'status' => 'on-leave',
      'description' => 'instructor is on leave',
    );
    db_insert('ks_instructor_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kinsts_id' => 4,
      'status' => 'indeterminate',
      'description' => 'instructor status is unknown',
    );
    db_insert('ks_instructor_status_desc')
      ->fields($fields)
      ->execute();
}
/**
 * populate the ks_lab_type_desc table
 */
  $rec_count = db_query('SELECT count(klabty_id) FROM {ks_lab_type_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_lab_type_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'klabty_id' => 0,
      'lab_type' => '',
      'description' => 'not set',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klabty_id' => 1,
      'lab_type' => 'Standard',
      'description' => 'Standard',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klabty_id' => 2,
      'lab_type' => 'Large',
      'description' => 'Large',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klabty_id' => 3,
      'lab_type' => 'Secure Level 1',
      'description' => 'Secure Level 1',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klabty_id' => 4,
      'lab_type' => 'Secure Level 2',
      'description' => 'Secure Level 2',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klabty_id' => 5,
      'lab_type' => 'Off Campus',
      'description' => 'Off Campus',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klabty_id' => 6,
      'lab_type' => 'Temporary',
      'description' => 'Temporary',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'klabty_id' => 7,
      'lab_type' => 'Other',
      'description' => 'Other',
    );
    db_insert('ks_lab_type_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_medical_category_desc table
 */
  $rec_count = db_query('SELECT count(ksmedc_id) FROM {ks_medical_category_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_medical_category_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'ksmedc_id' => 0,
      'med_category' => 'None',
      'description' => 'No category item',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmedc_id' => 1,
      'med_category' => 'Administrative',
      'description' => 'Administrative category',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmedc_id' => 2,
      'med_category' => 'Illnesses',
      'description' => 'Illnesses category',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmedc_id' => 3,
      'med_category' => 'Health problems',
      'description' => 'Health problems category',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmedc_id' => 4,
      'med_category' => 'Surgery',
      'description' => 'Surgery category',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmedc_id' => 5,
      'med_category' => 'Vaccination history',
      'description' => 'Vaccination history category',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmedc_id' => 6,
      'med_category' => 'Additional Info',
      'description' => 'Additional Info category',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmedc_id' => 7,
      'med_category' => 'Other',
      'description' => 'Other category',
    );
    db_insert('ks_medical_category_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_medical_subject_desc table
 */
  $rec_count = db_query('SELECT count(ksmeds_id) FROM {ks_medical_subject_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_medical_subject_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'ksmeds_id' => 0,
      'med_subject' => 'None',
      'description' => 'No subject item',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 1,
      'med_subject' => 'Chicken Pox',
      'description' => 'Chicken Pox',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 2,
      'med_subject' => 'German measles',
      'description' => 'German measles (Rubella)',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 3,
      'med_subject' => 'Hepatitis',
      'description' => 'Hepatitis',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 4,
      'med_subject' => 'Measles',
      'description' => 'Measles',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 5,
      'med_subject' => 'Mumps',
      'description' => 'Mumps',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 6,
      'med_subject' => 'Poliomyelitis',
      'description' => 'Poliomyelitis',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 7,
      'med_subject' => 'Tuberculosis',
      'description' => 'Tuberculosis',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 8,
      'med_subject' => 'Typhoid',
      'description' => 'Typhoid',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 9,
      'med_subject' => 'Whooping Cough',
      'description' => 'Whooping Cough',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 10,
      'med_subject' => 'Allergies',
      'description' => 'Allergies',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 11,
      'med_subject' => 'Asthma',
      'description' => 'Asthma',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 12,
      'med_subject' => 'Congenital Abnormalities',
      'description' => 'Congenital Abnormalities',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 13,
      'med_subject' => 'Convulsions/Epilepsy',
      'description' => 'Convulsions/Epilepsy',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 14,
      'med_subject' => 'Diabetes',
      'description' => 'Diabetes',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 15,
      'med_subject' => 'Frequent Headaches',
      'description' => 'Frequent Headaches',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 16,
      'med_subject' => 'Hearing Difficulties',
      'description' => 'Hearing Difficulties',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 17,
      'med_subject' => 'Speech Difficulties',
      'description' => 'Speech Difficulties',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 18,
      'med_subject' => 'Sight Difficulties',
      'description' => 'Sight Difficulties',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 19,
      'med_subject' => 'Heart Condition',
      'description' => 'Heart Condition',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 20,
      'med_subject' => 'BCG - Tuberculosis',
      'description' => 'DTP - Whooping Cough',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 21,
      'med_subject' => 'BCG - Tuberculosis',
      'description' => 'DTP - Whooping Cough',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 22,
      'med_subject' => 'Hepatitus A',
      'description' => 'Hepatitus A',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 23,
      'med_subject' => 'Hepatitus B',
      'description' => 'Hepatitus B',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 24,
      'med_subject' => 'Hib',
      'description' => 'Hib',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 25,
      'med_subject' => 'Japanese B Encephalitis',
      'description' => 'Japanese B Encephalitis',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 26,
      'med_subject' => 'OPV - Polio',
      'description' => 'OPV - Polio',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 27,
      'med_subject' => 'Rubella',
      'description' => 'Rubella',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 50,
      'med_subject' => 'Primary Physician',
      'description' => 'Primary Physician',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 51,
      'med_subject' => 'Primary Physician Phone No',
      'description' => 'Primary Physician Phone No',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 52,
      'med_subject' => 'Emergency Contact',
      'description' => 'Emergency Contact',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 53,
      'med_subject' => 'Emergency Contact Phone No',
      'description' => 'Emergency Contact Phone No',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 60,
      'med_subject' => 'Medicine allergies',
      'description' => 'Medicine allergies',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 61,
      'med_subject' => 'Current medication',
      'description' => 'Current medication',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 62,
      'med_subject' => 'Other med info',
      'description' => 'Other med info',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 70,
      'med_subject' => 'Administer meds',
      'description' => 'Administer meds',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksmeds_id' => 99,
      'med_subject' => 'Other',
      'description' => 'Other',
    );
    db_insert('ks_medical_subject_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_organization_desc table
 */
  $rec_count = db_query('SELECT count(korg_id) FROM {ks_organization_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_organization_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'korg_id' => 0,
      'organization' => '',
      'description' => 'not set',
    );
    db_insert('ks_organization_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'korg_id' => 1,
      'organization' => 'Kleosis Sample School',
      'description' => 'Sample school for testing and piloting Kleosis',
    );
    db_insert('ks_organization_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'korg_id' => 2,
      'organization' => 'Kleosis Partner School',
      'description' => 'Partner school for the Kleosis Sample School',
    );
    db_insert('ks_organization_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_program_desc table
 */
  $rec_count = db_query('SELECT count(kpgm_id) FROM {ks_program_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_program_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kpgm_id' => 0,
      'program' => 'Unspecified',
      'description' => 'no program',
    );
    db_insert('ks_program_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kpgm_id' => 1,
      'program' => 'General Academic',
      'description' => 'General Academic Program',
    );
    db_insert('ks_program_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kpgm_id' => 2,
      'program' => 'Advanced Academic',
      'description' => 'Advanced Academic Program',
    );
    db_insert('ks_program_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kpgm_id' => 3,
      'program' => 'Special Needs',
      'description' => 'Special Needs Program',
    );
    db_insert('ks_program_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kpgm_id' => 4,
      'program' => 'Standards Certification',
      'description' => 'Standards Certification Program',
    );
    db_insert('ks_program_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kpgm_id' => 5,
      'program' => 'Other',
      'description' => 'Other Program',
    );
    db_insert('ks_program_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_report_odt table
 */
  $rec_count = db_query('SELECT count(krodt_id) FROM {ks_report_odt}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_report_odt already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'krodt_id' => 0,
      'report_name' => '',
      'report_filename' => ' ',
      'description' => 'not set',
    );
    db_insert('ks_report_odt')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krodt_id' => 1,
      'report_name' => 'Progress A',
      'report_filename' => 'progress_a',
      'description' => 'Progress A report',
    );
    db_insert('ks_report_odt')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krodt_id' => 2,
      'report_name' => 'Progress B',
      'report_filename' => 'progress_b',
      'description' => 'Progress B report',
    );
    db_insert('ks_report_odt')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krodt_id' => 3,
      'report_name' => 'Other (tbd...)',
      'report_filename' => 'other',
      'description' => 'Other (tbd...)',
    );
    db_insert('ks_report_odt')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_residings_desc table
 */
  $rec_count = db_query('SELECT count(kres_id) FROM {ks_residings_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_residings_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kres_id' => 0,
      'residing_with' => 'Unspecified',
      'description' => 'not set',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 1,
      'residing_with' => 'Parents',
      'description' => 'Mother and Father',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 2,
      'residing_with' => 'Mother',
      'description' => 'Mother',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 3,
      'residing_with' => 'Father',
      'description' => 'Father',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 4,
      'residing_with' => 'Sister',
      'description' => 'Sister',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 5,
      'residing_with' => 'Brother',
      'description' => 'Brother',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 6,
      'residing_with' => 'Guardian',
      'description' => 'Legal Guardian',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 7,
      'residing_with' => 'Relative',
      'description' => 'Family Relative',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 8,
      'residing_with' => 'Friend',
      'description' => 'Friend of student',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 9,
      'residing_with' => 'Alone',
      'description' => 'Residing alone',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kres_id' => 10,
      'residing_with' => 'Other',
      'description' => 'Residing with other',
    );
    db_insert('ks_residings_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_room_type_desc table
 */
  $rec_count = db_query('SELECT count(krmtyp_id) FROM {ks_room_type_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_room_type_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'krmtyp_id' => 0,
      'room_type' => '',
      'description' => 'not set',
    );
    db_insert('ks_room_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krmtyp_id' => 1,
      'room_type' => 'Standard',
      'description' => 'Standard',
    );
    db_insert('ks_room_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krmtyp_id' => 2,
      'room_type' => 'Large',
      'description' => 'Large',
    );
    db_insert('ks_room_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krmtyp_id' => 3,
      'room_type' => 'Auditorium',
      'description' => 'Auditorium',
    );
    db_insert('ks_room_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krmtyp_id' => 4,
      'room_type' => 'Lab',
      'description' => 'Lab',
    );
    db_insert('ks_room_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krmtyp_id' => 5,
      'room_type' => 'Protected Lab',
      'description' => 'Protected Lab',
    );
    db_insert('ks_room_type_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'krmtyp_id' => 6,
      'room_type' => 'Temporary',
      'description' => 'Temporary',
    );
    db_insert('ks_room_type_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_student_group_desc table
 */
  $rec_count = db_query('SELECT count(ksgrpd_id) FROM {ks_student_group_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_student_group_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'ksgrpd_id' => 0,
      'groupname' => '',
      'description' => 'not set',
    );
    db_insert('ks_student_group_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksgrpd_id' => 1,
      'groupname' => 'Group 1',
      'description' => 'Group 1',
    );
    db_insert('ks_student_group_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksgrpd_id' => 2,
      'groupname' => 'Group 2',
      'description' => 'Group 2',
    );
    db_insert('ks_student_group_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksgrpd_id' => 3,
      'groupname' => 'Group 3',
      'description' => 'Group 3',
    );
    db_insert('ks_student_group_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksgrpd_id' => 4,
      'groupname' => 'Group 4',
      'description' => 'Group 4',
    );
    db_insert('ks_student_group_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksgrpd_id' => 5,
      'groupname' => 'Group 5',
      'description' => 'Group 5',
    );
    db_insert('ks_student_group_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksgrpd_id' => 6,
      'groupname' => 'Group 6',
      'description' => 'Group 6',
    );
    db_insert('ks_student_group_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_student_status_desc table
 */
  $rec_count = db_query('SELECT count(ksts_id) FROM {ks_student_status_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_student_status_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'ksts_id' => 0,
      'status' => '',
      'description' => 'no status',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksts_id' => 1,
      'status' => 'student',
      'description' => 'active student',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksts_id' => 2,
      'status' => 'graduated',
      'description' => 'graduated student',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksts_id' => 3,
      'status' => 'promoted',
      'description' => 'promoted to a higher gradelevel',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksts_id' => 4,
      'status' => 'reassessed',
      'description' => 'reassessed to a lower gradelevel',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksts_id' => 5,
      'status' => 'suspended',
      'description' => 'suspended student',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksts_id' => 6,
      'status' => 'withdrawn',
      'description' => 'withdrawn studen',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ksts_id' => 7,
      'status' => 'terminated',
      'description' => 'terminated student',
    );
    db_insert('ks_student_status_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_transportation_desc table
 */
  $rec_count = db_query('SELECT count(ktrns_id) FROM {ks_transportation_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_transportation_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'ktrns_id' => 0,
      'transportation' => '',
      'description' => 'no transportation',
    );
    db_insert('ks_transportation_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ktrns_id' => 1,
      'transportation' => 'None Required',
      'description' => 'No transportation is required',
    );
    db_insert('ks_transportation_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ktrns_id' => 2,
      'transportation' => 'School Bus',
      'description' => 'School bus transportation',
    );
    db_insert('ks_transportation_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ktrns_id' => 3,
      'transportation' => 'By Guardian',
      'description' => 'Transportation by guardian',
    );
    db_insert('ks_transportation_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'ktrns_id' => 4,
      'transportation' => 'By Self',
      'description' => 'Transportation provided by student',
    );
    db_insert('ks_transportation_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_user_relationships_desc table
 */
  $rec_count = db_query('SELECT count(kurel_id) FROM {ks_user_relationships_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_user_relationships_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kurel_id' => 0,
      'relationship' => '',
      'description' => 'not set',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 1,
      'relationship' => 'Mother',
      'description' => 'Mother',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 2,
      'relationship' => 'Father',
      'description' => 'Father',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 3,
      'relationship' => 'Brother',
      'description' => 'Brother',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 4,
      'relationship' => 'Sister',
      'description' => 'Sister',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 5,
      'relationship' => 'Primary Guardian',
      'description' => 'Primary Guardian',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 6,
      'relationship' => 'Secondary Guardian',
      'description' => 'Secondary Guardian',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 7,
      'relationship' => 'Relative',
      'description' => 'Relative',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 8,
      'relationship' => 'Friend',
      'description' => 'Friend',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 9,
      'relationship' => 'Aunt',
      'description' => 'Aunt',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 10,
      'relationship' => 'Uncle',
      'description' => 'Uncle',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 11,
      'relationship' => 'Grandmother',
      'description' => 'Grandmother',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 12,
      'relationship' => 'Grandfather',
      'description' => 'Grandfather',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kurel_id' => 13,
      'relationship' => 'Other',
      'description' => 'Other',
    );
    db_insert('ks_user_relationships_desc')
      ->fields($fields)
      ->execute();
}

/**
 * populate the ks_usertypes_desc table
 */
  $rec_count = db_query('SELECT count(kutyp_id) FROM {ks_usertypes_desc}' )->fetchField();

  if ($rec_count != 0) {
    $message = array('@rec_count' => $rec_count, '@populate' => t('Please delete these entries before re-populating this table,'));
    drupal_set_message(t('Description table: ks_usertypes_desc already contains @rec_count entries. @populate', $message));
  }
  else {
    $fields = array(
      'kutyp_id' => 0,
      'usertype' => '',
      'description' => 'no usertype',
    );
    db_insert('ks_usertypes_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kutyp_id' => 1,
      'usertype' => 'ks_instructor',
      'description' => 'ks_instructor',
    );
    db_insert('ks_usertypes_desc')
      ->fields($fields)
      ->execute();

    $fields = array(
      'kutyp_id' => 2,
      'usertype' => 'ks_parent_guardian',
      'description' => 'ks_parent_guardian',
    );
    db_insert('ks_usertypes_desc')
      ->fields($fields)
      ->execute();
}
