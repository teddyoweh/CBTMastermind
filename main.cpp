#include "cbt_application.cpp"


int main() {
    CBTApplication cbtApp;

    // Load question bank and user details
    cbtApp.bulkUploadQuestions("./data/question_bank.txt");
    cbtApp.bulkUploadUserDetails("./data/user_data.txt");

    // User login
   std::string username = Utilities::getUserInput<std::string>("Enter your username: ");
    std::string password = Utilities::getUserInput<std::string>("Enter your password: ");
    // std::string username = "alice";
    // std::string password = "password123";

    std::cout << username << std::endl;
    //check if empty
    if(username.empty() || password.empty()){
        std::cerr << "Error: Username or password cannot be empty." << std::endl;
        return 1;
    }else{
    if(cbtApp.loginUser(username, password)){
            std::cout << "Login successful. Welcome, " << username << "!" << std::endl;
                    cbtApp.takeTest();
                cbtApp.viewTestScript();
        }
    
    }
    
 
  

    return 0;
}
