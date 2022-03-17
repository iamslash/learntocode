# Problem

[Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)

수열 `nums[]` 가 주어진다. `nums[i]` 는 `1, 0` 으로만 구성되어 있다.
모든 `1` 이 연속되게 해보자. 임의의 `1` 과 `0` 의 위치를 바꿀 수 있다.
최소 회수를 구하라. 이때 `nums[]` 는 circular array 이다.

# Idea

예를 들어 `nums = [0,1,0,1,1,0,0]` 의 경우를 살펴보자.

```
nums: 0 1 0 1 1 0 0
          1 1 1
```

따라서 답은 `1` 이다.

이번에는 `nums = [1,1,0,0,1]` 의 경우를 살펴보자.

```
nums: 1 1 0 0 1 
                1 1 0 0 1
```

따라서 답은 `0` 이다.


 
# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
