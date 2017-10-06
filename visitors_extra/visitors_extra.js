(function ($) {
  $(document).ready(function() {
    Drupal.settings.visitors_extra.data['visitors_get_referer'] = document.referrer;
    $.ajax({
      type: "POST",
      cache: false,
      url: Drupal.settings.visitors_extra.url,
      data: Drupal.settings.visitors_extra.data
    });
  });
})(jQuery);
