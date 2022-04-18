// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
// freq == 1, return -1
// freq == 2, return  1
// freq == 3, return  1 
// freq == 3k,     freq == 3*k,             return k
// freq == 3k + 1, freq == 3*(k-1) + 2 + 2, return k + 1
// freq == 3k + 2, freq == 3*k + 2,         return k + 1
// rnd = (freq + 2) / 3

// 35ms 60.00% 56.5MB 60.00%
// hash map
// O(N) O(N)
class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> lvl2cntMap = new HashMap<>();
        for (int lvl : tasks) {
            lvl2cntMap.put(lvl, lvl2cntMap.getOrDefault(lvl, 0) + 1);            
        }
        int rnd = 0;
        for (int cnt : lvl2cntMap.values()) {
            if (cnt == 1) {
                return -1;
            }
            rnd += (cnt + 2) / 3;
        }
        return rnd;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
