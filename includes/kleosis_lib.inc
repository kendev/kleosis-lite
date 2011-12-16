<?php
// $Id$
/**
* @file
*   kleosis Library functions
*/

/**
 * Get the day of week for any timezone as a string
 *
 * @return
 *    the day of week as a string
 */
function getDayOfWeek($pTimezone) {

    if($pTimezone = 'default') {
      $pTimezone = date_default_timezone_get();
    }
    $userDateTimeZone = new DateTimeZone($pTimezone);

    $UserDateTime = new DateTime('now', $userDateTimeZone);

    $offsetSeconds = $UserDateTime->getOffset();
    //echo $offsetSeconds;

    return gmdate("l", time() + $offsetSeconds);
}

/**
 * Get the classids and classnames from the schedule records of a selected instructor
 *
 * @param $class_schedule_records
 *    records containing classes for the selected instructor
 * @return
 *    associative array of classids and classnames
 */
function get_classes_from_schedule_records($class_schedule_records) {

  $classes = array();

  foreach ($class_schedule_records as $record) {
    $node = node_load($record->kccls_id_fk);
    $classes[$record->kccls_id_fk] = $node->title;
  }
    return $classes;
}

/**
 * Get the days from the schedule records of a selected instructor
 *
 * @param $class_schedule_records
 *    records containing classes for the selected instructor
 * @return
 *    associative array of days
 */
function get_days_from_schedule_records($class_schedule_records) {

  $days = array();

  foreach ($class_schedule_records as $record) {
    $days[$record->period_day] = ks_get_day_string($record->period_day);
  }
    return $days;
}

/**
 * Get the periods from the schedule records of a selected instructor
 *
 * @param $class_schedule_records
 *    records containing classes for the selected instructor
 * @return
 *    associative array of periods
 */
function get_periods_from_schedule_records($class_schedule_records) {

  $periods = array();

  foreach ($class_schedule_records as $record) {

    $pstartd = new DateTime($record->period_start_datetime);
    $pendd = new DateTime($record->period_end_datetime);

    $pstarth = $pstartd->format('H');
    $pstartm = $pstartd->format('i');
    $pendh = $pendd->format('H');
    $pendm = $pendd->format('i');
    $period = $pstarth . ':' .  $pstartm .'-' . $pendh . ':' . $pendm;

    $periods[$period] = $period;
  }
    return $periods;
}

/**
 * Get the hour and minute from a period
 *
 * @param $period
 *    the period as a string (e.g.'08:00-09:15')
 * @return
 *    associative array for hour and minute
 */
function get_hour_and_minute_from_period($period) {

  if(strlen($period) <> 11) {
    return FALSE;
  }

  $pstarth = substr($period, 0, 2);
  $pstartm = substr($period, 3, 2);
  $pendh = substr($period, 6, 2);
  $pendm = substr($period, 9, 2);

  $hour_and_minute = array('start_hour' => $pstarth,
                    'start_minute' => $pstartm,
                    'end_hour' => $pendh,
                    'end_minute' => $pendm,
                    );

    return $hour_and_minute;
}

/**
 * The allowed values for day of week (ISO-8601)
 *
 * @return
 *    An array of days to select
 */
function kleosis_dayofweek_values() {  // todo: these values may be defined in the list (text) field directly

  $le_days = array(
      '1' => t('Monday'),
      '2' => t('Tuesday'),
      '3' => t('Wednesday'),
      '4' => t('Thursday'),
      '5' => t('Friday'),
      '6' => t('Saturday'),
      '7' => t('Sunday'),
  );
  return $le_days;
}

/**
 * Get day of week as string from int
 * (can use $DateTime->format('l') instead...)
 *
 * @return
 *    The day of week as a string
 */
function ks_get_day_string($intday) {

  $le_days = kleosis_dayofweek_values();
  if(!$intday) {
    return 'none';
  }
  $le_day = $le_days[$intday];

  return $le_day;
}

/**
 * Get day of week as int from string
 *
 * @return
 *    The day of week as an int
 */
function ks_get_day_int($strday) {

  $le_days = kleosis_dayofweek_values();

  $le_day = array_search($strday, $le_days);

  return ($le_day ? $le_day : 0);
}

/**
 * The allowed values for the hours field
 *
 * @return
 *    An array of hours to select
 */
function kleosis_hours_values() {  // todo: these values may be defined in the list (text) field directly

  $le_hours = array(
    '00' => t('00'),
    '01' => t('01'),
    '02' => t('02'),
    '03' => t('03'),
    '04' => t('04'),
    '05' => t('05'),
    '06' => t('06'),
    '07' => t('07'),
    '08' => t('08'),
    '09' => t('09'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
    '13' => t('13'),
    '14' => t('14'),
    '15' => t('15'),
    '16' => t('16'),
    '17' => t('17'),
    '18' => t('18'),
    '19' => t('19'),
    '20' => t('20'),
    '21' => t('21'),
    '22' => t('22'),
    '23' => t('23'),
  );
  return $le_hours;
}

/**
 * The allowed values for the minutes field
 *
 * @return
 *    An array of minutes to select
 */
function kleosis_minutes_values() {  // todo: these values may be defined in the list (text) field directly

  $le_minutes = array(
    '00' => t('00'),
    '05' => t('05'),
    '10' => t('10'),
    '15' => t('15'),
    '20' => t('20'),
    '25' => t('25'),
    '30' => t('30'),
    '35' => t('35'),
    '40' => t('40'),
    '45' => t('45'),
    '50' => t('50'),
    '55' => t('55'),
  );
  return $le_minutes;
}


/**
 * The allowed values for the grade fields
 *
 * @return
 *    An array of values to select
 */
function kleosis_grade_weights() {  // todo: these values may be defined in the list (text) field directly

  $le_weights = array(
    '00' => t('00'),
    '01' => t('01'),
    '02' => t('02'),
    '03' => t('03'),
    '04' => t('04'),
    '05' => t('05'),
    '06' => t('06'),
    '07' => t('07'),
    '08' => t('08'),
    '09' => t('09'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
    '13' => t('13'),
    '14' => t('14'),
    '15' => t('15'),
    '16' => t('16'),
    '17' => t('17'),
    '18' => t('18'),
    '19' => t('19'),
    '20' => t('20'),
    '21' => t('21'),
    '22' => t('22'),
    '23' => t('23'),
    '24' => t('24'),
    '25' => t('25'),
    '26' => t('26'),
    '27' => t('27'),
    '28' => t('28'),
    '29' => t('29'),
    '30' => t('30'),
    '31' => t('31'),
    '32' => t('32'),
    '33' => t('33'),
    '34' => t('34'),
    '35' => t('35'),
    '36' => t('36'),
    '37' => t('37'),
    '38' => t('38'),
    '39' => t('39'),
    '40' => t('40'),
    '41' => t('41'),
    '42' => t('42'),
    '43' => t('43'),
    '44' => t('44'),
    '45' => t('45'),
    '46' => t('46'),
    '47' => t('47'),
    '48' => t('48'),
    '49' => t('49'),
    '50' => t('50'),
    '51' => t('51'),
    '52' => t('52'),
    '53' => t('53'),
    '54' => t('54'),
    '55' => t('55'),
    '56' => t('56'),
    '57' => t('57'),
    '58' => t('58'),
    '59' => t('59'),
    '60' => t('60'),
    '61' => t('61'),
    '62' => t('62'),
    '63' => t('63'),
    '64' => t('64'),
    '65' => t('65'),
    '66' => t('66'),
    '67' => t('67'),
    '68' => t('68'),
    '69' => t('69'),
    '70' => t('70'),
    '71' => t('71'),
    '72' => t('72'),
    '73' => t('73'),
    '74' => t('74'),
    '75' => t('75'),
    '76' => t('76'),
    '77' => t('77'),
    '78' => t('78'),
    '79' => t('79'),
    '80' => t('80'),
    '81' => t('81'),
    '82' => t('82'),
    '83' => t('83'),
    '84' => t('84'),
    '85' => t('85'),
    '86' => t('86'),
    '87' => t('87'),
    '88' => t('88'),
    '89' => t('89'),
    '90' => t('90'),
    '91' => t('91'),
    '92' => t('92'),
    '93' => t('93'),
    '94' => t('94'),
    '95' => t('95'),
    '96' => t('96'),
    '97' => t('97'),
    '98' => t('98'),
    '99' => t('99'),
    '100' => t('100'),
  );
  return $le_weights;
}

/**
 * The allowed values for the gradelevel field
 *
 * @return
 *    An array of gradelevels to select
 */

function kleosis_gradelevel_values() {

  $le_array = array(
    'all' => t('All'),
    'k1' => t('K1'),
    'k2' => t('K2'),
    'k3' => t('K3'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
    '13' => t('13'),
  );
  return $le_array;
}
/**
 * map drupal gradelevel to kleosis gradelevel - this is silly...
 *
 * @param $drp_gradelevel
 *    a drupal string gradelevel value
 *
 * @return
 *    A Kleosis integer gradelevel value
 */

function ks_map_drp_gradelevel_to_ks($drp_gradelevel) {

  $le_array = array(
    'all' => 0,
    'k1' => 1,
    'k2' => 2,
    'k3' => 3,
    '1' => 4,
    '2' => 5,
    '3' => 6,
    '4' => 7,
    '5' => 8,
    '6' => 9,
    '7' => 10,
    '8' => 11,
    '9' => 12,
    '10' => 13,
    '11' => 14,
    '12' => 15,
    '13' => 16,
  );
  return $le_array[$drp_gradelevel];
}
/**
 * map a kleosis gradelevel to a drupal gradelevel - this is silly too...
 *
 * @param $ks_gradelevel
 *    a Kleosis integer gradelevel value
 * @return
 *    A drupal string gradelevel value
 */

function ks_map_ks_gradelevel_to_drp($ks_gradelevel) {

  $le_array = array(
    0 => t('All'),
    1 => t('k1'),
    2 => t('k2'),
    3 => t('k3'),
    4 => t('1'),
    5 => t('2'),
    6 => t('3'),
    7 => t('4'),
    8 => t('5'),
    9 => t('6'),
    10 => t('7'),
    11 => t('8'),
    12 => t('9'),
    13 => t('10'),
    14 => t('11'),
    15 => t('12'),
    16 => t('13'),
  );
  return $le_array[$ks_gradelevel];
}
/**
 * Get the academic years
 *
 * @return
 *    options - an array of academic years
 */
function kleosis_academic_year_values() {

  $options = array('all' => t('All'),);
  $results = db_query('SELECT academic_year FROM {ks_academic_year_desc}' )->fetchAll();
  foreach ($results as $iac_year) {
    $options[$iac_year->academic_year] = $iac_year->academic_year;
  }

  return $options;
}

/**
 * Get the academic year terms
 *
 * @return
 *    options - an array of academic year terms
 */
function kleosis_academic_term_values() {

  $le_array = array(
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    'fy' => t('FY'),
  );
  return $le_array;
}


/**
 * The allowed values for the lab_type courses field
 *
 * @return
 *    An array of lab_types to select
 */
function kleosis_lab_types_values() {  // todo: these values may be defined in the list (text) field directly

  $le_array = array(
    'standard' => t('Standard'),
    'large' => t('Large'),
    'auditorium' =>t('Auditorium'),
    'lab' => t('Lab'),
    'protected_lab' => t('Protected lab'),
    'temporary' => t('Temporary'),
  );
  return $le_array;
}

/**
 * The allowed values for the types of courses
 *
 * @return
 *    An array of lab_types to select
 */
function kleosis_course_types_values() {  // todo: these values may be defined in the list (text) field directly

  $le_array = array(
    'standard' => t('Standard'),
    'non-credit' => t('Non-Credit'),
    'attendance' =>t('Attendance'),
    'lab' => t('Lab'),
    'lunch-breaktime' => t('Lunch-Breaktime'),
    'other' => t('Other'),
  );
  return $le_array;
}

/**
 * The allowed values for the program field
 *
 * @return
 *    An array of programs to select
 */
function kleosis_program_values() {  // todo: these values may be defined in the list (text) field directly

  $le_array = array(
    'all' => t('All'),
    'general_academic' => t('General Academic'),
    'advanced_academic' => t('Advanced Academic'),
    'special_needs' => t('Special Needs'),
    'certification' =>t('Standards Certification'),
    'other' => t('Other'),
  );
  return $le_array;
}

/**
 * The allowed values for the department field
 *
 * @return
 *    An array of departments to select
 */
function kleosis_department_values() {  // todo: these values may be defined in the list (text) field directly

  $le_array = array(
    'all' => t('All'),
    'languages' => t('Languages'),
    'science' => t('Science'),
    'art' =>t('Art'),
    'music' => t('Music'),
    'mathmetics' => t('Mathematics'),
    'general' => t('General'),
  );
  return $le_array;
}

/**
 * The Morning, Lunch, and Afternoon breaktimes
 * *note* this may be deprecated if the technique changes to creating classes for the breaktimes...
 *
 * @return
 *    An array of breaktimes
 */
function kleosis_schedule_breaktimes() {

//  $breaktime_schedule_array[] = array('period' => $aperiod, 'class' => $period->kccls_id_fk, 'day' => $period->period_day,) ;

  $morning_break = variable_get('kleosis_morn_break_start_hour', '10') . ':' . variable_get('kleosis_morn_break_start_min', '05') .
                    '-' . variable_get('kleosis_morn_break_end_hour', '10') . ':' . variable_get('kleosis_morn_break_end_min', '20');

  $lunch_break = variable_get('kleosis_lunch_start_hour', '12') . ':' . variable_get('kleosis_lunch_start_min', '15') .
                    '-' . variable_get('kleosis_lunch_end_hour', '12') . ':' . variable_get('kleosis_lunch_end_min', '55');

  $afternoon_break = variable_get('kleosis_aft_break_start_hour', '14') . ':' . variable_get('kleosis_aft_break_start_min', '30') .
                    '-' . variable_get('kleosis_aft_break_end_hour', '14') . ':' . variable_get('kleosis_aft_break_end_min', '50');


  $breaktime_schedule_array[] = array('period' => $morning_break, 'class' => 'morning break', 'day' => 'all',) ;
  $breaktime_schedule_array[] = array('period' => $lunch_break, 'class' => 'lunch break', 'day' => 'all',) ;
  $breaktime_schedule_array[] = array('period' => $afternoon_break, 'class' => 'afternoon break', 'day' => 'all',) ;




  return $breaktime_schedule_array;
}





/**
 * Retrieve a test name (string)
 *
 * @return
 *   The test name as a string
 */
function kleosis_testname() {

  $testname = "Cool McCool";

return $testname;

}

