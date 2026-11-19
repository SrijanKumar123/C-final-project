//
// Created by kumars on 11/13/2026.
//

#ifndef C_FINAL_PROJECT_STRIKER_H
#define C_FINAL_PROJECT_STRIKER_H
using namespace std;
#include "Fighter.h"

class Striker : public Fighter {
public:
    explicit Striker(const std::string& name,
                 int striking  = 100,
                 int grappling = 100,
                 int defense   = 100,
                 int wins      = 0,
                 int losses    = 0);
    void specialStrike(Fighter& opponent);
private:
    int specialDamage;
};

#endif //C_FINAL_PROJECT_STRIKER_H
