#include "../include/lexer.hpp"
#include <cctype>

////////////////////////////////////////////////////////////
// helper functions
////////////////////////////////////////////////////////////

// returns current curr and increments the curr
char Lexer::advance() {
    if (this->curr >= this->source.size()) return '\0';
    return this->source[this->curr++];
}

// returns current curr without incrementing
char Lexer::peek() {
    if (this->curr >= this->source.size()) return '\0';
    return this->source[this->curr];
}

// returns the character n chars infront of curr
char Lexer::lookahead(int n) {
    if (curr + n >= source.size()) {
        return '\0';
    }
    return source[curr + n];
}

// bool returns if current character is some expected char
bool Lexer::match(char expected) {
    if (this->curr >=this->source.size()) return false;
    if (source[this->curr] != expected) return false;
    // if it is a match, we consume that character
    this->curr += 1;
    return true;
}

// adds the token to the token list which is to be returned
void Lexer::addToken(const TokenType& tokenType) {
    if (this->start > this->curr) return;
    std::string lexeme(
        this->source.begin() + this->start,
        this->source.begin() + this->curr
    );
    this->tokens.push_back(Token(tokenType, lexeme, this->line));
}

////////////////////////////////////////////////////////////

// Constructor
Lexer::Lexer(const std::vector<char>& inputSource) {
    this->source = inputSource;

    this->keywordMap = {
        {"if", TokenType::IF},
        {"then", TokenType::THEN},
        {"else", TokenType::ELSE},
        {"true", TokenType::TRUE},
        {"false", TokenType::FALSE},
        {"and", TokenType::AND},
        {"or", TokenType::OR},
        {"while", TokenType::WHILE},
        {"do", TokenType::DO},
        {"for", TokenType::FOR},
        {"func", TokenType::FUNC},
        {"null", TokenType::NULL_KEYWORD},
        {"end", TokenType::END},
        {"print", TokenType::PRINT},
        {"println", TokenType::PRINTLN},
        {"ret", TokenType::RET}
    };
}


// Goes through characters line by line and gets tokens
// Adds those tokens in token vector
// returns the token vector
std::vector<Token> Lexer::tokenize() {
    while (this->curr < this->source.size()) {
        this->start = this->curr;
        char ch = this->advance();

        // Ignore whitespace and newline
        if (ch == '\n') this->line += 1;
        else if (ch == '\t') continue;
        else if (ch == '\r') continue;
        else if (ch == ' ') continue;

            // ignore comment line
        else if (ch == '#') {
            while (
                this->curr < this->source.size() 
                && this->peek() != '\n'
            ) {
                this->advance();
            }
        }

        // Single-char tokens
        else if (ch == '(') this->addToken(TokenType::LPAREN);
        else if (ch == ')') this->addToken(TokenType::RPAREN);
        else if (ch == '{') this->addToken(TokenType::LCURLY);
        else if (ch == '}') this->addToken(TokenType::RCURLY);
        else if (ch == '[') this->addToken(TokenType::LSQUAR);
        else if (ch == ']') this->addToken(TokenType::RSQUAR);
        else if (ch == ',') this->addToken(TokenType::COMMA);
        else if (ch == '.') this->addToken(TokenType::DOT);
        else if (ch == '+') this->addToken(TokenType::PLUS);
        else if (ch == '-') this->addToken(TokenType::MINUS);
        else if (ch == '*') this->addToken(TokenType::STAR);
        else if (ch == '/') this->addToken(TokenType::SLASH);
        else if (ch == '^') this->addToken(TokenType::CARET);
        else if (ch == '%') this->addToken(TokenType::MOD);
        else if (ch == ';') this->addToken(TokenType::SEMICOLON);
        else if (ch == '?') this->addToken(TokenType::QUESTION);
            // ==
        else if (ch == '='){
            if (this->match('=')) this->addToken(TokenType::EQ);
        }
        // ~ && ~=
        else if (ch == '~') {
            if (this->match('=')) {
                this->addToken(TokenType::NE);
            } else {
                this->addToken(TokenType::NOT);
            }
        }
        // < && <=
        else if (ch == '<') {
            if (this->match('=')) {
                this->addToken(TokenType::LE);
            } else {
                this->addToken(TokenType::LT);
            }
        }
        // > && >=
        else if (ch == '>') {
            if (this->match('=')) {
                this->addToken(TokenType::GE);
            } else {
                this->addToken(TokenType::GT);
            }
        }
        // Handle := assignment opperator
        else if (ch == ':') {
            if (this->match('=')) {
                this->addToken(TokenType::ASSIGN);
            } else {
                this->addToken(TokenType::COLON);
            }
        }
        // Handle numbers - integers or floats
        else if (std::isdigit(ch)) {
            while (std::isdigit(this->peek())) this->advance();
            if (this->peek() == '.' && std::isdigit(this->lookahead())) {
                this->advance();
                while(std::isdigit(this->peek())) this->advance();
                this->addToken(TokenType::FLOAT);
            } else {
                this->addToken(TokenType::INTEGER);
            }
        }
        // Handle strings
        else if (ch == '\'' || ch == '\"') {
            char quote = ch;
            bool unterminated = false;
            while (this->peek() != quote) {
                if (this->peek() == '\0' || this->peek() == '\n') {
                    unterminated = true;
                    break;
                }
                this->advance();
            }
            if (unterminated) {
                std::cerr << "Error: Unterminated string at line " << this->line << std::endl;
            } else {
                this->advance();
                this->addToken(TokenType::STRING);
            }
        }
        // Handle identifier and keywords
        else if (std::isalpha(static_cast<unsigned char>(ch)) || ch == '_') {
            while (
                std::isalnum(static_cast<unsigned char>(this->peek())) 
                || this->peek() == '_'
            ) {
                this->advance();
            }
            std::string lexeme(
                this->source.begin() + this->start,
                this->source.begin() + this->curr
            );
            if (this->keywordMap.count(lexeme)) {
                this->tokens.push_back(
                    Token(this->keywordMap[lexeme], lexeme, this->line)
                );
            } else {
                this->addToken(TokenType::IDENTIFIER);
            }
        }

    }

    return this->tokens;
}
