#pragma once

/**
* @brief Structure representing the attributes for an entity.
*
* The Stats structure encapsulates the core attributes used in the combat simulator,
* such as health, defense, damage, and speed. These attributes influence an entity’s
* performance during combat and are used for calculating damage, defense, and turn order.
*/
struct Stats
{
    // Constructs a new Stats object with specified combat attributes.
    Stats(const unsigned short health, const unsigned short damage, const unsigned short defense, const unsigned short speed)
        : Health(health), Defense(defense), Damage(damage), Speed(speed)
    {
        // Additional initialization logic here:
        // ...
    }

    // Members:
    unsigned short Health { 0 };
    unsigned short Defense { 0 };
    unsigned short Damage { 0 };
    unsigned short Speed { 0 };
};