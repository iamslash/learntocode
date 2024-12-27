# Problem

[Best Position for a Service Centre](https://leetcode.com/problems/best-position-for-a-service-centre/)

좌표의 모음 `P[][]` 가 주어진다. 모든 점들과 가까운 새로운 점을 구하라.

# Idea

원점을 시작으로 점의 위치를 이동해 가며 가장 가까운 곳을 찾는다.

주먹 구구식으로 해결하는 알고리즘을 [heuristic algorithm](/doc/combinatorial_search.md#heuristic) 이라고 한다.  특히 heuristic algorithm 을 찾는 algorithm 을 meta heuristic algorithm 이라고 한다. simulated annealing 은 meta heurisitic algorithm 중 하나이다. 이 문제는 원점을 이리 저리 이동하면서 답을 찾는 것이기 때문에 simulated annealing 으로 해결할 만 하다.

`double minCost = DBL_MAX` 를 선언하여 답을 저장한다. `int dirs[5] = {-1, 0, 1, 0, 1}` 를 선언하여 기존 원점으로 부터 새로운 원점 4 개를 구할 때 이용한다. 그리고 새로운 원점에서 모든 점의 거리 합을 구하고 `minCost` 를 업데이트 한다.

`double step = 100, epsilon = 1e-6` 을 선언하여 `step > epslion` 인 동안 다음을 반복한다.

* `bool found = false` 를 선언하여 loop 을 탈출할 조건으로 이용한다.
* 인덱스 `i` 를 선언하여 `[0..4)` 인 동안 다음을 반복한다.
  * `vector<double> nextCenter = {nx, ny}` 를 선언하여 새로운 원점을 구한다.
  * `double cost = distAll(P, nextCenter}` 를 선언하여 새로운 원점에서
    모든 점들의 거리합을 구한다.
  * `cost < minCost` 이면 `minCost, centerPos, found` 를 업데이트하고
    loop 을 탈출한다.

모든 반복을 마치면 `minCost` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(???) O(N)
```
