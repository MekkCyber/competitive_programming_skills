/*
  Write a function that takes in a Binary Tree and returns a list of its branch
  sums ordered from leftmost branch sum to rightmost branch sum.
  A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree
  branch is a path of nodes in a tree that starts at the root node and ends at
  any leaf node.
Ex : tree = 1
        /     \
       2       3
     /   \    /  \
    4     5  6    7
  /   \  /
 8    9 10

output : [15, 16, 18, 10, 11]
// 15 == 1 + 2 + 4 + 8
// 16 == 1 + 2 + 4 + 9
// 18 == 1 + 2 + 5 + 10
// 10 == 1 + 3 + 6
// 11 == 1 + 3 + 7
*/

/*
    The idea is to use a dfs and keep traversing the tree while a keeping a running sum that gets updated every time we are at a node
    whenever we reach a leaf, we add the sum we have to the result array.
    This works because dfs already traverses the tree from left branch to right branch
*/

// The solution
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void dfs(BinaryTree* tree, vector<int>& result, int sumTillNow){
  if (!tree){
    return;
  }
  sumTillNow += tree->value;
  if (!tree->left && !tree->right){
    result.push_back(sumTillNow);
    return;
  }
  dfs(tree->left,result,sumTillNow);
  dfs(tree->right,result,sumTillNow);
}

vector<int> branchSums(BinaryTree* root) {
  vector<int> result;
  dfs(root,result,0);
  return result;
}
