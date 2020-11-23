# Problem

[Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)

높이로 구성된 이차원 배열 `H[][]` 가 주어진다. `H[0][0]` 에서 출발하여
`H[h-1][w-1]` 까지 이동해보자. 이때 인접한 두 셀의 높이의 차이는
최소가 되도록 한다. 이때 그동안 지나온 높이의 차이중 가장 큰 값을
리턴하라.

# Idea

예를 들어 `H = [[1,2,2],[3,8,2],[5,3,5]]` 의 경우를 살펴보자.

```
1 2 2
3 8 2
5 3 5

path: 1-3-5-3-5
 ans: max(abs(3-1), abs(5-3), abs(3-5), abs(5-3)) =
      2
```

따라서 답은 2 이다.

인접한 두 셀의 높이의 차이는 일반 그래프에서 거리와 같다. 문제를 다시
생각해 보면 거리가 `H[0][0]` 에서 출발하여 `H[h-1][w-1]` 까지 거리가
최소인 곳을 찾아서 탐색해야 한다. 한 점에서 출발하여 다른 한점까지 
최소 경로를 구하는 것과 같다. 이때 거리는 모두 양수이다. 

따라서 [dijkstra](/fundamentals/graph/dijkstra/README.md) 를 이용하여 해결할 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(ElgV) O(HW)
```
