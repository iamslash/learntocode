// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 5ms 20.55% 48.1MB 6.78%
// brute force
// O(N) O(N)
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode p = head;
        int carry = 0;
        while (l1 != null || l2 != null) {
            // System.out.println(l1);
            int digit = carry;
            if (l1 != null) {
                digit += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                digit += l2.val;
                l2 = l2.next;
            }
            carry = digit / 10;
            p.next = new ListNode(digit%10);
            p = p.next;
        }
        if (carry > 0) {
            p.next = new ListNode(carry);
        }
        return head.next;
    }
}

// 1ms 100.00% 42MB 68.01%
// brute force
// O(N) O(N)
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode p = head;
        while (l1 != null || l2 != null) {
            int v1 = 0, v2 = 0;
            if (l1 != null) {
                v1 = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                v2 = l2.val;
                l2 = l2.next;
            }
            p.val += v1 + v2;
            if (p.val >= 10) {
                p.val -= 10;
                p.next = new ListNode(1);
            } else  if (l1 != null || l2 != null) {
                p.next = new ListNode();
            }
            p = p.next;
        }
        return head;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
