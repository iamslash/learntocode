# Problem

[Number of Sets of K Non-Overlapping Line Segments](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)

숫자 `n, k` 가 주어진다. 1-D plane 에 `[0..n-1]` 의 점이 존재한다.
`k` 개의 겹치지 않는 직선을 선택하는 경우의 수를 구하라. 이때 직선은
양끝이 겹칠 수 있다.

# Idea

`[0..n-1]` 의 점들을 선택하는 문제이다. combination 의 냄새가 난다.
이것은 `[0..n + k - 1]` 의 점들에서 `2k` 개의 점을 선택하는 것과 같다.
즉 `n+k-1 C 2k` 이다.

# Implementation

* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(K) O(1)
```
