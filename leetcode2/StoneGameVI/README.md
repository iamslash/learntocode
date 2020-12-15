# Problem

[Stone Game VI](https://leetcode.com/problems/stone-game-vi/)

`i-th` 에 Alice 가 선택할 수 있는 점수의 모음 `A[]` 가 주어진다.  또한
`i-th` 에 Bob 이 선택할 수 있는 점수의 모음 `B[]` 가 주어진다.

Alice, Bob 이 최선을 다해 게임을 한다고 하자. Alice 가 이기면 `1`,
Alice 가 지면 `-1`, Alice 가 비기면 `0` 을 리턴하라.

# Idea

Alice 와 Bob 의 점수의 합을 내림차순으로 정렬하자. 서로 최선을 다해
게임을 해야 한다. 높은 점수부터 낮은 점수 방향으로 Alice 가 한번
선택하고 Bob 이 한번 선택을 해보자. 모든 반복을 마치면 Alice 의
점수합과 Bob 의 점수합을 비교해 보자.

문제의 조건에 의해 `1 <= A[i], B[i] <= 100` 이다.  Alice 와 Bob 의
점수를 합하였을 때 그 최대는 `200` 이다. `vector<vector<int>>
idx(200)` 을 선언한다. `idx[sum]` 에 Alice, Bob 점수합에 해당하는
인덱스들을 저장한다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(N) O(N)
```
