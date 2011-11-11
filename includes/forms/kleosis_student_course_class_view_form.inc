<?php
// $Id$

/**
 * @file
 *  kleosis Student Course-Class view form
 *  Provides the view form for a record in the student course class list table
 */

function kleosis_student_course_class_view_form() {

drupal_set_title('Student class enrollment entry');

    $build['view_return'] = array(
     '#type' => 'markup',
     '#markup' => '<p><br/>' . t('This is the kleosis_student_course_class_view_form - tbd') . '</p>',
      );

  return $build;

}



