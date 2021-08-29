// Copyright (C) 2021 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}


// // 8ms 27.18% 44.6MB 5.64%
// // priority queue
// // O(NLlgL) O(N)
// // N: count of nodes
// // L: count of lists
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

// divide and conquor
// O(NlgL) O(lgL)
// N: count of nodes
// L: count of lists
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
       if(lists.length == 0 || lists  == null)
            return null;
        return recurLists(lists, 0, lists.length - 1);
    }
    public ListNode recurLists(ListNode[] lists, int start, int end){
        // base
        if(start > end)
            return null;
        if(start == end)
            return lists[start];
        // recursion
        int m = start+(end - start) / 2; 
        ListNode left = recurLists(lists, start, m);
        ListNode right = recurLists(lists, m + 1, end);
        return merge(left, right);
    }
    public ListNode merge(ListNode left, ListNode right){
        ListNode ans = new ListNode();
        ListNode iter = ans;
        while(left != null && right != null){
            if(left.val < right.val){
                iter.next = left;
                left = left.next;
            }
            else{
                iter.next = right;
                right = right.next;
            }
            iter = iter.next;
        }
        if(left != null)
            iter.next = left;
        if(right != null)
            iter.next = right;
        return ans.next;
    }
}
