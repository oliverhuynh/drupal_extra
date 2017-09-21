<?php

/**
 * @file
 * Definition of views_handler_argument_null.
 */

/**
 * Argument handler that ignores the argument.
 *
 * @ingroup views_argument_handlers
 */
class views_handler_argument_date_null extends date_views_argument_handler {
  function init(&$view, &$options) {
    $options['date_fields'] = array('null');
    parent::init($view, $options);
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['date_fields'] = array('#tyle' => 'hidden', '#default_value' => 'null', '#value' => 'null');
  }
  function options_validate(&$form, &$form_state) {
  }
  function validate_argument_basic($arg) {
    if (!empty($this->options['must_not_be'])) {
      return !isset($arg);
    }

    return parent::validate_argument_basic($arg);
  }

  /**
   * Override the behavior of query() to prevent the query
   * from being changed in any way.
   */
  // function query($group_by = FALSE) {}
}
