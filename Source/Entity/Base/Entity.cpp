#include "Entity.h"
#include <iostream>
#include <stdexcept>
#include "../Data/Stats.h"

Entity::Entity(const std::string& name, Stats* stats) : Name(name)
{
    if (stats != nullptr)
    {
        // Assign the provided stats pointer to the internal member.
        this->_stats = stats;
    }
    else
    {
        // Throw an error if an invalid (null) stats pointer is provided.
        throw std::invalid_argument("Invalid stats structure assigned to entity.");
    }
}

Entity::~Entity()
{
    if (_stats != nullptr)
    {
        // Delete the associated Stats object and reset the pointer.
        delete _stats; _stats = nullptr;
    }
}

bool Entity::AreMatchingEntities(const Entity& a, const Entity& b)
{
    return (a.Name == b.Name) || (a._stats == b._stats);
}


#pragma region Getter Methods

    unsigned short Entity::GetHealth() const
    {
        return (_stats != nullptr) ? _stats->Health : 0;
    }

    unsigned short Entity::GetDamage() const
    {
        return (_stats != nullptr) ? _stats->Damage : 0;
    }

    unsigned short Entity::GetDefense() const
    {
        return (_stats != nullptr) ? _stats->Defense : 0;
    }

    unsigned short Entity::GetSpeed() const
    {
        return (_stats != nullptr) ? _stats->Speed : 0;
    }

#pragma endregion