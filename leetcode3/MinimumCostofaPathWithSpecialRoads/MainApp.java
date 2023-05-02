// Copyright (C) 2023 by iamslash

import java.util.*;

// .       e
// .     @ 
// .     !
// . !
// . s
// . . . . .
// 


// dijkstra
// O(NlgN) O(N)
class Solution {
    public int minimumCost(int[] start, int[] target, int[][] specialRoads) {
        Map<Integer, HashSet<Integer>> visit = new HashMap<>();
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        int ex = target[0], ey = target[1];
        pq.add(new int[]{start[0], start[1], 0});
        while (pq.size() > 0) {
            int[] top = pq.poll();
            int tx = top[0], ty = top[1], tc = top[2];
            if (visit.containsKey(tx) && visit.get(tx).contains(ty)) {
                continue;
            }
            visit.putIfAbsent(tx, new HashSet<>());
            visit.get(tx).add(ty);
            if (tx == ex && ty == ey) {
                return tc;
            }
            // Add edge from x,y to ex, ey
            pq.offer(new int[]{ex, ey, tc + Math.abs(tx - ex) + Math.abs(ty - ey)});
            // Add special edges
            for (int i = 0; i < specialRoads.length; ++i) {
                int x1 = specialRoads[i][0], y1 = specialRoads[i][1];
                int x2 = specialRoads[i][2], y2 = specialRoads[i][3];
                int cc = specialRoads[i][4];
                if (visit.containsKey(x2) && visit.get(x2).contains(y2)) {
                    continue;
                }
                pq.offer(new int[]{x2, y2, tc + cc + Math.abs(tx - x1) + Math.abs(ty - y1)});
            }
        }
        return -1;
    }
}

