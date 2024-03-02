// Copyright (C) 2024 by iamslash

import java.util.*;


//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 1ms 68.00% 43.9MB 80.00%
// linked list
// O(N) O(1)
class Solution {
    public String gameResult(ListNode head) {
        ListNode p = head;
        int evnWin = 0, oddWin = 0;
        while (p != null) {
            if (p.val > p.next.val) {
                evnWin++;
            } else if (p.val < p.next.val) {
                oddWin++;
            }
            p = p.next.next;
        }
        if (evnWin > oddWin) {
            return "Even";
        } else if (evnWin < oddWin) {
            return "Odd";
        }
        return "Tie";
    }
}
