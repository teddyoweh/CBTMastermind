#include <iostream>
#include <limits>

class Utilities {
public:
    template <typename T>
    static T getUserInput(const std::string& prompt) {
        T input;
        std::cout << prompt;
        std::cin >> input;
        return input;
    }
};