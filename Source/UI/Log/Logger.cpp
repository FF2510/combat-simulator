#include "Logger.h"


std::string Logger::AnsiString(std::string str, std::string styleFormat, std::string colorFormat, std::string backgroundColorFormat)
{
    
}

void Logger::PrintCombatantStats(const Combatant& combatant, bool bDisplayName, bool bInLine)
{
}

void Logger::PrintCombatantStats(std::string name, const unsigned short& health, const unsigned short& defense,
    const unsigned short& damage, const unsigned short& speed, bool bDisplayName, bool bInLine)
{
    
}

void Logger::LogCombatRoundInfo(Combatant& combatantA, Combatant& combatantB, unsigned short round, bool bClear)
{
}

void Logger::LogCombatAction(Combatant& agressor, Combatant& target, bool bClear)
{
}
