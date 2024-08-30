// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 5
// mltf: 2
// nums: 2 1 3 5 6
//         2
//       4
//         4
//           6
//       8
// nums: 1 2 3 4 5
//       1 0 2 3 4

// 4ms 14.19% 45.1MB 16.25%
// heap
// O(KNlgN) O(N)
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int n = nums.length;
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

        for (int i = 0; i < n; ++i) {
            pq.offer(new int[]{nums[i], i});
        }

        while (k-- > 0) {
            int[] top = pq.poll();

            top[0] *= multiplier;

            pq.offer(top);
        }

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int val = top[0], idx = top[1];
            nums[idx] = val;
        }

        return nums;        
    }
}


// 1ms 100.00% 44.9MB 49.21%
// brute force
// O(KN) O(1)
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int n = nums.length;

        for (int i = 0; i < k; ++i) {
            int minVal = Integer.MAX_VALUE;
            int idx = 0;

            for (int j = 0; j < n; ++j) {
                if (nums[j] < minVal) {
                    minVal = nums[j];
                    idx = j;
                }
            }

            nums[idx] *= multiplier;
        }

        return nums;
    }
}

