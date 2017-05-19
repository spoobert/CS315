#include "Token.hpp"
#include "Lex.hpp"
#include<cstring>
#include<iostream>
#include<fstream>

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

int main( int argc , char *argv[] )
{


  std::string jstr;
  std::string tempstr;
  std::ifstream jfile( argv[ 1 ] , std::ifstream::in );

  while( jfile.good() )
  {
    getline( jfile , tempstr );
    jstr += tempstr;
  }

  Lex *lex = new Lex(jstr);

  Token token = lex->getToken( );

  while( ! token.isEndOfText() )
  {
    token.print( );
    std::cout<< std::endl;
    token = lex -> getToken();
  }


    return 0;

}
