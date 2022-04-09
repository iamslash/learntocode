// Copyright (C) 2022 by iamslash

import java.util.*;

// Wrong Answer for:
// 0
// 1

// Time Limit Exceeded
// 11
// 248
// BFS
// O(8^N) O(8^N) 
class Solution {
    public int minKnightMoves(int ex, int ey) {
        int step = 0;
        ex = Math.abs(ex);
        ey = Math.abs(ey);
        int[][] dirs = new int[][]{{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        Set<String> visit = new HashSet<>();
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, 0});
        visit.add("0,0");
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int[] item = q.poll();
                int x = item[0], y = item[1];
                if (x == ex && y == ey) {
                    return step;
                }
                for (int[] dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    int[] pos = new int[]{nx, ny};
                    String posStr = String.format("%d,%d", nx, ny);
                    if (!visit.contains(posStr) && ex >= -1 && ey >= -1) {
                        q.add(pos);
                        visit.add(posStr);
                    }
                }
            }
            step++;
        }
        return -1;
    }
}

public class MainApp {
  public static void main(String[] args) {
      {
          Set<int[]> visit = new HashSet<>();
          visit.add(new int[]{0, 1});
          System.out.println(visit.contains(new int[]{0, 0}));
          System.out.println(visit.contains(new int[]{0, 1}));
      }
      {
          Set<String> visit = new HashSet<>();
          visit.add("0,1");
          System.out.println(visit.contains("0,0"));
          System.out.println(visit.contains("0,1"));
      }
  }
}
