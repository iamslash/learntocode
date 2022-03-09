// Copyright (C) 2022 by iamslash

import java.util.*;

//           s: cczazcc
// repeatLimit: 3
//                   i
//              zzcccca
//         

// 36ms 79.80% 43.1MB 91.00%
// priority queue
// O(NlgN) O(N)
class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int freqs[] = new int[26];
        StringBuilder sb = new StringBuilder();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> b[0] - a[0]);
        for(int i = 0; i < s.length(); i++){
            freqs[s.charAt(i)-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freqs[i] > 0) {
                pq.add(new int[]{i, freqs[i]});
            }
        }

        while (!pq.isEmpty()){
            int item[] = pq.poll();
            int code = item[0], freq = item[1], len = Math.min(freq, repeatLimit);
            for(int i = 0 ; i < len; i++){
                sb.append((char)(code + 'a'));
            }
            freq -= len;
            if (freq > 0 && !pq.isEmpty()){
                pq.peek()[1] -= 1;
                sb.append((char)(pq.peek()[0] + 'a'));
                if(pq.peek()[1] == 0) {
                    pq.poll(); 
                }
                pq.add(new int[]{code, freq});
            }
        }
        return sb.toString();
    }
}


