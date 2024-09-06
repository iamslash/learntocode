// Copyright (C) 2024 by iamslash

import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
};

// 1ms 100.00% 44.6MB 76.37%
// doubly linked list
// O(N) O(N)
class Solution {
    public int[] toArray(Node head) {
        int n = 0;
        Node p = head;

        while (p != null) {
            p = p.next;
            n++;
        }

        int[] ans = new int[n];
        p = head;
        int i = 0;
        while (p != null) {
            ans[i++] = p.val;
        }
        
        return ans;
    }
}
