/*
    Given two binary trees, merge them and return the resulting tree.
    If two nodes overlap during the merger then sum the values, otherwise use the existing node.
    Ex : 
tree1 =   1
        /   \
       3     2
     /   \
    7     4

tree2 =   1
        /   \
       5     9
     /      / \
    2      7   6
output :  2
        /   \
      8      11
    /  \    /  \
  9     4  7    6
*/


// My approach 
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void dfs(BinaryTree* tree1, BinaryTree* tree2, BinaryTree* parent, bool comingFromLeft){
  if (tree1==nullptr && tree2==nullptr){
    return;
  }
  if (tree1==nullptr){
    tree1 = new BinaryTree(tree2->value);
    if (comingFromLeft){
      parent->left = tree1;
    } else {
      parent->right = tree1;
    }
    dfs(tree1->left,tree2->left,tree1,true);
    dfs(tree1->right,tree2->right,tree1,false);
  } else if (tree1 && tree2){
    tree1->value = tree1->value+tree2->value;
    dfs(tree1->left,tree2->left,tree1,true);
    dfs(tree1->right,tree2->right,tree1,false);
  }
  
}
BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
  dfs(tree1,tree2,nullptr,true);
  return tree1;
}


// A far better approach 

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
  if (!tree1) return tree2;
  if (!tree2) return tree1;
  tree1->value += tree2->value;
  tree1->left = mergeBinaryTrees(tree1->left,tree2->left);
  tree1->right = mergeBinaryTrees(tree1->right,tree2->right);
  return tree1;
}
