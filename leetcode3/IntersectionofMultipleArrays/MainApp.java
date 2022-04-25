// Copyright (C) 2022 by iamslash

import java.util.*;

// hash map
// O(N) O(N)
class Solution {
    public List<Integer> intersection(int[][] numss) {
        int n = numss.length;
        int[] cnts = new int[1001];
        for (int[] nums : numss) {
            for (int num : nums) {
                cnts[num]++;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int num = 1; num < 1001; ++num) {
            if (cnts[num] == n) {
                ans.add(num);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
