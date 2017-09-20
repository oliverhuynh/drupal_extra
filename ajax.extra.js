(function ($) {
Drupal.behaviors.AJAX2 = {
  attach: function (context, settings) {
    // Load all Ajax behaviors specified in the settings.
    for (var base in settings.ajax) {
      if (!$('#' + base + '.ajax2-processed').length) {
        $('#' + base).addClass('ajax2-processed');
        var element_settings = settings.ajax[base];
        if (element_settings.onload) {
          $(element_settings.selector).each(function () {
            $(this).trigger("change");
          });
        }
      }
    }
  }
}
})(jQuery);
