#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include "question_functions.h"
#include "player_functions.h"

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Sample questions
    vector<Question> questions = loadQuestionsFromFile("questions.txt");

  cout << "Welcome to Who Wants to Be a Millionaire!" << endl;
    
    int choice;
    bool validChoice = false;
    do {
        cout << "Select game mode:" << endl;
        cout << "1. Single Player" << endl;
        cout << "2. Multiplayer" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            validChoice = true;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (!validChoice);

    switch (choice) {
        case 1:
            playSinglePlayer(questions);
            break;
        case 2:
            playMultiPlayer(questions);
            break;
        default:
            cout << "Invalid choice! Exiting..." << endl;
    }

    return 0;
}
