<?php
/**
 * @file
 * Create the sample schedule for kleosis
 */


  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8403', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Art 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8403', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Art 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8403', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Art 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8403', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Art 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8404', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample PE 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8404', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample PE 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8405', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Computer 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8405', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Computer 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 5;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8406', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Music 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8406', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Music 101 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 1;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 102 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 102 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 102 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 102 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 102 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 2;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
//--------------
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Science 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '08'; $p_s_m = '15'; $p_e_h = '09'; $p_e_m = '05'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8404', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample PE 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8404', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample PE 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8406', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Music 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 1;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8406', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Music 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 1;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '09'; $p_s_m = '10'; $p_e_h = '10'; $p_e_m = '00'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8401', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Math 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '10'; $p_s_m = '30'; $p_e_h = '11'; $p_e_m = '20'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8405', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Computer 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8405', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Computer 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '11'; $p_s_m = '25'; $p_e_h = '12'; $p_e_m = '15'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 202 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 202 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 202 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 202 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8407', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample English 202 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '13'; $p_s_m = '35'; $p_e_h = '14'; $p_e_m = '25'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8408', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Art 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8408', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Art 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8408', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis sample Art 201 Class - Section 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '14'; $p_s_m = '45'; $p_e_h = '15'; $p_e_m = '30'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
//----------
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '08'; $p_s_m = '00'; $p_e_h = '08'; $p_e_m = '15'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
/*
  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8400', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 3;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---
*/
  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
  $p_l_i = db_query($sql, array(':name' => 'instructor8402', ))->fetchField();

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '13'; $p_s_m = '30'; $p_e_h = '13'; $p_e_m = '35'; $cl_rm = 4;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Morning Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Morning Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Morning Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Morning Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Morning Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '10'; $p_s_m = '05'; $p_e_h = '10'; $p_e_m = '20'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Afternoon Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Afternoon Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Afternoon Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Afternoon Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Afternoon Break'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '14'; $p_s_m = '30'; $p_e_h = '14'; $p_e_m = '45'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Lunchtime A'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 1; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Lunchtime A'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 2; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Lunchtime A'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 3; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Lunchtime A'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 4; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

  $p_l_i = 0;  // No instructor required for lunch and breaks

  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
  $classid = db_query($sql, array(':type' => 'class', ':kleosis' => 'Kleosis Lunchtime A'))->fetchField();

  $theclass = node_load($classid);  // get the class start date from the class
  $start_date = $theclass->ks_class_start_end_date['und'][0]['value'];
  $class_start_date = new DateTime($start_date);  // create a datetime object for new period

  $p_d = 5; $p_s_h = '12'; $p_s_m = '15'; $p_e_h = '12'; $p_e_m = '55'; $cl_rm = 0;

  kleosis_sample_schedule_entry($classid, $class_start_date, $p_d, $p_s_h, $p_s_m, $p_e_h, $p_e_m, $cl_rm, $p_l_i);
//---

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

/*
 * Note - the following is an earlier 'manual' technique used to create the class schedule.
 * Left here for informational purposes only...
 *
 *
 * Be sure to change the kccls_id_fk and period_lead values before importing...
 *
1299 - Kleosis sample Art 101 Class - Section 1
1232 - Kleosis sample English 101 Class - Section 1
1238 - Kleosis sample English 102 Class - Section 1
1221 - Kleosis sample Math 101 Class - Section 1
1241 - Kleosis sample Science 101 Class - Section 1
1303 - Kleosis sample PE 101 Class - Section 1
1306 - Kleosis sample Music 101 Class - Section 1
1323 - Kleosis sample Computer 101 Class - Section 1
1317 - Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1
1327 - Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1

1248 - Kleosis sample Art 201 Class - Section 1
1271 - Kleosis sample English 201 Class - Section 1
1277 - Kleosis sample English 202 Class - Section 1
1260 - Kleosis sample Math 201 Class - Section 1
1280 - Kleosis sample Science 201 Class - Section 1
1310 - Kleosis sample PE 201 Class - Section 1
1313 - Kleosis sample Music 201 Class - Section 1
1325 - Kleosis sample Computer 201 Class - Section 1
1320 - Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1
1330 - Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1

880 - instructor8400
881 - instructor8401
882 - instructor8402
883 - instructor8403
884 - instructor8404
885 - instructor8405
886 - instructor8406
887 - instructor8407
888 - instructor8408
889 - instructor8409

*  kclss_id, kccls_id_fk, period_start_datetime, period_end_time, period_day, period_hour, period_length, period_status, classroom, period_lead, period_sub
*/
//use kleoport;

//INSERT INTO ks_class_schedule VALUES (1, 1232, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 1, 0, 0, 1, 2, 880, 0);
//INSERT INTO ks_class_schedule VALUES (2, 1232, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 2, 0, 0, 1, 2, 880, 0);
//INSERT INTO ks_class_schedule VALUES (3, 1232, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 3, 0, 0, 1, 2, 880, 0);
//INSERT INTO ks_class_schedule VALUES (4, 1232, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 4, 0, 0, 1, 2, 880, 0);
//INSERT INTO ks_class_schedule VALUES (5, 1232, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 5, 0, 0, 1, 2, 880, 0);
//INSERT INTO ks_class_schedule VALUES (6, 1221, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 1, 0, 0, 1, 2, 881, 0);
//INSERT INTO ks_class_schedule VALUES (7, 1221, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 2, 0, 0, 1, 2, 881, 0);
//INSERT INTO ks_class_schedule VALUES (8, 1221, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 3, 0, 0, 1, 2, 881, 0);
//INSERT INTO ks_class_schedule VALUES (9, 1221, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 4, 0, 0, 1, 2, 881, 0);
//INSERT INTO ks_class_schedule VALUES (10, 1221, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 5, 0, 0, 1, 2, 881, 0);
//INSERT INTO ks_class_schedule VALUES (11, 1299, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 1, 0, 0, 1, 2, 883, 0);
//INSERT INTO ks_class_schedule VALUES (12, 1299, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 2, 0, 0, 1, 2, 883, 0);
//INSERT INTO ks_class_schedule VALUES (13, 1299, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 3, 0, 0, 1, 2, 883, 0);
//INSERT INTO ks_class_schedule VALUES (14, 1299, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 5, 0, 0, 1, 2, 883, 0);
//INSERT INTO ks_class_schedule VALUES (15, 1241, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 3, 0, 0, 1, 2, 882, 0);
//INSERT INTO ks_class_schedule VALUES (16, 1241, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 4, 0, 0, 1, 2, 882, 0);
//INSERT INTO ks_class_schedule VALUES (17, 1241, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 5, 0, 0, 1, 2, 882, 0);
//INSERT INTO ks_class_schedule VALUES (18, 1241, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 1, 0, 0, 1, 2, 882, 0);
//INSERT INTO ks_class_schedule VALUES (19, 1241, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 2, 0, 0, 1, 2, 882, 0);
//INSERT INTO ks_class_schedule VALUES (20, 1303, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 4, 0, 0, 1, 2, 884, 0);
//INSERT INTO ks_class_schedule VALUES (21, 1303, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 1, 0, 0, 1, 2, 884, 0);
//INSERT INTO ks_class_schedule VALUES (22, 1323, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 2, 0, 0, 1, 5, 885, 0);
//INSERT INTO ks_class_schedule VALUES (23, 1323, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 3, 0, 0, 1, 5, 885, 0);
//INSERT INTO ks_class_schedule VALUES (24, 1306, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 4, 0, 0, 1, 1, 886, 0);
//INSERT INTO ks_class_schedule VALUES (25, 1306, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 5, 0, 0, 1, 1, 886, 0);
//INSERT INTO ks_class_schedule VALUES (26, 1238, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 1, 0, 0, 1, 2, 887, 0);
//INSERT INTO ks_class_schedule VALUES (27, 1238, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 2, 0, 0, 1, 2, 887, 0);
//INSERT INTO ks_class_schedule VALUES (28, 1238, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 3, 0, 0, 1, 2, 887, 0);
//INSERT INTO ks_class_schedule VALUES (29, 1238, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 4, 0, 0, 1, 2, 887, 0);
//INSERT INTO ks_class_schedule VALUES (30, 1238, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 5, 0, 0, 1, 2, 887, 0);
//INSERT INTO ks_class_schedule VALUES (31, 1280, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 1, 0, 0, 1, 3, 882, 0);
//INSERT INTO ks_class_schedule VALUES (32, 1280, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 2, 0, 0, 1, 3, 882, 0);
//INSERT INTO ks_class_schedule VALUES (33, 1280, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 3, 0, 0, 1, 3, 882, 0);
//INSERT INTO ks_class_schedule VALUES (34, 1280, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 4, 0, 0, 1, 3, 882, 0);
//INSERT INTO ks_class_schedule VALUES (35, 1280, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 5, 0, 0, 1, 3, 882, 0);
//INSERT INTO ks_class_schedule VALUES (36, 1310, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 1, 0, 0, 1, 3, 884, 0);
//INSERT INTO ks_class_schedule VALUES (37, 1310, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 5, 0, 0, 1, 3, 884, 0);
//INSERT INTO ks_class_schedule VALUES (38, 1313, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 2, 0, 0, 1, 1, 886, 0);
//INSERT INTO ks_class_schedule VALUES (39, 1313, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 1, 0, 0, 1, 1, 886, 0);
//INSERT INTO ks_class_schedule VALUES (40, 1260, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 3, 0, 0, 1, 3, 881, 0);
//INSERT INTO ks_class_schedule VALUES (41, 1260, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 4, 0, 0, 1, 3, 881, 0);
//INSERT INTO ks_class_schedule VALUES (42, 1260, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 5, 0, 0, 1, 3, 881, 0);
//INSERT INTO ks_class_schedule VALUES (43, 1260, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 1, 0, 0, 1, 3, 881, 0);
//INSERT INTO ks_class_schedule VALUES (44, 1260, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 2, 0, 0, 1, 3, 881, 0);
//INSERT INTO ks_class_schedule VALUES (45, 1271, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 1, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (46, 1271, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 2, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (47, 1271, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 3, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (48, 1271, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 4, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (49, 1271, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 5, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (50, 1325, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 3, 0, 0, 1, 4, 885, 0);
//INSERT INTO ks_class_schedule VALUES (51, 1325, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 4, 0, 0, 1, 4, 885, 0);
//INSERT INTO ks_class_schedule VALUES (52, 1277, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 1, 0, 0, 1, 3, 887, 0);
//INSERT INTO ks_class_schedule VALUES (53, 1277, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 2, 0, 0, 1, 3, 887, 0);
//INSERT INTO ks_class_schedule VALUES (54, 1277, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 3, 0, 0, 1, 3, 887, 0);
//INSERT INTO ks_class_schedule VALUES (55, 1277, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 4, 0, 0, 1, 3, 887, 0);
//INSERT INTO ks_class_schedule VALUES (56, 1277, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 5, 0, 0, 1, 3, 887, 0);
//INSERT INTO ks_class_schedule VALUES (57, 1248, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 3, 0, 0, 1, 3, 888, 0);
//INSERT INTO ks_class_schedule VALUES (58, 1248, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 4, 0, 0, 1, 3, 888, 0);
//INSERT INTO ks_class_schedule VALUES (59, 1248, '2011-08-07 14:45:00', '2011-08-07 15:30:00', 5, 0, 0, 1, 3, 888, 0);
//INSERT INTO ks_class_schedule VALUES (60, 1317, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 1, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (61, 1317, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 2, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (62, 1317, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 3, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (63, 1317, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 4, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (64, 1317, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 5, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (65, 1320, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 1, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (66, 1320, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 2, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (67, 1320, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 3, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (68, 1320, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 4, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (69, 1320, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 5, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (70, 1327, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 1, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (71, 1327, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 2, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (72, 1327, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 3, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (73, 1327, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 4, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (74, 1327, '2011-08-18 13:00:00', '2011-08-18 13:35:00', 5, 0, 0, 1, 3, 880, 0);
//INSERT INTO ks_class_schedule VALUES (75, 1330, '2011-09-28 13:30:00', '2011-09-28 13:35:00', 1, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (76, 1330, '2011-09-28 13:30:00', '2011-09-28 13:35:00', 2, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (77, 1330, '2011-09-28 13:00:00', '2011-09-28 13:35:00', 3, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (78, 1330, '2011-09-28 13:00:00', '2011-09-28 13:35:00', 4, 0, 0, 1, 4, 882, 0);
//INSERT INTO ks_class_schedule VALUES (79, 1330, '2011-09-28 13:00:00', '2011-09-28 13:35:00', 5, 0, 0, 1, 4, 882, 0);

