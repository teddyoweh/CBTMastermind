#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <limits>

namespace Utilities {

    // Function to clear input buffer
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Function to get user input with prompt
    template <typename T>
    T getUserInput(const std::string& prompt) {
        T input;
        std::cout << prompt;
        std::cin >> input;
        clearInputBuffer();
        return input;
    }

    // Function to get a yes/no answer from the user
    bool getYesNoInput(const std::string& prompt) {
        char response;
        do {
            response = getUserInput<char>(prompt + " (y/n): ");
        } while (response != 'y' && response != 'n');
        return response == 'y';
    }

} // namespace Utilities

#endif // UTILITIES_H
