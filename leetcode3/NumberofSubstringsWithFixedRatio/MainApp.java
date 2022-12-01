// Copyright (C) 2022 by iamslash

import java.util.*;

//          i
//       s: 0 1 1 0 0 1 1
//     ans: 
// freqMap:
//     

// 210ms 100.00% 115.6MB 100.00%
// hash map
// O(N) O(N)
class Solution {
    public long fixedRatio(String s, int num1, int num2) {
        long ans = 0;
        int sum = 0;
        Map<Integer, Integer> freqMap = new HashMap<>();
        freqMap.put(0, 1);
        for (char c : s.toCharArray()) {
            if (c == '0') {
                sum += num2;
            } else {
                sum -= num1;
            }
            ans += freqMap.getOrDefault(sum, 0);
            freqMap.put(sum, freqMap.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}
