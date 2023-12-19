/*
    The first step of the algorithm is to transform the array into a max Heap
    The first value is going to be the maxium value, we just swap it with the last value in the array. 
    Now we need to sift down the new value in head of the array to its location to reconstruct a max heap
    without taking into consideration the last element of the array already inplace, we keep this algorithm 
    until all the elements are sorted.
    O(nlogn) time | O(1) space
*/


#include <vector>
using namespace std;

void siftDown(vector<int>& array, int currentIdx, int endIdx){
  int childOne = 2*currentIdx + 1;
  while (childOne <= endIdx){
    int childTwo = childOne + 1;
    int indexToSwap;
    if (childTwo <= endIdx && array[childTwo]>array[childOne]){
      indexToSwap = childTwo;
    } else {
      indexToSwap = childOne;
    }
    if (array[currentIdx]<array[indexToSwap]){
      swap(array[indexToSwap],array[currentIdx]);
      currentIdx = indexToSwap;
      childOne = 2*currentIdx+1;
    } else {
      break;
    }
  }
}

void buildMaxHeap(vector<int>& array){
  int firstParent = (array.size()-2)/2;
  for (int node = firstParent; node>=0; node--){
    siftDown(array,node,array.size()-1);
  }
}

vector<int> heapSort(vector<int> array) {
  buildMaxHeap(array);
  for (int i = array.size()-1; i>=1; i--){
    swap(array[0],array[i]);
    siftDown(array,0,i-1);
  }
  return array;
}
