// Copyright (C) 2023 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

//   f
// 1 2
// s

//       f
// 1 2 3
//   s


//           f     
// 1 2 3 4 5
//     s

// 2ms 100.00% 63.9MB 100.00%
// tortoise and hare
// O(N) O(1)
class Solution {
    public ListNode[] splitCircularLinkedList(ListNode head) {
        ListNode fast = head.next;
        ListNode slow = head;
        while (fast != head && fast.next != head) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode body = slow.next;
        slow.next = head;
        slow = body;
        while (slow.next != head) {
            slow = slow.next;
        }
        slow.next = body;
        return new ListNode[]{head, body};
    }
}
