#pragma once
#include <string>
struct Stats;

/**
 * @brief Base class for all entities participating in the combat simulator.
 *
 * The Entity class provides the foundation for various in-game characters or objects
 * that engage in combat. Every entity has a unique name and is associated with a set
 * of statistical attributes (e.g., health, damage, defense, and speed), which determine
 * its capabilities in combat. Using this base class ensures consistent handling
 * of all entities within the simulator, promoting extensibility and code reuse.
 */
class Entity
{
    public:

        // Constructs a new Entity object.
        Entity(const std::string& name, Stats* stats);
    
        // Virtual destructor ensuring proper cleanup of resources.
        virtual ~Entity();
    
        // The unique name identifying the entity.
        const std::string Name;
    
        // Retrieves the current health value of the entity.
        unsigned short GetHealth() const;

        // Retrieves the damage attribute of the entity.
        unsigned short GetDamage() const;

        // Retrieves the defense attribute of the entity.
        unsigned short GetDefense() const;

        // Retrieves the speed attribute of the entity.
        unsigned short GetSpeed() const;

        // Compares two entities to determine if they are matching.
        static bool AreMatchingEntities(const Entity& a, const Entity& b);


    protected:

        // Pointer to the entity's stats structure.
        Stats* _stats{};
};
