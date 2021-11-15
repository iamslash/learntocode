// Copyright (C) 2021 by iamslash

import java.util.*;

//          i
// tickets: 2 3 2
//          1 2 1 3
// 

//       k: 1
//          i
// tickets: 5 1 3 1 
//          1 0 0 0     
//          4 1 3 1   


// i <= k, min(A[k], A[i])
// i  > k, min(A[k]-1, A[i])
// 0ms 100.00% 36.9MB 55.56%
// brute force
// O(N) O(1)
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int sec = 0;
        for (int i = 0; i < tickets.length; ++i) {
            if (i <= k) {
                sec += Math.min(tickets[k], tickets[i]);
            } else {
                sec += Math.min(tickets[k]-1, tickets[i]);
            }
        }
        return sec;        
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
