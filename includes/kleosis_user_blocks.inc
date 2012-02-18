<?php

/**
 * @file
 *  Kleosis User Blocks
 *
 *  Provides the blocks and ui functionality for Kleosis users
 */

require_once ('kleosis_ws.inc');  // webservices wrapper functions
require_once ('kleosis_db_lib.inc');  // lib functions

/**
 *  Implements hook_block_info()
 */
function kleosis_block_info() {

  $blocks['my_courses'] = array(
    'info' => t('My Courses - LMS Direct'),
    'status' => FALSE,
    'region' => 'sidebar_first',
    'weight' => -4,
  );
  $blocks['my_assignments'] = array(
    'info' => t('My Assignments - LMS Direct'),
    'status' => FALSE,
    'region' => 'sidebar_first',
    'weight' => -3,
  );
  $blocks['my_forums'] = array(
    'info' => t('My Forums - LMS Direct'),
    'status' => FALSE,
    'region' => 'sidebar_first',
    'weight' => -2,
  );
  $blocks['my_quizes'] = array(
    'info' => t('My Quizes - LMS Direct'),
    'status' => FALSE,
    'region' => 'sidebar_first',
    'weight' => -1,
  );
  $blocks['my_grades'] = array(
    'info' => t('My Grades - LMS Direct'),
    'status' => FALSE,
    'region' => 'sidebar_first',
    'weight' => -0,
  );
  return $blocks;
}

/**
 *  Implements hook_block_configure()
 */
function kleosis_block_configure($delta) {

  $form = array();

  switch ($delta) {

  case 'my_courses':
      $form['my_courses_count'] = array(
        '#type' => 'textfield',
        '#title' => t('Configure maximum number of courses to display'),
        '#size' => 3,
        '#description' => t('Enter the number of courses that will appear in the block.'),
        '#default_value' => variable_get('my_courses_count', 5),
      );
      break;
  case 'my_assignments':
      $form['my_assignments_count'] = array(
        '#type' => 'textfield',
        '#title' => t('Configure maximum number of assignments to display'),
        '#size' => 3,
        '#description' => t('Enter the number of assignments that will appear in the block.'),
        '#default_value' => variable_get('my_assignments_count', 5),
      );
      break;
  case 'my_forums':
      $form['my_forums_count'] = array(
        '#type' => 'textfield',
        '#title' => t('Configure maximum number of forums to display'),
        '#size' => 3,
        '#description' => t('Enter the number of forums that will appear in the block.'),
        '#default_value' => variable_get('my_forums_count', 5),
      );
      break;
  case 'my_quizes':
      $form['my_quizes_count'] = array(
        '#type' => 'textfield',
        '#title' => t('Configure maximum number of quizes to display'),
        '#size' => 3,
        '#description' => t('Enter the number of quizes that will appear in the block.'),
        '#default_value' => variable_get('my_quizes_count', 5),
      );
      break;
  case 'my_grades':
      $form['my_grades_count'] = array(
        '#type' => 'textfield',
        '#title' => t('Configure maximum number of grades to display'),
        '#size' => 3,
        '#description' => t('Enter the number of grades that will appear in the block.'),
        '#default_value' => variable_get('my_grades_count', 5),
      );
      break;
  case 'your_courses':

      // next block...

      break;
  }
  return $form;
}

/**
 *  Implements hook_block_save()
 */
function kleosis_block_save($delta = '', $edit = array()) {

  switch ($delta) {

  case 'my_courses':
      variable_set('my_courses_count', (int)$edit['my_courses_count']);
      break;
  case 'my_assignments':
      variable_set('my_assignments_count', (int)$edit['my_assignments_count']);
      break;
  case 'my_forums':
      variable_set('my_forums_count', (int)$edit['my_forums_count']);
      break;
  case 'my_quizes':
      variable_set('my_quizes_count', (int)$edit['my_quizes_count']);
      break;
  case 'my_grades':
      variable_set('my_grades_count', (int)$edit['my_grades_count']);
      break;
  case 'your_courses':

      // next block...

      break;
  }
}

/**
 *  Implements hook_block_view()
 */
function kleosis_block_view($delta = '') {

  switch ($delta) {

  case 'my_courses':
      $block['subject'] = t('My Courses');
      $block['content'] = kleosis_block_contents($delta);
      return $block;
      break;
  case 'my_assignments':
      $block['subject'] = t('My Assignments');
      $block['content'] = kleosis_block_contents($delta);
      return $block;
      break;
  case 'my_forums':
      $block['subject'] = t('My Forums');
      $block['content'] = kleosis_block_contents($delta);
      return $block;
      break;
  case 'my_quizes':
      $block['subject'] = t('My Quizes');
      $block['content'] = kleosis_block_contents($delta);
      return $block;
      break;
  case 'my_grades':
      $block['subject'] = t('My Grades');
      $block['content'] = kleosis_block_contents($delta);
      return $block;
      break;
  case 'your_courses':

      // next block...

      break;
  }
}

/**
 *  The Kleosis block content functions go here...
 */
function kleosis_block_contents($delta) {

  $moodle_url = variable_get('kleosis_moodle_url', 'http://localhost/moodle');

  switch ($delta) {

  case 'my_courses':

//    if (user_access('some permissions here')) {
        // todo: implement this...
//    }
      $items = array();
      $nbr_courses_to_display = variable_get('my_courses_count');
      $courses = ws_get_my_courses();
      if ($courses) {
        foreach ($courses as $key => $val) {
          if ($val['id'] != 1) {
            $items[$val['id']] = l($val['shortname'], $moodle_url . '/course/view.php', array('query' => array('id' => $val['id']), 'attributes' => array('target' => '_blank')));
          }
        }
      }
//      return array('#markup' => theme('item_list', array('items' => $items)));  // this is ok, but should return a renderable array
//      return array('#theme' => 'item_list', '#items' => $items, '#attached' => array('css' => drupal_get_path('module','kleosis') . '/css/kleosis_lms_direct_block.css'));  // this is cool - added some css...
      return array('#theme' => 'item_list', '#items' => $items, ); // this is better because it is a render array

      break;
  case 'my_assignments':

//   currently gets all assignments...

      $items = array();
      $nbr_assignments_to_display = variable_get('my_assignments_count');
      $assignments = ws_get_assignments();

      if ($assignments) {
        foreach ($assignments as $key => $val) {
          $items[$val['id']] = l($val['name'], $moodle_url . '/mod/assignment/index.php', array('query' => array('id' => $val['course']), 'attributes' => array('target' => '_blank')));
        }
      }
      return array('#markup' => theme('item_list', array('items' => $items)));

      break;
  case 'my_grades':

      $items = array();
      $nbr_grades_to_display = variable_get('my_grades_count');
      $grades = ws_get_grades();  // todo: evolve this function
      // create  an array of grades just for demo purposes
//      $items = array('0' => 'My Grade 1', '1' => 'My Grade 2', '2' => 'My Grade 3', '3' => 'My Grade 4', '4' => 'My Grade 5');
      $i = 0;
      if ( !empty($grades) ) {
      foreach ($grades as $key => $val) {
          if ( empty($val['error']) ) {
            $items[$i] = $val['itemid'] . ': &nbsp;&nbsp;&nbsp;&nbsp;' . $val['str_grade'];
            $i++;
          }
        }
      }
      asort($items);
      return array('#markup' => theme('item_list', array('items' => $items)));

      break;
  case 'my_forums':

      $nbr_forums_to_display = variable_get('my_forums_count');
//    $forums = ws_get_forums();  // todo: create this function
      // create  an array of forums just for demo purposes
      $items = array('0' => 'My Forum 1', '1' => 'My Forum 2', '2' => 'My Forum 3', '3' => 'My Forum 4', '4' => 'My Forum 5');

      return array('#markup' => theme('item_list', array('items' => $items)));

      break;
  case 'my_quizes':

      $nbr_quizes_to_display = variable_get('my_quizes_count');
//    $quizes = ws_get_quizes();  // todo: create this function
      // create  an array of quizes just for demo purposes
      $items = array('0' => 'My Quiz 1', '1' => 'My Quiz 2', '2' => 'My Quiz 3', '3' => 'My Quiz 4', '4' => 'My Quiz 5');

      return array('#markup' => theme('item_list', array('items' => $items)));

      break;
  case 'your_courses':

      // ok, right...

      break;
  }
}