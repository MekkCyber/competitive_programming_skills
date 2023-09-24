/*
    You're given a list of integers <span>nums</span>. Write a function that
    returns a boolean representing whether there exists a zero-sum subarray of
    nums.
    A zero-sum subarray is any subarray where all of the values add up to zero.
    A subarray is any contiguous section of the array. For the purposes of this
    problem, a subarray can be as small as one element and as long as the
    original array.
    Ex : array = [-5, -5, 2, 3, -2]
    output : True // The subarray [-5, 2, 3] has a sum of 0
*/

/*
    The idea behind the optimal solution in O(n) time is to keep a set or map of cumulative sums
    if at a certain index we have a sum that is already present in the set or map it means we have
    a subarray of sum 0, and we return true.
    The same goes if we find a sum of 0 then we retrun true directly
*/

// The simplest solution O(n²)
using namespace std;

bool zeroSumSubarray(vector<int> array)
{
    int startIndex = 0;
    int endIndex = 0;
    for (int i = 0; i < array.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < array.size(); j++)
        {
            sum += array[j];
            if (sum == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// More optimal 

using namespace std;

bool zeroSumSubarray(vector<int> nums) {
  unordered_map<int,bool> exists;
  int sum = 0;
  for (int i = 0; i<nums.size(); i++){
    sum+= nums[i];
    if (exists[sum] || sum==0){
      return true;
    } 
    exists[sum] = true;
  }
  return false;
}
