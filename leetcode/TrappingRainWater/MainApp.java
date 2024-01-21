// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 76.46% 46.2MB 27.67%
// two pointers
// O(N) O(1)
class Solution {
    public int trap(int[] heights) {
        int n = heights.length, water = 0;
        int maxIdx = 0, maxHeight = heights[0];
        int recentMax = heights[0];

        // Set maxIdx
        for (int i = 0; i < n; ++i) {
            if (heights[i] > maxHeight) {
                maxIdx = i;
                maxHeight = heights[i];
            }
        }
        // Traverse to right
        for (int i = 0; i < maxIdx; ++i) {
            recentMax = Math.max(recentMax, heights[i]);
            water += recentMax - heights[i];
        }

        // Traverse to left
        recentMax = heights[n - 1];
        for (int i = n - 1; i > maxIdx; --i) {
            recentMax = Math.max(recentMax, heights[i]);
            water += recentMax - heights[i];
        }
        return water;
    }
}

//                l
// heights: 0 1 0 2 1 0 1 3 2 1 2 1
//                                r
//    lMax: 1
//    rMax:
//   water: 1

// 0ms 100.00% 46.6MB 8.81%
// two pointers
// O(N) O(1)
class Solution {
    public int trap(int[] heights) {
        int n = heights.length, l = 0, r = n - 1;
        int water = 0, leftMax = heights[0], rightMax = heights[n - 1];
        while (l < r) {
            if (heights[l] <= heights[r]) {
                leftMax = Math.max(leftMax, heights[l]);
                water += leftMax - heights[l++];
            } else {
                rightMax = Math.max(rightMax, heights[r]);
                water += rightMax - heights[r--];
            }
        }
        return water;
    }
}
