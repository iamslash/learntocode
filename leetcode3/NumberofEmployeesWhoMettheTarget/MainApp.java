// Copyright (C) 2023 by iamslash

// 0ms 100.00% 41.2MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int cnt = 0;
        for (int hour : hours) {
            if (cnt >= target) {
                cnt++;
            }
        }
        return cnt;
    }
}
