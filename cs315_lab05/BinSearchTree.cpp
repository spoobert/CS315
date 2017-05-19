/*
Author: Devin T. Brown
Course: CS 315
Assignment: Lab 5 Part B
 */
#include "BinSearchTree.hpp"
#include "TreeNode.hpp"
#include <iostream>
#include<queue>

TreeNode* BinSearchTree::local_insert( TreeNode* root, int v ) {
  if( root == nullptr )
    return new TreeNode( v );
  if( root->value() < v )
    root->rightSubtree( local_insert( root->rightSubtree(), v) );
  else
    root->leftSubtree( local_insert( root->leftSubtree(), v ) );

  return root;
}

void BinSearchTree::insert( int v ){
  if( ! find(v) )
    root = local_insert( root, v );
}


bool BinSearchTree::find( int v ){
  return local_find( root, v );
}

TreeNode* BinSearchTree::local_find( TreeNode* root, int v ){
  if( root == nullptr )
    return root;
  if( root->value() == v )
    return root;
  if( root->value() < v )
    return local_find( root->rightSubtree(), v );
  if( root->value() > v )
    return local_find( root->leftSubtree(), v );
  return root;
}


void BinSearchTree::iterInsert( int v ){
  if( iterFind(v) )
    return;
  root = local_iterInsert( root, v );
}

//don't have to consider the t == v case because find is called first
TreeNode* BinSearchTree::local_iterInsert( TreeNode* root, int v ){
  TreeNode* t = root;
  while( t != nullptr ){
    if( t->value() < v ){
      if( t->rightSubtree() == nullptr) {
        t->rightSubtree( new TreeNode(v) );
        return root;
      }
      t = t->rightSubtree();
      continue;
    }
    if( t->leftSubtree() == nullptr ){
      t->leftSubtree( new TreeNode(v) );
      return root;
    }
    t = t->leftSubtree();
  }
  return new TreeNode(v);
}

bool BinSearchTree::remove( int v ){
  if( ! find( v ) )
    return false;
  if( root == NULL )
    return false;
  if( root->leftSubtree() == NULL && root->rightSubtree() == NULL ){
    if( root->value() == v ){
      delete root;
        return true;
    }
    return false;
  }
  if( root->value() == v ){
    if( root->leftSubtree() != NULL && root->rightSubtree() != NULL ){
      int maxInt = local_findMax( root->leftSubtree() );
      this->remove( maxInt );
      root->value() = maxInt;
      return true;
    }
    else if( root->leftSubtree() == NULL ){
      int minVal = local_findMin( root->rightSubtree() );
      this->remove( minVal );
      root->value() = minVal;
      return true;
    }
    else{
      int maxVal = local_findMax( root->leftSubtree() );
      this->remove( maxVal );
      root->value() = maxVal;
      return true;
    }
  }

  TreeNode* parent;
  TreeNode* key = root;
  while( key->value() != v  ){
    parent = key;
    if( key->value() < v ) key = key->rightSubtree();
    else if( key->value() > v ) key = key->leftSubtree();
  }
  if( key->leftSubtree() != NULL && key->rightSubtree() != NULL ){
    int maxInt = local_findMax( key->rightSubtree() );
    this->remove( maxInt );
    key->value() = maxInt;
    return true;
  }
  if( key->leftSubtree() != NULL ){
    if( parent->leftSubtree()->value() == v )
      parent->leftSubtree( key->leftSubtree() );
    else
      parent->rightSubtree( key->leftSubtree() );
    delete key;
    return true;
  }
  if( key->rightSubtree() != NULL ){
    if( parent->leftSubtree()->value() == v )
      parent->leftSubtree( key->rightSubtree() );
    else
      parent->rightSubtree( key->rightSubtree() );
    delete key;
    return true;
  }
  if( key->leftSubtree() == NULL && key->rightSubtree() == NULL){
    if( parent->leftSubtree()->value() == v )
      parent->leftSubtree( NULL );
    else
      parent->rightSubtree( NULL );
    delete key;
    return true;
  }
 else
  return false;
}

void BinSearchTree::levelOrderDump(){
  if( root == NULL )
    return;
  std::queue<TreeNode*> q;
  q.push( root );
  while( ! q.empty() ){
    TreeNode* tmp = q.front();
    std::cout << tmp->value() << std::endl;
    q.pop();
    if( tmp->leftSubtree() != NULL ){
      q.push( tmp->leftSubtree() );
    }
    if( tmp->rightSubtree() != NULL){
      q.push( tmp->rightSubtree() );
    }
  }

}





bool BinSearchTree::iterFind( int v ){
  return local_iterFind( root, v );
}

TreeNode* BinSearchTree::local_iterFind(TreeNode* root, int v){
  while( root != nullptr ){
    if( root->value() < v )
      root = root->rightSubtree();
    else if( root->value() > v )
      root = root->leftSubtree();
    else if( root->value() == v )
      return root;
  }
  return root;
}

void BinSearchTree::inorderDump(){
  local_inorderDump( root );
}


void BinSearchTree::local_inorderDump(TreeNode* root ){
  if( root == nullptr )
    return;
  local_inorderDump( root->leftSubtree() );
  std::cout<< root->value() << std::endl;
  local_inorderDump( root->rightSubtree() );
}

int BinSearchTree::maxDepth(){
  return local_maxDepth( root );
}

int BinSearchTree::local_maxDepth( TreeNode* root ){
  if( root == nullptr )
      return 0;
  int Rheight = local_maxDepth( root->rightSubtree() );
  int Lheight = local_maxDepth( root->leftSubtree() );

  return 1 + ( Rheight < Lheight ? Lheight : Rheight );

}

int BinSearchTree::iterMaxDepth(){
  if( root == NULL )
    return 0;
  std::queue<TreeNode*> q;
  q.push( root );
  int height = 0;
  while( ! q.empty() ){
    int nodeCount = q.size();
    for( int i = 0 ; i < nodeCount ; i++ ){
      TreeNode* tmp = q.front();
      if( tmp->leftSubtree() != NULL) q.push( tmp->leftSubtree() );
      if( tmp->rightSubtree() != NULL) q.push( tmp->rightSubtree() );
      q.pop();
    }
    ++height;
  }
  return height;
}


int BinSearchTree::kthSmallest(int k ){
  int count = 0;
  return local_kthSmallest( root, k, &count );
}

int BinSearchTree::local_kthSmallest(TreeNode *root, int k, int *count){
  if( root == nullptr )
    return 0;

  int kth = local_kthSmallest( root->leftSubtree(), k, count);

  if( kth )
    return kth;

  if( ++*count == k )
    return root->value();

  return local_kthSmallest( root->rightSubtree(), k, count);

}


void BinSearchTree::valuesAtLevel( int k ){
  int lvl = 1;
  valuesAtLevel( lvl , k , root );
}

void BinSearchTree::valuesAtLevel( int lvl, int k, TreeNode* root ){
  if( k == 1 ){
    std::cout << root->value() << std::endl;
    return;
  }
  if( lvl == k ){
    std::cout << root->value() << std::endl;
    return;
  }
  else {

    if( root->leftSubtree() != NULL && root->rightSubtree() == NULL ){
      valuesAtLevel( lvl + 1, k , root->leftSubtree() );
    }
    else if ( root->leftSubtree() == NULL && root->rightSubtree() != NULL ){
      valuesAtLevel( lvl + 1, k , root->rightSubtree() );
    }
    else if( root->leftSubtree() != NULL && root->rightSubtree() != NULL ){
      valuesAtLevel( lvl + 1, k , root->leftSubtree() );
      valuesAtLevel( lvl + 1, k , root->rightSubtree() );
    }
  }
}




void BinSearchTree::iterValuesAtLevel( int v ){
  if( root == NULL)
  return;

  std::queue<TreeNode*> q;
  q.push( root );

  for(int i = 1; i < v ; i++){
    int count = q.size();
    for( int i = 0; i < count; i++ ){
      TreeNode* tmp = q.front();
      if( tmp->leftSubtree() != NULL ) q.push( tmp->leftSubtree() );
      if( tmp->rightSubtree() != NULL) q.push( tmp->rightSubtree() );
      q.pop();
    }
  }

  int count = q.size();
  for( int i = 0; i < count; i++){
    TreeNode* tmp = q.front();
    std::cout << tmp->value() << std::endl;
    q.pop();
  }
}

int BinSearchTree::local_findMax( TreeNode* root ){
  while( root->rightSubtree() != NULL) root = root->rightSubtree();
  return root->value();
}

int BinSearchTree::local_findMin( TreeNode* root ){
  while( root->leftSubtree() != NULL) root = root->leftSubtree();
  return root->value();
}

bool BinSearchTree::hasRootToLeafSum(int sum ){
  int key = 0;
  return local_hasRootToLeafSum( root , sum , key );
}

bool BinSearchTree::local_hasRootToLeafSum( TreeNode* root , int sum , int key ){
  if( root == NULL )
    return false;
  key += root->value();
  if( root->leftSubtree() == NULL && root->rightSubtree() == NULL ){
    if( key == sum )
      return true;
    return false;
  }
    bool foundL = local_hasRootToLeafSum( root->leftSubtree(), sum , key );
    bool foundR = local_hasRootToLeafSum( root->rightSubtree(), sum, key );

    return foundL || foundR;
}

bool BinSearchTree::areIdentical( BinSearchTree *bst ){
  TreeNode* valTree = bst->root;
  return local_areIdentical( root , valTree );
}

bool BinSearchTree::local_areIdentical( TreeNode* keyRoot , TreeNode* valRoot ){
  if( keyRoot == NULL && valRoot == NULL )
    return true;
  if( keyRoot == NULL || valRoot == NULL )
    return false;


  bool lState = local_areIdentical( keyRoot->leftSubtree() , valRoot->leftSubtree() );
  bool rState = local_areIdentical( keyRoot->rightSubtree() , valRoot->rightSubtree() );

  return lState && rState;
}

BinSearchTree* BinSearchTree::intersectWith( BinSearchTree* bst ){
  BinSearchTree* newTree = new BinSearchTree();
  return local_intersectWith( newTree , bst->root );

}

BinSearchTree* BinSearchTree::local_intersectWith( BinSearchTree* newTree , TreeNode* root ){
  if( root == NULL )
    return newTree;
  if( this->find( root->value() ) )
    newTree->insert( root->value() );


   local_intersectWith( newTree , root->leftSubtree() );
   local_intersectWith( newTree , root->rightSubtree() );

  return newTree;
}

BinSearchTree* BinSearchTree::unionWith(BinSearchTree *bst){
  BinSearchTree* newTree = new BinSearchTree();
  return local_unionWith( newTree , root , bst->root );
}

BinSearchTree* BinSearchTree::local_unionWith( BinSearchTree* newTree, TreeNode* root , TreeNode* oRoot ){

  if( root == NULL || oRoot == NULL ){
    if( root != NULL ){
      newTree->insert( root->value() );
      local_unionWith( newTree , root->leftSubtree() , oRoot );
      local_unionWith( newTree , root->rightSubtree() , oRoot );
    }
    if( oRoot != NULL ){
      newTree->insert( oRoot->value() );
      local_unionWith( newTree , root , oRoot->leftSubtree() );
      local_unionWith( newTree , root , oRoot->rightSubtree() );
    }
    return newTree;

  }
  newTree->insert( oRoot->value() );
  newTree->insert( root->value() );

   local_unionWith( newTree , root->leftSubtree() ,oRoot->leftSubtree() );
   local_unionWith( newTree , root->rightSubtree() , oRoot->rightSubtree() );

  return newTree;
}

BinSearchTree* BinSearchTree::differenceOf(BinSearchTree *bst){
  BinSearchTree* newTree = new BinSearchTree();
  return local_differenceOf( newTree , bst->root );
}

BinSearchTree* BinSearchTree::local_differenceOf( BinSearchTree* newTree , TreeNode* root ){
  if( root == NULL )
    return newTree;
  if( ! this->find( root->value() ) )
      newTree->insert( root->value() );


  local_differenceOf( newTree , root->leftSubtree() );
  local_differenceOf( newTree , root->rightSubtree() );

  return newTree;
}

int BinSearchTree::size(){
  return local_size( root );
}

int BinSearchTree::local_size( TreeNode* root ){
  if( root == NULL )
    return 0;
  int lsize = local_size( root->leftSubtree() );
  int rsize = local_size( root->rightSubtree() );

  return 1 + rsize + lsize;

}
