// Copyright (C) 2022 by iamslash

import java.util.*;

// 82ms 76.64% 54.7MB 13.43%z
// priority queue
// O(N^2lgN) O(N)
class Solution {
    public int connectSticks(int[] sticks) {
        Queue<Integer> pq = new PriorityQueue<>();
        for (int len : sticks) {
            pq.offer(len);
        }
        int sum = 0;
        while (pq.size() > 1) {
            int a = pq.poll();
            int b = pq.poll();
            // System.out.printf("a: %d, b: %d\n", a, b);
            sum += a + b;
            pq.offer(a + b);
        }
        return sum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
