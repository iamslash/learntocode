# Problem

[Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)

수열 `nums[]` 가 주어진다. 모든 subarray 들을 한다. 각 subarray 의
최대값에서 최소값을 뺀 차이를 모두 더한 값을 구하라.

# Idea

예를 들어 `nums = [1,2,3]` 의 경우를 살펴보자.

```
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
```

따라서 답은 `0 + 0 + 0 + 1 + 1 + 2 = 4` 이다.

먼저 모든 subarray 들의 최대값들의 합을 구한다.  그리고 모든 subarray
들의 최소값들의 합을 구한다.  두 값의 차이가 곧 답이다.

모든 subarray 들의 최대값, 최소값은 [Sum of Subarray
Minimums](/leetcode/SumofSubarrayMinimums/README.md) 를 참고한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
