<?php

class views_handler_relationship_product_join extends views_handler_relationship{
  function query(){
    // this converts the relationship into a product join.
    if($this->definition['disable_fk']){
      $def = $this->definition;
      $this->table_alias=$def['base'] . '_' . $this->table;
      $this->real_field=$def['base_field'];
    }
    parent::query();
  }
}