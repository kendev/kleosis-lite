<?php

/**
* @file
* kleosis Grades (for LIST (_ls))
*/

/**
 * Render a filtered list of student final grades.
 *
 */
function kleosis_final_grades_ls_form($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = t('Final Grades-LS List');

  drupal_set_breadcrumb($breadcrumb);

  $build = array();
  $build['filter'] = kleosis_final_grades_ls_select_form();
  $build['#submit'][] = 'kleosis_final_grades_ls_select_form_submit';
  $build['list'] = kleosis_final_grades_ls_list();

  return $build;
}

/**
 *
 * Final grades filter by academic year, term, and class form
 *
 */

function kleosis_final_grades_ls_select_form() {

  // get the class value from the session variable (if any) and set the default value accordingly
  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  $sql = 'SELECT nid, title FROM {node} n WHERE n.type = :type AND n.status = :status ORDER BY n.title' ;
  $results = db_query($sql, array(':type' => 'class', ':status' => 1, ) );
  $form = array();
  $options = array();
  foreach ($results as $class) {
    $node = node_load($class->nid);
    $node_term =   $node->ks_class_term['und'][0]['value'];
    $node_academic_year =   $node->ks_class_academic_year['und'][0]['value'];
    if ( ($node_academic_year == $class_academic_year) || ($class_academic_year == 'all') ) { // iff year
     if ( ($node_term == $class_term) || ($class_term == 'all') ) { // iff term
        $options[$class->nid] = $class->title;
      } // iff term
    } // iff year
  }
  if (sizeof($options) == 0) {
//    drupal_set_message('empty result set');
    $options = array('0' => t('No classes exist for selected year and term'), );
  }
  // create a fieldset for the class selection
  $form['grades_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select a class'),
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['grades_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  !empty($class_academic_year) ? $class_academic_year : '2011-2012',
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $form['grades_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => !empty($class_term) ? $class_term : 'fy',
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $form['grades_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Set year and term'),
    '#weight' => 5,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );
  $form['grades_select']['class'] = array(
  '#type' => 'select',
    '#title' => t('Class'),
    '#options' =>  $options,
    '#default_value' => $class_id_from_filter,
    '#weight' => 7,
    '#prefix' => '<div style="float: left;clear:left;width:400px" >',
    '#suffix' => '</div>',
  );
  $form['grades_select']['get_grades'] = array(
    '#type' => 'submit',
    '#value' => t('Get grades'),
    '#weight' => 9,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );
  return $form;

}

/**
 *
 * Final grades list form
 *
 */
function kleosis_final_grades_ls_list() {

drupal_set_title(t('Final Grades-LS (by Class)'));

  $form = array();
$return;
  // get the filter values from the session variable (if any) and set the default form values accordingly

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  // the header contains all the fields that will be displayed in the tableselect list
//  if ($grade_item_3_exists) {
  if (3==3) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade_str' => t('Course Grade'),
      'final_exam_grade_str' => t('Final Exam'),
      'grade_item_1' => variable_get('kleosis_grade_item_1_name', t('GradeItem 1')),
      'grade_item_2' => variable_get('kleosis_grade_item_2_name', t('GradeItem 2')),
      'grade_item_3' => variable_get('kleosis_grade_item_3_name', t('GradeItem 3')),
      'final_grade_str' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
//  elseif ($grade_item_2_exists) {
  elseif (2==2) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade_str' => t('Course Grade'),
      'final_exam_grade_str' => t('Final Exam'),
      'grade_item_1' => variable_get('kleosis_grade_item_1_name', t('GradeItem 1')),
      'grade_item_2' => variable_get('kleosis_grade_item_2_name', t('GradeItem 2')),
      'final_grade_str' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
//  elseif ($grade_item_1_exists) {
  elseif (1==1) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade_str' => t('Course Grade'),
      'final_exam_grade_str' => t('Final Exam'),
      'grade_item_1' => variable_get('kleosis_grade_item_1_name', t('GradeItem 1')),
      'final_grade_str' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
//  elseif ($final_exam_grade_exists) {
  elseif (9==9) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade_str' => t('Course Grade'),
      'final_exam_grade_str' => t('Final Exam'),
      'final_grade_str' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
  else {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade_str' => t('Course Grade'),
      'final_grade_str' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }

  $students_in_the_class = kleosis_get_students_in_class_ls($class_id_from_filter);
  $options = array();

  foreach ($students_in_the_class as $student) {

    $graderow = kleosis_get_student_final_grade_record_ls($student->kstu_id_fk, $class_id_from_filter);

    $lp_kcclg = !empty($graderow) ? $graderow[0]->kcclg_id : 0;
    $lp_ksccl_id = $student->ksccl_id;

//    if ($grade_item_3_exists) {
    if (3==3) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade_str' => !empty($graderow) ? $graderow[0]->course_grade_str : '',
        'final_exam_grade_str' => !empty($graderow) ? $graderow[0]->final_exam_grade_str : '',
        'grade_item_1' => !empty($graderow) ? $graderow[0]->grade_item_1 : '',
        'grade_item_2' => !empty($graderow) ? $graderow[0]->grade_item_2 : '',
        'grade_item_3' => !empty($graderow) ? $graderow[0]->grade_item_3 : '',
        'final_grade_str' => !empty($graderow) ? $graderow[0]->final_grade_str : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades/final_grades_ls')))
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
//    elseif ($grade_item_2_exists) {
    elseif (2==2) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade_str' => !empty($graderow) ? $graderow[0]->course_grade_str : '',
        'final_exam_grade_str' => !empty($graderow) ? $graderow[0]->final_exam_grade_str : '',
        'grade_item_1' => !empty($graderow) ? $graderow[0]->grade_item_1 : '',
        'grade_item_2' => !empty($graderow) ? $graderow[0]->grade_item_2 : '',
        'final_grade_str' => !empty($graderow) ? $graderow[0]->final_grade_str : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades/final_grades_ls')))
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
//    elseif ($grade_item_1_exists) {
    elseif (1==1) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade_str' => !empty($graderow) ? $graderow[0]->course_grade_str : '',
        'final_exam_grade_str' => !empty($graderow) ? $graderow[0]->final_exam_grade_str : '',
        'grade_item_1' => !empty($graderow) ? $graderow[0]->grade_item_1 : '',
        'final_grade_str' => !empty($graderow) ? $graderow[0]->final_grade_str : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades/final_grades_ls')))
 //       'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
//    elseif ($final_exam_grade_exists) {
    elseif (9==9) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade_str' => !empty($graderow) ? $graderow[0]->course_grade_str : '',
        'final_exam_grade_str' => !empty($graderow) ? $graderow[0]->final_exam_grade_str : '',
        'final_grade_str' => !empty($graderow) ? $graderow[0]->final_grade_str : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades/final_grades_ls')))
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
     else {
      $options[$student->kstu_id_fk] = array(
//        'name' => $student->name,
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade_str' => !empty($graderow) ? $graderow[0]->course_grade_str : '',
        'final_grade_str' => !empty($graderow) ? $graderow[0]->final_grade_str : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades/final_grades_ls')))
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
  }

  $form['grades'] = array(
    '#type' => 'table',       // used for table
//        '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//        '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => ($class_id_from_filter <> 0) ? t('No students are enrolled in the selected class.') : '',
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );
  $form['pager'] = array('#markup' => theme('pager'));

  $form['grades_action']['edit_grades'] = array(
    '#type' => 'submit',
    '#value' => t('Edit all grades'),
    '#weight' => 20,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;clear:left; width:200px" >',
    '#suffix' => '</div>',
  );
return $form;
}

/**
 * Get all students in a specific class
 *
 * @param $classid
 *    The node id of the specific class
 *
 * @return
 *    Result set containing the student id and name for each class member
 */
function kleosis_get_students_in_class_ls($classid) {

  $query = db_select('ks_student_course_classes', 'ksscc');
  $query->innerJoin('users', 'u', 'u.uid = ksscc.kstu_id_fk');
  $query->addField('u', 'name');
  $query->addField('ksscc', 'ksccl_id');
  $query->addField('ksscc', 'kstu_id_fk');

  $query->condition('ksscc.' . 'kccls_id_fk', $classid, '=');
  $query->isNull('unenrol_date');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  $results = $query->execute()->fetchAll();

  return $results;
}

/**
 * Get a grade record for a specific student in a specific class
 *
 * @param $studentid
 *    The student id
 * @param $classid
 *    The node id of the specific class
 *
 * @return
 *    Result set containing the student grade record
 */
function kleosis_get_student_final_grade_record_ls($studentid, $classid) {

  $query = db_select('ks_student_course_class_grades', 'ksgrd');
  $query->innerJoin('ks_student_course_classes', 'ksccl', 'ksccl.ksccl_id = ksgrd.ksccl_id_fk');
  $query->innerJoin('users', 'u', 'u.uid = ksccl.kstu_id_fk');
  $query->addField('u', 'uid');
  $query->addField('u', 'name');
  $query->addField('ksgrd', 'kcclg_id');
  $query->addField('ksgrd', 'ksccl_id_fk');
  $query->addField('ksgrd', 'final_exam_grade_str');
  $query->addField('ksgrd', 'course_grade_str');
  $query->addField('ksgrd', 'grade_item_1');
  $query->addField('ksgrd', 'grade_item_2');
  $query->addField('ksgrd', 'grade_item_3');
  $query->addField('ksgrd', 'final_grade_str');
  $query->addField('ksgrd', 'remarks');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  // adjust the query according to the filter values (class_id)
  $query->condition('ksccl.' . 'kstu_id_fk', $studentid, '=');
  $query->condition('ksccl.' . 'kccls_id_fk', $classid, '=');

  $results = $query->execute()->fetchAll();


  return $results;
}

/**
 *
 * Implementation of hook_submit() for the Final Grades-LS List form.
 *   - main purpose is to store the selected class into session variables
 *
 */
function kleosis_final_grades_ls_select_form_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Clear':
      $_SESSION['ks_final_grades_class_filter'] = array();
      break;
    case 'Set year and term':

      $_SESSION['ks_final_grades_class_filter'] = array(
                                        'class_id' => 0,
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                        );

      break;
    case 'Get grades':
      $_SESSION['ks_final_grades_class_filter']['class_id'] = $form_state['values']['class'];
      break;
    case 'Edit selected grades':

      $form_state['redirect'] = 'kleosis/grades_ls/edit_final_grades';

      break;
  }
}

/**
 *
 * Final grades edit form
 *
 */
function kleosis_final_grades_ls_edit_form($form, &$form_state) {

drupal_set_title(t('Edit Final Grades-LS'));

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades-LS'), 'kleosis/grades_ls/final_grades_ls');
  $breadcrumb[] = t('Edit final grades-LS');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  $kcclg_id = isset( $_GET['ksopgid'] ) ? $_GET['ksopgid'] : 0;
  $ksccl_id = isset( $_GET['ksopcclid'] ) ? $_GET['ksopcclid'] : 0;
  $class_id = isset( $_GET['ksopcid'] ) ? $_GET['ksopcid'] : 0;
  $student_id = isset( $_GET['ksopsid'] ) ? $_GET['ksopsid'] : 0;
  $student_name = isset( $_GET['ksopsn'] ) ? $_GET['ksopsn'] : 'no student selected';

  if ($class_id == 0) {
    drupal_set_message(t('Please select a Student from the Final Grades List'));
    $form_state['redirect'] = 'kleosis/grades_ls/final_grades_ls';
    drupal_redirect_form($form_state);
  }
  $node = node_load($class_id);
  $class_name = $node->title;
//  $weights = kleosis_get_grade_item_weights_ls($class_id);

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';
  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  $grades =  kleosis_get_student_final_grade_record_ls($student_id, $class_id);

  $form['grades_edit']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  !empty($class_academic_year) ? $class_academic_year : '2011-2012',
    '#disabled' => TRUE,
    '#weight' => -10,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => !empty($class_term) ? $class_term : 'fy',
    '#disabled' => TRUE,
    '#weight' => -8,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['student'] = array(
    '#type' => 'textfield',
    '#title' => t('Student'),
    '#default_value' =>  $student_name,
    '#disabled' => TRUE,
    '#size' => 40,
    '#maxlength' => 60,
    '#weight' => -6,
    '#prefix' => '<div style="float: left;clear:left;width:300px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['class'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#default_value' =>  $class_name,
    '#disabled' => TRUE,
    '#size' => 50,
    '#maxlength' => 80,
    '#weight' => -4,
    '#prefix' => '<div style="float: left;width:310px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['kcclg_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $kcclg_id,
  );
  $form['grades_edit']['ksccl_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $ksccl_id,
  );
  $form['grades_edit']['kcclg_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $kcclg_id,
  );
  $form['grades_edit']['course_grade_str'] = array(
    '#type' => 'textfield',
    '#title' => t('Course grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->course_grade_str : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 0,
//    '#description' => '% of final grade: ' . $weights['cgw'],
    '#prefix' => '<div style="float: left;clear:left;width:175px" ><br/>',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['final_exam_grade_str'] = array(
//    '#type' => $final_exam_grade_exists,
    '#type' => 'textfield',
    '#title' => t('Final exam'),
    '#default_value' =>  !empty($grades) ? $grades[0]->final_exam_grade_str : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 2,
//    '#description' => '% of final grade: ' . $weights['few'],
    '#prefix' => '<div style="float: left;width:175px" ><br/>',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['grade_item_1'] = array(
//    '#type' => $grade_item_1_exists,
    '#type' => 'textfield',
    '#title' => variable_get('kleosis_grade_item_1_name', 'Item 1 grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->grade_item_1 : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 4,
//    '#description' => '% of final grade: ' . $weights['giaw'],
    '#prefix' => '<div style="float: left;clear:left; width:175px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['grade_item_2'] = array(
//    '#type' => $grade_item_2_exists,
    '#type' => 'textfield',
    '#title' => variable_get('kleosis_grade_item_2_name', 'Item 2 grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->grade_item_2 : '',
    '#size' => 7,
    '#maxlength' => 8,
//    '#description' => '% of final grade: ' . $weights['gibw'],
    '#weight' => 6,
    '#prefix' => '<div style="float: left;width:175px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['grade_item_3'] = array(
//    '#type' => $grade_item_3_exists,
    '#type' => 'textfield',
    '#title' => variable_get('kleosis_grade_item_3_name', 'Item 3 grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->grade_item_3 : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 8,
//    '#description' => '% of final grade: ' . $weights['gicw'],
    '#prefix' => '<div style="float: left;width:175px" >',
    '#suffix' => '</div>',
  );

  $form['grades_edit']['final_grade_str'] = array(
    '#type' => 'textfield',
    '#title' => t('Final grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->final_grade_str : '',
//    '#disabled' => TRUE,
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 10,
//    '#description' => 'Letter grade',
    '#prefix' => '<div id="final_grade_textfield_wrapper", style="float: left;clear:left;width:175px" >',
    '#suffix' => '</div>',
  );

  $form['grades_edit']['remarks'] = array(
    '#type' => 'textarea',
    '#title' => t('Remarks'),
    '#cols' => 80,
    '#rows' => 2,
    '#default_value' =>  !empty($grades) ? $grades[0]->remarks : '',
    '#resizeable' => TRUE,
    '#weight' => 12,
    '#prefix' => '<div style="float:left;width:275px" >',
    '#suffix' => '</div><br/>',
  );
  $form['grades_edit']['update'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#weight' => 15,
    '#prefix' => '<div style="float: left;clear:left;width:175px" ></br>',
    '#suffix' => '</div>',
  );

  $form['grades_edit']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#weight' => 17,
    '#prefix' => '<div style="float: left;width:150px" ></br>',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 *
 * Implementation of hook_validate() for the Edit Final Grades-LS form.
 *
 */
function kleosis_final_grades_ls_edit_form_validate($form, &$form_state) {

  if ($form_state['values']['op'] == 'Cancel') {
    return;
  }
/*
  if ( (empty($form_state['values']['final_exam_grade'])) || (!is_numeric($form_state['values']['final_exam_grade'])) ) {
      form_set_error('final_exam_grade', t('Final exam grade must be a decimal number.'), $limit_validation_errors = NULL);
    }
*/
}
/**
 *
 * Implementation of hook_submit() for the Edit Final Grades-LS form.
 *
 */
function kleosis_final_grades_ls_edit_form_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case 'Update':

    $ks_final_grade_record = array();
    $ks_final_grade_record['kcclg_id'] = $form_state['values']['kcclg_id'];
    $ks_final_grade_record['ksccl_id_fk'] = $form_state['values']['ksccl_id'];
//        $ks_final_grade_record['current_grade'] = $form_state['values']['current_grade'];
    $ks_final_grade_record['final_exam_grade_str'] = $form_state['values']['final_exam_grade_str'];
    $ks_final_grade_record['course_grade_str'] = $form_state['values']['course_grade_str'];
    $ks_final_grade_record['grade_item_1'] = $form_state['values']['grade_item_1'];
    $ks_final_grade_record['grade_item_2'] = $form_state['values']['grade_item_2'];
    $ks_final_grade_record['grade_item_3'] = $form_state['values']['grade_item_3'];
        $ks_final_grade_record['final_grade_str'] = $form_state['values']['final_grade_str'];
//    $ks_final_grade_record['final_grade'] = $final_grade;
    $ks_final_grade_record['remarks'] = $form_state['values']['remarks'];

    if ($ks_final_grade_record['kcclg_id']) {
      $res = ks_update_final_grade_ls_record($ks_final_grade_record);
    }
    else {
      $res = ks_insert_final_grade_ls_record($ks_final_grade_record);
    }

//    $form_state['redirect'] = 'kleosis/grades/final_grades_ls';

      break;

    case 'Cancel':

//      $form_state['redirect'] = 'kleosis/grades/final_grades_ls';

      break;
    }
}
/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/


/**
 * Provides the final grades for a student
 *
 * @return
 *   tbd
 */
function kleosis_student_final_grades_ls($form, &$form_state) {

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page.'));
    drupal_goto($path = 'kleosis/students', $options = array());
  }

  $_SESSION['student']['id'] = $uid;
  $_SESSION['student']['name'] = $name;

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Final Grades - LS');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Final Grades - LS'));

  $build['filter'] = kleosis_student_final_grades_ls_acyt_select_form();
  $build['#submit'][] = 'kleosis_student_final_grades_ls_acyt_select_form_submit';
  $build['list'] = kleosis_student_final_grades_ls_list();

  return $build;
}

/**
 *
 * Academic year and term selection for the Students Final Grades List form
 *
 */
function kleosis_student_final_grades_ls_acyt_select_form() {

  $academic_year = isset($_SESSION['ks_student_final_grades_ls_select_filter']['academic_year']) ? $_SESSION['ks_student_final_grades_ls_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['ks_student_final_grades_ls_select_filter']['term']) ? $_SESSION['ks_student_final_grades_ls_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term . '&nbsp; &nbsp; &nbsp; ' . t('Student') . ': ' . ks_get_usernames_for_display($uid),
    '#weight' => -5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $build['acy_select']['academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Academic Year'),
    '#options' =>  kleosis_academic_year_values(),
    '#default_value' =>  $academic_year,
    '#disabled' => FALSE,
    '#weight' => 1,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => $term,
    '#disabled' => FALSE,
    '#weight' => 3,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#weight' => 5,
    '#disabled' => FALSE,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );

  $usernames = ks_get_usernames_for_display($uid);  // get the display names for this user
  $text = t('Final grades for student <strong>@name</strong>' . ': ', array('@name' => $usernames));

  $build['thegrades'] = array(
    '#markup' => $text,
    '#prefix' => '<div style="float: left;clear:left; width:550px" >',
    '#suffix' => '</div>',
    );

  return $build;
}


/**
 *
 * Implementation of hook_submit() for the Students Final Grades List form.
 *
 */
function kleosis_student_final_grades_ls_acyt_select_form_submit($form, &$form_state) {

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  switch ($form_state['values']['op']) {

    case 'Apply':

      $_SESSION['ks_student_final_grades_ls_select_filter'] = array(
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                       );
      break;
  }
}

/**
 * Provides the final grades for a student
 *
 * @return
 *   build of final grades
 */
function kleosis_student_final_grades_ls_list() {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis grades')) ) {
    drupal_set_message(t("You currently do not have permissions to view Kleosis grades."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  $academic_year = isset($_SESSION['ks_student_final_grades_ls_select_filter']['academic_year']) ? $_SESSION['ks_student_final_grades_ls_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['ks_student_final_grades_ls_select_filter']['term']) ? $_SESSION['ks_student_final_grades_ls_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // the header contains all the fields that will be displayed in the tableselect list
/*
  $header = array(
    'name' => array('data' => t('Username'), $name),
    'title' => 'Course',
    'final_grade' => array('data' => t('Final Grade (decimal)'), 'field' => 'ksstugrades.final_grade'),
    'final_grade_str' => array('data' => t('Final Grade (letter)'), 'field' => 'ksstugrades.final_grade_str'),
    'remarks' => array('data' => t('Remarks'), 'field' => 'ksstugrades.remarks'),
    'operations' => array('data' => t('Ops')),
  );
*/
  $header = array(
//    'name' => array('data' => t('Student'), 'field' => 'u.name'),
    'name' => array('data' => t('Username'), $name),
    'title' => 'Course',
    'course_grade_str' => t('Course Grade'),
    'final_exam_grade_str' => t('Final Exam'),
    'grade_item_1' => variable_get('kleosis_grade_item_1_name', t('GradeItem 1')),
    'grade_item_2' => variable_get('kleosis_grade_item_2_name', t('GradeItem 2')),
    'grade_item_3' => variable_get('kleosis_grade_item_3_name', t('GradeItem 3')),
    'final_grade_str' => t('Final Grade'),
    'remarks' => t('Remarks'),
//    'operations' => array('data' => t('Ops')),
    'operations' => t('Ops'),
  );

//  $classid = $_SESSION['kleosis_class_selected_class']['classid'];

// get all class nids for the selected academic year and term:

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'class')
  ->fieldCondition('ks_class_term', 'value', $term, '=')
  ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
  ->fieldCondition('ks_class_status', 'value', '1', '=')  // 'Active'
  ->propertyCondition('status', 1)  // not needed, just an example...
  ->fieldOrderBy('ks_class_academic_year', 'value', 'ASC');

  $result = $query->execute();

  $build = array();
  $options = array();

  if ( !empty($result) ) {

    $nids = array_keys($result['node']);
    $nodes = entity_load('node', array_keys($result['node']));

    // get the grades from the classes that the student has taken during the selected academic year and term

    $query = db_select('ks_student_course_classes', 'ksstuclass');
//    $query->innerJoin('ks_student_course_class_grades', 'ksstugrades', 'ksstugrades.ksccl_id_fk = ksstuclass.ksccl_id');
    $query->leftJoin('ks_student_course_class_grades', 'ksstugrades', 'ksstugrades.ksccl_id_fk = ksstuclass.ksccl_id');
    $query->addField('ksstuclass', 'ksccl_id');
    $query->addField('ksstuclass', 'kstu_id_fk');
    $query->addField('ksstuclass', 'kccls_id_fk');
    $query->addField('ksstugrades', 'kcclg_id');
    $query->addField('ksstugrades', 'final_exam_grade_str');
    $query->addField('ksstugrades', 'course_grade_str');
    $query->addField('ksstugrades', 'grade_item_1');
    $query->addField('ksstugrades', 'grade_item_2');
    $query->addField('ksstugrades', 'grade_item_3');
    $query->addField('ksstugrades', 'final_grade_str');
    $query->addField('ksstugrades', 'remarks');

    $query->condition('ksstuclass.' . 'kstu_id_fk', $uid, '=');
    $query->condition('ksstuclass.' . 'kccls_id_fk', $nids, 'IN');

    $grade_records = $query->execute()->fetchAll();

    $attnda = array_keys(ks_get_course_types(), 'Attendance');  // get the Attendance course type key
    $lnchbrka = array_keys(ks_get_course_types(), 'Lunch-Breaktime');  // get the Lunch-Breaktime course type key

    foreach ($grade_records as $record) {

      $class_node = node_load($record->kccls_id_fk);
      $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
      $course_node = node_load($node_course_ref);
      $coursetitle = $course_node->title;
      $node_course_no =   $course_node->ks_course_no['und'][0]['value'];
      $node_course_type =   $course_node->ks_course_type['und'][0]['value'];

      if ( ($node_course_type != $attnda[0]) && ($node_course_type != $lnchbrka[0]) ) {
        $options[$record->kccls_id_fk] = array(
        'name' => l($name, 'kleosis/students/summary', array('query' => array('ksopid' => $uid, 'ksop' => $name))),
        'title' =>  $node_course_no,
        'course_grade_str' =>  $record->course_grade_str,
        'final_exam_grade_str' =>  $record->final_exam_grade_str,
        'grade_item_1' =>  $record->grade_item_1,
        'grade_item_2' =>  $record->grade_item_2,
        'grade_item_3' =>  $record->grade_item_3,
        'final_grade_str' =>  $record->final_grade_str,
        'remarks' =>  $record->remarks,
        //   the following link re-uses the final_grades_edit_form in kleosis_grades.inc - cool. See also: kleosis_final_grades_list() in the same .inc
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $record->kcclg_id, 'ksopcclid' => $record->ksccl_id, 'ksopcid' => $record->kccls_id_fk, 'ksopsid' => $uid, 'ksopsn' => $name, 'destination' => 'kleosis/students/grades/final_grades_ls')))
        );
      }
    }
  }
  asort($options);
  $build['students'] = array(
    '#type' => 'table',       // used for table
//    '#type' => 'tableselect',   // used for tableselect
    '#theme' => 'table',      // used only for table
    '#header' => $header,
//    '#options' => $options,   // used for tableselect
    '#rows' => $options,   // used for table
    '#empty' => t('No grades exist for the student for the selected academic year and term.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
  );

  $build['pager'] = array('#markup' => theme('pager'));
  return $build;
}