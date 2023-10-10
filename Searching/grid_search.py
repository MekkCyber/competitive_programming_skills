'''
    https://www.hackerrank.com/challenges/the-grid-search/problem?isFullScreen=true
'''
import math
import os
import random
import re
import sys

def matrixEqual(A,B) : 
    for i in range(len(A)) : 
        for j in range(len(A[0])) : 
            if A[i][j] != B[i][j] : 
                return False
    return True
def gridSearch(G, P):
    i = 0
    G = [list(s) for s in G]
    while i<len(G)-len(P)+1 : 
        j = 0
        while j < len(G[0])-len(P[0])+1 : 
            if G[i][j]==P[0][0] and G[i+len(P)-1][j]==P[len(P)-1][0] and G[i][j+len(P[0])-1]==P[0][len(P[0])-1] and G[i+len(P)-1][j+len(P[0])-1]==P[len(P)-1][len(P[0])-1] :
                if matrixEqual([x[j:j+len(P[0])] for x in G[i:i+len(P)]],P) : 
                    return 'YES'
            j+=1
        i+=1
    return 'NO'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        R = int(first_multiple_input[0])

        C = int(first_multiple_input[1])

        G = []

        for _ in range(R):
            G_item = input()
            G.append(G_item)

        second_multiple_input = input().rstrip().split()

        r = int(second_multiple_input[0])

        c = int(second_multiple_input[1])

        P = []

        for _ in range(r):
            P_item = input()
            P.append(P_item)

        result = gridSearch(G, P)

        fptr.write(result + '\n')

    fptr.close()
