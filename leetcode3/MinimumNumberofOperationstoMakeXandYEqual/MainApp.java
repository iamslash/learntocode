// Copyright (C) 2024 by iamslash

import java.util.*;

// 14ms 40.47% 45.1MB 31.92%
// bfs
// O(N) O(N)
class Solution {
    public int minimumOperationsToMakeEqual(int x, int y) {
        Queue<Integer> bfsQue = new LinkedList<>();
        Set<Integer> seenSet = new HashSet<>();

        bfsQue.offer(x);
        seenSet.add(x);
        int ops = 0;

        while (!bfsQue.isEmpty()) {
            int size = bfsQue.size();
            while (size-- > 0) {
                int u = bfsQue.poll();
                if (u == y) {
                    return ops;
                }

                int[] vs = new int[]{u - 1, u + 1, u / 5, u / 11};
                for (int v : vs) {
                    if (v > 0 && !seenSet.contains(v)) {
                        if ((v == u / 5 && u % 5 == 0) ||
                            (v == u / 11 && u % 11 == 0) ||
                            (v == u - 1) ||
                            (v == u + 1)) {
                            bfsQue.offer(v);
                            seenSet.add(v);
                        }
                    }
                }
            }
            ops++;
        }

        return ops;
    }
}
