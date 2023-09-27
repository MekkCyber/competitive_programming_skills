/*
    
  You're given an array of integers where each integer represents a jump of its
  value in the array. For instance, the integer 2 represents a jump
  of two indices forward in the array; the integer -3 represents a
  jump of three indices backward in the array.


  If a jump spills past the array's bounds, it wraps over to the other side. For
  instance, a jump of -1 at index 0 brings us to the last index in
  the array. Similarly, a jump of 1 at the last index in the array brings us to
  index 0.
  Write a function that returns a boolean representing whether the jumps in the
  array form a single cycle. A single cycle occurs if, starting at any index in
  the array and following the jumps, every element in the array is visited
  exactly once before landing back on the starting index.
*/

/*
    We need to verify that we visited all elements of the array
    if we go back to the first element and the counter is not equal to array.size() we have a problem
    if we do array.size() iterations and we are not yet back to the first element we have a problem
*/

// Approach using O(n) space and O(n) time
#include <vector>
using namespace std;

bool hasSingleCycle(vector<int> array) {
  vector<int> visited(array.size(),0);
  int counter = 0;
  int n = array.size();
  int next_index = 0;
  while (counter<=array.size()){
    if (visited[next_index] && counter<array.size()){
      return false;
    } 
    if (next_index != 0 && counter==array.size()) return false;
    visited[next_index] = 1;
    int jump = array[next_index];
    next_index += (jump%n+n)%n;
    next_index = next_index%n;
    counter++;
  }
  return true;
}
// better approach in O(n) time and O(1) space, so much more elegant
using namespace std;

bool hasSingleCycle(vector<int> array) {
  int numVisited = 0;
  int currentIdx = 0;
  int n = array.size();
  while (numVisited < array.size()){
    if (numVisited > 0 && currentIdx == 0) return false; // we went back to the first element and we didn't visit all the others (numVisited<array.size())
    numVisited++;
    int jump = array[currentIdx];
    currentIdx = (currentIdx+(jump%n+n)%n)%n;
  }
  return currentIdx==0;// 
}
