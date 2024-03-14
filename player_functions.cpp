#include <iostream>
#include <vector>
#include <cstdlib>
#include "question_functions.h"
#include "player_functions.h"

// Function to play the game for a single player
long long playSinglePlayer(const std::vector<Question>& questions) {
    int totalQuestions = questions.size();
    long long moneyWon = 0;

    for (int currentQuestionIndex = 0; currentQuestionIndex < totalQuestions; ++currentQuestionIndex) {
        std::cout << "Question " << currentQuestionIndex + 1 << "/" << totalQuestions << std::endl;
        displayQuestion(questions[currentQuestionIndex]);

        char playerAnswer;
        std::cin >> playerAnswer;

        if (checkAnswer(questions[currentQuestionIndex], playerAnswer)) {
            std::cout << "Correct!" << std::endl;
            moneyWon += 1000LL; // Increment money by 1000 for each correct answer (LL suffix for long long literal)
        } else {
            std::cout << "Incorrect! Game Over!" << std::endl;
            return moneyWon; // Exit the function and return the money won
        }

        std::cout << "You've won $" << moneyWon << std::endl << std::endl;
    }

    std::cout << "Congratulations! You've answered all questions correctly and won a total of $" << moneyWon << "!" << std::endl;
    return moneyWon; // Return the money won
}

// Function to play the game for multiple players
void playMultiPlayer(const std::vector<Question>& questions) {
    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;

    std::vector<int> playersMoney(numPlayers, 0);

    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Player " << i + 1 << ", it's your turn!" << std::endl;
        playersMoney[i] = playSinglePlayer(questions);
    }

    // Find the winner
    int maxMoney = 0;
    int winner = -1;
    for (int i = 0; i < numPlayers; ++i) {
        if (playersMoney[i] > maxMoney) {
            maxMoney = playersMoney[i];
            winner = i;
        }
    }
    
    if(winner == -1)
    {
        std::cout << "There is no winner!" << std::endl;
    }
    else
    {
         std::cout << "Player " << winner + 1 << " wins with $" << maxMoney << "!" << std::endl;
    }
}