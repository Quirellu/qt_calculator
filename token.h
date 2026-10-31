
#ifndef QT_CALCULATOR_TOKEN_H
#define QT_CALCULATOR_TOKEN_H
#include <string>

struct Token
{
    std::string content;
    bool is_number;

    bool operator==(const Token&) const = default;
};




#endif //QT_CALCULATOR_TOKEN_H
