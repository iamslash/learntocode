// Copyright (C) 2021 by iamslash

import java.util.*;

//                  i
//    nums: 0 1 1 0 1
//  oneCnt: - 0 1 0 1
//  curCnt: 0 1 3 1 4
//  cntMap: - 0 1
//          1 3 2
//     ans: 0 1 4 5 9

// 107ms 10.00% 134.7MB 10.00%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    private final int MOD = 1_000_000_007;
    public int subarraysWithMoreZerosThanOnes(int[] nums) {
        int ans = 0, oneBal = 0, curCnt = 0;
        // { count of 1 : freq when count of 1}
        Map<Integer, Integer> cntMap = new HashMap<>();
        cntMap.put(0, 1);
        for (int num : nums) {
            if (num == 1) {
                curCnt = (curCnt + cntMap.getOrDefault(oneBal, 0)) % MOD;
                oneBal++;
            } else {
                oneBal--;
                curCnt = (curCnt - cntMap.getOrDefault(oneBal, 0)) % MOD;
            }
            cntMap.putIfAbsent(oneBal, 0);
            cntMap.put(oneBal, cntMap.get(oneBal) + 1);
            ans = (ans + curCnt) % MOD;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
