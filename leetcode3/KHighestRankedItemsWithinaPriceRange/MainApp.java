// Copyright (C) 2022 by iamslash

import java.util.*;

// bfs, priority queue
// O(HW) O(NlgN)
class Solution {
    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing,
                                                   int[] start, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        int h = grid.length, w = grid[0].length;
        int lo = start[0], hi = start[1];
        // [dist, price, y, x]
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> {
                                              if (a[0] == b[0]) {
                                                  if (a[1] == b[1]) {
                                                      if (a[2] == b[2]) {
                                                          return a[3] - b[3];
                                                      }
                                                      return a[2] - b[2];
                                                  }
                                                  return a[1] - b[1];
                                              }
                                              return a[0] - b[0];
        });
        // [dist, price, y, x]
        Queue<int[]> q = new ArrayDeque<>();
        q.add(start);
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int[] item = q.poll();
                if (lo <= price && price <= hi) {
                    pq.add(item);
                }
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
