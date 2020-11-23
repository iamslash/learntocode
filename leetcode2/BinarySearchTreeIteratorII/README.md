# Problem

[Binary Search Tree Iterator II](https://leetcode.com/problems/binary-search-tree-iterator-ii/)

# Idea

`stack<TreeNode*> stck` 를 선언하여 in-order traversal 을 위해 현재
node 가 `cur` 이면 `cur->right` 의 left child 들을 삽입한다.

`vector<int> vals` 를 선언하여 지금까지 탐색한 값들을 삽입한다.

`int pos` 를 선언하여 현재 index 를 저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(N)
```
