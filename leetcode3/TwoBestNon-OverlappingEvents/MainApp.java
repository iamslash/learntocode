// Copyright (C) 2022 by iamslash

import java.util.*;

// events: 1,3,2 4,5,2 2,4,3 6,7,2
//         1,3,2 2,4,3 4,5,2 6,7,2
//                               i
//     pq:   7,2
// maxVal:     2     3     4     5 

// 35ms 96.62% 88.1MB 94.59%
// sort, heap
// O(NlgN) O(N)
class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length;
        Arrays.sort(events, (a, b) -> {
                if (a[0] == b[0]) {
                    return a[1] - b[1];
                }
                return a[0] - b[0];
            });
        // [endTime, value]
        Queue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        int maxPastVal = 0, ans = 0;
        for (int[] evt : events) {
            while (!pq.isEmpty()) {
                if (pq.peek()[0] >= evt[0]) {
                    break;
                }
                int[] pastEvt = pq.poll();
                maxPastVal = Math.max(maxPastVal, pastEvt[1]);
            }
            ans = Math.max(ans, evt[2] + maxPastVal);
            pq.offer(new int[]{evt[1], evt[2]});
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
