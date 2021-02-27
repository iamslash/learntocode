# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

# 36ms 43.44% 14.2MB 69.38%
# hash set
# O(1) O(1)
class Solution:
    def nextClosestTime(self, time: str) -> str:
        digitSet = set(digit for digit in time.replace(':', ''))
        hour, minute = time.split(':')
        while True:
            # Increase minute, Handle minute
            if minute == '59':
                hour = str(int(hour) + 1)
                minute = '00'
            else:
                minute = str(int(minute) + 1)
            # Handle hour
            if int(hour) > 23:
                hour = '00'
            # Fill 0
            if len(hour) == 1:
                hour = '0' + hour
            if len(minute) == 1:
                minute = '0' + minute
            # Check hour, minute is consisted of digitSet
            if all(x in digitSet for x in hour + minute):
                return hour + ':' + minute
            
if __name__ == "__main__":
    sln = Solution()
    # "19:39"
    print(sln.nextClosestTime("19:34"))
    # "22:22"
    print(sln.nextClosestTime("23:59"))
    # "11:11"
    print(sln.nextClosestTime("11:11"))
