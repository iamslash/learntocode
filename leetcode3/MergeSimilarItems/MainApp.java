// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 100.00% 54.8MB 50.00%
// hash map
// O(N) O(1)
class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        int[] val2weights = new int[1001];
        for (int i = 0; i < items1.length; ++i) {
            val2weights[items1[i][0]] += items1[i][1];
        }
        for (int i = 0; i < items2.length; ++i) {
            val2weights[items2[i][0]] += items2[i][1];
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 1; i <= 1000; ++i) {
            if (val2weights[i] > 0) {
                ans.add(Arrays.asList(i, val2weights[i]));
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
