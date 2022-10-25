// Copyright (C) 2022 by iamslash

import java.util.*;

//               i
//  players: 4 7 9
// trainers: 2 5 8 8
//                   j

// 32ms 87.47% 86.7MB 32.93%
// sort, two pointers
// O(NlgN) O(1)
class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int i = 0, m = players.length, n = trainers.length;
        for (int j = 0; i < m && j < n; ++j) {
            if (players[i] <= trainers[j]) {
                i++;
            }
        }
        return i;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
