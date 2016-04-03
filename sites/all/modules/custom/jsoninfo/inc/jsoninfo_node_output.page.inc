<?php
/**
 * callback from hook_menu()
 */
function _jsoninfo_node_recordlog_basic_values() {
  $JsonData = new JsonData();

  drupal_json_output($JsonData->jsonNodeRecordLogBasicValues());
}

