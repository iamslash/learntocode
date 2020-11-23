# Problem

[Smallest Integer Divisible by K](https://leetcode.com/problems/smallest-integer-divisible-by-k/)

# References

* [java 1ms modular solution with explanation @ leetcode](https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/275896/java-1ms-modular-solution-with-explanation)

# Idea

숫자 `K` 가 주어진다. `N` 은 `1` 로만 구성된 숫지이다. `K` 로 나누어
떨어지는 수 중 가장 작은 `N` 의 자리의 개수를 구하는 문제이다.

먼저 `1` 로만 구성된 숫자들을 나열해 보자.

```
   1 =   1 * 0  + 1
  11 =   1 * 10 + 1
 111 =  11 * 10 + 1
1111 = 111 * 10 + 1
```

위를 통해 자리수가 하나 증가한 `N` 은 `N = (N * 10) + 1` 을 통해 구할
수 있다. 한편 다음을 통해 이전의 `N` 대신 `N % K` 를 사용해도 됨을 알
수 있다.

```
N % K = ((N * 10) + 1) % K
      = ((N % K) * (10 % K) + 1 % K) % K
```

또한 `N` 의 자리수를 `cnt` 라고 할 때 `cnt > K` 인 경우는
이미 계산한 셈이 되므로 `cnt <= K` 인 동안만 반복해도 된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(K) O(1)
```
