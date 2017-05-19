
#ifndef _DirectoryNode_HPP
#define _DirectoryNode_HPP

#include "Lex.hpp"
#include<iostream>
#include<vector>

class DirectoryNode {
public:
    DirectoryNode(): _isFile(false), _isDirectory(false), _parent(""), _path(""), _name(""), _type("") , parentNode(NULL) {}

    bool isFile() { return _isFile; }  // is this a file directory type?
    bool isDirectory() { return _isDirectory; }  // is this a directory, directory type?

    void addDirectoryNode(DirectoryNode *list) { children.push_back(list); }
    int numEntries() { return children.size(); }
    std::vector<DirectoryNode *> getChildren() { return children; }

    std::string parent() { return _parent; }
    void parent(std::string pStr) { _parent = pStr; }

    std::string path() { return _path; }
    void path(std::string pStr) { _path = pStr; }

    std::string name() { return _name; }
    void name(std::string pStr) { _name = pStr; }

    std::string type() { return _type; }
    void type(std::string pStr) { _type = pStr; _isFile = (pStr == "file"); _isDirectory = ( pStr == "directory"); }

    DirectoryNode* getParent() { return parentNode; }
    void setParent( DirectoryNode* par ) { parentNode = par; }

private:
    std::string _parent, _path, _name, _type;
    DirectoryNode *parentNode;
    std::vector<DirectoryNode *> children;
    bool _isFile, _isDirectory;

};
#endif
