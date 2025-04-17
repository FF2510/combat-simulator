#pragma once
class Combatant;


/**
 * @brief Interface for basic combat logic.
 *
 * This interface defines the essential methods required for combat operations.
 * Classes implementing this interface should provide concrete logic for
 * executing attacks and handling incoming damage.
 */
class ICombat
{
public:
    
    virtual ~ICombat() = default;
        
    // Executes an attack on a specified combatant.
    virtual void Attack(Combatant& target) = 0;

    // Handles damage inflicted on the combatant.
    virtual void OnDamage(unsigned short amount) = 0;
};