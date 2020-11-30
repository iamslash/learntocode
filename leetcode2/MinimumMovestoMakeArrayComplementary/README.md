# Problem

[Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)

짝수개의 수열 `nums[]` 와 숫자 `limit` 이 주어진다. `nums[]` 의 임의의
숫자를 `[1..limit]` 의 숫자로 교체할 수 있다.  `nums[]` 를
complementary 로 만들기 위한 최소 교체수를 구하라.

`A[]` 가 complementary 하다는 의미는 다음과 같다.

* 가능한 `i` 에 대하여 `A[i] + A[n-1-i]` 가 모두 같다.

예를 들어, `A = [1, 2, 3, 4]` 는 `1 + 4 = 5, 2 + 3 = 5` 이기 때문에
`A` 는 complementary 하다.

# Idea

too difficult

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(max(N, K)) O(K)
```
