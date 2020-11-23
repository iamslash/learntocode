# Problem

[Even Odd Tree](https://leetcode.com/problems/even-odd-tree/)

# Idea

BFS 로 level order traversal 을 수행하면 쉽게 해결할 수 있다.

또한 tree 의 level 마다 마지막 값을 저장하고 있다면 DFS 로 해결할 수
있다. `vector<int> lastVals` 를 선언하여 새로운 `TreeNode* u` 를
방문할 때마다 `lastVals` 를 업데이트 한다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
