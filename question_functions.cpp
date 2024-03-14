#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "question_functions.h"

// Avoid using "using namespace std;" in header files

// Function to load questions from hardcoded sample data
std::vector<Question> loadSampleQuestions() {
    std::vector<Question> questions = {
        {"What is the capital of France?", {"London", "Paris", "Berlin", "Rome"}, 'B'},
        {"Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Leo Tolstoy"}, 'A'},
        {"What is the largest mammal?", {"Elephant", "Blue whale", "Giraffe", "Hippopotamus"}, 'B'}
    };

    return questions;
}

// Function to load questions from a file
std::vector<Question> loadQuestionsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Question> questions;
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    while (getline(file, line)) {
        Question q;
        q.question = line;
        for (int i = 0; i < 4; ++i) {
            getline(file, line);
            q.options.push_back(line);
        }
        getline(file, line);
        line.erase(std::remove(line.begin(), line.end(), ':'), line.end()); // Remove ':' character
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); // Remove spaces
        q.correctOption = std::toupper(line[0]);
        questions.push_back(q);
    }
    file.close();
    return questions;
}

// Function to display a question and its options
void displayQuestion(const Question& q) {
    std::cout << q.question << std::endl;
    for (int i = 0; i < q.options.size(); ++i) {
        std::cout << char('A' + i) << ". " << q.options[i] << std::endl;
    }
    std::cout << "Your answer: ";
}

// Function to check if the answer is correct
bool checkAnswer(const Question& q, char answer) {
    return (std::toupper(answer) == q.correctOption);
}
