<?php

/**
 * @file
 * Description of the file goes here.
 */

/**
 * Implements hook_views_data().
 */
function shadow_entity_views_data() {
  $data['shadow_entity']['table']['group'] = t('Shadow entity');

    $data['shadow_entity']['source_entity_id'] = array(
      'title' => t('Source entity id'),
      'help' => t('The source entity id'),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
    );

  // TODO: Generalize to use the configs
    $data['shadow_entity']['tag_to_node_source_entity_id'] = array(
      'title' => t('Source entity id'),
      'help' => t('The source entity id'),
      'relationship' => array(
        'title' => t('Source entity'),
        'help' => t('Source entity relationship'),
        'handler' => 'views_handler_relationship',

        'field' => 'source_entity_id',

        'base' => 'taxonomy_term_data',
        'left field' => 'tid',
        'label' => t('Source term'),
      ),
    );

    $data['shadow_entity']['dest_entity_id'] = array(
      'title' => t('Destination entity id'),
      'help' => t('The destination entity id'),
      'relationship' => array(
        'title' => t('Destination entity'),
        'help' => t('Destination entity relationship'),
        'handler' => 'views_handler_relationship',
        'base' => 'node',
        'left field' => 'nid',
        'label' => t('Destination node'),
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
    );
  // TODO: Strip the relationship out of the dest entity ^^^
  //       and generalize too

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function shadow_entity_views_data_alter(&$data) {
  // TODO: Generalize the addition of relationship fields to the tables

  $data['taxonomy_term_data']['tag_to_node'] = array(
    'title' => t('Tag To Node'),
    'help' => t('Tag To Node Shadowed entity'),
    'relationship' => array(
      'title' => t('Tag to Node Destination entity'),
      'help' => t('Tag to Node Destination entity relationship'),
      'label' => t('Tag To Node Destination node'),

      'handler' => 'shadow_entity_handler_relationship',

      'field table' => 'shadow_entity',
      'field' => 'source_entity_id',
      'base' => 'shadow_entity',
      'base field' => 'source_entity_id',

      // Specific to the relationship
      'relationship field' => 'tid',
    ),
  );

  $data['node']['tag_to_node'] = array(
    'title' => t('Tag To Node'),
    'help' => t('Tag To Node Source entity'),
    'relationship' => array(
      'title' => t('Tag to Node Source entity'),
      'help' => t('Tag to Node Source entity relationship'),
      'label' => t('Tag To Node Source node'),

      'handler' => 'shadow_entity_handler_relationship',

      'field table' => 'shadow_entity',
      'field' => 'dest_entity_id',
      'base' => 'shadow_entity',
      'base field' => 'dest_entity_id',

      // Specific to the relationship
      'relationship field' => 'nid',
    ),
  );
}
