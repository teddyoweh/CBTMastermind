#ifndef USER_H
#define USER_H

#include <string>
#include <map>

struct User {
    std::string username;
    std::string password;
    std::map<int, char> userResponses; // Mapping question number to user's chosen option
};

#endif // USER_H
