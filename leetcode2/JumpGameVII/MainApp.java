// Copyright (C) 2022 by iamslash

// minJump: 2
// maxJump: 3
//       i
// s: 011*1*
//         j

// Time Limit Exceeded
// two pointers
// O(N) O(N)
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        char[] road = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            // System.out.printf("i: %d\n", i);
            if (i == 0 || road[i] == '*') {
                int beg = i + minJump;
                int end = Math.min(n, i + maxJump + 1);
                // System.out.printf("i: %d, beg: %d, end: %d\n", i, beg, end);
                for (int j = beg; j < end; ++j) {
                    if (road[j] == '0') {
                        road[j] = '*';
                    }
                }
            }
        }
        // System.out.println(new String(road));
        return road[n-1] == '*';
    }
}
