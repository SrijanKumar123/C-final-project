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
#include <vector>
#include <memory>
#include "Fighter.h"
#include "Striker.h"
#include "Grappler.h"
#include<limits>

void displayFighter(const vector<unique_ptr<Fighter>>& fighters) {
    cout << "=====" << "AVAILABLE FIGHTERS" << "=====" << endl;
    for (int i = 0; i < fighters.size(); i++) {
        cout << i + 1 << ". " << fighters[i]->getName() << endl;
    }
}

pair<int,int> selectFighters(const vector<unique_ptr<Fighter>>& fighters) {
    int fighter1;
    int fighter2;
    while (true) {
        cout << "Select Fighter 1: ";
        if (!(cin >> fighter1)) {
            cout << "Error: Enter the correct index for a fighter!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << "Select Fighter 2: ";
        if (!(cin >> fighter2)) {
            cout << "Error: Enter the correct index for a fighter!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (fighter1 < 1 || fighter1 > fighters.size()) {
            cout << "Invalid Fighter 1 selection!" << endl;
            continue;
        }
        if (fighter2 < 1 || fighter2 > fighters.size()) {
            cout << "Invalid Fighter 2 selection!" << endl;
            continue;
        }
        if (fighter1 == fighter2) {
            cout << "You cannot select the same fighter twice." << endl;
            continue;
        }
        cout << "Selected Fight: "<< fighters[fighter1 - 1]->getName() << " vs "
        << fighters[fighter2 - 1]->getName() << endl;
        return {fighter1 - 1, fighter2 - 1};
    }
}

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
    vector<unique_ptr<Fighter>> fighters;
    fighters.push_back(make_unique<Striker>("Alex Pereira", 95, 90, 89));
    fighters.push_back(make_unique<Fighter>("Jon Jones", 98, 95, 93));
    fighters.push_back(make_unique<Fighter>("GSP", 95, 92, 94));
    fighters.push_back(make_unique<Fighter>("Joshua Van", 95, 85, 80));
    fighters.push_back(make_unique<Fighter>("Dustin Poirier", 94, 90, 92));
    fighters.push_back(make_unique<Grappler>("Charles Oliveira", 90, 97, 89));
    fighters.push_back(make_unique<Striker>("Ilia Topuria", 97, 95, 95));
    fighters.push_back(make_unique<Grappler>("Islam Makhachev", 85, 98, 95));
  
    cout << "WELCOME to UFC Fight Simulator!" << endl;
    menuOption();
  
    displayFighter(fighters);
    pair<int, int> selected = selectFighters(fighters);
    Fighter& firstFighter = *fighters[selected.first];
    Fighter& secondFighter = *fighters[selected.second];
    firstFighter.resetHealth();
    firstFighter.resetStamina();
    secondFighter.resetHealth();
    secondFighter.resetStamina();
    vector<Fighter> roster;
  
    return 0;
}

