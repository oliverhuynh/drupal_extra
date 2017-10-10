<?php
/**
 * @file
 * visitors_extra.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function visitors_extra_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "data" && $api == "data_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function visitors_extra_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
