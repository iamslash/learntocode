// Copyright (C) 2022 by iamslash

import java.util.*;

// Wrong Answer for:
// 0
// 1

// BFS
// O(8^N) O(8^N) 
class Solution {
    public int minKnightMoves(int ex, int ey) {
        int step = 0;
        int[][] dirs = new int[][]{{1,2}, {2,1}, {2,-1}, {1,-1}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}};
        Set<int[]> visit = new HashSet<>();
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, 0});
        visit.add(new int[]{0, 0});
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
                    if (!visit.contains(pos) &&
                        ((ex * nx) >= 0 && (ey * ny) >= 0) || step < 3) {
                        q.add(pos);
                        visit.add(pos);
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
  }
}
