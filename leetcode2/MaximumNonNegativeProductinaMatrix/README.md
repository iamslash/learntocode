# Problem

[Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)

이차원 수열 `G[][]` 가 주어진다. `G[0][0]` 에서 출발하여 `G[n-1][n-1]`
까지 아래쪽 혹은 오른쪽으로 탐색할 수 있다. 도착한 구역의 숫자를 모두
곱해서 가장 큰 값을 구해 보자. 만약 그 숫자가 음수이면 `-1` 를
리턴한다.

# Idea

`int cMax[][]` 를 선언하여 `G[0][0]` 에서 `G[y][x]` 까지 곱한 최대값을
저장한다. `int cMin[][]` 를 선언하여 `G[0][0]` 에서 `G[y][x]` 까지
곱한 최소값을 저장한다.

`cMax[][], cMin[][]` 를 모두 채우면 `cMax[h-1][w-1]` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
