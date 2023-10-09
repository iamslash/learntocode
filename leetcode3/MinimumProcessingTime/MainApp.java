// Copyright (C) 2023 by iamslash

import java.util.*;


// procTime: 8 10
//    tasks: 2 2 3 1 8 7 4 5
//           8       10
//           1 2 2 3 4 5 7 8

// 76ms 33.33% 59.2MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int minProcessingTime(List<Integer> processorTime, List<Integer> tasks) {
        Collections.sort(processorTime);
        Collections.sort(tasks, Collections.reverseOrder());
        int maxTime = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            int availTime = processorTime.get(i / 4);
            int taskTime = tasks.get(i);
            maxTime = Math.max(maxTime, availTime + taskTime);
        }
        return maxTime;        
    }
}
