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
