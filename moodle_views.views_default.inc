<?php

/**
 * @file
 * Definition of default Views provided by the moodle_views module.
 */

/**
 * Implements hook_views_default_views().
 */
function moodle_views_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'moodle_views_moodle_users';
  $view->description = 'Administrator list of Moodle users';
  $view->tag = 'default';
  $view->base_table = 'user';
  $view->human_name = 'Moodle users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Moodle users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'username' => 'username',
    'email' => 'email',
    'firstname' => 'firstname',
    'lastname' => 'lastname',
    'city' => 'city',
    'country' => 'country',
    'lastaccess' => 'lastaccess'
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'username' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'firstname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'lastname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'lastaccess' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    )
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Moodle User: User ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'user';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Moodle User: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'user';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['link_to_user'] = TRUE;
  /* Field: Moodle User: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'user';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  /* Field: Moodle User: First name */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'user';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  /* Field: Moodle User: Last name */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'user';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  /* Field: Moodle User: City/Town */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'user';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  /* Field: Moodle User: Country */
  $handler->display->display_options['fields']['country']['id'] = 'country';
  $handler->display->display_options['fields']['country']['table'] = 'user';
  $handler->display->display_options['fields']['country']['field'] = 'country';
  /* Field: Moodle User: Last access time */
  $handler->display->display_options['fields']['lastaccess']['id'] = 'lastaccess';
  $handler->display->display_options['fields']['lastaccess']['table'] = 'user';
  $handler->display->display_options['fields']['lastaccess']['field'] = 'lastaccess';
  $handler->display->display_options['fields']['lastaccess']['date_format'] = 'short';
  /* Sort criterion: Moodle User: User ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'user';
  $handler->display->display_options['sorts']['id']['field'] = 'id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/moodle-users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Moodle users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'moodle_views_moodle_courses';
  $view->description = 'Administrator list of Moodle courses';
  $view->tag = 'default';
  $view->base_table = 'course';
  $view->human_name = 'Moodle courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Moodle courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'fullname' => 'fullname',
    'name' => 'name'
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'fullname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    )
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Moodle Course: Course ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'course';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Moodle Course: Course Title */
  $handler->display->display_options['fields']['fullname']['id'] = 'fullname';
  $handler->display->display_options['fields']['fullname']['table'] = 'course';
  $handler->display->display_options['fields']['fullname']['field'] = 'fullname';
  $handler->display->display_options['fields']['fullname']['link_to_course'] = TRUE;
  /* Field: Moodle Course: Category */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'course_categories';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['link_to_category'] = TRUE;
  /* Sort criterion: Moodle Course: Course ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'course';
  $handler->display->display_options['sorts']['id']['field'] = 'id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/moodle-courses';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Moodle courses';
  $handler->display->display_options['menu']['name'] = 'management';

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'my_courses';
  $view->description = 'List the courses a user is enrolled on on their account page. Requires EVA module to work.';
  $view->tag = 'default';
  $view->base_table = 'course';
  $view->human_name = 'My Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'fullname' => 'fullname',
    'timestart' => 'timestart'
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'fullname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    ),
    'timestart' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0
    )
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>You aren\'t enroled on any courses yet. When you are, they will be listed here.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Moodle Course: Course Title */
  $handler->display->display_options['fields']['fullname']['id'] = 'fullname';
  $handler->display->display_options['fields']['fullname']['table'] = 'course';
  $handler->display->display_options['fields']['fullname']['field'] = 'fullname';
  $handler->display->display_options['fields']['fullname']['link_to_course'] = TRUE;
  /* Field: Moodle User-enrolement: User-enrolment start time */
  $handler->display->display_options['fields']['timestart']['id'] = 'timestart';
  $handler->display->display_options['fields']['timestart']['table'] = 'user_enrolments';
  $handler->display->display_options['fields']['timestart']['field'] = 'timestart';
  $handler->display->display_options['fields']['timestart']['label'] = 'Enrolled';
  $handler->display->display_options['fields']['timestart']['date_format'] = 'long';
  /* Contextual filter: Moodle User: Username */
  $handler->display->display_options['arguments']['username']['id'] = 'username';
  $handler->display->display_options['arguments']['username']['table'] = 'user';
  $handler->display->display_options['arguments']['username']['field'] = 'username';
  $handler->display->display_options['arguments']['username']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['username']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['username']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['username']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['username']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['username']['limit'] = '0';

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_1');
  $handler->display->display_options['entity_type'] = 'user';
  $handler->display->display_options['bundles'] = array(
    0 => 'user'
  );
  $handler->display->display_options['argument_mode'] = 'token';
  $handler->display->display_options['default_argument'] = '[user:name]';
  $handler->display->display_options['show_title'] = 1;

  $views[$view->name] = $view;

  return $views;
}