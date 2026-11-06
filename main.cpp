/*
 * C++ Final Project
 * MAIN Driver class for UFC Fighter Simulation Game
 * Josiah M., Srijan K., Ben R.
 */

#include <iostream>
#include <vector>

#include "Fight.h"
#include "Fighter.h"
#include "FightSimulator.h"

using namespace std;

int menuOption() {
    int option;
    string in {""};
    cout << "Please choose one of the following MENU options to proceed:" << endl;
    while (cin >> in) {   // cin.eof, cin.end or ...
        // 0 - load save file
        // 1 - start new fight (rounds?)
        // 2 -
    }
}

bool loadSaveFile(string fileName) {
    // return true if parse and File Opener is succesful, else FALSE
}

int main() {
    vector<Fight> fightHistory;
    vector<Fighter> roster;

    cout << "WELCOME to UFC Fight Simulator!" << endl;
    menuOption();

    return 0;
}