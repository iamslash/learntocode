// Copyright (C) 2022 by iamslash

import java.util.*;

// nums1: 1 2 3 4
// nums2: 2 10 20 19
//    pq: 1 8 15
//     k:  0
//     x:  2

// nums1: 10 10 10 11 5
// nums2:  1  0  6  6 1
//    pq:
//     k: 38

// heap
// O(NlgN) O(N)
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        pq.add(0);
        int n = nums1.length;
        for (int i = 0; i < n; ++i) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            if (diff > 0) {
                pq.add(diff);
            }
        }
        int k = k1 + k2;
        int prv = 0, cnt = 0;
        while (k > 0 && !pq.isEmpty()) {
            int top = pq.poll();
            if (pq.isEmpty()) {
                if (top > k) {
                    pq.offer(top - k);
                }
            } else {
                int gap = Math.min(top - pq.peek() + 1, k);
                pq.offer(top - gap);
                k -= gap;
            }
        }
        long ans = 0;
        for (long diff : pq) {
            ans += (long) diff * diff;
        }
        return ans;
    }
}
