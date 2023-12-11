// Copyright (C) 2023 by iamslash

// 1MS 100.00%43.4MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int countTestedDevices(int[] batteryPercentages) {
        int cnt = 0, delta = 0;
        for (int percent : batteryPercentages) {
            percent = Math.max(0, percent + delta);
            if (percent > 0) {
                cnt++;
                delta -= 1;
            } 
        }
        return cnt;
    }
}
