# Problem

[Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)

수열 `nums[]` 가 주어진다. `nums[]` 는 원래 수열을 회전시킨 것이다.
원래의 수열 non-decreasing 이었는지 검증하라.

# Idea

예를 들어 `nums = [3, 4, 5, 1, 2]` 인 경우를 살펴보자.

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `nums[i] > nums[(i+1)%n]` 이면 `cnt` 를 하나 증가한다.
* `cnt > 1` 이면 `false` 를 리턴한다.

모든 반복을 마치면 `true` 를 리턴한다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
