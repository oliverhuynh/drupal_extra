<?php

/**
 * Implement of hook_views_data_alter
 */
function editableviews_extra_views_data_alter(&$data) {
  foreach ($data as $table => $tableinfo) {
    foreach ($tableinfo as $field => $fieldinfo) {
      if (isset($fieldinfo['info']['handler']) && $fieldinfo['info']['handler'] == 'editableviews_handler_field_field_edit') {
        $fieldinfo['info']['handler'] = 'editableviews_extra_handler_field_field_edit';
      }
    }
  }
}
