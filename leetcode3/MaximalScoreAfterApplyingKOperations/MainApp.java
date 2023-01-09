// Copyright (C) 2023 by iamslash

import java.util.*;

// 155ms 100.00% 59.4MB 40.00%
// priority queue
// O(NlgN) O(N)
class Solution {
    public long maxKelements(int[] nums, int k) {
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int num : nums) {
            pq.offer(num);
        }
        long ans = 0;
        while (!pq.isEmpty() && k > 0) {
            int top = pq.poll();
            ans += top;
            pq.offer((int)Math.ceil(top / 3.0));
            k--;
        }
        return ans;
    }
}
