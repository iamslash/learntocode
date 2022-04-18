// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverse(ListNode h) {
        ListNode b = null;
        ListNode u = h;
        while (u != null) {
            ListNode v = u.next;
            u.next = b;
            b = u;
            u = v;
        }
        return b;
    }
}

public class MainApp {
    public static void dumpList(ListNode u) {
        while (u != null) {
            System.out.printf("%d ", u.val);
            u = u.next;
        }
        System.out.println();
    }
  public static void main(String[] args) {
      ListNode head = new ListNode(0, new ListNode(1, new ListNode(2)));
      dumpList(head);
      Solution sln = new Solution();
      dumpList(sln.reverse(head));
  }
}
