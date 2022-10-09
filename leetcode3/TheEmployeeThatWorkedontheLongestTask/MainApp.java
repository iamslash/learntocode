// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 42.5MB 87.50%
// hash map
// O(N) O(N)
class Solution {
    public int hardestWorker(int n, int[][] logs) {
        int[] works = new int[n];
        int started = 0;
        for (int[] log : logs) {
            // System.out.printf("worker: %d, ended: %d, started: %d\n", log[0], log[1], started);
            int worker = log[0], unit = log[1] - started;
            works[worker] = Math.max(works[worker], unit);
            started = log[1];
        }
        int bestWorker = 0, bestUnit = 0;
        for (int i = 0; i < works.length; ++i) {
            if (bestUnit < works[i]) {
                bestWorker = i;
                bestUnit = works[i];
            }
        }
        return bestWorker;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
