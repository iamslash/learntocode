# Problem

[Inorder Successor in BST II](https://leetcode.com/problems/inorder-successor-in-bst-ii/)

# Idea

BST 의 임의의 노드 `Node* u` 가 주어지면 inorder 로 트리를 표현했을 때
`u` 다음의 노드를 구하는 문제이다.

오른쪽 자식이 있다면 오른쪽 자손들 중 가장 작은
값을 가지고 있는 노드가 답이다.

```
    
        5
      /   \
     2     7
    / \   / \
   1   3 6   8

u: 5
r: 8 
```

오른쪽 자식이 없다면 `u` 의 부모 `p` 가 왼쪽 자식일 때까지 위로
탐색한다.

```
        5
      /   \
     2     7
    / \   / \
   1   3 6   8
u:3
r:5
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
