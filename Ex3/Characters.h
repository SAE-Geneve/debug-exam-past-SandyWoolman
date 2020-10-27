//
//  Characters.hpp
//  Test
//
//  Created by Elias Farhan on 14/12/16.
//  Copyright © 2016 Elias Farhan. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>

class Hero;

class Character
{
public:
    Character(int, int, int, int);
    void takeDamage(int damage);
    int getHealth();
    int getAttack();
    int getDefense();
    int getStrength();
    bool isAlive();
    virtual void death() = 0;

protected:
    int health_;
    int attack_;
    int defense_;
    int strength_;
};

class Monster : public Character
{
    public:
        Monster(int, int, int, int);
        void takeDamage(int damage);
        void fight(Hero* hero);
        void death();
};

class Hero : public Character
{
    public:
        Hero(int, int, int, int);
        void takeDamage(int damage);
        void fight(Monster* monster);
        void death();
};
