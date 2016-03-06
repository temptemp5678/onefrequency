<?php

/**
 * Implements page_callback(), callback from hook_menu()
 */
function _reportpage_product_chart() {
  drupal_add_js(drupal_get_path('module', 'reportpage') . '/js/reportpage_product_chart.js');

  $output = '';

  $output .= '<form class="form-inline">';
    $output .= '<div class="form-group">';
      $output .= '<label class="sr-only" for="exampleInputEmail3">Start</label>';
      $output .= '<input class="form-control" id="exampleInputEmail3" placeholder="Start">';
    $output .= '</div>';
    $output .= '<div class="form-group margin-left-12">';
      $output .= '<label class="sr-only" for="exampleInputPassword3">End</label>';
      $output .= '<input class="form-control" id="exampleInputPassword3" placeholder="End">';
    $output .= '</div>';
    $output .= '<div class="form-group margin-left-12">';
      $output .= '<button type="submit" class="btn btn-default">Submit</button>';
    $output .= '</div>';
  $output .= '</form>';

  $output .= '<div class="panel panel-default margin-top-12">';
    $output .= '<div class="panel-heading">Bivariate Chart</div>';
    $output .= '<div class="panel-body bg-ffffff padding-0">';
      $output .= '<canvas class="padding-6-12" id="reportpage-summary-quote-line-chart" width="390" height="150"></canvas>';
    $output .=' </div>';
  $output .=' </div>';

  return $output;
}
