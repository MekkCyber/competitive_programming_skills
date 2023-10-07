'''
    https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?isFullScreen=true
'''

def sherlockAndAnagrams(s):
    anagrams = {}
    count = 0
    for i in range(len(s)) : 
        for j in range(i+1,len(s)+1) :
            print(s[i:j]) 
            if tuple(sorted(s[i:j])) in anagrams.keys() : 
                anagrams[tuple(sorted(s[i:j]))] += 1
            else :
                anagrams[tuple(sorted(s[i:j]))] = 1
    for key, value in anagrams.items() : 
        count += (value*(value-1))//2
    return count