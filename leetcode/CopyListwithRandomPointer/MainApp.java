// Copyright (C) 2024 by iamslash

import java.util.*;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

// head: 7 13 11 10 1
//                    p
// clon: 7 13 11 10 1
//                  b q

// 0ms 100.00% 44.2MB 71.59%
// hash map
// O(N) O(N)
class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> nodeMap = new HashMap<>();
        Node p = head;
        while (p != null) {
            nodeMap.put(p, new Node(p.val));
            p = p.next;
        }

        p = head;
        while (p != null) {
            Node newNode = nodeMap.get(p);
            newNode.next = nodeMap.get(p.next);
            newNode.random = nodeMap.get(p.random);
            p = p.next;
        }

        return nodeMap.get(head);
    }
}
