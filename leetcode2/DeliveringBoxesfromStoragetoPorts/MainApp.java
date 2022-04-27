// Copyright (C) 2022 by iamslash

import java.util.*;

// boxes: 1,1 2,1 1,1

// 11ms 82.08% 135.6MB 62.26%
// iterative dynamic programming, sliding window
// O(N) O(N)
public class Solution {
    public int boxDelivering(int[][] boxes,
                             int portsCount,
                             int maxBoxes,
                             int maxWeight) {
        int n = boxes.length;
        // C[i]: min trips from i-th box
        int[] C = new int[n+1];
        int weight = 0, cost = 2;
        for (int l = 0, r = 0; r < n; ++r) {
            weight += boxes[r][1];
            if (r > 0 && boxes[r-1][0] != boxes[r][0]) {
                cost++;
            }
            while (r - l >= maxBoxes || weight > maxWeight ||
                   (l < r && C[l] == C[l + 1])) {
                weight -= boxes[l][1];
                if (boxes[l][0] != boxes[l+1][0]) {
                    cost--;
                }
                l++;
            }
            C[r+1] = C[l] + cost;
        }
        return C[n];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
