// Copyright (C) 2022 by iamslash

import java.util.*;

// 121ms 100.00% 129.3MB 100.00%
// hash map, heap
// O(NlgM) O(N)
class Solution {
    private int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    public int maximumSum(int[] nums) {
        Map<Integer, Queue<Integer>> dgtSum2PqMap = new HashMap<>();
        for (int num : nums) {
            int dgtSum = digitSum(num);
            dgtSum2PqMap.putIfAbsent(dgtSum, new PriorityQueue<>((a, b) -> b - a));
            dgtSum2PqMap.get(dgtSum).offer(num);
        }
        int maxSum = -1;
        for (int k : dgtSum2PqMap.keySet()) {
            Queue<Integer> q = dgtSum2PqMap.get(k);
            if (q.size() > 1) {
                // System.out.println(q);
                int sum = q.poll();
                sum += q.poll();
                if (sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
}
