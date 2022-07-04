// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 21ms 23.02% 248MB 41.45%
// brute force
// O(HW) O(HW)
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] ans = new int[m][n];
        for (int y = 0; y < m; ++y) {
            Arrays.fill(ans[y], -1);
        }
        int y = 0, x = 0, i = 0;
        int[] dir = new int[]{0, 1, 0, -1, 0};
        while (head != null) {
            ans[y][x] = head.val;
            head = head.next;
            int ny = y + dir[i], nx = x + dir[i+1];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n ||
                ans[ny][nx] >= 0) {
                i++;
                i %= 4;
                ny = y + dir[i];
                nx = x + dir[i+1];
            }
            y = ny;
            x = nx;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
