# Problem

[Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)

수열 `A[]` 와 숫자 `k` 가 주어진다. `k` 만큼의 윈도우가 `A[]` 의
처음부터 끝까지 이동한다. 이동할 때 마다 `median` 을 구한다. `median`
의 모음을 구하라.

# Idea

two heap 을 이용해서 해결할 수 있다. `multiset<int> minSet` 을
선언하여 median 보다 작은 값들을 저장한다. `multiset<int> maxSet` 을
선언하여 median 보다 크거나 같은 값들을 저장한다.

`k` 가 홀수이면 `*maxSet.begin()` 가 median 이다. `k` 가 짝수이면
`(*minSet.rbegin() + *maxSet.begin()) / 2` 가 median 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
