# Problem

[Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

# Idea

`0, 1` 로 구성된 그래프 `G[][]` 가 주어진다. `G[0][0]` 에서
`G[n-1][n-1]` 까지 최단 경로의 거리를 구하는 문제이다. `0` 은
갈 수 있고 `1` 갈 수 없다.

전형적인 [BFS shortest
path](/fundamentals/graph/bfsshortestpath/README.md) 문제이다.

두가지 사항을 주의하자.

* `int ans = 0` 을 선언하고 거리의 합을 저장한다. 그리고 `BFS loop`
  안에서 한번 더 loop 를 사용하여 `ans` 를 증가한다. `q.size()` 는
  inner loop 안에서 크기가 변하기 때문에 `qsize` 대신 `q.size()` 를
  사용하면 안된다.

```c
while (q.size()) {
  ans++;
  int qsize = q.size();
  for (int j = 0; j < qsize; ++j) {
  ...
  }
}
```
  
* 방문했다는 표시는 `q.push()` 와 함께 해야 한다. `q` 에 삽입된
  노드들도 다시 방문할 필요가 없다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
