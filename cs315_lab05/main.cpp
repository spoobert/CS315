/*
Author: Devin T. Brown
Course: CS 315
Assignment: Lab 5 Part B
 */
#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

int main( int argc, char* argv[] ) {
  //creat a tree and then print the values of its nodes
  //from the smalles to the largets

  BinSearchTree* tree = new BinSearchTree();
  BinSearchTree* otree = new BinSearchTree();
  //BinSearchTree* dtree = new BinSearchTree();

  int v;
  otree->iterInsert( 75 );
  otree->iterInsert( 100 );
  otree->iterInsert(10 );
  otree->iterInsert( 35 );
  otree->iterInsert( 33 );
  otree->iterInsert( 11 );

  while( std::cin >> v ) {
    tree->iterInsert( v );
  }
  //tree->levelOrderDump();
  //tree->levelOrderDump();
  //tree->valuesAtLevel( 1 );
  //tree->valuesAtLevel( 2 );
  //tree->valuesAtLevel( 1 );
  tree->valuesAtLevel( 2 );
  //tree->valuesAtLevel( 4 );

  //dtree = tree->differenceOf( otree );
  //dtree->levelOrderDump();


 //std::cout << tree->maxDepth() << std::endl;

  return 0;
}
