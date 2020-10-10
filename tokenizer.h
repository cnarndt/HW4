//
// Created by Clayton on 10/10/2020.
//

#ifndef HW4_TOKENIZER_H
#define HW4_TOKENIZER_H
#include <vector>
#include <string>
// Get a line of text from the user. Returns true if the
// value entered is not blank, othewise false
bool ReadLine(std::string &str);



unsigned StringToTokensWS(const std::string &input,std::vector<std::string> &tokens);

// Determine if each token if it is an integer, identifier,
// string, whitespace, or unknown
void AnalyzeTokens(const std::vector<std::string> &tokens);

#endif
