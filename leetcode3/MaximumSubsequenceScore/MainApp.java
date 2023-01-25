// Copyright (C) 2023 by iamslash

import java.util.*;

//     k: 3
// nums1: 1 3 3 2
// nums2: 2 1 3 4
//
//          i
// nums1: 2 3 1 3
// nums2: 4 3 2 1

// 102ms 76.52% 58.8MB 86.03%
// sort, heap
// O(NlgN) O(N)
class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; ++i) {
            pairs[i][0] = nums1[i];
            pairs[i][1] = nums2[i];
        }
        // Sort DESC
        Arrays.sort(pairs, (a, b) -> b[1] - a[1]);
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);
        long ans = 0, sum = 0;
        for (int[] pair : pairs) {
            pq.offer(pair[0]);
            sum += pair[0];
            if (pq.size() > k) {
                sum -= pq.poll();
            }
            if (pq.size() == k) {
                ans = Math.max(ans, sum * pair[1]);
            }
        }
        return ans;
    }
}
