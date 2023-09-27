#include <stack>
using namespace std;

bool twoColorable(vector<vector<int>> edges) {
  // Write your code here.
  unordered_map<int,int> colors;
  stack<int> s;
  colors[0] = 1;
  s.push(0);
  while (!s.empty()){
    int t = s.top();
    s.pop();
    for (int sibling : edges[t]){
      if (sibling == t || colors[sibling]==colors[t]){
        return false;
      } else if (!colors[sibling]){
        colors[sibling] = 3-colors[t];
        s.push(sibling);
      }
    }
  }
  return true;
}
