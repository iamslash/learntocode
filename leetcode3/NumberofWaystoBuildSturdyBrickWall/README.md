# Problem

[Number of Ways to Build Sturdy Brick Wall](https://leetcode.com/problems/number-of-ways-to-build-sturdy-brick-wall/submissions/)

숫자 `height, width`, 수열 `bricks[]` 가 주어진다.  `bricks[i]` 는
높이가 `1`, 넓이가 `bricks[i]` 인 벽돌을 표현한다.  `bricks[i]` 는
무한히 있다. 높이가 `height`, 넓이가 `width` 인 벽을 벽돌로 가득
채우자. 

단, 인접한 줄에 놓여진 벽돌들을 비교했을 때 모든 벽돌들의 위치는 서로
엇갈려야 한다. 예를 들어 `height = 2, width = 3, bricks = [1,2]` 인
경우 다음과 같은 경우는 피해야 한다.

```
1: the block width is 1
b: the block width is 2

bba
bba
```

벽을 가득채울 수 있는 경우의 수를 구하라.

# Idea

예를 들어 `height = 2, width = 3, bricks = [1,2]` 의 경우를 살펴보자.

```
a: bricks[0]
b: bricks[1]

bba    ab    bba
abb    ba    bba
```

따라서 답은 `2` 이다.

벽돌이 높여진 상황은 bitmask 로 표현가능하다. 예를 들어 `aab` 의
경우를 살펴보자.

```
aa. == 010
..b == 100
aab == aa. | ..b == 110

aa.   == 00010
..b   == 00100
...cc == 10000
aab == aa. | ..b | ...cc == 10110
```

인접한 줄에 놓인 벽돌들을 비교했을 때 모든 벽돌들의 위치가 서로 엇갈리기 위해서는
Bitwise AND 의 결과가 `0` 이어야 한다.

```
curLine = 10110
prvLine = 10110
curLine & prvLine = 10110 > 0


curLine = 01001
prvLine = 10110
curLine & prvLine = 00000
```

`int[][] C` 를 선언하여 `C[h][prvBm]` 에 경우의 수를 저장한다.
[recursive dynamic programming]() 으로 해결할 만 하다.

다음과 같은 부분문제를 정의한다.

```
int dfs(C, h, w, bricks, curBm, curWidth, prvBm)

return: 경우의 수
     h: input
     w: input
bricks: input
 curBm: 이번 줄에 놓인 벽돌들의 위치를 표현한 bitmask
curWidth: 이번줄에 놓인 마지막 벽돌의 위치 
 prvBm: 이전 줄에 놓인 벽돌들의 위치를 표현한 bitmask
```

`curBm == 0` 일 때만 `C[][]` 에 답을 저장한다. `curBm > 0` 의 경우는
이번줄을 다 채우지 못한 경우이기 때문에 `C[][]` 에 저장할 필요가 없다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(HW) O(HW)
H: height of the wall
W: bitmask of width
```
