//
// Created by kumars on 11/13/2026.
//

#ifndef C_FINAL_PROJECT_GRAPPLER_H
#define C_FINAL_PROJECT_GRAPPLER_H
#include <string>
using namespace std;
#include "Fighter.h"

class Grappler: public Fighter {
public:
    explicit Grappler(const std::string& name,
                 int striking  = 100,
                 int grappling = 100,
                 int defense   = 100,
                 int wins      = 0,
                 int losses    = 0);

    void grapplingStrike(Fighter& opponent);

private:
    int grapplingDamage;
};
#endif //C_FINAL_PROJECT_GRAPPLER_H
