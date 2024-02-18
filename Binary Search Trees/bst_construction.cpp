#include <vector>
using namespace std;


// Need to add iterative and recursive approachs
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST& insert(int val) {
    // Write your code here.
    if (val<value){
      if (left!=nullptr){
        left->insert(val);
      } else {
        left = new BST(val);
      }
    } else {
      if (right!=nullptr){
        right->insert(val);
      } else {
        right = new BST(val);
      }
    }
    // Do not edit the return statement of this method.
    return *this;
  }

  bool contains(int val) {
    BST* currentNode = this;
    if (val==value){
      return true;
    } else if (val<value){
      if (currentNode->left){
        return currentNode->left->contains(val);
      } 
    } else {
      if (currentNode->right){
        return this->right->contains(val);
      } 
    }
    return false;
  }

  BST& remove(int val, BST* parent=nullptr) {
    // Write your code here.
    BST* currentNode = this;
    while (currentNode != nullptr){
      if (val<currentNode->value){
        parent = currentNode;
        currentNode = currentNode->left;
      } else if (val>currentNode->value){
        parent = currentNode;
        currentNode = currentNode->right;
      } else {
        if (currentNode->left != nullptr && currentNode->right != nullptr){
          currentNode->value = currentNode->right->getMinValue();
          currentNode->right->remove(currentNode->value,currentNode);
        } else if (parent == nullptr){
            if (currentNode->left != nullptr){
              currentNode->value = currentNode->left->value;
              currentNode->right = currentNode->left->right;
              currentNode->left = currentNode->left->left;
            } else if (currentNode->right != nullptr){
              currentNode->value = currentNode->right->value;
              currentNode->left = currentNode->right->left;
              currentNode->right = currentNode->right->right;
            } else {
              // Tree with one node
            }
        } else if (parent->left==currentNode){
            parent->left = currentNode->left != nullptr ? currentNode->left : currentNode->right;
        } else if (parent->right==currentNode){
            parent->right = currentNode->left != nullptr ? currentNode->left : currentNode->right;
        }
        break;
      }
    }
    // Do not edit the return statement of this method.
    return *this;
  }
  int getMinValue(){
    if (left==nullptr){
      return value;
    } else {
      return left->getMinValue();
    }
  }

};
