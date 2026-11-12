
#include "Fight.h"
#include <iostream>

// Constructor
Fight::Fight(int fighter1Id, int fighter2Id) {
    fighter1Id_ = fighter1Id;
    fighter2Id_ = fighter2Id;
    round_ = 1;
    winnerId_ = -1;
    result_ = "Not finished";
}

// Getters
int Fight::getFighter1Id() const {
    return fighter1Id_;
}

int Fight::getFighter2Id() const {
    return fighter2Id_;
}

int Fight::getRound() const {
    return round_;
}

int Fight::getWinnerId() const {
    return winnerId_;
}

// Go to the next round
void Fight::nextRound() {
    round_++;
}

// Save the winner and result
void Fight::setResult(int winnerId, std::string result) {
    winnerId_ = winnerId;
    result_ = result;
}

// Print the result
void Fight::displayResult() const {
    std::cout << "Winner: Fighter " << winnerId_ << std::endl;
    std::cout << "Result: " << result_ << std::endl;
    std::cout << "Round: " << round_ << std::endl;
}
