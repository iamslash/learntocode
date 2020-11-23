# Problem

[Jump Game IV](https://leetcode.com/problems/jump-game-iv/)

수열 `A[]` 가 주어진다. `A[0]` 에서 시작하여 `A[n-1]` 로 가는 최소
비용을 리턴하라. 단, `A[i]` 에서 `A[i-1]` 혹은 `A[i+1]` 로 이동할 수
있다. 또한 `A[i] == A[j] (i != j)` 일때 `A[j]` 로 이동할 수 있다.

# Idea

이동 비용은 1 이고 최소 경로를 찾는
문제이다. [BFS](/fundamentals/graph/bfs/README.md) 로 해결할 만 하다.

`queue<int> q` 를 선언하여 BFS queue 로 이용한다.  

`vector<bool> visit` 를 선언하여 방문 여부를 저장한다.

`unordered_map<int, vector<int>> val2idxMap` 를 선언하여 `{value :
[index,]}` 를 저장한다.

`int step` 를 선언하여 최소경로를 저장한다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
