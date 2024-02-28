'''
    https://www.hackerrank.com/challenges/sansa-and-xor/problem?isFullScreen=true
'''

import math
import os
import random
import re
import sys


def sansaXor(arr):
    # Write your code here
    i = 0
    n = len(arr)
    result = 0
    # the first element of the array appears 1*(n-0) times
    # the second elt appears 2*(n-1) -> no need to account for it, it appears an even number of times
    # the third : 3*(n-2)
    # .....
    # which means we only consider cases where i is even and n-i is odd (because when i is odd (i+1)*(n-i) is even)
    while i<n : 
        if (n-i)&1 :
            result = result ^ arr[i]
        i += 2
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = sansaXor(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
