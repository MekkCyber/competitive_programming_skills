'''
    https://www.hackerrank.com/challenges/recursive-digit-sum/problem?isFullScreen=true
'''
import math
import os
import random
import re
import sys


def superDigit(n, k):
    if len(n)==1 and k==1 : 
        return int(n)
    else :
        n = list(n)
        n = [int(x) for x in n] 
        sum_ = sum(n)*k
        return superDigit(str(sum_),1)
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = first_multiple_input[0]

    k = int(first_multiple_input[1])

    result = superDigit(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()
