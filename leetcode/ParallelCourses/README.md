# Problem

[Parallel Courses](https://leetcode.com/problems/parallel-courses/)

# Idea

숫자 `N` 과 연결정보의 모음 `R[][]` 가 주어진다. 부모 노드 `u` 와 자식
노드 `v` 가 있을 때 `u` 는 `v` 의 선수과목을 의미한다. 선수과목을 먼저
수강하는 식으로 모든 과목을 이수했을 때 그 길이를 구하는 문제이다.
만약 cycle 이 있다면 `-1` 리턴한다.

DFS 로 해결할 만하다. `vector<int> D(N, 1)` 를 선언하여 노드의 거리를
저장한다. `vector<int> S(N, -1)` 를 선언하여 노드의 방문 상태를
저장한다.  `-1: not visited, 0: visiting, 1: visited` 이다.
`vector<vector<int>> G(N)` 를 선언하여 `R` 의 내용을 기반으로 채운다.

다음과 같이 부분문제 `dfs` 를 정의하고 재귀적으로 구현한다.

```c
bool dfs(vectorvector<int>>& G, vector<int>& D, vector<int>& S, int u)
     G: graph 
     D: distances of node
     S: visiting status of node
     u: this node
return: no cycle?
```

* `u == 1` 이면 이미 방문완료된 노드이다. 다시 방문할 필요가 없다. `true` 를 리턴한다.
* `u == 0` 이면 방문처리중인 노드이다. 즉, 사이클이다. `false` 를 리턴한다.
* `u = 0` 를 수행하고 `u` 의 이웃 `v` 들을 `dfs` 한다.
  * `dfs(G, D, S, v) == false` 이면 사이클을 발견했으니 false 를 리턴한다.
  * `v` 의 거리를 갱신하기 위해 `D[u] = max(D[u], 1 + D[v])` 수행한다.
* dfs loop 를 마치면 `u` 의 자손들을 모두 방문했다는 의미이다. `u = 1`
  를 수행하고 `true` 를 리턴한다.

dfs all loop 를 마치면 `D[i]` 중 가장 큰 것이 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(V+E) O(V)
```
