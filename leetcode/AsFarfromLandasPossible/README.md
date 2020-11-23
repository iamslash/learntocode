# Problem

[As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/)

# Idea

`0, 1` 로 구성된 그래프 `G[][]` 가 주어진다. 모든 `1` 에서 가장 멀리
떨어진 `0` 의 위치를 구하는 문제이다. 거리는 manhatan distance 를
이용한다.  두점 `(x0, y0), (x1, y1)` 에 대하여 거리는 `distance =
|x0 - x1| + |y0 - y1|` 이다.

BFS 를 이용해서 해결한다. 먼저 `queue<pair<int, int>> q` 
를 선언하여 BFS queue 로 이용한다.

그리고 `G` 를 순회하면서 `1` 의 상하좌우 셀을 `q` 에 삽입한다.  이때
한번 삽입한 셀에 대해 `G[y][x] = 2` 하여 중복으로 삽입되는 것을
방지한다.

`int step = 0` 을 선언하여 거리를 저장한다. BFS loop 에서 `int qsize =
q.size()` 를 선언하여 `step` 떨어진 노드들을 처리한다.

마지막에 `step == 0` 이면 한번도 BFS loop 을 수행하지 않은 거이므로
`-1` 을 리턴한다. `step > 0` 이면 `step` 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
