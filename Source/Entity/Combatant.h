#pragma once
#include "Base/Entity.h"
#include "Base/Interface/ICombat.h"
#include <string>
struct Stats;


class Combatant final : public Entity, public ICombat
{
    public:
    
        // Constructs a new Combatant object.
        Combatant(const std::string& name, unsigned short health, unsigned short defense, unsigned short damage, unsigned short speed);

        // Virtual destructor.
        ~Combatant() override;
    

        // Executes an attack on another combatant.
        void Attack(Combatant& target) override;

        // Checks whether the combatant is still alive.
        bool bIsAlive() const;


    protected:
        
        // Reacts to incoming damage.
        void OnDamage(unsigned short amount) override;
};
