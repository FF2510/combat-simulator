#include "Combatant.h"
#include "Data/Stats.h"

Combatant::Combatant(const std::string& name, unsigned short health, unsigned short defense, unsigned short damage, unsigned short speed)
    : Entity(name, new Stats(health, damage, defense, speed))
{
    // Additional construction logic:
    // ...
}

Combatant::~Combatant()
{
    
}

bool Combatant::bIsAlive() const
{
    
}

#pragma region Interface Implementation

    void Combatant::Attack(Combatant& target)
    {
    
    }

    void Combatant::OnDamage(unsigned short amount)
    {
    
    }

#pragma endregion 
