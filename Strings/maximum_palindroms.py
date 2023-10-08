#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'initialize' function below.
#
# The function accepts STRING s as parameter.
#
sys.setrecursionlimit(100000)
def initialize(s):
    # This function is called once before all queries.
    global string
    string = s

p = 1000000007
table = [0]*(10**5+1)
table[0] = 1
table[1] = 1
def fact_mod(n) : 
    if table[n] != 0 : 
        return table[n]
    else :
        table[n] = (n*fact_mod(n-1))
        return table[n]

def answerQuery(l, r):
    substring = list(string[l-1:r])
    counts = {}
    for c in substring : 
        if c in counts : 
            counts[c] += 1
        else : 
            counts[c] = 1
    max_element = 0
    number_odd_elements = 0
    denominator = 1
    for key, count in counts.items() : 
        max_element += (count//2)
        denominator *= fact_mod(count//2)
        denominator %= p
        if count&1 : 
            number_odd_elements += 1 
            
    if number_odd_elements == 0 : 
        print(11)
        return (fact_mod(max_element)*pow(denominator,p-2,p))%p
    else : 
        return (number_odd_elements*(fact_mod(max_element))*pow(denominator,p-2,p))%p
if __name__ == '__main__':
    fptr = open("results.txt", 'w')

    s = input()

    initialize(s)

    q = int(input().strip())

    for q_itr in range(q):
        first_multiple_input = input().rstrip().split()

        l = int(first_multiple_input[0])

        r = int(first_multiple_input[1])

        result = answerQuery(l, r)

        fptr.write(str(result) + '\n')

    fptr.close()
