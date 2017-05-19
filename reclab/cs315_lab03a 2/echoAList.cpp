#include "Token.hpp"
#include "Lex.hpp"
#include<cstring>
#include<iostream>

std::string readAnInputLine()
{
    std::string input;
    std::cout << "Enter a recursive list.\n";
    getline(std::cin, input);
    if( ! std::cin.good() ) {
        std::cout << "Input stream seems to be corrupt. Terminating...\n";
        exit(1);
    }
    return input;
}

int main()
{
    std::string input = readAnInputLine();

    Lex *lex = new Lex(input);

    Token token = lex->getToken();
    while( ! token.isEndOfText() ) {
        if( token.isLeftParen() )
            std::cout << '(';
        else if( token.isRightParen() )
            std::cout << ')';
        else if( token.isName() )
            std::cout << ' ' << token.getName() << ' ';
        else std::cout << "Perhaps you created a new token and didn't account for it?\n";
        token = lex->getToken();
    }
    std::cout << std::endl;
    return 0;
}
