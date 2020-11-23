# Problem

* [Paint House II](https://leetcode.com/problems/paint-house-ii/)

# Idea

집과 페인트 가격에 대한 2 차원 배열 `costs[][]` 가 주어진다.  연속한
집은 서로 같은 색의 페인트를 사용할 수 없다. 가장 최소의 비용으로 칠할
때 그 비용의 합을 구하는 문제이다.

이전의 첫번째로 작은 비용을 `prvmin1`, 두번째로 작은 비용을 `prvmin2`,
첫번째로 작은 비용의 마지막 페인트 색의 인덱스를 `prvidx1` 에
저장하자.

현재 어떤 집에 대해 가장 작은 비용을 `curmin1`, 두번째로 작은 비용을
`curmin2`, 첫번째로 작은 비용의 페인트 색의 인덱스를 `curidx1` 에
저장하자.q

모든 집, 모든 페인트를 다음과 같이 순회한다.

```
for (int i = 0; i < costs.size(); ++i)
  for (int j = 0; j < costs[0].size(); ++j)
```

그리고 다음을 반복한다.

0. 현재 색의 인덱스는 `j` 이다. `j != prvidx1` 이면 `j` 로 칠할 수
   있다. 따라서 `j` 까지 칠한 비용은 `cost = costs[i][j] + prvmin1`
   이다. 그러나 `j == prvidx11` 이면 바로 전에는 `j` 로 칠할 수
   없다. 따라서 `j` 까지 칠한 비용은 `cost = costs[i][j] + prvmin2`
   이다.
1. `j` 까지 칠한 비용에 대해 `cost < curmin1` 이면 `curmin2 = curmin1,
   curmin1 = cost, curidx1 = j` 를 수행한다. 그렇지 않고 `cost <
   curmin2` 이면 `curmin2 = cost` 를 수행한다.

집 `i` 에 대해 페인트 `j` 를 모두 순회했다면 `prvmin1 = curmin1,
prvmin2 = curmin2, prvidx1 = curidx1` 를 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NK) O(1)
```
