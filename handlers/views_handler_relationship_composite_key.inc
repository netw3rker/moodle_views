<?php
/**
 * the goal of this class is to provide a relationship that depends on two relationships.
 *
 * the example query would be:
 *
 * table1
 * inner join table2 on table1.pk=table2.fk
 * left join table3 on table1.pk=table3.pk AND table2.ck1=table3.ck2
 *
 * steps to achieve this:
 * 1) determine initial FK fields to ask relationship usage
 * 2) validate which relationships allow this to be possible before prompting
 *
 */
class views_handler_relationship_composite_key extends views_handler_relationship{
  function option_definition(){
    $options = parent::option_definition();
    $options['keys']=array('default'=> 0);
    return $options;
  }

  function options_form(&$form, &$form_state){
    parent::options_form($form, $form_state);
    $relationships = $this->view->display_handler->get_option('relationships');
    $options['none']="Do not use a relationship";
    foreach($relationships as $id=>$value){
      $options[$id]=$value['label'];
    }
    if($this->definition['extra keys']){
      $form['keys']=array(
        '#type'=>'fieldset',
        '#title'=>"Extra keys to map to relationships",
      );

      foreach($this->definition['extra keys'] as $key){
        $form['keys'][$key]=array(
          '#type'=>'select',
          '#title'=>t("relationship for %key", array('%key'=>$key)),
          '#options'=>$options,
          '#default_value'=>$this->options['keys'][$key],
        );
      }

    }
  }

  function query(){
    $def = $this->definition;
    $relationships = $this->view->display_handler->get_option('relationships');

    $alias=$def['base'] . '_' . $this->table;

    foreach($this->definition['extra keys'] as $key){
      if($this->options['keys'][$key] <> 'none'){
        $key_table=$this->view->relationship[$this->options['keys'][$key]]->table_alias;
      }
      else{
        $key_table=$this->table;
      }
      $this->definition['extra'][]=array(
        'table'=>'badge_user',
        'operator'=>'formula',
        'value'=>array(),
        'field'=>"{$key_table}.{$def['real field']}={$alias}.$key",
      );
    }

    parent::query();
  }
}