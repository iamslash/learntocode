// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 5 6
//

// Idea:
// Increment the least number

// 773ms 7.30% 128MB 32.73%
// mean heap
// O(NlgN) O(N)
class Solution {
    public int maximumProduct(int[] nums, int k) {
        int MOD = 1_000_000_007;
        int n = nums.length;
        if (n == 1) {
            return (int)(((long)nums[0] + k) % MOD); 
        }
        Queue<Long> pq = new PriorityQueue<>();
        for (int num : nums) {
            pq.offer((long)num);
        }
        while (k > 0) {
            long a = pq.poll(), b = pq.poll();
            long diff = Math.min(k, (b - a) + 1);
            a += diff;
            k -= diff;
            pq.offer(a);
            pq.offer(b);
        }
        long ans = 1;
        while (!pq.isEmpty()) {
            ans = ans * pq.poll() % MOD;
        }
        return (int)ans;        
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
