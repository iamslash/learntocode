// Copyright (C) 2022 by iamslash

import java.util.*;

//                                i
// intervals: 1,5 1,10 2,3 5,10 6,8
// 
//        pq: 8 10 10

// 123ms 77.52% 86.5MB 94.30%
// sort, priority queue
// O(NlgN) O(N)
class Solution {
    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int n = intervals.length;
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);
        for (int i = 0; i < n; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            // System.out.printf("s: %d, e: %d\n", s, e);
            if (!pq.isEmpty() && pq.peek() < s) {
                pq.remove();
            }
            pq.offer(e);
        }
        return pq.size();
    }
}

