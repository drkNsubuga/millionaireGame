#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define a structure for each question
struct Question {
    string question;
    vector<string> options;
    char correctOption;
};

// Function to display a question and its options
void displayQuestion(const Question& q) {
    cout << q.question << endl;
    for (int i = 0; i < q.options.size(); ++i) {
        cout << char('A' + i) << ") " << q.options[i] << endl;
    }
    cout << "Your answer: ";
}

// Function to check if the answer is correct
bool checkAnswer(const Question& q, char answer) {
    return (toupper(answer) == toupper(q.correctOption));
}

// Function to load questions from hardcoded sample data
vector<Question> loadSampleQuestions() {
    vector<Question> questions = {
        {"What is the capital of France?", {"London", "Paris", "Berlin", "Rome"}, 'B'},
        {"Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Leo Tolstoy"}, 'A'},
        {"What is the largest mammal?", {"Elephant", "Blue whale", "Giraffe", "Hippopotamus"}, 'B'}
    };

    return questions;
}
int main() {
    // Seed the random number generator
    srand(time(0));

    // Sample questions
    vector<Question> questions = loadSampleQuestions();

    int totalQuestions = questions.size();
    int currentQuestionIndex = 0;
    int moneyWon = 0;

    cout << "Welcome to Who Wants to Be a Millionaire!" << endl;

    while (currentQuestionIndex < totalQuestions) {
        cout << "Question " << currentQuestionIndex + 1 << "/" << totalQuestions << endl;
        displayQuestion(questions[currentQuestionIndex]);

        char playerAnswer;
        cin >> playerAnswer;

        if (checkAnswer(questions[currentQuestionIndex], playerAnswer)) {
            cout << "Correct!" << endl;
            moneyWon += 1000; // Increment money by 1000 for each correct answer
        } else {
            cout << "Incorrect!" << endl;
            //break;
        }

        cout << "You've won $" << moneyWon << endl << endl;
        ++currentQuestionIndex;
    }

    cout << "Thank you for playing! You've won a total of $" << moneyWon << endl;

    return 0;
}
