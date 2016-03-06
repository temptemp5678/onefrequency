<?php

/**
 * callback from hook_menu()
 */
function _jsoninfo_term_table($vid = NULL) {
  $JsonData = new JsonData();
  drupal_json_output($JsonData->jsonTermTable($vid));
}
