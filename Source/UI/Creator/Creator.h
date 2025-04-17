#pragma once
#include <vector>
class Combatant;

/**
 * @brief Handles the creation and registration of Combatant objects.
 *
 * The Creator class serves as both a factory and a registry for Combatant instances.
 * It enables the interactive creation of new Combatant objects via user input,
 * and it maintains an internal list of all created Combatants.
 */
class Creator final
{
    public:
        
        // Destructor that cleans up all registered Combatant objects.
        ~Creator();

        // Starts the creation process of a new Combatant.
        static Combatant& CreateNewCombatant(Creator& creator);

        // Force-deletes all registered Combatant objects.
        void ResetRegister();

    private:

        // Registers a new Combatant.
        void RegisterCombatant(Combatant* combatantPtr);
    
        // Container for all registered Combatant pointers.
        std::vector<Combatant*> _combatants;
};
