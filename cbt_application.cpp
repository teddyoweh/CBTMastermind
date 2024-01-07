#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cctype>  
#include "cbt_application.h"
#include <iomanip>  


inline void CBTApplication::bulkUploadUserDetails(const std::string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        User user;
        while (file >> user.username >> user.password) {
            userList.push_back(user);
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open user details file." << std::endl;
    }
}

inline bool CBTApplication::loginUser(const std::string& username, const std::string& password) {
    for (const User& user : userList) {
        if (user.username == username && user.password == password) {
            currentUser = user;
            std::cout << "Login successful. Welcome, " << username << "!" << std::endl;
            return true;
        }
    }
    std::cerr << "Error: Incorrect login details. Please try again." << std::endl;
    return false;
}
inline void CBTApplication::bulkUploadQuestions(const std::string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            Question question;
            question.questionText = line;

            for (char optionChar = 'A'; optionChar <= 'D'; ++optionChar) {
                if (getline(file, line)) {
                     question.options.push_back(line);
                } else {
                     std::cerr << "Error: Incomplete question format in file." << std::endl;
                    file.close();
                    return;
                }
            }

            
            char correctOption;
            if (getline(file, line)) {
                correctOption = line.at(0);
                question.correctOption = std::toupper(correctOption);
            } else {
                
                std::cerr << "Error: Incomplete question format in file." << std::endl;
                file.close();
                return;
            }

            
            getline(file, line);

            questionBank.push_back(question);
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open question bank file." << std::endl;
    }
}

inline void CBTApplication::displayQuestion(int questionNumber) {
    if (questionNumber >= 1 && questionNumber <= static_cast<int>(questionBank.size())) {
        const Question& question = questionBank[questionNumber - 1];
        std::cout << "Question " << questionNumber << ": " << question.questionText << std::endl;

        
        char optionChar = 'A';
        for (const std::string& option : question.options) {
            std::cout << optionChar << ") " << option << std::endl;
            ++optionChar;
        }
    } else {
        std::cerr << "Error: Invalid question number." << std::endl;
    }
}

inline void CBTApplication::takeTest() {
    if (userList.empty() || questionBank.empty()) {
        std::cerr << "Error: No users or questions available." << std::endl;
        return;
    }

    for (size_t i = 0; i < questionBank.size(); ++i) {
        displayQuestion(i + 1);
        char userChoice;
        do {
            userChoice = Utilities::getUserInput<char>("Your choice: ");
            userChoice = std::toupper(userChoice);
            if (userChoice < 'A' || userChoice > 'D') {
                std::cerr << "Error: Invalid choice. Please enter A, B, C, or D." << std::endl;
            }
        } while (userChoice < 'A' || userChoice > 'D');
        currentUser.userResponses[i + 1] = userChoice;
    }
    std::cout << "Test completed. Your responses have been recorded.\n" << std::endl;
}


inline void CBTApplication::viewTestScript() {
    if (currentUser.userResponses.empty()) {
        std::cerr << "Error: No test responses available." << std::endl;
        return;
    }

    int totalQuestions = questionBank.size();
    int correctAnswers = 0;

    std::cout << "Test Script:" << std::endl;
    for (const auto& response : currentUser.userResponses) {
        const Question& question = questionBank[response.first - 1];
        std::cout << "Question " << response.first << ": " << question.questionText;
        std::cout << " (Your Answer: " << response.second << ", Correct Answer: " << question.correctOption << ")" << std::endl;

        // Check if the user's answer is correct
        if (response.second == question.correctOption) {
            correctAnswers++;
        }
    }

    // Calculate percentage score
    double percentageScore = static_cast<double>(correctAnswers) / totalQuestions * 100.0;

    std::cout << "\nPercentage Score: " << std::setprecision(2) << std::fixed << percentageScore << "%" << std::endl;
}
