// Copyright (C) 2022 by iamslash

import java.util.*;

//           s: cczazcc
// repeatLimit: 3
//                   i
//              zzcccca
//         

// priority queue
// O(N) O(N)
class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        char[] freqs = new char[26];
        for (char c : s.toCharArray()) {
            freqs[c-'a']++;
        }
        int i = 25, prev = -1;
        StringBuilder ans = new StringBuilder();
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; ++i) {
            if (freqs[i] > 0) {
                pq.offer(new int[]{i, freqs[i]});
            }
        }
        while (!pq.isEmpty()) {
            int item[] = pq.poll();
            boolean remained = false;
            while (item[1] > 0) {
            }
        }
        return ans.toString();
    }
}
