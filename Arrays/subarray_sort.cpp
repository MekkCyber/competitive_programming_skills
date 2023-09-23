/*
    Write a function that takes in an array of at least two integers and that
    returns an array of the starting and ending indices of the smallest subarray
    in the input array that needs to be sorted in place in order for the entire
    input array to be sorted (in ascending order).
    If the input array is already sorted, the function should return [-1, -1].
    Ex : a = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
    output : [3,9]
*/

/*
    The intuition behind this is to find the lowest element not in order, and the largest element
    not in order. Their position in the sorted array, is the subarray that needs to be sorted
*/

#include <iostream>
#include <vector>
using namespace std;

// My approach
vector<int> subarraySort(vector<int> array)
{
    // Write your code here.
    int i = 0;
    int left = INT_MAX;
    int right = -1;
    int max_ = array[0];
    while (i < array.size() - 1)
    {
        if (array[i + 1] >= array[i] && array[i + 1] >= max_)
        {
            max_ = max(array[i + 1], max_);
        }
        else if (array[i + 1] >= array[i] && array[i + 1] < max_)
        {
            right = i + 1;
        }
        else
        {
            int j = i - 1;
            while (array[j] > array[i + 1] && j >= 0)
            {
                j--;
            }
            left = min(left, j + 1);
            right = i + 1;
        }
        i++;
    }
    if (left == INT_MAX)
        left = -1;
    return {left, right};
}
// A better approach
bool outOfOrder(int i, int num, vector<int> array)
{
    if (i == 0)
    {
        return num > array[i + 1];
    }
    if (i == array.size() - 1)
    {
        return num < array[i - 1];
    }
    return num > array[i + 1] || num < array[i - 1];
}
vector<int> subarraySort(vector<int> array)
{
    // Write your code here.
    int min_ = INT_MAX;
    int max_ = INT_MIN;

    for (int i = 0; i < array.size(); i++)
    {
        int num = array[i];
        if (outOfOrder(i, num, array))
        {
            min_ = min(min_, num);
            max_ = max(max_, num);
        }
    }
    if (min_ == INT_MAX)
    {
        return {-1, -1};
    }
    int left = 0;
    int right = array.size() - 1;
    while (array[left] <= min_)
    {
        left++;
    }
    while (array[right] >= max_)
    {
        right--;
    }
    return {left, right};
}