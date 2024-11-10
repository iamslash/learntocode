// Copyright (C) 2022 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// // 11ms 33.90% 47MB 12.03%
// // heap
// // O(NlgN) O(N)
// //   N: count of nodes
// class Solution {
//     public ListNode mergeKLists(ListNode[] lists) {
//         ListNode head = new ListNode();
//         ListNode p = head;
//         Queue<ListNode> pq = new PriorityQueue<ListNode>((a, b) -> a.val - b.val);
//         for (ListNode u : lists) {
//             if (u != null) {
//                 pq.offer(u);
//             }
//         }
//         while (pq.size() > 0) {
//             ListNode u = pq.poll();
//             p.next = u;
//             p = p.next;
//             if (u.next != null) {
//                 pq.offer(u.next);
//             }
//         }
//         return head.next;
//     }
// }

// 1ms 100.00% 44.1MB 56.05%
// divide and conquor
// O(NlgN) O(lgN)
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0 || lists == null) {
            return null;
        }
        return mergeParts(lists, 0, lists.length - 1);
    }
    private ListNode mergeParts(ListNode[] lists, int beg, int end) {
        // base
        if (beg > end) {
            return null;
        }
        if (beg == end) {
            return lists[beg];
        }
        // recursion
        int mid = beg + (end - beg) / 2;
        ListNode left = mergeParts(lists, beg, mid);
        ListNode right = mergeParts(lists, mid + 1, end);
        return merge(left, right);
    }
    private ListNode merge(ListNode left, ListNode right) {
        ListNode head = new ListNode();
        ListNode p = head;
        while (left != null && right != null) {
            if (left.val < right.val) {
                p.next = left;
                left = left.next;
            } else {
                p.next = right;
                right = right.next;
            }
            p = p.next;
        }
        if (left != null) {
            p.next = left;
        }
        if (right != null) {
            p.next = right;
        }
        return head.next;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
