<?php
/**
 * @file
 */

/**
 * class
 * $NodeQuery = new NodeQuery($nid);
 */
class NodeQuery {

  /** - - - - - - common Node Type- - - - - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @parameter, $node_type is array()
   *
   * @return array,
   * all Product NID
   */
  public function nodesByBundles($node_type = array()) {

    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $node_type)
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

}
