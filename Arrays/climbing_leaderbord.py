'''
    https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
'''
import math
import os
import random
import re
import sys


def climbingLeaderboard(ranked, player):
    ranks = {}
    rank = 1
    for i in range(len(ranked)) : 
        if ranked[i] not in ranks : 
            ranks[ranked[i]] = rank
            rank+=1
    result = [0]*len(player)
    i = len(ranked)-1
    score = 0
    while (score < len(player)) : 
        while (i>= 0 and player[score]>=ranked[i]) : 
            i -= 1
        if i<0 : 
            result[score] = 1
        else : result[score] = ranks[ranked[i]]+1
        score += 1
    return result
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
