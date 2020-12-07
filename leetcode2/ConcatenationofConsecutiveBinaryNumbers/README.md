# Problem

[Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)

숫자 `n` 이 주어진다. `[1..n]` 의 숫자를 이진수 형태로 이어 붙여서
만든 숫자를 구하라.

예를 들어 `n = 3` 이면 이진수 형태로 이어 붙여진 수는 `1,10,11` 이
합하여 `11011` 이다. 따라서 답은 `27` 이다.

# Idea

`f(n)` 를 숫자 `n` 에 대한 답이라고 해보자. 다음과 같은
점화식을 발견할 수 있다.

```

f(0): 0
f(1): 1        (f(0) << 1) + 1  len(1): 1
f(2): 110      (f(1) << 2) + 2  len(2): 2
f(3): 11011    (f(2) << 2) + 3  len(3): 2
...
f(n): (f(n-1) << len(n)) + n
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
