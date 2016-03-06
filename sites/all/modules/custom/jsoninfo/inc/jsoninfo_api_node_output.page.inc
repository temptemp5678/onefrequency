<?php
/**
 * callback from hook_menu()
 */
function _jsoninfo_node_all_order_data() {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->nodeOrderData());
}

/**
 * callback from hook_menu()
 */
function _jsoninfo_node_all_product_data() {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->nodeProductData());
}
/**
 * callback from hook_menu()
 */
function _jsoninfo_node_product_brand_data($brand_tid = NULL) {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->nodeProductBrandData(array($brand_tid)));
}

/**
 * callback from hook_menu()
 * @param, brand term tid
 * @return bran term name
 */
function _jsoninfo_node_product_brand_name($brand_tid = NULL) {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->nodeProductBrandName($brand_tid));
}

/**
 * callback from hook_menu()
 * @param, brand term tid
 * @return bran term name
 */
function _jsoninfo_node_product_node_name($nid = NULL) {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->nodeProductNodeName($nid));
}

/**
 * callback from hook_menu()
 */
function _jsoninfo_node_all_quote_data() {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->nodeQuoteData());
}
/**
 * callback from hook_menu()
 */
function _jsoninfo_node_quote_list() {
  $JsonData = new JsonData();
  drupal_json_output($JsonData->jsonNodeQuoteList());
}

