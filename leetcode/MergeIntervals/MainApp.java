// Copyright (C) 2021 by iamslash

import java.util.*;

//                       i
// intervals: [[1,4],[4,5]]
//       ans: [[1,4]

// 6ms 64.61% 41.5MB 87.12%
// sort
// O(NlgN) O(N)
class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        for (int[] interval : intervals) {
            int[] lastInterval = null;
            if (ans.size() > 0) {
                lastInterval = ans.get(ans.size()-1);
            }
            if (lastInterval == null || (lastInterval[1] < interval[0])) {
                ans.add(interval);
            } else {
                lastInterval[1] = Math.max(lastInterval[1], interval[1]);
            }
        }
        return ans.toArray(new int[0][]);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
