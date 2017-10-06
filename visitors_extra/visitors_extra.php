<?php

/**
 * @file
 * Handles counts of node views via Ajax with minimal bootstrap.
 */

/**
* Root directory of Drupal installation.
*/
if (isset($_POST['url'])) {
  define('DRUPAL_ROOT', substr($_SERVER['SCRIPT_FILENAME'], 0, strpos($_SERVER['SCRIPT_FILENAME'], $_POST['url'])));
  // Change the directory to the Drupal root.
  chdir(DRUPAL_ROOT);

  include_once DRUPAL_ROOT . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
  global $user;
  $not_admin = !in_array('administrator', $user->roles);
  $log_admin = !variable_get('visitors_exclude_administer_users', 0);
  if (isset($_POST['visitors_get_url'])) {
    if ($log_admin || $not_admin) {
      $ip_str = visitors_get_ip_str();

      $fields = array(
        'visitors_uid'            => $user->uid,
        'visitors_ip'             => $ip_str,
        'visitors_date_time'      => time(),
        'visitors_url'            => $_POST['visitors_get_url'],
        'visitors_referer'        => $_POST['visitors_get_referer'],
        'visitors_path'           => $_POST['visitors_get_path'],
        'visitors_title'          => $_POST['visitors_get_title'],
        'visitors_user_agent'     => visitors_get_user_agent()
      );

      if (module_exists('visitors_geoip')) {
        $geoip_data = visitors_get_geoip_data($ip_str);

        $fields['visitors_continent_code'] = $geoip_data['continent_code'];
        $fields['visitors_country_code']   = $geoip_data['country_code'];
        $fields['visitors_country_code3']  = $geoip_data['country_code3'];
        $fields['visitors_country_name']   = $geoip_data['country_name'];
        $fields['visitors_region']         = $geoip_data['region'];
        $fields['visitors_city']           = $geoip_data['city'];
        $fields['visitors_postal_code']    = $geoip_data['postal_code'];
        $fields['visitors_latitude']       = $geoip_data['latitude'];
        $fields['visitors_longitude']      = $geoip_data['longitude'];
        $fields['visitors_dma_code']       = $geoip_data['dma_code'];
        $fields['visitors_area_code']      = $geoip_data['area_code'];
      }

      db_insert('visitors')
        ->fields($fields)
        ->execute();
    }
  }
}
