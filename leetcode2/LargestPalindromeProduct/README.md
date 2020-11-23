# Problem

[Largest Palindrome Product](https://leetcode.com/problems/largest-palindrome-product/)

숫자 `n` 이 주어진다. `n` 자리의 숫자 두개를 곱해서 palindrome 이 되는
것을 찾아라. 이때 그 값은 매우 크기 때문에 `1337` 로 나눈 나머지를
구하라.

# Idea

두자리의 숫자 이어야 하므로 큰 수는 `upper = pow(10, n) - 1` 이고
작은 수는 `lower = pow(10, n-1)` 이다.

인덱스 `i` 를 이용하여 `[upper..lower]` 를 순회하며 다음을 반복한다.

* palindrome 의 후보 `candidate = i + reverse(i)` 를 만들자. 
* 인덱스 `j` 를 이용하여 `j = upper` 로 시작하여 `j*j >= cand` 일 동안 다음을 반복한다.
  * `cand % j == 0` 이고 `cand / j <= upper` 이면 `cand % 1337` 을
    리턴한다. `i, j` 가 아니고 `candidate` 을 찾는 것이 목적임을
    기억하자.
  * `j` 를 하나 감소한다.
* `i` 를 하나 감소한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
