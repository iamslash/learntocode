# Problem

[Find Latest Group of Size M](https://leetcode.com/problems/find-latest-group-of-size-m/)

수열 `A[]`, 숫자 `m` 이 주어진다. 길이가 `A[]` 의 길이와 같고 `0`
으로만 구성된 수열이 있다. `A[i]` 번째 비트를 `1` 로 바꾸자. 연속된
`1` 의 개수가 `m` 이 될때의 `i` 를 구하라. `i` 는 가장 큰 값이어야
한다.

# Idea

`lengths := make([]int, n+2)` 를 선언하고 `A[i]` 를 포함한 연속된 1 의
길이를 저장한다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
