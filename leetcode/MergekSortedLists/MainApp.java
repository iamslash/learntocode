// Copyright (C) 2021 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}


// 8ms 27.18% 44.6MB 5.64%
// priority queue
// O(NlgN) O(N)
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
        while (pq.size() > 0) {
            ListNode u = pq.poll();
            p.next = u;
            p = p.next;
            if (u.next != null) {
                pq.offer(u.next);
            }
        }
        return head.next;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
