# Abstract

소인수 분해에 대해 적어본다.

# Problem

숫자 `n` 이 주어지면 소인수분해를 구하는 문제이다.

# Idea

특정 숫자 `n` 을 `p x q` 로 표현해 보자. 이때 `p` 는 소수이고 `p <= q` 이다. `p`
의 후보는 `2` 부터 `sqrt(n)` 까지의 소수들이다. `p` 는 `2` 이후로 짝수가 될 수
없다. `p`가 `2` 일때 이미 소인수 분해 되어 버리기 때문이다.

# Implementation

* [c++11](a.cpp)

# complexity

```
O(sqrt(N)) O(N)
```
