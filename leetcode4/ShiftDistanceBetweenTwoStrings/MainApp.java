// Copyright (C) 2025 by iamslash

import java.util.*;


// Idea: prefix sum
// 
//    i
// s: leet
// t: code
//
// min(nextCost(a~b) + nextCost(l~z), prevCost(a~l) + prevCost(d~z))
// 

// 15ms 81.95% 46.07MB 18.05%
// prefix sum
// O(N) O(1)
class Solution {
    public long shiftDistance(String s, String t,
                              int[] nextCost, int[] previousCost) {
        int n = s.length();
        long[] nextPs = new long[27];
        long[] prevPs = new long[27];
        long cost = 0;
        
        for (int i = 0; i < 26; ++i) {
            nextPs[i + 1] = nextPs[i] + nextCost[i];
            prevPs[i + 1] = prevPs[i] + previousCost[i];
        }

        for (int i = 0; i < n; ++i) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);
            if (sChar == tChar) {
                continue;
            }
            int sPos = s.charAt(i) - 'a';
            int tPos = t.charAt(i) - 'a';
            long minCost = 0, forwardCost = 0, backwardCost = 0;

            if (sPos < tPos) {
                forwardCost = nextPs[tPos] - nextPs[sPos];
                backwardCost = prevPs[sPos + 1] + prevPs[26] - prevPs[tPos + 1];
            } else {
                forwardCost = nextPs[tPos] + nextPs[26] - nextPs[sPos];
                backwardCost = prevPs[sPos + 1] - prevPs[tPos + 1];
            }
            minCost = Math.min(forwardCost, backwardCost);
            // System.out.printf("%d, %d, %d\n", forwardCost, backwardCost, minCost);
            cost += minCost;            
        }

        return cost;                                     
    }
}
