#ifndef FIGHT_H
#define FIGHT_H

#include <string>

// Stores information about a fight
class Fight {
private:
    int fighter1Id_;
    int fighter2Id_;
    int round_;
    int winnerId_;
    std::string result_;

public:
    Fight(int fighter1Id, int fighter2Id);

    int getFighter1Id() const;
    int getFighter2Id() const;
    int getRound() const;
    int getWinnerId() const;

    void nextRound();
    void setResult(int winnerId, std::string result);
    void displayResult() const;
};

#endif
