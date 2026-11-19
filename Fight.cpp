#include "Fight.h"
#include <iostream>

// Constructor
Fight::Fight(int fighter1Id, int fighter2Id) :
    Fight{fighter1Id, fighter2Id, 1, -1, "Not finished"} {}

// Load from history + Overload
Fight::Fight(int fighter1Id, int fighter2Id, int round, int winnerId, const string& result) :
    fighter1Id_{fighter1Id}, fighter2Id_{fighter2Id}, round_{round}, winnerId_{winnerId}, result_{result} {}

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

string Fight::getResult() const {
    return result_;
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
