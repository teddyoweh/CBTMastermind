#ifndef CBT_APPLICATION_H
#define CBT_APPLICATION_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "includes/user.h"
#include "includes/question.h"

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
