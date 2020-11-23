# Problem

[The Maze III](https://leetcode.com/problems/the-maze-iii/)

# Idea

미로 `M[][]` 와 공의 위치 `B[]` 구멍의 위치 `H[]` 가 주어진다.
공이 구멍까지 도달하는 가장 짧은 거리에 대해 방향 문자열을 구하는
문제이다. 방향 문자열은 `urld` 과 같은 문자들로 구성된다.

미로 셀의 최소거리를 `dist[][]` 에 저장하고 그때의 경로를 `path[][]` 
에 저장한다. 

BFS 로 해결하기 위해 `queue<tuple<int, int, int, string>> q` 를
선언한다. `q` 는 `{uy, ux, ud (distance), up (path)}` 를 push 한다.
BFS loop 에서 `q` 의 아이템을 꺼내와서 다음과 같이
기존의 거리보다 짧은 것인지 비교해보고 그렇지 않으면 건너뛴다.
거리가 같다면 `path` 가 사전순으로 앞선 것이지 비교해 보고 그렇지 
않으면 건너뛴다.

```cpp
      if ((dist[uy][ux] < ud) ||
          (dist[uy][ux] == ud && path[uy][ux] <= up))
        continue;
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V+E) O(HW)
h: height of maze
w: width of maze
```