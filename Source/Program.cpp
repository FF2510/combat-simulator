#include <iostream>
#include <thread>

#include "Core/Loop/Loop.h"
#include "Entity/Base/Entity.h"
#include "UI/Creator/Creator.h"
#include "UI/Log/Logger.h"

int main()
{
    // Display welcome message to the user.
    std::cout << "Welcome to the "
              << Logger::AnsiString("Combat Simulator", TEXTSTYLE_BOLD, TEXTCOLOR_YELLOW)
              << "!" 
              << "\nPress '"
              << Logger::AnsiString("ENTER", TEXTSTYLE_BOLD, TEXTCOLOR_CYAN)
              << "' to create your combatants ...";
    std::cin.get();

    // Create a Creator instance for registering new combatants.
    Creator creator;
    Combatant* combatant_a = nullptr;
    Combatant* combatant_b = nullptr;

    // Loop until two distinct combatants are created.
    while (true)
    {
        // Create two new combatants using the user creation menu.
        combatant_a = &Creator::CreateNewCombatant(creator);
        combatant_b = &Creator::CreateNewCombatant(creator);

        // Check if the two created combatants are identical.
        if (Entity::AreMatchingEntities(*combatant_a, *combatant_b))
        {
            // Inform the user that two matching combatants were created and prompt to retry.
            for (int i = 3; i > 0; i--)
            {
                creator.ResetRegister(); // Remove all created combatants.
                
                system("cls");
                std::cout << Logger::AnsiString("You created two matching combatants. Try again in " + std::to_string(i) + " ...", TEXTSTYLE_BLINK, TEXTCOLOR_RED);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // https://en.cppreference.com/w/cpp/thread/sleep_for
            }
            continue;
        }
        break;
    }

    // Start the game loop with the two valid combatants.
    Loop loop;
    loop.Start(*combatant_a, *combatant_b);

    // Reset pointers (actual deletion is handled within the Creator).
    combatant_a = nullptr;
    combatant_b = nullptr;

    return 0;
}
