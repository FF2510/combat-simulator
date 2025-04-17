#include "Logger.h"
#include <iostream>
#include <vector>
#include "../../Entity/Combatant.h"


std::string Logger::AnsiString(std::string str, std::string styleFormat, std::string colorFormat, std::string backgroundColorFormat)
{
    if (str.empty()) // Return empty string if input is empty.
        return std::string("");

    // Assemble an array of active ANSI codes.
    std::vector<std::string> inputCodes;
    if (!styleFormat.empty()) inputCodes.push_back(styleFormat);
    if (!colorFormat.empty()) inputCodes.push_back(colorFormat);
    if (!backgroundColorFormat.empty()) inputCodes.push_back(backgroundColorFormat);

    // Concatenate the ANSI codes into one code string.
    std::string code;
    for (size_t i = 0; i < inputCodes.size(); i++)
    {
        if (i == 0)
            code += inputCodes[i];
        else
            code += (";" + inputCodes[i]);
    }

    // Return the string wrapped in ANSI escape codes.
    return "\033[" + code + "m" + str + "\033[0m";
}

void Logger::PrintCombatantStats(const Combatant& combatant, bool bDisplayName, bool bInLine)
{
    if (bInLine)
    {
        // Print stats in a single line.
        if (bDisplayName)
            std::cout << AnsiString(combatant.Name, TEXTSTYLE_BLINK, TEXTCOLOR_WHITE) + " -> ";
        std::cout << AnsiString(std::to_string(combatant.GetHealth()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_GREEN) + " | ";
        std::cout << AnsiString(std::to_string(combatant.GetDefense()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_CYAN) + " | ";
        std::cout << AnsiString(std::to_string(combatant.GetDamage()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_RED) + " | ";
        std::cout << AnsiString(std::to_string(combatant.GetSpeed()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_YELLOW) + " | ";
    }
    else
    {
        // Print each stat on a separate line.
        if (bDisplayName)
            std::cout << AnsiString(combatant.Name, TEXTSTYLE_BLINK, TEXTCOLOR_WHITE) + ":\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Health -> " + AnsiString(std::to_string(combatant.GetHealth()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_GREEN) + "\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Defense -> " + AnsiString(std::to_string(combatant.GetDefense()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_CYAN) + "\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Damage -> " + AnsiString(std::to_string(combatant.GetDamage()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_RED) + "\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Speed -> " + AnsiString(std::to_string(combatant.GetSpeed()), TEXTSTYLE_UNDERLINE, TEXTCOLOR_YELLOW) + "\n";
    }
}

void Logger::PrintCombatantStats(std::string name, const unsigned short& health, const unsigned short& defense,
    const unsigned short& damage, const unsigned short& speed, bool bDisplayName, bool bInLine)
{
    if (bInLine)
    {
        // Print stats in one line.
        if (bDisplayName)
            std::cout << AnsiString(name, TEXTSTYLE_BLINK, TEXTCOLOR_WHITE) + " -> ";
        std::cout << AnsiString(std::to_string(health), TEXTSTYLE_UNDERLINE, TEXTCOLOR_GREEN) + " | ";
        std::cout << AnsiString(std::to_string(defense), TEXTSTYLE_UNDERLINE, TEXTCOLOR_CYAN) + " | ";
        std::cout << AnsiString(std::to_string(damage), TEXTSTYLE_UNDERLINE, TEXTCOLOR_RED) + " | ";
        std::cout << AnsiString(std::to_string(speed), TEXTSTYLE_UNDERLINE, TEXTCOLOR_YELLOW) + " | ";
    }
    else
    {
        // Print stats over multiple lines.
        if (bDisplayName)
            std::cout << AnsiString(name, TEXTSTYLE_BLINK, TEXTCOLOR_WHITE) + ":\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Health -> " + AnsiString(std::to_string(health), TEXTSTYLE_UNDERLINE, TEXTCOLOR_GREEN) + "\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Defense -> " + AnsiString(std::to_string(defense), TEXTSTYLE_UNDERLINE, TEXTCOLOR_CYAN) + "\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Damage -> " + AnsiString(std::to_string(damage), TEXTSTYLE_UNDERLINE, TEXTCOLOR_RED) + "\n";
        std::cout << AnsiString(" > ", TEXTSTYLE_BLINK) + "Speed -> " + AnsiString(std::to_string(speed), TEXTSTYLE_UNDERLINE, TEXTCOLOR_YELLOW) + "\n";
    }
}

void Logger::LogCombatRoundInfo(Combatant& combatantA, Combatant& combatantB, unsigned short round, bool bClear)
{
    if (bClear)
    {
        CLEAR_CONSOLE();
    }

    std::cout << AnsiString(combatantA.Name, TEXTSTYLE_BOLD, TEXTCOLOR_GREEN)
              << AnsiString(" VS. ", TEXTSTYLE_BOLD, TEXTCOLOR_RED)
              << AnsiString(combatantB.Name, TEXTSTYLE_BOLD, TEXTCOLOR_GREEN)
              << " | " << AnsiString("Round: " + std::to_string(round), TEXTSTYLE_BOLD, TEXTCOLOR_YELLOW) 
              << std::endl;
}

void Logger::LogCombatAction(Combatant& agressor, Combatant& target, bool bClear)
{
    if (bClear)
    {
        CLEAR_CONSOLE();
    }
            
    std::cout << "New Combat Action -> " 
              << AnsiString(agressor.Name, TEXTSTYLE_UNDERLINE, TEXTCOLOR_GREEN)
              << " attacked "
              << AnsiString(target.Name, TEXTSTYLE_UNDERLINE, TEXTCOLOR_GREEN)
              << " (" << AnsiString(std::to_string(agressor.GetDamage()), TEXTSTYLE_BOLD, TEXTCOLOR_RED)
              << " Damage!) \n";
}
