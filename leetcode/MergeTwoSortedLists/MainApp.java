// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 0ms 100.00% 41.4MB 34.19%
// two pointers
// O(N) O(1)
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode();
        ListNode p = head;
        while (list1 != null || list2 != null) {
            if (list1 != null && list2 != null) {
                if (list1.val < list2.val) {
                    p.next = list1;
                    list1 = list1.next;
                } else {
                    p.next = list2;
                    list2 = list2.next;
                }
            } else if (list1 != null) {
                p.next = list1;
                list1 = list1.next;
            } else {
                p.next = list2;
                list2 = list2.next;
            }
            p = p.next;
        }
        return head.next;
    }
}

// 0ms 100.00$ 41.6MB 33.30%
// recursion
// O(N) O(N)
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // base
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        // recursion
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
