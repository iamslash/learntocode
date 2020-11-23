# Problem

[Predict the Winner](https://leetcode.com/problems/predict-the-winner/)

점수들의 모음 `P[]` 가 주어진다. Player 1 과 Player 2 가 게임을 한다.
양끝의 숫자들 중 하나를 가져간다. 가장 많은 숫자를 가져간 사람이
승자이다.  Player 1 이 이길 수 있는지 검증하라.

# Idea

`vector<vector<int>> C(n, vector<int>(n -1))` 를 선언하여 `C[i][j]` 에
Player-1 이 `P[i..j]` 를 선택해야할 경우 획득할 수 있는 최대 점수를
저장한다.

부분문제 `dfs` 를 다음과 같이 정의한다.

```
int dfs(C, P, i, j)

return: max score of Player-1 for i, j
     C: cache of C[i][j]
     i: left most index of scores
     j: right most index of socres
```

`dfs(i, j)` 를 생각해 보자. Player-1 이 `P[i]` 를 선택한 경우와 `P[j]`
를 선택한 경우를 비교하여 최대 값을 취하자.

```
    int a = P[i] + min(dfs(P, C, i+1, j-1), dfs(P, C, i+2, j));
    int b = P[j] + min(dfs(P, C, i, j-2), dfs(P, C, i+1, j-1));
```

모든 반복을 마치면 Player-1 의 점수합을 2 배했을 때 점수의 총합보다
크거나 같으면 true 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(P^2) O(P)
```
