# Problem

* [Stone Game III](https://leetcode.com/problems/stone-game-iii/)

점수가 적힌 돌들의 모임 `S[]` 가 주어진다. Alice 와 Bob 이 돌을
가져가는 게임을 한다. 항상 Alice 가 먼저 시작한다.  돌은 처음부터 1개
2개 혹은 3 개를 선택할 수 있다. 모든 돌이 선택되었을 때 점수가 가장
높은 사람이 승자가 된다. 또한 비길 수도 있다. Alice 가 이기면
`Alice`, Bob 이 이기면 `Bob`, 비기면 `Tie` 를 출력하라.

# Idea

다음과 같은 부분문제 `dfs` 를 정의하고 재귀적으로 해결해 본다.

```
int dfs(vector<int>& C, vector<int>& S, int i)

return: i번째 돌부터 선택하는 사람이 획득할 수 있는 최대 점수
     C: cache. C[i] 는 i번째 돌부터 선택하는 사람이 획득할 수 있는 최대 점수
     i: 이번 차례의 사람이 선택할 수 있는 돌의 인덱스
```

i-th 돌을 선택하는 사람이 Alice 혹은 Bob 인지는 중요하지 않다.
왜냐하면 `Alice` 가 항상 먼저 시작하기 때문에 `dfs` 를 처음 호출할 때
그 결과에 따라 승패를 알 수 있기 때문이다.

따라서 이번에 선택하는 사람이 1개, 2개, 3개 선택할 때 각각에 대해서
가장 최대의 점수를 얻을 때 그 최대의 점수를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
