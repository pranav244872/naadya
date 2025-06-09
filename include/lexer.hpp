#pragma once

#include <vector>
#include <unordered_map>

#include "../include/tokens.hpp"

class Lexer {
private:
    std::vector<Token> tokens;
    std::vector<char> source;

    int curr = 0;
    int start = 0;
    // keep track of current line, when we encounter \n increment
    int line = 1; 

    ////////////////////////////////////////////////////////////
    // helper functions
    ////////////////////////////////////////////////////////////
    // returns current curr and increments the curr
    char advance();
    // returns current curr without incrementing
    char peek();
    // returns the character n chars infront of curr
    char lookahead(int n = 1);
    // bool returns if current character is some expected char
    bool match(char expected);
    // adds the token to the token list which is to be returned
    void addToken(const TokenType& tokenType);
    ////////////////////////////////////////////////////////////

    // Stores keyword to token map
    std::unordered_map<std::string, TokenType> keywordMap;
public:
    // Constructor
    Lexer(const std::vector<char>& inputSource);

    // Goes through characters line by line and gets tokens
    // Adds those tokens in token vector
    // returns the token vector
    std::vector<Token> tokenize();
};
