# Problem

[Lowest Common Ancestor of a Binary Tree II](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)

`TreeNode* u, p, q` 가 주어진다. LCA 를 찾는다. 만약 `u` 를 root 로
하는 tree 에 `p` 혹은 `q` 가 없다면 NULL 을 리턴하라.

# Idea

[LCA](/geeksforgeeks/LowestCommonAncestorInABinaryTree/README.md) 를 참고해서 해결한다.

`TreeNode* pp, qq` 를 멤버로 선언한다. DFS 도중 `p` 를 만나면 `p` 를
`pp` 에 저장하고 `q` 를 만나면 `q` 를 `qq` 에 저장한다. DFS 를 마치고
`pp` 혹은 `qq` 가 `NULL` 이면 NULL 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(lgN)
```
