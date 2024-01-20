# Problem

수열 `A[]` 가 주어진다. 연속된 부분 수열중 가장 큰 합을 구하라.

# Idea

* [Kadane's_algorithm](https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm) 

예를 들어 `A = [-2,1,-3,4,-1,2,1,-5,4]` 의 경우를 살펴보자.
`[4,-1,2,1]` 의 합이 6 이고 곧 답이된다.

- `int locMax` 를 선언하여 지금까지 찾은 최대부분수열합중 최근값을 저장한다.
- `int glbMax` 를 선언하여 지금까지 찾은 최대부분수열합중 최대값을 저장한다.

`glbMax` 가 답이다.

# Implementation

[java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
