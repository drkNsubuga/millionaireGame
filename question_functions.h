#ifndef QUESTION_FUNCTIONS_H
#define QUESTION_FUNCTIONS_H

#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
// Define a structure for each question
struct Question {
    std::string question;
    std::vector<std::string> options;
    char correctOption;
};

// Function declarations
vector<Question> loadSampleQuestions();
void displayQuestion(const Question& q);
bool checkAnswer(const Question& q, char answer);
vector<Question> loadQuestionsFromFile(const string& filename);

#endif // QUESTION_FUNCTIONS_H
