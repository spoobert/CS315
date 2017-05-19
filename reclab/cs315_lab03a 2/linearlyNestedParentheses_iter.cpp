#include <iostream>

#include "Lex.hpp"

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

    int numOpenParens = 0;
    Lex *lex = new Lex(input);

    Token token = lex->getToken();
    while( token.isLeftParen() ) {  // count the number of open parentheses.
        numOpenParens++;
        token = lex->getToken();
    }

    if( token.isEndOfText() && numOpenParens == 0 ) {
        // We didn't see any open parentheses.
        std::cout << "No input to parse!\n";
        delete lex;
        return 0;
    }

    // We must have gotten a token that is not a left parenthesis.
    // It might be a right parenthesis or something else.

    lex->ungetToken();  // put the last token back!

    // We are about to get a new token. In this context, it seems
    // silly to return the token that we just got from Lex and
    // immediately ask for it back in the next statement. However, in
    // a situation where you are trying to process one part of the
    // input, you will often have to read an extra token to know that
    // you are finished. In that case, you would to return that extra
    // token to Lex so that you can retrieve it when you're ready to
    // process the next piece of the input.

    token = lex->getToken();  // get a new token.
    while( token.isRightParen() ) {
        numOpenParens--;
        token = lex->getToken();
    }

    if( numOpenParens != 0 || ! token.isEndOfText())
        std::cout << "The input string is not a well-formed nested parenthetical.\n";
    else
        std::cout << "Input is a well-formed nested parenthetical.\n";

    delete lex;
    return 0;
}
