#include "../includes/cbt_application.h"
#include "../includes/utils.h"
#include <fstream>

void CBTApplication::bulkUploadQuestions(const std::string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        Question question;
        while (getline(file, question.questionText)) {
 
            for (char optionChar = 'A'; optionChar <= 'D'; ++optionChar) {
                std::string option;
                getline(file, option);
                question.options.push_back(option);
            }
      
            file >> question.correctOption;
            questionBank.push_back(question);
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open question bank file." << std::endl;
    }
}

void CBTApplication::bulkUploadUserDetails(const std::string& filePath) {
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

void CBTApplication::loginUser(const std::string& username, const std::string& password) {
    for (const User& user : userList) {
        if (user.username == username && user.password == password) {
            currentUser = user;
            std::cout << "Login successful. Welcome, " << username << "!" << std::endl;
            return;
        }
    }
    std::cerr << "Error: Incorrect login details. Please try again." << std::endl;
}
