// Copyright (C) 2022 by iamslash

import java.util.*;

// changed: 1 3 4 2 6 8
//                i
//          1 2 3 4 6 8
//                    j
//     ans: 1 3 4
// changed: 0 1 3 6
//          0 2 6 12

// 362ms 31.08% 61.5MB 84.92%
// hash map
// O(NlgN) O(N)
class Solution {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        if (n % 2 == 1) {
            return new int[0];
        }
        Map<Integer, Integer> freqMap = new TreeMap<>();
        for (int a : changed) {
            freqMap.put(a, freqMap.getOrDefault(a, 0) + 1);
        }
        int i = 0;
        int[] ans = new int[n/2];
        for (int a : freqMap.keySet()) {
            int d = a + a; //doubled a
            if (freqMap.get(a) > freqMap.getOrDefault(d, 0)) {
                return new int[0];
            }
            for (int j = 0; j < freqMap.get(a); ++j) {
                ans[i++] = a;
                freqMap.put(d, freqMap.get(d) - 1);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
