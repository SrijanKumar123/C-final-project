#ifndef FIGHT_H
#define FIGHT_H

#include <string>

using namespace std;

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
    Fight(int fighter1Id, int fighter2Id, int round, int winnerId, const string& result);

    int getFighter1Id() const;
    int getFighter2Id() const;
    int getRound() const;
    int getWinnerId() const;
    string getResult() const;

    void nextRound();
    void setResult(int winnerId, string result);
    void displayResult() const;
};

#endif
