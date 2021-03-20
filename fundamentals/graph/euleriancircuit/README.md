# Problem

그래프 `adj[][]` 와 출발 정점 `u` 가 주어지면 모든 간선을 정확히 한번씩만 지나서
시작점으로 되돌아 오는 경로를 구하는 문제이다.

# Keyword

```
adj, order, dfs, euler_circuit
```

# Idea

무향, 방향 그래프 에서 발견 할 수 있다. 무향 그래프가 쉽다. 간선이 두개의
컴포넌트로 나누어져 있는 경우 불가능하다.

`a, b` 그리고 `c` 정점으로 구성된 두개의 컴포넌트가 있을때 `(a,b), (b,a)` 간선이
존재하는 경우 euler circuit 은 존재한다.

정점에 인접한 간선의 수를 차수 (degree) 라고 한다. 차수가 짝수이면 짝수점,
홀수이면 홀수점이라고한다. 모든 정점이 짝수점이어야 euler circuit 이 존재한다.
무향 그래프는 모든 정점이 짝수점이다. 홀수점이 하나라도 있으면 euler circuit 이
존재할 수 없다. 

[DFS](fundamentals/graph/dfs/README.md) 으로 `order` 에 정점을 삽입후 `order` 을 뒤집는다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V+E) O(V)
```