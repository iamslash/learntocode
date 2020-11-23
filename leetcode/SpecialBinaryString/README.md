# Problem

* [Special Binary String](https://leetcode.com/problems/special-binary-string/)

# Idea

`1, 0` 로 구성된 문자열 `s` 이 주어지면 special binary string 조건을 가진
부분 문자열들의 위치를 서로 바꾸어 사전순으로 가장 큰 문자열을 구하는
문제이다.

`1, 0` 은 `(, )` 으로 바꾸어 생각해도 된다. 가장 작은 수의 문자열부터
생각해보자.

`10` 은 이미 사전순으로 가장 큰 special binary string 이다.

`1010` 도 마찬가지이다. `0` 과 `1` 을 바꾸어 `1100` 을 생성하면 답이
될 것 같지만 `0` 과 `1` 은 special binary string 이 아니다.

`101100` 을 살펴보자. `10` 과 `1100` 을 바꾸면 `110010` 을 생성할 수 있고
사전순으로 가장 큰 문자열이 된다.

`s` 를 처음부터 순회하면서 부분 special binary string 들로
분리한다. 그리고 그 부분문자열들을 사전순으로 정렬하고 다시 하나의
문자열로 합하면 답이된다.  이때 부분 special binary string 들은 다시
재귀적으로 사전순으로 가장 큰 special binary string 으로 교체한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
