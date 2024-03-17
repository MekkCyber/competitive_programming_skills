/*
    Write a function that takes in a non-empty array of integers and returns the
    maximum sum that can be obtained by summing up all of the integers in a
    non-empty subarray of the input array. A subarray must only contain adjacent
    numbers (numbers next to each other in the input array).
*/
/*
    The intuition is that we need to iterate over the array, and keep a running sum, and whenever the sum is <0
    it means we no longer need that part, because it will just make the next part of the array worse
*/

#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  int max_so_far = INT_MIN;
  int max_here = 0;
  for (int i = 0; i < array.size(); i++){
    max_here += array[i];
    max_so_far = max(max_so_far,max_here);
    if (max_here<0){
      max_here = 0;
    }
  }
  return max_so_far;
}
