# Problem

[Count Sub Islands](https://leetcode.com/problems/count-sub-islands/)

이차원 배열 `A[], B[]` 가 주어진다. `A[]` 의 섬을 구성하는 모든 cell
이 `B[]` 의 섬을 구성하는 모든 cell 을 포함한다면 sub-island 가
존재한다고 하자. sub-island 의 개수를 구하라.

# Idea

예를 들어 다음과 같은 경우를 살펴보자.

```
A:          B:
1 1 1 0 0   1 1 1 0 0
0 1 1 1 1   0 0 1 1 1
0 0 0 0 0   0 1 0 0 0
1 0 0 0 0   1 0 1 1 0
1 1 0 1 1   0 1 0 1 0
```

`A[y][x] == 0` 이면 `B[y][x] == 1` 이라고 하더라도
sub-island 의 조건에 해당하지 않는다. `B[y][x]` 를
시작으로 DFS 하여 모든 cell 을 `0` 으로 채운다.

```
A:          B:
1 1 1 0 0   1 1 1 0 0
0 1 1 1 1   0 0 1 1 1
0 0 0 0 0   0 0 0 0 0
1 0 0 0 0   1 0 0 0 0
1 1 0 1 1   0 1 0 0 0
```

그리고 `B[]` 의 island 의 개수가 곧 답이다.

# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(HW) O(1)
```
