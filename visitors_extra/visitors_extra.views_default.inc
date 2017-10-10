<?php
/**
 * @file
 * visitors_extra.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function visitors_extra_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'myvisitors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'visitors';
  $view->human_name = 'Visitors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'visitors_title' => 'visitors_title',
    'visitors_url' => 'visitors_url',
    'visitors_path' => 'visitors_title',
    'visitors_path_1' => 'visitors_path_1',
  );
  $handler->display->display_options['style_options']['default'] = 'visitors_path_1';
  $handler->display->display_options['style_options']['info'] = array(
    'visitors_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'visitors_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'visitors_path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'visitors_path_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Visitors: Visitors title */
  $handler->display->display_options['fields']['visitors_title']['id'] = 'visitors_title';
  $handler->display->display_options['fields']['visitors_title']['table'] = 'visitors';
  $handler->display->display_options['fields']['visitors_title']['field'] = 'visitors_title';
  $handler->display->display_options['fields']['visitors_title']['label'] = 'Page';
  /* Field: Visitors: Visitors url */
  $handler->display->display_options['fields']['visitors_url']['id'] = 'visitors_url';
  $handler->display->display_options['fields']['visitors_url']['table'] = 'visitors';
  $handler->display->display_options['fields']['visitors_url']['field'] = 'visitors_url';
  $handler->display->display_options['fields']['visitors_url']['exclude'] = TRUE;
  /* Field: Visitors: Visitors path */
  $handler->display->display_options['fields']['visitors_path']['id'] = 'visitors_path';
  $handler->display->display_options['fields']['visitors_path']['table'] = 'visitors';
  $handler->display->display_options['fields']['visitors_path']['field'] = 'visitors_path';
  $handler->display->display_options['fields']['visitors_path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['visitors_path']['alter']['path'] = '[visitors_url]';
  /* Field: COUNT(Visitors: Visitors path) */
  $handler->display->display_options['fields']['visitors_path_1']['id'] = 'visitors_path_1';
  $handler->display->display_options['fields']['visitors_path_1']['table'] = 'visitors';
  $handler->display->display_options['fields']['visitors_path_1']['field'] = 'visitors_path';
  $handler->display->display_options['fields']['visitors_path_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['visitors_path_1']['label'] = 'Visited';
  /* Filter criterion: Date: Date (visitors) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'visitors';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'visitors.visitors_date_time' => 'visitors.visitors_date_time',
  );

  /* Display: System */
  $handler = $view->new_display('system', 'System', 'system_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['path'] = 'visitors/pages';
  $export['myvisitors'] = $view;

  return $export;
}
