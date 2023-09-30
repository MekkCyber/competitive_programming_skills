#include <unordered_map>
using namespace std;

class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
 public:
  TrieNode* root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }
  // O(n²) time and space to construct where n is the length of the string)
  void populateSuffixTrieFrom(string str) {
    for (int i = 0; i<str.length(); i++){
      string substring = str.substr(i);
      insert(substring);
    }
  }
  void insert(string str){
    TrieNode* currentNode = root;
    for (int i = 0; i<str.length(); i++){
      if (currentNode->children.find(str[i])==currentNode->children.end()){
        currentNode->children[str[i]] = new TrieNode();
      }
      currentNode = currentNode->children[str[i]];
    }
    if (currentNode->children.find(endSymbol)==currentNode->children.end()){
        currentNode->children[endSymbol] = nullptr;
    }
  }
  bool contains(string str) {
    int i = 0;
    TrieNode* currentNode = root;
    while (i<str.length()){
      if (currentNode->children.find(str[i])==currentNode->children.end()){
        return false;
      }
      currentNode = currentNode->children[str[i]];
      i++;
    }
    if (currentNode->children.find(endSymbol)==currentNode->children.end()){
      return false;
    }
    return true;
  }
};
