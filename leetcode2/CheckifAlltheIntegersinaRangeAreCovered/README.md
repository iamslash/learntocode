# Problem

[Check if All the Integers in a Range Are Covered](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/)

영역의 모음 `ranges[]`, 숫자 `left, right` 가 주어진다. `[left, right]`
가 `ranges[]` 들의 일부로 덮어지는지 검증하라.

# Idea

`ranges[]` 를 `ranges[i][0]` 의 오름차순으로 정렬한다.

`range[]` 로 `ranges[]` 를 순회하면서 다음을 반복한다.

* `range[0] <= left && left <= range[1]` 이면 `left = raange[1] + 1`
   를 수행한다.
   
모든 반복을 마치면 `left > right` 가 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(1)
```
