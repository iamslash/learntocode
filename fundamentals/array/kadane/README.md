# Problem

* [Kadane's_algorithm](https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm) 

# Idea

수열 `A[]` 가 주어진다. 연속된 부분 수열중 가장 큰 합을 구하라.

예를 들어 `A = [-2,1,-3,4,-1,2,1,-5,4]` 의 경우를 살펴보자.
`[4,-1,2,1]` 의 합이 6 이고 곧 답이된다.

`int cumMax` 를 선언한다. `A[i]`  를 포함하지 않은 누적합과 `A[i]` 를 비교하여 큰 값을 저장한다. `int glbMax` 를
선언한다. `cumMax` 들 중 최대 값을 저장한다.  

인덱스 `i` 를 선언하고 다음을 반복한다.

* `A[i]` 까지 포함된 누적합과 `A[i]` 를 비교하여 큰 값을 `cumMax` 에 저장한다.
* 지금까지의 `cumMax` 중 최대값을 `glbMax` 에 저장한다.
* `cumMax` 는 누적해서 합한 값 중 최대를 의미한다. 음수는 다음 반복에서 의미가 없다. 만약 음수이면 0 으로 초기화 한다.

모든 반복을 마치면 `globalMax` 가 답이된다.

# Implementation

* [c++](/leetcode/MaximumSubarray/a.cpp)

# Complexity

```
O(N) O(1)
```
