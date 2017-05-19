#ifndef _DirectoryEntry_hpp
#define _DirectoryEntry_hpp
#include "DirectoryNode.hpp"
#include <vector>
#include <string>

class DirectoryEntry{
public:
  DirectoryEntry();
  DirectoryEntry( DirectoryNode* );
  int depth();
  int depth( DirectoryNode* );
  std::string pwd();
  std::string cd();
  std::string cd(std::string path);
  std::vector<std::string> ls();
  std::vector<std::string> ls(std::string path);
  DirectoryEntry *duplicate();
  DirectoryNode* Duplicate(DirectoryNode*);

  DirectoryEntry *duplicate(std::string path);
  std::vector<std::string> find(std::string path);
  std::vector<std::string> find(std::string path, DirectoryNode*);

  bool hasSubstructure(DirectoryEntry *dirEntry);
  bool hasSubstructure(DirectoryNode *dirEntry, DirectoryNode*);
  bool areTheSame(DirectoryEntry *dirEntry);
  bool areTheSame(DirectoryNode*, DirectoryNode*);
  void move(std::string fromPath, std::string toPath);

private:
    DirectoryNode *rootDir;
    DirectoryNode *cwd;
};
#endif
