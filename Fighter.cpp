//
// Created by randolphb on 11/4/2026.
//

#include <iostream>
#include "Fighter.h"
using namespace std;

Fighter::Fighter() {
    wins_ = 0;
    losses_ = 0;
    health_ = 100;
    stamina_ = 100;
    striking_ = 100;
    grappling_ = 100;
    defense_ = 100;
}

Fighter::Fighter(const string &name): Fighter() {
    name_ = name;
}

string Fighter::getName() const {
    return name_;
}

int Fighter::getHealth() const {
    return health_;
}

int Fighter::getStamina() const {
    return stamina_;
}

int Fighter::getWins() const {
    return wins_;
}

int Fighter::getLosses() const {
    return losses_;
}

int Fighter::getStriking() const {
    return striking_;
}

int Fighter::getGrappling() const {
    return grappling_;
}

int Fighter::getDefense() const {
    return defense_;
}

void Fighter::takeDamage(int damage) {
    if (damage > 0) {
        health_ -= damage;
    }
    if (health_ <= 0) {
        health_ = 0;
    }
}

void Fighter::useStamina(int amount) {
    if (amount > 0) {
        stamina_ -= amount;
    }
    if (stamina_ <= 0) {
        stamina_ = 0;
    }
}

void Fighter::resetHealth() {
    health_ = 100;

}
