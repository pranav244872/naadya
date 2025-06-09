#include "../include/tokens.hpp"

Token::Token(
    const TokenType& inputTokenType,
    const std::string& inputLexeme,
    const int line
) {
    this->tokenType = inputTokenType;
    this->lexeme = inputLexeme;
    this->line = line;
}

// What to do if it is printed
std::ostream& operator<<(std::ostream& os, const Token& token) {
    // Convert the TokenType to a string representation with "TOK_" prefix
    switch (token.tokenType) {
        case TokenType::LPAREN: os << "(TOK_LPAREN, "; break;
        case TokenType::RPAREN: os << "(TOK_RPAREN, "; break;
        case TokenType::LCURLY: os << "(TOK_LCURLY, "; break;
        case TokenType::RCURLY: os << "(TOK_RCURLY, "; break;
        case TokenType::LSQUAR: os << "(TOK_LSQUAR, "; break;
        case TokenType::RSQUAR: os << "(TOK_RSQUAR, "; break;
        case TokenType::COMMA: os << "(TOK_COMMA, "; break;
        case TokenType::DOT: os << "(TOK_DOT, "; break;
        case TokenType::PLUS: os << "(TOK_PLUS, "; break;
        case TokenType::MINUS: os << "(TOK_MINUS, "; break;
        case TokenType::STAR: os << "(TOK_STAR, "; break;
        case TokenType::SLASH: os << "(TOK_SLASH, "; break;
        case TokenType::CARET: os << "(TOK_CARET, "; break;
        case TokenType::MOD: os << "(TOK_MOD, "; break;
        case TokenType::COLON: os << "(TOK_COLON, "; break;
        case TokenType::SEMICOLON: os << "(TOK_SEMICOLON, "; break;
        case TokenType::QUESTION: os << "(TOK_QUESTION, "; break;
        case TokenType::NOT: os << "(TOK_NOT, "; break;
        case TokenType::GT: os << "(TOK_GT, "; break;
        case TokenType::LT: os << "(TOK_LT, "; break;
        case TokenType::GE: os << "(TOK_GE, "; break;
        case TokenType::LE: os << "(TOK_LE, "; break;
        case TokenType::NE: os << "(TOK_NE, "; break;
        case TokenType::EQ: os << "(TOK_EQ, "; break;
        case TokenType::ASSIGN: os << "(TOK_ASSIGN, "; break;
        case TokenType::GTGT: os << "(TOK_GTGT, "; break;
        case TokenType::LTLT: os << "(TOK_LTLT, "; break;
        case TokenType::IDENTIFIER: os << "(TOK_IDENTIFIER, "; break;
        case TokenType::STRING: os << "(TOK_STRING, "; break;
        case TokenType::INTEGER: os << "(TOK_INTEGER, "; break;
        case TokenType::FLOAT: os << "(TOK_FLOAT, "; break;
        case TokenType::IF: os << "(TOK_IF, "; break;
        case TokenType::THEN: os << "(TOK_THEN, "; break;
        case TokenType::ELSE: os << "(TOK_ELSE, "; break;
        case TokenType::TRUE: os << "(TOK_TRUE, "; break;
        case TokenType::FALSE: os << "(TOK_FALSE, "; break;
        case TokenType::AND: os << "(TOK_AND, "; break;
        case TokenType::OR: os << "(TOK_OR, "; break;
        case TokenType::WHILE: os << "(TOK_WHILE, "; break;
        case TokenType::DO: os << "(TOK_DO, "; break;
        case TokenType::FOR: os << "(TOK_FOR, "; break;
        case TokenType::FUNC: os << "(TOK_FUNC, "; break;
        case TokenType::NULL_KEYWORD: os << "(TOK_NULL_KEYWORD, "; break;
        case TokenType::END: os << "(TOK_END, "; break;
        case TokenType::PRINT: os << "(TOK_PRINT, "; break;
        case TokenType::PRINTLN: os << "(TOK_PRINTLN, "; break;
        case TokenType::RET: os << "(TOK_RET, "; break;
        default: os << "(TOK_UNKNOWN, "; break;
    }
    // Print the lexeme in the second part of the pair
    os << "'" << token.lexeme << "', " << token.line << ")";
    return os;
}
