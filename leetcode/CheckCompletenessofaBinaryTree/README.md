# Problem

[Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

# Idea

트리의 노드 `u` 가 주어진다. complete binary tree 인지
검증하는 문제이다.

예를 들어 아래와 같이 다양한 binary tree 를 살펴보자.

```
     T      T     F
             
     1      1     1
    / \    /       \
   2   3  2         3
```

각 level 마다 왼쪽에서 오른쪽으로 탐색한다. 탐색이 종료되지 않았는데
`NULL` 을 만나면 false 를 리턴한다.

BFS 를 이용하여 해결할 만 하다. BFS 를 위해 `queue<TreeNode*> q` 를
선언한다.  BFS loop 에서 `q.top()` 이 `NULL`이면 false 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
