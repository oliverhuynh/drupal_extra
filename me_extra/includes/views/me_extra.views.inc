<?php

/**
 * @file
 *
 * Provides views intergration for the me module.
 */

/**
 * Implementation of hook_views_plugins
 */
function me_extra_views_plugins() {
  // Generate our plugin data.
  return array(
    'argument validator' => array(
      'me_extra' => array(
        'title' => t('Me Extra'),
        'handler' => 'me_extra_plugin_argument_validate_me_alias',
      ),
    ),
  );
}
