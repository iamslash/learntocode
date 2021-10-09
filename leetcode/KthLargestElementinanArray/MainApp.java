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

// // 4ms 68.65% 39.1MB 80.34%
// // heap
// // O(NlgK) O(1)
// class Solution {
//     public int findKthLargest(int[] nums, int k) {
//         PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);
//         for (int num: nums) {
//             pq.offer(num);
//             if (pq.size() > k) {
//                 pq.poll();
//             }
//         }
//         return pq.poll();
//     }
// }

//     p
//                   i
// 2 1 2 6 3 4 5 5 3
//       s

// Wrong Answer:
// [3,2,3,1,2,4,5,5,6]
// 4
// quick select
// average: O(N) O(1)
//   worst: O(N^2)
class Solution {
    int[] nums;
    public void swap(int a, int b) {
        int tmp = this.nums[a];
        this.nums[a] = this.nums[b];
        this.nums[b] = tmp;
    }
    public int partition(int left, int right, int pivotIdx) {
        int pivotVal = this.nums[pivotIdx];
        // move pivot to end
        swap(pivotIdx, left);
        int storeIdx = left;
        // move all smaller elements to the left
        for (int i = left; i <= right; ++i) {
            if (this.nums[i] < pivotVal) {
                swap(storeIdx, i);
                storeIdx++;
            }
        }
        // move pivot to its final place
        swap(storeIdx, right);
        return storeIdx;
    }
    public int quickselect(int left, int right, int kSmallest) {
        if (left == right) {
            return this.nums[left];
        }
        Random randomNum = new Random();
        int pivotIdx = left + randomNum.nextInt(right - left);
        pivotIdx = partition(left, right, pivotIdx);
        if (kSmallest == pivotIdx) {
            // the pivot is on (n-k)th smallest position
            return this.nums[kSmallest];
        } else if (kSmallest < pivotIdx) {
            // left side    
            return quickselect(left, pivotIdx - 1, kSmallest);
        }
        // right side
        return quickselect(pivotIdx + 1, right, kSmallest);
    }
    public int findKthLargest(int[] nums, int k) {
        this.nums = nums;
        int n = nums.length;
        return quickselect(0, n-1, n-k);
    }
}

public class MainApp {
  public static void main(String[] args) {
      
  }
}
