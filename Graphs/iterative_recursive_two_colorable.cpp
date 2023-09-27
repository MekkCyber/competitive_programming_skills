#include <stack>
using namespace std;
// Iterative
bool twoColorable(vector<vector<int>> edges) {
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

// Recursive 
bool twoColorable(vector<vector<int>> edges) {
  unordered_map<int,int> colors;
  return dfs(edges,0,1,colors);
}
bool dfs(vector<vector<int>> edges,int node, int color, unordered_map<int,int>& colors){
  colors[node] = color;
  for (int sibling : edges[node]){
    if (sibling==node || colors[sibling] == color){
      return false;
    } else if (!colors[sibling]){
      bool sub_problem = dfs(edges,sibling,3-color,colors);
      if (!sub_problem){
        return false;
      }
    }
  }
  return true;
}