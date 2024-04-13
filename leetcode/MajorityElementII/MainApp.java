// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: boyer-moore algorithm
//
// Find all elements which appear more than n/3.
// The number of elements is 2 at most.
//
// Define numA, numB, cntA, cntB.
// Build those.
//
// We need to recalculate cntA, cntB
// because we decreased before.
//
// Finaly find numbers which appear more than n/3.

//               i
// nums: 2 2 1 3
//       i
// numA: 2
// cntA: 1
// numB: 1
// cntB: 0

// 2ms 99.22% 47.6MB 68.72%
// boyer-moore
// O(N) O(1)
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        int numA = -1, numB = -1;
        int cntA = 0, cntB = 0;

        for (int num : nums) {
            if (num == numA) {
                cntA++;
            } else if (num == numB) {
                cntB++;
            } else if (cntA == 0) {
                numA = num;
                cntA = 1;
            } else if (cntB == 0) {
                numB = num;
                cntB = 1;
            } else {
                cntA--;
                cntB--;
            }
        }

        cntA = 0;
        cntB = 0;
        for (int num : nums) {
            if (num == numA) {
                cntA++;
            } else if (num == numB) {
                cntB++;
            }
        }

        List<Integer> ans = new ArrayList<>();
        if (cntA > n / 3) {
            ans.add(numA);
        }
        if (cntB > n / 3) {
            ans.add(numB);
        }
        return ans;
    }
}
