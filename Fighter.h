//
// Created by randolphb on 11/4/2026.
//

#ifndef C_FINAL_PROJECT_FIGHTER_H
#define C_FINAL_PROJECT_FIGHTER_H
using namespace std;

class Fighter {
private:
    string name_;
    int striking_;
    int grappling_;
    int defense_;
    int stamina_;
    int health_;
    int wins_;
    int losses_;
public:
    Fighter();
    Fighter(const string&name);
    Fighter(const string& name, int striking, int grappling, int defense);
    string getName() const;
    int getStriking() const;
    int getGrappling() const;
    int getDefense() const;
    int getStamina() const;
    int getHealth() const;
    int getWins() const;
    int getLosses() const;
    void takeDamage(int damage);
    void useStamina(int amount);
    void resetHealth();
    void resetStamina();
    void updateRecord(bool won);
    bool knockedOut() const;
    void recoverStamina(int amount);
    bool isExhausted() const;
};
#endif //C_FINAL_PROJECT_FIGHTER_H

