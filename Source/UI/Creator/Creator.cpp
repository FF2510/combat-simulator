#include "Creator.h"
#include <iostream>
#include <ostream>
#include "../../UI/Log/Logger.h"
#include "../../Entity/Combatant.h"
#include "../../Core/Input/Input.h"



Creator::~Creator()
{
    ResetRegister();
}

Combatant& Creator::CreateNewCombatant(Creator& creator)
{
    CLEAR_CONSOLE(); // Clear console at the start of the creation process.

    // Display welcome message.
    std::cout << "This is the " << Logger::AnsiString("Combatant Creator", TEXTSTYLE_BOLD, TEXTCOLOR_YELLOW)
              << "! Please press '" << Logger::AnsiString("ENTER", TEXTSTYLE_BOLD, TEXTCOLOR_CYAN)
              << "' to create a new combatant ..." << std::endl;

    std::cin.get();
    CLEAR_CONSOLE();

    // Get inputs for the new Combatant's attributes.
    auto name = Input::GetInputAs<std::string>("Please enter the new combatant's " + Logger::AnsiString("Name", TEXTSTYLE_BOLD, TEXTCOLOR_CYAN) + ":"); CLEAR_CONSOLE();
    auto health = Input::GetInputAs<unsigned short>("Please enter the combatant's " + Logger::AnsiString("Health", TEXTSTYLE_BOLD, TEXTCOLOR_CYAN) + ":"); CLEAR_CONSOLE();
    auto defense = Input::GetInputAs<unsigned short>("Please enter the combatant's " + Logger::AnsiString("Defense", TEXTSTYLE_BOLD, TEXTCOLOR_CYAN) + ":"); CLEAR_CONSOLE();
    auto damage = Input::GetInputAs<unsigned short>("Please enter the combatant's " + Logger::AnsiString("Damage", TEXTSTYLE_BOLD, TEXTCOLOR_CYAN) + ":"); CLEAR_CONSOLE();
    auto speed = Input::GetInputAs<unsigned short>("Please enter the combatant's " + Logger::AnsiString("Speed", TEXTSTYLE_BOLD, TEXTCOLOR_CYAN) + ":"); CLEAR_CONSOLE();

    // Display the selected combatant statistics.
    Logger::PrintCombatantStats(name, health, defense, damage, speed, false, false);

    // Ask if the user accepts the created combatant.
    bool accept = Input::GetInputAs<bool>("\nAre you sure you want to create " +
                    Logger::AnsiString(name, TEXTSTYLE_BLINK, TEXTCOLOR_GREEN) +
                    " as a new combatant? " + Logger::AnsiString("(yes / no) \n", TEXTSTYLE_BLINK, TEXTCOLOR_YELLOW));

    if (accept)
    {
        // Create and register the new Combatant.
        Combatant* combatant = new Combatant(name, health, defense, damage, speed);
        creator.RegisterCombatant(combatant);
        
        // Return a reference to the newly created Combatant.
        return *combatant;
    }
    
    // If the user did not accept, clear the console and restart the creation process.
    CLEAR_CONSOLE();
    return CreateNewCombatant(creator);
}

void Creator::ResetRegister()
{
    for (auto combatant : _combatants)
    {
        // Delete the Combatant and reset the pointer.
        delete combatant;
        combatant = nullptr;
    }
    _combatants.clear();
}

void Creator::RegisterCombatant(Combatant* combatantPtr)
{
    if (combatantPtr != nullptr)
    {
        _combatants.push_back(combatantPtr);
    }
}


