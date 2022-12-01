// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// Idea: stack, linked list
//
// Reverse and consider latest max value
// Need stack and consider recursion

// 15ms 91.33% 64.8MB 91.01%
// linked list
// O(N) O(N)
class Solution {
    public ListNode removeNodes(ListNode u) {
        // base
        if (u == null) {
            return null;
        }
        // recursion
        u.next = removeNodes(u.next);
        if (u.next != null && u.val < u.next.val) {
            return u.next;
        }
        return u;
    }
}

