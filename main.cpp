/*
 * C++ Final Project
 * MAIN Driver class for UFC Fighter Simulation Game
 * Josiah M., Srijan K., Ben R.
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>
#include<limits>

#include "Fight.h"
#include "Fighter.h"
#include "FightSimulator.h"
#include "Striker.h"
#include "Grappler.h"


using namespace std;

// IO Helpers

void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prompts repeatedly until the user enters an integer between minVal and maxVal
int getValidNumber(const string& prompt, int minVal, int maxVal) {
    int value = 0;

    while (true) {
        cout << prompt;

        if (!(cin >> value)) {
            cout << "Error: Please enter a valid number." << endl;
            clearBadInput();
            continue;
        }

        if (value < minVal || value > maxVal) {
            cout << "Invalid choice. Please enter a number between "
                 << minVal << " and " << maxVal << "." << endl;
            continue;
        }

        return value;
    }
}

// Fighters
void displayFighters(const vector<unique_ptr<Fighter>>& fighters) {
    cout << endl << "===== AVAILABLE FIGHTERS =====" << endl;
    cout << left << setw(4) << "#"
         << setw(20) << "Name"
         << setw(6) << "STR"
         << setw(6) << "GRP"
         << setw(6) << "DEF"
         << "Record" << endl;
    cout << string(48, '-') << endl;

    // Output Roster
    for (int i = 0; i < static_cast<int>(fighters.size()); i++) {
        const Fighter& f = *fighters[i];
        cout << left << setw(4) << (i + 1)
             << setw(20) << f.getName()
             << setw(6) << f.getStriking()
             << setw(6) << f.getGrappling()
             << setw(6) << f.getDefense()
             << f.getWins() << "-" << f.getLosses() << endl;
    }
}

void displayFightHistory(const vector<Fight>& fightHistory,
                         const vector<unique_ptr<Fighter>>& fighters) {
    cout << endl << "===== FIGHT HISTORY =====" << endl;

    if (fightHistory.empty()) {
        cout << "No fights have been simulated yet." << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(fightHistory.size()); i++) {
        const Fight& fight = fightHistory[i];

        string name1 = fighters[fight.getFighter1Id()]->getName();
        string name2 = fighters[fight.getFighter2Id()]->getName();
        string winnerName = fighters[fight.getWinnerId()]->getName();

        cout << (i + 1) << ". " << name1 << " vs. " << name2
             << " | Winner: " << winnerName
             << " | Round: " << fight.getRound() << endl;
    }
}

// Comparator passed below into std::sort: returns true if 'a' ranks above 'b'
bool compareByRecord(const Fighter* a, const Fighter* b) {
    if (a->getWins() != b->getWins()) {
        return a->getWins() > b->getWins();       // More wins ranks higher
    }
    if (a->getLosses() != b->getLosses()) {
        return a->getLosses() < b->getLosses();   // Fewer losses breaks ties
    }
    return a->getName() < b->getName();           // Alphabetical tie-breaker
}

void displayRankings(const vector<unique_ptr<Fighter>>& fighters) {
    // COPY pointers into a temporary vector so std::sort does not reorder OG Roster
    vector<const Fighter*> ranked;
    for (int i = 0; i < static_cast<int>(fighters.size()); i++) {
        ranked.push_back(fighters[i].get());
    }

    sort(ranked.begin(), ranked.end(), compareByRecord);  // built-in SORT!

    cout << endl << "===== FIGHTER RANKINGS =====" << endl;
    for (int i = 0; i < static_cast<int>(ranked.size()); i++) {
        cout << (i + 1) << ". " << left << setw(20) << ranked[i]->getName()
             << ranked[i]->getWins() << "-" << ranked[i]->getLosses() << endl;
    }
}

// RUN FIGHT
pair<int,int> selectFighters(const vector<unique_ptr<Fighter>>& fighters) {
    displayFighters(fighters);
    int rosterSize = fighters.size();
    while (true) {
        int choice1 = getValidNumber("Select Fighter 1: ", 1, rosterSize);
        int choice2 = getValidNumber("Select Fighter 2: ", 1, rosterSize);

        if (choice1 == choice2) {
            cout << "You cannot select the same fighter twice. Try again." << endl;
            continue;
        }

        // Convert to 0-index range
        int id1 = choice1 - 1;
        int id2 = choice2 - 1;

        cout << endl << "Selected Matchup: " << fighters[id1]->getName() << " vs. " << fighters[id2]->getName() << endl;
        return {id1, id2};
    }
}

int selectRounds() {
    while (true) {
        int rounds = getValidNumber("Select fight length (3 or 5 rounds): ", 3, 5);
        if (rounds == 3 || rounds == 5) {
            return rounds;
        }
        cout << "Invalid choice. Fights must be either 3 or 5 rounds." << endl;
    }
}


// Temporary bridge: copies a Fighter's attributes into FighterStats.
// Once FightSimulator accepts Fighter& directly, this helper can be removed.
FighterStats buildFighterStats(const Fighter& fighter) {
    FighterStats stats;
    stats.striking = fighter.getStriking();
    stats.grappling = fighter.getGrappling();
    stats.defense = fighter.getDefense();
    stats.stamina = fighter.getStamina();
    return stats;
}

void runFight(vector<unique_ptr<Fighter>>& fighters, vector<Fight>& fightHistory) {
    if (fighters.size() < 2) {
        cout << "Need at least 2 fighters in the roster to start a fight." << endl;
        return;
    }

    pair<int, int> selected = selectFighters(fighters);
    int id1 = selected.first;
    int id2 = selected.second;
    int rounds = selectRounds();

    Fighter& firstFighter = *fighters[id1];
    Fighter& secondFighter = *fighters[id2];

    // Ensure both fighters start fresh before every fight
    firstFighter.resetHealth();
    firstFighter.resetStamina();
    secondFighter.resetHealth();
    secondFighter.resetStamina();

    // Run simulation using the temporary FighterStats bridge
    FighterStats stats1 = buildFighterStats(firstFighter);
    FighterStats stats2 = buildFighterStats(secondFighter);

    Fight currentFight(id1, id2);
    FightSimulator simulator(currentFight, stats1, stats2, rounds);
    simulator.simulateFight();

    // Update win/loss records and save the completed Fight to history
    int winnerId = currentFight.getWinnerId();
    bool fighter1Won = (winnerId == id1);

    if (winnerId == id1) {
        firstFighter.updateRecord(fighter1Won);
    } else {
        secondFighter.updateRecord(!fighter1Won);
    }

    fightHistory.push_back(currentFight);

    // Output Win
    cout << endl << "Official Winner: " << fighters[winnerId]->getName()
         << " (Round " << currentFight.getRound() << ")" << endl;
    cout << "Updated Records -> "
         << firstFighter.getName() << " (" << firstFighter.getWins() << "-" << firstFighter.getLosses() << ") | "
         << secondFighter.getName() << " (" << secondFighter.getWins() << "-" << secondFighter.getLosses() << ")" << endl;
}

// MENU functions

int getMenuChoice() {
    const string MENU = "===== UFC FIGHT SIMULATOR MENU =====\n"
                        "1. View Available Fighters\n"
                        "2. Start a New Fight\n"
                        "3. View Fight History\n"
                        "4. View Fighter Rankings\n"
                        "5. Save Game (coming next)\n"
                        "6. Load Game (coming next)\n"
                        "7. Exit";
    cout << endl << MENU << endl;

    return getValidNumber("Choose an option (1-7):  ", 1, 7);
}

// Single Menu Selection
bool handleMenuChoice(int choice,
                      vector<unique_ptr<Fighter>>& fighters,
                      vector<Fight>& fightHistory) {
    switch (choice) {  // routing to game options
        case 1:
            displayFighters(fighters);
            return true;
        case 2:
            runFight(fighters, fightHistory);
            return true;
        case 3:
            displayFightHistory(fightHistory, fighters);
            return true;
        case 4:
            displayRankings(fighters);
            return true;
        case 5:
            cout << "Save functionality not implemented yet." << endl;
            return true;
        case 6:
            cout << "Load functionality not implemented yet." << endl;
            return true;
        case 7:
            cout << "Exiting UFC Fight Simulator. Goodbye!" << endl;
            return false;
        default:
            cout << "Invalid option." << endl;
            return true;
    }
}

void runMenuLoop(vector<unique_ptr<Fighter>>& fighters, vector<Fight>& fightHistory) {
    bool running = true;
    while (running) {
        int choice = getMenuChoice();
        running = handleMenuChoice(choice, fighters, fightHistory);
    }
}

bool loadSaveFile(string fileName) {
    // return true if parse and File Opener is succesful, else FALSE
}

// Fill the Roster (passed in by reference) with Default UFC Fighters!
void loadDefualtRoster(vector<unique_ptr<Fighter>>& fighters) {
    fighters.clear();
    fighters.push_back(make_unique<Striker>("Alex Pereira", 95, 90, 89));
    fighters.push_back(make_unique<Fighter>("Jon Jones", 98, 95, 93));
    fighters.push_back(make_unique<Fighter>("GSP", 95, 92, 94));
    fighters.push_back(make_unique<Fighter>("Joshua Van", 95, 85, 80));
    fighters.push_back(make_unique<Fighter>("Dustin Poirier", 94, 90, 92));
    fighters.push_back(make_unique<Grappler>("Charles Oliveira", 90, 97, 89));
    fighters.push_back(make_unique<Striker>("Ilia Topuria", 97, 95, 95));
    fighters.push_back(make_unique<Grappler>("Islam Makhachev", 85, 98, 95));
}

int main() {
    // srand(static_cast<unsigned>(time(nullptr))); maybe

    vector<Fight> fightHistory;
    vector<unique_ptr<Fighter>> fighters;
    loadDefualtRoster(fighters); // Load UFC Fighters

    //displayFighters(fighters);

    // Loop Menu Options
    cout << "WELCOME to UFC Fight Simulator!" << endl;
    runMenuLoop(fighters, fightHistory);

    /*
    pair<int, int> selected = selectFighters(fighters);
    Fighter& firstFighter = *fighters[selected.first];
    Fighter& secondFighter = *fighters[selected.second];
    firstFighter.resetHealth();
    firstFighter.resetStamina();
    secondFighter.resetHealth();
    secondFighter.resetStamina();
    */

    return 0;
}

