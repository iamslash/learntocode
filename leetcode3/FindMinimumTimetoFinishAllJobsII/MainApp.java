// Copyright (C) 2022 by iamslash

import java.util.*;

//    jobs: 2 4 5
// workers: 1 5 7

//    jobs: 3 9 15 18
// workers: 1 3  5  6

// 37ms 100.00% 59.8MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int minimumTime(int[] jobs, int[] workers) {
        Arrays.sort(jobs);
        Arrays.sort(workers);
        int maxDay = 0, n = jobs.length;
        for (int i = 0; i < n; ++i) {
            int quo = (jobs[i] + workers[i] - 1) / workers[i];
            maxDay = Math.max(maxDay, quo);
        }
        return maxDay;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
