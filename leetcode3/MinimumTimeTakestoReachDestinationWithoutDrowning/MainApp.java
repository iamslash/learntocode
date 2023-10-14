// Copyright (C) 2023 by iamslash

import java.util.*;

// D . * 
// . . .
// . S .
//
// D 1 0
// 3 2 1
// 4 S 2

// Idea: bfs, dijkstra
//
// "*": 0    flooded
// ".": -1   empty
// "S": -2   start
// "D": -3   end
// "X": -4   stone
//
// 73ms 44.30% 45.1MB 21.52%
// bfs, dijkstra
// O(N) O(N)
class Solution {
    public int minimumSeconds(List<List<String>> land) {
        int INF = (int)1e9;
        int[] dirs = {1, 0, -1, 0, 1};
        int h = land.size(), w = land.get(0).size();
        int[][] dist = new int[h][w];
        for (int i = 0; i < h; i++) {
            Arrays.fill(dist[i], INF);
        }
        Queue<int[]> q = new LinkedList<>();
        int[] start = new int[2], end = new int[2];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                String s = land.get(i).get(j);
                if (s.equals("*")) {
                    q.offer(new int[]{i, j});
                    dist[i][j] = 0;
                } else if (s.equals("S")) {
                    start = new int[]{i, j};
                } else if (s.equals("D")) {
                    end = new int[]{i, j};
                }
            }
        }
        // Update flooded dist[][].
        while (!q.isEmpty()) {
            int[] top = q.poll();
            int y = top[0], x = top[1];
            for (int i = 0; i < 4; i++) {
                int ny = y + dirs[i], nx = x + dirs[i + 1];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                    continue;
                }
                if (!land.get(ny).get(nx).equals(".")) {
                    continue;
                }
                if (dist[ny][nx] != INF) {
                    continue;
                }
                dist[ny][nx] = Math.min(dist[ny][nx], dist[y][x] + 1);
                q.offer(new int[]{ny, nx});
            }
        }
        // Traverse from start to end.
        q.clear();
        q.offer(start);
        boolean[][] visit = new boolean[h][w];
        visit[start[0]][start[1]] = true;
        int step = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int[] top = q.poll();
                int y = top[0], x = top[1];
                if (y == end[0] && x == end[1]) {
                    return step;
                }
                for (int i = 0; i < 4; i++) {
                    int ny = y + dirs[i], nx = x + dirs[i+1];
                    if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                        continue;
                    }
                    if (visit[ny][nx]) {
                        continue;
                    }
                    if (land.get(ny).get(nx).equals("X") || land.get(ny).get(nx).equals("*")) {
                        continue;
                    }
                    if (dist[ny][nx] <= step + 1) {
                        continue;
                    }
                    q.offer(new int[]{ny, nx});
                    visit[ny][nx] = true;
                }
            }
            step++;
        }
        return -1;
    }
}
