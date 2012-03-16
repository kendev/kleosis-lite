<?php

/**
 * @file
 * Kleosis Grades functions
 */

/**
 * Defines a Current grades placeholder tab
 *
 * @return
 *    redirects to kleosis_current_grades_by_class()
 */
function kleosis_current_grades($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades'), 'kleosis/grades/current_grades');
  $breadcrumb[] = t('Current Grades');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Current Grades by Class'));


$page_desc = <<<EOT
    <br/>This is the kleosis_current_grades form.<br/><br/>
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
  drupal_goto($path = 'kleosis/grades/current_grades', $options = array());
  return $form;
}

/**
 * Retrieves the current grades for all students in a class (from Moodle)
 *
 * @return
 *    a list of current grades
 */
function kleosis_current_grades_by_class($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Current grades'), 'kleosis/grades/current_grades/by_class');
  $breadcrumb[] = t('Current Grades by Class');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Current Grades (by Class)'));

  $build['filter'] = kleosis_current_grades_select_form();
  $build['#submit'][] = 'kleosis_current_grades_select_form_submit';
  $build['list'] = kleosis_current_grades_list();

  return $build;
}

/**
 *
 * Current grades filter by academic year, term, and class form
 *
 */
function kleosis_current_grades_select_form() {

  // check permissions
  global $user;
  $view_grades = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis grades')) ) {
    $view_grades = FALSE;
  }

  if ( !isset($_SESSION['ks_student_current_grades_acyt_select']['toggle_grades']) ) {  // if not set, then this is the first time into this screen - set default sesion variables

    $_SESSION['ks_student_current_grades_acyt_select']['toggle_grades'] = 'inactive';
  }
  // get the class value from the session variable (if any) and set the default value accordingly
  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  $sql = 'SELECT nid, title FROM {node} n WHERE n.type = :type AND n.status = :status ORDER BY n.title' ;
  $results = db_query($sql, array(':type' => 'class', ':status' => 1, ) );
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
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;clear:left;width:130px" >',
    '#suffix' => '</div>',
  );
  $form['grades_select']['term'] = array(
    '#type' => 'select',
    '#title' => t('Term'),
    '#options' => array('all' => t('All')) + kleosis_academic_term_values(),
    '#default_value' => !empty($class_term) ? $class_term : 'fy',
    '#weight' => 3,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $form['grades_select']['select'] = array(
    '#type' => 'submit',
    '#value' => t('Set year and term'),
    '#weight' => 5,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );
  $form['grades_select']['class'] = array(
  '#type' => 'select',
    '#title' => t('Class'),
    '#options' =>  $options,
    '#default_value' => $class_id_from_filter,
    '#weight' => 7,
    '#prefix' => '<div style="float: left;clear:left;width:425px" >',
    '#suffix' => '</div>',
  );
  $form['grades_select']['get_grades'] = array(
    '#type' => 'submit',
    '#value' => t('Get current grades from Moodle gradebook'),
    '#weight' => 9,
    '#disabled' => !$view_grades,
    '#prefix' => '<div style="float: left;width:225px" ></br>',
    '#suffix' => '</div>',
  );
  return $form;
}

/**
 *
 * Current grades list form
 *
 */
function kleosis_current_grades_list() {

  drupal_set_title(t('Current Grades (by Class)'));

  $form = array();

  // get the filter values from the session variable (if any) and set the default form values accordingly

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  $build = array();

  // get the moodle class shortname (Course->course_no) for the selected class

  if ($class_id_from_filter) {
    $class_node = node_load($class_id_from_filter);
//    $classtitle = $class_node->title;
    $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
    $course_node = node_load($node_course_ref);
    $coursetitle = $course_node->title;
    $node_course_no =   $course_node->ks_course_no['und'][0]['value'];
  }
  else {
    return $build;  // todo: maybe return a message...
  }

  $class_shortname = $node_course_no;
  $grades_toggle = isset($_SESSION['ks_student_current_grades_acyt_select']['toggle_grades']) ? $_SESSION['ks_student_current_grades_acyt_select']['toggle_grades'] : 'inactive';

  if ( $grades_toggle == 'active' ) {  // get the grades from moodle

    $text = t('Current grades from Moodle for class<strong>@classname</strong>' . ': ' , array('@classname' => $class_shortname));

    $build['thegrades'] = array(
      '#markup' => $text,
      '#prefix' => '<div style="float: left;clear:left; width:425px" >',
      '#suffix' => '</div>',
      );

    $header = array(
      'student' => array('data' => t('Student')),
      'course' => array('data' => t('Course'), ),
      'grade' => array('data' => t('Current Grade (decimal)'), ),
      'str_grade' => array('data' => t('Current Grade (letter)'), ),
      'operations' => array('data' => t('Ops')),
    );

        $moodle_url = variable_get('kleosis_moodle_url', 'http://localhost/moodle');
        $grades = ws_get_course_grades($class_shortname);  // todo: evolve this function

        $options = array();

        $i = 0;
        if ( !empty($grades) ) {
        foreach ($grades as $key => $val) {
            if ( empty($val['error']) ) {
              $options[$i] = array('student' => $val['itemid'],
                            'course' => $coursetitle,
                            'grade' => ($val['grade']) ? number_format($val['grade'], 2) : '',
                            'str_grade' => $val['str_grade'],
                            'operations' => 'details',
                            );
              $i++;
            }
          }
        }
        asort($options);

    $build['grades'] = array(
          '#type' => 'table',       // used for table
  //        '#type' => 'tableselect',   // used for tableselect
          '#theme' => 'table',      // used only for table
          '#header' => $header,
  //        '#options' => $options,   // used for tableselect
          '#rows' => $options,   // used for table
          '#empty' => t('No current grades are available.'),
          '#multiple' => TRUE,
          '#js_select' => TRUE,
        );

    $_SESSION['ks_student_current_grades_acyt_select']['toggle_grades'] = 'inactive';
  }

  return $build;
}

/**
 *
 * Implementation of hook_submit() for the Current Grades List form.
 *   - main purpose is to store the selected class into session variables
 *
 */
function kleosis_current_grades_select_form_submit($form, &$form_state) {

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
    case 'Get current grades from Moodle gradebook':
      $_SESSION['ks_final_grades_class_filter']['class_id'] = $form_state['values']['class'];
      $_SESSION['ks_student_current_grades_acyt_select']['toggle_grades'] = 'active';

      break;
  }
}

/**
 * List the final grades by Class
 *
 * @return
 *    grades list...
 */
function kleosis_final_grades_by_class($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades'), 'kleosis/grades/final_grades/by_class');
  $breadcrumb[] = t('Final Grades by Class');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Final Grades (by Class)'));


  $build['filter'] = kleosis_final_grades_select_form();
  $build['#submit'][] = 'kleosis_final_grades_select_form_submit';
  $build['list'] = kleosis_final_grades_list();

  return $build;
}

/**
 *
 * Final grades filter by academic year, term, and class form
 *
 */
function kleosis_final_grades_select_form() {

  // check permissions
  global $user;
  $view_grades = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis grades')) ) {
    $view_grades = FALSE;
  }

  // get the class value from the session variable (if any) and set the default value accordingly
  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

  $sql = 'SELECT nid, title FROM {node} n WHERE n.type = :type AND n.status = :status ORDER BY n.title' ;
  $results = db_query($sql, array(':type' => 'class', ':status' => 1, ) );
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
    '#disabled' => !$view_grades,
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
function kleosis_final_grades_list() {


//drupal_set_title(t('Final Grades (by Class)'));

  $form = array();

  // get the filter values from the session variable (if any) and set the default form values accordingly

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';

  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';


    $header = array(
      'name' => array('data' => t('Student'), 'field' => 'u.name'),
      'final_grade' => t('Final Grade (decimal)'),
      'final_grade_str' => t('Final Grade (letter)'),
      'remarks' => t('Remarks'),
      'operations' => array('data' => t('Ops')),
    );

  $students_in_the_class = kleosis_get_students_in_class($class_id_from_filter);
//  dpm($students_in_the_class);

  $options = array();

  foreach ($students_in_the_class as $student) {

    $graderow = kleosis_get_student_final_grade_record($student->kstu_id_fk, $class_id_from_filter);

    $lp_kcclg = !empty($graderow) ? $graderow[0]->kcclg_id : 0;
    $lp_ksccl_id = $student->ksccl_id;

      $options[$student->kstu_id_fk] = array(
        'name' =>  l($student->name, 'kleosis/students/summary', array('query' => array('ksopid' => $student->kstu_id_fk, 'ksop' => $student->name))),
        'final_grade' => !empty($graderow) ? ( ($graderow[0]->final_grade > 0.00000)  ? number_format($graderow[0]->final_grade, 2) : '' ) : '',
        'final_grade_str' => !empty($graderow) ? $graderow[0]->final_grade_str : '',
        'remarks' => !empty($graderow) ? $graderow[0]->remarks : '',
  //      'operations' => l(t('edit'), 'kleosis/grades/final_grades_edit', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name, 'destination' => 'kleosis/grades_ls/final_grades_ls')))
        'operations' => l(t('edit'), 'kleosis/grades/final_grades_edit', array('query' => array('ksopgid' => $lp_kcclg, 'ksopcclid' => $lp_ksccl_id, 'ksopcid' => $class_id_from_filter, 'ksopsid' => $student->kstu_id_fk, 'ksopsn' => $student->name,  'destination' => 'kleosis/grades/final_grades')))
       );
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
 *
 * Implementation of hook_submit() for the Final Grades List form.
 *   - main purpose is to store the selected class into session variables
 *
 */
function kleosis_final_grades_select_form_submit($form, &$form_state) {

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

      $form_state['redirect'] = 'kleosis/grades/final_grades_edit';

      break;
  }
}


/**
 *
 * Final grades edit form
 *
 */
function kleosis_final_grades_edit_form($form, &$form_state) {

  // check permissions
  global $user;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('edit kleosis grades')) ) {
    drupal_set_message(t("You currently do not have permissions to edit grades."));
    $options = array('query' => array('destination' => 'kleosis/students') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  drupal_set_title(t('Edit Final Grades'));

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades-'), 'kleosis/grades/final_grades');
  $breadcrumb[] = t('Edit final grades');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  $kcclg_id = isset( $_GET['ksopgid'] ) ? $_GET['ksopgid'] : 0;
  $ksccl_id = isset( $_GET['ksopcclid'] ) ? $_GET['ksopcclid'] : 0;
  $class_id = isset( $_GET['ksopcid'] ) ? $_GET['ksopcid'] : 0;
  $student_id = isset( $_GET['ksopsid'] ) ? $_GET['ksopsid'] : 0;
  $student_name = isset( $_GET['ksopsn'] ) ? $_GET['ksopsn'] : 'no student selected';

  if ($class_id == 0) {
    drupal_set_message(t('Please select the edit link in the Ops column for a student.'));
    $form_state['redirect'] = 'kleosis/grades/final_grades';
    drupal_redirect_form($form_state);
  }
  $node = node_load($class_id);
  $class_name = $node->title;

  $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;
  $class_name_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_name']) ? $_SESSION['ks_final_grades_class_filter']['class_name'] : '';
  $class_academic_year = isset($_SESSION['ks_final_grades_class_filter']['academic_year']) ? $_SESSION['ks_final_grades_class_filter']['academic_year'] : '2011-2012';
  $class_term = isset($_SESSION['ks_final_grades_class_filter']['term']) ? $_SESSION['ks_final_grades_class_filter']['term'] : 'fy';

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
  $form['grades_edit']['final_grade'] = array(
    '#type' => 'textfield',
    '#title' => t('Final grade (decimal)'),
    '#default_value' =>  !empty($grades) ? $grades[0]->final_grade : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 0,
    '#description' => 'Final decimal grade',
    '#prefix' => '<div style="float: left;clear:left;width:175px" ><br/>',
    '#suffix' => '</div>',
  );
  $form['grades_edit']['final_grade_str'] = array(
    '#type' => 'textfield',
    '#title' => t('Final grade (letter)'),
    '#default_value' =>  !empty($grades) ? $grades[0]->final_grade_str : '',
    '#size' => 7,
    '#maxlength' => 8,
    '#weight' => 2,
    '#description' => 'Final letter grade',
    '#prefix' => '<div style="float: left;width:175px" ><br/>',
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
 * Implementation of hook_validate() for the Edit Final Grades form.
 *
 */
function kleosis_final_grades_edit_form_validate($form, &$form_state) {

// dpm($form_state);
  if ($form_state['values']['op'] == 'Cancel') {
    return;
  }
  if ( (empty($form_state['values']['final_grade'])) || (!is_numeric($form_state['values']['final_grade'])) ) {
      form_set_error('final_grade', t('Final grade must be a decimal number.'), $limit_validation_errors = NULL);
  }
}

/**
 *
 * Implementation of hook_submit() for the Edit Final Grades form.
 *
 */
function kleosis_final_grades_edit_form_submit($form, &$form_state) {

//  dpm($form);
//  dpm($form_state['input']['final_grade']);
  switch ($form_state['values']['op']) {

    case 'Update':

    $final_grade = $form_state['values']['final_grade'];
    $final_grade_str = $form_state['values']['final_grade_str'];

    $class_id_from_filter = isset($_SESSION['ks_final_grades_class_filter']['class_id']) ? $_SESSION['ks_final_grades_class_filter']['class_id'] : 0;

    $ks_final_grade_record = array();
    $ks_final_grade_record['kcclg_id'] = $form_state['values']['kcclg_id'];
    $ks_final_grade_record['ksccl_id_fk'] = $form_state['values']['ksccl_id'];
//    $ks_final_grade_record['current_grade'] = $form_state['values']['current_grade'];
//    $ks_final_grade_record['current_grade_str'] = $form_state['values']['current_grade_str'];
//    $ks_final_grade_record['final_exam_grade'] = $form_state['values']['final_exam_grade'];
//    $ks_final_grade_record['course_grade'] = $form_state['values']['course_grade'];
//    $ks_final_grade_record['grade_item_1'] = $form_state['values']['grade_item_1'];
//    $ks_final_grade_record['grade_item_2'] = $form_state['values']['grade_item_2'];
//    $ks_final_grade_record['grade_item_3'] = $form_state['values']['grade_item_3'];
//    $ks_final_grade_record['final_grade'] = $form_state['values']['final_grade'];
//    $ks_final_grade_record['final_grade_str'] = $form_state['values']['final_grade_str'];
    $ks_final_grade_record['final_grade'] = $final_grade;
    $ks_final_grade_record['final_grade_str'] = $final_grade_str;
    $ks_final_grade_record['remarks'] = $form_state['values']['remarks'];

    if ($ks_final_grade_record['kcclg_id']) {
      $res = ks_update_final_grade_record($ks_final_grade_record);
    }
    else {
      $res = ks_insert_final_grade_record($ks_final_grade_record);
    }

//    $form_state['redirect'] = 'kleosis/grades/final_grades';
//    drupal_redirect_form($form_state);

      break;

    case 'Cancel':

//    $form_state['redirect'] = 'kleosis/grades/final_grades';
//    drupal_redirect_form($form_state);

      break;
    }
}
/**
 * Provides Grades functions available in kleosis available in Kleosis
 *
 * @return
 *   tbd
 */

/**
 * Defines a get current grades placeholder tab
 *  (not currently used - moved to student/grades/current_grades)
 *
 * @return
 *    a markup blurb...
 */
function kleosis_current_grades_by_student($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Current grades'), 'kleosis/grades/current_grades');
  $breadcrumb[] = t('Current Grades by Student');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Current Grades by Student'));

$page_desc = <<<EOT
    <br/>This is the kleosis_current_grades_by_student form.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Current Grades by Student'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );
  return $form;
}

/**
 * Defines a grades placeholder tab - not currently used
 *  (not currently used - moved to student/grades/final_grades)
 *
 * @return
 *    a markup blurb...
 */
function kleosis_final_grades_by_student($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades'), 'kleosis/grades/final_grades');
  $breadcrumb[] = t('Final Grades by Student');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Final Grades by Student'));

$page_desc = <<<EOT
    <br/>This is the kleosis_final_grades_by_student form.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Final Grades by Student'),
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
function kleosis_edit_final_grades($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Final grades'), 'kleosis/grades/final_grades_edit');
  $breadcrumb[] = t('Edit Final Grades');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Edit Final Grades'));

$page_desc = <<<EOT
    <br/>This is the kleosis_edit_final_grades form.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Edit Final Grades'),
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
function kleosis_grade_scales($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Grades'), 'kleosis/grades/grade_scales');
  $breadcrumb[] = t('Grade Scales');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Grade Scales'));

$page_desc = <<<EOT
    <br/>This is the kleosis_grade_scales form.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Grade Scales'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );
  return $form;
}

