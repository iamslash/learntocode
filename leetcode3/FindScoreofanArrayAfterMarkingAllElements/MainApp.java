// Copyright (C) 2023 by iamslash

import java.util.*;

// 265ms 66.67% 60.2MB 50.00%
// greedy, heap
// O(NlgN) O(N)
class Solution {
    public long findScore(int[] nums) {
        long score = 0;
        int n = nums.length;
        boolean[] marked = new boolean[n];
        Queue<Integer> pq = new PriorityQueue<>((i, j) -> nums[i] == nums[j] ? i - j : nums[i] - nums[j]);
        for (int i = 0; i < n; ++i) {
            pq.offer(i);
        }
        while (!pq.isEmpty()) {
            while (!pq.isEmpty() && marked[pq.peek()]) {
                pq.poll();
            }
            if (pq.isEmpty()) {
                break;
            }
            int idx = pq.poll();
            score += nums[idx];
            marked[idx] = true;
            if (idx > 0) {
                marked[idx - 1] = true;
            }
            if (idx < n - 1) {
                marked[idx + 1] = true;
            }
        }
        return score;
    }
}
