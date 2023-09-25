/*
    Write a function that takes in a Binary Tree and returns its max path sum.
    A path is a collection of connected nodes in a tree, where no node is
    connected to more than two other nodes; a path sum is the sum of the values of
    the nodes in a particular path.
Ex :   1
    /     \
   2       3
 /   \   /   \
4     5 6     7
output : 18 // 5 + 2 + 1 + 3 + 7
*/

/*
    The intuition is the same as the diameter problem, the only difference is that here we need to account for 
    negative numbers so we check for the max(right.maxBranchSum+left.maxBranchSum+tree->value,left.maxBranchSum+tree->value,right.maxBranchSum+tree->value);
    instead of just adding right.maxBranchSum+left.maxBranchSum+tree->value like we did in the diameter case
*/

// My approach
#include <vector>
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

struct TreeInfo{
  int maxBranchSum;
  int maxPathSum;
};

TreeInfo dfs(BinaryTree *tree){
  if (tree==nullptr){
    return TreeInfo{0,INT_MIN};
  }
  TreeInfo right = dfs(tree->right);
  TreeInfo left = dfs(tree->left);

  int maxPathSumForNow = max(right.maxPathSum,left.maxPathSum);
  int maxPathThroughNode = max(right.maxBranchSum+left.maxBranchSum+tree->value,\
                               max(left.maxBranchSum+tree->value,\
                               right.maxBranchSum+tree->value));
  int maxPathSum = max(maxPathThroughNode,maxPathSumForNow);
  int maxBranchSum = tree->value+max(right.maxBranchSum,left.maxBranchSum);
  return {maxBranchSum,maxPathSum};
}

int maxPathSum(BinaryTree tree) {
  
  return dfs(&tree).maxPathSum;
}
