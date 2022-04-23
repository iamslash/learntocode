# Problem

[Candy Crush](https://leetcode.com/problems/candy-crush/)

그리드 데이터 `G[][]` 가 주어지면 캔디 크러시 알고리즘을 적용한 결과를
구하는 문제이다.

# Idea

지워야할 후보자들을 표기하는 eliminate phase 와 표기된 후보자들을
지우는 resolve phase 로 단계를 나누자.  eliminate phase 에서 아무것도
표기하지 않았다면 루프를 멈춘다.

* eliminate phase

`G[][]` 의 행과 열의 크기를 `h, w` 에 저장한다.
`G[][]` 의 행렬을 인덱스 `y, x` 를 이용하여 순회하면서 다음을 반복한다.

0. `x+2 < w` 이면 `G[y][x] == abs(G[y][x+1]) && G[y][x] == abs(G[y][x+2])` 를
   검사한다. 만약 그렇다면 해당 위치의 숫자를 음의 부호로 바꾼다.
1. `y+2 < h` 이면 `G[y][x] == abs(G[y][x]) && G[y+1][x] == abs(G[y+2][x])` 를
   검사한다. 만약 그렇다면 해당 위치의 숫자를 음의 부호로 바꾼다.

* resolve phase

읽기헤드 `rhead`, 쓰기헤드 `whead` 를 이용하여 제거해보자. `G[][]` 의
열을 인덱스 `x` 를 이용하여 순회하면서 다음을 반복한다.

0. `whead = h-1`
1. 인덱스 `rhead` 를 `h-1` 부터 `0` 까지 거꾸로 순회하면서 다음을
   반복한다.
  0. `G[rhead][x] > 0` 이면 `G[whead--][x] = G[rhead][x]`
2. `whead >= 0` 이면 나머지 값들은 `0` 으로 채워도 된다.

# Implementation

* [c++11](a.cpp)
* [java11](MainApp.java)

# Complexity

```
O(HW) O(1)
```
