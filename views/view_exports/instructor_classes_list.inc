<?php

/**
 * @file
 *  An exported Views report that lists instructor classes
 */

$view = new view;
$view->name = 'instructor_classes';
$view->description = 'List of classes assigned to an instructor';
$view->tag = 'default';
$view->base_table = 'ks_class_schedule';
$view->human_name = 'Instructor classes';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Instructor Classes';
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '30';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'kclss_id' => 'kclss_id',
  'kccls_id_fk' => 'kccls_id_fk',
  'period_lead' => 'period_lead',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'kclss_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'kccls_id_fk' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'period_lead' => array(
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
/* Relationship: Kleosis: ks_cls_sched class */
$handler->display->display_options['relationships']['kccls_id_fk']['id'] = 'kccls_id_fk';
$handler->display->display_options['relationships']['kccls_id_fk']['table'] = 'ks_class_schedule';
$handler->display->display_options['relationships']['kccls_id_fk']['field'] = 'kccls_id_fk';
$handler->display->display_options['relationships']['kccls_id_fk']['label'] = 'Kleosis Classname';
$handler->display->display_options['relationships']['kccls_id_fk']['required'] = 1;
/* Relationship: Kleosis: ks_cls_sched classroom */
$handler->display->display_options['relationships']['classroom']['id'] = 'classroom';
$handler->display->display_options['relationships']['classroom']['table'] = 'ks_class_schedule';
$handler->display->display_options['relationships']['classroom']['field'] = 'classroom';
$handler->display->display_options['relationships']['classroom']['required'] = 1;
/* Relationship: Kleosis: ks_cls_sched period status */
$handler->display->display_options['relationships']['period_status']['id'] = 'period_status';
$handler->display->display_options['relationships']['period_status']['table'] = 'ks_class_schedule';
$handler->display->display_options['relationships']['period_status']['field'] = 'period_status';
$handler->display->display_options['relationships']['period_status']['required'] = 1;
/* Relationship: Kleosis: ks_cls_sched: Link to Instructor */
$handler->display->display_options['relationships']['period_lead']['id'] = 'period_lead';
$handler->display->display_options['relationships']['period_lead']['table'] = 'ks_class_schedule';
$handler->display->display_options['relationships']['period_lead']['field'] = 'period_lead';
$handler->display->display_options['relationships']['period_lead']['required'] = 1;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'period_lead';
$handler->display->display_options['fields']['name']['label'] = 'Instructor';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['external'] = 0;
$handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['element_label_colon'] = 1;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
$handler->display->display_options['fields']['name']['format_username'] = 1;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'kccls_id_fk';
$handler->display->display_options['fields']['title']['label'] = 'Class';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['title']['alter']['external'] = 0;
$handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['title']['alter']['trim'] = 0;
$handler->display->display_options['fields']['title']['alter']['html'] = 0;
$handler->display->display_options['fields']['title']['element_label_colon'] = 1;
$handler->display->display_options['fields']['title']['element_default_classes'] = 1;
$handler->display->display_options['fields']['title']['hide_empty'] = 0;
$handler->display->display_options['fields']['title']['empty_zero'] = 0;
$handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['title']['link_to_node'] = 1;
/* Field: Kleosis: ks_cls_sched period day */
$handler->display->display_options['fields']['period_day']['id'] = 'period_day';
$handler->display->display_options['fields']['period_day']['table'] = 'ks_class_schedule';
$handler->display->display_options['fields']['period_day']['field'] = 'period_day';
$handler->display->display_options['fields']['period_day']['label'] = 'Day';
$handler->display->display_options['fields']['period_day']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['external'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['period_day']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['period_day']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['trim'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['html'] = 0;
$handler->display->display_options['fields']['period_day']['element_label_colon'] = 1;
$handler->display->display_options['fields']['period_day']['element_default_classes'] = 1;
$handler->display->display_options['fields']['period_day']['hide_empty'] = 0;
$handler->display->display_options['fields']['period_day']['empty_zero'] = 0;
$handler->display->display_options['fields']['period_day']['hide_alter_empty'] = 1;
/* Field: Kleosis: ks_cls_sched start datetime */
$handler->display->display_options['fields']['period_start_datetime']['id'] = 'period_start_datetime';
$handler->display->display_options['fields']['period_start_datetime']['table'] = 'ks_class_schedule';
$handler->display->display_options['fields']['period_start_datetime']['field'] = 'period_start_datetime';
$handler->display->display_options['fields']['period_start_datetime']['label'] = 'Period start';
$handler->display->display_options['fields']['period_start_datetime']['alter']['alter_text'] = 1;
$handler->display->display_options['fields']['period_start_datetime']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['alter']['external'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['alter']['nl2br'] = 1;
$handler->display->display_options['fields']['period_start_datetime']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['period_start_datetime']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['period_start_datetime']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['alter']['trim'] = 1;
$handler->display->display_options['fields']['period_start_datetime']['alter']['html'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['element_label_colon'] = 1;
$handler->display->display_options['fields']['period_start_datetime']['element_default_classes'] = 1;
$handler->display->display_options['fields']['period_start_datetime']['hide_empty'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['empty_zero'] = 0;
$handler->display->display_options['fields']['period_start_datetime']['hide_alter_empty'] = 1;
/* Field: Kleosis: kclsrmdesc classroom */
$handler->display->display_options['fields']['room_name']['id'] = 'room_name';
$handler->display->display_options['fields']['room_name']['table'] = 'ks_classroom_desc';
$handler->display->display_options['fields']['room_name']['field'] = 'room_name';
$handler->display->display_options['fields']['room_name']['relationship'] = 'classroom';
$handler->display->display_options['fields']['room_name']['label'] = 'Classroom';
$handler->display->display_options['fields']['room_name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['external'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['room_name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['room_name']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['room_name']['alter']['html'] = 0;
$handler->display->display_options['fields']['room_name']['element_label_colon'] = 1;
$handler->display->display_options['fields']['room_name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['room_name']['hide_empty'] = 0;
$handler->display->display_options['fields']['room_name']['empty_zero'] = 0;
$handler->display->display_options['fields']['room_name']['hide_alter_empty'] = 1;
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['relationship'] = 'period_lead';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['group'] = 1;
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'Instructor';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
$handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
/* Filter criterion: Kleosis: ks_cls_sched start datetime */
$handler->display->display_options['filters']['period_start_datetime']['id'] = 'period_start_datetime';
$handler->display->display_options['filters']['period_start_datetime']['table'] = 'ks_class_schedule';
$handler->display->display_options['filters']['period_start_datetime']['field'] = 'period_start_datetime';
$handler->display->display_options['filters']['period_start_datetime']['operator'] = 'between';
$handler->display->display_options['filters']['period_start_datetime']['group'] = 1;
$handler->display->display_options['filters']['period_start_datetime']['exposed'] = TRUE;
$handler->display->display_options['filters']['period_start_datetime']['expose']['operator_id'] = 'period_start_datetime_op';
$handler->display->display_options['filters']['period_start_datetime']['expose']['label'] = 'Class start date between (YYYY-MM-DD)';
$handler->display->display_options['filters']['period_start_datetime']['expose']['operator'] = 'period_start_datetime_op';
$handler->display->display_options['filters']['period_start_datetime']['expose']['identifier'] = 'period_start_datetime';
$handler->display->display_options['filters']['period_start_datetime']['expose']['remember'] = 1;
$handler->display->display_options['filters']['period_start_datetime']['expose']['multiple'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'instructor-classes';
