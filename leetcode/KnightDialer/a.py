# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 960ms 81.57% 14.4MB 54.75%
# iterative dynamic programming
# O(N) O(1)
class Solution:
    def knightDialer(self, n: int) -> int:
        MOD = 1000000007
        moves = [
            [4,6],
            [6,8],
            [7,9],
            [4,8],
            [0,3,9],
            [],
            [0,1,7],
            [2,6],
            [1,3],
            [2,4],
        ];
        prev_move_cnt = [1]*10
        for _ in range(n-1):            
            curr_move_cnt = [0]*10
            for i in range(10):
                curr_move_cnt[i] = sum([prev_move_cnt[j] for j in moves[i]]) % MOD
            prev_move_cnt = curr_move_cnt
        return sum(prev_move_cnt) % MOD
        
if __name__ == "__main__":    
    sln = Solution()
    # 10
    print(sln.knightDialer(1))
    # 20
    print(sln.knightDialer(2))
    # 46
    print(sln.knightDialer(3))
    # 104
    print(sln.knightDialer(4))
    # 3131
    print(sln.knightDialer(3131))
