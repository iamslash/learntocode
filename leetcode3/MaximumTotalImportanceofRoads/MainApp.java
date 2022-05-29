// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: sort
//
// gather node degrees (in, out)
// sort them
// allocate num

// 7ms 100.00% 64.5MB 100.00%
// sort
// O(NlgN) O(N)
class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long[] degrees = new long[n];
        long sum = 0;
        for (int[] road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }
        Arrays.sort(degrees);
        for (int i = 0; i < n; ++i) {
            sum += degrees[i] * (i + 1);
        }
        return sum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
