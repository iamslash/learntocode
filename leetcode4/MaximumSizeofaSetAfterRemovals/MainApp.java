// Copyright (C) 2024 by iamslash

import java.util.*;

// Ideation: set
//
// The length of num is even.
//
// 0) no intersection
// nums1: 1 2 
// nums2: 5 6
//   ans: min(min(2, 1) + min(2, 1), 4) = 2
//
// 1) yes intersection
// nums1: 1 2
// nums2: 2 6
//   ans: min(min(2, 1) + min(2, 1), 3) = 2
//
// 2) no intersection, same numbers
// nums1: 1 1
// nums2: 2 2
//   ans: min(min(1, 1) + min(1, 1), 2) = 2
//
// 3) yes intersection, same numbers 
// nums1: 1 1
// nums2: 1 1
//   ans: min(min(1, 1) + min(1, 1), 1) = 1
//
// set1: set of nums1
// set2: set of nums2
// set3: set of union
//   ans: min(min(set1.len, nums1.len / 2) +
//            min(set2.len, nums2.len / 2),
//            set3)

// 39ms 42.59% 57MB 5.79%
// greedy
// O(N) O(N)
// difficult
class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        Set<Integer> set3 = new HashSet<>();

        for (int num: nums1) {
            set1.add(num);
            set3.add(num);
        }
        for (int num: nums2) {
            set2.add(num);
            set3.add(num);
        }
        return Math.min(Math.min(set1.size(), n / 2) +
                        Math.min(set2.size(), m / 2), set3.size());
    }
}
