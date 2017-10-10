<?php
/**
 * @file
 * visitors_extra.data_default.inc
 */

/**
 * Implements hook_data_default().
 */
function visitors_extra_data_default() {
  $export = array();

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Visitors';
  $data_table->name = 'visitors';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'visitors_id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'visitors_uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => TRUE,
        'default' => 0,
        'description' => '',
      ),
      'visitors_ip' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '32',
        'not null' => TRUE,
        'default' => '',
        'description' => '',
      ),
      'visitors_date_time' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => TRUE,
        'default' => 0,
        'description' => '',
      ),
      'visitors_url' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'visitors_referer' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'visitors_path' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'visitors_title' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'visitors_user_agent' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'visitors_nid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
    ),
    'name' => 'visitors',
    'primary key' => array(
      0 => 'visitors_id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'visitors_id' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_uid' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_ip' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_date_time' => array(
        'date' => array(
          'sql_type' => 'datestamp',
          'granularity' => 'second',
        ),
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_url' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_referer' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_path' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_title' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_user_agent' => array(
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'visitors_nid' => array(
        'label' => '',
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
    ),
    'join' => array(
      'users' => array(
        'left_field' => 'uid',
        'field' => 'visitors_uid',
        'inner_join' => '0',
      ),
      'node' => array(
        'left_field' => 'nid',
        'field' => 'visitors_nid',
        'inner_join' => '0',
      ),
    ),
  );
  $export['visitors'] = $data_table;

  return $export;
}
