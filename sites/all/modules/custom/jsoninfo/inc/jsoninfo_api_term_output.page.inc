<?php
/**
 * callback from hook_menu()
 */
function _jsoninfo_term_all_brand_data() {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->termBrandData());
}
/**
 * callback from hook_menu()
 */
function _jsoninfo_term_all_contact_data() {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->termContactData());
}

/**
 * callback from hook_menu()
 */
function _jsoninfo_term_all_client_data() {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->termClientData());
}

