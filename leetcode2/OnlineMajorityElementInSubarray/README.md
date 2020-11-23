# Problem

[Online Majority Element In Subarray](https://leetcode.com/problems/online-majority-element-in-subarray/)

# Idea

`unordered_map<int, vector<int>> idxMap` 을 선언하여 `{number:
[indices of number]}` 를 저장한다.

예를 들어 `MajorityChecker majorityChecker = new
MajorityChecker([1,1,2,2,1,1]);` 의 경우를 살펴보자.

```
     A: 1 1 2 2 1 1
idxMap: {{1:[0,1,4,5], {2:[2,3]}}
```

query 가 `majorityChecker.query(0,5,4);` 일때의 경우를 살펴보자.
`idxMap` 을 `auto& pr` 로 순회하며 다음을 반복한다. 

* `auto& idxs = pr.second` 를 수행한다.
* `idxs.size() < threashold` 이면 건너뛴다.
* `0` 의 lower_bound 를 구하고 `5` 의 upper_bound 를 구해서 그 차이가
  `threashold` 보다 크거나 같으면 `pr.first` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
