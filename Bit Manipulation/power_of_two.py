'''
    https://www.hackerrank.com/challenges/counter-game/problem?isFullScreen=true
'''
import math
import os
import random
import re
import sys


def counterGame(n):
    if n==1 : 
        return "Richard"
    LouisePlaying = True
    while (n>1) : 
        if (int(n-2**(int(math.log2(n)))) == 0) : # power of two
            n //= 2
            LouisePlaying = not LouisePlaying
        else : 
            n = int(n-2**(int(math.log2(n))))
            LouisePlaying = not LouisePlaying
    if LouisePlaying : 
        return "Richard"
    else : 
        return "Louise"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = counterGame(n)

        fptr.write(result + '\n')

    fptr.close()
