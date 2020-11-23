# Problem

[Find All Good Strings](https://leetcode.com/problems/find-all-good-strings/)

숫자 `n`, 문자열 `a, b, evil` 이 주어진다.  사전순으로 `a` 보다 크거나
같고 `b` 보다 작거나 같고 `evil` 은 포함되지 않은 문자열의 개수를
구하라.

# Idea

문자열 검색을 빠르게 하기 위해 [KMP Partial Index](/fundamentals/string/kmppikmp/README.md) 를 이용한다.

매우 어렵다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NM) O(NM)
```
