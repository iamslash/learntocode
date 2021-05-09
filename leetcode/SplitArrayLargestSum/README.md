# Problem

> * [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

수열 `V` 와 숫자 `m` 이 주어진다. `V` 를 `m` 개의 그룹으로 나눈다.
이때 각 그룹의 합들 중 가장 큰 값을 `maxsum` 이라고 하자.  `maxsum` 이
최소가 되도록 `m` 그룹으로 나누었을 때 `maxsum` 을 구하는 문제이다. 
`1 <= m <= min(50, n)` 이다. `m` 은 항상 `n` 보다 작다.

# Idea

가장 잘게 나누면 각 숫자가 하나의 그룹이 될 수 있다. 가장 큰 숫자를
`lo` 라고 하자. 모든 숫자를 합한 것을 `hi` 라고 하자.

[binary search](/fundamentals/search/binarysearch/README.md) 를
이용하여 해결할 만 하다.

함수 `validGroup(int[] nums, int maxGrp, long bndSum)` 를 정의하여
다음과 같이 구현한다.

* 부분수열의 합이 `bndSum` 보다 작게 grouping 하자. 그 그룹의 개수가
  `maxGrp` 보다 크면 false 를 리턴한다. `bndSum` 을 더욱 키워서 그룹의
  개수가 작도록 해야 한다.
* 부분수열의 합이 `bndSum` 보다 작게 grouping 하자. 그 그룹의 개수가
  `maxGrp` 보다 작거나 같으면 true 를 리턴한다. `bndSum` 을 더욱
  작게해서 그룹의 개수가 크도록 해야 한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(1)
```
