# Problem

[Stone Game V](https://leetcode.com/problems/stone-game-v/)

수열 `S[]` 가 주어진다. Alice 와 Bob 은 다음과 같은 순서로 게임을
한다.

* `Alice` 는 `S[]` 를 2 개의 group 으로 나눈다.
* `Bob` 은 2 개의 group 중 합이 큰 것을 제거한다.
* `Alice` 는 나머지 group 의 합을 얻는다.

`Alice` 가 얻는 점수가 최대가 되도록 하고 그때의 점수를 구하라.

# Idea

예를 들어, `S = [6, 2, 3, 4, 5, 5]` 의 경우를 살펴보자. 

```
S: 6 2 3 | 4 5 5    11
   6 | 2 3          16
   2 | 3            18 
```

따라서 답은 18 이다.

`vector<int> PS(n)` 를 선언하여 연속된 구간의 합을 빠르게 구할 수
있다.  `vector<vector<int>> C(n, vector<int>(n))` 를 선언하여
`C[i][j]` 에 `i, j` 구간에서 Alice 가 얻을 수 있는 최대값을 저장한다.

다음과 같이 부분문제 `dfs(int i, int j)` 를 선언하여 recursive dynamic
programming 으로 해결한다.

```
int dfs(int i, int j)

return: maximum alice's score between i, j
     i: start index of the range
     j: end index of the range
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
