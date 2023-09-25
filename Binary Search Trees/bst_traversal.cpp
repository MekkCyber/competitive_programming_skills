#include <vector>
using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
};
// All of the traversals are in O(n) time and O(n) space
void inOrderTraverse(BST* tree, vector<int>& array) {
  if (!tree){
    return;
  }
  inOrderTraverse(tree->left,array);
  array.push_back(tree->value);
  inOrderTraverse(tree->right,array);
}

void preOrderTraverse(BST* tree, vector<int>& array) {
  if (!tree){
    return;
  }
  array.push_back(tree->value);
  preOrderTraverse(tree->left,array);
  preOrderTraverse(tree->right,array);
}

void postOrderTraverse(BST* tree, vector<int>& array) {
  if (!tree){
    return;
  }
  postOrderTraverse(tree->left,array);
  postOrderTraverse(tree->right,array);
  array.push_back(tree->value);
}
