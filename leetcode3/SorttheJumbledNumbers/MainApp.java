// Copyright (C) 2022 by iamslash

import java.util.*;

// mapping: 8 ...
//    nums: 991 338 38
//          669 007 07
//    idxs:   0   1  2

// Wrong Answer for:
// [9,8,7,6,5,4,3,2,1,0]
// [0,1,2,3,4,5,6,7,8,9]

// hash map, sort
// O(NlgN) O(n)
class Solution {
    private int getOrgNum(int[] mapping, int num) {
        int org = 0, mul = 1;
        while (num > 0) {
            int dgt = mapping[num % 10];
            org = mul * dgt + org;
            mul *= 10;
            num /= 10;
        }
        return org;
    }
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        int[] orgs = new int[n];
        Integer[] idxs = new Integer[n];
        for (int i = 0; i < n; ++i) {
            orgs[i] = getOrgNum(mapping, nums[i]);
            idxs[i] = i;
        }
        Arrays.sort(idxs, (i, j) -> {
                if (orgs[i] == orgs[j]) {
                    return i - j;
                }
                return orgs[i] - orgs[j];
            });
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[idxs[i]];
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
