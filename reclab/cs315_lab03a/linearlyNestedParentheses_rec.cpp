#include <iostream>
#include "Token.hpp"
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

bool isList(Lex *lex)
{

    Token token = lex->getToken();

    if( token.isEndOfText() )
        return true;

    if( Lex::isNotLeftThing( token ) )
        return false;

    Token Ltoken = token;
    token = lex->getToken();

    if( token.isRightParen() ||  token.isRightCurly() ||  token.isRightBracket() )
        return Lex::LmatchR( Ltoken , token );

    lex -> ungetToken();

    if( isList(lex) ) {

      token = lex->getToken();

      if( token.isRightParen() )
        {
          if( Ltoken.isLeftParen() )
            return true;
          return false;
        }

      if( token.isRightCurly() )
        {
          if( Ltoken.isLeftCurly() )
            return true;
          return false;
        }

      if( token.isRightBracket() )
        {
          if( Ltoken.isLeftBracket() )
            return true;
          return false;
        }
    }

    return false;
}

int main()
{
    std::string input = readAnInputLine();
//    std::string input = "(  (()  ())  )))";

    Lex *lex = new Lex(input);

    Token token = lex->getToken();  // get a token to determine if the input is empty or not.
    if( token.isEndOfText() ) {
        std::cout << "No input to parse!\n";
        delete lex;
        return 0;
    }

    // The input was not empty. So, put the token back and have isList to parse the input list.
    lex->ungetToken();

    bool wasList = isList(lex);

    // Get another token to determine if we have exhausted the input or not.
    token = lex->getToken();

    if( ! wasList || ! token.isEndOfText() )
        std::cout << "The input string is not a well-formed nested parenthetical.\n";
    else
        std::cout << "Input is a well-formed nested parenthetical.\n";

    delete lex;
    return 0;
}
