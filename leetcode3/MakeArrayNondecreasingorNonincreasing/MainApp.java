// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 3 2 4 5 0
// 

// 12ms 70.59% 43.3MB 76.47%
// heap
// O(NlgN) O(N)
class Solution {
    public int convertArray(int[] nums) {
        int n = nums.length, cnt1 = 0, cnt2 = 0, diff = 0;
        Queue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < n; ++i) {
            if (!maxHeap.isEmpty() && maxHeap.peek() >= nums[i]) {
                diff = maxHeap.poll() - nums[i];
                cnt1 += diff;
                maxHeap.offer(nums[i]);
            }
            maxHeap.offer(nums[i]);
        }
        diff = 0;
        Queue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            if (!minHeap.isEmpty() && minHeap.peek() <= nums[i]) {
                diff = nums[i] - minHeap.poll();
                cnt2 += diff;
                minHeap.offer(nums[i]);
            }
            minHeap.offer(nums[i]);
        }
        return Math.min(cnt1, cnt2);
    }
}

//               i
// nums: 3 2 4 5 0
//   pq: 2 2 4 0 0 
//  cnt: 6
//                 i
// nums: 0 5 4 2 3
//   pq: 0 2 2 3 3  
//  cnt: 4

// 7ms 94.12% 43MB 76.47%
// heap
// O(NlgN) O(N)
class Solution {
    public int convertArray(int[] nums) {
        int n = nums.length;
        int[] reversedNums = new int[nums.length];
        for (int i = 0; i < n; i++) {
            reversedNums[i] = nums[n - 1 - i];
        }
        return Math.min(getCnt(nums), getCnt(reversedNums));
    }
    private int getCnt(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        int cnt = 0;
        for (int num : nums) {
            if (!pq.isEmpty() && num < pq.peek()) {
                int largest = pq.poll();
                cnt += largest - num;
                pq.add(num); 
            }
            pq.add(num);
        }
        return cnt;
    }
}
