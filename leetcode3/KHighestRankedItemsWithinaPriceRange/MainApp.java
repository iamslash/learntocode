// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
// BFS with pq not q

// 148ms 58.23% 74.4MB 83.29%
// bfs, priority queue
// O(HW) O(NlgN)
class Solution {
    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing,
                                                   int[] start, int k) {
        int[] dirs = new int[]{-1, 0, 1, 0, -1};
        List<List<Integer>> ans = new ArrayList<>();
        int h = grid.length, w = grid[0].length;
        int lo = pricing[0], hi = pricing[1];
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
        pq.add(new int[]{0, grid[start[0]][start[1]], start[0], start[1]});
        grid[start[0]][start[1]] = 0;
        while (!pq.isEmpty() && ans.size() < k) {
            int[] item = pq.poll();
            // System.out.printf("lo: %d, hi: %d, price: %d, y: %d, x: %d\n", lo, hi, item[1], item[2], item[3]);
            if (item[1] != 1 && lo <= item[1] && item[1] <= hi) {
                ans.add(Arrays.asList(item[2], item[3]));
            }
            for (int i = 0; i < 4; ++i) {
                int ny = item[2] + dirs[i];
                int nx = item[3] + dirs[i+1];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w || grid[ny][nx] == 0) {
                    continue;
                }
                pq.offer(new int[]{item[0] + 1, grid[ny][nx], ny, nx});
                grid[ny][nx] = 0;
            }
        }
        return ans;
    }
}

// 1 0 1
// 3 5 2
// 1 0 1

public class MainApp {
  public static void main(String[] args) {
  }
}
