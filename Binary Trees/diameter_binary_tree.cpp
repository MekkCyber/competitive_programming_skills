/*
    Write a function that takes in a Binary Tree and returns its diameter. The
    diameter of a binary tree is defined as the length of its longest path, even
    if that path doesn't pass through the root of the tree.
        
    A path is a collection of connected nodes in a tree, where no node is
    connected to more than two other nodes. The length of a path is the number of
    edges between the path's first node and its last node.
Ex : tree =   1
            /   \
           3     2
         /   \ 
        7     4
       /       \
      8         5
     /           \
    9             6
output : 6 // 9-8-7-3-4-5-6
*/


/*
    the idea is to keep track of the height as well as the diameter of each node when doing the dfs search.
    when we are at a leaf node, we return {0,0}, and we start revisiting the tree bottom-up, for every node
    we have the maxDiameterSoFar = max(rightTree.diameter,leftTree.diameter), and the longest path that can
    pass through that node longestPath = rightTree.path+leftTree.path, so the current diameter is the max of 
    these two values and the current height is just the max of longestPath incremented by one
*/


using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};
//vector[0] diameter and vector[1] the height
vector<int> dfs(BinaryTree *tree){
  if (tree == nullptr){
    return {0,0};
  }
  vector<int> right_tree = dfs(tree->right);
  vector<int> left_tree = dfs(tree->left);

  int maxDiameterNow = max(right_tree[0],left_tree[0]);
  int maxDiameterThroughNode = right_tree[1]+left_tree[1];
  int currentDiameter = max(maxDiameterNow,maxDiameterThroughNode);
  int currentHeight = max(right_tree[1],left_tree[1])+1;
  return {currentDiameter,currentHeight};
}

int binaryTreeDiameter(BinaryTree *tree) {
  return dfs(tree)[0];
}
