<?php

/**
 * @file
 *  An exported Views attendance report with user filters
 */

$view = new view;
$view->name = 'kleosis_attendance_totals_2';
$view->description = 'Daily attendance details for a student for the given academic year and term (with filters)';
$view->tag = 'default';
$view->base_table = 'ks_student_attendance';
$view->human_name = 'Attendance details 2';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Kleosis Attendance Details (w/Filters)';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = 'No attendance details are available for this student.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
$handler->display->display_options['empty']['area']['tokenize'] = 0;
/* Relationship: Kleosis: ksatnd absent type */
$handler->display->display_options['relationships']['abs_type']['id'] = 'abs_type';
$handler->display->display_options['relationships']['abs_type']['table'] = 'ks_student_attendance';
$handler->display->display_options['relationships']['abs_type']['field'] = 'abs_type';
$handler->display->display_options['relationships']['abs_type']['required'] = 0;
/* Relationship: Kleosis: ks_std_atnd: Link to Student */
$handler->display->display_options['relationships']['kstu_id_fk']['id'] = 'kstu_id_fk';
$handler->display->display_options['relationships']['kstu_id_fk']['table'] = 'ks_student_attendance';
$handler->display->display_options['relationships']['kstu_id_fk']['field'] = 'kstu_id_fk';
$handler->display->display_options['relationships']['kstu_id_fk']['required'] = 0;
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
$handler->display->display_options['fields']['atnd_date']['element_label_colon'] = 0;
$handler->display->display_options['fields']['atnd_date']['element_default_classes'] = 1;
$handler->display->display_options['fields']['atnd_date']['hide_empty'] = 0;
$handler->display->display_options['fields']['atnd_date']['empty_zero'] = 0;
$handler->display->display_options['fields']['atnd_date']['hide_alter_empty'] = 0;
/* Field: Kleosis: ksatnd period day */
$handler->display->display_options['fields']['period_day']['id'] = 'period_day';
$handler->display->display_options['fields']['period_day']['table'] = 'ks_student_attendance';
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
$handler->display->display_options['fields']['period_day']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['trim'] = 0;
$handler->display->display_options['fields']['period_day']['alter']['html'] = 0;
$handler->display->display_options['fields']['period_day']['element_label_colon'] = 1;
$handler->display->display_options['fields']['period_day']['element_default_classes'] = 1;
$handler->display->display_options['fields']['period_day']['hide_empty'] = 0;
$handler->display->display_options['fields']['period_day']['empty_zero'] = 0;
$handler->display->display_options['fields']['period_day']['hide_alter_empty'] = 0;
/* Field: Kleosis: katndesc absence_type */
$handler->display->display_options['fields']['absence_type']['id'] = 'absence_type';
$handler->display->display_options['fields']['absence_type']['table'] = 'ks_absence_type_desc';
$handler->display->display_options['fields']['absence_type']['field'] = 'absence_type';
$handler->display->display_options['fields']['absence_type']['relationship'] = 'abs_type';
$handler->display->display_options['fields']['absence_type']['label'] = 'Absent type';
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
/* Field: Kleosis: ksatnd remarks instructor */
$handler->display->display_options['fields']['remarks_instructor']['id'] = 'remarks_instructor';
$handler->display->display_options['fields']['remarks_instructor']['table'] = 'ks_student_attendance';
$handler->display->display_options['fields']['remarks_instructor']['field'] = 'remarks_instructor';
$handler->display->display_options['fields']['remarks_instructor']['label'] = 'Instructor remarks';
$handler->display->display_options['fields']['remarks_instructor']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['external'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['remarks_instructor']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['remarks_instructor']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['trim'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['alter']['html'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['element_label_colon'] = 1;
$handler->display->display_options['fields']['remarks_instructor']['element_default_classes'] = 1;
$handler->display->display_options['fields']['remarks_instructor']['hide_empty'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['empty_zero'] = 0;
$handler->display->display_options['fields']['remarks_instructor']['hide_alter_empty'] = 0;
/* Sort criterion: Kleosis: ksatnd atnd date */
$handler->display->display_options['sorts']['atnd_date']['id'] = 'atnd_date';
$handler->display->display_options['sorts']['atnd_date']['table'] = 'ks_student_attendance';
$handler->display->display_options['sorts']['atnd_date']['field'] = 'atnd_date';
$handler->display->display_options['sorts']['atnd_date']['order'] = 'DESC';
$handler->display->display_options['sorts']['atnd_date']['exposed'] = TRUE;
$handler->display->display_options['sorts']['atnd_date']['expose']['label'] = 'Attendance Date';
/* Sort criterion: Kleosis: katndesc absence_type */
$handler->display->display_options['sorts']['absence_type']['id'] = 'absence_type';
$handler->display->display_options['sorts']['absence_type']['table'] = 'ks_absence_type_desc';
$handler->display->display_options['sorts']['absence_type']['field'] = 'absence_type';
$handler->display->display_options['sorts']['absence_type']['relationship'] = 'abs_type';
$handler->display->display_options['sorts']['absence_type']['exposed'] = TRUE;
$handler->display->display_options['sorts']['absence_type']['expose']['label'] = 'Absence Type';
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'users';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['relationship'] = 'kstu_id_fk';
$handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
$handler->display->display_options['arguments']['uid']['not'] = 0;
/* Contextual filter: Kleosis: ksatnd atnd date */
$handler->display->display_options['arguments']['atnd_date']['id'] = 'atnd_date';
$handler->display->display_options['arguments']['atnd_date']['table'] = 'ks_student_attendance';
$handler->display->display_options['arguments']['atnd_date']['field'] = 'atnd_date';
$handler->display->display_options['arguments']['atnd_date']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['atnd_date']['default_argument_skip_url'] = 0;
$handler->display->display_options['arguments']['atnd_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['atnd_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['atnd_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['atnd_date']['specify_validation'] = 1;
$handler->display->display_options['arguments']['atnd_date']['validate']['type'] = 'php';
$handler->display->display_options['arguments']['atnd_date']['validate_options']['code'] = '// $argument has two date values appended together with and underscore
// ex. 2011-08-08 08:00:00_2011-12-31 08:00:00
// so may not be recognized as a valid numeric value.  Hence:

return TRUE;

// for now...';
$handler->display->display_options['arguments']['atnd_date']['break_phrase'] = 0;
$handler->display->display_options['arguments']['atnd_date']['not'] = 0;
/* Filter criterion: Kleosis: ksatnd absent type */
$handler->display->display_options['filters']['abs_type']['id'] = 'abs_type';
$handler->display->display_options['filters']['abs_type']['table'] = 'ks_student_attendance';
$handler->display->display_options['filters']['abs_type']['field'] = 'abs_type';
$handler->display->display_options['filters']['abs_type']['operator'] = '!=';
$handler->display->display_options['filters']['abs_type']['value']['value'] = '0';
/* Filter criterion: Kleosis: ksatnd atnd date */
$handler->display->display_options['filters']['atnd_date']['id'] = 'atnd_date';
$handler->display->display_options['filters']['atnd_date']['table'] = 'ks_student_attendance';
$handler->display->display_options['filters']['atnd_date']['field'] = 'atnd_date';
$handler->display->display_options['filters']['atnd_date']['operator'] = 'between';
$handler->display->display_options['filters']['atnd_date']['value']['min'] = '2011-08-03 08:00:00';
$handler->display->display_options['filters']['atnd_date']['value']['max'] = '2012-06-25 08:00:00';
$handler->display->display_options['filters']['atnd_date']['exposed'] = TRUE;
$handler->display->display_options['filters']['atnd_date']['expose']['operator_id'] = 'atnd_date_op';
$handler->display->display_options['filters']['atnd_date']['expose']['label'] = 'Attendance Date';
$handler->display->display_options['filters']['atnd_date']['expose']['use_operator'] = 1;
$handler->display->display_options['filters']['atnd_date']['expose']['operator'] = 'atnd_date_op';
$handler->display->display_options['filters']['atnd_date']['expose']['identifier'] = 'atnd_date';
$handler->display->display_options['filters']['atnd_date']['expose']['multiple'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'kleosis-attendance-totals-2';
