# Problem

[String Without AAA or BBB](https://leetcode.com/problems/string-without-aaa-or-bbb/)

# Idea

두개의 숫자 `A, B` 가 주어진다. `aaa` 혹은 `bbb` 가 발생하지 않도록
`a` 는 `A` 개, `b` 는 `B` 개가 되는 문자열을 구하는 문제이다.

greedy algorithm 으로 해결해본다. 먼저 큰 수에 해당하는 문자를 두개
사용하고 작은 수에 해당하는 문자를 한개 사용한다. 만약 두수가 같아지면
서로 한개씩 사용하는 방식으로 풀어본다.

일단 `A, B` 중 큰 수를 `X` 라고 하고 해당 문자를 `x` 라고 하자.
한편 `A, B` 중 작은 것을 `Y` 라고 하자 해당 문자를 `y` 라고 하자. 

`X > 0` 인 동안 `X` 를 하나씩 감소하면서 다음을 반복한다.

* `ans += x`
* `X > Y` 이면 `ans += x`
* `Y > 0` 이면 `ans += y`

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(A+B) O(A+B)
```
