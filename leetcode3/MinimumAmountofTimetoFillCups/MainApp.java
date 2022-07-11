// Copyright (C) 2022 by iamslash

import java.util.*;


// Idea:
//
// There are 2 cases
// 0. The count is water of max cup.
// 1. The count is ceil(sum of water / 2)
// The answer is max(case 0, case 1)
//
// ex)
// amount: 1 4 2
//    ans: 4
//
// amount: 9 1 1
//    ans: 9
//
// amount: 9 8 1
//    ans: 9
//
// amount: 9 9 1
//    ans: 10

// 0ms 100.00% 41.5MB 81.82%
// math
// O(1) O(1)
class Solution {
    public int fillCups(int[] amount) {
        int maxCnt = Math.max(amount[0], Math.max(amount[1], amount[2]));
        int ceilVal = (amount[0] + amount[1] + amount[2] + 1) / 2;
        return Math.max(maxCnt, ceilVal);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
