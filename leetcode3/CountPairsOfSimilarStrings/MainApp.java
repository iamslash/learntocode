// Copyright (C) 2022 by iamslash

import java.util.*;

// 8ms 50.00% 44.7MB 37.50%
// hash map
// O(N) O(N)
class Solution {
    private int bitseq(String s) {
        int bm = 0;
        for (char c : s.toCharArray()) {
            bm |= (1 << c - 'a');
        }
        return bm;
    }
    private int factorial(int n) {
        int rst = 1;
        while (n > 0) {
            rst *= n;
            n--;
        }
        return rst;
    }
    public int similarPairs(String[] words) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (String s : words) {
            int bm = bitseq(s);
            freqMap.put(bm, freqMap.getOrDefault(bm, 0) + 1);
        }
        int ans = 0;
        for (int freq : freqMap.values()) {
            // System.out.printf("freq: %d\n", freq);
            if (freq > 1) {
                ans += freq * (freq - 1) / 2;
            }
        }
        return ans;
    }
}
