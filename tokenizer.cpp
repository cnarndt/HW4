//
// Created by Clayton on 10/10/2020.
//

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
