<?php

class EntityFieldQuerySpecialExtra extends EntityFieldQueryExtraFields {
  private $_customWhere = array();
  public function customWhere($snippet, $args = array()) {
    $this->_customWhere[] = func_get_args() + array("", array());
    return $this;
  }
  private $_customExpression = array();
  public function addExpression($expression, $alias = NULL, $arguments = array()) {
    $this->_customExpression[] = func_get_args() + array("", NULL, array());
    return $this;
  }
  private $_orderBy = array();
  public function orderBy($field, $direction = 'ASC') {
    $this->_orderBy[] = func_get_args() + array("", "ASC");
    return $this;
  }
  function finishQuery($select_query, $id_key = 'entity_id') {
    foreach ($this->_customWhere as $item) {
      list ($snippet, $args) = $item;
      $select_query->where($snippet, $args);
    }
    foreach ($this->_customExpression as $item) {
      list ($expression, $alias, $arguments) = $item;
      $select_query->addExpression($expression, $alias, $arguments);
    }
    foreach ($this->_orderBy as $item) {
      list ($field, $direction) = $item;
      $select_query->orderBy($field, $direction);
    }
    return parent::finishQuery($select_query, $id_key);
  }
}
