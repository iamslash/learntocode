# Problem

> [Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/)

좌표들의 모음 `P[][]` 가 주어지면 점 4 개를 선택하여 만들 수 있는
사각형들 중 가장 넓이가 적은 것의 크기를 구하는 문제이다.

# Idea

문제를 잘 읽어봐야 한다. 모든 점을 포함하는 사각형의 넓이가 아니고 4
개의 점을 선택하여 만들 수 있는 최소 크기의 사각형의 넓이를 구하는
것이다.

예를 들어 다음과 같이 6 개의 점이 있다고 해보자.

```
  c   b
  . 
  a . d
0 
```

가장 먼저 `a` 와 `b` 를 선택한다. 그리고 `a` 와 `x` 가 같고 `b` 와 `y`
가 같은 `c` 가 있는지 검사한다. 그리고 `a` 와 `y` 가 같고 `b` 와 `x`
가 같은 `d` 가 있는지 검사한다. 이와 같이 `a, b, c, d` 를 찾으면
사각형을 구성할 수 있다.  넓이를 계산한다. `c, d` 를 빨리 찾기 위해
`Map<Integer, Set<Integer>>` 를 이용한다.

이제 다음과 같이 풀어보자.

한 점을 `(x, y)` 로 표기할 수 있다. `Map<Integer, Set<Integer>>
rectMap` 를 선언하여 `x` 를 키로 `y` 를 값들로 저장하자.

`int ans = Integer.MAX_VALUE` 를 선언하여 최소 넓이를 저장한다.

`int[] a` 으로 `points` 를 순회하며 다음을 반복한다.

* `int[] b` 으로 `points` 를 순회하며 다음을 반복한다.
  * `a[0] == b[0] || a[1] == b[1]` 이 같으면 건너뛴다. 앞서 언급한
    것처럼 하나의 사각형을 구성하는 `a, b` 가 아니기 때문이다.
  * `rectMap.get(a[0]).contains(b[1]) &&
    rectMap.get(b[0]).contains(a[1])` 이면 사각형을 구성하는 `a, b, c,
    d` 를 찾은 것이다. `ans` 를 업데이트 한다. 즉, `ans = min(ans,
    abs(a[0]-b[0]) * abs(a[1]-b[1]))` 를 수행한다.

모든 반복을 마치면 `ans == Integer.MAX_VALUE` 이면 0 이 답이다. 그렇지
않으면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
