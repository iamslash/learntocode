// Copyright (C) 2023 by iamslash

import java.util.*;

// 7 2 1    1 2 7
// 6 4 2    2 4 6
// 6 5 3    3 5 6
// 3 2 1    1 2 3

// 17ms 38.81% 68.6MB 8.18%
// sort
// O(N^2lgN) O(1)
class Solution {
    public int matrixSum(int[][] nums) {
        int h = nums.length, w = nums[0].length;
        for (int[] line : nums) {
            Arrays.sort(line);
        }
        int sum = 0;
        for (int x = 0; x < w; ++x) {
            int maxNum = 0;
            for (int y = 0; y < h; ++y) {
                maxNum = Math.max(maxNum, nums[y][x]);
            }
            sum += maxNum;
        }
        return sum;
    }
}
