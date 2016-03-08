(function($){
  jQuery(document).ready(function() {
    console.log(22);
    $('#form').submit(function(){
      if (typeof($(this).data('generate')) !== 'undefined' && $(this).data('generate') === true) {
        alert('正在生成网站快照，请耐心等待...');
        return false;
      }

      $(this).data('generate', true);
      $('button').text('正在生成快照...').attr('disabled', true);

      $.ajax({
        type: 'GET',
        url: '?',
        data: 'url=' + $('#url').val(),
        success: function(data){
          $('#placeholder').attr('src', data).show();
          $('#form').data('generate', false);
          $('button').text('生成快照').attr('disabled', false);
        }
      });

      return false;
    });
  });
})(jQuery);
