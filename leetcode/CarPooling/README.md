# Problem

[CarPooling](https://leetcode.com/problems/car-pooling/)

# Idea

승객, 승차시각, 하차시각 의 모임 `T[]` 와 자동차의 최대 승객수 `cap`
이 주어진다. `T[]` 의 내용대로 자동차를 운행하면 승객의 숫자가 `cap`
을 초과하지 않는지 검증하는 문제이다.

문제의 조건에 의해 `0 <= T[i][1] < T[i][2] <= 1000` 이다.
`vector<int> evts(1001)` 를 선언하여 `{on time, -passenger count} or
{off time, passenger count}` 를 저장한다. 그리고 `evts` 를 순회하면서
`evts[i]` 를 `cap` 에 더하고 `cap < 0` 이면 false 를 리턴한다.

예를 들어 `T = [[2,1,5],[3,3,7]], cap = 5` 의 경우 풀이 과정이다.

```
         i            i            i            i
evts:    1 3 5 7    1 3 5 7    1 3 5 7    1 3 5 7
        -2 3 2-3   -2 3 2-3   -2 3 2-3   -2 3 2-3
 cap: 5  3            6            8            5
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
