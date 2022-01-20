// Copyright (C) 2022 by iamslash

import java.util.*;

//                     l
// height: 0 1 0 2 1 0 1 3 2 1 2 1
//                       r

//               l
// height: 5 5 1 7 1 1 5 2 7 6
//                         r
//   lMax: 7
//   rMax: 7
//  water: 4

// two pointers
// O(N) O(1)
class Solution {
    public int trap(int[] height) {
        int n = height.length, water = 0, lCum = 0, rCum = 0;
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
