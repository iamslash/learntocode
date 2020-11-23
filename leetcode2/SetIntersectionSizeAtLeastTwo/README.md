# Problem

[Set Intersection Size At Least Two](https://leetcode.com/problems/set-intersection-size-at-least-two/)

간격의 모음 `I[][]` 가 주어진다. 모든 간격에 대해 최소 2 영역만큼
겹치는 최소 길이의 set 을 만들어 그 길이를 구하라.

# Idea

예를 들어, `I = [[1, 3], [1, 4], [2, 5], [3, 5]]` 의 경우를 살펴보자.
먼저 `I` 를 다음과 같이 종료 시각의 오름차순, 시작 시각의 내림차순으로
정렬한다. `int ans = 2` 를 선언하여 set 의 길이를 저장한다. `int left
= I[0][1]-1, right = I[0][1]` 를 선언하여 set 의 영역을 저장한다.

```
                                  i
   I = [1,3] [1,4] [3,5] [2,5] [7,6]
 ans =    2     2     3     3     5
left =    2     2     3     3     5
right=    3     3     5     5     6
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
