#ifndef FileSystemBuilder_HPP
#define FileSystemBuilder_HPP
#include "DirectoryNode.hpp"
#include "Lex.hpp"


class FileSystemBuilder {
public:
  // DO NOT NEED TO MAKE AN INSTANCE (object)
  // FileSystemBuilder* builder =
  //   new FileSystemBuilder();
  // builder->buildFileSystem(lex);
  // XXXXXXXXXXXXXXX

  // DirectoryNode* tree =
  //   FileSystemBuilder::buildFileSystem(lex);
  static DirectoryNode* buildFileSystem( Lex* );

private:
  static void fillDirNotChild( Lex*, DirectoryNode* );
  static bool seekNextColon( Lex* );

};
#endif
