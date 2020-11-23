# Problem

[Minimum Factorization](https://leetcode.com/problems/minimum-factorization/)

# Idea

숫자 `q` 가 주어진다. 자리수의 숫자를 각각 모두 곱하였을 때 `q` 가
되는 최소의 숫자 `r` 을 구하는 문제이다. 이때 `r` 은 32-bit signed
integer 를 넘지 않는다.

`r` 을 한자리 숫자로 인수분해 하는 문제이다. 그리고 숫자를 하나씩
만들어서 `r` 에 추가해야 하기 때문에 정수 `d` 를 선언하여 `0` 부터
하나씩 늘리자. `d < 0` 이어야 한다.

최소의 `r` 을 구해야 하기 때문에 숫자 `p` 를 `[9..2]` 와 같이
내림차순으로 순회한다. `q % p == 0` 인 `p` 를 찾아서 `r` 에 자리숫를
조정해 가면서 추가한다. 이때 `p` 는 두개이상일 수 있다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(1)
```
