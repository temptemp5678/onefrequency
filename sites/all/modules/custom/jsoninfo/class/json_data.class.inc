<?php
/**
 * class
   $JsonDataUnit = new JsonDataUnit();
   $JsonDataUnit->termCityJsonFile();
 *
 */
class JsonDataUnit {

  /** - - - - - Node Json- - - - - - - - - - - - - - - */
  /**
   *
   * @return array
   */
  public function nodeRecordLogBasicValues() {
    $NodeQuery = new NodeQuery();
    $node_nids = $NodeQuery->nodesByBundles(array('record_log'));

    $nodes = node_load_multiple($node_nids);

    /**
     * data row array
     */
    $data_row = array();
    $data_row['nodes'] = array();

    if (is_array($nodes)) {
      // foreach($nodes as $key => $node) {
      //   if ($key > 2000) {
      //     break;
      //   }

      //   $RecordLogInfo = new RecordLogInfo($node);
      //   $data_row['nodes']['recordLog'][] = array(
      //     'timeNs' => $RecordLogInfo->timeNs(),
      //     'velocity1' => $RecordLogInfo->velocity1(),
      //     'velocity2' => $RecordLogInfo->velocity2(),
      //   );
      // }

      for ($x = 900; $x <= 1000; $x++) {
        $RecordLogInfo = new RecordLogInfo($nodes[$x]);
        $data_row['nodes']['recordLog'][] = array(
          'timeNs' => $RecordLogInfo->timeNs(),
          'velocity1' => $RecordLogInfo->velocity1(),
          'velocity2' => $RecordLogInfo->velocity2(),
        );
      }
    }

    return $data_row;
  }

  /** - - - - - Term Standard Json- - - - - - - - - - - - - - - - - - - - - - */
  /**
   * @return Term Array data
   */
  public function pushDefaultValue($import_array = NULL, $default_value = array()) {
    $output = NULL;
    if (is_array($import_array)) {
      $output = array_merge(array($default_value), $import_array);
    }
    return $output;
  }

  /** - - - - - Term Standard Json- - - - - - - - - - - - - - - - - - - - - - */
  /**
   * @return Term Array data by specify VID
   */
  public function termStandardJson($vid = NULL, $class_name = NULL, $basic = NULL) {
    if ($class_name) {
      $all_term_array = taxonomy_get_tree($vid);

      if (is_array($all_term_array)) {
        foreach ($all_term_array as $term_key => $term_row) {
          // $TermProgramInfo = new TermProgramInfo($term_row->tid);
          $TermClassInfo = new $class_name($term_row->tid);

          if ($basic) {
            $output[] = $TermClassInfo->basicMethodsValue();
          }
          else {
            $output[] = $TermClassInfo->allMethodsValue();
          }
        }
      }
    }

    return $output;
  }

  /** - - - - - Term - - - - - - - - - - - - - - - */
  /**
   * @return Term Array data
   */
  public function termBrand($basic = NULL) {
    $output = $this->termStandardJson(19, 'TermBrandInfo', $basic);
    return $output;
  }

  /**
   * @return Term Array data
   */
  public function termTable($vid = NULL) {
    $terms = taxonomy_get_tree(7);
    if (is_array($terms)) {
      foreach ($terms as $tid) {
        $TermCompanyInfo = new TermCompanyInfo($tid);

        $output[] = array(
          'companyTitle' => $TermCompanyInfo->companyTitle(),
          'address' => $TermCompanyInfo->address(),
          'termEditLink' => $TermCompanyInfo->termEditLink(),
        );
      }
    }
    return $output;
  }

  /** - - - - - User - - - - - - -- - - - - - - - - - - - - - - - - - - -   */
  /**
   * @return Term Array data
   */
  public function userBasicInfo($uids = NULL) {
    $output = NULL;

    if (is_array($uids)) {
      foreach ($uids as $uid) {
        $UserInfo = new UserInfo($uid);
        $output[] = $UserInfo->basicMethodsValue();
      }
    }

    return $output;
  }
  /**
   * @return Term Array data
   */
  public function userFullInfo($uids = NULL) {
    $output = NULL;

    if (is_array($uids)) {
      foreach ($uids as $uid) {
        $UserInfo = new UserInfo($uid);
        $output[] = $UserInfo->allMethodsValue();
      }
    }

    return $output;
  }
  /**
   * @return Term Array data
   */
  public function allUserList() {
    $output = NULL;

    $UserQuery = new UserQuery();
    $uids = $UserQuery->allUserUid();

    $output = $this->userBasicInfo($uids);

    return $output;
  }
}

/**
 * class
   $JsonData = new JsonData();
   $JsonData->sourceArrayData();
 *
 */
class JsonData extends JsonDataUnit  {
  /** - - - - - - node - - - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @return Array data
   * for current user
   */
  public function jsonNodeRecordLogBasicValues() {
    $output = $this->nodeRecordLogBasicValues();
    return $output;
  }

  /** - - - - - - term - - - - - - - - - - - - - - - - - - - - - - - -  */

  /**
   * @return Term Array data
   */
  // public function jsonTermTable($vid = NULL) {
  //   $output = $this->termTable($vid);
  //   return $output;
  // }

  /** - - - - - - user - - - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @return Array data
   */
  // public function jsonUserList() {
  //   $output = NULL;

  //   $output['userList'] = $this->allUserList();
  //   $output['termBusinessUnit'] = $this->termBusinessUnit();
  //   $output['termCity'] = $this->termCityArrayFile();
  //   $output['termProvince'] = $this->termProvince();
  //   $output['termTherapeuticArea'] = $this->termTherapeuticArea();

  //   return $output;
  // }

}
