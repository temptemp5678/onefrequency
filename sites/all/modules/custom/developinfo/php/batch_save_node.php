<?php

/**
 *
drupal_set_time_limit(0);
require_once(DRUPAL_ROOT . '/sites/all/modules/custom/developinfo/php/batch_save_node.php');
_get_csv_array();
removeRecordLogNid();

 */

/**
 * node save
 */
function _get_csv_array($param_array = NULL) {
  $csv_file = drupal_get_path('module', 'developinfo') . '/php/source/huaneng-02251056-1M.csv';

  $handle = fopen($csv_file, 'r');

  timer_start('your_key');
  $count = 0;
  if (2 > 1) {
    while ($row = fgetcsv($handle)) {
      // $key 0 is header
      if (is_numeric($row[0])) {
        // if ($count > 2000) {
        //   break;
        // }

        $csv_para = array(
          'time' => round($row[0]),     // format nubmer as integer
          'velocity1' => $row[1],
          'velocity2' => $row[2],
        );

        // $node_nid = _save_recordlog_node($csv_para);
      }

      $count++;
    }
  }

  fclose($handle);

  dpm(timer_stop('your_key'));
}


/** - - - - - - node save with field - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/**
 * node save
 */
function _save_recordlog_node($param_array = NULL) {
  global $user;

  $node = new stdClass();
  $node->type = 'record_log';
  $node->title = 'Import Log';
  $node->language = LANGUAGE_NONE; // Or any language code if Locale module is enabled. More on this below *

  node_object_prepare($node); // Set some default values.
  $node->uid = $user->uid;

  $node->field_recordlog_time['und'][0]['value'] = $param_array['time'];
  $node->field_recordlog_velocity1['und'][0]['value'] = $param_array['velocity1'];
  $node->field_recordlog_velocity2['und'][0]['value'] = $param_array['velocity2'];

  $node = node_submit($node); // Prepare node for a submit
  node_save($node); // After this call we'll get a nid

  $node_nid = $node->nid;

  dpm(t('Save node as ') . $node_nid);
  // drupal_set_message(t('Save node as ') . $node_nid);

  return $node->nid;
}


/** - - - - - - node save with field - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/**
 * node remove
 */
function removeRecordLogNid() {
  $nids = allRecordLogNid();
dpm(count($nids));

  timer_start('your_key2');
  if (is_array($nids)) {
    // node_delete_multiple($nids);
  }
  dpm(timer_stop('your_key2'));
}

function allRecordLogNid() {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'record_log')
    ->propertyCondition('status', NODE_PUBLISHED);

  $result = $query->execute();

  $nid_array = NULL;
  if (isset($result['node'])) {
    if (count($result['node']) > 0 ) {
      $nid_array = array_keys($result['node']);
    }
  }

  return $nid_array;
}
