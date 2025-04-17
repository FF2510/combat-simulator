#pragma once
class Combatant;

/**
 * @brief Manages the main game loop.
 *
 * This class controls the flow of a battle between two combatants,
 * managing turn order, updating combat rounds, and displaying
 * combat information until a winner is determined.
 */
class Loop final
{
    
public:
    
    // Starts the game loop for a battle between two combatants.
    void Start(Combatant& combatantA, Combatant& combatantB);
};
