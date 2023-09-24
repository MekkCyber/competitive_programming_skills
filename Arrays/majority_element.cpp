/*
    Write a function that takes in a non-empty, unordered array of
    positive integers and returns the array's majority element without sorting
    the array and without using more than constant space.

    An array's majority element is an element of the array that appears in over
    half of its indices. Note that the most common element of an array (the
    element that appears the most times in the array) isn't necessarily the
    array's majority element; for example, the arrays
    <span>[3, 2, 2, 1]</span> and <span>[3, 4, 2, 2, 1]</span> both have
    <span>2</span> as their most common element, yet neither of these arrays
    have a majority element, because neither <span>2</span> nor any other
    element appears in over half of the respective arrays' indices.
    You can assume that the input array will always have a majority element.

    Ex : array = [1, 2, 3, 2, 2, 1, 2]
    2 // 2 occurs in 4/7 array indices, making it the majority element</span>
*/

/*
    The underlying concept of this problem lies in recognizing that the majority element's frequency 
    remains unchanged even after removing a certain proportion of it, alongside an equivalent proportion 
    of other elements. To put it differently, removing two majority elements from the array, along with
    two other elements, will preserve the same majority element in the new array. Likewise, removing 
    non-majority elements will not alter the majority element in this scenario either.
    we start with the first element as a majority element and a count of 0, if the second elemnt
    equals the provisional majority_element we increment count, else we decrement it. When the count is 0 it
    mean there is not majority element found in the visited part of the array, so the majority_element
    will change to be the first element of next part.
*/

// The Solution
using namespace std;

int majorityElement(vector<int> array)
{
    int majority_element = array[0];
    int count = 0;
    int i = 0;
    while (i < array.size())
    {
        if (count == 0)
        {
            majority_element = array[i];
        }
        if (array[i] == majority_element)
            count++;
        else
            count--;
        i++;
    }
    return majority_element;
}

// Bit manipulation approach : for each bit placement (there are 32) count the number of set bits, and if it's > n/2 than the bit is set in the majority element