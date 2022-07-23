// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 42.4MB 23.08%
// hash map
// O(N) O(N)
class Solution {
    public String bestHand(int[] ranks, char[] suits) {
        int[] rankCnts = new int[14];
        int[] suitCnts = new int[4]; 
        for (int i = 0; i < 5; ++i) {
            rankCnts[ranks[i]]++; 
            suitCnts[suits[i] - 'a']++;
        }
        int maxRankCnt = 0, maxSuitCnt = 0;
        for (int i = 0; i < 14; ++i) {
            maxRankCnt = Math.max(maxRankCnt, rankCnts[i]);
        }
        for (int i = 0; i < 4; ++i) {
            maxSuitCnt = Math.max(maxSuitCnt, suitCnts[i]);
        }
        if (maxSuitCnt == 5) {
            return "Flush";
        }
        if (maxRankCnt >= 3) {
            return "Three of a Kind";
        }
        if (maxRankCnt == 2) {
            return "Pair";
        }
        return "High Card";
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
