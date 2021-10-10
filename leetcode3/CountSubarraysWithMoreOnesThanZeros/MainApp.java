// Copyright (C) 2021 by iamslash

import java.util.*;

//           i
// nums: 0 1 1 0 1
//  amt: - 0
//   dp: 0 1
//    C: - 0
//       1 2
//  cnt:   1


// iterative dynamic programming
// O(N) O(N)
class Solution {
    private final int MOD = 1_000_000_007;
    public int subarraysWithMoreZerosThanOnes(int[] nums) {
        int ans = 0, oneCnt = 0, prevCnt = 0;
        // { count of 1 : freq when count of 1}
        Map<Integer, Integer> cntMap = new HashMap<>();
        cntMap.put(0, 1);
        for (int num : nums) {
            if (num == 1) {
                prevCnt = (prevCnt + cntMap.getOrDefault(oneCnt, 0)) % MOD;
                oneCnt++;
            } else {
                oneCnt--;
                prevCnt = (prevCnt - cntMap.getOrDefault(oneCnt, 0)) % MOD;
            }
            cntMap.putIfAbsent(oneCnt, 0);
            cntMap.put(oneCnt, cntMap.get(oneCnt) + 1);
            ans = (ans + prevCnt) % MOD;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
