# Problem

[Uncrossed Lines @ leetcode](https://leetcode.com/problems/uncrossed-lines/)

# Idea

두개의 수열 `A[], B[]` 가 주어진다. subsequences 중 서로 공통이고 길이가
최대인 것의 길이를 구하는 문제이다. `A, B` 의 길이를 각각 `H, W` 라고 하자.

2D 캐시 `C[][]` 를 사용하여 dynamic programming 으로 해결한다.

예를 들어 `A[] = (1, 4, 2), B[] = (1, 2, 4)` 의 경우를
살펴보자.

```
  0 1 2 4 
0 0 0 0 0 
1 0 1 1 1 
4 0 1 1 2 
2 0 1 2 2 
```

다음과 같은 규칙을 발견할 수 있다.

* `A[i] == B[j]` 일 때 `C[i][j] = max(C[i][j-1], C[i-1][j], C[i-1][j-1] + 1)` 임을 알 수 있다.
* `A[i] != B[j]` 일 때 `C[i][j] = max(C[i][j-1], C[i-1][j], C[i-1][j-1] + 0)` 임을 알 수 있다.

캐시가 모두 완성되면 `C[H-1][W-1]` 가 답이다.

캐시가 갱신되는 과정을 살펴보면 2 행만을 사용하는 것을 발견할 수
있다. 따라서 1D 캐시로 구현하면 공간복잡도를 낮출 수 있다.

# Implementation

* [c++11](/leetcode/UncrossedLines/a.cpp)

# Complexity

```
O(HW) O(W)
```

# See Also

* [Max Dot Product of Two Subsequences @ leetcode](/leetcode2/MaxDotProductofTwoSubsequences/README.md)
