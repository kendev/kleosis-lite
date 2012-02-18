<?php

/**
 * @file
 *  Create the sample schedule for kleosis
 */

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample English 101 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 101 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 101 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 101 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Math 101 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Math 101 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Math 101 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Math 101 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8403', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Art 101 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Art 101 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Art 101 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Art 101 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Science 101 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Science 101 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Science 101 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Science 101 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8404', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample PE 101 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample PE 101 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample PE 101 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample PE 101 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8405', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 101 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 101 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 101 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 101 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8406', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Music 101 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Music 101 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Music 101 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Music 101 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample English 102 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 102 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 102 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 102 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------
//--------------
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Science 201 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Science 201 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Science 201 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Science 201 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8404', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample PE 201 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample PE 201 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample PE 201 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample PE 201 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8406', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Music 201 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Music 201 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Music 201 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Music 201 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 1;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Math 201 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Math 201 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Math 201 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Math 201 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample English 201 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 201 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 201 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 201 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8405', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 201 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 201 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 201 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Computer 201 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample English 202 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 202 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 202 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample English 202 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8408', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis sample Art 201 Class - Section 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Art 201 Class - Section S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Art 201 Class - Section 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis sample Art 201 Class - Section S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------
//----------
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-9 Class - Sec S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-9 Class - Sec S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-10 Class - Sec S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Morning Attnd G-10 Class - Sec S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------
/*
  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------
*/

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $classid =  kleosis_sample_get_classid('Kleosis Morning Break', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Morning Break S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Morning Break', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Morning Break S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $classid =  kleosis_sample_get_classid('Kleosis Afternoon Break', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Afternoon Break S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Afternoon Break', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Afternoon Break S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $classid =  kleosis_sample_get_classid('Kleosis Lunchtime A', '2011-2012', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Lunchtime S1', '2011-2012', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Lunchtime A', '2012-2013', 'fy');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
  $classid =  kleosis_sample_get_classid('Kleosis Lunchtime S1', '2012-2013', '3');
  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 2; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 3; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 4; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);

  $p_d = 5; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;
  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//------

/**
 * function to write a record into the the ks_class_schedule table
 * uses ks_insert_schedule_record() in ks_db_lib.inc
 *
 */
function kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i) {
  $schedule_record = array();
//  $schedule_record['kclss_id'] = $id;
  $schedule_record['kccls_id_fk'] = $classid;
  $schedule_record['period_start_datetime']['year'] = $class_start_date->format('Y');
  $schedule_record['period_start_datetime']['month'] = $class_start_date->format('n');
  $schedule_record['period_start_datetime']['day'] = $class_start_date->format('j');
  $schedule_record['period_day'] = $p_d;
  $schedule_record['period_start_hour'] = $p_s_h;
  $schedule_record['period_start_minute'] = $p_s_m;
  $schedule_record['period_end_hour'] = $p_e_h;
  $schedule_record['period_end_minute'] = $p_e_m;
  $schedule_record['classroom'] = $cl_rm;
  $schedule_record['period_status'] = 1;  // for Kleosis Lite
  $schedule_record['period_lead'] = $p_l_i;
  $schedule_record['period_sub'] = 0;

  $ok = ks_insert_schedule_record($schedule_record);
}

/**
 * function to return the class id for a specific class
 *
 * @param  $class_title
 * @param  $academic_year
 *
 * @return the class id
 *
 */
function kleosis_sample_get_classid($class_title, $academic_year, $term) {

  $nids = 0;
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_status', 'value', 1, '=') // 'active'
  ->propertyCondition('title', $class_title);

  $result = $query->execute();

  if ( !empty($result) ) {
    $nids = array_keys($result['node']);
  }
  return $nids[0];
}
