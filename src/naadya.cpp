#include <fstream>
#include <iostream>
#include <string>

#include "../include/lexer.hpp"
#include "../include/tokens.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./naadya <filename>\n";
        std::exit(1);
    }

    std::string filename = argv[1];
    std::cout << "Filename: " << filename << std::endl;

    // Open the file
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        std::exit(1);
    }

    // Read the file into a vector of characters
    std::vector<char> source;
    char ch;
    while(file.get(ch)) {
        source.push_back(ch); // Read one character at a time
    }

    // Close the file
    file.close();

    std::cout << "LEXER: \n";
    std::vector<Token> tokens = Lexer(source).tokenize();

    for(const auto token: tokens) {
        std::cout << token << std::endl;
    }

    return 0;
}
