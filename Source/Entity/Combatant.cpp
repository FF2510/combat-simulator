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
    // Additional destructor logic:
    // ...
}

bool Combatant::bIsAlive() const
{
    return (_stats != nullptr) ? (_stats->Health > 0) : false;
}

#pragma region Interface Implementation

    void Combatant::Attack(Combatant& target)
    {
        if (_stats->Damage > 0)
        {
            target.OnDamage(_stats->Damage);
        }
        
        // If no damage can be inflicted, no action is taken.
    }

    void Combatant::OnDamage(unsigned short amount)
    {
        if (amount > 0)
        {
            // Reduce defense first by the smaller value between defense and damage.
            unsigned short defenseDamage = std::min(_stats->Defense, amount);
            _stats->Defense -= defenseDamage;

            // Calculate the remaining damage that should be applied to health.
            unsigned short remainingDamage = amount - defenseDamage;
            if (remainingDamage > 0)
            {
                _stats->Health -= std::min(_stats->Health, remainingDamage);
            }
        }
        
        // If no damage is inflicted, no reaction is necessary.
    }

#pragma endregion 
