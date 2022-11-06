// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 5
// nums: 2 4 -2

//           i
// nums: 2 2 4
//  ans: 4
//   pq: 2,2 0,2

// priority queue
// O(NlgN) O(N)
// 111ms 54.68% 90.7MB 5.61% 
class Solution {
    public long kSum(int[] nums, int k) {
        int n = nums.length;
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.max(nums[i], 0);
            nums[i] = Math.abs(nums[i]);
        }
        Arrays.sort(nums);        
        Queue<long[]> pq = new PriorityQueue<long[]>((a, b) -> Long.compare(b[0], a[0]));
        pq.offer(new long[]{ans - nums[0], 0});
        while (--k > 0) {
            long[] top = pq.poll();
            long sum = top[0];
            int i = (int)top[1];
            if (i < n - 1) {
                pq.offer(new long[]{sum - nums[i + 1] + nums[i], i + 1});
                pq.offer(new long[]{sum - nums[i + 1], i + 1});
            }
            ans = sum;
        }
        return ans;        
    }
}
