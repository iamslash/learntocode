// Copyright (C) 2022 by iamslash

import java.util.*;

//  1  4  7 11 15
//  2  5  8 12 19
//  3  6  9 16 22
// 10 13 14 17 24
// 18 21 23 26 30


// Traverse from right top
// 10ms 55.57% 57.5MB 30.58%
// brute force
// O(H+W) O(1)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int h = matrix.length, w = matrix[0].length, y = 0, x = w-1;
        while (y < h && x >= 0) {
            if (matrix[y][x] == target) {
                return true;
            } else if (matrix[y][x] > target) {
                --x;
            } else {
                ++y;
            }
        }
        return false;  
    }
}
