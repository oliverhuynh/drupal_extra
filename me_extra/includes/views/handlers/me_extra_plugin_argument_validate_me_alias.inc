<?php

/**
 * @file
 *
 * Argument validator to help validate the me alias. If the argument is 'me', other validators
 * will most likely be useless at this point, so we provde the same functionality as the
 * user validator.
 */

/**
 * Validate whether an argument is an acceptable me alias, and user name/uid.
 */
class me_extra_plugin_argument_validate_me_alias extends me_plugin_argument_validate_me_alias {
  /**
   * Performs the actual validation.
   */
  function validate_argument($argument) {
    $ret = parent::validate_argument($argument);
    if ($this->check_is_admin($argument)) {
      $this->view->build_info['denied'] = FALSE;
      return TRUE;
    }
    return $ret;
  }

  function check_is_admin($argument) {
    return user_access('access all other uids');
  }
}

