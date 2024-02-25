/*
    Write a function that takes in a non-empty array of non-negative integers and a non-negative integer 
    representing a target sum. The function should find the longest subarray where the values collectively
    sum up to equal the target sum. Return an array containing the starting index and ending index of this subarray,
    both inclusive.
    If there is no subarray that sums up to the target sum, the function should return an
    empty array. You can assume that the given inputs will only ever have one answer.
    Ex : array = [1, 2, 3, 4, 3, 3, 1, 2, 1, 2]
    targetSum = 10
    output : [4,8]
*/

/*
    we can just try to find all possible subarrays, and find their sum, this is a O(n²) approach.
    We can do better by using two pointers, a startIndex and an endIndex. At first startIndex=0, and
    we start by moving the endIndex until the sum we have is larger than the targetSum, then we increment
    the startIndex by 1, if the sum is still bigger than the target we re-increment the startIndex and so on
    until the sum is lower. After that continue incrementing the endIndex. While doing so we keep track of
    of the startIndex and endIndex that give us the intended array
*/

// Whenever you have a subarray problem think about using a left and right pointer !!!!!!!!!!!!!!

// The solution approach

using namespace std;

vector<int> longestSubarrayWithSum(vector<int> array, int targetSum)
{
    int startIndex = 0;
    int endIndex = 0;
    vector<int> indices = {};
    int sum = 0;
    while (endIndex < array.size())
    {
        sum += array[endIndex];
        while (startIndex < endIndex && sum > targetSum)
        {
            sum -= array[startIndex];
            startIndex++;
        }
        if (sum == targetSum)
        {
            if (indices.empty() || indices[1] - indices[0] < endIndex - startIndex)
            {
                indices = {startIndex, endIndex};
            }
        }
        endIndex++;
    }
    return indices;
}
