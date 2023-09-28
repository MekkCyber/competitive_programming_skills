/*
    
    Write a function that takes in an array of strings and groups anagrams together.

    Ex : words = ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"]
    output : [["yo", "oy"], ["flop", "olfp"], ["act", "tac", "cat"], ["foo"]]

*/

/*
    The idea is for every word we visit we store a sorted version of that word in hashmap, where the key is the sorted word
    and the value is a vector that's going to contain all the anagrams
*/

#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  vector<vector<string>> result;
  unordered_map<string,vector<string>> already_exists;
  for (int i = 0; i<words.size(); i++){
    string word = words[i];
    sort(word.begin(),word.end());
    if (already_exists.find(word)!=already_exists.end()){
      already_exists[word].push_back(words[i]);
    } else {
      already_exists[word] = {words[i]};
    }
  }
  for (auto vct : already_exists){
    result.push_back(vct.second);
  }
  return result;
}