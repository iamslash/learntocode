// Copyright (C) 2024 by iamslash

import java.util.*;

// nums: 4 5 8
// 

// 12ms 97.39% 46.9MB 53.61%
// heap
// KthLarget: O(N)
//       add: O(lgN)
class KthLargest {

    private Queue<Integer> pq = new PriorityQueue<>();
    int bnd = 0;

    public KthLargest(int k, int[] nums) {
        this.bnd = k;
        int n = nums.length, i = 0;

        for (i = 0; i < k && i < n; ++i) {
            pq.offer(nums[i]);
        }

        while (i < n) {
            add(nums[i++]);
        }
    }
    
    public int add(int val) {
        if (pq.size() < bnd) {
            pq.offer(val);
        } else if (pq.peek() < val) {
            pq.poll();
            pq.offer(val);
        }
        return pq.peek();
    }
}

