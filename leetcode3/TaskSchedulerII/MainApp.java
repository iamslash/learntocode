// Copyright (C) 2023 by iamslash

import java.util.*;

// space: 3
// tasks: 1 2 1 2 3 1
//                    i
//   map: 1 2 3
//        9 2 7
//    ts: 9
// 

// 45ms 62.18% 57.2MB 47.90%
// hash map
// O(N) O(N)
class Solution {
    public long taskSchedulerII(int[] tasks, int space) {
        Map<Integer, Long> taskTsMap = new HashMap<>();
        long ts = 0;
        for (int i = 0; i < tasks.length; ++i, ++ts) {
            if (taskTsMap.containsKey(tasks[i])) {
                long gap = ts - taskTsMap.get(tasks[i]) - 1;
                if (gap < space) {
                    ts += (space - gap);
                }
            }
            taskTsMap.put(tasks[i], ts);
        }
        return ts;
    }
}
