//
// Created by randolphb on 11/4/2026.
//

#ifndef C_FINAL_PROJECT_FIGHTSIMULATOR_H
#define C_FINAL_PROJECT_FIGHTSIMULATOR_H

// Ben's class
class FightSimulator {
private:
    int maxRounds_{};
    int currentRound_{};
    int randomNumber_{};

public:
    void simulateFight();
    void simulateRound();
    int calculateDamage();
    int determineWinner();
};

#endif //C_FINAL_PROJECT_FIGHTSIMULATOR_H
