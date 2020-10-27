//
//  Characters.cpp
//  Test
//
//  Created by Elias Farhan on 14/12/16.
//  Copyright © 2016 Elias Farhan. All rights reserved.
//

#include "Characters.h"
#include <iostream>

//////////Character////////////

Character::Character(int health, int attack, int defense, int strength)
{
    this->health_ = health;
    this->attack_ = attack;
    this->defense_ = defense;
    this->strength_ = strength;
}

bool Character::isAlive()
{
    if (health_ <= 0)
    {
        return false;
    }
    return true;
}

void Character::takeDamage(int damage)
{
    health_ -= damage;
}

int Character::getHealth()
{
    return health_;
}

int Character::getAttack()
{
    return attack_;
}

int Character::getDefense()
{
    return defense_;
}

int Character::getStrength()
{
    return strength_;
}



//////////Monster////////////

Monster::Monster(int, int, int, int) : Character(health_, attack_, defense_, strength_) {}
void Monster::takeDamage(int damage)
{
}
void Monster::fight(Hero* hero)
{
    int damage = attack_/hero->getDefense()*strength_;
    if (damage < 0)
        {
            damage = 0;
        }
    if(damage > strength_)
        {
        damage = strength_;
        }
    std::cout << "Monster gives "<<damage<<" to Hero\n";
    ((Character*)hero)->takeDamage(damage);
}

void Monster::death()
{
    std::cout << "Yet another dead monster!\n";

}

//////////Hero////////////

Hero::Hero(int health, int attack, int defense, int strength): Character(health, attack, defense, strength)
{

}
void Hero::takeDamage(int damage)
{
}
void Hero::fight(Monster* monster)
{
int damage = attack_/getDefense()*strength_;
    if(damage < 0)
        {
            damage = 0;
        }
    if (damage > strength_)
        {
            damage = strength_;
        }
    std::cout << "Hero gives "<<damage<<" to Monster\n";
    monster->takeDamage(damage);
}
void Hero::death()
{
    std::cout << "The hero is dead, long live the hero!\n";
}
