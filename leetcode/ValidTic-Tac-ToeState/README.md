# Problem

[Valid Tic-Tac-Toe State](https://leetcode.com/problems/valid-tic-tac-toe-state/)

# Idea

`3 x 3` 의 보드정보 `B[][]` 가 주어진다. 첫번째 플레이어는 `X` 를
채우고 두번째 플레이어는 `O` 를 채운다. 두 플레이어가 정상적으로
Tic-Tac-Toe 플레이할 때 `B[][]` 는 옳바른 보드의 상태인지 검증하는
문제이다.

예를 들어 다음과 같은 `B[][]` 는 옳바르지 못하다.

```
O..
...
...

X 가 무조건 먼저 와야 한다.

XOX
.X.
...

X 가 3 개이다. O 는 2 개 혹은 3 개 이어야 한다.

XXX
...
OOO

X 도 이기고 O 도 이긴다.
```

`cnt(X), cnt(Y), win(X), win(Y)` 를 기준으로 다음과 같이 여러가지 제한조건을 생각해 볼 수 있다.

0. `win(X) && win(Y)` 이면 `return false`
1. `win(X)` 이면 `return cnt(X) == cnt(O) + 1`
2. `win(Y)` 이면 `return cnt(X) == cnt(O)`
3. `!win(X) && !win(Y)` 이면 `return cnt(X) == cnt(O) + 1 || cnt(X) == cnt(O)`

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(1)
```
