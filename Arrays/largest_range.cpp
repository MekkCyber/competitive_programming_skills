/*
    Write a function that takes in an array of integers and returns an array of
    length 2 representing the largest range of integers contained in that array.

    The first number in the output array should be the first number in the range,
    while the second number should be the last number in the range.

    A range of numbers is defined as a set of numbers that come right after each
    other in the set of real integers. For instance, the output array
    <span>[2, 6]</span> represents the range <span>{2, 3, 4, 5, 6}</span>, which
    is a range of length 5. Note that numbers don't need to be sorted or adjacent
    in the input array in order to form a range.
    Ex : a = [1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6]
    output : [0,7]
*/

/*
    The easiest solution can be done using sorting O(nlog(n))
    To optimize that we can come up with a solution in O(n) time and O(n) space.
    we create an unordered_map where we store our array values as keys and booleans set
    to false as values.
    We then iterate over the array, for each array[i] element we look in the map if array[i]-1
    exists and it is set to false, if so we set it to true and go on the next element array[i]-2,
    we explore in the same way the right side array[i]+k until there is a k,k` for which
    array[i]+k and array[i]-k` are not in the map (the boolean values are used in order not to redo the work
    for example if we visit 1 and go on to discover that we have the [0,7] range we don't have to redo the
    discovering when we visit 3, 0, etc)
*/

// My approach
#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array)
{
    int min_ = *min_element(array.begin(), array.end());
    int max_ = *max_element(array.begin(), array.end());
    set<int> s(array.begin(), array.end());
    int longest_range = 0;
    int left = 1;
    int right = 1;
    int i = min_;
    while (i <= max_)
    {
        int j = 0;
        while (i + j <= max_ && s.find(i + j) != s.end())
        {
            j++;
        }
        if (j - 1 > longest_range)
        {
            longest_range = j - 1;
            left = i;
            right = i + j - 1;
        }
        i += j + 1;
    }
    return {left, right};
}
// The Solution approach
#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array)
{
    // Write your code here.
    vector<int> best = {};
    int longest_range = 0;
    unordered_map<int, bool> nums = {};
    for (int num : array)
    {
        nums[num] = false;
    }
    for (int num : array)
    {
        if (nums[num])
        {
            continue;
        }
        nums[num] = true;
        int current_length = 1;
        int left = num - 1;
        int right = num + 1;
        while (nums.find(left) != nums.end())
        {
            nums[left] = true;
            current_length++;
            left--;
        }
        while (nums.find(right) != nums.end())
        {
            nums[right] = true;
            current_length++;
            right++;
        }
        if (current_length > longest_range)
        {
            longest_range = current_length;
            best = {left + 1, right - 1};
        }
    }
    return best;
}
