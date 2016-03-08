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

/**
 * Implements page_callback(), callback from hook_menu()
 * 使用phantomjs生成网站快照
 * http://www.oschina.net/code/snippet_815453_23718
 */
function _develop_nodejs_demo_two() {
  drupal_add_js(drupal_get_path('module', 'developinfo') . '/js/develop_nodejs_demo_two.js');

  if (isset($_GET['url'])) {
    dpm($_GET["url"]);
  }
  if (isset($_POST['url'])) {
    dpm($_POST["url"]);
  }
  $output = '';
  $output .= '<div class="panel panel-default margin-top-12">';
    $output .= '<div class="panel-heading">Bivariate Chart</div>';
    $output .= '<div class="panel-body bg-ffffff padding-0">';
      $output .= '<form action="" id="form">';
        $output .= '<input type="text" id="url" />';
        $output .= '<button type="submit">生成快照</button>';
        $output .= '<div>';
          $output .= '<img src="" alt="" id="placeholder" />';
        $output .= '</div>';
      $output .= '</form>';
    $output .=' </div>';
  $output .=' </div>';

  return $output;
}

