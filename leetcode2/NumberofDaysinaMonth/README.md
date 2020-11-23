# Problem

[Number of Days in a Month](https://leetcode.com/problems/number-of-days-in-a-month/)

# Idea

숫자 `Y`, `M` 가 주어진다. `Y` 년도 `M` 월은 몇일로 구성되어 있는지
구하는 문제이다.

각 월의 구성일은 다음과 같다.

```
[31, 28, 31, 30, 31, 30, 31, 31, 30, 31,
 30, 31]
```

2 월이 문제이다. 다음과 같은 수식으로 윤년인 경우 2 월은 29 일이다.
그렇지 않으면 28 일이다.

```
(Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0)
```

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
