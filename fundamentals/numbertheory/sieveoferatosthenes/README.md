# Abstract

에라토스테네스의 체에 대해 적는다.

# Problem

숫자 `n` 이 주어지면 `[1..n]` 의 숫자들중 소수들을 구하는 문제이다.

# Idea

에라토스테네스의 체는 `2` 부터 `n` 까지의 숫자들 중 소수를 찾는 알고리즘이다.  `2` 부터 `sqrt(n)` 까지 숫자들을 하나씩 순회하자.  각 숫자들의 배수들을 제거하면 남은 숫자들은 소수가 된다.

이해를 돕기 위해 합성수를 `c = p * q (p <= q)` 로 표현해 보자. `c` 는 composite number, `p` 는 prime number 를 의미한다. 한 마디로 합성수는 `p` 의 배수이다.

예를 들어, `c == 100` 일 때, `p == 10` 이면 `q == 10` 이다. `p == 20` 이면 `q == 5` 이다. 그러나 `p <= q` 이므로 `20 * 5` 는 `5 * 20` 에서 이미 처리되었다.

인덱스 `p` 를 선언한다. 이제 `p` 의 배수인 `c` 를 찾는다.  즉, `c = p * q (p <= q)` 이다. `c` 는 `p * p` 부터 시작한다. `p <= q` 를 만족하는 가장 작은 합성수이기 때문이다. `c` 에 `p` 를 계속 더한다. `c` 는 항상 `p` 의 배수이다. 소수가 아니라고 기록하자.

```java
        // c = p * q (p <= q)
        // p <= sqrt(n)
        // p * p <= n
        for (int p = 2; p * p <= n; ++p) {
            if (!primes[p]) {
                continue;
            }
            // c = p * q (p <= q) 
            // c = p * p, p * p + p, p * p + 2p, p * p + 3p, etc...
            for (int c = p * p; c <= n; c += p) {
                primes[c] = false;
            }
        }
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(sqrt(N)N) O(N)
```
