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
    Grappler(const string& name, int striking, int grappling, int defense);
    void grapplingStrike(Fighter& opponent);
private:
    int grapplingDamage;
};
#endif //C_FINAL_PROJECT_GRAPPLER_H
