<?php

/**
 * @file
 *  Kleosis Term Reports
 *
 *  This is an early draft of a generic report module for Kleosis
 */

 module_load_include('pages.inc', 'node', 'node');

/**
 * Display or create the term report for a student
 *
 * @return
 *   Form for the rendered term report or link to create the report
 */
function kleosis_term_report_view($callback_arg = '') {

  // check permissions
  global $user;

  if ( !(in_array('administrator', $user->roles))  && !(user_access('view kleosis student info')) ) {
    drupal_set_message(t("You currently do not have permissions to view Kleosis student term_reports."));
    $options = array('query' => array('destination' => 'kleosis/reports_and_queries') );
    drupal_goto($_SERVER['HTTP_REFERER'], $options, $http_response_code = 302); // return to calling url
  }

  module_load_include('inc', 'node', 'node.pages');  // needed for the node_add() function

  global $user;
  global $base_root;
  $build = array();
//  dpm($callback_arg);
//  dpm('Here are args 0, 1, 2, 3, 4');
//  dpm(arg(0)); dpm(arg(1)); dpm(arg(2)); dpm(arg(3)); dpm(arg(4));

  // Set Breadcrumbs
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), 'kleosis');
  $breadcrumb[] = l(t('Reports and Queries'), 'kleosis/reports_and_queries');
  $breadcrumb[] = t('Reports');

  drupal_set_breadcrumb($breadcrumb);

  if (arg(4)) {  // if user id is passed, then look up the term report node and display it

  drupal_set_title(t('Term Report View'));
  $nid = term_report_get_node_id(arg(4));
  if ($nid) {
    $node = node_load($nid);

    $build['node_display'] = node_view($node);

    return $build;
     /* if ($nid) {  // another technique: redirect to let Drupal launch the node edit form
        $path = 'node/add/'' . $nid;
        $options = array('query' => array('destination' => 'kleosis/reports_and_queries') );
        drupal_goto($path, $options, $http_response_code = 302);
        }
      */
  }

  else {  // node does not exist, can create it (todo: clean this up...)

    // if administrator, ask to create node or return to kleosis/reports_and_queries
    // if not admin, just return with simple message
    if (in_array('administrator', $user->roles))  {

      $usersname = term_report_get_users_name(arg(4));  // get users name from the uid
      if (!empty($usersname)) {

        $usernames = ks_get_usernames_for_display(arg(4)); // get the display names for this user
        $title = t('@first_part @name', array('@first_part' => t('Click here to add a term report for user:'), '@name' => $usernames));

        $build['the_link']['addit'] = array(
          '#type' => 'link',
          '#title' => $title,
          '#href' => $base_root . url('node/add/term-report/' . arg(4), array('query' => array('destination' => 'kleosis/reports_and_queries'))),
          '#prefix' => '<br/><div style="float:left;width:550px"><strong>Term report does not exist for this user</strong><br/><br/>',
          '#suffix' => '</div><br/>',
        );
        return $build;
        return array();

       }
      else {
        // maybe write code to do this:

        //  if no student, then
        //     show link to create new node and,
        //     show autocomplete textbox to select one, then display it
        //  in the meantime:

        $build['student_id_not_found'] = array(
          '#type' => 'markup',
          '#markup' => '<p>' . t('Student id not found. New term report for a student is currently created starting from kleosis/reports_and_queries.') . '<br/> ' . t('From there select a student...') . '</p>');

          return $build;
        }
      }  // end if (in_array('administrator', $user->roles))
    }  // end node does not exist
  }  // end if arg(4)

}

/**
 *
 * Retrieve the Term Report node id for a student
 *
 * @param $uid
 *   The user id
 *
 *  return Term Report node id or FALSE if no id
 */
function term_report_get_node_id($uid) {

  $nid = db_query('SELECT revision_id FROM {field_revision_field_tr_student} WHERE field_tr_student_uid = :uid',
                   array(':uid' => $uid))->fetchField();
  return $nid;
}

/**
 *
 * Retrieve the name for a user by user id
 *
 * @param $uid
 *   The user id from arg(1)
 *
 *  return user's name
 */
function term_report_get_users_name($uid) {

  $name = db_query('SELECT name FROM {users} WHERE uid = :uid',
                   array(':uid' => $uid))->fetchField();
  return $name;
}

/**
 * Custom callback that builds a list of term reports - not currently used
 *
 * @return
 *   a build array
 *
 */
function kleosis_term_report_list() {
  $build = array();
  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.status = :status';
  $result = db_query($sql,
    array(
      ':type' => 'term_report',
      ':status' => 1,
    )
  );
  // Loop through each of the term_report nodes and instruct node_view
  // to use the default view.
  foreach ($result as $row) {
    $node = node_load($row->nid);
    $build['node_list'][]= node_view($node);
  }
  return $build;
}


/**
 *
 * Implements hook_node_delete().
 *
 */
function term_report_node_delete($node) {

  if ($node->type == '') {
    //$gone = ks_delete_med_subject_record($node->nid);
  }
}
/**
 *
 * Implements term_report_node_view().
 *

function term_report_node_view($node, $view_mode, $langcode) {

//  used primarily when this term_report node uses a custom table (in addition to term_report_form_alter)

  if ($node->type == 'ter_report') {

    $tr_nid = $node->nid;

    require_once('forms/kleosis_some_term_report_view_form.inc');

    return $node;

    }
}
 */
/**
 * Implements hook_help().

function term_report_help($path, $arg) {
  switch ($path) {
    case 'admin/help#term_report':
      return "<p>" . t(
        "The Term_Report module provides a custom node type for a term report.
        You can create new nodes using the <a href='!nodeadd'>node add form</a>.
        Nodes that you create will be displayed here.",
        array('!nodeadd' => url('node/add/term_report'))
      ) . "</p>";
  }
}
 */


