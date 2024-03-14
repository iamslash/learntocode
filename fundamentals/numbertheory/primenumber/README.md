# Abstract

1 과 자신을 제외한 숫자로 나누어 떨어지지 않는 숫자를 소수 `(prime number)` 라고 한다.

# Problem

숫자 `n` 이 주어지면 소수인지 검증하는 문제이다.

# Idea

이해를 돕기 위해 합성수를 `c = p * q (p <= q)` 로 표현해 보자. `c` 는 composite number, `p` 는 prime number 를 의미한다. 한 마디로 합성수는 `p` 의 배수이다.

예를 들어, `c == 100` 일 때, `p == 10` 이면 `q == 10` 이다. `p == 20` 이면 `q == 5` 이다. 그러나 `p <= q` 이므로 `10 * 5` 는 `5 * 10` 에서 이미 처리되었다.

- `n == 1` 이면 `return false` 한다.
- `n == 2` 이면 `return true` 한다.
- `3 <= p <= sqrt(n)` 동안 다음을 반복한다.
  - `n % p == 0` 이면 `return false` 수행한다.
  - `n % p != 0` 이면 `p += 2` 수행한다.

# Implementation

- [c++11](a.cpp)
- [java](MainApp.java)

# Complexity

```
O(sqrt(n)) O(1)
```
