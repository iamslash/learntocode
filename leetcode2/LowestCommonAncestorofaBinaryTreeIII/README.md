# Problem

[Lowest Common Ancestor of a Binary Tree III](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/)

다음과 같은 `Node` 가 주어진다. 

```
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

두 노드 `p, q` 가 주어지면 `lca` 를 구하라.

# Idea

예를 들어 `p = 2, q = 1` 인 경우를 살펴보자.

```
         3
       /   \ 
      5     1
     / \   / \
    6   2 0   8 
       / \
      7   4 
```

다음의 두 값은 같다. 따라서 `src, dst` 는 결국 만나게 된다.

- `p` 에서 `lca` 까지 탐색하고 `q` 에서 `lca` 까지 탐색한 거리의 합
- `q` 에서 `lca` 까지 탐색하고 `p` 에서 `lca` 까지 탐색한 거리의 합

- `src = p, dst = q` 를 선언한다. 
- `src != dst` 동안 다음을 반복한다.
  - `src == NULL` 이면 `src = q` 
  - `src != NULL` 이면 `src = src.parent`
  - `dst == NULL` 이면 `dst = p`
  - `dst != NULL` 이면 `dst = dst.parent`

# Implementation

- [c++11](a.cpp)
- [java17](MainApp.java)

# Complexity

```
O(N) O(1)
```
