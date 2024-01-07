#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

struct Question {
    std::string questionText;
    std::vector<std::string> options;
    char correctOption;
};

#endif // QUESTION_H
