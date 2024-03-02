// Copyright (C) 2024 by iamslash


// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// Idea: linked list
//
// Find the middle of the list.
// Reverse the second half of the list.
// Merge two list.
//
//     p
// 0 1 2 3 4 5
//         q
//     b
// 0 1 2 3 4 5
//       u
//         v
// p
//   r
// 0 1 2
// 5 4 3
//   s
// q
//

// linked list
// O(N) O(1)
class Solution {
    private void dump(ListNode p) {
        while (p != null) {
            System.out.printf("%d ", p.val);
            p = p.next;
        }
        System.out.println();
    }
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }

        // Find the middle of the list.
        ListNode p = head, q = head;
        while (q.next != null && q.next.next != null) {
            p = p.next;
            q = q.next.next;
        }

        // Reverse the second half of the list
        ListNode b = null, u = p.next;
        p.next = null;
        // dump(head);
        // dump(u);
        while (u != null) {
            ListNode v = u != null ? u.next : null;
            u.next = b;
            b = u;
            u = v;
        }
        // dump(b);

        // Merge two list
        p = head;
        q = b;
        while (p != null) {
            ListNode r = p.next;
            ListNode s = q != null ? q.next : null;
            if (q != null) {
                q.next = r;
            }
            p.next = q;
            p = r;
            q = s;
        }
    }
}
