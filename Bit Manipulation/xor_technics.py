'''
    https://www.hackerrank.com/challenges/xor-se/problem?isFullScreen=true
'''
import math
import os
import random
import re
import sys

def computeXOR(n) : 
    if n % 4 == 0 : 
        return n 
    if n % 4 == 1 : 
        return 1
    if n % 4 == 2 : 
        return n + 1
    return 0
def computeXOROdd(n) : 
    if n % 8 == 1 : 
        return n 
    if n % 8 == 3 : 
        return 2
    if n % 8 == 5 : 
        return n + 2
    return 0
def computeXOREven(n) : 
    if n % 8 == 2 : 
        return 2 
    if n % 8 == 4 : 
        return n+2
    if n % 8 == 0 : 
        return n
    return 0
def xorSequence(l, r):
    Al = computeXOR(l)
    if (r&1) : 
        if l&1 : 
            return computeXOROdd(r)^computeXOROdd(l)^Al
        else : 
            return computeXOROdd(r)^computeXOROdd(l-1)
    else : 
        if l&1 : 
            return computeXOREven(r)^computeXOREven(l-1)
        else : 
            return computeXOREven(r)^computeXOREven(l)^Al
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        lr = input().split()

        l = int(lr[0])

        r = int(lr[1])

        result = xorSequence(l, r)

        fptr.write(str(result) + '\n')

    fptr.close()
