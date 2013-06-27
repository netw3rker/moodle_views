<?php

/**
 * @file
 * Definition of SQL join class to execute a range join to find the row with the largest value smaller than the given value.
 */

/**
 * A function class to represent a join and create the SQL necessary
 * to implement the join.
 *
 * join definition
 * - table: table to join (right table)
 * - field: field to join on (right field)
 * - left_table: The table we join to
 * - left_field: The field we join to
 * - type: either LEFT (default) or INNER
 * - extra: An array of extra conditions on the join. Each condition is
 * either a string that's directly added, or an array of items:
 * - - table: If not set, current table; if NULL, no table. If you specify a
 * table in cached definition, Views will try to load from an existing
 * alias. If you use realtime joins, it works better.
 * - - field: Field or formula
 * in formulas we can reference the right table by using %alias
 *
 * @see SelectQueryInterface::addJoin() - - operator: defaults to =
 *      - - value: Must be set. If an array, operator will be defaulted to IN.
 *      - - numeric: If true, the value will not be surrounded in quotes.
 *      - - extra type: How all the extras will be combined. Either AND or OR. Defaults to AND.
 */
class moodle_views_range_join extends views_join {

  /**
   * Build the SQL for the join this object represents.
   *
   * When possible, try to use table alias instead of table names.
   *
   * @param $select_query An
   *          implementation of SelectQueryInterface.
   * @param $table The
   *          base table to join.
   * @param $view_query The
   *          source query, implementation of views_plugin_query.
   */
  function build_join($select_query, $table, $view_query) {
    if (empty($this->definition['table formula'])) {
      $right_table = $this->table;
    }
    else {
      $right_table = $this->definition['table formula'];
    }

    if ($this->left_table) {
      $left = $view_query->get_table_info($this->left_table);
      $left_field = "$left[alias].$this->left_field";
    }
    else {
      // This can be used if left_field is a formula or something. It should be used only *very* rarely.
      $left_field = $this->left_field;
    }

    $condition = "$left_field >= $table[alias].$this->field";
    $arguments = array();

    // Tack on the extra.
    if (isset($this->extra)) {
      if (is_array($this->extra)) {
        $extras = array();
        foreach ($this->extra as $info) {
          $extra = '';
          // Figure out the table name. Remember, only use aliases provided
          // if at all possible.
          $join_table = '';
          if (!array_key_exists('table', $info)) {
            $join_table = $table['alias'] . '.';
          }
          elseif (isset($info['table'])) {
            // If we're aware of a table alias for this table, use the table
            // alias instead of the table name.
            if (isset($left) && $left['table'] == $info['table']) {
              $join_table = $left['alias'] . '.';
            }
            else {
              $join_table = $info['table'] . '.';
            }
          }

          // Convert a single-valued array of values to the single-value case,
          // and transform from IN() notation to = notation
          if (is_array($info['value']) && count($info['value']) == 1) {
            if (empty($info['operator'])) {
              $operator = '=';
            }
            else {
              $operator = $info['operator'] == 'NOT IN' ? '!=' : '=';
            }
            $info['value'] = array_shift($info['value']);
          }

          if (is_array($info['value'])) {
            // With an array of values, we need multiple placeholders and the
            // 'IN' operator is implicit.
            foreach ($info['value'] as $value) {
              $placeholder_i = ':views_join_condition_' . $select_query->nextPlaceholder();
              $arguments[$placeholder_i] = $value;
            }

            $operator = !empty($info['operator']) ? $info['operator'] : 'IN';
            $placeholder = '( ' . implode(', ', array_keys($arguments)) . ' )';
          }
          else {
            // With a single value, the '=' operator is implicit.
            $operator = !empty($info['operator']) ? $info['operator'] : '=';
            $placeholder = ':views_join_condition_' . $select_query->nextPlaceholder();
            $arguments[$placeholder] = $info['value'];
          }

          $extras[] = "$join_table$info[field] $operator $placeholder";
        }

        if ($extras) {
          if (count($extras) == 1) {
            $condition .= ' AND ' . array_shift($extras);
          }
          else {
            $condition .= ' AND (' . implode(' ' . $this->extra_type . ' ', $extras) . ')';
          }
        }
      }
      elseif ($this->extra && is_string($this->extra)) {
        $condition .= " AND ($this->extra)";
      }
    }

    $select_query->addJoin($this->type, $right_table, $table['alias'], $condition, $arguments);

    // Build second join onto same table
    $select_query->addJoin('LEFT', $right_table, $table['alias'] . '2', "$table[alias].$this->field < $table[alias]2.$this->field AND $left_field >= $table[alias]2.$this->field");
    // Add requirement for NULL
    $select_query->isNull("$table[alias]2.$this->field");
  }
}