// Copyright (C) 2024 by iamslash

import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode half(ListNode head) {
        // Merge two list
        ListNode p = head, q = head;

        while (q.next != null && q.next.next != null) {
            p = p.next;
            q = q.next.next;
        }

        return p.next;
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
        Solution sln = new Solution();
        {
            ListNode head = new ListNode(1, new ListNode(2, new ListNode(3)));
            dumpList(sln.half(head));
            // 3
        }
        {
            ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
            dumpList(sln.half(head));
            // 3 4
        }
    }
}
