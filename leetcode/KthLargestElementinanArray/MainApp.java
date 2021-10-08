// Copyright (C) 2021 by iamslash

import java.util.*;

// // 1ms 98.54% 39.5MB 54.82%
// // sort
// // O(NlgN) O(1)
// class Solution {
//     public int findKthLargest(int[] nums, int k) {
//         int n = nums.length;
//         Arrays.sort(nums);
//         return nums[n-k];
//     }
// }

// 4ms 68.65% 39.1MB 80.34%
// heap
// O(NlgK) O(1)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);
        for (int num: nums) {
            pq.offer(num);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        return pq.poll();
    }
}

public class MainApp {
  public static void main(String[] args) {
      
  }
}
