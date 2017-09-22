<?php

/**
 * Implement of hook_views_plugins_alter
 */
function views_summarize_extra_views_plugins_alter(&$plugins) {
  $plugins['tablesummarized']['handler'] = 'views_summarize_extra_plugin_style_tablesummarized';
}
