# Problem

[Check If Two Expression Trees are Equivalent](https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/)

tree root node `u, v` 가 주어진다. tree 는 binary exrpession tree
이다. `u, v` 의 결과가 같은지 검증하라.

# Idea

tree 의 operator 는 `+, -` 이고 operands 는 `[a-z]` 이다.  `+` 를
부모로 하는 alphabet 은 개수를 늘리고 `-` 를 부모로 하는 alphabet 은
개수를 줄여보자.

`u, v` 를 각각 DFS 수행하고 alphabet 개수를 비교해보자.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
