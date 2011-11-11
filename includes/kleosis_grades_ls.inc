<?php
// $Id$
/**
* @file
* kleosis Grades (for LIST (_ls))
*/

/**
 * Provides Grades functions available in kleosis available in Kleosis
 *
 * @return
 *   tbd
 */

/**
 * Render a filtered list of student final grades.
 *
 */
function kleosis_final_grades_ls_form() {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = t('Final Grades-LS List');

  drupal_set_breadcrumb($breadcrumb);

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
  $results = db_query($sql, array(':type' => 'class', ':status' => 1,) );
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
    $options = array('0' => t('No classes exist for selected year and term'),);
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


drupal_set_title(t('Final Grades-LS'));

  $form = array();

  // get the filter values from the session variable (if any) and set the default form values accordingly

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  $final_exam_grade_exists = $grade_item_1_exists =  $grade_item_2_exists =  $grade_item_3_exists = FALSE;
  $weights = kleosis_get_grade_item_weights($class_id_from_filter);
  if(isset($weights)) {
    $final_exam_grade_exists =  ($weights['few'] <> '00.00') ? TRUE : FALSE;
    $grade_item_1_exists =  ($weights['giaw'] <> '00.00') ? TRUE : FALSE;
    $grade_item_2_exists =  ($weights['gibw'] <> '00.00') ? TRUE : FALSE;
    $grade_item_3_exists =  ($weights['gicw'] <> '00.00') ? TRUE : FALSE;
  }

  // the header contains all the fields that will be displayed in the tableselect list
  if ($grade_item_3_exists) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade' => t('Course Grade'),
      'final_exam_grade' => t('Final Exam'),
      'grade_item_1' => variable_get('kleosis_grade_item_1_name',t('GradeItem 1')),
      'grade_item_2' => variable_get('kleosis_grade_item_2_name',t('GradeItem 2')),
      'grade_item_3' => variable_get('kleosis_grade_item_3_name',t('GradeItem 3')),
      'final_grade' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
  elseif ($grade_item_2_exists) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade' => t('Course Grade'),
      'final_exam_grade' => t('Final Exam'),
      'grade_item_1' => variable_get('kleosis_grade_item_1_name',t('GradeItem 1')),
      'grade_item_2' => variable_get('kleosis_grade_item_2_name',t('GradeItem 2')),
      'final_grade' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
  elseif ($grade_item_1_exists) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade' => t('Course Grade'),
      'final_exam_grade' => t('Final Exam'),
      'grade_item_1' => variable_get('kleosis_grade_item_1_name',t('GradeItem 1')),
      'final_grade' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
  elseif ($final_exam_grade_exists) {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade' => t('Course Grade'),
      'final_exam_grade' => t('Final Exam'),
      'final_grade' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
  else {
    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'course_grade' => t('Course Grade'),
      'final_grade' => t('Final Grade'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );
  }
  $students_in_the_class = kleosis_get_students_in_class($class_id_from_filter);
//  dpm($students_in_the_class);

  $options = array();

  foreach ($students_in_the_class as $student) {

    $graderow = kleosis_get_student_final_grade_record($student->kstu_id_fk, $class_id_from_filter);

    $lp_kcclg = !empty($graderow) ? $graderow[0]->kcclg_id : 0;
    $lp_ksccl_id = $student->ksccl_id;

    if ($grade_item_3_exists) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade' => !empty($graderow) ? $graderow[0]->course_grade : '',
        'final_exam_grade' => !empty($graderow) ? $graderow[0]->final_exam_grade : '',
        'grade_item_1' => !empty($graderow) ? $graderow[0]->grade_item_1 : '',
        'grade_item_2' => !empty($graderow) ? $graderow[0]->grade_item_2 : '',
        'grade_item_3' => !empty($graderow) ? $graderow[0]->grade_item_3 : '',
        'final_grade' => !empty($graderow) ? $graderow[0]->final_grade : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades_ls/final_grades_ls')))
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
    elseif ($grade_item_2_exists) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade' => !empty($graderow) ? $graderow[0]->course_grade : '',
        'final_exam_grade' => !empty($graderow) ? $graderow[0]->final_exam_grade : '',
        'grade_item_1' => !empty($graderow) ? $graderow[0]->grade_item_1 : '',
        'grade_item_2' => !empty($graderow) ? $graderow[0]->grade_item_2 : '',
        'final_grade' => !empty($graderow) ? $graderow[0]->final_grade : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades_ls/final_grades_ls')))
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
    elseif ($grade_item_1_exists) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade' => !empty($graderow) ? $graderow[0]->course_grade : '',
        'final_exam_grade' => !empty($graderow) ? $graderow[0]->final_exam_grade : '',
        'grade_item_1' => !empty($graderow) ? $graderow[0]->grade_item_1 : '',
        'final_grade' => !empty($graderow) ? $graderow[0]->final_grade : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades_ls/final_grades_ls')))
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
    elseif ($final_exam_grade_exists) {
      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade' => !empty($graderow) ? $graderow[0]->course_grade : '',
        'final_exam_grade' => !empty($graderow) ? $graderow[0]->final_exam_grade : '',
        'final_grade' => !empty($graderow) ? $graderow[0]->final_grade : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades_ls/final_grades_ls')))
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
       );
     }
     else {
      $options[$student->kstu_id_fk] = array(
//        'name' => $student->name,
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'course_grade' => !empty($graderow) ? $graderow[0]->course_grade : '',
        'final_grade' => !empty($graderow) ? $graderow[0]->final_grade : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
  //      'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades_ls/final_grades_ls')))
        'operations' => l(t('edit'), 'kleosis/grades_ls/edit_final_grades_ls', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name)))
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

  $form['grades_action']['grades_from_lms'] = array(
    '#type' => 'submit',
    '#value' => t('Get grades from Moodle gradebook'),
    '#weight' => 25,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left; width:225px" >',
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
function kleosis_get_students_in_class($classid) {

  $query = db_select('ks_student_course_classes', 'ksscc');
  $query->innerJoin('users', 'u', 'u.uid = ksscc.kstu_id_fk');
  $query->addField('u', 'name');
  $query->addField('ksscc', 'ksccl_id');
  $query->addField('ksscc', 'kstu_id_fk');

  $query->condition('ksscc.' . 'kccls_id_fk', $classid, '=');
  $query->isNull('unenrol_date');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

//  $query = $query->extend('PagerDefault')->limit(variable_get('kleosis_pager_rows', 16));
//  $query = $query->extend('TableSort');
//  $query->orderByHeader($header);

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
function kleosis_get_student_final_grade_record($studentid, $classid) {

  $query = db_select('ks_student_course_class_grades', 'ksgrd');
  $query->innerJoin('ks_student_course_classes', 'ksccl', 'ksccl.ksccl_id = ksgrd.ksccl_id_fk');
  $query->innerJoin('users', 'u', 'u.uid = ksccl.kstu_id_fk');
  $query->addField('u', 'uid');
  $query->addField('u', 'name');
  $query->addField('ksgrd', 'kcclg_id');
  $query->addField('ksgrd', 'ksccl_id_fk');
  $query->addField('ksgrd', 'final_exam_grade');
  $query->addField('ksgrd', 'course_grade');
  $query->addField('ksgrd', 'grade_item_1');
  $query->addField('ksgrd', 'grade_item_2');
  $query->addField('ksgrd', 'grade_item_3');
  $query->addField('ksgrd', 'final_grade');
  $query->addField('ksgrd', 'remarks');

  // Only get items 0-1999, for scalability reasons...
  $query->range(0, 2000);

  // adjust the query according to the filter values (class_id)
  $query->condition('ksccl.' . 'kstu_id_fk', $studentid, '=');
  $query->condition('ksccl.' . 'kccls_id_fk', $classid, '=');

//  $query = $query->extend('PagerDefault')->limit(variable_get('kleosis_pager_rows', 16));
//  $query = $query->extend('TableSort');
//  $query->orderByHeader($header);

  $results = $query->execute()->fetchAll();


  return $results;
}

/**
 * Get the grade item weights from the course for a specific class
 *
 * @param $classid
 *    The class id
 * @return
 *    array of weights
 */
function kleosis_get_grade_item_weights($classid) {

  $theclass = node_load($classid);
  if( (isset($theclass)) && ($classid <> 0) ) {
    $thecourse = node_load($theclass->ks_class_course_ref['und'][0]['nid']);
  }
  $cgw = isset($thecourse->ks_course_grade_weight['und'][0]['value']) ? $thecourse->ks_course_grade_weight['und'][0]['value'] : 0.0;
  $few = isset($thecourse->ks_final_exam_weight['und'][0]['value']) ? $thecourse->ks_final_exam_weight['und'][0]['value'] : 0.0;
  $giaw = isset($thecourse->ks_grade_item_a_weight['und'][0]['value']) ? $thecourse->ks_grade_item_a_weight['und'][0]['value'] : 0.0;
  $gibw = isset($thecourse->ks_grade_item_b_weight['und'][0]['value']) ? $thecourse->ks_grade_item_b_weight['und'][0]['value'] : 0.0;
  $gicw = isset($thecourse->ks_grade_item_c_weight['und'][0]['value']) ? $thecourse->ks_grade_item_c_weight['und'][0]['value'] : 0.0;

  $weights = array('cgw' => $cgw, 'few' => $few, 'giaw' => $giaw, 'gibw' => $gibw, 'gicw' => $gicw);

  return $weights;
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
 * Defines a get current grades placeholder tab
 *
 * @return
 *    a markup blurb...
 */
function kleosis_get_current_grades_ls($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades-LS'), 'kleosis/grades_ls/final_grades_ls');
  $breadcrumb[] = t('Current Grades');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

 drupal_set_title(t('Current Grades'));


$page_desc = <<<EOT
    <br/>This grades page will obtain and display the current grades for students in a selected class.
    The grades will be retrieved from the assessment plan in Moodle for the selected class.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Current Grades'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );

return $form;
}

/**
 * Defines a grades placeholder tab
 *
 * @return
 *    a markup blurb...
 */
function kleosis_grades_ls_placeholder_tab($form, &$form_state) {

 drupal_set_title(t('Grades Item'));

$page_desc = <<<EOT
  <br/>This is a placeholder page for upcoming Kleosis grading functionality (currently under construction...)
  <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Description'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );

return $form;
}

/**
 * Defines a set term final grades placeholder tab
 *
 * @return
 *    a markup blurb...
 */
function kleosis_set_final_grades_ls($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades-LS'), 'kleosis/grades_ls/final_grades_ls');
  $breadcrumb[] = t('Lock Final Grades-LS');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

drupal_set_title(t('Lock Final Grades-LS'));

$page_desc = <<<EOT
    <br/>This administrative page will set the final grades for all classes...
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Lock Final Grades-LS'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );

return $form;
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
  $weights = kleosis_get_grade_item_weights($class_id);

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';
  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  $final_exam_grade_exists =  ($weights['few'] <> '00.00') ? 'textfield' : 'hidden';
  $grade_item_1_exists =  ($weights['giaw'] <> '00.00') ? 'textfield' : 'hidden';
  $grade_item_2_exists =  ($weights['gibw'] <> '00.00') ? 'textfield' : 'hidden';
  $grade_item_3_exists =  ($weights['gicw'] <> '00.00') ? 'textfield' : 'hidden';

  $grades =  kleosis_get_student_final_grade_record($student_id, $class_id);

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
  $form['grades_edit']['course_grade'] = array(
    '#type' => 'textfield',
    '#title' => t('Course grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->course_grade : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 0,
    '#description' => '% of final grade: ' . $weights['cgw'],
    '#prefix' => '<div style="float: left;clear:left;width:175px" ><br/>',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['final_exam_grade'] = array(
    '#type' => $final_exam_grade_exists,
    '#title' => t('Final exam'),
    '#default_value' =>  !empty($grades) ? $grades[0]->final_exam_grade : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 2,
    '#description' => '% of final grade: ' . $weights['few'],
    '#prefix' => '<div style="float: left;width:175px" ><br/>',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['grade_item_1'] = array(
    '#type' => $grade_item_1_exists,
    '#title' => variable_get('kleosis_grade_item_1_name','Item 1 grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->grade_item_1 : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 4,
    '#description' => '% of final grade: ' . $weights['giaw'],
    '#prefix' => '<div style="float: left;clear:left;width:175px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['grade_item_2'] = array(
    '#type' => $grade_item_2_exists,
    '#title' => variable_get('kleosis_grade_item_2_name','Item 2 grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->grade_item_2 : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#description' => '% of final grade: ' . $weights['gibw'],
    '#weight' => 6,
    '#prefix' => '<div style="float: left;width:175px" >',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['grade_item_3'] = array(
    '#type' => $grade_item_3_exists,
    '#title' => variable_get('kleosis_grade_item_3_name','Item 3 grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->grade_item_3 : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 8,
    '#description' => '% of final grade: ' . $weights['gicw'],
    '#prefix' => '<div style="float: left;width:175px" >',
    '#suffix' => '</div>',
  );

  $form['grades_edit']['final_grade'] = array(
    '#type' => 'textfield',
    '#title' => t('Final grade'),
    '#default_value' =>  !empty($grades) ? $grades[0]->final_grade : '',
    '#disabled' => TRUE,
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 10,
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

  $form['grades_edit']['calculate'] = array(
    '#type' => 'submit',
    '#value' => t('Calculate final grade'),
    '#weight' => 16,
    '#ajax' => array(
        'callback' => 'calculate_final_grade_ajax_callback',
        'wrapper' => 'final_grade_textfield_wrapper',
        'method' => 'replace',
    ),
    '#prefix' => '<div style="float: left;width:250px" ></br>',
    '#suffix' => '</div>',
  );

  $form['grades_edit']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#weight' => 17,
    '#prefix' => '<div style="float: left;width:150px" ></br>',
    '#suffix' => '</div>',
  );

//  dpm('inside kleosis_final_grades_ls_edit_form');
//  dpm($form);
//  dpm($form_state);

  return $form;
}

/**
 *
 *  Ajax callback for final grade calculation
 *
 */
 function calculate_final_grade_ajax_callback($form, $form_state) {

  $final_exam = $form_state['values']['final_exam_grade'];
  $course_grade = $form_state['values']['course_grade'];
  $grade_item_1 = $form_state['values']['grade_item_1'];
  $grade_item_2 = $form_state['values']['grade_item_2'];
  $grade_item_3 = $form_state['values']['grade_item_3'];

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;

  $final_grade = kleosis_calculate_final_grade($class_id_from_filter, $course_grade, $final_exam, $grade_item_1, $grade_item_2, $grade_item_3);

  $element = $form['grades_edit']['final_grade'];
  $element['#value'] = $final_grade;
  $element['#default_value'] = $final_grade;  // no effect...

  return $element;
 }

/**
 *
 *  Final grade calculation
 *
 */
function kleosis_calculate_final_grade($classid, $course_grade, $final_exam, $grade_item_1, $grade_item_2, $grade_item_3) {

  $weights = kleosis_get_grade_item_weights($classid);

  $cgw = $weights['cgw'];
  $few = $weights['few'];
  $giaw = $weights['giaw'];
  $gibw = $weights['gibw'];
  $gicw = $weights['gicw'];

  if ($cgw == '100.00' && $few == '00.00' && $giaw == '00.00' && $gibw == '00.00' && $gicw == '00.00') {

    $le_final_grade = $course_grade;
  }
  elseif ($cgw <> '00.00' && $few <> '00.00' && $giaw == '00.00' && $gibw == '00.00' && $gicw == '00.00') {
    $le_final_grade = (($course_grade * $cgw) + ($final_exam * $few)) / 100.0;
  }
  elseif ($cgw <> '00.00' && $few <> '00.00' && $giaw <> '00.00' && $gibw == '00.00' && $gicw == '00.00') {
    $le_final_grade = (($course_grade * $cgw) + ($final_exam * $few) + ($grade_item_1 * $giaw)) / 100.0;
  }
  elseif ($cgw <> '00.00' && $few <> '00.00' && $giaw <> '00.00' && $gibw <> '00.00' && $gicw == '00.00') {
    $le_final_grade = (($course_grade * $cgw) + ($final_exam * $few) + ($grade_item_1 * $giaw) + ($grade_item_2 * $gibw)) / 100.0;
  }
  elseif ($cgw <> '00.00' && $few <> '00.00' && $giaw <> '00.00' && $gibw <> '00.00' && $gicw <> '00.00') {
    $le_final_grade = (($course_grade * $cgw) + ($final_exam * $few) + ($grade_item_1 * $giaw) + ($grade_item_2 * $gibw) + ($grade_item_3 * $gicw)) / 100.0;
  }
  else {
    $le_final_grade = 0;
  }

  return $le_final_grade;
 }

/**
 *
 * Implementation of hook_validate() for the Edit Final Grades-LS form.
 *
 */
function kleosis_final_grades_ls_edit_form_validate($form, &$form_state) {

// dpm($form_state);
  if ($form_state['values']['op'] == 'Cancel') {
    return;
  }
  if( (empty($form_state['values']['final_exam_grade'])) || (!is_numeric($form_state['values']['final_exam_grade'])) ) {
      form_set_error('final_exam_grade', t('Final exam grade must be a decimal number.'), $limit_validation_errors = NULL);
    }
  if( (empty($form_state['values']['course_grade'])) || (!is_numeric($form_state['values']['course_grade'])) ) {
      form_set_error('course_grade', t('Course grade must be a decimal number.'), $limit_validation_errors = NULL);
    }
//  if( (empty($form_state['values']['final_grade'])) || (!is_numeric($form_state['values']['final_grade'])) ) {
//      form_set_error('final_grade', t('Final grade must be a decimal number.'), $limit_validation_errors = NULL);
//    }
//  if ( !is_numeric($form_state['values']['final_grade']) ) {
//      form_set_error('final_grade', t('Final grade must be a decimal number.'), $limit_validation_errors = NULL);
//    }

  if (empty($form_state['values']['grade_item_1'])) {
    $form_state['values']['grade_item_1'] = NULL;
    }
  elseif ( !is_numeric($form_state['values']['grade_item_1'])  ) {
     form_set_error('grade_item_1', t('Grade Item 1 must be a decimal number.'), $limit_validation_errors = NULL);
    }
  if (empty($form_state['values']['grade_item_2'])) {
    $form_state['values']['grade_item_2'] = NULL;
    }
  elseif ( !is_numeric($form_state['values']['grade_item_2'])  ) {
     form_set_error('grade_item_2', t('Grade Item 2 must be a decimal number.'), $limit_validation_errors = NULL);
    }
  if (empty($form_state['values']['grade_item_3'])) {
    $form_state['values']['grade_item_3'] = NULL;
    }
  elseif ( !is_numeric($form_state['values']['grade_item_3'])  ) {
     form_set_error('grade_item_3', t('Grade Item 3 must be a decimal number.'), $limit_validation_errors = NULL);
    }
}
/**
 *
 * Implementation of hook_submit() for the Edit Final Grades-LS form.
 *
 */
function kleosis_final_grades_ls_edit_form_submit($form, &$form_state) {

//  dpm($form);
//  dpm($form_state['input']['final_grade']);
  switch ($form_state['values']['op']) {

    case 'Update':

    // calculated the final grade again because form values altered by ajax do not show up for the submit process!
    $final_exam = $form_state['values']['final_exam_grade'];
    $course_grade = $form_state['values']['course_grade'];
    $grade_item_1 = $form_state['values']['grade_item_1'];
    $grade_item_2 = $form_state['values']['grade_item_2'];
    $grade_item_3 = $form_state['values']['grade_item_3'];

    $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
    $final_grade = kleosis_calculate_final_grade($class_id_from_filter, $course_grade, $final_exam, $grade_item_1, $grade_item_2, $grade_item_3);

    $ks_final_grade_record = array();
    $ks_final_grade_record['kcclg_id'] = $form_state['values']['kcclg_id'];
    $ks_final_grade_record['ksccl_id_fk'] = $form_state['values']['ksccl_id'];
//        $ks_final_grade_record['current_grade'] = $form_state['values']['current_grade'];
    $ks_final_grade_record['final_exam_grade'] = $form_state['values']['final_exam_grade'];
    $ks_final_grade_record['course_grade'] = $form_state['values']['course_grade'];
    $ks_final_grade_record['grade_item_1'] = $form_state['values']['grade_item_1'];
    $ks_final_grade_record['grade_item_2'] = $form_state['values']['grade_item_2'];
    $ks_final_grade_record['grade_item_3'] = $form_state['values']['grade_item_3'];
//        $ks_final_grade_record['final_grade'] = $form_state['values']['final_grade'];
    $ks_final_grade_record['final_grade'] = $final_grade;
    $ks_final_grade_record['remarks'] = $form_state['values']['remarks'];

    if ($ks_final_grade_record['kcclg_id']) {
      $res = ks_update_final_grade_ls_record($ks_final_grade_record);
    }
    else {
      $res = ks_insert_final_grade_ls_record($ks_final_grade_record);
    }

    $form_state['redirect'] = 'kleosis/grades_ls/final_grades_ls';

      break;

    case 'Cancel':

      $form_state['redirect'] = 'kleosis/grades_ls/final_grades_ls';

      break;
    }
}
