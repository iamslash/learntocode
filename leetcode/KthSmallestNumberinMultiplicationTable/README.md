# Problem

* [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)

# Idea

숫자 `m, n, k` 가 주어진다. `m X n` 으로 곱셈 테이블을 만들었을 때 `k`
번째 수를 구하는 문제이다.

예를 들어 `3 x 3` 으로 만들 수 있는 곱셈 테이블은 다음과 같다.

```
  1 2 3
1 1 2 3
2 2 4 6
3 3 6 9
```

`k = 5` 이면 답은 `3 (1, 2, 2, 3, 3, ...)` 이다.

binary search 를 이용하여 해결한다.

다음은 `m = 3, n = 3, k = 5` 일때 풀이과정이다.

```
 lo:  1 1 1 3
 hi: 10 5 3 3
 mi:  5 3 2
cnt:  6 5 3
```

`cnt` 는 `mi` 보다 작거나 같은 수가 몇개인지를 의미한다.
예를 들어 `mi = 4` 이면 `cnt = 5 (1, 2, 2, 3, 4)` 이다.

`k > cnt` 이면 `lo = mi + 1` 이다.
`k <= cnt` 이면 `hi = mi` 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
