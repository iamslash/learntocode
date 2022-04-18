// Copyright (C) 2022 by iamslash

import java.util.*;


class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// Idea: two pointers, stack
//  num: 1
//  cnt: 0
//       u
// head: 5 6 2 3 9 1
//       v
// stck: 

// 115ms 10.42% 64.5MB 83.07%
// two pointers, stack
// O(N) O(N)
class Solution {
    public ListNode reverseEvenLengthGroups(ListNode head) {
        ListNode u = head;
        int ord = 1;
        while (u != null) {
            ListNode v = u;
            Stack<Integer> stck = new Stack<>();
            // Push val to stack
            while (stck.size() < ord && u != null) {
                stck.push(u.val);
                u = u.next;
            }
            // Reverse even group
            if (stck.size() % 2 == 0) {
                while (v != u) {
                    v.val = stck.pop();
                    v = v.next;
                }
            }
            ord++;
        }
        return head;
    }
}

// 34ms 28.13% 64.8MB 82.81%
// two pointers, deque
// O(N) O(N)
class Solution {
    public ListNode reverseEvenLengthGroups(ListNode head) {
        ListNode u = head;
        int ord = 1;
        while (u != null) {
            ListNode v = u;
            Deque<Integer> deq = new ArrayDeque<>();
            // Push val to stack
            while (deq.size() < ord && u != null) {
                deq.offerLast(u.val);
                u = u.next;
            }
            // Reverse even group
            if (deq.size() % 2 == 0) {
                while (v != u) {
                    v.val = deq.pollLast();
                    v = v.next;
                }
            }
            ord++;
        }
        return head;
    }
}

// Idea: linked list
//       d
// head:   5 6 2 3 9 1
//             b
//               u
//           c
//         t

// reverse
//       b
//         u
// head: 6 2
//         v

// 5ms 100.00% 61MB 87.24%
// four pointers, reverse
// O(N) O(1)
class Solution {
    private ListNode reverse(ListNode h) {
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
    public ListNode reverseEvenLengthGroups(ListNode head) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode curr = head;
        ListNode tail = dummy;
        for (int ord = 1; curr != null; ++ord) {
            ListNode b = null;
            ListNode u = curr;
            int cnt = 0;
            while (u != null && cnt < ord) {
                b = u;
                u = u.next;
                cnt++;
            }
            b.next = null;
            if (cnt % 2 == 0) {
                tail.next = reverse(curr);
                tail = curr;
            } else {
                tail.next = curr;
                tail = b;
            }
            curr = u;
        }
        return head;
    }
}

