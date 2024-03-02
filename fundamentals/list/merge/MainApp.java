// Copyright (C) 2024 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode merge(ListNode a, ListNode b) {
        // Merge two list
        ListNode p = a;
        ListNode q = b;
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
        return a;        
    }
}

public class MainApp {
    public static void dumpList(ListNode u) {
        while (u != null) {
            System.out.printf("%d ", u.val);
            u = u.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        {
            ListNode a = new ListNode(1, new ListNode(2, new ListNode(3)));
            ListNode b = new ListNode(4, new ListNode(5, new ListNode(6)));
            Solution sln = new Solution();
            dumpList(sln.merge(a, b));
            // 1 4 2 5 3 6
        }
        {
            ListNode a = new ListNode(1, new ListNode(2, new ListNode(3)));
            ListNode b = new ListNode(4, new ListNode(5));
            Solution sln = new Solution();
            dumpList(sln.merge(a, b));
            // 1 4 2 5 3
        }
    }
}
