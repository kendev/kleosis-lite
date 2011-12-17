<?php
/**
 * @file
 * Create the sample courses and classes for kleosis
 */

  $course_nids = array();

  $course_nids[0] = kleosis_create_sample_course('Kleosis auto generated Math Course 101', 'Math101', 'general_academic', 'mathematics', 'standard', '9', 'Description for Kleosis auto generated Math Course 101');
    kleosis_create_sample_class('Kleosis sample Math 101 Class - Section 1', $course_nids[0], 'fy', '1', 'Remarks for Kleosis sample Math 101 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Math 101 Class - Section 2', $course_nids[0], 'fy', '2', 'Remarks for Kleosis sample Math 101 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Math 101 Class - Section 3', $course_nids[0], 'fy', '3', 'Remarks for Kleosis sample Math 101 Class - Section 3');
  $course_nids[1] = kleosis_create_sample_course('Kleosis auto generated Math Course 102', 'Math102', 'general_academic', 'mathematics', 'standard', '9', 'Description for Kleosis auto generated Math Course 102');
    kleosis_create_sample_class('Kleosis sample Math 102 Class - Section 1', $course_nids[1], '1', '1', 'Remarks for Kleosis sample Math 102 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Math 102 Class - Section 2', $course_nids[1], '1', '2', 'Remarks for Kleosis sample Math 102 Class - Section 2');
  $course_nids[2] = kleosis_create_sample_course('Kleosis auto generated Math Course 103', 'Math103', 'general_academic', 'mathematics', 'standard', '9', 'Description for Kleosis auto generated Math Course 103');
    kleosis_create_sample_class('Kleosis sample Math 103 Class - Section 1', $course_nids[2], '2', '1', 'Remarks for Kleosis sample Math 103 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Math 103 Class - Section 2', $course_nids[2], '2', '2', 'Remarks for Kleosis sample Math 103 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Math 103 Class - Section 3', $course_nids[2], '2', '3', 'Remarks for Kleosis sample Math 103 Class - Section 3');
  $course_nids[3] = kleosis_create_sample_course('Kleosis auto generated English Course 101', 'English101', 'general_academic', 'languages', 'standard', '9', 'Description for Kleosis auto generated English Course 101');
    kleosis_create_sample_class('Kleosis sample English 101 Class - Section 1', $course_nids[3], 'fy', '1', 'Remarks for Kleosis sample English 101 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample English 101 Class - Section 2', $course_nids[3], 'fy', '2', 'Remarks for Kleosis sample English 101 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample English 101 Class - Section 3', $course_nids[3], 'fy', '3', 'Remarks for Kleosis sample English 101 Class - Section 3');
    kleosis_create_sample_class('Kleosis sample English 101 Class - Section 4', $course_nids[3], 'fy', '4', 'Remarks for Kleosis sample English 101 Class - Section 4');
    kleosis_create_sample_class('Kleosis sample English 101 Class - Section 5', $course_nids[3], 'fy', '5', 'Remarks for Kleosis sample English 101 Class - Section 5');
  $course_nids[4] = kleosis_create_sample_course('Kleosis auto generated English Course 102', 'English102', 'general_academic', 'languages', 'standard', '9', 'Description for Kleosis auto generated English Course 102');
    kleosis_create_sample_class('Kleosis sample English 102 Class - Section 1', $course_nids[4], 'fy', '1', 'Remarks for Kleosis sample English 102 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample English 102 Class - Section 2', $course_nids[4], 'fy', '2', 'Remarks for Kleosis sample English 102 Class - Section 2');
  $course_nids[5] = kleosis_create_sample_course('Kleosis auto generated Science Course 101', 'Science101', 'general_academic', 'science', 'standard', '9', 'Description for Kleosis auto generated Science Course 101');
    kleosis_create_sample_class('Kleosis sample Science 101 Class - Section 1', $course_nids[5], 'fy', '1', 'Remarks for Kleosis sample Science 101 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Science 101 Class - Section 2', $course_nids[5], 'fy', '2', 'Remarks for Kleosis sample Science 101 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Science 101 Class - Section 3', $course_nids[5], 'fy', '3', 'Remarks for Kleosis sample Science 101 Class - Section 3');
  $course_nids[6] = kleosis_create_sample_course('Kleosis auto generated Science Course 102', 'Science102', 'general_academic', 'science', 'standard', '9', 'Description for Kleosis auto generated Science Course 102');
    kleosis_create_sample_class('Kleosis sample Science 102 Class - Section 1', $course_nids[6], '1', '1', 'Remarks for Kleosis sample Science 102 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Science 102 Class - Section 2', $course_nids[6], '1', '2', 'Remarks for Kleosis sample Science 102 Class - Section 2');

  $course_nids[7] = kleosis_create_sample_course('Kleosis auto generated Art Course 201', 'Art201', 'general_academic', 'art', 'standard', '10', 'Description for Kleosis auto generated Art Course 201');
    kleosis_create_sample_class('Kleosis sample Art 201 Class - Section 1', $course_nids[7], 'fy', '1', 'Remarks for Kleosis sample Art 201 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Art 201 Class - Section 2', $course_nids[7], 'fy', '2', 'Remarks for Kleosis sample Art 201 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Art 201 Class - Section 3', $course_nids[7], 'fy', '3', 'Remarks for Kleosis sample Art 201 Class - Section 3');
  $course_nids[8] = kleosis_create_sample_course('Kleosis auto generated Art Course 202', 'Art202', 'advanced_academic', 'art', 'standard', '10', 'Description for Kleosis auto generated Art Course 202');
    kleosis_create_sample_class('Kleosis sample Art 202 Class - Section 1', $course_nids[8], '1', '1', 'Remarks for Kleosis sample Art 202 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Art 202 Class - Section 2', $course_nids[8], '1', '2', 'Remarks for Kleosis sample Art 202 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Art 202 Class - Section 3', $course_nids[8], '1', '3', 'Remarks for Kleosis sample Art 202 Class - Section 3');
    kleosis_create_sample_class('Kleosis sample Art 202 Class - Section 4', $course_nids[8], '1', '4', 'Remarks for Kleosis sample Art 202 Class - Section 4');
  $course_nids[9] = kleosis_create_sample_course('Kleosis auto generated Art Course 203', 'Art203', 'advanced_academic', 'art', 'standard', '10', 'Description for Kleosis auto generated Art Course 203');
    kleosis_create_sample_class('Kleosis sample Art 203 Class - Section 1', $course_nids[9], '2', '1', 'Remarks for Kleosis sample Art 203 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Art 203 Class - Section 2', $course_nids[9], '2', '2', 'Remarks for Kleosis sample Art 203 Class - Section 2');

  $course_nids[10] = kleosis_create_sample_course('Kleosis auto generated Math Course 201', 'Math201', 'general_academic', 'mathematics', 'standard', '10', 'Description for Kleosis auto generated Math Course 201');
    kleosis_create_sample_class('Kleosis sample Math 201 Class - Section 1', $course_nids[10], 'fy', '1', 'Remarks for Kleosis sample Math 201 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Math 201 Class - Section 2', $course_nids[10], 'fy', '2', 'Remarks for Kleosis sample Math 201 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Math 201 Class - Section 3', $course_nids[10], 'fy', '3', 'Remarks for Kleosis sample Math 201 Class - Section 3');
  $course_nids[11] = kleosis_create_sample_course('Kleosis auto generated Math Course 202', 'Math202', 'general_academic', 'mathematics', 'standard', '10', 'Description for Kleosis auto generated Math Course 202');
    kleosis_create_sample_class('Kleosis sample Math 202 Class - Section 1', $course_nids[11], '1', '1', 'Remarks for Kleosis sample Math 202 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Math 202 Class - Section 2', $course_nids[11], '1', '2', 'Remarks for Kleosis sample Math 202 Class - Section 2');
  $course_nids[12] = kleosis_create_sample_course('Kleosis auto generated Math Course 203', 'Math203', 'general_academic', 'mathematics', 'standard', '10', 'Description for Kleosis auto generated Math Course 203');
    kleosis_create_sample_class('Kleosis sample Math 203 Class - Section 1', $course_nids[12], '2', '1', 'Remarks for Kleosis sample Math 203 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Math 203 Class - Section 2', $course_nids[12], '2', '2', 'Remarks for Kleosis sample Math 203 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Math 203 Class - Section 3', $course_nids[12], '2', '3', 'Remarks for Kleosis sample Math 203 Class - Section 3');
  $course_nids[13] = kleosis_create_sample_course('Kleosis auto generated English Course 201', 'English201', 'general_academic', 'languages', 'standard', '10', 'Description for Kleosis auto generated English Course 201');
    kleosis_create_sample_class('Kleosis sample English 201 Class - Section 1', $course_nids[13], 'fy', '1', 'Remarks for Kleosis sample English 201 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample English 201 Class - Section 2', $course_nids[13], 'fy', '2', 'Remarks for Kleosis sample English 201 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample English 201 Class - Section 3', $course_nids[13], 'fy', '3', 'Remarks for Kleosis sample English 201 Class - Section 3');
    kleosis_create_sample_class('Kleosis sample English 201 Class - Section 4', $course_nids[13], 'fy', '4', 'Remarks for Kleosis sample English 201 Class - Section 4');
    kleosis_create_sample_class('Kleosis sample English 201 Class - Section 5', $course_nids[13], 'fy', '5', 'Remarks for Kleosis sample English 201 Class - Section 5');
  $course_nids[14] = kleosis_create_sample_course('Kleosis auto generated English Course 202', 'English202', 'general_academic', 'languages', 'standard', '10', 'Description for Kleosis auto generated English Course 202');
    kleosis_create_sample_class('Kleosis sample English 202 Class - Section 1', $course_nids[14], 'fy', '1', 'Remarks for Kleosis sample English 202 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample English 202 Class - Section 2', $course_nids[14], 'fy', '2', 'Remarks for Kleosis sample English 202 Class - Section 2');
  $course_nids[15] = kleosis_create_sample_course('Kleosis auto generated Science Course 201', 'Science201', 'general_academic', 'science', 'standard', '10', 'Description for Kleosis auto generated Science Course 201');
    kleosis_create_sample_class('Kleosis sample Science 201 Class - Section 1', $course_nids[15], 'fy', '1', 'Remarks for Kleosis sample Science 201 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Science 201 Class - Section 2', $course_nids[15], 'fy', '2', 'Remarks for Kleosis sample Science 201 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Science 201 Class - Section 3', $course_nids[15], 'fy', '3', 'Remarks for Kleosis sample Science 201 Class - Section 3');
  $course_nids[16] = kleosis_create_sample_course('Kleosis auto generated Science Course 202', 'Science202', 'general_academic', 'science', 'standard', '10', 'Description for Kleosis auto generated Science Course 202');
    kleosis_create_sample_class('Kleosis sample Science 202 Class - Section 1', $course_nids[16], '2', '1', 'Remarks for Kleosis sample Science 202 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Science 202 Class - Section 2', $course_nids[16], '2', '2', 'Remarks for Kleosis sample Science 202 Class - Section 2');
  $course_nids[17] = kleosis_create_sample_course('Kleosis auto generated Art Course 310', 'Art310', 'general_academic', 'art', 'standard', '11', 'Description for Kleosis auto generated Art Course 310');
    kleosis_create_sample_class('Kleosis sample Art 310 Class - Section 1', $course_nids[17], 'fy', '1', 'Remarks for Kleosis sample Art 310 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Art 310 Class - Section 2', $course_nids[17], 'fy', '2', 'Remarks for Kleosis sample Art 310 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Art 310 Class - Section 3', $course_nids[17], 'fy', '3', 'Remarks for Kleosis sample Art 310 Class - Section 3');
  $course_nids[18] = kleosis_create_sample_course('Kleosis auto generated Art Course 311', 'Art311', 'advanced_academic', 'art', 'standard', '11', 'Description for Kleosis auto generated Art Course 311');
    kleosis_create_sample_class('Kleosis sample Art 311 Class - Section 1', $course_nids[18], '2', '1', 'Remarks for Kleosis sample Art 311 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Art 311 Class - Section 2', $course_nids[18], '2', '2', 'Remarks for Kleosis sample Art 311 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Art 311 Class - Section 3', $course_nids[18], '2', '3', 'Remarks for Kleosis sample Art 311 Class - Section 3');
    kleosis_create_sample_class('Kleosis sample Art 311 Class - Section 4', $course_nids[18], '2', '4', 'Remarks for Kleosis sample Art 311 Class - Section 4');
  $course_nids[19] = kleosis_create_sample_course('Kleosis auto generated Art Course 312', 'Art312', 'advanced_academic', 'art', 'standard', '12', 'Description for Kleosis auto generated Art Course 312');
    kleosis_create_sample_class('Kleosis sample Art 312 Class - Section 1', $course_nids[19], '2', '1', 'Remarks for Kleosis sample Art 312 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Art 312 Class - Section 2', $course_nids[19], '2', '2', 'Remarks for Kleosis sample Art 312 Class - Section 2');
  $course_nids[20] = kleosis_create_sample_course('Kleosis auto generated Art Course 101', 'Art101', 'general_academic', 'art', 'standard', '9', 'Description for Kleosis auto generated Art Course 101');
    kleosis_create_sample_class('Kleosis sample Art 101 Class - Section 1', $course_nids[20], 'fy', '1', 'Remarks for Kleosis sample Art 101 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Art 101 Class - Section 2', $course_nids[20], 'fy', '2', 'Remarks for Kleosis sample Art 101 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Art 101 Class - Section 3', $course_nids[20], 'fy', '3', 'Remarks for Kleosis sample Art 101 Class - Section 3');

  $course_nids[21] = kleosis_create_sample_course('Kleosis auto generated PE Course 101', 'PE101', 'general_academic', 'general', 'standard', '9', 'Description for Kleosis auto generated PE Course 101');
    kleosis_create_sample_class('Kleosis sample PE 101 Class - Section 1', $course_nids[21], 'fy', '1', 'Remarks for Kleosis sample PE 101 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample PE 101 Class - Section 2', $course_nids[21], 'fy', '2', 'Remarks for Kleosis sample PE 101 Class - Section 2');
  $course_nids[22] = kleosis_create_sample_course('Kleosis auto generated Music Course 101', 'Music101', 'general_academic', 'general', 'standard', '9', 'Description for Kleosis auto generated Music Course 101');
    kleosis_create_sample_class('Kleosis sample Music 101 Class - Section 1', $course_nids[22], 'fy', '1', 'Remarks for Kleosis sample Music 101 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Music 101 Class - Section 2', $course_nids[22], 'fy', '2', 'Remarks for Kleosis sample Music 101 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Music 101 Class - Section 3', $course_nids[22], 'fy', '3', 'Remarks for Kleosis sample Music 101 Class - Section 3');
  $course_nids[23] = kleosis_create_sample_course('Kleosis auto generated PE Course 201', 'PE201', 'general_academic', 'general', 'standard', '10', 'Description for Kleosis auto generated PE Course 201');
    kleosis_create_sample_class('Kleosis sample PE 201 Class - Section 1', $course_nids[23], 'fy', '1', 'Remarks for Kleosis sample PE 201 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample PE 201 Class - Section 2', $course_nids[23], 'fy', '2', 'Remarks for Kleosis sample PE 201 Class - Section 2');
  $course_nids[24] = kleosis_create_sample_course('Kleosis auto generated Music Course 201', 'Music201', 'general_academic', 'general', 'standard', '10', 'Description for Kleosis auto generated Music Course 201');
    kleosis_create_sample_class('Kleosis sample Music 201 Class - Section 1', $course_nids[24], 'fy', '1', 'Remarks for Kleosis sample Music 201 Class - Section 1');
    kleosis_create_sample_class('Kleosis sample Music 201 Class - Section 2', $course_nids[24], 'fy', '2', 'Remarks for Kleosis sample Music 201 Class - Section 2');
    kleosis_create_sample_class('Kleosis sample Music 201 Class - Section 3', $course_nids[24], 'fy', '3', 'Remarks for Kleosis sample Music 201 Class - Section 3');

  $course_nids[25] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Morning Attnd Grade 9', 'HRAttm09', 'general_academic', 'general', 'attendance', '9', 'Description for Kleosis auto generated Homeroom-Morning Attnd Grade 9');
    kleosis_create_sample_class('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1', $course_nids[25], 'fy', '1', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1');
    kleosis_create_sample_class('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 2', $course_nids[25], 'fy', '2', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec 2');

  $course_nids[26] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Morning Attnd Grade 10', 'HRAttm10', 'general_academic', 'general', 'attendance', '10', 'Description for Kleosis auto generated Homeroom-Morning Attnd Grade 10');
    kleosis_create_sample_class('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1', $course_nids[26], 'fy', '1', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1');
    kleosis_create_sample_class('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 2', $course_nids[26], 'fy', '2', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec 2');

  $course_nids[27] = kleosis_create_sample_course('Kleosis auto generated Computer Course 101', 'Computer101', 'general_academic', 'general', 'standard', '9', 'Description for Kleosis auto generated Computer Course 101');
    kleosis_create_sample_class('Kleosis sample Computer 101 Class - Section 1', $course_nids[27], 'fy', '1', 'Remarks for Kleosis sample Computer 101 Class - Section 1');
  $course_nids[28] = kleosis_create_sample_course('Kleosis auto generated Computer Course 201', 'Computer201', 'general_academic', 'general', 'standard', '10', 'Description for Kleosis auto generated Computer Course 201');
    kleosis_create_sample_class('Kleosis sample Computer 201 Class - Section 1', $course_nids[28], 'fy', '1', 'Remarks for Kleosis sample Computer 201 Class - Section 1');

  $course_nids[29] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Afternoon Attnd Grade 9', 'HRAtta09', 'general_academic', 'general', 'attendance', '9', 'Description for Kleosis auto generated Homeroom-Afternoon Attnd Grade 9');
   kleosis_create_sample_class('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1', $course_nids[29], 'fy', '1', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section 1');
    kleosis_create_sample_class('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 2', $course_nids[29], 'fy', '2', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section 2');

  $course_nids[30] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Afternoon Attnd Grade 10', 'HRAtta10', 'general_academic', 'general', 'attendance', '10', 'Description for Kleosis auto generated Homeroom-Afternoon Attnd Grade 10');
    kleosis_create_sample_class('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1', $course_nids[30], 'fy', '1', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1');
    kleosis_create_sample_class('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 2', $course_nids[30], 'fy', '2', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 2');

  $course_nids[31] = kleosis_create_sample_course('Kleosis Breaktime', 'Break', 'general_academic', 'other', 'lunch-breaktime', 'all', 'Description for Kleosis Breaktime');
    kleosis_create_sample_class('Kleosis Morning Break', $course_nids[31], 'fy', 'M1', 'Remarks for Kleosis Morning Break');
    kleosis_create_sample_class('Kleosis Afternoon Break', $course_nids[31], 'fy', 'A1', 'Remarks for Kleosis Afternoon Break');

  $course_nids[32] = kleosis_create_sample_course('Kleosis Lunchtime', 'Lunch', 'general_academic', 'other', 'lunch-breaktime', 'all', 'Description for Kleosis Lunchtime');
    kleosis_create_sample_class('Kleosis Lunchtime A', $course_nids[32], 'fy', 'A', 'Remarks for Kleosis Lunchtime A');
    kleosis_create_sample_class('Kleosis Lunchtime B', $course_nids[32], 'fy', 'B', 'Remarks for Kleosis Lunchtime B');

/**
 * Create a Kleosis sample course
 */
function kleosis_create_sample_course($title, $course_no, $program, $dept, $course_type, $gradelevel, $desc) {

  $node = new stdClass(); // Create a new node object
  $node->type = "course";
  node_object_prepare($node); // Set some default values

  $node->title    = $title;
  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled

  $node->uid = 1; // UID of the author of the node; or use $node->name
  $node->status = 1;
  $node->promote = 0;
  $node->sticky = 0;

  $node->ks_course_no['und'][0]['value'] = $course_no;
  $node->ks_course_program['und'][0]['value'] = $program;
  $node->ks_course_department['und'][0]['value'] = $dept;

  $node->ks_course_creation_date['und'][0]['value'] = '2011-07-12T10:30:00';

  $node->ks_course_prerequisite['und'][0]['value'] = 'None';
  $node->ks_course_type['und'][0]['value'] = $course_type;
  $node->ks_course_gradelevel['und'][0]['value'] = $gradelevel;
  $node->ks_course_status['und'][0]['value'] = 'active';
  $node->ks_course_length['und'][0]['value'] = 100;
  $node->ks_course_room_type['und'][0]['value'] = 'standard';
  $node->ks_course_lab_type['und'][0]['value'] = 'none';
  $node->ks_course_description['und'][0]['value'] = $desc ;
/*
  $node->ks_course_grade_weight['und'][0]['value'] = '75.00' ;
  $node->ks_final_exam_weight['und'][0]['value'] = '25.00' ;
  $node->ks_grade_item_a_weight['und'][0]['value'] = '0.00' ;
  $node->ks_grade_item_b_weight['und'][0]['value'] = '0.00' ;
  $node->ks_grade_item_c_weight['und'][0]['value'] = '0.00' ;
*/
  if($node = node_submit($node)) { // Prepare node for saving
      node_save($node);
    //  drupal_set_message('Course: ' . $title . ' with nid: ' . $node->nid . ' created successfully.');
  }
  return $node->nid;
}

/**
 * Create a Kleosis sample class
 */
function kleosis_create_sample_class($title, $course_nid, $term, $class_section, $remarks) {

  $start_end_date_s = '2011-08-07T10:30:00';
  $start_end_date_e = '2011-12-10T10:00:00';
  if($term == 2) {
    $start_end_date_s = '2012-01-07T10:30:00';
    $start_end_date_e = '2012-06-24T10:00:00';
  }
  $node = new stdClass(); // Create a new node object
  $node->type = "class";
  node_object_prepare($node); // Set some default values

  $node->title    = $title;
  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled

  $node->uid = 1; // UID of the author of the node; or use $node->name
  $node->status = 1;
  $node->promote = 0;
  $node->sticky = 0;

  $node->ks_class_course_ref['und'][0]['nid'] = $course_nid;
  $node->ks_class_section['und'][0]['value'] = $class_section;
  $node->ks_class_start_end_date['und'][0]['value'] = $start_end_date_s;
  $node->ks_class_start_end_date['und'][0]['value2'] = $start_end_date_e;
  $node->ks_class_academic_year['und'][0]['value'] = '2011-2012';
  $node->ks_class_term['und'][0]['value'] = $term;
  $node->ks_class_type['und'][0]['value'] = 'standard';
  $node->ks_class_status['und'][0]['value'] = 'active';
  $node->ks_class_remarks['und'][0]['value'] = $remarks;

  if($node = node_submit($node)) { // Prepare node for saving
      node_save($node);
   //   drupal_set_message('Class: ' . $title . ' with nid: ' . $node->nid . ' created successfully.');
  }
  return $node->nid;
}
