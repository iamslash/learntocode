# Problem

[Minimum Possible Integer After at Most K Adjacent Swaps On Digits](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/)

문자열 `s`, 숫자 `k` 가 주어진다. 연속된 두 숫자를 `k` 번 교체할 수
있다.  가장 최소의 수를 구하라.

# Idea

bubble sort 와 유사하다. `s.size()` 를 `n` 이라고 해보자.
`k >= n*(n+1)/2` 이면 `s` 를 bubble sort 하여 오름차순으로 
정렬할 수 있다. 그리고 그 결과가 곧 답이된다.

그렇지 않으면 `[0..9]` 중 `s` 에 존재하는 최소 숫자를 맨 앞으로
위치하고 `k` 를 줄여가면서 재귀적으로 해결한다.

# Implementation

* [py3](a.py)

# Complexity

```
O(NlgN) O(N)
```
