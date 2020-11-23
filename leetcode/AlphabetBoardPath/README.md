# Problem

[Alphabet Board Path](https://leetcode.com/problems/alphabet-board-path/)

# Idea

문자열 `s` 가 주어진다. 다음과 같은 보드의 `0, 0` 부터 출발하여 `s` 를
완성해 보자. `s` 를 완성했을 때 탐색한 방향문자 `D, U, L, R, !` 모음을
구하는 문제이다.

```
a b c d e 
f g h i j
k l m n o
p q r s t
u v w x y
z
```

manhatan distance 를 이용하면 최단 거리를 구할 수 있다.
예를 들어 `s = ah` 일 때 탐색해 보자.

* 목적지 `a` 는 `v = (0, 0)` 이다. 현재 위치는 `u = (0, 0)`
  이다. 거리는 `d = (0, 0)` 이다. `!` 를 `ans` 에 추가한다.
* 목적지 `h` 는 `v = (1, 2)` 이다. 현재 위치는 `u = (0, 0)`
  이다. 거리는 `d = (1, 2)` 이다. `DRR!` 를 `ans` 에 추가한다.
  
이때 `z` 를 유의해야 한다. 임의의 위치에서 `z` 까지 가려면 왼쪽으로
먼저 따져보고 아래쪽으로 따져봐야 한다. 그래야 `z` 의 오른쪽 4 칸에
방문하지 않게 된다. 또한 `z` 에서 다른 문자를 탐색할 때는 위로
따져보고 오른쪽 혹은 왼쪽을 따져 보아야 한다.

따라서 따져보야할 방향의 우선순위는 `U, R, L, D` 이다.

# Implementation

[c++11](a.cpp)

# Complexity

```
O(S) O(S)
```
