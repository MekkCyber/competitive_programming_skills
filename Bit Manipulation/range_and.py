'''

'''
import math
import os
import random
import re
import sys


def andProduct(a, b):
    
    # the idea is to go through the binary representation of a and b and add their value multiplied by the proper power of 2 until we find a difference 
    # When that happens we just break out of the loop and we have our result, the reason is that in the smallest number we have a 0 in the ith position
    # and in the largest one we have a 1 in the ith position, for the range of numbers between these two numbers we must have one that switches the ith
    # position from 0 to 1 with all bits i-1->0 set to 0, doing an & operation with this number will set all bits from i-1->0 to 0 in the result
    i = 31
    result = 0
    while i>0 : 
        temp_a = a>>i
        temp_b = b>>i
        if ((temp_a&1)!=(temp_b&1)) : break
        result += (temp_a&1) * 2**i
        i -= 1
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    for n_itr in range(n):
        first_multiple_input = input().rstrip().split()

        a = int(first_multiple_input[0])

        b = int(first_multiple_input[1])

        result = andProduct(a, b)

        fptr.write(str(result) + '\n')

    fptr.close()
