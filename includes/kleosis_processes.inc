<?php
// $Id$
/**
* @file
* kleosis Processes functions
*/

require_once ('kleosis_ws.inc');  // webservices wrapper functions

//$kwspath = drupal_get_path('module', 'kleosis');
//$kwspath .= '/kws/MoodleWS.php';
//require_once ($kwspath);

/**
 * Display a list of Processes in kleosis (callback function)
 *
 * @return
 *   List of Processes in kleosis
 */
function kleosis_processes() {

  return show_ptable();

}

/**
 * Display the kleosis Processes list
 *
 * @return
 *   The kleosis Processes list (HTML)
 */
function show_ptable($table = NULL, $rows_per_page = 20) {

$page_desc = <<<EOT
    <br/>This is the base page for the Kleosis Process functions. Functions such as those involved in the beginning-of-term and end-of-term tasks will be placed and organized here. <br/><br/>

    The example functions in above tabs are the following:<br/>
    <ul>
      <li>Test - Sync Users -> code skeleton for manually synchronizing users<br/><br/></li>
      <li>Test - Test - Users List -> shows content from internal tables and from moodle<br/><br/></li>
      <li>Test - Dev Code -> for quick function development and testing by programmers<br/><br/></li>
      <li>Sample Data -> loads sample data into Kleosis<br/><br/></li>
      <li>Force Logout -> compensated for a bug in an earlier version of Drupal 7<br/><br/></li>
      <li>more to come...<br/><br/></li>
    </ul>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

  $base_content = $page_desc;

  $output = '<p>' . $base_content . '</p>';

  return $output;
}

/**
 * Render a filtered list of entries in the database.
 *
 * DBTNG also helps processing queries that return several rows, providing the
 * found objects in the same query execution call.
 *
 * This function queries the database using a JOIN between users table and the
 * example entries, to provide the username that created the entry, and creates
 * a table with the results, processing each row.
 *
 * SELECT
 *  e.pid as pid, e.name as name, e.surname as surname, e.age as age
 *  u.name as username
 * FROM
 *  {dbtng_example} e
 * JOIN
 *  users u ON e.uid = u.uid
 * WHERE
 *  e.name = 'John' AND e.age > 18
 *
 * @see db_select()
 * @seeW http://drupal.org/node/310075
 */
function kleosis_processes_usersync() {

  drupal_set_title(t('Test - Users Lists'));

  $output = '';
  $select = db_select('ks_users', 'ksu');
  // Join the users table, so we can get the username from there.
  $select->join('users', 'u', 'ksu.drp_uid_fk = u.uid');
  // Select these specific fields for the output.
  $select->addField('ksu', 'mdl_uid_fk');
  $select->addField('u', 'name', 'username');
  $select->addField('ksu', 'fullname');
  $select->addField('ksu', 'friendlyname');
  $select->addField('ksu', 'address_city');
  // Filter only persons older than 0 years.
  $select->condition('ksu.fullname', 'Redondo', '<>');
  // Make sure we only get items 0-999, for scalability reasons.
  $select->range(0, 1000);

/*******************************************************************************/

/*******************************************************************************/

  // Now, loop all these entries and show them in a table. Note that there is no
  // db_fetch_* object or array function being called here. Also note that the
  // following line could have been written as
  // $entries = $select->execute()->fetchAll() which would return each selected
  // record as an object instead of an array.
  $entries = $select->execute()->fetchAll(PDO::FETCH_ASSOC);

  if (!empty($entries)) {
    $rows = array();
    foreach ($entries as $entry) {
      // Sanitize the data before handing it off to the theme layer.
      $rows[] = array_map('check_plain', $entry);
    }
    // Make a table for them.
    $header = array(t('Moodle User ID'), t('Username'), t('Fullname'), t('Friendlyname'), t('City'));

    $output .= t("This test function is currently still here as demo code and simple shows three tables of data, two from local Drupal and the third directly from the Moodle database. <br/><br/>
    The following table displays the contents of Kleosis users extension table (joined with the Web Portal (Drupal) users table):");
    $output .= theme('table', array('header' => $header, 'rows' => $rows));

  }
  else {
    drupal_set_message(t('No entries meet the filter criteria (Age > 0).'));
  }

  $output .= t("<br/>The following table displays the contents of the Web Portal (Drupal) users table:");

      $select = db_select('users', 'u');
      // Select these specific fields for the output.
      $select->addField('u', 'uid');
      $select->addField('u', 'name', 'username');
      $select->addField('u', 'mail');
      $select->addField('u', 'status');
      $select->range(0, 1000);

  $entries = $select->execute()->fetchAll(PDO::FETCH_ASSOC);

  if (!empty($entries)) {
    $rows = array();
    foreach ($entries as $entry) {
      // Sanitize the data before handing it off to the theme layer.
      $rows[] = array_map('check_plain', $entry);
    }
    // Make a table for them.
    $header = array(t('Web Portal User ID'), t('Username'), t('e-mail'), t('status'));
    $output .= theme('table', array('header' => $header, 'rows' => $rows));

//    $output .= t("<br/><br/>...Table goes here...");
  }
  else {
    drupal_set_message(t('No entries in the Web Portal users table?'));
  }

  $output .= t("<br/>The following table displays the contents of the Moodle users table (see LMS Direct, List Users for an example
  of how to edit the Moodle user data directly:");

  $therows = array();
  $therows = ws_get_users();
//  dpm($therows);

  if (!empty($therows)) {
    $rows = array();
    foreach ($therows as $therow) {
      // Sanitize the data before handing it off to the theme layer.
      $rows[] = array_map('check_plain', $therow);
    }
    // Make a table for them.
    $header = array(t('Moodle User ID'), t('Username'), t('Firstname'), t('Lastname'));
    $output .= theme('table', array('header' => $header, 'rows' => $rows));

  }
  else {
    drupal_set_message(t('No entries in the Web Portal users table?'));
  }


// ToDo: Maybe create another tab to actually perform the syncronization - be sure to backup before testing...

  return $output;
}

