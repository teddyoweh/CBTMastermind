#ifndef CBT_APPLICATION_H
#define CBT_APPLICATION_H

#include <iostream>
#include <vector>
#include <map>

struct Question {
    std::string questionText;
    std::vector<std::string> options;
    char correctOption;
};

struct User {
    std::string username;
    std::string password;
    std::map<int, char> userResponses; // Mapping question number to user's chosen option
};

class CBTApplication {
public:
    void bulkUploadQuestions(const std::string& filePath);
    void bulkUploadUserDetails(const std::string& filePath);
    void loginUser(const std::string& username, const std::string& password);
    void displayQuestion(int questionNumber);
    void takeTest();
    void viewTestScript();

private:
    std::vector<Question> questionBank;
    std::vector<User> userList;
    User currentUser; // To keep track of the current user during the test
};

#endif // CBT_APPLICATION_H
