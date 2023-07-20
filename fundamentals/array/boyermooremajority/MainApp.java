// Copyright (C) 2023 by iamslash

import java.util.*;

//                               i
// nums: 1 1 1 3 3 2 2 3 3 3 2 3 3
//  maj: 3
//  cnt: 4

// boyer moore
// O(N) O(1)
class MainApp {
    public int majorityElement(int[] nums) {
        int maj = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0 || maj == num) {
                cnt++;
                maj = num;
            } else {
                cnt--;
            }
        }
        return maj;
    }
    public static void main(String[] args) {
        Solution sln = new Solution();
        int[] nums = new int[]{1, 1, 1, 3, 3, 2, 2, 3, 3, 3, 2, 3, 3};
        System.out.println(sln.majorityElement(nums));
    }
}
