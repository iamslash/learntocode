// Copyright (C) 2021 by iamslash

import java.util.*;

//          i
// tickets: 2 3 2
//          1 2 1 3
// 

//       k: 1
//          i
// tickets: 5 1 3 1     
//          4 0 2 0     
//          2 0 0 0     

// brute force
// O(N) O(1)
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int sec = 0;
        for (int i = 0; i < tickets.length; ++i) {
            sec += Math.min(tickets[i], tickets[k]);
        }
        return sec;        
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
