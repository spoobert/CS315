#include<iostream>
#include<cstring>

#ifndef __Token_hpp
#define __Token_hpp

class Token
{
public:
    // variable charToken represents a one-character token such as ( and ).
    // To create such token, use the constructor that accepts a character.

    // variable nameTokenValue represents an atom -- a sequence of character.
    // To create such a token, use the constructor that accepts a string.

    // To create an end-of-text token, create an instance of this
    // class using the contructor that doesn't take any arguments and
    // then, call function makeEndOfText() on that instance.  

    Token(): charToken('\0'), nameTokenValue(""), endOfText(false) {}
    Token(char c): charToken(c), nameTokenValue(""), endOfText(false) {}
    Token(std::string st): charToken('\0'), nameTokenValue(st), endOfText(false) {}
    
    void makeLeftParen()  { charToken = '('; }
    void makeRightParen() { charToken = ')'; }
    void makeEndOfText()  { endOfText = true; }

    bool isLeftParen()    { return charToken == '('; }
    bool isRightParen()   { return charToken == ')'; }
    bool isName()         { return nameTokenValue != ""; }
    bool isEndOfText()    { return endOfText; }

    std::string getName() { return nameTokenValue; }

private:
    char charToken;
    std::string nameTokenValue;
    bool endOfText;
};

#endif
