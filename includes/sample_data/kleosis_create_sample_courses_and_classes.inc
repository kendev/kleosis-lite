<?php
/**
 * @file
 * Create the sample courses and classes for kleosis
 */
/*
general academic = 1
standard = 1
mathematics = 5
languages = 1
science = 2
art = 3
general = 6
attendance = 4
lunch-breaktime = 5
other = 6
*/
  $course_nids = array();

  $course_nids[0] = kleosis_create_sample_course('Kleosis auto generated Math Course 101', 'Math101', '1', '5', '1', '12', 'Description for Kleosis auto generated Math Course 101');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 101 Class - Section 1', $course_nids[0], 'fy', '1', 'Remarks for Kleosis sample Math 101 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 101 Class - Section 2', $course_nids[0], 'fy', '2', 'Remarks for Kleosis sample Math 101 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 101 Class - Section S1', $course_nids[0], '3', 'S1', 'Remarks for Kleosis sample Math 101 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 101 Class - Section 1', $course_nids[0], 'fy', '1', 'Remarks for Kleosis sample Math 101 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 101 Class - Section 2', $course_nids[0], 'fy', '2', 'Remarks for Kleosis sample Math 101 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 101 Class - Section S1', $course_nids[0], '3', 'S1', 'Remarks for Kleosis sample Math 101 Class - Section S1');
  $course_nids[1] = kleosis_create_sample_course('Kleosis auto generated Math Course 102', 'Math102', '1', '5', '1', '12', 'Description for Kleosis auto generated Math Course 102');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 102 Class - Section 1', $course_nids[1], '1', '1', 'Remarks for Kleosis sample Math 102 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 102 Class - Section 2', $course_nids[1], '1', '2', 'Remarks for Kleosis sample Math 102 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 102 Class - Section S1', $course_nids[1], '3', '2', 'Remarks for Kleosis sample Math 102 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 102 Class - Section 1', $course_nids[1], '1', '1', 'Remarks for Kleosis sample Math 102 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 102 Class - Section 2', $course_nids[1], '1', '2', 'Remarks for Kleosis sample Math 102 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 102 Class - Section S1', $course_nids[1], '3', '2', 'Remarks for Kleosis sample Math 102 Class - Section S1');
  $course_nids[2] = kleosis_create_sample_course('Kleosis auto generated Math Course 103', 'Math103', '1', '5', '1', '12', 'Description for Kleosis auto generated Math Course 103');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 103 Class - Section 1', $course_nids[2], '2', '1', 'Remarks for Kleosis sample Math 103 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 103 Class - Section 2', $course_nids[2], '2', '2', 'Remarks for Kleosis sample Math 103 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 103 Class - Section S1', $course_nids[2], '3', 'S1', 'Remarks for Kleosis sample Math 103 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 103 Class - Section 1', $course_nids[2], '2', '1', 'Remarks for Kleosis sample Math 103 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 103 Class - Section 2', $course_nids[2], '2', '2', 'Remarks for Kleosis sample Math 103 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 103 Class - Section S1', $course_nids[2], '3', 'S1', 'Remarks for Kleosis sample Math 103 Class - Section S1');
  $course_nids[3] = kleosis_create_sample_course('Kleosis auto generated English Course 101', 'English101', '1', '1', '1', '12', 'Description for Kleosis auto generated English Course 101');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 101 Class - Section 1', $course_nids[3], 'fy', '1', 'Remarks for Kleosis sample English 101 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 101 Class - Section 2', $course_nids[3], 'fy', '2', 'Remarks for Kleosis sample English 101 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 101 Class - Section S1', $course_nids[3], '3', '3', 'Remarks for Kleosis sample English 101 Class - Section S1');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 101 Class - Section 4', $course_nids[3], 'fy', '4', 'Remarks for Kleosis sample English 101 Class - Section 4');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 101 Class - Section 5', $course_nids[3], 'fy', '5', 'Remarks for Kleosis sample English 101 Class - Section 5');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 101 Class - Section 1', $course_nids[3], 'fy', '1', 'Remarks for Kleosis sample English 101 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 101 Class - Section 2', $course_nids[3], 'fy', '2', 'Remarks for Kleosis sample English 101 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 101 Class - Section S1', $course_nids[3], '3', '3', 'Remarks for Kleosis sample English 101 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 101 Class - Section 4', $course_nids[3], 'fy', '4', 'Remarks for Kleosis sample English 101 Class - Section 4');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 101 Class - Section 5', $course_nids[3], 'fy', '5', 'Remarks for Kleosis sample English 101 Class - Section 5');
  $course_nids[4] = kleosis_create_sample_course('Kleosis auto generated English Course 102', 'English102', '1', '1', '1', '12', 'Description for Kleosis auto generated English Course 102');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 102 Class - Section 1', $course_nids[4], 'fy', '1', 'Remarks for Kleosis sample English 102 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 102 Class - Section 2', $course_nids[4], 'fy', '2', 'Remarks for Kleosis sample English 102 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 102 Class - Section S1', $course_nids[4], '3', 'S1', 'Remarks for Kleosis sample English 102 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 102 Class - Section 1', $course_nids[4], 'fy', '1', 'Remarks for Kleosis sample English 102 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 102 Class - Section 2', $course_nids[4], 'fy', '2', 'Remarks for Kleosis sample English 102 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 102 Class - Section S1', $course_nids[4], '3', 'S1', 'Remarks for Kleosis sample English 102 Class - Section S1');
  $course_nids[5] = kleosis_create_sample_course('Kleosis auto generated Science Course 101', 'Science101', '1', '2', '1', '12', 'Description for Kleosis auto generated Science Course 101');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 101 Class - Section 1', $course_nids[5], 'fy', '1', 'Remarks for Kleosis sample Science 101 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 101 Class - Section 2', $course_nids[5], 'fy', '2', 'Remarks for Kleosis sample Science 101 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 101 Class - Section S1', $course_nids[5], '3', 'S1', 'Remarks for Kleosis sample Science 101 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 101 Class - Section 1', $course_nids[5], 'fy', '1', 'Remarks for Kleosis sample Science 101 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 101 Class - Section 2', $course_nids[5], 'fy', '2', 'Remarks for Kleosis sample Science 101 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 101 Class - Section S1', $course_nids[5], '3', 'S1', 'Remarks for Kleosis sample Science 101 Class - Section S1');
  $course_nids[6] = kleosis_create_sample_course('Kleosis auto generated Science Course 102', 'Science102', '1', '2', '1', '12', 'Description for Kleosis auto generated Science Course 102');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 102 Class - Section 1', $course_nids[6], '1', '1', 'Remarks for Kleosis sample Science 102 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 102 Class - Section 2', $course_nids[6], '1', '2', 'Remarks for Kleosis sample Science 102 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 102 Class - Section S1', $course_nids[6], '3', 'S1', 'Remarks for Kleosis sample Science 102 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 102 Class - Section 1', $course_nids[6], '1', '1', 'Remarks for Kleosis sample Science 102 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 102 Class - Section 2', $course_nids[6], '1', '2', 'Remarks for Kleosis sample Science 102 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 102 Class - Section S1', $course_nids[6], '3', 'S1', 'Remarks for Kleosis sample Science 102 Class - Section S1');

  $course_nids[7] = kleosis_create_sample_course('Kleosis auto generated Art Course 201', 'Art201', '1', '3', '1', '13', 'Description for Kleosis auto generated Art Course 201');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 201 Class - Section 1', $course_nids[7], 'fy', '1', 'Remarks for Kleosis sample Art 201 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 201 Class - Section 2', $course_nids[7], 'fy', '2', 'Remarks for Kleosis sample Art 201 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 201 Class - Section S1', $course_nids[7], '3', 'S1', 'Remarks for Kleosis sample Art 201 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 201 Class - Section 1', $course_nids[7], 'fy', '1', 'Remarks for Kleosis sample Art 201 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 201 Class - Section 2', $course_nids[7], 'fy', '2', 'Remarks for Kleosis sample Art 201 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 201 Class - Section S1', $course_nids[7], '3', 'S1', 'Remarks for Kleosis sample Art 201 Class - Section S1');
  $course_nids[8] = kleosis_create_sample_course('Kleosis auto generated Art Course 202', 'Art202', 'advanced_academic', '3', '1', '13', 'Description for Kleosis auto generated Art Course 202');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 202 Class - Section 1', $course_nids[8], '1', '1', 'Remarks for Kleosis sample Art 202 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 202 Class - Section 2', $course_nids[8], '1', '2', 'Remarks for Kleosis sample Art 202 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 202 Class - Section S1', $course_nids[8], '3', 'S1', 'Remarks for Kleosis sample Art 202 Class - Section S1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 202 Class - Section 4', $course_nids[8], '1', '4', 'Remarks for Kleosis sample Art 202 Class - Section 4');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 202 Class - Section 1', $course_nids[8], '1', '1', 'Remarks for Kleosis sample Art 202 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 202 Class - Section 2', $course_nids[8], '1', '2', 'Remarks for Kleosis sample Art 202 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 202 Class - Section S1', $course_nids[8], '3', 'S1', 'Remarks for Kleosis sample Art 202 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 202 Class - Section 4', $course_nids[8], '1', '4', 'Remarks for Kleosis sample Art 202 Class - Section 4');
  $course_nids[9] = kleosis_create_sample_course('Kleosis auto generated Art Course 203', 'Art203', 'advanced_academic', '3', '1', '13', 'Description for Kleosis auto generated Art Course 203');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 203 Class - Section 1', $course_nids[9], '2', '1', 'Remarks for Kleosis sample Art 203 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 203 Class - Section 2', $course_nids[9], '2', '2', 'Remarks for Kleosis sample Art 203 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 203 Class - Section S1', $course_nids[9], '3', 'S1', 'Remarks for Kleosis sample Art 203 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 203 Class - Section 1', $course_nids[9], '2', '1', 'Remarks for Kleosis sample Art 203 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 203 Class - Section 2', $course_nids[9], '2', '2', 'Remarks for Kleosis sample Art 203 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 203 Class - Section S1', $course_nids[9], '3', 'S1', 'Remarks for Kleosis sample Art 203 Class - Section S1');

  $course_nids[10] = kleosis_create_sample_course('Kleosis auto generated Math Course 201', 'Math201', '1', '5', '1', '13', 'Description for Kleosis auto generated Math Course 201');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 201 Class - Section 1', $course_nids[10], 'fy', '1', 'Remarks for Kleosis sample Math 201 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 201 Class - Section 2', $course_nids[10], 'fy', '2', 'Remarks for Kleosis sample Math 201 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 201 Class - Section S1', $course_nids[10], '3', 'S1', 'Remarks for Kleosis sample Math 201 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 201 Class - Section 1', $course_nids[10], 'fy', '1', 'Remarks for Kleosis sample Math 201 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 201 Class - Section 2', $course_nids[10], 'fy', '2', 'Remarks for Kleosis sample Math 201 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 201 Class - Section S1', $course_nids[10], '3', 'S1', 'Remarks for Kleosis sample Math 201 Class - Section S1');
  $course_nids[11] = kleosis_create_sample_course('Kleosis auto generated Math Course 202', 'Math202', '1', '5', '1', '13', 'Description for Kleosis auto generated Math Course 202');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 202 Class - Section 1', $course_nids[11], '1', '1', 'Remarks for Kleosis sample Math 202 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 202 Class - Section 2', $course_nids[11], '1', '2', 'Remarks for Kleosis sample Math 202 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 202 Class - Section S1', $course_nids[11], '3', 'S1', 'Remarks for Kleosis sample Math 202 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 202 Class - Section 1', $course_nids[11], '1', '1', 'Remarks for Kleosis sample Math 202 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 202 Class - Section 2', $course_nids[11], '1', '2', 'Remarks for Kleosis sample Math 202 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 202 Class - Section S1', $course_nids[11], '3', 'S1', 'Remarks for Kleosis sample Math 202 Class - Section S1');
  $course_nids[12] = kleosis_create_sample_course('Kleosis auto generated Math Course 203', 'Math203', '1', '5', '1', '13', 'Description for Kleosis auto generated Math Course 203');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 203 Class - Section 1', $course_nids[12], '2', '1', 'Remarks for Kleosis sample Math 203 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 203 Class - Section 2', $course_nids[12], '2', '2', 'Remarks for Kleosis sample Math 203 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Math 203 Class - Section S1', $course_nids[12], '3', 'S1', 'Remarks for Kleosis sample Math 203 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 203 Class - Section 1', $course_nids[12], '2', '1', 'Remarks for Kleosis sample Math 203 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 203 Class - Section 2', $course_nids[12], '2', '2', 'Remarks for Kleosis sample Math 203 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Math 203 Class - Section S1', $course_nids[12], '3', 'S1', 'Remarks for Kleosis sample Math 203 Class - Section S1');
  $course_nids[13] = kleosis_create_sample_course('Kleosis auto generated English Course 201', 'English201', '1', '1', '1', '13', 'Description for Kleosis auto generated English Course 201');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 201 Class - Section 1', $course_nids[13], 'fy', '1', 'Remarks for Kleosis sample English 201 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 201 Class - Section 2', $course_nids[13], 'fy', '2', 'Remarks for Kleosis sample English 201 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 201 Class - Section S1', $course_nids[13], '3', 'S1', 'Remarks for Kleosis sample English 201 Class - Section S1');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 201 Class - Section 4', $course_nids[13], 'fy', '4', 'Remarks for Kleosis sample English 201 Class - Section 4');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 201 Class - Section 5', $course_nids[13], 'fy', '5', 'Remarks for Kleosis sample English 201 Class - Section 5');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 201 Class - Section 1', $course_nids[13], 'fy', '1', 'Remarks for Kleosis sample English 201 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 201 Class - Section 2', $course_nids[13], 'fy', '2', 'Remarks for Kleosis sample English 201 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 201 Class - Section S1', $course_nids[13], '3', 'S1', 'Remarks for Kleosis sample English 201 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 201 Class - Section 4', $course_nids[13], 'fy', '4', 'Remarks for Kleosis sample English 201 Class - Section 4');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 201 Class - Section 5', $course_nids[13], 'fy', '5', 'Remarks for Kleosis sample English 201 Class - Section 5');
  $course_nids[14] = kleosis_create_sample_course('Kleosis auto generated English Course 202', 'English202', '1', '1', '1', '13', 'Description for Kleosis auto generated English Course 202');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 202 Class - Section 1', $course_nids[14], 'fy', '1', 'Remarks for Kleosis sample English 202 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 202 Class - Section 2', $course_nids[14], 'fy', '2', 'Remarks for Kleosis sample English 202 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample English 202 Class - Section S1', $course_nids[14], '3', 'S1', 'Remarks for Kleosis sample English 202 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 202 Class - Section 1', $course_nids[14], 'fy', '1', 'Remarks for Kleosis sample English 202 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 202 Class - Section 2', $course_nids[14], 'fy', '2', 'Remarks for Kleosis sample English 202 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample English 202 Class - Section S1', $course_nids[14], '3', 'S1', 'Remarks for Kleosis sample English 202 Class - Section S1');
  $course_nids[15] = kleosis_create_sample_course('Kleosis auto generated Science Course 201', 'Science201', '1', '2', '1', '13', 'Description for Kleosis auto generated Science Course 201');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 201 Class - Section 1', $course_nids[15], 'fy', '1', 'Remarks for Kleosis sample Science 201 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 201 Class - Section 2', $course_nids[15], 'fy', '2', 'Remarks for Kleosis sample Science 201 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 201 Class - Section S1', $course_nids[15], '3', 'S1', 'Remarks for Kleosis sample Science 201 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 201 Class - Section 1', $course_nids[15], 'fy', '1', 'Remarks for Kleosis sample Science 201 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 201 Class - Section 2', $course_nids[15], 'fy', '2', 'Remarks for Kleosis sample Science 201 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 201 Class - Section S1', $course_nids[15], '3', 'S1', 'Remarks for Kleosis sample Science 201 Class - Section S1');
  $course_nids[16] = kleosis_create_sample_course('Kleosis auto generated Science Course 202', 'Science202', '1', '2', '1', '13', 'Description for Kleosis auto generated Science Course 202');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 202 Class - Section 1', $course_nids[16], '2', '1', 'Remarks for Kleosis sample Science 202 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 202 Class - Section 2', $course_nids[16], '2', '2', 'Remarks for Kleosis sample Science 202 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Science 202 Class - Section S1', $course_nids[16], '3', 'S1', 'Remarks for Kleosis sample Science 202 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 202 Class - Section 1', $course_nids[16], '2', '1', 'Remarks for Kleosis sample Science 202 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 202 Class - Section 2', $course_nids[16], '2', '2', 'Remarks for Kleosis sample Science 202 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Science 202 Class - Section S1', $course_nids[16], '3', 'S1', 'Remarks for Kleosis sample Science 202 Class - Section S1');
  $course_nids[17] = kleosis_create_sample_course('Kleosis auto generated Art Course 310', 'Art310', '1', '3', '1', '11', 'Description for Kleosis auto generated Art Course 310');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 310 Class - Section 1', $course_nids[17], 'fy', '1', 'Remarks for Kleosis sample Art 310 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 310 Class - Section 2', $course_nids[17], 'fy', '2', 'Remarks for Kleosis sample Art 310 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 310 Class - Section S1', $course_nids[17], '3', 'S1', 'Remarks for Kleosis sample Art 310 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 310 Class - Section 1', $course_nids[17], 'fy', '1', 'Remarks for Kleosis sample Art 310 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 310 Class - Section 2', $course_nids[17], 'fy', '2', 'Remarks for Kleosis sample Art 310 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 310 Class - Section S1', $course_nids[17], '3', 'S1', 'Remarks for Kleosis sample Art 310 Class - Section S1');
  $course_nids[18] = kleosis_create_sample_course('Kleosis auto generated Art Course 311', 'Art311', 'advanced_academic', '3', '1', '11', 'Description for Kleosis auto generated Art Course 311');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 311 Class - Section 1', $course_nids[18], '2', '1', 'Remarks for Kleosis sample Art 311 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 311 Class - Section 2', $course_nids[18], '2', '2', 'Remarks for Kleosis sample Art 311 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 311 Class - Section S1', $course_nids[18], '3', 'S1', 'Remarks for Kleosis sample Art 311 Class - Section S1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 311 Class - Section 4', $course_nids[18], '2', '4', 'Remarks for Kleosis sample Art 311 Class - Section 4');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 311 Class - Section 1', $course_nids[18], '2', '1', 'Remarks for Kleosis sample Art 311 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 311 Class - Section 2', $course_nids[18], '2', '2', 'Remarks for Kleosis sample Art 311 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 311 Class - Section S1', $course_nids[18], '3', 'S1', 'Remarks for Kleosis sample Art 311 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 311 Class - Section 4', $course_nids[18], '2', '4', 'Remarks for Kleosis sample Art 311 Class - Section 4');
  $course_nids[19] = kleosis_create_sample_course('Kleosis auto generated Art Course 312', 'Art312', 'advanced_academic', '3', '1', '12', 'Description for Kleosis auto generated Art Course 312');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 312 Class - Section 1', $course_nids[19], '2', '1', 'Remarks for Kleosis sample Art 312 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 312 Class - Section 2', $course_nids[19], '2', '2', 'Remarks for Kleosis sample Art 312 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 312 Class - Section S1', $course_nids[19], '3', 'S1', 'Remarks for Kleosis sample Art 312 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 312 Class - Section 1', $course_nids[19], '2', '1', 'Remarks for Kleosis sample Art 312 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 312 Class - Section 2', $course_nids[19], '2', '2', 'Remarks for Kleosis sample Art 312 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 312 Class - Section S1', $course_nids[19], '3', 'S1', 'Remarks for Kleosis sample Art 312 Class - Section S1');
  $course_nids[20] = kleosis_create_sample_course('Kleosis auto generated Art Course 101', 'Art101', '1', '3', '1', '12', 'Description for Kleosis auto generated Art Course 101');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 101 Class - Section 1', $course_nids[20], 'fy', '1', 'Remarks for Kleosis sample Art 101 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 101 Class - Section 2', $course_nids[20], 'fy', '2', 'Remarks for Kleosis sample Art 101 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Art 101 Class - Section S1', $course_nids[20], '3', 'S1', 'Remarks for Kleosis sample Art 101 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 101 Class - Section 1', $course_nids[20], 'fy', '1', 'Remarks for Kleosis sample Art 101 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 101 Class - Section 2', $course_nids[20], 'fy', '2', 'Remarks for Kleosis sample Art 101 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Art 101 Class - Section S1', $course_nids[20], '3', 'S1', 'Remarks for Kleosis sample Art 101 Class - Section S1');

  $course_nids[21] = kleosis_create_sample_course('Kleosis auto generated PE Course 101', 'PE101', '1', '6', '1', '12', 'Description for Kleosis auto generated PE Course 101');
    kleosis_create_sample_class_2011_2012('Kleosis sample PE 101 Class - Section 1', $course_nids[21], 'fy', '1', 'Remarks for Kleosis sample PE 101 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample PE 101 Class - Section 2', $course_nids[21], 'fy', '2', 'Remarks for Kleosis sample PE 101 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample PE 101 Class - Section S1', $course_nids[21], '3', 'S1', 'Remarks for Kleosis sample PE 101 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample PE 101 Class - Section 1', $course_nids[21], 'fy', '1', 'Remarks for Kleosis sample PE 101 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample PE 101 Class - Section 2', $course_nids[21], 'fy', '2', 'Remarks for Kleosis sample PE 101 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample PE 101 Class - Section S1', $course_nids[21], '3', 'S1', 'Remarks for Kleosis sample PE 101 Class - Section S1');
  $course_nids[22] = kleosis_create_sample_course('Kleosis auto generated Music Course 101', 'Music101', '1', '6', '1', '12', 'Description for Kleosis auto generated Music Course 101');
    kleosis_create_sample_class_2011_2012('Kleosis sample Music 101 Class - Section 1', $course_nids[22], 'fy', '1', 'Remarks for Kleosis sample Music 101 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Music 101 Class - Section 2', $course_nids[22], 'fy', '2', 'Remarks for Kleosis sample Music 101 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Music 101 Class - Section S1', $course_nids[22], '3', 'S1', 'Remarks for Kleosis sample Music 101 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Music 101 Class - Section 1', $course_nids[22], 'fy', '1', 'Remarks for Kleosis sample Music 101 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Music 101 Class - Section 2', $course_nids[22], 'fy', '2', 'Remarks for Kleosis sample Music 101 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Music 101 Class - Section S1', $course_nids[22], '3', 'S1', 'Remarks for Kleosis sample Music 101 Class - Section S1');
  $course_nids[23] = kleosis_create_sample_course('Kleosis auto generated PE Course 201', 'PE201', '1', '6', '1', '13', 'Description for Kleosis auto generated PE Course 201');
    kleosis_create_sample_class_2011_2012('Kleosis sample PE 201 Class - Section 1', $course_nids[23], 'fy', '1', 'Remarks for Kleosis sample PE 201 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample PE 201 Class - Section 2', $course_nids[23], 'fy', '2', 'Remarks for Kleosis sample PE 201 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample PE 201 Class - Section S1', $course_nids[23], '3', 'S1', 'Remarks for Kleosis sample PE 201 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample PE 201 Class - Section 1', $course_nids[23], 'fy', '1', 'Remarks for Kleosis sample PE 201 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample PE 201 Class - Section 2', $course_nids[23], 'fy', '2', 'Remarks for Kleosis sample PE 201 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample PE 201 Class - Section S1', $course_nids[23], '3', 'S1', 'Remarks for Kleosis sample PE 201 Class - Section S1');
  $course_nids[24] = kleosis_create_sample_course('Kleosis auto generated Music Course 201', 'Music201', '1', '6', '1', '13', 'Description for Kleosis auto generated Music Course 201');
    kleosis_create_sample_class_2011_2012('Kleosis sample Music 201 Class - Section 1', $course_nids[24], 'fy', '1', 'Remarks for Kleosis sample Music 201 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Music 201 Class - Section 2', $course_nids[24], 'fy', '2', 'Remarks for Kleosis sample Music 201 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis sample Music 201 Class - Section S1', $course_nids[24], '3', 'S1', 'Remarks for Kleosis sample Music 201 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Music 201 Class - Section 1', $course_nids[24], 'fy', '1', 'Remarks for Kleosis sample Music 201 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Music 201 Class - Section 2', $course_nids[24], 'fy', '2', 'Remarks for Kleosis sample Music 201 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis sample Music 201 Class - Section S1', $course_nids[24], '3', 'S1', 'Remarks for Kleosis sample Music 201 Class - Section S1');

  $course_nids[25] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Morning Attnd Grade 9', 'HRAttm09', '1', '6', '4', '12', 'Description for Kleosis auto generated Homeroom-Morning Attnd Grade 9');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1', $course_nids[25], 'fy', '1', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 2', $course_nids[25], 'fy', '2', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec 2');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Morning Attnd G-9 Class - Sec S1', $course_nids[25], '3', 'S1', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec S1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1', $course_nids[25], 'fy', '1', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Morning Attnd G-9 Class - Sec 2', $course_nids[25], 'fy', '2', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec 2');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Morning Attnd G-9 Class - Sec S1', $course_nids[25], '3', 'S1', 'Remarks for Kleosis Homeroom-Morning Attnd G-9 Class - Sec S1');

  $course_nids[26] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Morning Attnd Grade 10', 'HRAttm10', '1', '6', '4', '13', 'Description for Kleosis auto generated Homeroom-Morning Attnd Grade 10');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1', $course_nids[26], 'fy', '1', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 2', $course_nids[26], 'fy', '2', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec 2');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Morning Attnd G-10 Class - Sec S1', $course_nids[26], '3', 'S1', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec S1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1', $course_nids[26], 'fy', '1', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Morning Attnd G-10 Class - Sec 2', $course_nids[26], 'fy', '2', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec 2');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Morning Attnd G-10 Class - Sec S1', $course_nids[26], '3', 'S1', 'Remarks for Kleosis Homeroom-Morning Attnd G-10 Class - Sec S1');

  $course_nids[27] = kleosis_create_sample_course('Kleosis auto generated Computer Course 101', 'Computer101', '1', '6', '1', '12', 'Description for Kleosis auto generated Computer Course 101');
    kleosis_create_sample_class_2011_2012('Kleosis sample Computer 101 Class - Section 1', $course_nids[27], 'fy', '1', 'Remarks for Kleosis sample Computer 101 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Computer 101 Class - Section S1', $course_nids[27], '3', 'S1', 'Remarks for Kleosis sample Computer 101 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Computer 101 Class - Section 1', $course_nids[27], 'fy', '1', 'Remarks for Kleosis sample Computer 101 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Computer 101 Class - Section S1', $course_nids[27], '3', 'S1', 'Remarks for Kleosis sample Computer 101 Class - Section S1');

  $course_nids[28] = kleosis_create_sample_course('Kleosis auto generated Computer Course 201', 'Computer201', '1', '6', '1', '13', 'Description for Kleosis auto generated Computer Course 201');
    kleosis_create_sample_class_2011_2012('Kleosis sample Computer 201 Class - Section 1', $course_nids[28], 'fy', '1', 'Remarks for Kleosis sample Computer 201 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis sample Computer 201 Class - Section S1', $course_nids[28], '3', 'S1', 'Remarks for Kleosis sample Computer 201 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Computer 201 Class - Section 1', $course_nids[28], 'fy', '1', 'Remarks for Kleosis sample Computer 201 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis sample Computer 201 Class - Section S1', $course_nids[28], '3', 'S1', 'Remarks for Kleosis sample Computer 201 Class - Section S1');

  $course_nids[29] = kleosis_create_sample_course('Kleosis Breaktime', 'Break', '1', '6', '5', 'all', 'Description for Kleosis Breaktime');
    kleosis_create_sample_class_2011_2012('Kleosis Morning Break', $course_nids[29], 'fy', 'M1', 'Remarks for Kleosis Morning Break');
    kleosis_create_sample_class_2011_2012('Kleosis Morning Break S1', $course_nids[29], '3', 'S1', 'Remarks for Kleosis Morning Break');
    kleosis_create_sample_class_2011_2012('Kleosis Afternoon Break', $course_nids[29], 'fy', 'A1', 'Remarks for Kleosis Afternoon Break');
    kleosis_create_sample_class_2011_2012('Kleosis Afternoon Break S1', $course_nids[29], '3', 'S1', 'Remarks for Kleosis Afternoon Break');
    kleosis_create_sample_class_2012_2013('Kleosis Morning Break', $course_nids[29], 'fy', 'M1', 'Remarks for Kleosis Morning Break');
    kleosis_create_sample_class_2012_2013('Kleosis Morning Break S1', $course_nids[29], '3', 'S1', 'Remarks for Kleosis Morning Break');
    kleosis_create_sample_class_2012_2013('Kleosis Afternoon Break', $course_nids[29], 'fy', 'A1', 'Remarks for Kleosis Afternoon Break');
    kleosis_create_sample_class_2012_2013('Kleosis Afternoon Break S1', $course_nids[29], '3', 'S1', 'Remarks for Kleosis Afternoon Break');

  $course_nids[30] = kleosis_create_sample_course('Kleosis Lunchtime', 'Lunch', '1', '6', '5', 'all', 'Description for Kleosis Lunchtime');
    kleosis_create_sample_class_2011_2012('Kleosis Lunchtime A', $course_nids[30], 'fy', 'A', 'Remarks for Kleosis Lunchtime A');
    kleosis_create_sample_class_2011_2012('Kleosis Lunchtime S1', $course_nids[30], '3', 'S1', 'Remarks for Kleosis Lunchtime S1');
    kleosis_create_sample_class_2011_2012('Kleosis Lunchtime B', $course_nids[30], 'fy', 'B', 'Remarks for Kleosis Lunchtime B');
    kleosis_create_sample_class_2012_2013('Kleosis Lunchtime A', $course_nids[30], 'fy', 'A', 'Remarks for Kleosis Lunchtime A');
    kleosis_create_sample_class_2012_2013('Kleosis Lunchtime S1', $course_nids[30], '3', 'S1', 'Remarks for Kleosis Lunchtime S1');
    kleosis_create_sample_class_2012_2013('Kleosis Lunchtime B', $course_nids[30], 'fy', 'B', 'Remarks for Kleosis Lunchtime B');

/*
  $course_nids[31] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Afternoon Attnd Grade 9', 'HRAtta09', '1', '6', '4', '12', 'Description for Kleosis auto generated Homeroom-Afternoon Attnd Grade 9');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1', $course_nids[31], 'fy', '1', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section 1');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 2', $course_nids[31], 'fy', '2', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section 2');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec S1', $course_nids[31], '3', 'S1', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section S1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1', $course_nids[31], 'fy', '1', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section 1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 2', $course_nids[31], 'fy', '2', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section 2');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec S1', $course_nids[31], '3', 'S1', 'Remarks for Kleosis sample Homeroom-Afternoon Grade 9 Class - Section S1');
*/
  $course_nids[32] = kleosis_create_sample_course('Kleosis auto generated Homeroom-Afternoon Attnd Grade 10', 'HRAtta10', '1', '6', '4', '13', 'Description for Kleosis auto generated Homeroom-Afternoon Attnd Grade 10');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1', $course_nids[32], 'fy', '1', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 2', $course_nids[32], 'fy', '2', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 2');
    kleosis_create_sample_class_2011_2012('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec S1', $course_nids[32], '3', 'S1', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec S1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1', $course_nids[32], 'fy', '1', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 2', $course_nids[32], 'fy', '2', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 2');
    kleosis_create_sample_class_2012_2013('Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec S1', $course_nids[32], '3', 'S1', 'Remarks for Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec S1');

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
  $node->ks_course_status['und'][0]['value'] = '1'; // active
  $node->ks_course_length['und'][0]['value'] = 100;
  $node->ks_course_room_type['und'][0]['value'] = '1'; // Standard
  $node->ks_course_lab_type['und'][0]['value'] = '0'; // none
  $node->ks_course_description['und'][0]['value'] = $desc ;
/*
  $node->ks_course_grade_weight['und'][0]['value'] = '75.00' ;
  $node->ks_final_exam_weight['und'][0]['value'] = '25.00' ;
  $node->ks_grade_item_a_weight['und'][0]['value'] = '0.00' ;
  $node->ks_grade_item_b_weight['und'][0]['value'] = '0.00' ;
  $node->ks_grade_item_c_weight['und'][0]['value'] = '0.00' ;
*/
  if ($node = node_submit($node)) { // Prepare node for saving
      node_save($node);
    //  drupal_set_message('Course: ' . $title . ' with nid: ' . $node->nid . ' created successfully.');
  }
  return $node->nid;
}

/**
 * Create a Kleosis sample class for academic year 2011-2012
 */
function kleosis_create_sample_class_2011_2012($title, $course_nid, $term, $class_section, $remarks) {

  $start_end_date_s = '2011-08-07T08:00:00';  // assume term = fy
  $start_end_date_e = '2012-06-24T08:00:00';
  if ($term == 1) {
    $start_end_date_s = '2011-08-07T08:00:00';
    $start_end_date_e = '2011-12-27T08:00:00';
  }
  elseif ($term == 2) {
    $start_end_date_s = '2012-01-07T08:00:00';
    $start_end_date_e = '2012-06-24T08:00:00';
  }
  elseif ($term == 3) {
    $start_end_date_s = '2012-06-28T08:00:00';
    $start_end_date_e = '2012-07-29T08:00:00';
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
  $node->ks_class_type['und'][0]['value'] = '1';  // Standard
  $node->ks_class_status['und'][0]['value'] = '1';  // active
  $node->ks_class_remarks['und'][0]['value'] = $remarks;

  if ($node = node_submit($node)) { // Prepare node for saving
      node_save($node);
   //   drupal_set_message('Class: ' . $title . ' with nid: ' . $node->nid . ' created successfully.');
  }
  return $node->nid;
}
/**
 * Create a Kleosis sample class for academic year 2012-2013
 */
function kleosis_create_sample_class_2012_2013($title, $course_nid, $term, $class_section, $remarks) {

  $start_end_date_s = '2012-08-07T08:00:00';  // assume term = fy
  $start_end_date_e = '2013-06-24T08:00:00';
  if ($term == 1) {
    $start_end_date_s = '2012-08-07T08:00:00';
    $start_end_date_e = '2012-12-25T08:00:00';
  }
  elseif ($term == 2) {
    $start_end_date_s = '2013-01-07T08:00:00';
    $start_end_date_e = '2013-06-24T08:00:00';
  }
  elseif ($term == 3) {
    $start_end_date_s = '2013-06-27T08:00:00';
    $start_end_date_e = '2013-07-29T08:00:00';
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
  $node->ks_class_academic_year['und'][0]['value'] = '2012-2013';
  $node->ks_class_term['und'][0]['value'] = $term;
  $node->ks_class_type['und'][0]['value'] = '1';  // Standard
  $node->ks_class_status['und'][0]['value'] = '1';  // active
  $node->ks_class_remarks['und'][0]['value'] = $remarks;

  if ($node = node_submit($node)) { // Prepare node for saving
      node_save($node);
   //   drupal_set_message('Class: ' . $title . ' with nid: ' . $node->nid . ' created successfully.');
  }
  return $node->nid;
}
