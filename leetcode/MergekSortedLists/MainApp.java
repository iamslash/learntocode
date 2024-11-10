// Copyright (C) 2024 by iamslash

import java.util.*;


// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 4ms 76.26% 44.6MB 30.33%
// heap
// O(NlgL) O(L)
// N: num of items
// L: num of lists
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode();
        ListNode p = head;
        Queue<ListNode> pq = new PriorityQueue<ListNode>((a, b) -> a.val - b.val);

        for (ListNode u : lists) {
            if (u != null) {
                pq.offer(u);
            }
        }

        while (!pq.isEmpty()) {
            ListNode u = pq.poll();
            p.next = u;
            p = u;
            if (u.next != null) {
                pq.offer(u.next);
            }            
        }

        return head.next;
    }
}

// lists: 1 4 5
//        1 3 4
//        2 6
//
// dfs(0, 2): 1 2 3 4 4 5 6
//   dfs(0,1): 1 3 4 4 5
//     dfs(0,0): 1 4 5
//     dfs(1,1): 1 3 4
//   dfs(2): 2 6

// 1ms 99.86% 44.2MB 79.93%
// recursive divide and conquor
// O(NlgK) O(lgK)
// N: num of items
// K: num of lists
class Solution {

    private ListNode merge(ListNode left, ListNode right) {
        ListNode ans = new ListNode();
        ListNode p = ans;

        while (left != null && right != null) {
            if (left.val <= right.val) {
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

        return ans.next;
    }

    private ListNode dfs(ListNode[] lists, int beg, int end) {
        // base
        if (beg > end) {
            return null;
        }
        if (beg == end) {
            return lists[beg];
        }

        // recursion
        int m = beg + (end - beg) / 2;
        ListNode left = dfs(lists, beg, m);
        ListNode right = dfs(lists, m + 1, end);
        return merge(left, right);
    }
    
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        return dfs(lists, 0, lists.length - 1);
    }
}

// 1ms 99.86% 44.7MB 22.00%
// iterative divide and conquor
// O(NlgK) O(1)
// N: num of items
// K: num of lists
class Solution {

    private ListNode merge(ListNode left, ListNode right) {
        ListNode head = new ListNode();
        ListNode p = head;

        while (left != null && right != null) {
            if (left.val <= right.val) {
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
        } else {
            p.next = right;
        }        

        return head.next;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }

        int n = lists.length, step = 1;

        while (step < n) {
            for (int i = 0; i < n - step; i += step * 2) {
                lists[i] = merge(lists[i], lists[i + step]);
            }
            step *= 2;
        }
                         
        return lists[0];
    }
}


