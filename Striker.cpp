//
// Created by kumars on 11/13/2026.
//

#include <iostream>
#include "Striker.h"
using namespace std;

Striker::Striker(const std::string& name, int striking, int grappling, int defense, int wins, int losses)
    : Fighter{name, striking, grappling, defense, wins, losses},
      specialDamage{25}  {}

void Striker::specialStrike(Fighter& opponent) {
    if (getStamina() >= 15) {
        useStamina(15);
        opponent.takeDamage(specialDamage);
    }
}
