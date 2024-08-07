// Copyright (C) 2024 by iamslash

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

// 10ms 80.91% 45.5MB 80.88%
// deque
// O(N) O(N)
class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode u) {
        // base
        if (u == null) {
            return "N";
        }

        // recursion
        StringBuilder sb = new StringBuilder();
        sb.append(String.valueOf(u.val));
        sb.append(",");
        sb.append(serialize(u.left));
        sb.append(",");
        sb.append(serialize(u.right));
        
        return sb.toString(); 
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

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        List<String> dataList = Arrays.asList(data.split(","));
        Deque<String> dataDeq = new ArrayDeque<>(dataList);
        return buildTree(dataDeq);
    }
}
