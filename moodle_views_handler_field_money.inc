<?php

/**
 * @file
 * Handler definition for course prices.
 */
class moodle_views_handler_field_money extends views_handler_field_numeric {

  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['currency'] = array(
      'table' => 'price',
      'field' => 'currency'
    );
  }

  /**
   * Render the field.
   *
   * @param $values The
   *          values retrieved from the database.
   */
  function render($values) {
    $value = $this->get_value($values);
    $currency = $this->get_value($values, 'currency');
    $currency_symbols = array(
      'GBP' => '£',
      'EUR' => '€',
      'USD' => '$',
      'JPY' => '¥',
      'CAD' => 'C$',
      'AUD' => 'A$'
    );
    if (array_key_exists($currency, $currency_symbols)) {
      $currency = $currency_symbols[$currency];
    }
    else {
      $currency = $currency . ' ';
    }
    $value = $currency . number_format($value, 2);
    return $this->sanitize_value($value);
  }
}