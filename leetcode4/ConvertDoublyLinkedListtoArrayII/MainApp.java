// Copyright (C) 2024 by iamslash

import java.util.*;

class Node {
    public int val;
    public Node prev;
    public Node next;
};

// 1ms 100.00% 45.4MB 62.37%
// list
// O(N) O(N)
class Solution {
    public int[] toArray(Node node) {
        int n = 1;
        Node p = node;

        while (p.prev != null) {
            p = p.prev;
            n++;
        }

        Node h = p;
        p = node;
        while (p.next != null) {
            p = p.next;
            n++;
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = h.val;
            h = h.next;
        }

        return ans;
    }
}
