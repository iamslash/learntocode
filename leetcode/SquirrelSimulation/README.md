# Problem

[Squirrel Simulation](https://leetcode.com/problems/squirrel-simulation/)

# Idea

나무의 위치 `tr[]`, 다람쥐의 위치 `sq[]`, 도토리의 위치 `nuts[][]` 가 주어진다.
다람쥐가 도토리 중 하나를 집어서 나무로 간다음 나머지 도토리들을 나무로 가져오는
거리들의 최소값을 구하는 문제이다.

다람쥐가 처음 선택하는 도토리를 제외하면 나머지 도토리들과 나무사이의 서리합은 항상 같다. 모든 도토리와 나무의 거리의 합을 `totd` 라고 하자. 다람쥐가 처음 선택하는 도토리를 `nut0` 이라고 하자. 

```
    result = totd - dist(nut0, tr) + dist(nut0, sq)
           = totd - (dist(nut0, tr) + dist(nut0, sq))
min result = totd - max(dist(nut0, tr) + dist(nut0, sq))
```

최대의 `dist(nut0, tr) + dist(nut0, sq)` 를 찾아서 `totd` 에서 빼면 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```