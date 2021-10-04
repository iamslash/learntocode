// Copyright (C) 2021 by iamslash

import java.util.*;

//  target: 7777
//    nums: 777 7 77 77
// freqMap: 7 77 777
//          1  2   3

// 2ms 100.00% 38.6MB 100.00%
// hash map
// O(N) O(N)
class Solution {
    public int numOfPairs(String[] nums, String tgt) {
        Map<String, Integer> freqMap = new HashMap<>();
        int cnt = 0;
        for (String s : nums) {
            freqMap.putIfAbsent(s, 0);
            freqMap.put(s, freqMap.get(s) + 1);
        }
        for (String prefix : freqMap.keySet()) {
            if (!tgt.startsWith(prefix)) {
                continue;
            }
            String suffix = tgt.substring(prefix.length());
            if (!freqMap.containsKey(suffix)) {
                continue;
            }
            int prefixFreq = freqMap.get(prefix);
            int suffixFreq = freqMap.get(suffix);
            if (prefix.equals(suffix)) {
                cnt += (prefixFreq * (prefixFreq-1));
            } else {
                cnt += prefixFreq * suffixFreq;
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
