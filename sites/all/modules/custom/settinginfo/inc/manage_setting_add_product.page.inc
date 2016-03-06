<?php
/**
 * @file for New Client Form
 */

/**
 * Implements page_callback(), callback from hook_menu()
 */
function _manage_setting_add_product() {
  $link_array = array();

  if (user_access('access role siteadmin')) {
    $link_array_plus = array(
      array('link_text' => t('Add Brand'), 'link_path' => 'term/brand/add'),
      array('link_text' => t('Add Product'), 'link_path' => 'manage/product/add'),
      array('link_text' => t('Add User'), 'link_path' => 'manage/user/create'),
      array('link_text' => t('User List'), 'link_path' => 'manage/user/list'),
      array('link_text' => t('Company List'), 'link_path' => 'manage/term/table/7'),
      array('link_text' => t('Product List'), 'link_path' => 'shop/review/products'),
    );

    $link_array = array_merge($link_array, $link_array_plus);
  }

  /**
   * output
   */
  $output = '';
  $output .= '<div class="row margin-0">';

    foreach ($link_array as $key => $value) {
      $output .= '<div class="col-xs-12 col-sm-6 col-md-3">';
        $output .= '<button class="btn btn-info">';
          $output .= '<span class="glyphicon glyphicon-calendar margin-right-6"></span>';
          $output .= l($value['link_text'], $value['link_path'], array(
              'attributes' => array('class' => array('color-fff')),
              'query' => array('destination' => 'manage/setting/add-product'),
            ));
        $output .= '</button>';
      $output .= '</div>';

      if ((($key + 1) % 4) == 0) {
        $output .= '</div>';
        $output .= '<hr />';
        $output .= '<div class="row margin-0">';
      }
    }

  $output .= '</div>';

  return $output;
}
