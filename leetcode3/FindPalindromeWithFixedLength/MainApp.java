// Copyright (C) 2022 by iamslash

import java.util.*;

// intLength: 3
//   queries: 1 2 3 4 5 90
// 

class Solution {
    public long[] kthPalindrome(int[] queries, int n) {
        long[] ans = new long[queries.length];
        int half = (n + 1) / 2;
        long beg = (long)Math.pow(10, half - 1);
        long end = (long)Math.pow(10, half) - 1;
        long total = end - beg + 1;
        for (int i = 0; i < queries.length; ++i) {
            if (queries[i] <= total) {
            } else {
            }
        }
        return ans;
    }
}
        
         
public class MainApp {
  public static void main(String[] args) {
  }
}
