<?php

/**
 * @file
 * Twitter Pull Box
 */

/**
 * Simple custom text box.
 */
class boxes_views extends boxes_box {
  /**
   * Implementation of boxes_box::options_defaults().
   */
  public function options_defaults() {
   return array(
     'views' => '',
     'display' => '',
     'argument' => '',
     'itermsperpage' => '',
   );
  }

  /**
   * Implementation of boxes_box::options_form().
   */
  public function options_form(&$form_state) {
    $form = array();

    $form['views'] = array(
      '#type' => 'textfield',
      '#title' => t('Views'),
      '#required' => TRUE,
      '#default_value' => $this->options['views'],
      '#description' => t("Views name"),
    );
    $form['display'] = array(
      '#type' => 'textfield',
      '#title' => t('Display'),
      '#required' => TRUE,
      '#default_value' => $this->options['display'],
      '#description' => t("Views display"),
    );

    $form['argument'] = array(
      '#type' => 'textfield',
      '#title' => t('Argument'),
      '#required' => TRUE,
      '#default_value' => $this->options['argument'],
      '#description' => t("Views argument"),
    );

    $form['itermsperpage'] = array(
      '#type' => 'textfield',
      '#title' => t('Items per page'),
      '#required' => FALSE,
      '#default_value' => $this->options['itermsperpage'],
      '#description' => t("Views items per page"),
    );

    $info = vb_get_available_views();
    if ($info) {
      $default = $info[0];
      $default = current($default);
      $form['views']['#default_value'] = $default[0];
      $form['display']['#default_value'] = $default[1];
    }
    return $form;
  }

  /**
   * Implementation of boxes_box::render().
   */
  public function render() {
    $info = vb_get_available_views();
    $content = "";
    $title = "";
    if (isset($this->options['display']) && $this->options['display']) {
      $title = $this->title;
      // TODO: Get block title $title = "";
      if ($this->options['argument']) {
        $content = de_views_embed_view($this->options['views'], $this->options['display'], $this->options['itermsperpage'], $this->options['argument']);
      }
      else {
        $content = de_views_embed_view($this->options['views'], $this->options['display'], $this->options['itermsperpage']);
      }
    }
    return array(
      'delta' => $this->delta, // Crucial.
      'title' => $title,
      'subject' => $title,
      'content' => $content,
    );
  }
}
