Certainly! I have added the instructions for running the build script to the existing documentation:

# CBTMastermind -  Computer-Based Testing (CBT) Application Design

## Overview
A standalone Computer-Based Testing (CBT) Applications. The goal is to streamline the testing process, allowing for bulk question uploads, user login management, and efficient test-taking functionalities.

## Features
1. **Bulk Question Upload:**
    - Enable the bulk upload of questions to the application.
    
2. **Bulk User Login Details:**
    - Provide a feature to bulk upload user login details.

3. **Incorrect Login Handling:**
    - Display a notification for incorrect login details.
    - Prompt users to re-login if incorrect information is provided.

4. **Keyboard Input for Options:**
    - Allow users to input character options using the keyboard.
    - Accept both lowercase and uppercase characters for options.

5. **Error Handling for Incorrect Choices:**
    - Display an error message for incorrect choice characters.
    - Prompt users to re-enter a valid choice or option.

6. **Retain User Input:**
    - Store and retain the options entered by the user for each question.

7. **Skip and Return to Questions:**
    - Allow users to skip a question.
    - Provide an option to return to skipped questions.

8. **Test Completion:**
    - Display the user's score upon completing the test.

9. **Test Script Viewing:**
    - Offer users the option to view their test script.

## System Design

```cpp
// Sample Code Snippet for Core Functionality

#include <iostream>
#include <vector>
#include <map>
#include <fstream>

// Define structures to store questions, user details, etc.

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
    // Functions for bulk question upload, user login details upload, etc.

    void loginUser(std::string username, std::string password);
    void displayQuestion(int questionNumber);
    void takeTest();
    void viewTestScript();

private:
    std::vector<Question> questionBank;
    std::vector<User> userList;
};

int main() {
    // Application initialization and user interaction
    return 0;
}
```

## Folder Architecture

```
CBT_Application/
|-- CMakeLists.txt
|-- build.sh
|-- cmake.sh
|-- logs.txt
|-- run.sh
|-- t.txt
|-- main.cpp
|-- cbt_application.cpp
|-- cbt_application.h
|-- question.h
|-- user.h
|-- utils.h
|-- data/
|   |-- question_bank.txt
|   |-- user_data.txt
|-- .gitignore
```

To run the build script, use the following commands in the terminal:

```bash
chmod +x build.sh
./build.sh
```

These commands give execute permission to the `build.sh` script and then run it. Ensure that you are in the correct directory containing the `build.sh` file before executing these commands.