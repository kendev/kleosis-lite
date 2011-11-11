<?php
// $Id$
/**
* @file
* kleosis LMS Direct
*/

/**
 * Provides LMS Direct functions available in kleosis available in kleosis (callback function)
 *
 * @return
 *   tbd
 */

// todo: move the other moodle direct functions into this file

function kleosis_lms_direct_page($form, &$form_state) {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = t('LMS Direct');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

drupal_set_title(t('LMS Direct - demo'));

$page_desc = <<<EOT
    <br/>This is the base page for the kleosis LMS Direct functions that directly access the Moodle API thru the webservices layer. <br/><br/>
    The above tabs currently provide access to functions that demonstrate the technique for Mooodle access:<br/><br/>
    <ul>
      <li>List Users - displays all users registered in Moodle and allows edit/update of the users data.  (Moodle data only)<br/><br/></li>
      <li>List Roles - displays the currently defined roles in Moodle.<br/><br/></li>
      <li>List all Courses - displays all currently defined courses in Moodle<br/><br/></li>
    </ul>
    See also the MyCourses LMS Direct Block and others from the Structure/Blocks menu item.<br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info

$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page Description'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );

return $form;
}

/**
 * Retrieve all of the courses defined in Moodle (callback function)
 *
 * @return
 *   List of all the courses defined in Moodle
 */
function kleosis_courses() {

  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('LMS Direct'), 'kleosis/lms_direct');
  $breadcrumb[] = t('List all Courses');

  // Set Breadcrumbs
  drupal_set_breadcrumb($breadcrumb);

  return show_ctable();

}

/**
 * Display the Moodle courses list
 *
 * @return
 *   The Moodle courses list (HTML)
 */
function show_ctable($table = NULL, $rows_per_page = 20) {
    $header[0] = array(
      'data' => 'Id',
      'field' => '`' . 'id' . '`',
      );
    $header[1] = array(
      'data' => 'Shortname',
      'field' => '`' . 'shortname' . '`',
      );
    $header[2] = array(
      'data' => 'Fullname',
      'field' => '`' . 'fullname' . '`',
      );
    $header[3] = array(
      'data' => 'Summary',
      'field' => '`' . 'summary' . '`',
      );

  $coursesa = ws_get_courses();  // from kleosis_ws.inc

  drupal_set_title(t('Courses in Moodle - demo'));

  $output = '<p>' . t('Requested feature: Click on a column title to sort by that column...') . '</p><br/>';

  // Build the displayable table.
  // $output .= theme('table', $header, $coursesa);
  // $output .= theme('pager', $rows_per_page);

  // For Drupal 7:

  $output .= theme('table', array('header' => $header, 'rows' => $coursesa, 'attributes' => array(), 'caption' => NULL, 'colgroups' => array(), 'sticky' => TRUE));



  return $output;
}

