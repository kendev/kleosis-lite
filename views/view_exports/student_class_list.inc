<?php

/**
 * @file
 *  An exported Views report that lists students classes
 */

$view = new view;
$view->name = 'students_class_list';
$view->description = 'List of classes each student is currently enrolled in';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'Student class list';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Student Class List';
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access user profiles';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '42';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'name',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'title' => 'title',
  'ib_level' => 'ib_level',
  'completed' => 'completed',
  'final_grade' => 'final_grade',
  'enrol_date' => 'enrol_date',
  'remarks' => 'remarks',
);
$handler->display->display_options['style_options']['default'] = 'name';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'ib_level' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'completed' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'final_grade' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'enrol_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'remarks' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['empty_table'] = 0;
/* Relationship: Kleosis: ksccl class */
$handler->display->display_options['relationships']['kccls_id_fk']['id'] = 'kccls_id_fk';
$handler->display->display_options['relationships']['kccls_id_fk']['table'] = 'ks_student_course_classes';
$handler->display->display_options['relationships']['kccls_id_fk']['field'] = 'kccls_id_fk';
$handler->display->display_options['relationships']['kccls_id_fk']['required'] = 0;
/* Relationship: Kleosis: ksccl ib_level */
$handler->display->display_options['relationships']['ib_level']['id'] = 'ib_level';
$handler->display->display_options['relationships']['ib_level']['table'] = 'ks_student_course_classes';
$handler->display->display_options['relationships']['ib_level']['field'] = 'ib_level';
$handler->display->display_options['relationships']['ib_level']['required'] = 0;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Student Name';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['external'] = 0;
$handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['element_label_colon'] = 1;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'kccls_id_fk';
$handler->display->display_options['fields']['title']['label'] = 'Class Name';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['title']['alter']['external'] = 0;
$handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['title']['alter']['trim'] = 0;
$handler->display->display_options['fields']['title']['alter']['html'] = 0;
$handler->display->display_options['fields']['title']['element_label_colon'] = 1;
$handler->display->display_options['fields']['title']['element_default_classes'] = 1;
$handler->display->display_options['fields']['title']['hide_empty'] = 0;
$handler->display->display_options['fields']['title']['empty_zero'] = 0;
$handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['title']['link_to_node'] = 1;
/* Field: Kleosis: kiblvldesc ib_level */
$handler->display->display_options['fields']['ib_level']['id'] = 'ib_level';
$handler->display->display_options['fields']['ib_level']['table'] = 'ks_ib_level_desc';
$handler->display->display_options['fields']['ib_level']['field'] = 'ib_level';
$handler->display->display_options['fields']['ib_level']['relationship'] = 'ib_level';
$handler->display->display_options['fields']['ib_level']['label'] = 'IB Level';
$handler->display->display_options['fields']['ib_level']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['external'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['ib_level']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['ib_level']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['trim'] = 0;
$handler->display->display_options['fields']['ib_level']['alter']['html'] = 0;
$handler->display->display_options['fields']['ib_level']['element_label_colon'] = 1;
$handler->display->display_options['fields']['ib_level']['element_default_classes'] = 1;
$handler->display->display_options['fields']['ib_level']['hide_empty'] = 0;
$handler->display->display_options['fields']['ib_level']['empty_zero'] = 0;
$handler->display->display_options['fields']['ib_level']['hide_alter_empty'] = 1;
/* Field: Kleosis: ksccl completed */
$handler->display->display_options['fields']['completed']['id'] = 'completed';
$handler->display->display_options['fields']['completed']['table'] = 'ks_student_course_classes';
$handler->display->display_options['fields']['completed']['field'] = 'completed';
$handler->display->display_options['fields']['completed']['label'] = 'Completed';
$handler->display->display_options['fields']['completed']['exclude'] = TRUE;
$handler->display->display_options['fields']['completed']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['completed']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['completed']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['completed']['alter']['external'] = 0;
$handler->display->display_options['fields']['completed']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['completed']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['completed']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['completed']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['completed']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['completed']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['completed']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['completed']['alter']['trim'] = 0;
$handler->display->display_options['fields']['completed']['alter']['html'] = 0;
$handler->display->display_options['fields']['completed']['element_label_colon'] = 1;
$handler->display->display_options['fields']['completed']['element_default_classes'] = 1;
$handler->display->display_options['fields']['completed']['hide_empty'] = 0;
$handler->display->display_options['fields']['completed']['empty_zero'] = 0;
$handler->display->display_options['fields']['completed']['hide_alter_empty'] = 0;
/* Field: Kleosis: ksccl final grade */
$handler->display->display_options['fields']['final_grade']['id'] = 'final_grade';
$handler->display->display_options['fields']['final_grade']['table'] = 'ks_student_course_classes';
$handler->display->display_options['fields']['final_grade']['field'] = 'final_grade';
$handler->display->display_options['fields']['final_grade']['label'] = 'Final grade';
$handler->display->display_options['fields']['final_grade']['exclude'] = TRUE;
$handler->display->display_options['fields']['final_grade']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['external'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['final_grade']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['final_grade']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['trim'] = 0;
$handler->display->display_options['fields']['final_grade']['alter']['html'] = 0;
$handler->display->display_options['fields']['final_grade']['element_label_colon'] = 1;
$handler->display->display_options['fields']['final_grade']['element_default_classes'] = 1;
$handler->display->display_options['fields']['final_grade']['hide_empty'] = 0;
$handler->display->display_options['fields']['final_grade']['empty_zero'] = 0;
$handler->display->display_options['fields']['final_grade']['hide_alter_empty'] = 0;
/* Field: Kleosis: ksccl enrol date */
$handler->display->display_options['fields']['enrol_date']['id'] = 'enrol_date';
$handler->display->display_options['fields']['enrol_date']['table'] = 'ks_student_course_classes';
$handler->display->display_options['fields']['enrol_date']['field'] = 'enrol_date';
$handler->display->display_options['fields']['enrol_date']['label'] = 'Enrol date';
$handler->display->display_options['fields']['enrol_date']['alter']['alter_text'] = 1;
$handler->display->display_options['fields']['enrol_date']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['external'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['max_length'] = '10';
$handler->display->display_options['fields']['enrol_date']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['ellipsis'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['enrol_date']['alter']['trim'] = 1;
$handler->display->display_options['fields']['enrol_date']['alter']['html'] = 0;
$handler->display->display_options['fields']['enrol_date']['element_label_colon'] = 1;
$handler->display->display_options['fields']['enrol_date']['element_default_classes'] = 1;
$handler->display->display_options['fields']['enrol_date']['hide_empty'] = 0;
$handler->display->display_options['fields']['enrol_date']['empty_zero'] = 0;
$handler->display->display_options['fields']['enrol_date']['hide_alter_empty'] = 0;
/* Field: Kleosis: ksccl remarks */
$handler->display->display_options['fields']['remarks']['id'] = 'remarks';
$handler->display->display_options['fields']['remarks']['table'] = 'ks_student_course_classes';
$handler->display->display_options['fields']['remarks']['field'] = 'remarks';
$handler->display->display_options['fields']['remarks']['label'] = 'Remarks';
$handler->display->display_options['fields']['remarks']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['external'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['remarks']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['remarks']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['trim'] = 0;
$handler->display->display_options['fields']['remarks']['alter']['html'] = 0;
$handler->display->display_options['fields']['remarks']['element_label_colon'] = 1;
$handler->display->display_options['fields']['remarks']['element_default_classes'] = 1;
$handler->display->display_options['fields']['remarks']['hide_empty'] = 0;
$handler->display->display_options['fields']['remarks']['empty_zero'] = 0;
$handler->display->display_options['fields']['remarks']['hide_alter_empty'] = 0;
/* Sort criterion: User: Name */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'users';
$handler->display->display_options['sorts']['name']['field'] = 'name';
$handler->display->display_options['sorts']['name']['expose']['label'] = 'Student Name';
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['sorts']['title']['relationship'] = 'kccls_id_fk';
$handler->display->display_options['sorts']['title']['expose']['label'] = 'Course Name';
/* Sort criterion: Kleosis: ksccl enrol date */
$handler->display->display_options['sorts']['enrol_date']['id'] = 'enrol_date';
$handler->display->display_options['sorts']['enrol_date']['table'] = 'ks_student_course_classes';
$handler->display->display_options['sorts']['enrol_date']['field'] = 'enrol_date';
$handler->display->display_options['sorts']['enrol_date']['expose']['label'] = 'Enrol date';
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: User: Roles */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['value'] = array(
  4 => '4',
);
$handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'Student';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
$handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'students-class-list';
$handler->display->display_options['menu']['title'] = 'Report - Students Class List';
$handler->display->display_options['menu']['description'] = 'List students in a class';
$handler->display->display_options['menu']['weight'] = '25';
$handler->display->display_options['menu']['name'] = 'kleosismm';
