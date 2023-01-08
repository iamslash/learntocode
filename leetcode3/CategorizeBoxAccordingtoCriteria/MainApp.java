// Copyright (C) 2023 by iamslash

import java.util.*;

// 0ms 100.00%, 39.5MB, 100.00%
// brute force
// O(1) O(1)
class Solution {
    public String categorizeBox(int length, int width, int height, int mass) {
        int dimensionBound = 10_000, volumeBound = 1_000_000_000, massBound = 100;
        long volume = (long)length * width * height;
        boolean bulky = length >= dimensionBound ||
            width >= dimensionBound ||
            height >= dimensionBound ||
            volume >= volumeBound;
        boolean heavy = mass >= massBound;
        if (bulky && heavy) {
            return "Both";
        }
        if (!bulky && !heavy) {
            return "Neither";
        }
        if (bulky && !heavy) {
            return "Bulky";
        }
        return "Heavy";
    }
}
