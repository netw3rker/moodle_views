<?php

class moodle_views_handler_argument_userid extends views_handler_argument {
  /**
   * Override the behavior of title(). Get the title of the node.
   */
  function title_query() {
    $titles = array();
    db_set_active('moodle');
    $result = db_query("SELECT u.id FROM {user} u WHERE u.idnumber IN (:uids)", array(':uids' => $this->value));
    foreach ($result as $term) {
      $titles[] = check_plain($term->id);
    }
    db_set_active();
    return $titles;
  }

}
