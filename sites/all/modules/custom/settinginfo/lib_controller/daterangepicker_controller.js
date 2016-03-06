jQuery(document).ready(function($) {
  /**
   * Date Range Picker
   * Pre-defined Ranges & Callback
   *
   */
  $('#daterangepicker-warpper').daterangepicker(
    {
      ranges: {
        // 'Today': [moment(), moment()],
        // 'Yesterday': [moment().subtract('days', 1), moment().subtract('days', 1)],
        // 'Last 30 Days': [moment().subtract('days', 29), moment()],
        'Last 30 Days': [moment().subtract(29, 'days'), moment()],
        'Last 60 Days': [moment().subtract(59, 'days'), moment()],
        'Last 90 Days': [moment().subtract(89, 'days'), moment()],
        'YTD': [moment().startOf('year'), moment()],
        'All Orders': [moment().subtract(2000, 'days'), moment().add(1000, 'days')],
        // 'This Month': [moment().startOf('month'), moment().endOf('month')],
        // 'Last Month': [moment().subtract('month', 1).startOf('month'), moment().subtract('month', 1).endOf('month')]
      },
      startDate: moment().subtract(30, 'days'),
      endDate: moment()
    },
    // action after click "apply" button or above quick "ranges" link
    function(start, end) {
      $('#reportrange-header span').html(start.format('MMMM D, YYYY') + ' - ' + end.format('MMMM D, YYYY'));

      // start.valueOf() is Unix TimeStamp
      var startDate = parseInt((start.valueOf()) / 1000);
      var endDate = parseInt((end.valueOf()) / 1000);

      // check path
      var path = $(location).attr('href');
      var pathArray = path.split("/");

      // get URL only path arg() without unix timestamp
      var pathFilter = '';
      $.each( path.split("/"), function( key, value ) {
        if ( (value.length > 9) && ($.isNumeric(value)) ) {
          // Unix TimeStamp length is 10, ignore the URL Unix TimeStamp
        }
        else {
          if (key == 0) {
            pathFilter += value;
          }
          else {
            pathFilter += '/' + value;
          }
        }
      });

      // add new date range parameter
      var pathDate = pathFilter + '/' + startDate + '/' + endDate;

      // redirect page
      // window.location.replace(pathDate);
    }
  );
});





