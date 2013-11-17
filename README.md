Shadow Entity Drupal Module
===========================

NOTE: This module is still under heave development and it is not recommended to
be used in real sites.

This Drupal module allows to automatically make copies of Drupal entities when
they are created. The copies can be of a different entity type.

 * You want a node created for every taxonomy term. You can setup the module so
   that every time a term is created in a given vocabulary a node of a
   determined content type will be created with the same label (aka: title,
   term name, etc).
 * This can be useful when you have a site built a type of entity that is
   usefull for some functionality but you need to have the same structure built
   using a different kind of entity required by some other functionality.
