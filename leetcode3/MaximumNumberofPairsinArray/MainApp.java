// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 43.1MB 20.0%
// hash map
// O(N) O(1)
class Solution {
    public int[] numberOfPairs(int[] nums) {
        int[] freqs = new int[101];
        for (int a : nums) {
            freqs[a]++;
        }
        int remCnt = 0, pairCnt = 0; 
        for (int a = 0; a <= 100; ++a) {
            if (freqs[a] > 0) {
                pairCnt += (freqs[a] / 2);
                remCnt += (freqs[a] % 2);
            }
        }
        return new int[]{pairCnt, remCnt};
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
