// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 10
// 
// nums: 2 11 10 1 3
//       4 11 10 3
//       11 10 10

//    k: 20
// nums: 1 1 2 4 9
//       2 4 9 3
//       4 9 7
//       9 15
//       33

// 148ms 70.53% 70.6MB 54.13% 
// heap
// O(NlgN) O(N)
class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length, cnt = 0;
        Queue<Long> pq = new PriorityQueue<>();

        for (int num : nums) {
            pq.offer((long)num);
        }

        while (pq.size() > 1 && pq.peek() < k) {
            cnt++;
            long a = pq.poll(), b = pq.poll();
            long num = Math.min(a, b) * 2 + Math.max(a, b);
            pq.offer(num);
        }

        return cnt;
    }
}
