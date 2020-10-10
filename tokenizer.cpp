//
//  Clayton Arndt
// CS201
// Homework 4


#include "tokenizer.h"
#include <iostream>
#include <sstream>
#include <cctype>

bool ReadLine(std::string &str)
{
    if (!std::getline(std::cin, str))
        return false;

    if (str == "")
        return false;

    return true;
}

unsigned StringToTokensWS(const std::string &input,std::vector<std::string> &tokens)
{
    std::istringstream ss(input);
    std::string token;
    unsigned numTokens = 0;

    while (ss >> token)
    {
        tokens.push_back(token);
        numTokens++;
    }

    tokens.push_back("");
    return numTokens;
}


// Determine if each token if it is an integer, identifier,
// string, whitespace, or unknown
void AnalyzeTokens(const std::vector<std::string> &tokens)
{
    for (unsigned i = 0; i < tokens.size(); i++)
    {
        std::string token = tokens[i];

        // Check if it's a whitespace
        if (token == "")
        {
            std::cout << "[whitespace]  " << "\"" << token << "\"" << std::endl;
            continue;
        }

        // Check if it's a number
        int number;
        std::istringstream ss(token);
        ss >> number;

        if (!ss.fail() && ss.eof())
        {
            std::cout << "[integer]     " << number << std::endl;
            continue;
        }

        // Check if it's a string literal
        if (token.length() >= 2 && token.front() == '"' && token.back() == '"')
        {
            std::cout << "[string]      " << '"' << '\\' << '"' << token.substr(1, token.size() - 2) << '\\' << '"' << '"' << std::endl;
            continue;
        }

        // Check if it's an identifier, it should start with a letter or underscore
        if (isalpha(token.front()) || token.front() == '_')
        {
            // The rest should be a letter, number or underscore too
            bool isIdentifier = true;

            for (unsigned i = 1; i < token.size(); i++){
                if (isalnum(token[i]) || token[i] == '_')
                    continue;
                isIdentifier = false;
                break;
            }

            if (isIdentifier){
                std::cout << "[identifier]  " << "\"" << token << "\"" << std::endl;
                continue;
            }
        }

        // If all the above validations didn't go through then it's an 'other'
        std::cout << "[other]       " << "\"" << token << "\"" << std::endl;
    }
}