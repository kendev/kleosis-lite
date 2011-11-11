<?php
// $Id$
/**
 * @file
 * kleosis New Node Code Template
 * Provides a code skeleton for developing modules for new nodes
 *
 * Replace "new_node" with the node name
 * Replace "new_module" with the module name
 * Replace "..field.." with whatever
 *
 *
*/

/**
 * Implements hook_menu().
 *
 */
function new_module_menu() {
  $items = array();

  //Create a menu item on the Kleosis menu
  $items['kleosis/new_module'] = array(
    'title' => 'New Nodes',
    'description' => 'List the New Nodes',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('kleosis_new_module_list_form'),
    'access callback' => TRUE,
    'expanded' => TRUE,
    'weight' => 20,
  );
  $items['kleosis/new_module/default'] = array(
    'type' => MENU_DEFAULT_LOCAL_TASK,
    'title' => 'New Nodes List',
    'weight' => 1,
  );

  $items['kleosis/new_module/create'] = array(
    'title' => 'Add a New Node',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('kleosis_create_new_node_form'),
    'access callback' => TRUE,
    'type' => MENU_LOCAL_TASK,
    'weight' => 2,
  );
  $items['kleosis/new_module/details/%ks_new_node_nid'] = array(
    'description' => 'Display a new node',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('kleosis_new_node_view'),
//    'page callback' => 'kleosis_new_node_view',
//    'page arguments' => array(4),
    'access arguments' => array('access content'),
    'title' => 'New Nodes Details',
    'type' => MENU_LOCAL_TASK,
    'weight' => 3,
  );

  return $items;
}

/**
 * Displays the New Node main page - not currently used
 *
 */
function kleosis_new_module_page($form, &$form_state) {

$page_desc = <<<EOT
    <br/>This is the base page for the kleosis New Node functions.
    A description of the New NOdes functions accessable from above tabs will go here.<br/><br/>
    <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
EOT;

// add a fieldset for the page info
$form['pagehelp'] = array(
    '#type' => 'fieldset',
    '#title' => t('New Node Page Description'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

$form['pagehelp']['pageinfo'] = array(
    '#markup' => $page_desc,
  );

return $form;
}

/**
 * Render a filtered list of New Nodes.
 *
 * Returned form has a filter form and a list of courses
 *
 */
function kleosis_new_module_list_form() {

  $build['filter'] = kleosis_new_module_filter_form();
  $build['#submit'][] = 'kleosis_new_module_filter_form_submit';
  $build['list'] = kleosis_new_module_list();

  return $build;
}
/**
 *
 * New Nodes filters form
 *
 */

function kleosis_new_module_filter_form() {

  // get the filter values from the session variable (if any) and set the default values accordingly
  $new_node_field = isset($_SESSION['new_node_filter']['field']) ? $_SESSION['new_node_filter']['field'] : '';
  $new_node_oper = isset($_SESSION['new_node_filter']['oper']) ? $_SESSION['new_node_filter']['oper'] : '';
  $new_node_operand = isset($_SESSION['new_node_filter']['operand']) ? $_SESSION['new_node_filter']['operand'] : '';

  // create a fieldset with search elements
  $form['searchfield'] = array(
    '#type' => 'fieldset',
    '#title' => t('New Node Search'),
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['searchfield']['field'] = array(
    '#type' => 'select',
    '#title' => t('Where'),
    '#options' =>  ks_fill_search_new_node_fields(),
    '#default_value' => !empty($new_node_field) ? $new_node_field : 'new_node_field_1',
    '#weight' => 1,
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['searchfield']['oper'] = array(
  '#type' => 'select',
    '#title' => t('Operator'),
    '#options' =>  array('is' => t('is'), 'like' => t('like')),
    '#default_value' => !empty($new_node_oper) ? $new_node_oper : 'is',
    '#weight' => 5,
    '#prefix' => '<div style="float: left;width:120px" >',
    '#suffix' => '</div>',
  );
  $form['searchfield']['operand'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter name'),
    '#size' => 30,
    '#maxlength' => 64,
    '#default_value' => !empty($new_node_operand) ? $new_node_operand : '',
    '#weight' => 10,
    '#prefix' => '<div style="float: left;width:100px" >',
    '#suffix' => '</div>',
  );

  $form['searchfield']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Clear'),
    '#weight' => '5',
    '#prefix' => '<div style="float: right;width:100px" >',
    '#suffix' => '</div>',
  );

  $form['searchfield']['search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#weight' => '10',
    '#prefix' => '<div style="float: right;width:100px" >',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Fill the searchfield select box for the New Nodes List form
 *
 * @return
 *    An array of items to select
 */
function ks_fill_search_new_node_fields() {

  $le_array = array(
    'new_node_field_1' => t('Node Field 1'),
    'new_node_field_2' => t('Node Field 2'),
    'new_node_field_3' => t('Node Field 3'),
  );
  return $le_array;
}

/**
 * Fill the Update options select box for the Students List form
 *  - this is sample code for further development, not currently used...
 *
 * @return
 *    An array of items to select
 */
function new_node_fill_updateoptions_items() {

  $op_array = array(
    'operation1' => t('Operation 1'),
    'operation2' => t('Operation 2'),
    'operation3' => t('Operation 3'),
  );
  return $op_array;
}

/**
 * Provides a list of New Nodes in a Table
 *
 */

function kleosis_new_module_list() {

drupal_set_title(t('New Node List'));

  $form = array();

  // get the filter values from the session variable (if any) and set the default values accordingly
  $new_node_field = isset($_SESSION['new_node_filter']['field']) ? $_SESSION['new_node_filter']['field'] : '';
  $new_node_oper = isset($_SESSION['new_node_filter']['oper']) ? $_SESSION['new_node_filter']['oper'] : '';
  $new_node_operand = isset($_SESSION['new_node_filter']['operand']) ? $_SESSION['new_node_filter']['operand'] : '';

  // create another fieldset for multiple update options (tbd...)
/*
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -5,
  );
  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => new_node_fill_updateoptions_items(),
    '#default_value' => '',
  );
  $options = array();
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#submit' => array('kleosis_new_node_list_submit'),
  );
*/
  // the header contains all the fields that will be displayed in the tableselect list
  $header = array(
    'nid' => array('data' => t('Node id'), 'field' => 'nn.nid'),
    'title' => array('data' => t('Title'), 'field' => 'nn.title'),
    'type' => array('data' => t('Node type'), 'field' => 'nn.type'),
    'operations' => array('data' => t('Ops')),
  );

  $query = db_select('node', 'nn');
  $query->addField('nn', 'nid');
  $query->condition('nn.' . 'type', 'new_node', '=');
  $query->condition('nn.' . 'status', 1, '=');

  // adjust the query according to the filter values
  if ( (!empty($new_node_operand)) )  {
    if ($new_node_oper == 'is') {
       $query->condition('nn.' . $new_node_field, $new_node_operand, '=');
    }
    else{
        $query->condition('nn.' . $new_node_field, $new_node_operand . '%', 'like');
    }
  }

  $query = $query->extend('PagerDefault')->limit(variable_get('kleosis_pager_rows', 16));
  $query = $query->extend('TableSort');
  $query->orderByHeader($header);
  $results = $query->execute()->fetchAll();

    /*
      $sql = 'SELECT nid FROM {node} nn WHERE nn.type = :type AND nn.status = :status';
      $results = db_query($sql,
        array(
          ':type' => 'new_node',
          ':status' => 1,
        )
      );
     */
  // Loop through each of the new_node nodes and obtain relevant fields
  $options = array();

  foreach ($results as $row) {
    $node = node_load($row->nid);
    $options[$row->nid] = array(
      'nid' => $node->nid,
      'title' => $node->title,
      'type' => $node->type,
//      'operations' =>  l(t('view'), 'node/' . $row->nid, array('query' => array('destination' => 'kleosis/new_nodes/list')))
      'operations' =>  l(t('view'), 'kleosis/new_module/details/' . $row->nid, array('query' => array('ksop' => 'view', 'destination' => 'kleosis/new_module'))) . ' | ' . l(t('edit'), 'kleosis/new_module/details/' . $row->nid, array('query' => array('ksop' => 'edit', 'destination' => 'kleosis/new_module'))),
      );
  }

  $build = array();

  $build['new_node'] = array(
//        '#type' => 'table',       // used for table
      '#type' => 'tableselect',   // used for tablesect
//        '#theme' => 'table',      // used only for table
      '#header' => $header,
      '#options' => $options,     // used for tablesect
//        '#rows' => $options,      // used for table
      '#empty' => t('No content available.'),
      '#multiple' => TRUE,
      '#js_select' => TRUE,
    );
  $build['pager'] = array('#markup' => theme('pager'));

return $build;

}

/**
 *
 * Implementation of hook_submit() for the New Node filter form.
 *   - main purpose is to store the selected student, operation, and user into session variables
 *
 */
function kleosis_new_node_filter_form_submit($form, &$form_state) {

    if ($form_state['values']['op'] == 'Clear') {
        $_SESSION['new_node_filter'] = array();
    }
    else {
        $_SESSION['new_node_filter'] = array('field' => $form_state['values']['field'],
                                        'oper' => $form_state['values']['oper'],
                                        'operand' => $form_state['values']['operand'], );
    }
}

/************************************************************************************************/

/**
 * Display or edit a new_node node
 *
 * @return
 *   Form for the rendered new_node info or link to create the new_node node
 */

function kleosis_new_node_view($callback_arg = '') {

  module_load_include('inc', 'node', 'node.pages');  // needed for the node_add() function

  global $user;
  global $base_root;
  $build = array();
//  dpm($callback_arg);
//  dpm('Here are args 0, 1, 2, 3, 4');
//  dpm(arg(0)); dpm(arg(1)); dpm(arg(2)); dpm(arg(3)); dpm(arg(4));

    drupal_set_title(t('New Node Info'));
    $nid = arg(3);
    if ($nid && ($nid <> 1)) {  // if nid id is passed, then look up the new_node node and display it
      $node = node_load($nid);
      if(  !empty($node)  ) {
        $ksop = isset($_GET['ksop']) ? $_GET['ksop'] : '';
        if ($ksop == 'edit') {
          $build['node_edit'] = node_page_edit($node);
        }
        else {
          $build['node_display'] = node_view($node);
        }
      }
      else {
        $build['node_not_exists'] = array(
        '#type' => 'markup',
        '#markup' => '<p><br/>' . t('This new_node does not exist or cannot be found - please select another.') . '</p>',
        );
      }
    }
    else {  // node argument does not exist, or is = 1, try again
      $build['no_node_argument'] = array(
     '#type' => 'markup',
     '#markup' => '<p><br/>' . t('Please select a New Node from the New Node List page by clicking on a view or edit link.') . '</p>',
      );
    }
  return $build;
}

/**
 * Create a new_node node
 *
 * @return
 *   Node Add form for a new_node
 */

function kleosis_create_new_node_form($form, $form_state) {

  global $user;
  global $base_root;
  drupal_set_title(t('Create a new_node'));
  $build = array();

  if (  (in_array('administrator', $user->roles))  || (user_access('administer nodes'))  ){
//    $build['the_new_node'] = node_add('new_node');  // this throws a form expired error, so:

        $path = 'node/add/' . 'new_node';   // another technique: redirect to let Drupal launch the node add form
        $options = array('query' => array('destination' => 'kleosis/new_module') );
        drupal_goto($path, $options, $http_response_code = 302);
  }
  else {
    $build['view_return'] = array(
     '#type' => 'markup',
   //  '#markup' => '<p><br/>' . t('<a href="!url">Return to New Node List</a>', array('!url' => $base_root . url('kleosis/new_module')) ) . '</p>',);
     '#markup' => '<p><br/>' . t('You do not have permission to create new_nodes.') . '</p>',
      );
  }
  return $build;
}

/**
 * Implements hook_form_alter().
 *
 * Set the node reference fields and pre-load the title
 *
 */
function new_module_form_alter(&$form, &$form_state, $form_id) {

//dpm('inside new_module_form_alter()');

/*
  if( ($form_id == 'new_module_node_form') && (!empty($form['#node_edit_form'])) ) {

//dpm($form);

    $elem1 = (isset($form['another_nodes_node_ref'][LANGUAGE_NONE][0])) ? $form['another_nodes_node_ref'][LANGUAGE_NONE][0] : null;
    $elem2 = (isset($form['title']['#default_value'])) ? $form['title']['#default_value'] : null;

    if(arg(3)) { //arg(3) is the uid in the url.

      $title = t('@first_part @name', array('@first_part' => t('New Nodes info for'), '@name' => ks_new_node_get_users_name(arg(3))));
      $form['title']['#default_value'] = ($elem2) ? $elem2 : $title;
      $elem1['uid']['#default_value'] = arg(3);
      $form['another_nodes_node_ref'][LANGUAGE_NONE][0] = $elem1;
      }
    else {

      $title = t('New Nodes info for');
      $form['title']['#default_value'] = ($elem2) ? $elem2 : $title;
    }
  }
 */
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
function ks_new_node_get_users_name($uid){

  $name = db_query('SELECT name FROM {users} WHERE uid = :uid',
                   array(':uid' => $uid))->fetchField();
  return $name;
}

/**
 *
 *  Provide a non-null parameter replacement for this menu item:
 *    $items['kleosis/new_nodes/details/%new_node_id'']
 *
 * @param $uarg
 *   The new_node id from the url (can be null)
 *
 *  return non-null nid
 */
function ks_new_node_nid_to_arg($uarg){

  $arg3 = arg(3);
  $nid = !empty($uarg) ? $uarg : !empty($arg3) ? $arg3 : 1;

//  if($nid == 1) {  // recursion city...
//    drupal_set_message('Please select a new_node view or edit link from the Nwe Node List tab.');
//    drupal_goto('kleosis/new_module', array());
//  }

//  $nid = isset($_SESSION['new_node']['nid']) ? $_SESSION['new_node']['nid'] : $someid;

  return $nid;
}

/**
 *
 * Implements hook_node_insert().
 *
 */
function new_module_node_insert($node) {

//  used primarily when this new_node module uses a custom table
//  dpm('inside new_module_node_insert() - not currently implemented - ' . $node->title);
}

/**
 *
 * Implements hook_node_load().
 *
 */
function new_module_node_load($nodes, $types) {

//  used primarily when this new_node module uses a custom table
//  foreach ($nodes as $node) {
//    dpm($node);
//    dpm('inside new_module_node_load() - not currently implemented - ' . $node->title);
//  }
}

/**
 *
 * Implements hook_node_update().
 *
 */
function new_module_node_update($node) {

//  used primarily when this new_node module uses a custom table
//  dpm('inside new_module_node_update() - not currently implemented - ' . $node->title);
//  dpm($node);
}

/**
 *
 * Implements hook_node_delete().
 *
 */
function new_module_node_delete($node) {

//  used primarily when this new_node module uses a custom table
//  dpm('inside new_module_node_delete() - not currently implemented');
}

/**
 *
 * Implements simple_new_module_node_view().
 *
 */
function new_module_node_view($node, $view_mode, $langcode) {

//  used primarily when this new_module module uses a custom table (in addition to new_module_form_alter)
//dpm('inside new_module_node_view() - not currently implemented - ' . $node->title);
//dpm($node);
//dpm($view_mode);
}

/**
 * Implements hook_help().
 */
function new_module_help($path, $arg) {
  switch ($path) {
    case 'admin/help#new_module':
      return "<p>" . t(
        "The New Nodes module provides a custom node type for new_nodes info about a student.
        You can create new nodes using the <a href='!nodeadd'>node add form</a>.
        Nodes that you create will be displayed here.",
        array('!nodeadd' => url('node/add/new_node'))
      ) . "</p>";
  }
}


/******************************************************************

 *    Example functions to load list_text type fields (for the Courses module)

/******************************************************************/
/**
 * The allowed values for the lab_type courses field
 *
 * @return
 *    An array of lab_types to select
 */
/*
function kleosis_lab_types_values() {  // todo: these values may be defined in the list (text) field directly

  $le_array = array(
    'standard' => t('Standard'),
    'large' => t('Large'),
    'auditorium' =>t('Auditorium'),
    'lab' => t('Lab'),
    'protected_lab' => t('Protected lab'),
    'temporary' => t('Temporary'),
  );
  return $le_array;
}
*/
/**
 * The allowed values for the program field
 *
 * @return
 *    An array of programs to select
 */
 /*
function kleosis_program_values() {  // todo: these values may be defined in the list (text) field directly

  $le_array = array(
    'english' => t('English'),
    'advanced' => t('Advanced'),
    'language' =>t('Language'),
    'special_needs' => t('Special Needs'),
    'general_academic' => t('General Academic'),
  );
  return $le_array;
}
*/
/**
 * The allowed values for the department field
 *
 * @return
 *    An array of departments to select
 */
 /*
function kleosis_department_values() {  // todo: these values may be defined in the list (text) field directly

  $le_array = array(
    'general' => t('General'),
    'science' => t('Science'),
    'languages' => t('Languages'),
    'art' =>t('Art'),
    'music' => t('Music'),
    'biology' => t('Biology'),
    'mathmetics' => t('Mathematics'),
  );
  return $le_array;
}
*/

/**
 * The allowed values for the gradelevel
 *
 * @return
 *    An array of gradelevels to select
 */
 /*
function kleosis_gradelevel_values() {  // todo: read the ks_gradelevel_desc table for these values

  $le_array = array(
    'k1' => t('K1'),
    'k2' => t('K2'),
    'k3' => t('K3'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
    '13' => t('13'),
  );
  return $le_array;
}
*/
/************************************************************************************************/
/**
 *
 * Retrieve the Courses node id for a student - currently not used...
 *
 * @param $uid
 *   The user id
 *
 *  return courses node id or FALSE if no id
 */
  /* function courses_get_node_id($uid){

  //  $nid = db_query('SELECT revision_id FROM {field_revision_courses_user_ref} WHERE courses_user_ref_uid = :uid',
  //                   array(':uid' => $uid))->fetchField();
  //  return $nid;
  //  return NULL;
  }
  */
/************************************************************************************************/

