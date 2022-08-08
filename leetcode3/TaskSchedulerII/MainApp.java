// Copyright (C) 2022 by iamslash

import java.util.*;

// Caution:
// space means days we should pass when we do the same task.

// 89ms 22.22% 135.4MB 11.11%
// hash map
// O(N) O(N)
class Solution {
    public long taskSchedulerII(int[] tasks, int space) {
        // { task type : last executed at } 
        Map<Integer, Long> lastExMap = new HashMap<>();
        long minDays = 0;
        for (int task : tasks) {
            if (lastExMap.containsKey(task)) {
                minDays = Math.max(lastExMap.get(task) + space, minDays);    
            } 
            lastExMap.put(task, ++minDays);
        }
        return minDays;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
