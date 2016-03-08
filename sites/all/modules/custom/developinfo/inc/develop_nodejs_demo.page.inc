<?php

/**
 * Implements page_callback(), callback from hook_menu()
 */
function _develop_nodejs_demo_one() {
  // drupal_add_js(drupal_get_path('module', 'reportpage') . '/js/reportpage_product_chart.js');

  $output = '';
  $output .= '<div class="panel panel-default margin-top-12">';
    $output .= '<div class="panel-heading">Bivariate Chart</div>';
    $output .= '<div class="panel-body bg-ffffff padding-0">';
      $output .= 'rr';
    $output .=' </div>';
  $output .=' </div>';

  return $output;
}
