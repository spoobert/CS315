/*
Author: Devin T. Brown
Course: CS 315
Assignment: Lab 5 Part B
 */
class TreeNode;
#include<queue>

class BinSearchTree{
public:
  void insert( int v );
  bool find( int v );
  bool iterFind( int v );
  int size();
  void inorderDump();
  void levelOrderDump();
  bool remove( int v );
  int kthSmallest( int k );
  void valuesAtLevel( int k );
  void valuesAtLevel(int lvl, int k, TreeNode*);
  void iterValuesAtLevel( int k );
  int maxDepth();
  int iterMaxDepth();
  void iterInsert( int v );
  bool hasRootToLeafSum( int sum );
  bool areIdentical( BinSearchTree *bst );
  BinSearchTree *intersectWith( BinSearchTree *bst );
  BinSearchTree *unionWith( BinSearchTree *bst );
  BinSearchTree *differenceOf( BinSearchTree *bst );
  int findMin();
  int findMax();



private:
  int local_size( TreeNode* root );
  BinSearchTree* local_differenceOf( BinSearchTree*, TreeNode* );
  BinSearchTree* local_unionWith( BinSearchTree* newTree , TreeNode* root , TreeNode* oRoot );
  BinSearchTree* local_intersectWith( BinSearchTree* , TreeNode* );
  bool local_hasRootToLeafSum(TreeNode*,int ,int key);
  int local_kthSmallest( TreeNode* root, int k, int* count );
  TreeNode* local_insert( TreeNode *, int );
  void local_inorderDump( TreeNode* );
  TreeNode* local_find( TreeNode* , int );
  TreeNode* local_iterFind( TreeNode*, int );
  bool local_inorderDump( TreeNode*, int );
  TreeNode* local_iterInsert( TreeNode*, int );
  int local_maxDepth( TreeNode* );
  int local_findMin( TreeNode* );
  int local_findMax( TreeNode* );
  bool local_areIdentical( TreeNode* root, TreeNode* valTree );
  TreeNode* root;
};
