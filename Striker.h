//
// Created by kumars on 11/13/2026.
//

#ifndef C_FINAL_PROJECT_STRIKER_H
#define C_FINAL_PROJECT_STRIKER_H
using namespace std;
#include "Fighter.h"

class Striker : public Fighter {
public:
    Striker(const string& name, int striking, int grappling, int defense);
    void specialStrike(Fighter& opponent);
private:
    int specialDamage;
};

#endif //C_FINAL_PROJECT_STRIKER_H
