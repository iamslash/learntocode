// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: left most equal binary search, sliding window
//
// Do left most equal binary search the window.
// - center value (x) - left value > right value - center value (x)
// Gather k numbers from the left index of the window.

//   k: 4
//   x: 3
//      l
// arr: 1 2 3 4 5
//      h
//      m

//   k: 4
//   x: 3
//      l
// arr: 1 2 3 4 5 6 7
//        h
//      m

// 4ms 95.72% 46MB 42.08%
// left most equal binary search, slide window
// O(log(N-k) + k) O(N)
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n = arr.length;
        int lo = 0, hi = n - k;

        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (x - arr[mi] > arr[mi + k] - x) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = lo; i < lo + k; ++i) {
            ans.add(arr[i]);
        }

        return ans;                                           
    }
}
