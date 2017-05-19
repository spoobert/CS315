
#include "Lex.hpp"
#include <ctype.h>

Lex::Lex(std::string input): inputToTokenize(input), whereToStart(0), haveAnUngottenToken(false), lastToken( ) {}

int Lex::skipWhiteSpaces()
{
    // Scan the inputToTokenize string until either we exhaust the input or we find a non-black character.
    while( whereToStart < inputToTokenize.length() && isspace(inputToTokenize[whereToStart]) )
        whereToStart++;
    return whereToStart;
}

std::string Lex::parseKey()
{
    // precondition: whereToStart < inputToTokenize.length() is true.
    // That is, there is at least one non-space character (may or many not be a name character)
    // left in inputToTokenize.

    std::string key = "";

    unsigned int idx = whereToStart;
    while( idx < inputToTokenize.length() && isalpha(inputToTokenize[idx]) ) {
      key += inputToTokenize[idx];
      idx++;
    }

    if( idx - whereToStart == 0 ) {  // inputToTokenize[whereToStart] must havenot been a letter.
        std::cout << "Unexpected character in input. The character is ->" << inputToTokenize[whereToStart]
                  << "<- wts:" << whereToStart << std::endl;
        exit(1);
    }

    whereToStart = idx;
    return key;
}

std::string Lex::parseValue(){

  std::string value = "";
  int idx = ++whereToStart;
  while( idx < inputToTokenize.length() && inputToTokenize[idx] != '\'' ){
    if( inputToTokenize[idx] == '\\')
      idx++;
    value += inputToTokenize[idx++];
  }
  if( inputToTokenize.length() - idx == 0 ){
    std::cout << " wrong token: " << inputToTokenize[whereToStart] << std::endl;
    exit(1);
  }
  whereToStart = ++idx;
  return value;
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
        return lastToken = token;
    }

    char c = inputToTokenize[whereToStart];
    if ( c == (char)TokenType::LCURLY
      || c == (char)TokenType::RCURLY
      || c == (char)TokenType::LBRACKET
      || c == (char)TokenType::RBRACKET
      || c == (char)TokenType::COLON
      || c == (char)TokenType::COMMA
      ) {
        lastToken = Token(inputToTokenize[whereToStart]);
        whereToStart++;
        return lastToken;
    }

    if( inputToTokenize[whereToStart] == '\'' ){
      std::string value = parseValue();
      lastToken = Token( TokenType::VALUE, value);
      return lastToken;
    }

    std::string key = parseKey();
    //removed skipWhiteSpaces() from this line
    lastToken = Token(TokenType::KEY, key);
    return lastToken;
}

void Lex::ungetToken()
{
    haveAnUngottenToken = true;
}
