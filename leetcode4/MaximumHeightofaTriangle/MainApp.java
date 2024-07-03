// Copyright (C) 2024 by iamslash

// 1ms 86.34% 40.5MB 90.34%
// math
// O(N) O(1)
class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(simulate(red, blue), simulate(blue, red));
    }
    private int simulate(int hi, int lo) {
        int i = 1, lv = 0;

        while (true) {
            if (i % 2 == 0) {
                if (hi >= i) {
                    hi -= i;
                } else {
                    break;
                }
            } else {
                if (lo >= i) {
                    lo -= i;
                } else {
                    break;
                }
            }
            
            i++;
            lv++;
        }

        return lv;
    }
}
