// Copyright (C) 2022 by iamslash

import java.util.*;

// 1805ms 13.38% 210.4MB 18.47%
// BFS
// O(8^N) O(8^N) 
class Solution {
    private final int[][] dirs = new int[][]{{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    public int minKnightMoves(int ex, int ey) {
        ex = Math.abs(ex);
        ey = Math.abs(ey);
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, 0});
        Set<String> visit = new HashSet<>();
        visit.add("0,0");
        int step = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int[] item = q.poll();
                int x = item[0], int y = item[1];
                if (x == ex && y == ey) {
                    return step;
                }
                for (int[] dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (!visit.contains(nx + "," + ny) && nx >= -1 && ny >= -1) {
                        q.offer(new int[]{nx, ny});
                        visit.add(nx + "," + ny);
                    }
                }
            }
            step++;
        }
        return -1;
    }
}

// 926ms 37.57% 52.2MB 73.45%
// DFS
// O(N) O(N)
class Solution {
    private final int[][] dirs = new int[][] {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};    
    public int minKnightMoves(int ex, int ey) {
        ex = Math.abs(ex);
        ey = Math.abs(ey);
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {0, 0});        
        Set<String> visit = new HashSet<>();
        visit.add("0,0");        
        int step = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] cur = q.remove();
                int x = cur[0];
                int y = cur[1];
                if (x == ex && y == ey) {
                    return step;
                }               
                for (int[] dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (!visit.contains(nx + "," + ny) && nx >= -1 && ny >= -1) {
                        q.add(new int[] {nx, ny});
                        visit.add(nx + "," + ny);
                    }
                }
            }
            step++;
        }
        return -1;
    }
}

// 13ms 98.43% 44.4MB 95.28%
// DFS
// O(N) O(N)
class Solution {
    private int dfs(Map<Pair, Integer> C, int ex, int ey) {
        ex = Math.abs(ex);
        ey = Math.abs(ey);
        if (ex + ey == 0) {
            return 0;
        }
        if (ex + ey == 2) {
            return 2;
        }
        Pair key = new Pair(ex, ey);
        if (C.containsKey(key)) {
            return C.get(key);
        }
        int minStep = 1 + Math.min(dfs(C, ex-1, ey-2), dfs(C, ex-2, ey-1));
        C.put(key, minStep);
        return minStep;
    }
    public int minKnightMoves(int ex, int ey) {
        Map<Pair, Integer> C = new HashMap<>();
        ex = Math.abs(ex);
        ey = Math.abs(ey);
        return dfs(C, ex, ey);
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
