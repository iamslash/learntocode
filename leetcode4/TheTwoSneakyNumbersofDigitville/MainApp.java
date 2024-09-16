// Copyright (C) 2024 by iamslash

// 1ms 100.00% 44.3MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length;
        int[] cnts = new int[n + 2];
        int[] ans = new int[]{-1, -1};

        for (int num : nums) {
            cnts[num]++;
            if (cnts[num] > 1) {
                if (ans[0] < 0) {
                    ans[0] = num;
                } else {
                    ans[1] = num;
                    break;
                }
            }
        }

        return ans;
    }
}
