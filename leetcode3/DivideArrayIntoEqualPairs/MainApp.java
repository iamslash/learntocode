// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 100.00% 46.4MB 25.00%
// hash map
// O(N) O(N)
class Solution {
    public boolean divideArray(int[] nums) {
        int[] freqs = new int[501];
        for (int num : nums) {
            freqs[num]++;
        }
        for (int freq : freqs) {
            if (freq > 0 && (freq % 2) == 1) {
                return false;
            }
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
