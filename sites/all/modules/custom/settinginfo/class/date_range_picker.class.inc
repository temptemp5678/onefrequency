<?php
/**
 * @file
 */

/**
 *  class, calculate function
 */
class DashDateRangePicker {
  /**
   * @return HTML element for page
   *  output on navbar header
   */
  public static function dateRangePickerHeader() {
    // add Date Range Picker JS Library, from hook_library()
    drupal_add_library('othersetting', 'othersetting_date_range_picker');
    drupal_add_js(drupal_get_path('module', 'othersetting') .'/lib_controller/daterangepicker_controller.js');

    // set YTD,  'Year To Date - YTD' The period beginning January 1st of the current year up until today's date.
    $date_start = '2015-01-01';
    $date_end = '2015-07-01';

    // date range picker HTML
    $output = '';
    $output .= '<div class="pull-right">';
      $output .= '<div id="daterangepicker-warpper" class="pull-right btn btn-info margin-right-24 margin-bottom-24">';
        $output .= '<i class="fa fa-calendar fa-lg"></i>';
        $output .= '<span class="color-fff">' . $date_start . ' - ' . $date_end . '</span> <b class="caret"></b>';
      $output .= '</div>';
    $output .= '</div>';

    return $output;
  }
}
