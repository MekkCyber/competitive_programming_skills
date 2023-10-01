/*
    Sort a stack recursively in place without using any additional data structure 
*/

#include <vector>
using namespace std;

vector<int> sortStack(vector<int>& stack) {
  if (stack.empty()) return stack;
  int top = stack.back();
  stack.pop_back();
  if (stack.empty()){
    stack.push_back(top);
    return stack;
  } 
  sortStack(stack);
  if (top >= stack.back()){
    stack.push_back(top);
    return stack;
  } else {
    int top2 = stack.back();
    stack.pop_back();
    stack.push_back(top);
    sortStack(stack);
    stack.push_back(top2);
  }
  return stack;
}
