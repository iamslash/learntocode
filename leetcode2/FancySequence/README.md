# Problem

[Fancy Sequence](https://leetcode.com/problems/fancy-sequence/)

# Idea

이 문제는 [partial sum](/fundamentals/partialsum/partialsum/README.md), [modular multiplicative
inverse](/fundamentals/numbertheory/modulararithmatic/README.md) 를
이해해야 풀 수 있다.

`uint64_ inc = 0` 를 선언하여 `addAll(a)` 를 호출할 때 마다 `inc += a` 를
수행한다.  이때 수가 클 수 있으니 `inc = (inc + a % MOD) % MOD` 를 수행한다.

`uint64_ mul = 1` 를 선언하여 `multAll(a)` 를 호출할 때 마다 `inc *= a` 를
수행한다.  이때 수가 클 수 있으니 `mul = (mul * a % MOD) % MOD` 를 수행한다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
getIndex: O(1) O(N)
```
