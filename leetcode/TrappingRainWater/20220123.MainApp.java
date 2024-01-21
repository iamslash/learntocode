// Copyright (C) 2022 by iamslash

import java.util.*;

//                     l
// height: 0 1 0 2 1 0 1 3 2 1 2 1
//                       r

//               l
//
// height: 5 5 1 7 1 1 5 2 7 6
//                         r
//   lMax: 7
//   rMax: 7
//  water: 4

// one pointer
// O(N) O(1)
class Solution {
    public int trap(int[] height) {
        int n = height.length, maxIdx = 0, maxHeight = height[0];
        int ans = 0;
        int locMax = height[0];
        for (int i = 0; i < n; ++i) {
            if (height[i] > maxHeight) {
                maxIdx = i;
                maxHeight = height[i];
            }
        }
        for (int i = 0; i < maxIdx; ++i) {
            locMax = Math.max(locMax, height[i]);
            ans += locMax - height[i];
        }
        locMax = height[n-1];
        for (int i = n-1; i > maxIdx; --i) {
            locMax = Math.max(locMax, height[i]);
            ans += locMax - height[i];
        }
        return ans;
    }
}

// 1ms 92.24% 42.1MB 23.56%
// two pointers
// O(N) O(1)
class Solution {
    public int trap(int[] height) {
        int n = height.length, water = 0;
        int l = 0, r = n-1, lMax = height[0], rMax = height[n-1];
        while (l < r) {
            if (height[l] <= height[r]) {
                lMax = Math.max(lMax, height[l]);
                water += lMax - height[l++];
            } else {
                rMax = Math.max(rMax, height[r]);
                water += rMax - height[r--];
            }
        }
        return water;
    }
}
