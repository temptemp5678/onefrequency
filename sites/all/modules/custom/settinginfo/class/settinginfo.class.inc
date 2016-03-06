<?php
/**
 * @file
 */

/**
 * class
   $SettingInfo = new SettingInfo();
 */
class SettingInfo {
  /**
   * @return site logo
   */
  public function siteLogoImage($param_classes = array()) {
    $logo_image = NULL;

    // combine attributes class
    $classes = array('site-logo');
    if (is_array($param_classes)) {
      $classes = array_merge($classes, $param_classes);
    }

    $attributes_class = '';
    if (is_array($classes)) {
      $attributes_class = implode(" ", $classes);
    }

    // theme_image()
    if (theme_get_setting('logo')) {
      $image = array(
        'path' => theme_get_setting('logo'),
        'alt' => 'Site Logo',
        'attributes' => array('class' => $attributes_class),
      );
      $logo_image = theme('image', $image);
    }

    return $logo_image;
  }

  /**
   * @return site logo
   */
  public function siteLogoHTML() {
    $logo_image = $this->siteLogoImage();

    $output = NULL;
    if ($logo_image) {
      $output .= '<div class="color-fff">';
        $output .= $logo_image;
      $output .= '</div>';
    }
    return $output;
  }
}
