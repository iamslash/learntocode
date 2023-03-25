// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 3 -2 6 -5
//   ps: 3  1 7  2

// nums: 6 -6 -3 3 1  5 -4 -3 -2 -3 4 -1 4 4 -2  6  0
//   ps: 6  0  3 6 7 12  8  5  3  0 4  3 7 11 9 15 15
//                   i
//   pq: -3   

// 14ms 61.54%
// greedy, min heap
// O(N) O(1)
class Solution {
    public int makePrefSumNonNegative(int[] nums) {
        int sum = 0, cnt = 0;
        Queue<Integer> pq = new PriorityQueue<>();
        for (int num : nums) {
            sum += num;
            if (num < 0) {
                pq.offer(num);
            }
            while (!pq.isEmpty() && sum < 0) {
                sum -= pq.poll();
                cnt++;
            }
        }
        return cnt;
    }
}
