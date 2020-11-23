# Problem

[Maximum Length of Repeated Subarray @ leetcode](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

# Idea

두개의 수열 `A[], B[]` 가 주어진다. 연속된 부분수열들 중 서로 공통이고
길이가 최대인 것의 길이를 구하는 문제이다.

2D 캐시 `C[][]` 를 사용하여 dynamic programming 으로 해결한다.

예를 들어 `A[] = (3, 2, 1, 4, 7), B[] = (1, 2, 3, 2, 1)` 의 경우를
살펴보자.

```
  0 1 2 3 2 1
0 0 0 0 0 0 0
3 0 0 0 1 0 0
2 0 0 1 0 2 0
1 0 1 0 0 0 3
4 0 0 0 0 0 0
7 0 0 0 0 0 0
```

* `C[1][3]` 를 살펴보자. `A[0] == B[2] == 3` 이다. `C[1][3] =
  C[0][2] + 1 = 1` 이다. 그리고 `ans = max(ans, C[1][3])` 을 수행하여
  `ans` 를 갱신한다.
* `C[2][4]` 를 살펴보자. `A[1] == B[3] == 2` 이다. `C[2][4] =
  C[1][3] + 1 = 2` 이다. 그리고 `ans = max(ans, C[2][4])` 을 수행하여
  `ans` 를 갱신한다.
* 앞서 언급한 두 규칙을 이용하여 `A[i] == B[j]` 일 때 `C[i+1][j+1] =
  C[i][j] + 1` 임을 알 수 있다. 그리고 `ans = max(ans, C[i+1][j+1]` 을
  수행하여 `ans` 를 갱신해야 한다.

캐시가 모두 완성되면 `ans` 가 답이다.

캐시가 갱신되는 과정을 살펴보면 2 행만을 사용하는 것을 발견할 수
있다. 따라서 1D 캐시로 구현하면 공간복잡도를 낮출 수 있다.

# Implementation

* [c++11](/leetcode/MaximumLengthofRepeatedSubarray/a.cpp)

# Complexity

```
O(AB) O(A)
```
