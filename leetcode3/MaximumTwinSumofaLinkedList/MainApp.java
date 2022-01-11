// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
// 26ms 45.58% 123.2MB 63.70%
// list
// O(N) O(N)
class Solution {
    public int pairSum(ListNode head) {
        List<Integer> numList = new ArrayList<>();
        ListNode u = head;
        while (u != null) {
            numList.add(u.val);
            u = u.next;
        }
        int n = numList.size(), maxTwin = 0;
        for (int i = 0; i < (n/2); ++i) {
            maxTwin = Math.max(maxTwin, numList.get(i) + numList.get(n-1-i));
        }
        return maxTwin;
    }
}

// Did not use List<>
// 8ms 86.72% 124.9MB 35.75%
// list
// O(N) O(N)
class Solution {
    public int pairSum(ListNode head) {
        int half = 0;
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            half++;
        }
        int[] nums = new int[half];
        fast = head;
        int idx = 0;
        while (slow != null) {
            nums[idx++] += fast.val;
            nums[--half] += slow.val;
            slow = slow.next;
            fast = fast.next;
        }
        int maxTwin = 0;
        for (int num : nums) {
            maxTwin = Math.max(maxTwin, num);
        }
        return maxTwin;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
