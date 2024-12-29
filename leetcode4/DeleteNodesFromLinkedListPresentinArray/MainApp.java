// Copyright (C) 2024 by iamslash

import java.util.*;


class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}


// head: 1 2 3 4 5
//             p

// 22ms 26.62% 64.40% 59.60%
// linked list
// O(N) O(N)
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        
        while (head != null && numSet.contains(head.val)) {
            head = head.next;
        }

        if (head == null) {
            return null;
        }

        ListNode p = head;
        while (p.next != null) {
            if (numSet.contains(p.next.val)) {
                p.next = p.next.next;
            } else {
                p = p.next;
            }
        }

        return head;
    }
}


// 5ms 96.48% 72.41% 5.04%
// linked list
// O(N) O(1)
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        boolean[] numExists = new boolean[100_001];
        for (int num : nums) {
            numExists[num] = true;
        }

        while (head != null && numExists[head.val]) {
            head = head.next;
        }

        if (head == null) {
            return null;
        }

        ListNode p = head;
        while (p.next != null) {
            if (numExists[p.next.val]) {
                p.next = p.next.next;
            } else {
                p = p.next;
            }
        }

        return head;
    }
}
