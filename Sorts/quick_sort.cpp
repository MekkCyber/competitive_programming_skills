/*
    We take a value as a pivot, we put all the smaller numbers to the left of the pivot
    and all the great numbers to the right
    we start the pivot to be the first element of the array, and we initialize a left and right
    pointer (left = second element and righ = last element), if left>pivot and right<pivot we swap
    the elements, however if left<pivot we just increment left because its already in the right position
    and if right>pivot, the same thing happens, we just increment right
    we keep this process until the Left pointer exceeds the right pointer, when that happens 
    we swap the pivot value with the value of the right pointer
    Now we have two subarrays on the right and left of the pivot
    we take the smallest subarray and we do the same algorithm described (if the length of the subarray is 1 
    we consider it sorted) and we do the same thing for the other subarray

*/