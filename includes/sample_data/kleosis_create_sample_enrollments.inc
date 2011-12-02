<?php
/**
 * @file
 * Create the sample enrollments for kleosis
 */

  $studentnames = array('student9000','student9001','student9002','student9003','student9004','student9005','student9006','student9007',
                        'student9008','student9009','student9010','student9011','student9012','student9013','student9014','student9015',
                        );
  $classnames = array ('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1', 'Kleosis sample Art 101 Class - Section 1',
                        'Kleosis sample Computer 101 Class - Section 1', 'Kleosis sample English 101 Class - Section 1',
                        'Kleosis sample English 102 Class - Section 1', 'Kleosis sample Math 101 Class - Section 1',
                        'Kleosis sample Music 101 Class - Section 1', 'Kleosis sample PE 101 Class - Section 1',
                        'Kleosis sample Science 101 Class - Section 1',
                        );

  foreach($studentnames as $studentname) {

    $sql = 'SELECT uid FROM {users} u WHERE u.name = :name';
    $studentid = db_query($sql, array(':name' => $studentname,))->fetchField();

    foreach($classnames as $classname) {
      $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.title = :kleosis';
      $classid = db_query($sql, array(':type' => 'class', ':kleosis' => $classname))->fetchField();

      try {
        kleosis_enroll_student_into_class($studentid, $classid, $classname);
      }
      catch (Exception $e) {
        drupal_set_message('Sample enrollment error: ' . $e->getMessage() );
      }
    }
  }


/*
 * Function to enroll a student into a class
 * ks_insert_enroll_record() or ks_update_enroll_record() in ks_db_lib.inc
 *
*/
function kleosis_enroll_student_into_class($studentid, $classid, $classname) {

    $enrd = new DateTime('now');
    $enroll_record = array();

    $enroll_record['drp_uid'] = $studentid;
    $enroll_record['class_nid'] = $classid;
    $enroll_record['class_auth'] = 1;
    $enroll_record['enrol_date']['year'] = $enrd->format('Y');
    $enroll_record['enrol_date']['month'] = $enrd->format('n');
    $enroll_record['enrol_date']['day'] = $enrd->format('j');
    $enroll_record['unenrol_date']['year'] = '1900';
    $enroll_record['unenrol_date']['month'] = '01';
    $enroll_record['unenrol_date']['day'] = '01';
    $enroll_record['completed'] = 0;
    $enroll_record['final_grade'] = 0;
    $enroll_record['final_attendance'] = '';
    $enroll_record['final_other'] = '';
    $enroll_record['remarks'] = 'Sample data enroll into class ' . $classname;

    $there_already = ks_get_enroll_records($studentid, TRUE, $classid);
    $there_but_unenrolled = ks_get_enroll_records($studentid, FALSE, $classid);

    if  ( (empty($there_already)) &&  (empty($there_but_unenrolled)) ){
      $newrec_id = ks_insert_enroll_record($enroll_record);
//      drupal_set_message('Student: ' . $studentid . ' was enrolled into class: ' . $classname . ' (class id:) ' .  $classid . ')');
    }
    else {
      $enroll_record['ksccl_id'] = $there_but_unenrolled['ksccl_id'];
      $ok = ks_update_enroll_record($enroll_record);
//      drupal_set_message('Student: ' . $studentid . ' has been re-enrolled in class: ' . $classname . ' (class id:) ' .  $classid . ')');
    }
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

