// Copyright (C) 2021 by iamslash

import java.util.*;

// back tracking, sort
class Solution {
    private int cand;
    private List<Integer> ans;
    private Set<Integer> visitSet = new HashSet<>();

    private void dfs(int[] digits, int pos) {
    }
    public int[] findEvenNumbers(int[] digits) {
        Arrays.sort(digits);
        return ans.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
