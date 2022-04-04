// Copyright (C) 2022 by iamslash

import java.util.*;

// 380ms 33.33% 153.5MB 66.67%
// hash set, hash map
// O(NlgN) O(N)
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Set<Integer> winnerSet = new TreeSet<>();
        Map<Integer, Integer> loser2cntMap = new TreeMap<>();
        for (int[] match : matches) {
            winnerSet.add(match[0]);
            loser2cntMap.put(match[1], loser2cntMap.getOrDefault(match[1], 0) + 1);
        }
        List<List<Integer>> ans = Arrays.asList(new ArrayList<>(), new ArrayList<>());
        for (Integer winner : winnerSet) {
            if (!loser2cntMap.containsKey(winner)) {
                ans.get(0).add(winner);
            }
        }
        for (Integer loser : loser2cntMap.keySet()) {
            if (loser2cntMap.get(loser) == 1) {
                ans.get(1).add(loser);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
