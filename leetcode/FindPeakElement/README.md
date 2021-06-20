# Problem

[Find Peak Element](https://leetcode.com/problems/find-peak-element/)

수열 `nums[]` 가 주어진다. local maximum 의 index 를 구하라.

# Idea

예를 들어 `nums = [1,2,3,1]` 의 경우를 살펴보자.

```
    .
  . .
. . . . 
0 1 2 3
```

따라서 답은 2 이다.

이 문제는 local maximum 의 값들 중 임의의 것을 선택해 그 인덱스를 구하면
답이된다. 문제의 조건에 의해 `nums[i] != nums[i+1]` 이다. 임의의 수 `nums[i]` 를
선택하고 `nums[i] > nums[i+1]` 이면 왼쪽으로 탐색한다. `nums[i] < nums[i+1]`
이면 오른 쪽으로 탐색한다. [binary
search](/fundamentals/search/binarysearch/README.md) 로 해결할 만 하다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(lgN) O(1)
```
