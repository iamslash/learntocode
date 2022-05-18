// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: greedy
//
// There are 2 cases for minimum cost
// 0) min, sec
// 1) min-1, sec+60
// 
// ex)
//      startAt: 1
//     moveCost: 2
//     pushCost: 1
//   targetSecs: 600
//   10 min 00 sec    1 + 2 + 1 + 1 + 1 = 6
//    9 min 60 sec    2 + 1 + 2 + 1 + 2 + 1 = 9
// ex)
//      startAt: 0
//     moveCost: 1
//     pushCost: 2
//   targetSecs: 76
//    1 min 16 sec    1 + 2 + 2 + 1 + 2 = 8
//    0 min 76 sec    1 + 2 + 1 + 2 = 6

class Solution {
    public int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
