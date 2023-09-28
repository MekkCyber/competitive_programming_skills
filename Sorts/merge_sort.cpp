/*
    The idea of the merge sort is to call recursively the merge function and each half of the array, and 
    reconstruct the array using an other function that merges sorted arrays
*/

#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int> array1, vector<int> array2);

vector<int> mergeSort(vector<int> array) {
  if (array.size()==1){
    return array;
  }
  int n = array.size();
  vector<int> left(array.begin(),array.begin()+n/2);
  vector<int> right(array.begin()+n/2,array.end());
  return mergeSortedArrays(mergeSort(left),mergeSort(right));
}

vector<int> mergeSortedArrays(vector<int> array1, vector<int> array2){
  int firstp = 0;
  int secondp = 0;
  vector<int> result(array1.size()+array2.size());
  int thirdp = 0;
  while (firstp<array1.size() && secondp<array2.size()){
    if (array1[firstp]<=array2[secondp]){
      result[thirdp] = array1[firstp];
      firstp++;
      thirdp++;
    } else {
      result[thirdp] = array2[secondp];
      secondp++;
      thirdp++;
    }
  }
  while (firstp<array1.size()){
    result[thirdp] = array1[firstp];
    firstp++;
    thirdp++;
  }
  while (secondp<array2.size()){
    result[thirdp] = array2[secondp];
    secondp++;
    thirdp++;
  }
  return result;
}
