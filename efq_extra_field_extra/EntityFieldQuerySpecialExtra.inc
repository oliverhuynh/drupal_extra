<?php

class EntityFieldQuerySpecialExtra extends EntityFieldQueryExtraFields {
  private $_customWhere = array();
  public function customWhere($snippet, $args = array()) {
    $this->_customWhere[] = func_get_args();
    return $this;
  }
  function finishQuery($select_query, $id_key = 'entity_id') {
    foreach ($this->_customWhere as $item) {
      list ($snippet, $args) = $item;
      $select_query->where($snippet, $args);
    }
    return parent::finishQuery($select_query, $id_key);
  }
}
