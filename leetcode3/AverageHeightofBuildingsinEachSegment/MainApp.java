// Copyright (C) 2021 by iamslash

import java.util.*;

//                
// buildings:
//                               i
//        pq: 1,2 3,4 5,-2 10,-4
//       ans: 1,3,2 3,5,3 5,10,4
//     start: 10
//       sum: 0
//       cnt: 0              

// 86ms 78.72% 93.6MB 97.87%
// priority queue
// O(NlgN) O(N)
class Solution {
    public int[][] averageHeightOfBuildings(int[][] buildings) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int[] bldg : buildings) {
            pq.offer(new int[]{bldg[0], bldg[2]});
            pq.offer(new int[]{bldg[1], -bldg[2]});			
        }
        Deque<int[]> ans = new ArrayDeque<>();
        int start = 0, sum = 0, cnt = 0;
        while (!pq.isEmpty()) {
            int[] evt = pq.poll();
            if (cnt != 0 && evt[0] != start) {
                int avgh = sum / cnt;
                // merge continued segment with same avgh
                // add new one
                if (!ans.isEmpty() &&
                    ans.peekLast()[1] == start &&
                    ans.peekLast()[2] == avgh) {
                    ans.peekLast()[1] = evt[0];
                    ans.peekLast()[2] = avgh;
                } else {
                    ans.offerLast(new int[]{start, evt[0], avgh});
                }
            }
            start = evt[0];
            sum += evt[1];
            cnt += evt[1] > 0 ? 1 : -1;
        }
        return ans.toArray(new int[0][]);		
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
