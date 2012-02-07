<?php

/**
 * @file
 * An exported Views daily attendance report
 */

$view = new view;
$view->name = 'daily_attendance_list';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'ks_student_attendance';
$view->human_name = 'Daily attendance list';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Daily attendance list';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'atnd_date' => 'atnd_date',
  'absence_type' => 'absence_type',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'atnd_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'absence_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['empty_table'] = 1;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'No Attendance Results';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = 'No absences recorded for the specified date.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
$handler->display->display_options['empty']['area']['tokenize'] = 0;
/* Relationship: Kleosis: ks_std_atnd: Link to Student */
$handler->display->display_options['relationships']['kstu_id_fk']['id'] = 'kstu_id_fk';
$handler->display->display_options['relationships']['kstu_id_fk']['table'] = 'ks_student_attendance';
$handler->display->display_options['relationships']['kstu_id_fk']['field'] = 'kstu_id_fk';
$handler->display->display_options['relationships']['kstu_id_fk']['required'] = 0;
/* Relationship: Kleosis: ksatnd absent type */
$handler->display->display_options['relationships']['abs_type']['id'] = 'abs_type';
$handler->display->display_options['relationships']['abs_type']['table'] = 'ks_student_attendance';
$handler->display->display_options['relationships']['abs_type']['field'] = 'abs_type';
$handler->display->display_options['relationships']['abs_type']['required'] = 0;
/* Relationship: Kleosis: ksatnd excuse reason */
$handler->display->display_options['relationships']['excuse_reason']['id'] = 'excuse_reason';
$handler->display->display_options['relationships']['excuse_reason']['table'] = 'ks_student_attendance';
$handler->display->display_options['relationships']['excuse_reason']['field'] = 'excuse_reason';
$handler->display->display_options['relationships']['excuse_reason']['required'] = 0;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'kstu_id_fk';
$handler->display->display_options['fields']['name']['label'] = 'Username';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['external'] = 0;
$handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
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
$handler->display->display_options['fields']['name']['format_username'] = 1;
/* Field: Kleosis: ksatnd atnd date */
$handler->display->display_options['fields']['atnd_date']['id'] = 'atnd_date';
$handler->display->display_options['fields']['atnd_date']['table'] = 'ks_student_attendance';
$handler->display->display_options['fields']['atnd_date']['field'] = 'atnd_date';
$handler->display->display_options['fields']['atnd_date']['label'] = 'Attendance Date';
$handler->display->display_options['fields']['atnd_date']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['external'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['atnd_date']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['atnd_date']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['trim'] = 0;
$handler->display->display_options['fields']['atnd_date']['alter']['html'] = 0;
$handler->display->display_options['fields']['atnd_date']['element_label_colon'] = 1;
$handler->display->display_options['fields']['atnd_date']['element_default_classes'] = 1;
$handler->display->display_options['fields']['atnd_date']['hide_empty'] = 0;
$handler->display->display_options['fields']['atnd_date']['empty_zero'] = 0;
$handler->display->display_options['fields']['atnd_date']['hide_alter_empty'] = 0;
/* Field: Kleosis: katndesc absence_type */
$handler->display->display_options['fields']['absence_type']['id'] = 'absence_type';
$handler->display->display_options['fields']['absence_type']['table'] = 'ks_absence_type_desc';
$handler->display->display_options['fields']['absence_type']['field'] = 'absence_type';
$handler->display->display_options['fields']['absence_type']['relationship'] = 'abs_type';
$handler->display->display_options['fields']['absence_type']['label'] = 'Absence type';
$handler->display->display_options['fields']['absence_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_type']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['external'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['absence_type']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['absence_type']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['trim'] = 0;
$handler->display->display_options['fields']['absence_type']['alter']['html'] = 0;
$handler->display->display_options['fields']['absence_type']['element_label_colon'] = 1;
$handler->display->display_options['fields']['absence_type']['element_default_classes'] = 1;
$handler->display->display_options['fields']['absence_type']['hide_empty'] = 0;
$handler->display->display_options['fields']['absence_type']['empty_zero'] = 0;
$handler->display->display_options['fields']['absence_type']['hide_alter_empty'] = 0;
/* Field: Kleosis: kexcrdesc excuse_reason */
$handler->display->display_options['fields']['excuse_reason']['id'] = 'excuse_reason';
$handler->display->display_options['fields']['excuse_reason']['table'] = 'ks_excused_absence_reason_desc';
$handler->display->display_options['fields']['excuse_reason']['field'] = 'excuse_reason';
$handler->display->display_options['fields']['excuse_reason']['relationship'] = 'excuse_reason';
$handler->display->display_options['fields']['excuse_reason']['label'] = 'Excuse Reason';
$handler->display->display_options['fields']['excuse_reason']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['external'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['excuse_reason']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['excuse_reason']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['trim'] = 0;
$handler->display->display_options['fields']['excuse_reason']['alter']['html'] = 0;
$handler->display->display_options['fields']['excuse_reason']['element_label_colon'] = 1;
$handler->display->display_options['fields']['excuse_reason']['element_default_classes'] = 1;
$handler->display->display_options['fields']['excuse_reason']['empty'] = 'none specified';
$handler->display->display_options['fields']['excuse_reason']['hide_empty'] = 0;
$handler->display->display_options['fields']['excuse_reason']['empty_zero'] = 0;
$handler->display->display_options['fields']['excuse_reason']['hide_alter_empty'] = 0;
/* Sort criterion: User: Name */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'users';
$handler->display->display_options['sorts']['name']['field'] = 'name';
$handler->display->display_options['sorts']['name']['relationship'] = 'kstu_id_fk';
/* Sort criterion: Kleosis: ksatnd atnd date */
$handler->display->display_options['sorts']['atnd_date']['id'] = 'atnd_date';
$handler->display->display_options['sorts']['atnd_date']['table'] = 'ks_student_attendance';
$handler->display->display_options['sorts']['atnd_date']['field'] = 'atnd_date';
/* Filter criterion: Kleosis: ksatnd absent type */
$handler->display->display_options['filters']['abs_type']['id'] = 'abs_type';
$handler->display->display_options['filters']['abs_type']['table'] = 'ks_student_attendance';
$handler->display->display_options['filters']['abs_type']['field'] = 'abs_type';
$handler->display->display_options['filters']['abs_type']['operator'] = '>';
$handler->display->display_options['filters']['abs_type']['value']['value'] = '0';
/* Filter criterion: Kleosis: ksatnd atnd date */
$handler->display->display_options['filters']['atnd_date']['id'] = 'atnd_date';
$handler->display->display_options['filters']['atnd_date']['table'] = 'ks_student_attendance';
$handler->display->display_options['filters']['atnd_date']['field'] = 'atnd_date';
$handler->display->display_options['filters']['atnd_date']['exposed'] = TRUE;
$handler->display->display_options['filters']['atnd_date']['expose']['operator_id'] = 'atnd_date_op';
$handler->display->display_options['filters']['atnd_date']['expose']['label'] = 'Attendance Date';
$handler->display->display_options['filters']['atnd_date']['expose']['operator'] = 'atnd_date_op';
$handler->display->display_options['filters']['atnd_date']['expose']['identifier'] = 'atnd_date';
$handler->display->display_options['filters']['atnd_date']['expose']['multiple'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'daily-attendance-list';
