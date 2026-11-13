
#ifndef FIGHT_SIMULATOR_H
#define FIGHT_SIMULATOR_H

#include "Fight.h"

// Temporary stats until Srijan's Fighter class is ready
struct FighterStats {
    int striking;
    int grappling;
    int defense;
    int stamina;
};

class FightSimulator {
private:
    Fight& fight_;
    FighterStats fighters_[2];
    int health_[2];
    int stamina_[2];
    int maxRounds_;

    int randomNumber(int lowest, int highest);

public:
    FightSimulator(Fight& fight, FighterStats fighter1,
                   FighterStats fighter2, int maxRounds);

    void simulateFight();
    void simulateRound();
    int calculateDamage(int striking, int defense);
    int determineWinner();
};

#endif
