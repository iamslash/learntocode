# Problem

[Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)

수열 `nums[]` 가 주어진다. mountain array 가 되기 위해 최소로
삭제해야할 원소들의 개수를 구하라.

mountain array 는 다음을 만족하는 array 이다.

```
* arr.length >= 3

* There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
  * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
```

# Idea

예를 들어 `nums = [2,1,1,5,6,2,3,1]` 를 살펴보자.  `x = nums[i]` 라고
해보자. `x` 를 중심으로 `nums[0..i)` 의 longest increasing subsequence
를 `lis` 라고 해보자. 또한 `x` 를 중심으로 `nums(i..n)` 의 longest
decreasing subsequence 를 `lds` 라고 해보자. 

답은 `min(n - (lis + lds + 1)` 과 같다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2lgN) O(N)
```
