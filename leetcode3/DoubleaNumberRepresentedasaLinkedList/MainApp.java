// Copyright (C) 2023 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

//       u
// head: 1 8 9
//       3 7 8
//
//             u
// head: 1 9 9 8
//       

// 2ms 100.00% 44.9MB 100.00%
// linked list
// O(N) O(1)
class Solution {
    public ListNode doubleIt(ListNode head) {
        ListNode u = head;
        if (u.val >= 5) {
            head = new ListNode(0, u);
        } else {
            u.val *= 2;
        }
        u = head;
        while (u.next != null) {
            if (u.next.val >= 5) {
                u.val += 1;
            }
            u.next.val = (u.next.val * 2) % 10;
            u = u.next;
        }
        return head;
    }
}
