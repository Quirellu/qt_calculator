
#include "CalculationEngine.h"

#include <cassert>
#include <iostream>
#include <stack>

#include "token.h"


double CalculationEngine::calculate(std::string_view expression)
{
    if (expression.empty())
    {
        return 0;
    }
    return evaluatePostfix(parseExpression(tokenize(expression))) ;
}

std::vector<Token> CalculationEngine::tokenize(const std::string_view expression)
{
    std::string temp_numeric_string;
    std::vector<Token> result;

    for (const char character: expression)
    {
        if (std::isdigit(character) || character == '.')
        {
            temp_numeric_string.push_back(character);

        }else
        {
            // For end of numbers
            if (!temp_numeric_string.empty())
            {
                result.emplace_back(Token(temp_numeric_string,true));
                temp_numeric_string.clear();
            }

            // For operators and functions
            result.emplace_back(Token(std::string{character},false));
        }
    }

    //When numbers neded
    if (!temp_numeric_string.empty())
    {
        result.emplace_back(Token(temp_numeric_string,true));
    }

    return result;
}

std::vector<Token> CalculationEngine::parseExpression(const std::vector<Token>& tokens)
{
    /*
     * Shunting-Yard Algorithm
     */
    std::vector<Token> postfix;
    std::stack<Token> operatorStack;

    postfix.reserve(tokens.size());

    for (const auto& token :tokens)
    {
        if (token.is_number)
        {
            postfix.push_back(token);
            continue;
        }

        if (!token.is_number){
           while (!operatorStack.empty() &&
               operatorPrecedence[operatorStack.top().content] > operatorPrecedence[token.content])
           {
               const auto topOperator = operatorStack.top();
               operatorStack.pop();

               postfix.push_back(topOperator);
           }

            operatorStack.push(token);
        }
    }

    while (!operatorStack.empty())
    {
        postfix.push_back(operatorStack.top());
        operatorStack.pop();
    }

    return postfix;
}

double CalculationEngine::evaluatePostfix(const std::vector<Token>& tokens)
{
    std::stack<double> numberStack;

    std::string finalAnswer;

    for (const auto& [content, is_number]: tokens)
    {
        if (is_number)
        {
            numberStack.push(std::stod(content));
        }
        else
        {
            if (numberStack.size() < 2)
            {
                throw std::runtime_error("Error evaluating postfix notation. Potential invalid expression");
            }

            const auto val2 = numberStack.top();
            numberStack.pop();
            const auto val1 = numberStack.top();
            numberStack.pop();

            switch (resolveOperatorString(content))
            {
            case Addition:
                numberStack.push(val1 + val2);
                break;
            case Subtraction:
                numberStack.push(val1 - val2);
                break;
            case Multiplication:
                numberStack.push(val1 * val2);
                break;
            case Division:
                numberStack.push(val1 / val2);
                break;
            case UnknownOperator:
                throw std::runtime_error("Unknown operator: " + content);
            }
        }

    }

    assert(numberStack.size() == 1);
    return numberStack.top();
}

Operators CalculationEngine::resolveOperatorString(const std::string_view operatorString)
{
    if (operatorString == "+")
    {
        return Addition;
    }
    if (operatorString == "-")
    {
        return Subtraction;
    }
    if (operatorString == "*")
    {
        return Multiplication;
    }
    if (operatorString == "/")
    {
        return Division;
    }

    return UnknownOperator;
}