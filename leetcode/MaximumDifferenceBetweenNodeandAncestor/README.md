# Problem

[Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)

# Idea

바이너리 트리의 루트노드 `u` 가 주어진다. 임의의 두 노드의 차이값의
절대값들 중 가장 큰 값을 구하는 문제이다.

대부분의 트리 문제는 DFS 로 해결한다. 노드의 값들 중 가장 큰 값과 가장
작은 값을 구하면 두 값의 차이가 곧 답이다. 다음과 같은 부분문제를
정의하고 재귀적으로 해결해 보자.

```
int dfs(TreeNode* u, int maxv, int minv)
     u: this node
  maxv: the max value of recent nodes
  minv: the min value of recent nodes
return: max difference between the max value and the min value
```

* `u == NULL` 이면 `return maxv - minv` 를 수행한다. 
* `maxv = max(maxv, u->val)`
* `minv = min(minv, u->val)`
* 새로운 `maxv, minv` 와 함께 두 자식을 방문한다.
* 두 자식들이 리턴값을 중 가장 큰 값을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
