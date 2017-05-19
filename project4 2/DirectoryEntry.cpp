#include "DirectoryNode.hpp"
#include "DirectoryEntry.hpp"
#include <queue>
#include<algorithm>



DirectoryEntry::DirectoryEntry(){
  rootDir = NULL;
  cwd = NULL;
}

DirectoryEntry::DirectoryEntry( DirectoryNode* newDir ){
  rootDir = newDir;
  cwd = newDir;
}

int DirectoryEntry::depth(){
  return depth( rootDir );
}

int DirectoryEntry::depth( DirectoryNode* tmpDir ){
    int maxDepth = 1;
    std::vector<DirectoryNode*> children = tmpDir->getChildren();
    for( auto child : children ){
      int currentDepth = depth( child ) + 1;
      if( maxDepth < currentDepth )
        maxDepth = currentDepth;
    }
    return maxDepth;
}

std::string DirectoryEntry::pwd( ){
  std::string strPath = "";
  DirectoryNode* tmp = cwd;
  while( tmp != NULL ){
    std::string tempName = tmp->name();
    strPath = "/" + tempName + strPath;
    tmp = tmp->getParent();
  }
  return strPath;
}

std::string DirectoryEntry::cd(){
  if( cwd != rootDir ){
    cwd = rootDir;
  }
  return cwd->name();
}

std::string DirectoryEntry::cd( std::string path ){

  DirectoryNode* tmp = cwd;
  std::string tmpStr = "";
  std::queue<std::string>q;
  int i = 0;
  while( path[i] != '\0'){
    while( path[i] != '/' && path[i] != '\0' )
      tmpStr += path[i++];
    q.push(tmpStr);
    tmpStr = "";
    if( path[i] != '\0')
      i++;
  }
  while( ! q.empty() ){
    std::string tmpStr = q.front();
    q.pop();
    if( tmpStr == "" ){
      tmp = rootDir;
    }
    else if( tmpStr == "."){
      tmp = tmp;
    }
    else if( tmpStr == ".." ) {
      tmp = tmp->getParent();
    }
    else {
      std::vector<DirectoryNode*> children = tmp->getChildren();
      bool found = false;
      for( auto child : children ){
        if(child->name() == tmpStr && child->isDirectory() ) {
          tmp = child;
          found = true;
          break;
        }
      }
      if( found == true )
        continue;
      return path + " No such directory ";
    }
  }
  cwd = tmp;
  return cwd->name();
}

std::vector<std::string> DirectoryEntry::ls(){
  std::vector<DirectoryNode*> children = cwd->getChildren();
  std::vector<std::string> lsStr;
  for(auto child: children){
    lsStr.push_back(child->name());
  }
  return lsStr;
}

std::vector<std::string> DirectoryEntry::ls(std::string path){
  DirectoryNode* tmp = cwd;
  cd(path);
  std::vector<std::string> lsCurrent = ls();
  cwd = tmp;
  return lsCurrent;
}

DirectoryEntry* DirectoryEntry::duplicate(){
  DirectoryEntry* newEntry = new DirectoryEntry( Duplicate( cwd ) );
  return newEntry;
}

DirectoryNode* DirectoryEntry::Duplicate( DirectoryNode* oldNode ){
  DirectoryNode* newNode = new DirectoryNode();
    newNode->name( oldNode->name() );
    newNode->path( oldNode->path() );
    newNode->type( oldNode->type() );
    newNode->parent( oldNode->parent() );
    std::vector<DirectoryNode*> children = oldNode->getChildren();
    for(auto child: children){
      DirectoryNode* chilDupe = Duplicate( child );
      chilDupe->setParent( newNode );
      newNode->addDirectoryNode( chilDupe );
    }
  return newNode;
}

std::vector<std::string> DirectoryEntry::find(std::string path){
    return find( path, cwd );
}

std::vector<std::string> DirectoryEntry::find(std::string path, DirectoryNode* theCwd ){
    std::vector<std::string> match;
    if( theCwd->name().find( path ) != std::string::npos ){
        match.push_back( theCwd->name() );
    }
    std::vector<DirectoryNode*> children = theCwd->getChildren();
    for(auto child: children){
      std::vector<std::string> temp = find( path, child );
      match.insert(match.end(), temp.begin(), temp.end());
    }
    return match;
}

bool DirectoryEntry::areTheSame(DirectoryEntry *dirEntry){
  return areTheSame( cwd, dirEntry->cwd );
}
bool DirectoryEntry::areTheSame(DirectoryNode* calleeDirEnt, DirectoryNode* lookDirEnt) {
  if( calleeDirEnt->name() == lookDirEnt->name() &&  calleeDirEnt->type() == lookDirEnt->type() &&
    calleeDirEnt->type() == lookDirEnt->type() &&  calleeDirEnt->parent() == lookDirEnt->parent()){
    std::vector<DirectoryNode*> calleeChildren = calleeDirEnt->getChildren();
    std::vector<DirectoryNode*> lookDirEntChildren = lookDirEnt->getChildren();
    if( calleeChildren.size() == lookDirEntChildren.size() ){
      bool result = true;
      for(int i = 0; i < calleeChildren.size(); i++){
        if( ! areTheSame( calleeChildren[i], lookDirEntChildren[i] ) )
          result = false;
      }
      if(result)
        return true;
    }
  }
  return false;
}

bool DirectoryEntry::hasSubstructure( DirectoryEntry *dirEntry){
  return hasSubstructure( cwd, dirEntry->cwd );

}

bool DirectoryEntry::hasSubstructure(DirectoryNode* calleeDirEnt, DirectoryNode* lookDirEnt){
  if( areTheSame( calleeDirEnt, lookDirEnt ) )
    return true;
  std::vector<DirectoryNode*>  calleeChildren = calleeDirEnt->getChildren();
  for(auto child: calleeChildren ){
    if ( hasSubstructure( child, lookDirEnt ) )
      return true;
  }
  return false;
}
//not the root: fromPath
void DirectoryEntry::move(std::string fromPath, std::string toPath ){
  if( fromPath == toPath )
    return;
  DirectoryNode* saveCwd = cwd;
  cd( fromPath );
  DirectoryNode* moveThis = cwd;
  std::vector<DirectoryNode*> oldSibs = moveThis->getParent()->getChildren();
  oldSibs.erase(std::find(oldSibs.begin(), oldSibs.end( ), moveThis ) );
  cd( toPath );
  cwd->addDirectoryNode( moveThis );
  moveThis->setParent( cwd );
  cwd = saveCwd;
}
