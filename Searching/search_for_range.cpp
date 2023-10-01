/*
    Write a function that takes in a sorted array of integers as well as a target
    integer. The function should use a variation of the Binary Search algorithm to
    find a range of indices in between which the target number is contained in the
    array and should return this range in the form of an array.
    The first number in the output array should represent the first index at which
    the target number is located, while the second number should represent the
    last index at which the target number is located. The function should return
    [-1, -1] if the integer isn't contained in the array.
    Ex array = [0, 1, 21, 33, 45, 45, 45, 45, 45, 45, 61, 71, 73]
       target = 45
    output : [4, 9]
*/
// Naive approach : 
// O(n)
#include <vector>
using namespace std;
vector<int> searchForRange(vector<int> array, int target) {
  int start = 0;
  int end = array.size()-1;
  while (start<=end){
    int middle = (start+end)/2;
    if (target > array[middle]){
      start = middle + 1;
    } else if (target < array[middle]){
      end = middle - 1;
    } else{
      int middle_right = middle+1;
      int middle_left = middle-1;
      while (middle_left>=0 && array[middle_left]==target){
        middle_left--;
      }
      while (middle_right<array.size() && array[middle_right]==target){
        middle_right++;
      }
      return {middle_left+1,middle_right-1};
    }
  }
  return {-1,-1};
}

// More interesting approach : we perform the binary search, when we find our target, we check the right value, if its equal to our target value too, 
// we do a binary search to the left part and we keep doing so until we find our first target occurence. The same approach is done for the right part
// O(log(n))

// My implementation
#include <vector>
using namespace std;

vector<int> searchForRange(vector<int> array, int target) {
  int start = 0;
  int end = array.size()-1;
  int left_limit = -1;
  int right_limit = -1;
  bool notFoundLeft = true;
  while (start<=end){
    int middle = (start+end)/2;
    if (target > array[middle]){
      start = middle + 1;
    } else if (target < array[middle]){
      end = middle - 1;
    } else{
      if (middle>0 && array[middle-1]==target && notFoundLeft){
        end = middle - 1;
        continue;
      } else if (middle==0 || array[middle-1]!=target){
        left_limit = middle;
        notFoundLeft = false;
      }
      if (middle<array.size() && array[middle+1]==array[middle]){
        start = middle+1;
        end = array.size()-1;
        cout<<end<<"\n";
      } else {
        right_limit = middle;
        break;
      }
    }
  }
  return {left_limit,right_limit};
}

/*
Solutions implemented in Python : 

# Solution #1   -   Recursive SOlution
# O(logn) time  |  O(logn) space
def searchForRange(array,  target):
    finalRange = [-1, -1]
    alteredBinarySearch(array, target, 0, len(array) - 1, finalRange, True)
    alteredBinarySearch(array, target, 0, len(array) - 1, finalRange, False)
    return finalRange

def alteredBinarySearch(array, target, left, right, finalRange, goLeft):
    if left > right:
        return
    mid = (left + right) // 2
    if array[mid] < target:
        alteredBinarySearch(array, target, mid + 1, right, finalRange, goLeft)
    elif array[mid] > target:
        alteredBinarySearch(array, target, left, mid - 1, finalRange, goLeft)
    else:
        if goLeft:
            if mid == 0 or array[mid - 1] != target:
                finalRange[0] = mid
            else:
                alteredBinarySearch(array, target, left, mid - 1, finalRange, goLeft)
        else:
            if mid == len(array) - 1 or array[mid + 1] != target:
                finalRange[1] = mid
            else:
                alteredBinarySearch(array, target, mid + 1, right, finalRange, goLeft)


# Solution #2   -   Iterative SOlution
# O(logn) time  |  O(1) space
def searchForRange(array,  target):
    finalRange = [-1, -1]
    alteredBinarySearch(array, target, 0, len(array) - 1, finalRange, True)
    alteredBinarySearch(array, target, 0, len(array) - 1, finalRange, False)
    return finalRange

def alteredBinarySearch(array, target, left, right, finalRange, goLeft):
    while left <= right:
        mid = (left + right) // 2
        if array[mid] < target:
            left = mid + 1
        elif array[mid] > target:
            right = mid - 1
        else:
            if goLeft:
                if mid == 0 or array[mid - 1] != target:
                    finalRange[0] = mid
                else:
                    right = mid - 1
            else:
                if mid == len(array) - 1 or array[mid + 1] != target:
                    finalRange[1] = mid
                else:
                    left = mid + 1



# Solution 3  - using python bisect library
import bisect
def searchForRange(array, target):
    # Write your code here.
    left = bisect.bisect_left(array, target)
	right = bisect.bisect_right(array, target)
	return [left, right - 1] if left < right else [-1, -1]
*/