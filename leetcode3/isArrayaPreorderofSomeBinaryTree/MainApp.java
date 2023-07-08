// Copyright (C) 2023 by iamslash

import java.util.*;

//                       i
// nodes: 0,-1 1,0 2,0 3,2
//  stck: 0 2 3

//                       i
// nodes: 0,-1 1,0 2,0 3,1
//  stck:        

// 20ms 81.25% 84.2MB 93.75%
// stack
// O(N) O(N)
class Solution {
    public boolean isPreorder(List<List<Integer>> nodes) {
        int n = nodes.size();
        Deque<Integer> stck = new ArrayDeque<>();
        stck.addLast(nodes.get(0).get(0));
        for (int i = 1; i < n; ++i) {
            int u = nodes.get(i).get(0);
            int p = nodes.get(i).get(1);
            while (!stck.isEmpty() && stck.peekLast() != p) {
                stck.removeLast();
            }
            if (stck.isEmpty()) {
                return false;
            }
            stck.addLast(u);
        }
        return true;
    }
}
