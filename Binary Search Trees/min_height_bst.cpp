/* 
    Write a function that takes in a non-empty sorted array of distinct integers,
    constructs a BST from the integers, and returns the root of the BST.
    The function should minimize the height of the BST.
    Ex : array = [1, 2, 5, 7, 10, 13, 14, 15, 22]
    output : 
         10
       /     \
      2      14
    /   \   /   \
   1     5 13   15
          \       \
           7      22
// This is one example of a BST with min height
// that you could create from the input array.
// You could create other BSTs with min height
// from the same array; for example:
         10
       /     \
      5      15
    /   \   /   \
   2     7 13   22
 /           \
1            14

*/

/*
    the idea is to notice that if we want to have the same number of nodes on the left subtree and on the right subtree
    the node should be the median of the array. So we just construct the tree recursively by each time taking median
    and passing the elements in the left of the median to the left subtree and the elements in the right to the right subtree.
    Notice that the fact that all the tree elements are distinct is important for our reasoning
*/

// Solution

using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST* minHeightBst(vector<int> array) {
  // Write your code here.
  if (array.size()==0){
    return nullptr;
  }
  int median = (array.size()-1)/2;
  BST* tree = new BST(array[median]);
  tree->left = minHeightBst(vector<int>(array.begin(),array.begin()+median));
  tree->right = minHeightBst(vector<int>(array.begin()+median+1,array.end()));
  return tree;
}

