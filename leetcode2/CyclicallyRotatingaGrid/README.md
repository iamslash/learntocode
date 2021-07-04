# Problem

[Cyclically Rotating a Grid](https://leetcode.com/problems/cyclically-rotating-a-grid/)

이차원 배열 `grid[][]`, 숫자 `k` 가 주어진다. `grid[][]` 의 모든
숫자를 반 시계 방향으로 `k` 만큼 회전한 결과를 구하라.

# Idea

예를 들어 다음과 같은 경우를 살펴보자.

```
1   2  3  4
16  1  2  5
15  8  3  6
14  7  4  7
13  6  5  8
12 11 10  9
```

이 것을 반 시계 방향으로 한번 회전해 보자.

```
 2  3  4  5
 1  2  3  6
16  1  4  7
15  8  5  8
14  7  6  9
13 12 11 10
```

`grid[][]` 를 구성하는 층을 layer 라고 하자. 그렇다면 
layer 의 개수는 다음과 같이 구할 수 있다.

```
     h: 6
     w: 4
layers: 2 min(4,6)/2
```

또한 layer 를 구성하는 원소들의 개수는 다음과 같이 구할 수 있다.

```
     h: 6
     w: 4
cnt of elements in the layer
      : (h-1 - 2*i + w-1 - 2*i) * 2
```

이제 인덱스 i 를 이용하여 `[0..layers)` 동안 layers 를 순회한다.  `int
t = grid[i][i]` 를 선언하여 각 layer 의 left top 숫자를 저장한다.

layer 를 구성하는 숫자들을 top, right, bottom, left line 으로 나눌 수
있다.

각 line 을 다시 순회하며 한 칸씩 회전한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(HW) O(1)
```
