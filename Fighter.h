//
// Created by randolphb on 11/4/2026.
//

#ifndef C_FINAL_PROJECT_FIGHTER_H
#define C_FINAL_PROJECT_FIGHTER_H

#include <string>

// Srijan's class
class Fighter {
private:
    std::string name_;
    int striking_{};
    int grappling_{};
    int defense_{};
    int stamina_{};
    int health_{};
    int wins_{};
    int losses_{};

public:
    std::string getName() const;
    int getStriking() const;
    void takeDamage(int amount);
    void updateRecord(bool won);
};

#endif //C_FINAL_PROJECT_FIGHTER_H
