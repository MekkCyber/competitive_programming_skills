'''
    https://www.hackerrank.com/challenges/greedy-florist/problem?isFullScreen=true
'''
import math
import os
import random
import re
import sys


def getMinimumCost(k, c):
    sorted_c = sorted(c,reverse=True)
    print(sorted_c)
    previously_purchased = 0
    min_ = sum(sorted_c[:min(k,len(c))])
    for i in range(k,len(c)) : 
        if i%k==0 : 
            previously_purchased += 1
        min_ += (1+previously_purchased)*sorted_c[i]
    return min_
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    minimumCost = getMinimumCost(k, c)

    fptr.write(str(minimumCost) + '\n')

    fptr.close()
