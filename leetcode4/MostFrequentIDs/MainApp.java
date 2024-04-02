// Copyright (C) 2024 by iamslash

import java.util.*;

//             i
//     nums: 2 3  2 1
//    freqs: 3 2 -3 1
// 
// numFreqs: 2 3
//           3 2
//       pq: 2 3
//           3 2
//      ans: 3 3

// 47ms 93.09% 64.1MB 87.55%
// heap
// O(NlgN) O(N)
class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freqs) {
        int n = nums.length;
        long[] ans = new long[n];
        Queue<long[]> pq = new PriorityQueue<long[]>((a, b) -> Long.compare(b[1], a[1]));
        long[] numFreqs = new long[100_001];

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            numFreqs[num] += freqs[i];
            pq.offer(new long[]{(long)num, numFreqs[num]});
            while (numFreqs[(int)pq.peek()[0]] != pq.peek()[1]) {
                pq.poll();
            }
            long maxFreq = pq.isEmpty() ? 0 : pq.peek()[1];            
            ans[i] = maxFreq;
        }

        return ans;
    }
}
