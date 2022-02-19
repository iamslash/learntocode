// Copyright (C) 2022 by iamslash

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

//     1
//   /   \
// 2       3
//       /   \
//     4       5

// 1,2,N,N,3,4,N,N,5,N,N,

// 27ms 41.07% 55MB 15.00%
// pre-order
//   serialize: O(N) O(N)
// deserialize: O(N) O(lgN) 
class Codec {
    public String serialize(TreeNode u) {
        // base
        if (u == null) {
            return "N";
        }
        // recursion
        return String.valueOf(u.val) + "," + serialize(u.left) + "," + serialize(u.right);
    }
    private TreeNode buildTree(Deque<String> deq) {
        String s = deq.removeFirst();
        // base
        if (s.equals("N")) {
            return null;
        }
        // recursion
        TreeNode u = new TreeNode(Integer.valueOf(s));
        u.left = buildTree(deq);
        u.right = buildTree(deq);
        return u;        
    }
    public TreeNode deserialize(String data) {
        List<String> dataList = Arrays.asList(data.split(","));
        Deque<String> deq = new ArrayDeque<>(dataList);
        return buildTree(deq);
    }
}
