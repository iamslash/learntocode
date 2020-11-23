# Problem

[Super Pow](https://leetcode.com/problems/super-pow/)

# Idea

숫자 `a` 와 수열 `b[]` 가 주어진다. `a^b % 1337` 를 구하는 문제이다.

mod 연산은 다음의 법칙이
성립한다. [참고](/fundamentals/numbertheory/modulararithmatic/README.md)

```
(a * b) % m = ((a % m) * (b % m)) % m
(c ^ d) % m = ((c % m) * (c % m) * ... * (c % m)) % m 
```

따라서 `b` 의 끝에서 부터 숫자를 하나씩 꺼내오면서 mod 연산의
분배법칙을 활용하면 재귀적으로 계산할 수 있다.

```
// ab % k = (a%k)(b%k)%k
// a^123 % k =                           (a^120 % k) * (a^3 % k) % k
//           =                     (a^12 % k)^10 % k * (a^3 % k) % k
//           =       ((a^10 % k) * (a^2 % k))^10 % k * (a^3 % k) % k
//           = ((a^1 % k)^10 % k * (a^2 % k))^10 % k * (a^3 % k) % k
```

`(a ^ k) % m` 을 `powk(a, k)` 이라고 정의하면 `superPow(a, b[])` 는
다음과 같이 부분문제를 이용하여 표현할 수 있다.

```
superPow(a, b[]) = powk(superPow(a, b[:-1]), 10) * powk(a, b[-1]) 
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
