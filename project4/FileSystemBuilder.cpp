#include "DirectoryNode.hpp"
#include "FileSystemBuilder.hpp"
#include "Lex.hpp"

DirectoryNode* FileSystemBuilder::buildFileSystem( Lex *lex )
{
  Token token = lex->getToken();
  DirectoryNode *dir = new DirectoryNode();

  if( token.isEndOfText() )
    return nullptr;

  if( ! token.isLeftCurly() )
    exit(1);
  fillDirNotChild( lex, dir );
  //at next token(unGotten) after type (value)
  token = lex->getToken();
  //token is either } or ,
  if( token.isRightCurly() )
    return dir;
  //not a } so , then child
  if ( ! seekNextColon(lex) )
    exit(1);
  // skip over [
  lex->getToken();
  token = lex->getToken();
  while( token.isLeftCurly() ){
    lex->ungetToken();
    DirectoryNode *newDir = buildFileSystem( lex );
    newDir->setParent( dir );
    dir->addDirectoryNode( newDir );
    token = lex->getToken();
    if( token.isComma() )
      token = lex->getToken();
  }

  token= lex->getToken();
  //token is }

  return dir;
}

bool FileSystemBuilder::seekNextColon( Lex* lex ) {
  if( ! lex->getToken().isKey() )
    return false;
  if( ! lex->getToken().isColon())
    return false;
  return true;
}

//Lex is at {
void FileSystemBuilder::fillDirNotChild( Lex *lex, DirectoryNode* dir ){
  if ( ! seekNextColon(lex) )
    exit(1);
  dir->parent( lex->getToken().getName() );
  lex->getToken();
  if( ! seekNextColon(lex) )
    exit(1);
  dir->path( lex->getToken().getName() );
  lex->getToken();
  if ( ! seekNextColon(lex) )
    exit(1);
  dir->name( lex->getToken().getName() );
  lex->getToken();
  if ( ! seekNextColon(lex) )
    exit(1);
  dir->type( lex->getToken().getName() );
  lex->getToken();
  lex->ungetToken();
}
