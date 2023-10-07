// Copyright (C) 2023 by iamslash

import java.util.*;

//    k: 20
//                  i
// nums: 2 3 3 7 3 5
// stck: 18 7 15      
//        
//

// nums: 2 3 3

// 9ms 26.32% 56.9MB 31.58%
// greedy, stack
// O(N) O(N)
class Solution {
    public int minArrayLength(int[] nums, int k) {
        Deque<Long> deq = new ArrayDeque<>();
        for (int num : nums) {
            long prod = num;
            while (deq.size() > 0 && deq.peekLast() * prod <= k) {
                prod *= deq.removeLast();
            }
            deq.addLast(prod);
        }
        return deq.size();
    }
}

//    k: 20
//                 i
// nums: 2 3 3 7 3 5
//  prv: 15
//  ans: 3

// 1ms 100.00% 55.7MB 89.47%
// greedy
// O(N) O(1)
class Solution {
    public int minArrayLength(int[] nums, int k) {
        int n = nums.length, ans = n;
        long prv = nums[0];
        for (int i = 1; i < n; ++i) {
            if (prv * nums[i] <= k) {
                ans--;
                prv *= nums[i];
            } else {
                prv = nums[i];
            }
        }
        return prv == 0 ? 1 : ans;
    }
}
