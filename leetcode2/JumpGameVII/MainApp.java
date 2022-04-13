// Copyright (C) 2022 by iamslash

// minJump: 2
// maxJump: 3
//       i
// s: 011*1*
//         j

// 9ms 93.21% 43.2MB 89.81%
// two pointers
// O(N) O(N)
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        char[] road = s.toCharArray();
        for (int i = 0, j = 0; i < n; ++i) {
            if (i == 0 || road[i] == '*') {
                int beg = Math.max(j, i + minJump);
                int end = Math.min(n, i + maxJump + 1);
                for (j = beg; j < end; ++j) {
                    if (road[j] == '0') {
                        road[j] = '*';
                    }
                }
            }
        }
        return road[n-1] == '*';
    }
}
