<?php

/**
 * @file
 * CKEditor integration for the entity_embed module.
 */

/**
 * Implements hook_ckeditor_plugin().
 */
function entity_embed_ckeditor_plugin() {
  $plugins = array(
    'drupalentity' => array(
      'name' => 'drupalentity',
      'desc' => t('Plugin for embedding entities'),
      'path' => base_path() . drupal_get_path('module', 'entity_embed') . '/js/plugins/drupalentity/',
      'default' => 'f',
    ),
  );

  // Add user-defined buttons.
  ctools_include('export');

  $embed_buttons = ctools_export_crud_load_all('entity_embed');

  $buttons = array();

  foreach ($embed_buttons as $embed_button) {
    // CKEditor only supports icons relative to the plugin path.
    // @todo: Figure out how to support custom icons.
    $buttons[$embed_button->name] = array(
      'label' => check_plain($embed_button->button_label),
      'icon' => 'entity.png',
    );
  }

  $plugins['drupalentity']['buttons'] = $buttons;

  return $plugins;
}
