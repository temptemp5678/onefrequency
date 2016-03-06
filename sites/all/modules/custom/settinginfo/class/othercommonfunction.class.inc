<?php
/**
 * @file
 */

/**
 * class
 */
class OtherCommonFunction {

  /**
   * Checks if a string is a valid UNIX timestamp.
   *
   * @param  string $timestamp Timestamp to validate.
   *
   * @return Boolean
   */
  public static function is_timestamp($timestamp) {
    $check = (is_int($timestamp) OR is_float($timestamp))
             ? $timestamp
             : (string) (int) $timestamp;

    $result = ($check === $timestamp)
              AND ( (int) $timestamp <=  PHP_INT_MAX)
              AND ( (int) $timestamp >= ~PHP_INT_MAX);

    return $result;
  }

}
