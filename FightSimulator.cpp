
#include "FightSimulator.h"
#include <cstdlib>
#include <iostream>

// Constructor
FightSimulator::FightSimulator(Fight& fight, FighterStats fighter1,
                               FighterStats fighter2, int maxRounds)
    : fight_(fight) {

    fighters_[0] = fighter1;
    fighters_[1] = fighter2;
    maxRounds_ = maxRounds;

    health_[0] = 100;
    health_[1] = 100;

    stamina_[0] = fighter1.stamina;
    stamina_[1] = fighter2.stamina;
}

// Generate a random number
int FightSimulator::randomNumber(int lowest, int highest) {
    return lowest + std::rand() % (highest - lowest + 1);
}

// Calculate damage from a strike
int FightSimulator::calculateDamage(int striking, int defense) {
    int damage = striking / 10 - defense / 20 + randomNumber(-2, 2);

    if (damage < 1) {
        damage = 1;
    }

    return damage;
}


void FightSimulator::simulateRound() {
    // Each round has 10 exchanges
    for (int exchange = 1; exchange <= 10; exchange++) {

        // Randomly choose who attacks
        int attacker = randomNumber(0, 1);
        int defender = 1 - attacker;

        // Get the attackers ID
        int attackerId = fight_.getFighter1Id();
        if (attacker == 1) {
            attackerId = fight_.getFighter2Id();
        }

        // Attacking costs 5 stamina
        stamina_[attacker] = stamina_[attacker] - 5;

        if (stamina_[attacker] < 0) {
            stamina_[attacker] = 0;
        }

        // 80% chance of striking, 20% chance of grappling
        if (randomNumber(1, 100) <= 80) {

            // Calculate chance of landing the strike
            int hitChance = 50 + (fighters_[attacker].striking
                            - fighters_[defender].defense) / 2;

            // Low stamina makes striking harder
            if (stamina_[attacker] < 25) {
                hitChance = hitChance - 20;
            }

            // Keep hit chance between 10% and 90%
            if (hitChance < 10) {
                hitChance = 10;
            }
            if (hitChance > 90) {
                hitChance = 90;
            }

            // Determine whether the strike lands
            if (randomNumber(1, 100) <= hitChance) {

                int damage = calculateDamage(
                    fighters_[attacker].striking,
                    fighters_[defender].defense);

                health_[defender] = health_[defender] - damage;

                std::cout << "Fighter " << attackerId
                          << " hits for " << damage << " damage.\n";

                // Check for knockout
                if (health_[defender] <= 0) {
                    health_[defender] = 0;
                    fight_.setResult(attackerId, "KO");
                    return;
                }

            } else {
                std::cout << "Fighter " << attackerId
                          << " misses.\n";
            }

        } else {
            // Grappling / submission attempt
            int submissionChance = 5 + (fighters_[attacker].grappling
                                   - fighters_[defender].defense) / 4;

            // Low stamina reduces submission chance
            if (stamina_[attacker] < 25) {
                submissionChance = submissionChance / 2;
            }

            // Keep submission chance between 1% and 30%
            if (submissionChance < 1) {
                submissionChance = 1;
            }
            if (submissionChance > 30) {
                submissionChance = 30;
            }

            // Determine whether submission succeeds
            if (randomNumber(1, 100) <= submissionChance) {
                std::cout << "Fighter " << attackerId
                          << " lands a submission!\n";

                fight_.setResult(attackerId, "Submission");
                return;

            } else {
                std::cout << "Fighter " << attackerId
                          << " fails a submission.\n";
            }
        }
    }
}


int FightSimulator::determineWinner() {
    // Fighter 1 wins if they have more health
    if (health_[0] > health_[1]) {
        return fight_.getFighter1Id();
    }

    // Fighter 2 wins if they have more health
    if (health_[1] > health_[0]) {
        return fight_.getFighter2Id();
    }

    // If tied, randomly pick a winner
    if (randomNumber(0, 1) == 0) {
        return fight_.getFighter1Id();
    }

    return fight_.getFighter2Id();
}


// Simulate the entire fight
void FightSimulator::simulateFight() {

    std::cout << "FIGHT START!\n";

    // Run each round
    for (int round = 1; round <= maxRounds_; round++) {

        std::cout << "\nROUND " << fight_.getRound() << "\n";

        simulateRound();

        // Stop if someone won by KO or submission
        if (fight_.getWinnerId() != -1) {
            break;
        }

        // Advance to the next round if needed
        if (round < maxRounds_) {
            fight_.nextRound();
        }
    }

    // If nobody finished the fight, go to a decision
    if (fight_.getWinnerId() == -1) {
        int winner = determineWinner();
        fight_.setResult(winner, "Decision");
    }

    // Display the final result
    std::cout << "\nFIGHT OVER!\n";
    fight_.displayResult();
}
