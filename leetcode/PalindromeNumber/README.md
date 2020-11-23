# Problem

[Palindrome Number](https://leetcode.com/problems/palindrome-number/)

# Idea

숫자 `x` 가 주어진다. `x` 가 palindrome 인지 검증하는 문제이다.

`x < 0` 이면 `-` 로 시작하므로 palindrome 이 아니다.  `x != 0 && x %
10 == 0` 이면 `0` 으로 끝나기 때문에 palindrome 이 아니다.

`x` 를 뒤집은 수 `y` 를 만들어 둘이 같으면 palindrome 이다. 이때 `x`
의 왼쪽에서 반 만큼만 뒤집어서 `y` 에 저장하면 시간복잡도를 더욱 낮출
수 있다. 만약 `x` 가 홀 수 이면 `x == y / 10` 를 검사한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(X) O(1)
```
