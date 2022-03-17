// Copyright (C) 2022 by iamslash

import java.util.*;

//     time: 2
//                   i
// security: 5 3 3 3 5 6 2

// Time Limit Exceeded
// brute force
// O(NT) O(1)
class Solution {
    private boolean validate(int[] security, int beg, int end, int mode) {
        if (beg == end) {
            return true;
        }
        for (int i = beg; i < end; ++i) {
            if (mode == 0 && security[i] < security[i+1]) { // non-increasing
                return false;
            } else if (mode == 1 && security[i] > security[i+1]) {
                return false;
            }
        }
        return true;
    }
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        List<Integer> ans = new ArrayList<>();
        int n = security.length;
        for (int i = time; i < n - time; ++i) {
            // Validate left
            if (validate(security, i - time, i, 0) == false) {
                continue;
            }
            // Validate right
            if (validate(security, i, i + time, 1) == false) {
                continue;
            }
            ans.add(i);
        }
        return ans;
    }
}

//     time: 2
//                 i    
// security: 5 3 3 3 5 6 2
//                       i
//    lefts: 0 1 2 3 0 0 1
//           i
//   rights: 0 4 3 2 1 0 0

// 6ms 96.85% 61.8MB 85.63%
// prefix sum
// O(N) O(N)
class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        int n = security.length;
        int[] lefts = new int[n];
        int[] rights = new int[n];
        for (int i = 1; i < n; ++i) {
            lefts[i] = security[i-1] >= security[i] ? lefts[i-1] + 1 : 0;
        }
        for (int i = n-2; i >= 0; --i) {
            rights[i] = security[i] <= security[i+1] ? rights[i+1] + 1 : 0;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = time; i < n - time; ++i) {
            if (lefts[i] >= time && rights[i] >= time) {
                ans.add(i);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
