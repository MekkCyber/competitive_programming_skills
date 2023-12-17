'''
https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?isFullScreen=true
'''

from bisect import bisect_left

def activityNotifications(expenditure, d):
    k = 0
    sorted_trail = sorted(expenditure[:d])
    
    for i in range(len(expenditure) - d):
        median = sorted_trail[d // 2] if d % 2 == 1 else (sorted_trail[d // 2 - 1] + sorted_trail[d // 2]) / 2
        if expenditure[i+d] >= 2 * median:
            k += 1
        index = bisect_left(sorted_trail, expenditure[i])
        sorted_trail.pop(index)
        index = bisect_left(sorted_trail, expenditure[i+d])
        sorted_trail.insert(index, expenditure[i+d])
    
    return k
