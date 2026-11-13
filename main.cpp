//
// Created by kumars on 11/1/2026.
//
#include <iostream>
using namespace std;
#include "Fighter.h"
#include <vector>
#include <utility>
#include <limits>

void displayFighter(const vector<Fighter>& fighters) {
    cout << "=====" << "AVAILABLE FIGHTERS" << "=====" << endl;
    for (int i = 0; i < fighters.size(); i++) {
        cout << i + 1 << ". " << fighters[i].getName() << endl;
    }
}

pair<int,int> selectFighters(const vector<Fighter>& fighters) {
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
        cout << "Selected Fight: "<< fighters[fighter1 - 1].getName() << " vs "
        << fighters[fighter2 - 1].getName() << endl;
        return {fighter1 - 1, fighter2 - 1};
    }
}

int main() {
    vector<Fighter> fighters = {
        Fighter("Alex Pereira", 95,90,89),
        Fighter("Jon Jones", 98,95,93),
        Fighter("GSP", 95,92, 94),
        Fighter("Joshua Van", 95, 85,80),
        Fighter("Dustin Poirier", 94,90,92),
        Fighter("Charles Oliveria", 90,97,89),
        Fighter("Illia Topuria", 97,95,95),
        Fighter("Islam Makachev", 85,98, 95)
        };
    displayFighter(fighters);
    pair<int, int> selected = selectFighters(fighters);
    Fighter& firstFighter = fighters[selected.first];
    Fighter& secondFighter = fighters[selected.second];
    firstFighter.resetHealth();
    firstFighter.resetStamina();
    secondFighter.resetHealth();
    secondFighter.resetStamina();
    return 0;
}

