<?php

/**
 * @file
 */

/**
 * Implements hook_views_data_alter().
 */
function drupal_extra_views_data_alter(&$data) {
  $data['views']['datenull'] = array(
    'title' => t('Date Null'),
    'help' => t('Allow a contextual date filter value to be ignored. The query will not be altered by this contextual filter value. Can be used when contextual filter values come from the URL, and a part of the URL needs to be ignored.'),
    'argument' => array(
      'handler' => 'views_handler_argument_date_null',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date_null',
      'empty field name' => t('Undated'),
      'is date' => TRUE,
      // 'skip base' => $base_table,
    ),
  );
}
