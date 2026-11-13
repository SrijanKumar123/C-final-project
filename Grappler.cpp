//
// Created by kumars on 11/13/2026.
//

#include <iostream>
#include "Grappler.h"
using namespace std;

Grappler::Grappler(const string &name, int striking, int grappling, int defense):
Fighter(name, striking, grappling, defense), grapplingDamage(25) {
}

void Grappler::grapplingStrike(Fighter &opponent) {
    if (getStamina() >= 15) {
        useStamina(15);
        opponent.takeDamage(grapplingDamage);
    }
}
