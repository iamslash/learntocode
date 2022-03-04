// Copyright (C) 2022 by iamslash

import java.util.*;

// 0 5 10 15 20 30 
// + +  -  +  -  -

// 1 13 13 15
// +  -  +

// 11ms 54.30% 46MB 7.25%
// sort
// O(NlgN) O(N)
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        List<int[]> eventList = new ArrayList<>();
        for (int[] interval : intervals) {
            eventList.add(new int[]{interval[0], 1});
            eventList.add(new int[]{interval[1], -1});
        }
        Collections.sort(eventList, (a, b) -> {
                if (a[0] == b[0]) {
                    return a[1] - b[1];
                }
                return a[0] - b[0];
            });
        int maxCnt = 0, cnt = 0;
        for (int[] event : eventList) {
            cnt += event[1];
            maxCnt = Math.max(maxCnt, cnt);
        }
        return maxCnt;
    }
}

// intervals: [[0,30],[5,10],[15,20]]
//                     i
//      begs:  0  5 15
//      ends: 10 20 30
//                j

// 2ms 99.38% 41.9MB 83.07%
// two pointers, sort
// O(NlgN) O(N)
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        int[] begs = new int[n];
        int[] ends = new int[n];
        for (int i = 0; i < n; ++i) {
            begs[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        Arrays.sort(begs);
        Arrays.sort(ends);
        int maxCnt = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (begs[i] < ends[j]) {
                maxCnt++;
            } else {
                j++;
            }
        }
        return maxCnt;
    }
}
