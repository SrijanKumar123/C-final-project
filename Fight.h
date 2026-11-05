//
// Created by randolphb on 11/4/2026.
//

#ifndef C_FINAL_PROJECT_FIGHT_H
#define C_FINAL_PROJECT_FIGHT_H


#include <string>

// Ben's class
class Fight {
private:
    int fighter1Id_{};
    int fighter2Id_{};
    int round_{};
    int winnerId_{};
    std::string result_;

public:
    int getRound() const;
    void setResult();
    void displayResult() const;
};


#endif //C_FINAL_PROJECT_FIGHT_H
