#include "Token.hpp"
#include <iostream>



void Token::print()
{


    if( this->isLeftParen() )
      std::cout << '(';

    else if( this->isRightParen() )
      std::cout << ')';

    else if( this->isLeftBracket() )
      std::cout << '[';

    else if( this->isRightBracket() )
      std::cout << ']';

    else if( this->isLeftCurly() )
      std::cout << '{';

    else if( this->isRightCurly() )
      std::cout << '}';

    else if( this->isColon() )
      std::cout << ':';

    else if( this->isTick() )
      std::cout << '\'';

    else if( this->isComma() )
      std::cout << ',';

    else if( this->isName() )
      std::cout << ' ' << this->getName() << ' ';

  }
