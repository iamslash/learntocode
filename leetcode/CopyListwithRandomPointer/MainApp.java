// Copyright (C) 2022 by iamslash

import java.util.*;

// Definition for a Node.
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

// 0ms 100.00% 42.5MB 16.54%
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
    p= head;
    while (p != null) {
      Node v = nodeMap.get(p);
      v.next = nodeMap.get(p.next);
      v.random = nodeMap.get(p.random);
      p = p.next;
    }
    return nodeMap.get(head);
  }
}
