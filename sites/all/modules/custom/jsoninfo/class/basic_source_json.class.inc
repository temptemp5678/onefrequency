<?php
/**
 * @file
 */

/**
 * class
   OtherCommonJson::encodeJson();
   OtherCommonJson::saveDataToJson();
 */
class OtherCommonJson {
  /**
   * @return json array
   */
  public static function parsingJson($file_name = NULL) {
    $json_data = NULL;

    $json_data = file_get_contents('public://json/' . $file_name);

    return $json_data;
  }

  /**
   * @return json array
   */
  public static function encodeJson($raw_data = NULL) {
    $json_data = NULL;

    if (is_array($raw_data)) {
      $json_data = drupal_json_encode($raw_data);
    }

    return $json_data;
  }

  /**
   * @param  array.
   *
   * @return Save file
   */
  public static function saveJsonToFile($json_data = NULL, $file_name = NULL) {
    if (!$file_name) {
      return;
    }

    if ($json_data) {
      $file = file_save_data($json_data, 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
    }
    else {
      // put empty content
      $file = file_save_data('', 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
    }
  }

  /**
   * @param  array.
   *
   * @return Save Data to Json file
     OtherCommonJson::saveDataToJson($SourceJson->commerceOrderData(), 'orderinfo/orderinfo_summary_index.json');
   */
  public static function saveDataToJson($raw_data = NULL, $file_name = NULL) {
    if (!$file_name) {
      return;
    }

    if (is_array($raw_data)) {
      $json_data = OtherCommonJson::encodeJson($raw_data);

      if ($json_data) {
        $file = file_save_data($json_data, 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
      }
      else {
        // put empty content
        $file = file_save_data('', 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
      }
    }
    else {
      // put empty content
      $file = file_save_data('', 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
    }
  }
}

/**
 * class
   $SourceJson = new SourceJson();
   $SourceJson->sourceArrayData();
 *
 */
class SourceJson {
  /** - - - - - node - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
  /**
   *
   * @return array
   */
  public function nodeOrderData() {
    global $user;
    if (!isset($account)) {
      $account = $GLOBALS['user'];
    }

    /**
     * data
     */
    $NodeQuery = new NodeQuery();
    $nids = $NodeQuery->specifyBundleNid(array('order'));

    $nodes = node_load_multiple($nids);

    /**
     * data row array
     */
    $data_row = array();
    $data_row['nodes'] = array();
    if (is_array($nodes)) {
      foreach($nodes as $node) {
        $OrderInfo = new OrderInfo($node);

        // table row
        if ($OrderInfo->accessView($account)) {
          $data_row['nodes']['order'][] = $OrderInfo->allMethodsValue();
        }
      }
    }

    return $data_row;
  }

  /**
   *
   * @return array
   */
  public function nodeProductData() {
    /**
     * data
     * product is include Card, Chassis and Software
     */
    $NodeQuery = new NodeQuery();
    $all_product_nid = $NodeQuery->specifyBundleNid(array('product'));

    $product_nodes = node_load_multiple($all_product_nid);

    /**
     * data row array
     */
    $data_row = array();

    $data_row['nodes'] = array();
    if (is_array($product_nodes)) {
      foreach($product_nodes as $key => $node) {
        $ProductInfo = new ProductInfo($node);

        // table row
        $data_row['nodes']['products'][] = $ProductInfo->allMethodsValue();
      }
    }

    return $data_row;
  }
  /**
   * @param, brand term tids
   * @return array
   */
  public function nodeProductBrandData($brand_tids = NULL) {
    /**
     * data
     * product is include Card, Chassis and Software
     */
    $NodeQuery = new NodeQuery();
    $nids = $NodeQuery->productByBrandNid(array('product'), $brand_tids);

    $nodes = node_load_multiple($nids);

    /**
     * data row array
     */
    $data_row = array();

    $data_row['nodes'] = array();
    if (is_array($nodes)) {
      foreach($nodes as $node) {
        $ProductInfo = new ProductInfo($node);

        // table row
        $data_row['nodes']['products'][] = $ProductInfo->allMethodsValue();
      }
    }

    return $data_row;
  }

  /**
   * @param, brand term tid
   * @return array
   */
  public function nodeProductBrandName($brand_tid = NULL) {
    $output = NULL;

    $TermInfo = new TermInfo($brand_tid);
    $output = $TermInfo->termName();

    return $output;
  }

  /**
   * @param, Product Node nid
   * @return array
   */
  public function nodeProductNodeName($nid = NULL) {
    $output = NULL;

    $NodeInfo = new NodeInfo($nid);
    $output = $NodeInfo->nodeTitle();

    return $output;
  }

  /**
   *
   * @return array
   */
  public function nodeQuoteData() {
    global $user;
    if (!isset($account)) {
      $account = $GLOBALS['user'];
    }

    $NodeQuery = new NodeQuery();
    $all_quote_nid = $NodeQuery->allQuoteNid();

    $nodes = node_load_multiple($all_quote_nid);

    /**
     * data row array
     */
    $data_row = array();
    $data_row['nodes'] = array();

    if (is_array($nodes)) {
      foreach($nodes as $node) {
        $QuoteInfo = new QuoteInfo($node);

        if ($QuoteInfo->accessView($account)) {
          $data_row['nodes']['quote'][] = $QuoteInfo->allMethodsValue();
        }
      }
    }

    return $data_row;
  }

  /** - - - - - Term - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
  /** - - - - - Term Standard Json- - - - - - - - - - - - - - -   */
  /**
   * @return Term Array data by specify VID
   */
  public function termStandardJson($vid = NULL, $class_name = NULL) {
    if ($class_name) {
      $all_term_array = taxonomy_get_tree($vid);

      if (is_array($all_term_array)) {
        foreach ($all_term_array as $term_key => $term_row) {
          // $TermProgramInfo = new TermProgramInfo($term_row->tid);
          $TermClassInfo = new $class_name($term_row->tid);

          $output[] = $TermClassInfo->allMethodsValue();
        }
      }
    }

    return $output;
  }

  /**
   * @return array
   */
  public function termBrandData() {
    $terms = taxonomy_get_tree(2);

    /**
     * data array
     */
    $data_row = array();

    if (is_array($terms)) {
      foreach($terms as $term) {
        // table row
        $data_row[] = array(
          'termName' => $term->name,
          'termTid' => $term->tid,
        );
      }
    }

    return $data_row;
  }

  /**
   * @return Term Array data
   * category by bundle
   */
  public function termArrayData() {
    $output = NULL;

    $all_voc = taxonomy_vocabulary_get_names();
    foreach (taxonomy_vocabulary_get_names() as $voc_key => $voc_row) {

      $all_term_array = taxonomy_get_tree($voc_row->vid);
      $all_term = array();

      if (is_array($all_term_array)) {
        foreach ($all_term_array as $term_key => $term_row) {
          $all_term[$term_row->tid] = array(
            'tid'  => $term_row->tid,
            'name' => $term_row->name,
          );
        }

        $output[$voc_row->machine_name] = array(
          'vid'  => $voc_row->vid,
          'term' => $all_term,
        );
      }
    }

    return $output;
  }

  /**
   *
   * @return array
   */
  public function termClientData() {
    $TermQuery = new TermQuery();
    $all_client_tids =  $TermQuery->allClientTerms();

    $terms = taxonomy_term_load_multiple($all_client_tids);

    /**
     * json data array
     */
    $data_row = array();

    if (is_array($terms)) {
      foreach($terms as $term) {
        $TermClientInfo = new TermClientInfo($term);

        $extra_array = array(
          'link' => base_path() .  '/term/client/view/' . $TermClientInfo->termTid(),
          'linkAddUserClientManager' => base_path() .  '/term/client-action/addClientManager',
          'linkRemoveUserClientManager' => base_path() .  '/term/client-action/removeClientManager',
        );

        $data_row[] = $extra_array + ($TermClientInfo->allMethodsValue());
      }
    }

    return $data_row;
  }

  /**
   *
   * @return array
   */
  public function termContactData() {
    $data_row = NULL;
    $all_term_array = taxonomy_get_tree(5);
    /**
     * json data array
     */
    $data_row = array();

    if (is_array($all_term_array)) {
      foreach($all_term_array as $term) {
        $TermContactInfo = new TermContactInfo($term);

        $data_row[] = $TermContactInfo->allMethodsValue();
      }
    }

    return $data_row;
  }

  /** - - - - - user - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
  /**
   * @return User List data
   * category by user roles
   */
  public function userListData() {
    $output = NULL;

    foreach (entity_load('user') as $key => $row) {
      if ($key > 0) {
        if ($row->status == 1) {
          // exculde admin user
          if ($row->uid > 1) {
            $UserInfo = new UserInfo($row->uid);

            $output['users']['profile'][] = $UserInfo->allMethodsValue();
          }
        }
      }
    }

    return $output;
  }

}
