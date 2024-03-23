// Copyright (C) 2024 by iamslash

import java.util.*;

//       i
// arr1: 1 10 100
// arr2: 1000
//          j
//
// 

// 238ms 13.86% 55.7MB 73.10%
// hash set
// O(NM^2) O(NM)
// N: represents the total number of elements in the longest array
// between arr1 and arr2.
// M: represents the maximum number of digits in the largest number
// found in either of the arrays.
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> numSet = new HashSet<>();

        for (int num : arr1) {
            String s = num + "";
            int len = s.length();
            for (int i = 0; i < len; ++i) {
                int cur = Integer.parseInt(s.substring(0, i + 1));
                numSet.add(cur);
            }
        }

        int maxCommonLen = 0;

        for (int num : arr2) {
            String s = num + "";
            int len = s.length();
            for (int i = maxCommonLen; i < len; ++i) {
                int cur = Integer.parseInt(s.substring(0, i + 1));
                if (numSet.contains(cur)) {
                    maxCommonLen = i + 1;
                }
            }
        }

        return maxCommonLen;
    }
}

// 43ms 76.86% 55.9MB 58.99%
// trie
// O(NM) O(NM)
// N: the total number of elements in arr1 (for space
// complexity, it's relevant to the trie's construction) and the
// analysis of arr2 elements (for time complexity during the queries).
// M: the maximum number of digits in the largest number
// found in either of the arrays, dictating both the depth of the trie
// (affecting space complexity) and the length of the longest query
// operation (affecting time complexity).
class Node {
    Node[] children = new Node[10];
}
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Node root = new Node();
        for (int num: arr1) {
            insert(root, num);
        }
        int maxCommonLen = 0;
        for (int num: arr2) {
            maxCommonLen = Math.max(maxCommonLen, query(root, num));
        }
        return maxCommonLen;
    }
    
    private void insert(Node root, int num) {
        List<Integer> list = new ArrayList<>();
        while (num > 0) {
            list.add(num % 10);
            num /= 10;
        }
        int m = list.size();
        Node node = root;
        for (int i = m - 1; i >= 0; i--) {
            if (node.children[list.get(i)] == null) {
                node.children[list.get(i)] = new Node();
            }
            node = node.children[list.get(i)];
        }
    }
    
    private int query(Node root, int num) {
        List<Integer> list = new ArrayList<>();
        while (num > 0) {
            list.add(num % 10);
            num /= 10;
        }
        int m = list.size();
        Node node = root;
        int maxCommonLen = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (node.children[list.get(i)] == null) {
                break;
            }
            node = node.children[list.get(i)];
            maxCommonLen++;
        }
        return maxCommonLen;
    }
}
