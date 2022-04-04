// Copyright (C) 2022 by iamslash

import java.util.*;

// damage: 2 7 4 3
//         17

// 2ms 97.31% 77.4MB 56.99%
// brute force
// O(N) O(1)
class Solution {
    public long minimumHealth(int[] damage, int armor) {
        long hp = 1, maxCost = 0;
        for (int cost : damage) {
            hp += cost;
            maxCost = Math.max(maxCost, cost);
        }
        // System.out.println(hp);
        return hp - maxCost + Math.max(0, maxCost - armor);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
