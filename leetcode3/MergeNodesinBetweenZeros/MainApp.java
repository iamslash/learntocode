// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// h
//               u
// 0 3 1 0 4 5 2 0
//               v

// 6ms 100.00% 71.1MB 99.54%
// two pointers
// O(N) O(1)
class Solution {
    public ListNode mergeNodes(ListNode head) {
        head = head.next;
        ListNode u = head;
        while (u != null && u.next != null) {
            ListNode v = u.next;
            while (v != null && v.val != 0) {
                u.val += v.val;
                v = v.next;
            }
            u.next = v.next;
            u = v.next;
        }        
        return head;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
