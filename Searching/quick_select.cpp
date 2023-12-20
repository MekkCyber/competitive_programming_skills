/*
    Find the kth smallest value in the array in O(n) time
*/

/*
    works like quick sort until the pivot position is equal to k-1
*/
// O(n) time in average (O(n²) in worst case) and O(1) space

#include <vector>
using namespace std;

int quickSelectHelper(vector<int>& array, int l, int r, int position);

int quickselect(vector<int> array, int k) {
  int l = 0;
  int r = array.size()-1;
  int position = k-1;
  return quickSelectHelper(array, l, r, position);
}

int quickSelectHelper(vector<int>& array, int l, int r, int position){
  while (true){
    int pivotIdx = l;
    int startIdx = l+1;
    int endIdx = r;
    while (startIdx <= endIdx) {
      if (array[startIdx]>array[pivotIdx] && array[endIdx]<array[pivotIdx]){
        swap(array[startIdx],array[endIdx]);
        startIdx++;
        endIdx--;
      } else if (array[startIdx]<array[pivotIdx]){
        startIdx++;
      } else if (array[endIdx]>array[pivotIdx]){
        endIdx--;
      }
    }
    swap(array[endIdx],array[pivotIdx]);
    if (endIdx == position){
      return array[position];
    } else if (endIdx < position){
      l = endIdx + 1;
    } else {
      r = endIdx -1;
    }
  }
}
