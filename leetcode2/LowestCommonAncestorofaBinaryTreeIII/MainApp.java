// Copyright (C) 2024 by iamslash

import java.util.*;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};

//        3
//     /     \
//    5       1
//  /   \   /   \
// 6     2 0     8
//      / \
//     7   4

// 28ms 87.37% 44.5MB 63.33%
// math
// O(N) O(1)
class Solution {
    public Node lowestCommonAncestor(Node p, Node q) {
        Node s = p, t = q;

        while (s != t) {
            if (s == null) {
                s = q;
            } else {
                s = s.parent;
            }

            if (t == null) {
                t = p;
            } else {
                t = t.parent;
            }
        }
        
        return s;
    }
}
