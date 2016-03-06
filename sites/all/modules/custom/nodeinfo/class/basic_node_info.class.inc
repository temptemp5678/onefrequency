<?php
/**
 * @file
 */

/**
 * class
   $NodeInfo = new NodeInfo($nid);
   $NodeInfo->nodeTitle();
 */
class NodeInfo {
  public $nid;
  public $node = NULL;

  /**
   * @parameter is nid or node object
   */
  function __construct($para){
    if (is_numeric($para)) {
      $node = node_load($para);
      if ($node) {
        $this->node = $node;
        $this->nid = $this->node->nid;
      }
    }
    else if (is_object($para)) {
      if (isset($para->nid)) {
        $this->node = $para;
        $this->nid = $this->node->nid;
      }
    }
  }
  /** - - - - - - field - - - - - - - - - - - - - - - - - - - - - - - - - -  */
  // public function entityWrapper() {
  //   $output = NULL;
  //   if (isset($this->node->nid)) {
  //     $output = entity_metadata_wrapper('node', $this->node);
  //   }
  //   return $output;
  // }
  /** - - - - - Basic Object - - - - - - - - - -  - - - - -   */
  /**
   * all Methods
   */
  protected function allMethods() {
    $methods = NULL;

    /**
     * similar with  $methods = get_class_methods($this);
     */
    $reflect = new ReflectionClass(get_class($this));
    $methods = $reflect->getMethods(ReflectionProperty::IS_PUBLIC);

    return $methods;
  }

  /**
   * all Methods with filter condition
   */
  protected function allMethodsArray() {
    $output = NULL;

    $methods = $this->allMethods();
    if (is_array($methods)) {
      foreach ($methods as $method) {
        if ($method->name != '__construct') {
          if ($method->name != 'allMethodsValue') {
            $output[] = $method->name;
          }
        }
      }
    }
    return $output;
  }

  /**
   * all Methods value
   * @return, array
     array{
       method1 => value1,
       method2 => value2,
     };
   */
  public function allMethodsValue() {
    $output = array();

    $methods = $this->allMethodsArray();
    if (is_array($methods)) {
      $row = '';
      foreach ($methods as $key => $method) {
        $row[$method] = $this->$method();
      }
      $output = $row;
    }
    return $output;
  }

  /** - - - - - Basic Property - - - - - - - - - -  - - - - -   */

  /**
   * @return String, Node Title
   */
  public function nodeNid() {
    $output = NULL;
    if (isset($this->nid)) {
      $output = $this->nid;
    }
    return $output;
  }

  /**
   * @return String, Node Title
   */
  public function nodeTitle() {
    $output = NULL;
    if (isset($this->node->title)) {
      $output = $this->node->title;
    }
    return $output;
  }

  /**
   * @return String, Node Title
   */
  public function nodeBody() {
    $output = NULL;
    if (isset($this->node->body['und'][0]['value'])) {
      $output = $this->node->body['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return String, Node Title
   */
  public function nodeUid() {
    $output = $this->node->uid;
    return $output;
  }
  /**
   * @return String,
   */
  public function nodeUidName() {
    $output = '';
    $UserInfo = new UserInfo($this->nodeUid());
    $output = $UserInfo->userName();

    return $output;
  }

  /**
   * @return String, Node type
   */
  public function nodeType() {
    $output = NULL;
    if (isset($this->node->type)) {
      $output = $this->node->type;
    }
    return $output;
  }

  /**
   * @return integer, date unix stamp for quote order time
   */
  public function createdUnixStamp() {
    $output = NULL;
    if (isset($this->node->created)) {
      $output = $this->node->created;
    }
    return $output;
  }
  /**
   * @return integer, date unix stamp
   */
  public function createdValue($format = NULL) {
    if (!$format) {
      $format = "Y-m-d";
    }

    $output = NULL;
    $stamp = $this->createdUnixStamp();
    if ($stamp) {
      $output = format_date($stamp, 'custom', $format);
    }
    return $output;
  }

  /** - - - - - - node link - - - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @return link, $this->nodeType()
   */
  public function nodeEditLink() {
    $output = base_path() . 'manage/node/edit/' . $this->nid;
    return $output;
  }
  /**
   * @return integer, date unix stamp
   */
  public function nodeViewLink() {
    $output = base_path() . $this->nodeType() . '/node/view/' . $this->nid;
    return $output;
  }
}

/**
 * class
   $OrderInfo = new OrderInfo($order_nid);
   $OrderInfo->description();
 */
class OrderInfo extends NodeInfo {
  /**
   * @return integer, date unix stamp for quote order time
   */
  public function dateUnixStamp() {
    $output = NULL;
    if (isset($this->node->field_order_date['und'][0]['value'])) {
      $output = $this->node->field_order_date['und'][0]['value'];
    }
    return $output;
  }
  /**
   * @return integer, date unix stamp
   */
  public function dateValue($format = NULL) {
    if (!$format) {
      $format = "Y-m-d";
    }

    $output = NULL;
    $stamp = $this->dateUnixStamp();
    if ($stamp) {
      $output = format_date($stamp, 'custom', $format);
    }
    return $output;
  }
}
