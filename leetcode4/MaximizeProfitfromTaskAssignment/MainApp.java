// Copyright (C) 2025 by iamslash

import java.util.*;

// works: 1 2 3 4 5
// tasks: 1,100 2,400 3,100 3,400
//            i

// works: 10 10000 1000000000
// tasks: 1,100 
//            i

// 78ms 42.86% 98.95MB 38.09%
// hash map, priority queue
// O(NlgN) O(N)
class Solution {
    public long maxProfit(int[] workers, int[][] tasks) {
        Map<Integer, PriorityQueue<Integer>> lvProfitMap = new HashMap<>();

        for (int[] task : tasks) {
            lvProfitMap.putIfAbsent(task[0], new PriorityQueue<>((a, b) -> b - a));
            lvProfitMap.get(task[0]).offer(task[1]);
        }

        long ans = 0;
        for (int lv : workers) {
            if (!lvProfitMap.containsKey(lv)) {
                continue;
            }
            ans += lvProfitMap.get(lv).poll();
            if (lvProfitMap.get(lv).size() == 0) {
                lvProfitMap.remove(lv);
            }
        }

        // Add additional worker's profit
        if (lvProfitMap.size() > 0) {
            int maxProfit = 0;

            for (int lv : lvProfitMap.keySet()) {
                maxProfit = Math.max(maxProfit, lvProfitMap.get(lv).peek());
            }

            ans += maxProfit;
        }

        return ans;
    }
}
