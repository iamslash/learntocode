# Problem

[Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/)

# Idea

비용의 모음이 `int A[][]` 형태로 주어진다. `A[0][i]` 에서 `A[n-1][j]`
까지의 경로를 구한다. 이때 인접한 경로는 같은 열이 될 수 없다. 가장
작은 비용의 경로를 찾고 그 비용을 구하는 문제이다.

예를 들어 다음과 같이 `A = [[1,2,3],[4,5,6],[7,8,9]]` 를 살펴보자.

```
1 2 3
4 5 6
7 8 9

minPath = 1 5 7
answer  = 13
```

`int min1st = 0, minJ = -1, min2nd2 = 0` 를 선언한다.  각각
`A[0..n-1]` 에 대하여 누적하여 더해진 첫번째 최소비용, 첫번째
최소비용의 인덱스, 두번째 최소비용을 저장한다.

인덱스 `i` 를 이용하여 `A[0]` 부터 `A[n-1]` 까지 순회하면서 다음을
반복한다. 

* `int min1st2 = INT_MAX, minJ2 = -1, min2nd2 = INT_MAX` 를 선언하여
  각각 `A[i]` 에 대하여 첫번째 최소비용, 첫번째 최소비용의 인덱스,
  두번째 최소비용을 저장한다.
* 인덱스 `j` 를 선언하고 `A[i][0..n-1]` 를 순회하면서 다음을 반복한다.
  * `int minVal` 를 선언하여 `j == minJ` 이면 `min1st` 를, `j != minJ`
    이면 `min2nd` 를 저장한다.
  * `A[i][j] + minVal` 이 `min1st2` 보다 작다면 `min1st2, minJ, min2nd`
    를 업데이트한다.
  * `A[i][j] + minVal` 이 `min1st2` 보다 크거나 같다면 `min2nd`
    를 업데이트한다.

모든 반복을 마치면 `min1st` 가 곧 답이다.

다음은 `A = [[1,2,3],[4,5,6],[7,8,9]]` 의 처리과정이다.

```
     A: 1 2 3
        4 5 6
        7 8 9
              minval: 
min1st: 0    min1st2: INT_MAX
  minJ:-1      minJ2: -1
min2nd: 0    min2nd2: INT_MAX

     A: 1 2 3 <-
        4 5 6
        7 8 9
              minval: 0
min1st: 1    min1st2: 1
  minJ: 0      minJ2: 0
min2nd: 2    min2nd2: 2

     A: 1 2 3 
        4 5 6 <-
        7 8 9
              minval: 
min1st: 6    min1st2: 6
  minJ: 1      minJ2: 1
min2nd: 6    min2nd2: 6

     A: 1 2 3 
        4 5 6 
        7 8 9 <-
              minval: 
min1st: 5    min1st2:13
  minJ: 0      minJ2: 0
min2nd: 6    min2nd2:13
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(1)
```
