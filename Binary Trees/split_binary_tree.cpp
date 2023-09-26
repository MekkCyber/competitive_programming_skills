/*
    Write a function that takes in a Binary Tree with at least one node and
    checks if that Binary Tree can be split into two Binary Trees of equal sum by
    removing a single edge. If this split is possible, return the new sum of each
    Binary Tree, otherwise return 0. Note that you do not need to return the edge
    that was removed.
    The sum of a Binary Tree is the sum of all values in that Binary Tree.
Ex : tree= 1
        /     \
       3       -2
     /   \    /  \
    6    -5  5    2
  /
 2
output : 6 // Remove the edge to the left of the root node, creating two trees, each with sums of 6
*/

/*
    The idea is to notice that when splitting a tree one of the results of the split must be a subtree, so we just need to
    calculate all the sums of the subtrees recursively, and compare them to total_tree_sum/2 (if its even)
*/

// Solution
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};
int dfsTotalSum(BinaryTree* tree){
  if (!tree){
    return 0;
  }
  int right_sum = dfsTotalSum(tree->right);
  int left_sum = dfsTotalSum(tree->left);
  return right_sum+left_sum+tree->value;
}
int dfsSubtreeSum(BinaryTree* tree, int targetSum, bool* splitable){
  if (!tree){
    return 0;
  }
  int right_subtree_sum = dfsSubtreeSum(tree->right,targetSum,splitable);
  int left_subtree_sum = dfsSubtreeSum(tree->left,targetSum,splitable);
  int subtree_sum = right_subtree_sum+left_subtree_sum+tree->value;
  if (subtree_sum==targetSum){
    *splitable = true;
  }
  return subtree_sum;
}

int splitBinaryTree(BinaryTree* tree) {
  int total_sum = dfsTotalSum(tree);
  if (total_sum&1){
    return 0;
  } else {
    int split_sum = total_sum/2;
    bool splitable = false;
    dfsSubtreeSum(tree,split_sum,&splitable);
    if (splitable){
      return split_sum;
    } else {
      return 0;
    }
  }
}
