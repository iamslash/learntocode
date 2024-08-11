// Copyright (C) 2024 by iamslash

import java.util.*;

// 22ms 94.59% 57.5MB 61.16%
// sort
// O(NlgN) O(1)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        return nums[n - k];
    }
}

// 61ms 45.84% 62MB 5.37%
// heap
// O(NlgK) O(K)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Queue<Integer> pq = new PriorityQueue<>();

        for (int num : nums) {
            pq.offer(num);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        return pq.poll();
    }
}


//    k: 2
// nums: 3 2 1 5 6 4
//
//   left: 0
//  right: 5
// ascIdx: 4
// pvtIdx: 1
// pvtVal: 2
//           .
//           b
//   nums: 1 2 3 5 6 4
//                     i
//
//   left: 2
//  right: 5
// ascIdx: 4
// pvtIdx: 1
// pvtVal: 5
//               .
//                 b
//   nums:     3 4 5 6
//                     i
//
// qs(0, 5, 4)
//   qa(2, 5, 4)

// 2184ms 5.12% 61MB 26.82%
// quick select
// O(N) O(lgN)
class Solution {

    private Random rnd = new Random();

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    private int partition(int[] nums, int left, int right, int pvtIdx) {
        int pvtVal = nums[pvtIdx];
        swap(nums, pvtIdx, right);

        int pos = left;
        for (int i = left; i <= right; ++i) {
            if (nums[i] < pvtVal) {
                swap(nums, i, pos++);
            }
        }

        swap(nums, pos, right);
        return pos;
    }

    private int quickSelect(int[] nums, int left, int right, int ascIdx) {
        // base
        if (left == right) {
            return nums[left];
        }

        // recursion
        int pvtIdx = left + rnd.nextInt(right - left);
        int bndIdx = partition(nums, left, right, pvtIdx);
        if (ascIdx == bndIdx) {
            return nums[ascIdx];
        } else if (ascIdx < bndIdx) {
            return quickSelect(nums, left, bndIdx - 1, ascIdx);
        }
        return quickSelect(nums, bndIdx + 1, right, ascIdx);
    }
    
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        return quickSelect(nums, 0, n-1, n-k);
    }
}

// 3ms 99.58% 55.1MB 98.79%
// bucket sort
// O(N) O(N)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // range -10,000 to 10,000
        int[] count = new int[20001];
        int offset = 10000; // to handle negative values

        for (int num : nums) {
            count[num + offset]++;
        }

        int countSum = 0;
        for (int i = 20000; i >= 0; --i) {
            countSum += count[i];
            if (countSum >= k) {
                return i - offset;
            }
        }

        return -1;
    }
}
