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
        StringBuilder ans = new StringBuilder();
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; ++i) {
            if (freqs[i] > 0) {
                pq.offer(new int[]{i, freqs[i]});
            }
        }
        while (!pq.isEmpty()) {
            int item[] = pq.poll();
            int code = item[0], freq = item[1], len = Math.min(freq, repeatLimit);
            for (int i = 0; i < len; ++i) {
                ans.append((char)(code + 'a'));
            }
            freq -= len;
            if (freq > 0 && !pq.isEmpty()) {
                pq.peek()[1] -= 1;
                ans.append((char)(pq.peek()[0] + 'a'));
                if (pq.peek()[1] == 0) {
                    pq.poll();
                }
                pq.add(new int[]{code, freq});
            }
        }
        return ans.toString();
    }
}
