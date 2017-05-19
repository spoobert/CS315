#include "tokenizer.hpp"
#include "Token.hpp"
#include <vector>
#include <iostream>
using namespace std;

<Token *> &tokenizer::tokenize()
{
  //whitespace for pushback
  expression += " ";
  string romanBuilder = "";

  for( auto token : expression  )
    {
      if( isRoman( token ) )
	{
	  romanBuilder += token;
	  continue; 
	}
      
      if( ! romanBuilder.empty() )
	{
	  token.pushback( new Token( romanBuilder ) );
	  romanBuilder += "";
	}
      if( isOperator( token ) || isAVariable( token ) )
	{
	  token.pushback( new Token( token ) );
	}
    }
  Token *eolToken = new Token();
  eolToken -> eol(true);
  token.pushback( eolToken );
  return token; 
}

