// Copyright (C) 2022 by iamslash

import java.util.*;

// boxes: 1,1 2,1 1,1

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
        int i = 0, distinctPorts = 0;
        for (int j = 0; j < n; ++j) {
            maxWeight -= boxes[j][1];
            maxBoxes--;
            if (j > 0 && boxes[j-1][0] != boxes[j][0]) {
                distinctPorts++;
            }
            while (maxWeight < 0 || maxBoxes < 0 ||
                   (i < j && C[i] == C[i + 1])) {
                maxWeight += boxes[i++][1];
                maxBoxes++;
                if (boxes[i-1][0] != boxes[i][0]) {
                    distinctPorts--;
                }
            }
            C[i+1] = C[i] + distinctPorts + 2;
        }
        return C[n];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
