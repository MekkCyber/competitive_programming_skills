'''
    https://www.hackerrank.com/challenges/the-great-xor/problem?isFullScreen=true
'''

import math
import os
import random
import re
import sys

def theGreatXor(x):
    result = 0
    i = 0
    while (x > 0) : 
        # if the last bit is not set it means that adding numbers between 2**(i+1)-1 and 2**(i) is gonna make the number greater than the original
        if (not x&1) : 
            result += (2**(i+1)-2**i)
        i+=1
        x = x>>1
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        x = int(input().strip())

        result = theGreatXor(x)

        fptr.write(str(result) + '\n')

    fptr.close()
