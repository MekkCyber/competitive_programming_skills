/*
    Min Heap : a tree where the min element is the root, the value of every node is less or equal than its children nodes
    Max Heap : a tree where the max element is the root, the value of every node is higher or equal than its children nodes
    (the tree should be filled from the left to the right)
    Properties : 
        -when representing the heap on an array, the children of the node i are at 2*i+1 and 2*i+2
        -if child node = i then the parent node is round((i-1)/2)
        Ex : tree =  8
                   /   \
                  12   23
                 /  \  / \
                17  31 30 44
                / \
               102 18
            array = [8,12,23,17,31,30,44,102,18]
    In Mean Heap : 
        -In order to insert a number in a heap, we need to sift it up until its smaller than its children and higher than its parent
        To do that in the array representation, we append the element to the end of the array, we determine its parent with the property 
        of indexes, and if its smaller we sift it up by swaping the two values
        -To remove the root node from the tree, we swap it with the final node in the array, pop it of because its now a leaf node, and then 
        sift down the new root node. Each time, we compare it with the smallest value of its children and if its higher, we swap them
        -To construct a min heap from an array, we start by constructing the tree that follows the indices rule, the first element is the 
        root, the second and third are the direct children and son. After that, we start by the last parent in the tree and we sift it down
        and we move on the parent right before and so on
        -Sift Down and Sift Up in O(log(n)) time and O(1) space
        -Build Heap : O(N) (you make think that its O(Nlog(N)) because we call sift down on every parent node, however the cost of sift down is 
        not the same for every parent, nodes near the bottom cost less, and they are the majority, this is why its only O(N), and we can show
        rigourously that the cplxity is O(N). In fact this is one of the reasons of using sift down to build a heap over sift up, in sift up
        nodes near the bottom cost more to sift up, so the cplxity is O(Nlog(N)) in general)
*/

#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
 public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }
  // O(n) time | O(1) space
  vector<int> buildHeap(vector<int>& vector) {
    int firstParent = (vector.size()-2)/2;
    for (int parent = firstParent; parent>=0; parent--){
      siftDown(parent,vector.size()-1,vector);
    }
    return vector;
  }
  // O(log(n)) time | O(1) space
  void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
    int childOne = 2*currentIdx + 1;
    while (childOne <= endIdx){ // we verify that we have at least a child
      int childTwo = childOne + 1;
      int indexToSwap;
      if (childTwo <= endIdx && heap[childTwo]<heap[childOne]){
        indexToSwap = childTwo;
      } else {
        indexToSwap = childOne;
      }
      if (heap[currentIdx]>heap[indexToSwap]){
        swap(currentIdx,indexToSwap,heap);
        currentIdx = indexToSwap;
        childOne = 2*currentIdx+1;
      } else {
        break;
      }
    }
  }
  // O(log(n)) time | O(1) space
  void siftUp(int currentIdx, vector<int>& heap) {
    int parent = (currentIdx-1)/2;
    while (currentIdx > 0 && heap[currentIdx]<heap[parent]){
      swap(currentIdx,parent,heap);
      currentIdx = parent;
      parent = (currentIdx-1)/2;
    }
  }

  int peek() {
    return heap[0];
  }

  int remove() {
    swap(0,heap.size()-1,heap);
    int valueToRemove = heap.back();
    heap.pop_back();
    siftDown(0,heap.size()-1,heap);
    return valueToRemove;
  }

  void insert(int value) {
    heap.push_back(value);
    siftUp(heap.size()-1,heap);
  }

  void swap(int index1, int index2, vector<int>& heap){
    program::swap(heap[index1],heap[index2]);
  }
};
