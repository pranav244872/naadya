#pragma once

#include <string>
#include <iostream>

////////////////////////////////////////////////////
// Enum class to define the different token types
///////////////////////////////////////////////////
enum class TokenType {

    // Single-char tokens
    LPAREN,      // (
    RPAREN,      // )
    LCURLY,      // {
    RCURLY,      // }
    LSQUAR,      // [
    RSQUAR,      // ]
    COMMA,       // ,
    DOT,         // .
    PLUS,        // +
    MINUS,       // -
    STAR,        // *
    SLASH,       // /
    CARET,       // ^
    MOD,         // %
    COLON,       // :
    SEMICOLON,   // ;
    QUESTION,    // ?
    NOT,         // ~
    GT,          // >
    LT,          // <

    // Two-char tokens
    GE,          // >=
    LE,          // <=
    NE,          // !=
    EQ,          // ==
    ASSIGN,      // :=
    GTGT,        // >>
    LTLT,        // <<

    // Literals
    IDENTIFIER,
    STRING,
    INTEGER,
    FLOAT,

    // Keywords
    IF,
    THEN,
    ELSE,
    TRUE,
    FALSE,
    AND,
    OR,
    WHILE,
    DO,
    FOR,
    FUNC,
    NULL_KEYWORD,
    END,
    PRINT,
    PRINTLN,
    RET
};

////////////////////////////////////////////////////
// Token class definition
///////////////////////////////////////////////////

class Token {
private:
    TokenType tokenType;
    std::string lexeme;
    int line;

public:
    Token(
        const TokenType& inputTokenType,
        const std::string& inputLexeme,
        const int line
    );

    // What to do if it is printed using <<
    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};
