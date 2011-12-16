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
                        'Kleosis Morning Break', 'Kleosis Lunchtime A', 'Kleosis Afternoon Break'
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

