# Problem

* [Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/)

# Idea

`L,R,X` 로 이루어진 문자열 `S, E` 가 주어진다. `XL->LX, RX->XR` 
로 변환 가능하다고 할 때 `S->E` 가 가능한지 검증하는 문제이다.

`S` 의 문자 `L` 은 왼쪽으로 자리이동할 수 있고
`S` 의 문자 `R` 은 오른쪽으로 자리이동할 수 있다.

인덱스 `i, j` 를 이용하여 다음을 반복한다.

1. `S[i] != 'X' && E[j] != 'X'` 일때 `S[i] != E[j]` 이면 거짓이다.
2. `S[i] != `X` && E[j] != 'X'` 이고 `S[i] == 'L'` 이면 `i > j` 이어야 한다.
2. `S[i] != `X` && E[j] != 'X'` 이고 `S[i] == 'R'` 이면 `i < j` 이어야 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```