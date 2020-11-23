# Problem

* [Maximum Swap](https://leetcode.com/problems/maximum-swap/)

# Idea

숫자 `n` 이 주어지면 두개의 숫자를 골라서 뒤바꿨을 때
가장 최대가 되는 수를 찾는 문제이다.

숫자 `n` 을 문자열 `s` 로 전환한다. 다음과 같이 인덱스 `i` 를 이용하여
오른쪽 끝에서 왼쪽으로 순회하면서 인덱스 `l, r` 을 갱신한다. 인덱스
`m` 는 `s[i]` 가 최대일 때의 인덱스이다.

```
// l
//       r
//       m
// i
// 10909091
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```

