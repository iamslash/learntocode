// Copyright (C) 2022 by iamslash

import java.util.*;

// 82ms 76.64% 54.7MB 13.43%z
// priority queue
// O(NlgN) O(N)
class Solution {
    public int connectSticks(int[] sticks) {
        Queue<Integer> pq = new PriorityQueue<>();
        for (int len : sticks) {
            pq.offer(len);
        }
        int ans = 0;
        while (pq.size() > 1) {
            int sum = pq.poll() + pq.poll();
            pq.offer(sum);
            ans += sum;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
