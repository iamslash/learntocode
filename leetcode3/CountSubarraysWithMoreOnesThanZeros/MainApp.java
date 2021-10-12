// Copyright (C) 2021 by iamslash

import java.util.*;

//                  i
//    nums: 0 1 1 0 1
//  oneCnt: - 0 1 0 1
// prevCnt: 0 1 3 1 4
//  cntMap: - 0 1
//          1 3 2
//     ans: 0 1 4 5 9

// 107ms 10.00% 134.7MB 10.00%
// iterative dynamic programming
// O(N) O(N)
// difficult to understand
class Solution {
    private final int MOD = 1_000_000_007;
    public int subarraysWithMoreZerosThanOnes(int[] nums) {
        int ans = 0, oneCnt = 0, curSubarrayCnt = 0;
        // { count of 1 : freq when count of 1}
        Map<Integer, Integer> cntMap = new HashMap<>();
        cntMap.put(0, 1);
        for (int num : nums) {
            if (num == 1) {
                curSubarrayCnt = (curSubarrayCnt + cntMap.getOrDefault(oneCnt, 0)) % MOD;
                oneCnt++;
            } else {
                oneCnt--;
                curSubarrayCnt = (curSubarrayCnt - cntMap.getOrDefault(oneCnt, 0)) % MOD;
            }
            cntMap.putIfAbsent(oneCnt, 0);
            cntMap.put(oneCnt, cntMap.get(oneCnt) + 1);
            ans = (ans + curSubarrayCnt) % MOD;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
