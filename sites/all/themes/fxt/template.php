<?php

/**
 * @file
 * template.php
 */

/** - - - - - - base_path() - - - - - - - - - - - - - - - - - - - -  */
/**
 * pass "base path" to JS
 */
drupal_add_js('jQuery.extend(Drupal.settings, { "basePath": "' . base_path() . '" });', 'inline');

/** - - - - - - current language url prefix - - - - - - - - - - - - - - - - - - - -  */
global $language;
if (isset($language->language)) {
  if ($language->language == 'zh-hans') {
    drupal_add_js('jQuery.extend(Drupal.settings, { "currentLanguagePrefix": "' . $language->language . '" });', 'inline');
  }
}

