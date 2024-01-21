# Problem

* [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

# Idea

첫번째 방법은 `maxIdx` 를 이용하는 방법이다.

- 가장 높은 높이의 인덱스를 찾아 `maxIdx` 에 저장한다.  
- `[0, maxIdx]` 동안 순회하면서 모을 수 있는 물을 답에 더한다.
- `[maxIdx, n-1]` 을 오른쪽에서 왼쪽으로 순회하면서 모을 수 있는 물을
  답에 더한다.

두번째 방법은 `leftMax, rightMax` 를 이용하는 방법이다. `maxIdx` 를
찾을 필요가 없어서 더 빠르다.

- 양 끝 인덱스를 `l, r` 에 저장한다.
- `l < r` 동안 다음을 반복한다.
  - `heights[l] <= heights[r]` 이면 오른쪽에 더 높은 벽이 있다고
    생각하고 `l` 을 전진한다.
    - 모을 수 있는 물이 있다면 답에 더한다.
  - `heights[l] > heights[r]` 이면 왼쪽에 더 높은 벽이 있다고 생각하고
    `r` 을 왼쪽으로 전진한다.
    - 모을 수 있는 물이 있다면 답에 더한다.

# Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

# Complexity

```
O(N), O(1)
```
