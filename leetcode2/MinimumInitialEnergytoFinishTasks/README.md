# Problem

[Minimum Initial Energy to Finish Tasks](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/)

수열 `T[][]` 가 주어진다. `T[i][0]` 와 `T[i][1]` 는 i-th 작업의 비용과
조건이다. `T[i]` 를 수행하기 위해 내가 가진 에너지가 `T[i][1]` 만큼
있어야 한다. 그리고 `T[i]` 를 수행하면 내가 가진 에너지에서 `T[i][0]`
만큼 제거한다.

`T[][]` 를 모두 수행하기 위해 내가 가져야할 에너지의 최소값을 구하라.

# Idea

예를 들어 `tasks = [[1,2],[2,4],[4,8]]` 의 경우를 살펴보자.

내가 가진 에너지를 `H` 라고 해보자. `H-T[i][0]` 이 작은 것부터
시작하면 좋을 것 같다. 그러나 `T[i][1]` 역시 작은 것부터 시작해야 할
것 같다.

`T[i][1] - T[i][0]` 이 작은 것부터 하면 비용과 조건을 모두 반영할 수
있다. `tasks` 를 `T[i][1] - T[i][0], T[i][1]` 의 오름차순으로
정렬한다. 그리고 다시 `tasks` 를 순회하면서 `T[i][0]` 을 모두 더한다.

`int ans = 0` 를 선언하여 답을 저장한다.

인덱스 `i` 를 선언하고 `[0..n)` 를 순회하며 다음을 반복한다.

* `T[i][0] = T[i][1] - T[i][0]` 를 수행한다.

`T[][]` 를 오름차순으로 정렬한다. 이제 `T[][]` 는 `T[i][1] - T[i][0],
T[i][1]` 를 기준으로 정렬되어 있다.

인덱스 `i` 를 선언하고 `[0..n)` 를 순회하며 다음을 반복한다.

* `ans = max(ans + T[i][1] - T[i][0], T[i][1])` 를 수행한다. `T[i][0]`
  은 `minimum - actual` 이다.  따라서 `actual = minimum - (minimum -
  actual)` 이므로 `actual = T[i][1] - T[i][0]` 과 같다.
  
모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
