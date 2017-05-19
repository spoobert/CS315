#include "Lex.hpp"
#include <ctype.h>

enum { COLON = ':', TICK = '\'' , LCURLY = '{' , RCURLY = '}' ,
        LBRACKET = '[' , RBRACKET = ']' , LPAREN = '(' , RPAREN = ')' , COMMA = ','};

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

std::string Lex::parseTick()
{
  int idx = whereToStart;
  std::string name = "";
  name += inputToTokenize[ idx++ ];

  while( inputToTokenize[ idx ] != '\'')
  {
    //after 's the [idx++] should be always on s otherwise while loop breaks
    if( inputToTokenize[ idx ] == '\\' && inputToTokenize[ idx + 1] == '\'')
    {
      name += inputToTokenize[ idx++ ];
      name += inputToTokenize[ idx++ ];
    }
    name += inputToTokenize[ idx++ ];
  }

  name += inputToTokenize[ idx++ ];

  whereToStart = idx;

  return name;

}

std::string Lex::parseName()
{
    // precondition: whereToStart < inputToTokenize.length() is true.
    // That is, there is at least one non-space character (may or many not be a name character)
    // left in inputToTokenize.

    std::string name = "";

    unsigned int idx = whereToStart;

    while( idx < inputToTokenize.length() && isalpha( inputToTokenize[idx] ) )
        name += inputToTokenize[ idx++ ];

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

    if( inputToTokenize[whereToStart] == COLON ) {
        lastToken = Token(inputToTokenize[whereToStart]);
        whereToStart++;
        return lastToken;
    }

    if( inputToTokenize[ whereToStart ] == COMMA )
    {
      lastToken = Token( inputToTokenize[ whereToStart ] );
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

    std::string name;

    if( inputToTokenize[ whereToStart ] == TICK )
    {
      name = parseTick();
      lastToken = Token( name );
      return lastToken;
    }


    name = parseName();

    lastToken = Token(name);

    return lastToken;

}

void Lex::ungetToken()
{
    haveAnUngottenToken = true;
}
