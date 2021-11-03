// Copyright (C) 2021 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 4ms 100.00% 61.1MB 85.01%
// linked list
// O(N) O(1)
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int firstIdx = 0, lastIdx = 0, lastVal = head.val;
        int minDist = Integer.MAX_VALUE;
        for (int i = 0; head.next != null; ++i) {
            if ((lastVal < head.val && head.val > head.next.val) ||
                (lastVal > head.val && head.val < head.next.val)) {
                if (lastIdx != 0) {
                    minDist = Math.min(minDist, i - lastIdx);
                }
                lastIdx = i;
                if (firstIdx == 0) {
                    firstIdx = i;
                }
            }
            lastVal = head.val;
            head = head.next;
        }
        if (minDist == Integer.MAX_VALUE) {
            return new int[]{-1, -1};
        }
        return new int[]{minDist, lastIdx - firstIdx};
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
