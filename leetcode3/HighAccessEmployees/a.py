# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

from typing import List

# 189ms 72.19% 16.4MB 45.24%
# sort
# O(NlgN) O(N)
class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        user2times_map = {}
        for acc_time in access_times:
            user = acc_time[0]
            time = int(acc_time[1])
            if user not in user2times_map:
                user2times_map[user] = []
            user2times_map[user].append(time)

        ans = []
        for user in user2times_map.keys():
            time_list = user2times_map[user]
            if len(time_list) < 3:
                continue
            time_list.sort()
            for i in range(len(time_list) - 2):
                if time_list[i] + 100 > time_list[i+2]:
                    ans.append(user)
                    break
                   
        return ans
