// Copyright (C) 2022 by iamslash

import java.util.*;


//            l
// costs: 1 2 3
//          r

// 116ms 67.74% 52.3MB 97.22%
// min heap
// O(NlgN) O(N)
class Solution {
    public long totalCost(int[] costs, int k, int cand) {
        Queue<Integer> pq = new PriorityQueue<>((i, j) -> costs[i] == costs[j] ? i - j : costs[i] - costs[j]);
        int n = costs.length, left = 0, right = n-1;
        long ans = 0;
        for (int i = 0; i < cand && left <= right; ++i) {
            pq.offer(left++);
            if (left <= right) {
                pq.offer(right--);
            }
        }        
        while (k-- > 0) {
            int pos = pq.poll();
            if (left <= right) {
                if (pos <= left) {
                    pq.offer(left++);
                } else {
                    pq.offer(right--);
                }
            }
            ans += costs[pos];            
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
