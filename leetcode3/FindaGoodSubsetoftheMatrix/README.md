# Problem

[Find a Good Subset of the Matrix](https://leetcode.com/problems/find-a-good-subset-of-the-matrix/)

이차원 배열 `grid[][]` 가 주어진다. 임의의 행을 고른다.  그 개수를 `k`
라고 하자. 고른 행들의 열끼리 더해본다.  그 합이 최대 `k` 를
넘지않아야 한다. 고른 행들을 구하라.

# Idea

예를 들어 `grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]` 의
경우를 살펴보자.

```
0 1 1 0    *
0 0 0 1    *
1 1 1 1


k = 2, k/2 = 1
```

따라서 답은 `[0, 1]` 이다. 

답의 후보는 `k` 가 `1, 2` 뿐이다.  `k` 가 `3` 보다 크거나 같을 때의
답은 `k` 가 `1, 2` 일 때의 답을 포함한다. 즉, `k == 1` 을 만족하는
답이 있는 점검하고 `k == 2` 를 만족하는 답이 있는지 점검한다.  그 외의
경우는 `k == 0` 이다.

이 것을 수학적으로 어떻게 증명해야 할까?

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(H^2W) O(1)
```
