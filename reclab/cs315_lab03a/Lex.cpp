
#include "Lex.hpp"
#include <ctype.h>

enum { LPAREN = '(', RPAREN = ')' , LCURLY = '{' , RCURLY = '}' ,
        LBRACKET = '[' , RBRACKET = ']' };

Lex::Lex(std::string input): inputToTokenize(input), whereToStart(0), haveAnUngottenToken(false), lastToken("") {}

int Lex::skipWhiteSpaces()
{
    // Scan the inputToTokenize string until either we exhaust the input or we find a non-blank character.
    while( whereToStart < inputToTokenize.length() && isspace(inputToTokenize[whereToStart]) )
        whereToStart++;
    return whereToStart;
}
bool Lex::isNotLeftThing( Token token )
{
  return  ! token.isLeftParen() && ! token.isLeftBracket() && ! token.isLeftCurly() ;
}
bool Lex::LmatchR( Token L , Token R )
{
  if( L.isLeftParen() )
    {
      if( R.isRightParen() )
        return true;
      return false;
    }

  if( L.isLeftCurly() )
    {
      if( R.isRightCurly() )
        return true;
      return false;
    }

  if( L.isLeftBracket() )
    {
      if( R.isRightBracket() )
        return true;
      return false;
    }
  return false;
}

std::string Lex::parseName()
{
    // precondition: whereToStart < inputToTokenize.length() is true.
    // That is, there is at least one non-space character (may or many not be a name character)
    // left in inputToTokenize.

    std::string name = "";

    unsigned int idx = whereToStart;
    while( idx < inputToTokenize.length() && isalpha( inputToTokenize[idx] ) ) {
        name += inputToTokenize[idx];
        idx++;
    }

    if( idx - whereToStart == 0 ) {  // inputToTokenize[whereToStart] must havenot been a letter.
        std::cout << "Unexpected character in input. The character is ->" << inputToTokenize[whereToStart]
                  << "<-" << std::endl;
        exit(1);
    }

    whereToStart = idx;
    return name;
}

Token Lex::getToken()
{
    if( haveAnUngottenToken ) {
        haveAnUngottenToken = false;
        return lastToken;
    }

    skipWhiteSpaces();
    if( whereToStart == inputToTokenize.length() ) {
        Token token;
        token.makeEndOfText();
        return lastToken = token;
    }

    if( inputToTokenize[whereToStart] == LPAREN || inputToTokenize[whereToStart] == RPAREN  ) {
        lastToken = Token(inputToTokenize[whereToStart]);
        whereToStart++;
        return lastToken;
    }

    if( inputToTokenize[whereToStart] == LBRACKET || inputToTokenize[whereToStart] == RBRACKET  ) {
        lastToken = Token(inputToTokenize[whereToStart]);
        whereToStart++;
        return lastToken;
    }

    if( inputToTokenize[whereToStart] == LCURLY || inputToTokenize[whereToStart] == RCURLY  ) {
        lastToken = Token(inputToTokenize[whereToStart]);
        whereToStart++;
        return lastToken;
    }

    std::string name = parseName();
    lastToken = Token(name);
    return lastToken;

}

void Lex::ungetToken()
{
    haveAnUngottenToken = true;
}
