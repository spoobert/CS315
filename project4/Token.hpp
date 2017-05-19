#include<iostream>
#include<cstring>

#ifndef __Token_hpp
#define __Token_hpp

enum class TokenType : char {
  LCURLY = '{',   RCURLY = '}',
  LBRACKET = '[', RBRACKET = ']',
  COMMA = ',' , EoT, COLON = ':',
  KEY, VALUE
};

class Token
{
public:



    Token(): type( TokenType::EoT ), stringValue("") {}
    Token(TokenType t): type(t) {}
    Token(char c): type((TokenType)c), stringValue("") {}
    Token(TokenType t, std::string st): type(t), stringValue(st) {}


    bool isLeftCurly()    { return type == TokenType::LCURLY; }
    bool isRightCurly()   { return type == TokenType::RCURLY; }
    bool isLeftBracket()    { return type == TokenType::LBRACKET; }
    bool isRightBracket()   { return type == TokenType::RBRACKET; }
    bool isComma()          { return type == TokenType::COMMA; }
    bool isColon()          { return type == TokenType::COLON; }
    bool isKey()         { return  type == TokenType::KEY; }
    bool isValue()         { return  type == TokenType::VALUE; }
    bool isEndOfText()    { return type == TokenType::EoT; }

    std::string getName() { return stringValue; }

private:
    TokenType type;
    std::string stringValue;
};

#endif
