<?php
/**
 * @file
 *
 */

/**
 * callback from hook_block_view()
 */
function _blockinfo_footer_company_info() {
  $output = '';
  $output .= '<div class="othercontent-footer-company-info-wrapper hidden-print">';

    $output .= '<div class="text-center">';
      $output .= '<div class="color-ddd">' . t('北京市朝阳区平乐园100号') . '</div>';
      $output .= '<div class="color-ddd">';
      $output .= '</div>';
    $output .= '</div>';

    $output .= '<div class="text-center">';
      $output .= '<div> V1.18.09</div>';
    $output .= '</div>';

  $output .= '</div>';

  return $output;
}
