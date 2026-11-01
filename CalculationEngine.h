
#ifndef QT_CALCULATOR_CALCULATION_ENGINE_H
#define QT_CALCULATOR_CALCULATION_ENGINE_H

#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include <vector>

#include "token.h"

enum Operators
{
    UnknownOperator,
    Addition,
    Subtraction,
    Multiplication,
    Division
};

class CalculationEngine
{

public:
    double calculate(std::string_view expression);

private:
    std::vector<Token> tokenize(std::string_view expression);
    std::vector<Token> parseExpression(const std::vector<Token>& tokens);
    double evaluatePostfix(const std::vector<Token>& tokens);
    Operators resolveOperatorString(std::string_view operatorString);

    std::array<std::string, 4> operatorArray {"+", "-", "*", "/"};
    std::map<std::string, uint8_t> operatorPrecedence{{"*", 1} , {"/", 1}, {"+", 0}, {"-",0}};



};


#endif //QT_CALCULATOR_CALCULATION_ENGINE_H
