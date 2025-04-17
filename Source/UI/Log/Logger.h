#pragma once
#include <string>
class Combatant;

#pragma region LOGGER_MACROS

    // ANSI Styles:
    #define TEXTSTYLE_RESET "0"
    #define TEXTSTYLE_BOLD "1"
    #define TEXTSTYLE_UNDERLINE "4"
    #define TEXTSTYLE_BLINK "5"
    #define TEXTSTYLE_INVERSE "6"

    // ANSI Colors: 
    #define TEXTCOLOR_BLACK "30"
    #define TEXTCOLOR_RED "31"
    #define TEXTCOLOR_GREEN "32"
    #define TEXTCOLOR_YELLOW "33"
    #define TEXTCOLOR_BLUE "34"
    #define TEXTCOLOR_MAGENTA "35"
    #define TEXTCOLOR_CYAN "36"
    #define TEXTCOLOR_WHITE "37"

    // ANSI Backgrounds:
    #define TEXTBACKGROUND_BLACK "40"
    #define TEXTBACKGROUND_RED "41"
    #define TEXTBACKGROUND_GREEN "42"
    #define TEXTBACKGROUND_YELLOW "43"
    #define TEXTBACKGROUND_BLUE "44"
    #define TEXTBACKGROUND_MAGENTA "45"
    #define TEXTBACKGROUND_CYAN "46"
    #define TEXTBACKGROUND_WHITE "47"
    #define TEXTBACKGROUND_NONE ""

    
    // Multi-Platform console clear:
    #ifdef _WIN32
        #define CLEAR_CONSOLE() system("cls")
    #else
        #define CLEAR_CONSOLE() system("clear")
    #endif

#pragma endregion


/**
 * @brief Provides logging and display utilities for the combat simulator.
 *
 * The Logger class includes functions to format strings using ANSI escape codes,
 * print combatant statistics, and log combat rounds and combat actions.
 */
class Logger final
{
public:

    // Formats a string using ANSI escape codes.
    static std::string AnsiString(std::string str, std::string styleFormat = "", std::string colorFormat = "", std::string backgroundColorFormat = "");

    // Prints the stats of a combatant.
    static void PrintCombatantStats(const Combatant& combatant, bool bDisplayName, bool bInLine);

    // Logs information about a combat round to the console.
    static void LogCombatRoundInfo(Combatant& combatantA, Combatant& combatantB, unsigned short round, bool bClear = true);

    // Logs a combat action to the console.
    static void LogCombatAction(Combatant& agressor, Combatant& target, bool bClear = true);
};
