#include "Loop.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <windows.h>
#include "../../Entity/Combatant.h"
#include "../../UI/Log/Logger.h"

// Runs the battle game loop between two combatants.
void Loop::Start(Combatant& combatantA, Combatant& combatantB)
{
    // Determine the combatant who takes the first turn based on speed.
    Combatant* turnCombatant = (combatantA.GetSpeed() > combatantB.GetSpeed()) ? &combatantA : &combatantB;
    unsigned short rounds = 0;
    
    // Continue the loop while both combatants are still alive.
    while (combatantA.bIsAlive() && combatantB.bIsAlive())
    {
        if (turnCombatant != nullptr)
        {
            rounds++;
            Logger::LogCombatRoundInfo(combatantA, combatantB, rounds);
            std::cout << "\n";
            
            // Execute the attack based on the current turn.
            if (Entity::AreMatchingEntities(combatantA, *turnCombatant))
            {
                combatantA.Attack(combatantB);
                Logger::LogCombatAction(*turnCombatant, combatantB, false);
                turnCombatant = &combatantB;
            }
            else if (Entity::AreMatchingEntities(combatantB, *turnCombatant))
            {
                combatantB.Attack(combatantA);
                Logger::LogCombatAction(*turnCombatant, combatantA, false);
                turnCombatant = &combatantA;
            }

            std::cout << std::endl << std::endl;
            
            // Display the current statistics of both combatants.
            Logger::PrintCombatantStats(combatantA, true, true);
            std::cout << std::endl;
            Logger::PrintCombatantStats(combatantB, true, true);
            std::cout << std::endl;
            
            std::this_thread::sleep_for(std::chrono::milliseconds(2500)); // https://en.cppreference.com/w/cpp/thread/sleep_for
            continue;
        }
        
        break;
    }

    // Determine the winning combatant.
    turnCombatant = combatantA.bIsAlive() ? &combatantA : &combatantB;
    CLEAR_CONSOLE();

    // Announce the winner and prompt the user to exit the application.
    std::cout << "And the Winner is " 
              << Logger::AnsiString(turnCombatant->Name, TEXTSTYLE_BLINK, TEXTCOLOR_YELLOW) 
              << "! \n\nPress '" 
              << Logger::AnsiString("ENTER", TEXTSTYLE_BLINK, TEXTCOLOR_CYAN)
              << "' to close the application ...";
    std::cin.get();
}
