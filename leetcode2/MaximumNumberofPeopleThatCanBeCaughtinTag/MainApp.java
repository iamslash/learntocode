// Copyright (C) 2021 by iamslash

import java.util.*;

// dist: 3
//               i
// team: 1 0 0 1 0 1
//             j

// 9ms 64.95% 88.6MB 37.11%
// two pointers
// O(N) O(1)
class Solution {
    public int catchMaximumAmountofPeople(int[] team, int dist) {
        int n = team.length, cnt = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (team[i] == 0) {
                continue;
            }
            while (j < i - dist) {
                ++j;
            }
            while (j < n && j < i+dist && team[j] == 1) {
                ++j;
            }
            if (j < n && team[j] == 0) {
                ++cnt;
                ++j;
            }
        }
        return cnt;
        
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
