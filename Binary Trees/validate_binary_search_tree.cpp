/*
  Write a function that takes in a potentially invalid Binary Search Tree (BST)
  and returns a boolean representing whether the BST is valid.
  Each BST node has an integer value, a
  left child node, and a right child node. A node is
  said to be a valid BST node if and only if it satisfies the BST
  property: its value is strictly greater than the values of every
  node to its left; its value is less than or equal to the values
  of every node to its right; and its children nodes are either valid
  BST nodes themselves or None / null.
*/

/*
    The key idea is to notice that every node in the tree has a minimum value and a maximum value
    and for each node, for the bst to be valid, its value needs to lay in that interval
*/

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

bool validateBstHelper(BST* tree, int min_, int max_);

bool validateBst(BST* tree) {
  return validateBstHelper(tree,INT_MIN,INT_MAX);
}

bool validateBstHelper(BST* tree, int min_, int max_){
  if (tree->value<min_ || tree->value>=max_){
    return false;
  }
  if (tree->left && !validateBstHelper(tree->left,min_,tree->value)) return false;
  if (tree->right && !validateBstHelper(tree->right,tree->value,max_)) return false;
  return true;
}