# Problem

[Check if Word Can Be Placed In Crossword](https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/)

2 차원 배열 `B[][]`, 문자열 `word` 가 주어진다. `B[][]` 는 영문 소문자
혹은 ` `, `#` 으로 구성되어 있다. `word` 가 왼쪽으로 오른쪽으로 위로
혹은 방향으로 빈칸에 놓여질 수 있는지 검증하라. 이때 `word` 는 시작
하는 문자와 끝나는 문자의 이웃이 공백이 아니어야 한다.

# Idea

예를 들어 `board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"`
의 경우를 살펴보자.

```
# . #
. . #
# c .

# a #
. b #
# c .
```

따라서 답은 `true` 이다.

brute force 를 이용하여 해결할 만하다.

인덱스 `y, x` 를 이용하여 `B[][]` 를 순환한다. `B[y][x]` 에서
부터 시작하여 각 방향으로 `word` 가 빈칸에 놓여질 수 잇는지 검증한다.

시작 문자의 이웃이란 놓여질 방향과 반대방향의 cell 을 말한다. 이때
시작 문자의 이웃은 `B[][]` 의 바깥이거나 `#` 이어야 한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(HWS) O(1)

S: length of word
```
