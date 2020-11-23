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

예를 들어 `p = 5, q = 1` 인 경우를 살펴보자.

```
         3
       /   \ 
      5     1
     / \   / \
    6   2 0   8 
       / \
      7   4 
```

`Node *s = p, *t = q` 를 선언한다. `s, t` 는 부모로 이동한다. 만약 `s
== NULL` 이면 `s = q` 를 수행한다. `t == NULL` 이면 `t = p` 를
수행한다. `s == t` 이면 `lca` 를 찾게된다.

`s` 에서 `lca` 까지 이동한 거리는 `t` 에서 `lca` 까지 이동한 거리가
같다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
