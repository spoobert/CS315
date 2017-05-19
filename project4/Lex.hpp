
#ifndef __LEX_HPP
#define __LEX_HPP

#include "Token.hpp"

#include<iostream>
#include<cstring>


class Lex
{
public:
    Lex(std::string);
    Token getToken();
    void ungetToken();

private:
    std::string inputToTokenize;
    unsigned int whereToStart;
    bool haveAnUngottenToken;
    Token lastToken;
    int skipWhiteSpaces();
    std::string parseKey();
    std::string parseValue(); 
};

#endif
