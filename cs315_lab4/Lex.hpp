
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
    std::string lastNameToken;

    int skipWhiteSpaces();
    std::string parseName();
};

#endif
