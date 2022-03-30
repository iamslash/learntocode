// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 3 8 20
//  sum: 31
// half: 15.5
//   pq: 20 8 3    31
//       10 8 3    21
//        8 5 3    16
//        5 4 3    12


// 363ms 41.86% 108.5MB 75.25%
// heap
// O(NlgN) O(N)
class Solution {
    public int halveArray(int[] nums) {
        int cnt = 0;
        Queue<Double> pq = new PriorityQueue<Double>((a, b) -> b.compareTo(a));
        double sum = 0.0, half = 0.0;
        for (int num : nums) {
            pq.offer((double)num);
            sum += num;
        }
        half = sum / 2.0;
        while (sum > half) {
            Double d = pq.poll() / 2.0;
            sum -= d;
            pq.offer(d);
            cnt++;
            // System.out.printf("cnt: %d, sum: %f\n", cnt, sum);
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
