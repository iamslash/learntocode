# Problem

[Correct a Binary Tree](https://leetcode.com/problems/correct-a-binary-tree/)

binary tree 의 root node 인 `TreeNode* root` 가 주어진다. 트리의 한
노드는 오른쪽 자식이 잘 못 할당되어 있다. 같은 깊이의 다른 노드를
가르키고 있다. 잘 못된 노드를 제거하라.

# DFS 

## Idea

`unordered_set<TreeNode*> ust` 를 선언하여 이미 방문한 노드의 포인터를
저장한다.

`root` 를 오른쪽 부터 DFS 한다. 만약 문제 있는 node 를 만나면 NULL 을
리턴하도록 `correctBinaryTree` 를 구현한다. `correctBinaryTree` 가
리턴한 node 는 `root->left` 혹은 `root->right` 가 가르키도록 한다.

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N) O(N)
```

# BFS

## Idea

`unordered_set<TreeNode*> ust` 를 선언하여 이미 방문한 노드의 포인터를
저장한다. `queue<TreeNode**> q` 를 선언하여 BFS queue 로 사용한다.

잘못된 노드 `*u` 를 만나면 `*u = NULL` 를 수행하고 BFS loop 를 빠져
나온다.

## Implementation

* [c++11](a.cpp)
* [py3](a.py)

## Complexity

```
O(N) O(N)
```
