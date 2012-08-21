<?php

 /**
 * @file
 *   Kleosis Reports
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
    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page.'));
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
 * Academic year and term selection for the Student OpenOffice (.odt) Reports form
 *
 */
function kleosis_student_reports_odt_acyt_select_form() {

  // check permissions
  global $user;
  $view_reports = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis reports and queries')) ) {
    $view_reports = FALSE;
  }

  $academic_year = isset($_SESSION['ks_student_reports_odt_select_filter']['academic_year']) ? $_SESSION['ks_student_reports_odt_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2011-2012');
  $term = isset($_SESSION['ks_student_reports_odt_select_filter']['term']) ? $_SESSION['ks_student_reports_odt_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');
  $report_odt = isset($_SESSION['ks_student_reports_odt_select_filter']['report_odt']) ? $_SESSION['ks_student_reports_odt_select_filter']['report_odt'] : 'none';

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
  * These reports are template-based using the OpenOffice standard document file format (.odt) -
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
  $organization = ks_get_organization_desc(variable_get('kleosis_organization', '1'));
  $filename = $academic_year . '_' . $term . '_' . $name . '_' . $report_odt;

  // check if the selected report exists
  $this_dir_name = dirname(__FILE__);
  $curr_odtreport_dir = '/odtreports/reports/';
  $fullpath = $this_dir_name . $curr_odtreport_dir . $report_odt . '.odt';

  $file_ok = file_exists("$fullpath");

  if ( $report_odt == 'none' || $report_odt == 'other' || !$file_ok) {
    drupal_set_message(t('Please select a valid report from the Reports select box.'));
  }
  else {

    // get the students gradelevel
    $ks_student = ks_get_student_record($uid);
    $stu_gradelevel_label = kleosis_get_desc_table_label('ks_course_gradelevel', $ks_student['curr_gradelevel']);

    $fullname = $ks_student['fullname'];

		//  get the course names for classes that the current student is enrolled in
		$enrolled_classes_shortnames = kleosis_get_current_classes($uid, $academic_year, $term);

    global $base_url;

    $kleosispath = drupal_get_path('module', 'kleosis');
    $rptlibpath = $kleosispath . '/includes/odtreports/library/odf.php';
    $reportpath = $kleosispath . '/includes/odtreports/reports' . '/' . $report_odt . '.odt';
    require_once ($rptlibpath);

    $odf = new odf($reportpath);

    $odf->setVars('school', 'Kleosis Sample International School');

    $reportname = $report_odt_name . ' Report Card';
    $odf->setVars('reportname', $reportname);

    $odf->setVars('studentname', $fullname);
    $odf->setVars('gradelevel', $stu_gradelevel_label);

    $rpt_date = new DateTime('now');
    $odf->setVars('reportdate', $rpt_date->format('F') . '  ' . $rpt_date->format('Y'));

//    $xtra_var_1 = 'Extra Var 1';
//    $odf->setVars('odtextra1', $xtra_var_1);


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

//file_exists("test.txt");


  //  $odf->saveToDisk($filename_with_path);

    $odf->exportAsAttachedFile($filename);

//    drupal_set_message(t('Report filename' . ': ') . $filename . ' was successfully downloaded.');
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
 * Provides various webform interactive reports for a student
 *
 * @return
 *    a webform interactive report...
 */
function kleosis_student_reports_wf($form, &$form_state) {

  $uid = isset( $_GET['ksopid'] ) ? $_GET['ksopid'] : (isset($_SESSION['student']['id']) ? $_SESSION['student']['id'] : 0);
  $name = isset( $_GET['ksop'] ) ? $_GET['ksop'] : (isset($_SESSION['student']['name']) ? $_SESSION['student']['name'] : '');

  if ($uid == 0) {
    drupal_set_message(t('Please select a Student by clicking on a Student link.from the Student List page.'));
    drupal_goto($path = 'kleosis/students', $options = array());
  }

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Students'), 'kleosis/students');
  $breadcrumb[] = t('Student Webform Reports');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Student Webform Reports'));

  $build['filter'] = kleosis_student_reports_wf_acyt_select_form();
	$build['#submit'][] = 'kleosis_student_reports_wf_acyt_select_form_submit';
	$build['list'] = kleosis_student_reports_wf_list();

  return $build;

//  return array();
}

/**
 *
 * Academic year and term selection for the Student Webform Interactive Reports form
 *
 */
function kleosis_student_reports_wf_acyt_select_form() {

  // check permissions
  global $user;
  $view_reports = TRUE;
  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis reports and queries')) ) {
    $view_reports = FALSE;
  }

  $academic_year = isset($_SESSION['ks_student_reports_wf_select_filter']['academic_year']) ? $_SESSION['ks_student_reports_wf_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2012-2013');
  $term = isset($_SESSION['ks_student_reports_wf_select_filter']['term']) ? $_SESSION['ks_student_reports_wf_select_filter']['term'] : variable_get('kleosis_academic_term', 'fy');
  $report_wf = isset($_SESSION['ks_student_reports_wf_select_filter']['report_wf']) ? $_SESSION['ks_student_reports_wf_select_filter']['report_wf'] : 'none';

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
    '#prefix' => '<div style="float: left;width:90px" >',
    '#suffix' => '</div>',
  );
  $build['acy_select']['reports_wf'] = array(
    '#type' => 'select',
    '#title' => t('Reports'),
    '#options' => array('none' => t('None')) + kleosis_webform_report_types_values(),
    '#default_value' => $report_wf,
    '#disabled' => FALSE,
    '#weight' => 5,
    '#prefix' => '<div style="float: left;width:200px" >',
    '#suffix' => '</div>',
  );

  $build['acy_select']['createit'] = array(
    '#type' => 'submit',
    '#value' => t('Create Report'),
    '#weight' => 10,
    '#disabled' => !$view_reports,
    '#prefix' => '<div style="float: left;width:140px" ></br>',
    '#suffix' => '</div>',
  );

  $build['acy_select']['viewit'] = array(
    '#type' => 'submit',
    '#value' => t('View Reports'),
    '#weight' => 12,
    '#disabled' => !$view_reports,
    '#prefix' => '<div style="float: left;width:170px" ></br>',
    '#suffix' => '</div>',
  );
/*
  $wfreport_desc = <<<EOT
  * These Webform reports can be created and modified by a user with appropriate permissions -
  see the Kleosis documentation for more information on these user-customizable reports.
EOT;

  $build['report_type'] = array(
    '#markup' => t($wfreport_desc),
    #weight' => 15,
    );
*/
  return $build;
}

/**
 * Provides a list of interactive (webform) reports for a student
 *
 * @return
 *   a form with list of entries
 */
function kleosis_student_reports_wf_list() {

  $academic_year = isset($_SESSION['ks_student_reports_wf_select_filter']['academic_year']) ? $_SESSION['ks_student_reports_wf_select_filter']['academic_year'] : variable_get('kleosis_academic_year', '2012-2013');
	$report_name = isset($_SESSION['ks_student_reports_wf_select_filter']['report_wf_name']) ? $_SESSION['ks_student_reports_wf_select_filter']['report_wf_name'] : 'none';
	$student_id = $_SESSION['student']['id'];

	$sids = array();
	$cids = array();
	$form = array();

  $header = array(
    'report_title' => array('data' => t('Report')),
    'submitter' => array('data' => t('Submitted By')),
    'report_date' => array('data' => t('Report Date'), 'field' => 'report_date'),
    'ops' => array('data' => t('Ops')),
  );
  $options = array();

	// get the nid for the selected report
	$nid = db_query('SELECT nid FROM {node} WHERE title = :rpt_title AND type = :type',
														array(':rpt_title' => $report_name,
																	':type' => 'webform'))->fetchField();
	if (empty($nid)) {
		drupal_set_message(t('Selected report not found'));
		return;
	}

	// get all component ids for the selected report
	$comp_result = db_query('SELECT cid, form_key FROM {webform_component} WHERE nid = :nid',
														array(':nid' => $nid,))->fetchAll();

	foreach($comp_result as $therow) {
    $cids[$therow->cid] = $therow->form_key;
	}
	// get the component ids that will be shown in display list (or used in a filter)
	$stu_id_cid = array_search('student_id', $cids);
	$report_title_cid = array_search('report_title', $cids);
	$report_date_cid = array_search('report_date', $cids);
	$academic_year_cid = array_search('academic_year', $cids);

	// filter the submissions based on the student
  $subm_stu_id_data_result = '';
  $query = db_select('webform_submitted_data', 'wsd');
  $query->addField('wsd', 'sid');
  $query->condition('wsd.nid', $nid, '=');
  $query->condition('wsd.cid', $stu_id_cid, '=');
  $query->condition('wsd.data', $student_id, '=');
  $subm_stu_id_data_result = $query->execute()->fetchAll();

	foreach($subm_stu_id_data_result as $sidrow) {
		$sids[] = $sidrow->sid;
	}

	// then, filter the submissions based on the academic year
  $subm_acy_data_result = '';
  $query = db_select('webform_submitted_data', 'wsd');
  $query->addField('wsd', 'sid');
  $query->condition('wsd.nid', $nid, '=');
	if ($academic_year != 'all') {
	  $query->condition('wsd.cid', $academic_year_cid, '=');
	 	$query->condition('wsd.data', $academic_year, '=');
}
	if (!empty($sids)) {
	  $query->condition('wsd.sid', $sids, 'IN');
	}
	else {
	  $query->condition('wsd.sid', array(0), 'IN');
	}
  $subm_acy_data_result = $query->execute()->fetchAll();

	// use the sids to get the other field data
	foreach ($subm_acy_data_result as $thesidrow) {

		$rpt_title_result = db_query('SELECT data FROM {webform_submitted_data} WHERE sid = :sid AND cid = :cid',
															array(':sid' => $thesidrow->sid,
																		':cid' => $report_title_cid,))->fetchField();
		$rpt_date_result = db_query('SELECT data FROM {webform_submitted_data} WHERE sid = :sid AND cid = :cid',
															array(':sid' => $thesidrow->sid,																		':cid' => $report_date_cid,))->fetchField();

		$rpt_submitted_by = db_query('SELECT uid FROM {webform_submissions} WHERE sid = :sid',
															array(':sid' => $thesidrow->sid,))->fetchField();
		// 	stu_id_result = db_query('SELECT data FROM {webform_submitted_data} WHERE sid = :sid AND cid = :cid',
		//													array(':sid' => $thesidrow->sid,
		//																':cid' => $stu_id_cid,))->fetchField();
		$options[$thesidrow->sid] = array(
			'report_title' => $rpt_title_result,
			'submitter' => get_ks_username_by_id($rpt_submitted_by),
			'report_date' => $rpt_date_result,
			'ops' => l(t('view'), 'node/' . $nid . '/submission/' . $thesidrow->sid, array('query' => array('destination' => 'kleosis/students/reports/wf_reports'))),
		);
	}

	$form['ks_interactive_reports_list'] = array(
    '#type' => 'table',       // used for table
    '#theme' => 'table',      // used only for table
    '#header' => $header,
    '#rows' => $options,   // used for table
    '#empty' => t('No interactive reports exist for this student.'),
    '#multiple' => TRUE,
    '#js_select' => TRUE,
    '#prefix' => '<div style="float: left;clear: left;width:700px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 *
 * Implementation of hook_submit() for the Students Webform Reports Select form.
 *
 */
function kleosis_student_reports_wf_acyt_select_form_submit($form, &$form_state) {

  $uid = $_SESSION['student']['id'];
  $name = $_SESSION['student']['name'];
  $report_name = $form['filter']['acy_select']['reports_wf']['#options'][$form_state['values']['reports_wf']];
	$academic_year = $form_state['values']['academic_year'];
	$term = $form_state['values']['term'];
	$_SESSION['ks_student_reports_wf_select_filter'] = array(
																		'academic_year' => $academic_year,
																		'term' => $term,
																		'report_wf' => $form_state['values']['reports_wf'],
																		'report_wf_name' => $report_name,
																	 );

  switch ($form_state['values']['op']) {

    case 'Create Report':

			$nid = db_query('SELECT nid FROM {node} WHERE title = :rpt_title AND type = :type',
																array(':rpt_title' => $report_name,
																			':type' => 'webform'))->fetchField();
			if (empty($nid)) {
				drupal_set_message(t('Selected report not found'));
				return;
			}

  		$today = new DateTime('now');
    	// get the students gradelevel
    	$ks_student = ks_get_student_record($uid);
    	$stu_gradelevel_label = kleosis_get_desc_table_label('ks_course_gradelevel', $ks_student['curr_gradelevel']);

			$ksr_date = $today->format('Y-m-d');
			$ksr_title = $report_name . ' - ';
			$ksr_acy = $form_state['values']['academic_year'];
			$ksr_term = $form_state['values']['term'];
			$ksr_sname = $name;
			$ksr_stid = $uid;
			$ksr_grlevel = $stu_gradelevel_label;
			$ksr_cls1 = 'Le Class UnoUno';
			$ksr_cls2 = 'Le Class Dos';

			//  get the course names for classes that the current student is enrolled in
			if ( !empty($uid) && !empty($academic_year) && !empty($term)) {
				$enrolled_classes_shortnames = kleosis_get_current_classes($uid, $academic_year, $term);
			}
			$clsarray = array();
			$i=1;
			while($i<=12) {	// set each course name to blank
				$clsarray['ksr_cls' . $i] = '';
				$i++;
			}

			$i = 1;
			foreach($enrolled_classes_shortnames AS $element) {
				$clsarray['ksr_cls' . $i] = $element['course'];
				$i++;
			}
			//pre-populate and create the webform
			drupal_goto($path = 'node/' . $nid,
									$options =  array('query' => array( 'ksr_title' => $ksr_title,
																											'ksr_date' => $ksr_date,
																											'ksr_acy' => $ksr_acy,
																											'ksr_term' => $ksr_term,
																											'ksr_sname' => $ksr_sname,
																											'ksr_stid' => $ksr_stid,
																											'ksr_grlevel' => $ksr_grlevel,
																											'ksr_cls1' => $clsarray['ksr_cls1'],
																											'ksr_cls2' => $clsarray['ksr_cls2'],
																											'ksr_cls3' => $clsarray['ksr_cls3'],
																											'ksr_cls4' => $clsarray['ksr_cls4'],
																											'ksr_cls5' => $clsarray['ksr_cls5'],
																											'ksr_cls6' => $clsarray['ksr_cls6'],
																											'ksr_cls7' => $clsarray['ksr_cls7'],
																											'ksr_cls8' => $clsarray['ksr_cls8'],
																											'ksr_cls9' => $clsarray['ksr_cls9'],
																											'ksr_cls10' => $clsarray['ksr_cls10'],
																											'ksr_cls11' => $clsarray['ksr_cls11'],
																											'ksr_cls12' => $clsarray['ksr_cls12'],
																											'destination' => 'kleosis/students/reports/wf_reports')));
			break;

    case 'View Reports':
		// form refreshes itself...
      break;
	}
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
    <br/>These customizable, interactive reports will allow the user to add and edit additional data, add and arrange new fields,
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
    <br/>The student transcript is generated as an OpenOffice document from a customizable template (tbd)
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

/**
 * Obtains all current classes for a student
 *
 * @param $uid
 *    student id
 * @param $academic_year
 *    academic_year
 * @param $term
 *    academic term
 * @return
 *   array of class shortnames
 */
function kleosis_get_current_classes($uid, $academic_year, $term) {

  ///  The following section of code will get the course names for classes the current student is enrolled in

  //  get the class nids for the selected academic year and term:
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'class')
    ->fieldCondition('ks_class_term', 'value', $term, '=')
    ->fieldCondition('ks_class_academic_year', 'value', $academic_year, '=')
    ->fieldCondition('ks_class_status', 'value', '1', '=')  // 'Active'
    ->propertyCondition('status', 1)  // not needed, just an example...
    // ->fieldCondition('example_field_date', 'value', array('2011-03-01', '2011-03-31'), 'BETWEEN')    // not needed, just an example...
    // ->fieldCondition('example_other_field', 'state', (array) $states, 'IN', 0);   // not needed, just an example.
    ->fieldOrderBy('ks_class_academic_year', 'value', 'ASC');

    $result = $query->execute();

    $nids = array();
    if ( !empty($result) ) {
      $nids = array_keys($result['node']);  // these nids will be used to filter the following query:
    }
    else {
			drupal_set_message(t('No classes exist in the selected academic year and term for this student' . '.'), $type = 'warning');
			return array();
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

        $node_course_type_label = kleosis_get_desc_table_label('ks_course_type', $node_course_type);
      }
      else {
        $node_course_no =  '';
      }
      if ( $node_course_type_label != 'Attendance' &&  $node_course_type_label != 'Lunch-Breaktime' ) {
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

 return $enrolled_classes_shortnames;
}

