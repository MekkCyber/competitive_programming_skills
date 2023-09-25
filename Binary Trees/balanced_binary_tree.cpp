/*
    You're given the root node of a Binary Tree. Write a function that returns
    <span>true</span> if this Binary Tree is height balanced and
    <span>false</span> if it isn't.
    A Binary Tree is height balanced if for each node in the tree, the difference
    between the height of its left subtree and the height of its right subtree is
    at most <span>1</span>.
*/

/*
    its just a dfs search to determine the heights of the left subtree and right subtree, if the difference
    is greater than 1 , the tree is not balanced else we keep the dfs. 
    while in the approach used in the code below, we used a global variable that we passed by reference to the dfs
    we can rely on an other approach : each dfs returns the height as well as if the subtree it returns from is 
    balanced or not, so to for a certain node to verify if the subtree is balanced we need to check
    (right_tree.isBalanced && left_tree.isBalanced && abs(right_tree.height-left_tree.height)<=1). The edge case in this 
    approach is node==nullptr and returns {True,-1} (-1 is the height because node==nullptr means the node doesnt exist but even 0 works fine)
*/

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int dfs(BinaryTree *node, bool* balanced){
  if (node == nullptr){
    return 0;
  }
  int height_right = dfs(node->right,balanced);
  int height_left = dfs(node->left,balanced);
  if (abs(height_right-height_left) > 1) *balanced = false;
  return max(height_right,height_left)+1;
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
  // Write your code here.
  bool balanced = true;
  dfs(tree,&balanced);
  return balanced;
  
}