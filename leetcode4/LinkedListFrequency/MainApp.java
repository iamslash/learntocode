// Copyright (C) 2024 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 37ms 35.65% 57.7MB 58.56%
// linked list
// O(N) O(N)
class Solution {
    public ListNode frequenciesOfElements(ListNode head) {
        Map<Integer, Integer> freqMap = new HashMap<>();

        ListNode p = head;
        while (p != null) {
            freqMap.put(p.val, freqMap.getOrDefault(p.val, 0) + 1);
            p = p.next;
        }

        ListNode h = null, b = null;
        for (int key : freqMap.keySet()) {
            ListNode q = new ListNode(freqMap.get(key));
            if (h == null) {
                h = q;
            }
            if (b != null) {
                b.next = q;
            }
            b = q;
        }

        return h;
    }
}
