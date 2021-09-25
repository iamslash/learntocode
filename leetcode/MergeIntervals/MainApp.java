// Copyright (C) 2021 by iamslash

import java.util.*;

// // 6ms 64.61% 41.5MB 87.12%
// // sort
// // O(NlgN) O(N)
// class Solution {
//     public int[][] merge(int[][] intervals) {
//         List<int[]> ans = new ArrayList<>();
//         Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
//         for (int[] interval : intervals) {
//             int[] lastInterval = null;
//             if (ans.size() > 0) {
//                 lastInterval = ans.get(ans.size()-1);
//             }
//             if (lastInterval == null || (lastInterval[1] < interval[0])) {
//                 ans.add(interval);
//             } else {
//                 lastInterval[1] = Math.max(lastInterval[1], interval[1]);
//             }
//         }
//         return ans.toArray(new int[0][]);
//     }
// }

//                       i
// intervals: [[1,4],[4,5]]
// mergedSrc: [[1,4]

// 5ms 96.06% 41.4MB 87.12%
// sort
// O(NlgN) O(N)
class Solution {
    public int[][] merge(int[][] intervals) {
        int[][] mergedSrc = new int[intervals.length][2];
        int pos = 0;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        for (int[] interval : intervals) {
            if (pos == 0 || mergedSrc[pos-1][1] < interval[0]) {
                mergedSrc[pos][0] = interval[0];
                mergedSrc[pos][1] = interval[1];
                ++pos;
            } else {
                mergedSrc[pos-1][1] = Math.max(mergedSrc[pos-1][1], interval[1]);
            }
        }
        int[][] mergedDst = new int[pos][2];
        for (int i = 0; i < pos; ++i) {
            mergedDst[i][0] = mergedSrc[i][0];
            mergedDst[i][1] = mergedSrc[i][1];
        }
        return mergedDst;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
