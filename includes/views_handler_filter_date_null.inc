<?php
/**
 * @file
 */

class views_handler_filter_date_null extends date_views_filter_handler {
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
}
