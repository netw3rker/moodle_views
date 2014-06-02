<?php

class moodle_views_handler_argument_badgeid extends views_handler_argument {
  /**
   * Override the behavior of title(). Get the title of the node.
   */
  function title_query() {
    $titles = array();
    db_set_active('moodle');
    $result = db_query("SELECT b.name FROM {badge} b WHERE b.id IN (:bids)", array(':bids' => $this->value));
    foreach ($result as $term) {
      $titles[] = check_plain($term->name);
    }
    db_set_active();
    return $titles;
  }

}
