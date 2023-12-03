// Copyright (C) 2023 by iamslash

import java.util.*;

// intervals: 5,10 6,8 1,5 2,3 1,10
//                                 i
//            1,5 1,10 2,3, 5,10 6,8
//        pq: 8 10 10 

// 92ms 49.37% 76.4MB 60.13%
// sort, heap
// O(NlgN) O(N)
class Solution {
    public int minGroups(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        Queue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            int beg = intervals[i][0], end = intervals[i][1];
            if (!pq.isEmpty() && pq.peek() < beg) {
                pq.poll();
            }
            pq.offer(end);
        }
        return pq.size();
    }
}
