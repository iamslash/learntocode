// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 3
// nums: 1 3 -1 -3 5 3 6 7
//                       i
//  deq: 7 
//  ans:      3  3 5 5 6 7

// 53ms 61.11% 141.5MB 30.20%
// sliding window
// O(N) O(K)
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> deq = new ArrayDeque<>();
        int n = nums.length;
        int[] ans = new int[n-k+1];
        for (int i = 0; i < n; ++i) {
            while (deq.size() > 0 && nums[deq.peekLast()] < nums[i]) {
                deq.pollLast();
            }
            deq.offerLast(i);
            if (i >= k && deq.size() > 0 && deq.peekFirst() == i-k) {
                deq.pollFirst();
            }
            if (i >= k - 1) {
                ans[i-k+1] = nums[deq.peekFirst()];
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
