// Copyright (C) 2021 by iamslash

import java.util.*;

//  target: 7777
//    nums: 777 7 77 77
// freqMap: 7 77 777
//          1  2   3

class Solution {
    public int numOfPairs(String[] nums, String tgt) {
        Map<String, Integer> freqMap = new HashMap<>();
        int cnt = 0;
        for (String s : nums) {
            freqMap.putIfAbsent(s, 0);
            freqMap.put(s, freqMap.get(s) + 1);
        }
        for (String prefix : nums) {
            if (!tgt.startsWith(prefix)) {
                continue;
            }
            if (prefix.length() * 2 == nums) {
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
