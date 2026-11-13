//
// Created by kumars on 11/13/2026.
//

#include <iostream>
#include "Striker.h"
using namespace std;

Striker::Striker(const string& name, int striking, int grappling, int defense)
    : Fighter(name, striking, grappling, defense),
      specialDamage(25) {
}

void Striker::specialStrike(Fighter& opponent) {
    if (getStamina() >= 15) {
        useStamina(15);
        opponent.takeDamage(specialDamage);
    }
}
