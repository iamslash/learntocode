// Copyright (C) 2025 by iamslash

import java.util.*;


// moveTime:
// 0 4
// 4 4

// moveTime:
// 0 0 0 0
// 0 0 0 0

// moveTime:
// 0 1
// 1 2

// 777ms 10.82% 133.75MB 10.08%
// priority queue, hash set
// O(N) O(N)
class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int h = moveTime.length, w = moveTime[0].length;
        int[] dirs = new int[]{-1, 0, 1, 0, -1};

        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, 1, 0, 0});

        Set<String> seen = new HashSet<>();
        seen.add("0,0");

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int ts = top[0], step = top[1];
            int y = top[2], x = top[3];

            if (y == h - 1 && x == w - 1) {
                return ts;
            }

            for (int i = 0; i < 4; ++i) {
                int ny = y + dirs[i], nx = x + dirs[i + 1];
                String pos = ny + "," + nx;

                if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
                    seen.contains(pos)) {
                    continue;
                }

                int nts = Math.max(ts, moveTime[ny][nx]) + step;
                int nstep = 3 - step; // nstep is 1 or 2
                pq.offer(new int[]{nts, nstep, ny, nx});
                seen.add(pos);
            }
        }

        return -1;
    }
}

// 34ms 99.63% 96.49MB 97.39%
// priority queue
// O(N) O(N)
class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int h = moveTime.length, w = moveTime[0].length;
        int[] dirs = new int[]{-1, 0, 1, 0, -1};

        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, 1, 0, 0}); // ts, step, y, x

        moveTime[0][0] = -1;

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int ts = top[0], step = top[1];
            int y = top[2], x = top[3];

            for (int i = 0; i < 4; ++i) {
                int ny = y + dirs[i], nx = x + dirs[i + 1];

                if (ny < 0 || ny >= h || nx < 0 || nx >= w || 
                    moveTime[ny][nx] < 0) {
                    continue;
                }

                int nts = Math.max(ts, moveTime[ny][nx]) + step;
                
                if (ny == h - 1 && nx == w - 1) {
                    return nts;
                }

                int nstep = 3 - step; // nstep is 1 or 2
                pq.offer(new int[]{nts, nstep, ny, nx});
                moveTime[ny][nx] = -1; // visit
            }
        }

        return -1;
    }
}


