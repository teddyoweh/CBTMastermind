#include "../includes/cbt_application.h"
#include "../includes/utils.h"

int main() {
    CBTApplication cbtApp;

    // Load question bank and user details
    cbtApp.bulkUploadQuestions("../data/question_bank.txt");
    cbtApp.bulkUploadUserDetails("../data/user_data.txt");

    // User login
    std::string username = Utilities::getUserInput<std::string>("Enter your username: ");
    std::string password = Utilities::getUserInput<std::string>("Enter your password: ");
    cbtApp.loginUser(username, password);

    // If login successful, proceed with the test
    if (!username.empty() && !password.empty()) {
        cbtApp.takeTest();
        cbtApp.viewTestScript();
    }

    return 0;
}
