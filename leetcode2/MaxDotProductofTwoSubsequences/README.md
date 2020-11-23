# Problem

[Max Dot Product of Two Subsequences](https://leetcode.com/problems/max-dot-product-of-two-subsequences/)

수열 `A[], B[]` 이 주어진다. `A[]` 의 subsequence 들과 `B[]` 의
subsequence 들의 dot product 연산의 결과값 들중 최대값을 구하라.

# Idea

예를 들어, `A = [2, 1, -2, 5], B = [3, 0, -6]` 의 경우를 살펴보자.

```
...
[2, -2] dot [3, 0]  = 6
[2, -2] dot [3, -6] = 18
...
```

따라서 답은 18 이다.

`A[]` 의 길이를 `n`, `B[]` 의 길이를 `m` 이라고 하자.  캐시
`vector<vector<int>> C(n, vector<int>(m))` 을 선언한다.  `C[i][j]` 에
`A[..i] dot B[..j]` 의 최대값을 저장한다.

다음과 같이 모든 경우의 수를 생각해 보자.

* `A[i]*B[j]` 가 dot product 에 포함되는 경우
* `A[i]*B[j]` 만 dot product 에 포함되거나 `A[i]` 포함되지 않는 경우
* `A[i]*B[j]` 만 dot product 에 포함되거나 `B[i]` 포함되지 않는 경우

```
i = latest index of A[]
j = latest index of B[]

C[i][j] = C[i-1][j-1] + A[i]*B[j]    : include A[i],B[j]
C[i][j] = max(A[i]*B[j], C[i-1][j])  : exclude A[i] or just A[i]*B[j]
C[i][j] = max(A[i]*B[j], C[i][j-1]): exclude B[j] or just A[i]*B[j]
```

모든 반복을 마치면 `C[n-1][m-1]` 이 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(AB) O(AB)
```
