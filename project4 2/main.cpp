#include "DirectoryNode.hpp"
#include "Lex.hpp"
#include "FileSystemBuilder.hpp"
#include "DirectoryEntry.hpp"
#include <fstream>
#include <string>
#include <vector>
int main( int argc, const char* const argv[]){
  std::fstream input(argv[1]);
  std::string str;
  while( input ){
    std::string temp;
    std::getline(input,temp );
    str += temp;
    }
  Lex *lex = new Lex(str);
  DirectoryNode *root = FileSystemBuilder::buildFileSystem( lex );
  DirectoryEntry dir( root );

  std::cout << "*** depth() ***" << std::endl;
  std::cout << dir.depth() << std::endl;
  std::cout << std::endl;

  //std::cout << "*** pwd() ***" << std::endl;
  //std::cout << dir.pwd() << std::endl;
  // std::cout << std::endl;

  std::cout << "*** cd() ***" << std::endl;
  std::cout << dir.cd( "/project1/RomanCalculatorStudentFiles") << std::endl;
  std::cout << std::endl;

  //dir.cd("../");

  std::cout << "*** pwd() ***" << std::endl;
  std::cout << dir.pwd() << std::endl;
  std::cout << std::endl;

  std::cout << "*** ls() ***" << std::endl;
  std::vector<std::string> sv = dir.ls("/project1/RomanCalculatorStudentFiles" );
  for(auto child : sv ){
    std::cout << child << std::endl;
  }
  std::cout<< std::endl;
  std::cout << "*** cd() ***" << std::endl;
  dir.cd();
  std::cout << "*** duplicate() ***" << std::endl;
  DirectoryEntry* newDir =  dir.duplicate();
  std::cout<< "XXX"<< std::endl;

  std::cout << "*** pwd() ***" << std::endl;
  std::cout << newDir->pwd() << std::endl;
  std::cout << "***ls()***" << std::endl; 
  std::vector<std::string> s1 = newDir->ls("/project1/RomanCalculatorStudentFiles" );
  for(auto child : s1 ){
    std::cout << child << std::endl;
  }

  std::cout << dir.hasSubstructure(newDir);


  return 0;
}
