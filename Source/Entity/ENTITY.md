# Entity Directory


This directory contains all classes which are used to simulate different entities in the “Combat Simulator”.

- **ICombat**: The basic interface for all combat logics. Contains methods to attack and react to an attack.


- **Entity**: The base class for all entities. Contains all entity statistics and controls how this data can be accessed and edited.


- **Stats**: Structure that holds all entity stats. 


- **Combatant**: The final class for an entity equipped with the ICombat interface. Allows entities to fight each other while retaining their individual values through the entity class.