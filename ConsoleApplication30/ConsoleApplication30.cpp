#include <iostream>
class Unit
{
protected:
    int health;
    int damage;
public:
    Unit(int health, int damage)
    {
        this->health = health; this->damage = damage;
    }
    virtual void takeDamage(int damage)
    {
        if (damage < health) health -= damage;
        else health = 0;
    }
    virtual void attack(Unit& other) = 0;
};

class MeleeUnit : public Unit
{
public:
    MeleeUnit(int health, int damage) : Unit(health, damage)
    {}
    virtual void attack(Unit& other) override
    {
        other.takeDamage(damage);
    }
};

class RangeUnit : public Unit
{
protected:
    int countAttack;
public:
    RangeUnit(int health, int damage, int count) : Unit(health, damage)
    {
        this->countAttack = count;
    }
    virtual void attack(Unit& other) override
    {
        for (int i = 0; i < countAttack; i++)
        {
            other.takeDamage(damage);
        }
    }
};

int main()
{

}
