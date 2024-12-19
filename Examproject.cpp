#include<bits/stdc++.h>
using namespace std;


struct Question {
    string questionText;
    vector<string> options;
    int correctOption; 
};

int conductExam(const vector<Question>& questions) {
    int score = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "\nQuestion " << i + 1 << ": " << questions[i].questionText << endl;
        for (size_t j = 0; j < questions[i].options.size(); ++j) {
            cout << j + 1 << ". " << questions[i].options[j] << endl;
        }
        int userAnswer;
        cout << "Enter your answer (1-" << questions[i].options.size() << "): ";
        cin >> userAnswer;
        
        if (userAnswer - 1 == questions[i].correctOption) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! The correct answer was: " 
                 << questions[i].options[questions[i].correctOption] << endl;
        }
    }
    return score;
}

bool authenticateUser(const string& username, const string& password) {
    const string correctUsername = "Student";
    const string correctPassword = "password123456";
    return username == correctUsername && password == correctPassword;
}
int main() {
    cout << "     Welcome to the Examination Testing System     \n";
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (!authenticateUser(username, password)) {
        cout << "Authentication failed! Exiting the program.\n";
        return 0;
    }
    cout << "Authentication successful! Starting the test...\n";
    vector<Question> questions = {
        {"Who wrote Shree Hanuman Chalisa?",
         {"Ved Vyas", "Maharishi Valmiki", "Goswami Tulsidas", "BudhKaushik"}, 2},
        {"Which planet is known as the Red Planet?",
         {"Earth", "Mars", "Jupiter", "Venus"}, 1},
        {"Which city is known as the 'Silicon Valley Of INDIA'?",
         {"Bengaluru", "Mumbai", "Delhi", "Gurugram"}, 0},
        {"Which team won the ODI World Cup 2023?",
         {"India", "Australia", "England", "New Zealand"}, 1},
         {"Who is the most expensive buy in the IPL Auction 2024?",
         {"KL Rahul","MS Dhoni","Virat Kohli","Rishabh Pant"},3
         }

    
         
    };
    int score = conductExam(questions);
    cout << "\n=== Examination Results ===\n";
    cout << "You scored " << score << " out of " << questions.size() << endl;
    if (score == questions.size()) {
        cout << "Excellent! You have rocked in the test.\n";
    } else if (score >= questions.size() / 2) {
        cout << "Good job! You passed with average score.\n";
    } else {
        cout << "You need to improve. Better luck next time.\n";
    }
    cout << "Thanks for taking the examination!\n";
    return 0;
}
