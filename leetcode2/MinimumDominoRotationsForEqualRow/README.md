# Problem

[Minimum Domino Rotations For Equal Row](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/)

수열 `A[], B[]` 가 주어진다. `A[i], B[i]` 는 주사위의 눈을 의미하는
`[1..6]` 이 저장되어 있다. `A[0..n)` 혹은 `B[0..n)]` 의 주사위 숫자가
모두 같도록 `A[i]` 와 `B[i]` 를 교체해보자. 최소 교체 횟수를 구하라.
만약 불가능하다면 `-1` 을 리턴하라.

# Idea

`cntA[6], cntB[6]` 을 선언하여 `{dice number: cnt}` 를 저장한다.
`same[]` 를 선언하여 `A[i], B[i]` 가 같다면 `same[A[i]-1]` 에
저장한다.

`cntA[], cntB[], sam[]` 가 모두 채워지면 인덱스 `i` 를 이용하여
`[0..6)` 을 순회하며 다음을 반복한다.

* `n == cntA[i] + cntB[i] - same[i]` 이면 한 행을 같은 숫자 `i+1` 로 배치할 수
  있다. `n - max(cntA[i], cntB[i])` 를 리턴하라.

모든 반복을 마치면 -1 을 리턴한다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
