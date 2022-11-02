// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 97.23% 60.2MB 95.11%
// hash map
// O(N) O(N)
class Solution {
    public int edgeScore(int[] edges) {
        int n = edges.length;
        long[] inputs = new long[n];
        for (int u = 0; u < n; ++u) {
            int v = edges[u];
            inputs[v] += u;
        }
        // System.out.printf("inputs[0]: %d, inputs[1]: %d\n", inputs[0], inputs[1]);
        long maxInput = -1;
        int maxNode = 0;
        for (int u = 0; u < n; ++u) {
            if (inputs[u] > maxInput) {
                maxInput = inputs[u];
                maxNode = u;
            }
        }
        return maxNode;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
