/*

  Write a function that takes in an array of integers and returns the length of
  the longest peak in the array.

  A peak is defined as adjacent integers in the array that are <b>strictly</b>
  increasing until they reach a tip (the highest value in the peak), at which
  point they become strictly decreasing. At least three integers are required to
  form a peak.

  Ex : a = [1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3]
  output : 6 // 0, 10, 6, 5, -1, -3

*/

/*
    The first approach that comes to mind is start iterating over the array, and keep
    track of the peaks and their length, this might be tricky because there are a lot of
    cases to consider

    The second approach which is better is to start by finding the peaks, to do that we just
    compare each value with its right and left neighbors, if it is greater then we mark it
    as a peak.
    Once we have the peaks we iterate over them and see how much far to the left and to the
    right we can go, we keep going as long as we have strictly decreasing integers
    We can implement the same idea without having two for loops and without needing extra space
    to store the peaks. We can just iterate over the array and if we find a peak, try to find how far
    we can go to the left and right and store value of the longest peak til now.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int longestPeak_complicated(vector<int> array)
    {
        bool increasing = false;
        bool peak = false;
        int max_peak = 0;
        if (array.size() < 3)
        {
            return 0;
        }
        int counter = 1;
        for (int i = 0; i < array.size() - 1; i++)
        {
            if (array[i] < array[i + 1] && increasing)
            {
                counter++;
            }
            else if (array[i] < array[i + 1] && !increasing)
            {
                increasing = true;
                if (peak)
                {
                    max_peak = max(counter + 1, max_peak);
                    peak = false;
                    counter = 1;
                }
                else
                {
                    counter = 1;
                }
            }
            else if (array[i] > array[i + 1] && increasing)
            {
                peak = true;
                counter++;
                increasing = false;
            }
            else if (array[i] > array[i + 1] && !increasing)
            {
                if (peak)
                    counter++;
                else
                    continue;
            }
            else
            {
                if (peak)
                {
                    max_peak = max(counter + 1, max_peak);
                    peak = false;
                }
                else
                {
                    counter = 1;
                    increasing = false;
                }
            }
            if (i == array.size() - 2 && peak)
            {
                counter++;
                max_peak = max(counter, max_peak);
            }
        }
        return max_peak;
    }

    int longestPeak_better(vector<int> array)
    {
        int i = 1;
        int max_peak = 0;
        while (i < int(array.size() - 1))
        {
            bool peak = (array[i] > array[i + 1] && array[i] > array[i - 1]);
            if (!peak)
            {
                i++;
                continue;
            }
            int left = i - 2;
            int right = i + 2;

            while (left >= 0 && array[left] < array[left + 1])
            {
                left--;
            }
            while (right < array.size() && array[right] < array[right - 1])
            {
                right++;
            }

            int peak_length = right - left - 1;
            max_peak = max(peak_length, max_peak);
            i = right;
        }
        return max_peak;
    }
}