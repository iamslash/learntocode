# Problem

[FAMILYTREE](https://algospot.com/judge/problem/read/FAMILYTREE)

# Idea

[LCA @ geeksforgeeks](geeksforgeeks/LowestCommonAncestorInABinaryTree/README.md) 를
참고하면 [RMQT](/doc/tree_rmq.md) 를 활용하여 LCA를 찾아 낼 수 있다.
`a` 노드의 깊이를 `depth[a]`, `b` 노드의 깊이를 `depth[b]`, `LCA`
노드의 깊이를 `depth[LCA]` 라고 했을때 답에 해당하는 거리는 
`depth[a] + depth[b] - 2 * depth[LCA]` 와 같다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N)
```

```
O(N)   : tree traversal
O(N)   : build segment tree
O(lgN) : range minimum query 
```

# Space Complexity

```
O(N)   : segment tree array
O(N)   : call stack for query
```
