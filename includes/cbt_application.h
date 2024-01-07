#ifndef CBT_APPLICATION_H
#define CBT_APPLICATION_H

#include <iostream>
#include <vector>
#include <map>
#include "question.h"
#include "user.h"

class CBTApplication {
public:
    void loginUser(std::string username, std::string password);
    void displayQuestion(int questionNumber);
    void takeTest();
    void viewTestScript();

private:
    std::vector<Question> questionBank;
    std::vector<User> userList;
};

#endif // CBT_APPLICATION_H
