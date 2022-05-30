// Copyright (C) 2022 by iamslash

import java.util.*;

//          
// heights: 3 1 4 2 5
//        j
//     deq: 4 5
//     ans: 2 1 2 1 0

//          i
// heights: 5 1 
//            j  
//          3 1
//          4 1
//     deq:

// 30ms 91.78% 66MB 91.78%
// mono stack
// O(HW) O(HW)
class Solution {
    private void fill(int[][] heights, int[][] ans,
                      int y, int x, int dy, int dx) {
        Deque<Integer> deq = new ArrayDeque<>();
        for (int i = y, j = x; i >= 0 && j >= 0; i += dy, j += dx) {
            while (deq.size() > 0 && deq.peekFirst() < heights[i][j]) {
                deq.removeFirst();
                ans[i][j]++;
            }
            ans[i][j] += deq.size() > 0 ? 1 : 0;
            if (deq.size() > 0 && deq.peekFirst() == heights[i][j]) {
                continue;
            }
            deq.addFirst(heights[i][j]);
        }
    }
    public int[][] seePeople(int[][] heights) {
        int h = heights.length, w = heights[0].length;
        int[][] ans = new int[h][w];
        for (int y = 0; y < h; ++y) {
            fill(heights, ans, y, w-1, 0, -1);
        }
        for (int x = 0; x < w; ++x) {
            fill(heights, ans, h-1, x, -1, 0);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
