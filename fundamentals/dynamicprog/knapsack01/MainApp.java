// Copyright (C) 2023 by iamslash

import java.util.*;

// recursive dynamic programming
// O(CN) O(C)
class RecursiveSolution {
    private int dfs(int[] values, int[] weights, int[] C, int avail) {
        int n = values.length;
        // base
        if (avail <= 0) {
            return 0;
        }
        // memo
        if (C[avail] >= 0) {
            return C[avail];
        }
        // recursion
        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            if (weights[i] <= avail) {
                maxVal = Math.max(maxVal,
                                  values[i] +
                                  dfs(values, weights, C, avail - weights[i]));
            }
        }
        return C[avail] = maxVal;
    }
    public int solve(int[] values, int[] weights, int capacity) {
        int n = values.length;
        int[] C = new int[capacity + 1];
        Arrays.fill(C, -1);
        return dfs(values, weights, C, capacity);
    }
}

// iterative dynamic programming
// O(CN) O(C)
class IterativeSolution {
    public int solve(int[] values, int[] weights, int capacity) {
        int n = values.length;
        int[] C = new int[capacity + 1];
        Arrays.fill(C, 0);
        for (int w = 0; w <= capacity; ++w) {
            for (int i = 0; i < n; ++i) {
                if (weights[i] <= w) {
                    C[w] = Math.max(C[w], values[i] + C[w - weights[i]]);
                }
            }
        }
        return C[capacity];
    }
}

public class MainApp {
  public static void main(String[] args) {
      int[] values = new int[]{10, 30, 20};
      int[] weights = new int[]{5, 10, 15};
      int capacity = 100;

      RecursiveSolution recurSln = new RecursiveSolution();
      System.out.println(recurSln.solve(values, weights, capacity)); // 300

      IterativeSolution iterSln = new IterativeSolution();
      System.out.println(iterSln.solve(values, weights, capacity));  // 300
  }
}
