// Copyright (C) 2023 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

//        u .  .
// head: 18 6 10 3
//         3
//          

// 2ms 93.44% 43.4MB 97.65%
// linked list
// O(N) O(1)
class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode u = head;
        while (u.next != null) {
            int val = gcd(u.val, u.next.val);
            ListNode v = new ListNode(val, u.next);
            u.next = v;
            u = v.next;
        }
        return head;
    }
}
