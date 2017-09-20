(function ($) {
jQuery.fn.toggleOption = function( show ) {
    $(this).each(function() {
      var $select = $(this).closest('select');
      // Reset to _none first
      if (!show) {
        if ($(this).attr('value') == $select.val()) {
          $(this).attr('selected', '');
          $select.val('_none').find("[value='_none']").attr('selected', 'selected');
          $select.trigger('change');
        }
      }
      jQuery( this ).toggle( show );
      if( show ) {
          if( jQuery( this ).parent( 'span.toggleOption' ).length ) {
            jQuery( this ).unwrap( );
          }
      } else {
          if( jQuery( this ).parent( 'span.toggleOption' ).length == 0 ) {
            jQuery( this ).wrap( '<span class="toggleOption" style="display: none;" />' );
          }
      }
    })
};

  states = Drupal.states;
  if (states) {
    Drupal.states.Trigger.states.valuechange = {
      'change': function () {
        var awayscchange = this.data('awayscchange') || false;
        this.data('awayscchange', !awayscchange);
        return !awayscchange;
      }
    };
    $(document).bind('state:hideselectedoption', function(e) {
      if (e.trigger) {
        try {
          var dependento = Drupal.settings.states['#' + $(e.target).attr("id")]['hideselectedoption'];
          for (var dependent in dependento) {
              break;
          }
          var v = $(dependent).val();
          var op = $(e.target).find('option[value="'+ v +'"]');
          $(e.target).find('option').toggleOption(true);
          if (v != '_none') {
            op.toggleOption(false);
          }
        }
        catch(f) {
        }
      }
    });
  }
})(jQuery);
