# Problem

[Longest Arithmetic Sequence](https://leetcode.com/problems/longest-arithmetic-sequence/)

# Idea

수열 `A[]` 가 주어진다. 각 간격이 동일한 subsequence 의 개수를 구하는
문제이다.

임의의 `i < j < k` 에 대하여 세 수 `A[i], A[j], A[k]` 의 
간격이 모두 동일하다고 하면 다음의 식이 성립한다.

```
A[j] - A[i] == A[k] - A[j]

        A[i] = 2 * A[j] - A[k]
```

캐시 `C[][]` 를 선언하여 `C[j][k]` 에 간격이 `d` 인 개수를 저장한다.
또한 `C[j][k] = C[i][j] + 1` 임을 알 수 있다. 

우리는 앞서 언급한 수식에서 `A[j], A[k]` 를 알면 동일한 간격의 이전 수
`A[i]` 곧 `prv` 을 구할 수 있었다. 이때 또 다른 캐시 `pos[]` 를
선언하여 `{value, index}` 를 저장한다. 그렇다면 `pos[prv]` 가 곧 `i`
이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
