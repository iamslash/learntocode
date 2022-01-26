// Copyright (C) 2022 by iamslash

import java.util.*;

//         s
// head: 1 2
//           f
//
//         s
// head: 1 2 3
//           f

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 6ms 43.89% 215MB 23.75%
// slow fast
// O(N) (1)
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if (head.next == null) {
            return null;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode b = dummy, s = head, f = head;
        while (f != null && f.next != null) {
            b = s;
            s = s.next;
            f = f.next.next;
        }
        b.next = s.next;
        return head;
    }
}
