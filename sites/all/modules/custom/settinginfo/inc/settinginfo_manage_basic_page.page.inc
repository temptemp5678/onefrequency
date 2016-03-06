<?php
/**
 * callback from hook_menu()
 */
function _settinginfo_manage_basic_page_403() {
  // if(user_is_anonymous()) {
  //   drupal_goto('user');
  //   // drupal_exit();
  // }

  $output = '';
  $output .= '<div class="text-center">
    <p style="height:80px;">&nbsp;</p>
    <p><span class="h1" style="font-size:80px;">403</span></p>
    <p>&nbsp;</p>
    <p>You Requested the page that is no longer There</p>
    <p style="height:325px;">&nbsp;</p>
    </div>';

  return $output;
}

/**
 * callback from hook_menu()
 */
function _settinginfo_manage_basic_page_404() {
  $image = array(
    'path' => base_path() . '/sites/default/files/pictures/lib/404-error-img.png',
    'alt' => 'Site 404',
    'attributes' => array('class' => 'site-404'),
  );
  $image_404 = theme('image', $image);

  $output = '';
  $output = '<div class="text-center">';
    $output .= '<p style="height:6px;">&nbsp;</p>';
    $output .= '<p><span class="h1" style="font-size:80px;">404</span></p>';
    $output .= '<p>&nbsp;</p>';
    $output .= '<p><span class="h1 margin-top-12">PAGE NOT FOUND</span></p>';
    $output .= '<p>&nbsp;</p>';
    $output .= $image_404;
    $output .= '<p>&nbsp;</p>';
    $output .= '<p>You Requested the page that is no longer There</p>';
    $output .= '<p style="height:64px;">&nbsp;</p>';
  $output .= '</div>';

  return $output;
}
