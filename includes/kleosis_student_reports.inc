<?php
 /**
 * @file
 * kleosis Reports
 */

/**
 * Provides various reports for a student using .odt files
 *
 * @return
 *   a downloaded .odt file
 */

function kleosis_student_reports_odt($form, &$form_state) {

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message('Please select a Student by clicking on a Student link.from the Student List page.');
    drupal_goto($path = 'kleosis/students', $options = array());
  }

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Reports');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Reports'));

  $build['filter'] = kleosis_student_reports_odt_acyt_select_form();
  $build['#submit'][] = 'kleosis_student_reports_odt_acyt_select_form_submit';
  $build['list'] = kleosis_student_reports_odt_list();

  return $build;
}

/**
 *
 * Academic year and term selection for the Student Open Office (.odt) Reports form
 *
 */

function kleosis_student_reports_odt_acyt_select_form() {

  // check permissions
  global $user;
  $view_reports = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view reports and queries')) ) {
    $view_reports = FALSE;
  }

  $academic_year = isset($_SESSION['ks_student_reports_odt_select_filter']['academic_year']) ? $_SESSION['ks_student_reports_odt_select_filter']['academic_year'] : variable_get('kleosis_academic_year','2011-2012');
  $term = isset($_SESSION['ks_student_reports_odt_select_filter']['term']) ? $_SESSION['ks_student_reports_odt_select_filter']['term'] : variable_get('kleosis_academic_term','fy');
  $report_odt = isset($_SESSION['ks_student_reports_odt_select_filter']['report_odt']) ? $_SESSION['ks_student_reports_odt_select_filter']['report_odt'] : 'none';

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  // create a fieldset for the class academic year and term selection
  $build['acy_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Academic Year') . ': ' . $academic_year . '&nbsp; &nbsp; &nbsp; ' . t('Term') . ': ' . $term . '&nbsp; &nbsp; &nbsp; ' . t('Student') . ': ' . $name,
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
    '#prefix' => '<div style="float: left;width:90px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['reports_odt'] = array(
    '#type' => 'select',
    '#title' => t('Reports'),
    '#options' => array('none' => t('None')) + kleosis_report_odt_values(),
    '#default_value' => $report_odt,
    '#disabled' => FALSE,
    '#weight' => 5,
    '#prefix' => '<div style="float: left;width:200px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['download'] = array(
    '#type' => 'submit',
    '#value' => t('Download Report'),
    '#weight' => 10,
    '#disabled' => !$view_reports,
    '#prefix' => '<div style="float: left;width:170px" ></br>',
    '#suffix' => '</div>',
  );
  $build['acy_select']['upload'] = array(
    '#type' => 'submit',
    '#value' => t('Upload Report'),
    '#weight' => 12,
//    '#disabled' => !$view_reports,
    '#disabled' => TRUE,
    '#prefix' => '<div style="float: left;width:140px" ></br>',
    '#suffix' => '</div>',
  );

  $odtreport_desc = <<<EOT
  * These reports are template-based using the Open Office standard document file format (.odt) -
  see the Kleosis documentation for more information on these user-customizable reports.
EOT;

  $build['report_type'] = array(
    '#markup' => t($odtreport_desc),
    #weight' => 10,
    );

  return $build;
}

/**
 *
 * Implementation of hook_submit() for the Students Reports Select form.
 *
 */
function kleosis_student_reports_odt_acyt_select_form_submit($form, &$form_state) {

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];

  switch ($form_state['values']['op']) {

    case 'Download Report':

      $_SESSION['ks_student_reports_odt_select_filter'] = array(
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                        'report_odt' => $form_state['values']['reports_odt'],
                                        'report_odt_name' => $form['filter']['acy_select']['reports_odt']['#options'][$form_state['values']['reports_odt']],
                                       );
      kleosis_student_reports_odt_download();
      break;
    case 'Upload Report':
      $_SESSION['ks_student_reports_odt_select_filter'] = array(
                                        'academic_year' => $form_state['values']['academic_year'],
                                        'term' => $form_state['values']['term'],
                                        'report_odt' => $form_state['values']['reports_odt'],
                                        'report_odt_name' => $form['filter']['acy_select']['reports_odt']['#options'][$form_state['values']['reports_odt']],
                                      );
      kleosis_student_reports_odt_upload();
      break;
  }
}

/**
 *
 * Report_odt Download
 *
 */
function kleosis_student_reports_odt_download() {

  error_reporting(E_ERROR); // todo: fix the cause of the error message about headers already being sent...
                            // todo: verify that the newer odtphp.lib file fixed the error...

  $academic_year = isset($_SESSION['ks_student_reports_odt_select_filter']['academic_year']) ? $_SESSION['ks_student_reports_odt_select_filter']['academic_year'] : variable_get('kleosis_academic_year','2011-2012');
  $term = isset($_SESSION['ks_student_reports_odt_select_filter']['term']) ? $_SESSION['ks_student_reports_odt_select_filter']['term'] : variable_get('kleosis_academic_term','fy');
  $report_odt = isset($_SESSION['ks_student_reports_odt_select_filter']['report_odt']) ? $_SESSION['ks_student_reports_odt_select_filter']['report_odt'] : 'none';
  $report_odt_name = isset($_SESSION['ks_student_reports_odt_select_filter']['report_odt_name']) ? $_SESSION['ks_student_reports_odt_select_filter']['report_odt_name'] : 'none';
  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];
  $organization = get_organization_desc(variable_get('kleosis_organization', '1'));
  $filename = $academic_year . '_' . $term . '_' . $name . '_' . $report_odt;

  if ( $report_odt == 'none' || $report_odt == 'other' ) {
    drupal_set_message(t('Please select a report from the Reports select box.'));
  }
  else {

    // get the students gradelevel
    $ks_student = ks_get_student_record($uid);
    $stu_gradelevel = ks_map_ks_gradelevel_to_drp($ks_student['curr_gradelevel']);
    $fullname = $ks_student['fullname'];

  ///  The following section of code will get the course names for classes the current student is enrolled in

  //  get the class nids for the selected academic year and term:

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'class')
    ->fieldCondition('ks_class_term', 'value', $term, '=')
    ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
    ->fieldCondition('ks_class_status', 'value', 'active', '=')
    ->propertyCondition('status', 1)  // not needed, just an example...
    // ->fieldCondition('example_field_date', 'value', array('2011-03-01', '2011-03-31'), 'BETWEEN')    // not needed, just an example...
    // ->fieldCondition('example_other_field', 'state', (array) $states, 'IN', 0);   // not needed, just an example.
    ->fieldOrderBy('ks_class_academic_year', 'value', 'ASC');

    $result = $query->execute();

    $nids = array();

    if ( !empty($result) ) {
      $nids = array_keys($result['node']);  // these nids will be used to filter the following query:
    }

    $query = db_select('ks_student_course_classes', 'ksscc');
    $query->innerJoin('users', 'u', 'u.uid = ksscc.kstu_id_fk');
    $query->addField('u', 'name');
    $query->addField('ksscc', 'ksccl_id');
    $query->addField('ksscc', 'kstu_id_fk');
    $query->addField('ksscc', 'kccls_id_fk');
    $query->addField('ksscc', 'enrol_date');
    $query->addField('ksscc', 'completed');
    $query->addField('ksscc', 'final_grade');
  //  $query->addField('ksscc', 'final_attendance');
    $query->addField('ksscc', 'remarks');

    $query->condition('ksscc.' . 'kstu_id_fk', $uid, '=');
    $query->condition('ksscc.' . 'kccls_id_fk', $nids, 'IN');
    $query->isNull('unenrol_date');

    // Only get items 0-1999, for scalability reasons...
    $query->range(0, 2000);


    $enrolled_classes = array();
    $enrolled_classes_shortnames = array();

    $results = $query->execute()->fetchAll();

    foreach ($results as $course_class) {

      $node = node_load($course_class->kccls_id_fk);

  //  get the Course Number (short coursename)

      if ($course_class->kccls_id_fk) {
        $class_node = node_load($course_class->kccls_id_fk);
        $node_course_ref =   $class_node->ks_class_course_ref['und'][0]['nid'];
        $course_node = node_load($node_course_ref);
        $node_course_no =   $course_node->ks_course_no['und'][0]['value'];
        $node_course_type =   $course_node->ks_course_type['und'][0]['value'];

      }
      else {
        $node_course_no =  '';
      }

      if (   $node_course_type != 'attendance' &&  $node_course_type != 'lunch-breaktime'  ) {
      /*
        $enrolled_classes[$node->nid] = array(
          'title' =>  $node->title,
          'course_no' =>  $node_course_no,
        );
      */
        $enrolled_classes_shortnames[] = array('course' => $node_course_no,);
      }
    }

  ///  The above section of code retrieved the course names for classes the current student is enrolled in

    global $base_url;

    $kleosispath = drupal_get_path('module', 'kleosis');
    $rptlibpath = $kleosispath . '/includes/odtreports/library/odf.php';
  //  $reportpath = 'sites/default/files/kleosis_files/odttemplates/' . $report_odt . '.odt';
    $reportpath = $kleosispath . '/includes/odtreports/reports' . '/' . $report_odt . '.odt';
    require_once ($rptlibpath);

    $odf = new odf($reportpath);

    $odf->setVars('school', 'Kleosis Sample International School');

    $reportname = $report_odt_name . ' Report Card';
    $odf->setVars('reportname', $reportname);

    $odf->setVars('studentname', $fullname);
    $odf->setVars('gradelevel', $stu_gradelevel);

    $rpt_date = new DateTime('now');
    $odf->setVars('reportdate', $rpt_date->format('F') . '  ' . $rpt_date->format('Y'));


    $article = $odf->setSegment('articles');

    foreach($enrolled_classes_shortnames AS $element) {
      $article->courseArticle($element['course']);
      $article->merge();
    }

    $odf->mergeSegment($article);

    // Export the file

    $filename .= '.odt';
  //  $odf->saveToDisk($filename);  // stores in ..kleoport

    $filename_with_path = 'sites/default/files/kleosis_files/odtreports/' . $filename;

  //  $odf->saveToDisk($filename_with_path);

    $odf->exportAsAttachedFile($filename);

//    drupal_set_message(t('Report filename: ') . $filename . ' was successfully downloaded.');
  }
}
/**
 *
 * Report_odt Upload
 *
 */
function kleosis_student_reports_odt_upload() {

  drupal_set_message(t('Reports upload is being developed...'));
}

/**
 *
 * Student Reports list form (not currently used)
 *
 */
function kleosis_student_reports_odt_list() {

//  $form = array();
//  $form['nada'] = array(
//      '#markup' => t('report feature development is in process...'),
//    );
//  return $form;
}


/**
 * Defines a student reports main tab
 *
 * @return
 *    redirects to kleosis_student_reports_odt
 */
function kleosis_student_reports($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Reports');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Reports'));


  $page_desc = <<<EOT
    <br/>This is the kleosis_student_reports form.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Student Reports'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );
  drupal_goto($path = 'kleosis/students/reports/odt_reports', $options = array());
  return $form;
}

/**
 * Provides various interactive reports for a student
 *
 * @return
 *    an interactive report...
 */
function kleosis_student_reports_ia($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Interactive Reports');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Interactive Reports'));


  $page_desc = <<<EOT
    <br/>These interactive reports will allow the user to add and edit additional data to each report.
    The added data becomes managed by Kleosis and can be searched for fast retrieval (tbd)
    - see the Kleosis documentation for more information on these reports.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Student Interactive Reports'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );
  return $form;
}

/**
 * Provides various reports using the PDS Report Service
 *
 * @return
 *    interacts with the PDS Report Service (tbd)
 */
function kleosis_student_reports_pds($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('PDS Report Service');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('PDS Report Service'));


  $page_desc = <<<EOT
    <br/>These customizeable, interactive reports will allow the user to add and edit additional data, add and arrange new fields,
    select themes, control layout and printing, subscribe to report events, and enable numerous other report options from the PDS Report Service (tbd).
    The added data becomes managed by PDS report service and can be searched for fast retrieval (tbd)
    - see the Kleosis documentation for more information on these reports.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info

  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('PDS Report Service'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );
  return $form;
}

/**
 * Provides a transcript for a student using an .odt template
 *
 * @return
 *   a downloaded .odt file
 */

function kleosis_student_transcript_odt($form, &$form_state) {

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Transcript');

  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Transcript'));

  $page_desc = <<<EOT
    <br/>The student transcript is generated as an Open Office document from a customizeable template (tbd)
        - see the Kleosis documentation for more information.
    <br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  // add a fieldset for the page info
  $form['pagehelp'] = array(
      '#type' => 'fieldset',
      '#title' => t('Student Transcripts'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

  $form['pagehelp']['pageinfo'] = array(
      '#markup' => $page_desc,
    );

  return $form;
}
