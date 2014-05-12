<?php
define(MOODLE_VIEWS_VISIBLE,  1);
define(MOODLE_VIEWS_INVISIBLE,2);
define(MOODLE_VIEWS_EXPIRED,  3);
define(MOODLE_VIEWS_VALID,    4);

class views_handler_relationship_badges_issued extends views_handler_relationship{
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['qualificationparams']=array(
      '#type'=>'checkboxes',
      '#title'=>"Only join issued badges of type",
      '#help' => "Use these when you need to see badges or users that may not have badges issued based on these criteria",
      '#options'=>array(
        MOODLE_VIEWS_VISIBLE => 'Visible',
        MOODLE_VIEWS_INVISIBLE => 'Invisible',
        MOODLE_VIEWS_EXPIRED => 'Expired',
        MOODLE_VIEWS_VALID => 'Valid',
      ),
      '#default_value' => $this->options['qualificationparams'],
    );
  }
  function option_definition() {
    $options = parent::option_definition();
    $options['qualificationparams'] = array('default' => array(), 'bool' => TRUE);;

    return $options;
  }

  function query(){
    $alias = $this->definition['base'] . '_' . $this->table;
    if($this->options['qualificationparams'][MOODLE_VIEWS_VISIBLE] == MOODLE_VIEWS_VISIBLE){
      $this->definition['extra'][]="$alias.visible = 1";
    }
    if($this->options['qualificationparams'][MOODLE_VIEWS_INVISIBLE] == MOODLE_VIEWS_INVISIBLE){
      $this->definition['extra'][]="$alias.visible = 0";
    }
    if($this->options['qualificationparams'][MOODLE_VIEWS_EXPIRED] == MOODLE_VIEWS_EXPIRED){
      $this->definition['extra'][]="$alias.dateexpire <= ".strtotime('now');
    }
    if($this->options['qualificationparams'][MOODLE_VIEWS_VALID] == MOODLE_VIEWS_VALID){
      $this->definition['extra'][]="$alias.dateexpire > ".strtotime('now');
    }
    $this->definition['extra']=implode($this->definition['extra'], " AND ");

    parent::query();
  }
}