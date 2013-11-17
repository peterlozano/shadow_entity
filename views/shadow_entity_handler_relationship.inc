<?php

/**
 * @file
 * Description of the file goes here.
 */

class shadow_entity_handler_relationship extends views_handler_relationship {

  function init(&$view, &$options) {
    dpm("shadow entity rel handler init");
    parent::init($view, $options);
  }

}
