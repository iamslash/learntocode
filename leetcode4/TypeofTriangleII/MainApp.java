// Copyright (C) 2024 by iamslash

import java.util.*;


// 1ms 61.63% 42.6MB 6.005
// math
// O(1) O(1)
class Solution {
    public String triangleType(int[] nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b <= c || b + c <= a || c + a <= b) {
            return "none";
        } else if (a == b && b == c) {
            return "equilateral";
        } else if (a != b && b != c && a != c) {
            return "scalene";
        } else if (a == b || b == c || c == a) {
            return "isosceles";
        }
        return "none";
    }
}
