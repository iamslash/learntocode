# Problem

[Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)

# Idea

두개의 비행기 번호와 예약된 좌석수의 모임 `B[]` 와 비행기의 수 `n` 이
주어진다. `B[i] = {a, b, c}` 일 때 `a` 부터 `b` 비행기 까지 `c` 개의
좌석을 예약한다. `B` 만큼 예약을 실행했을 때 `n` 개의 비행기는 각각
몇개의 좌석이 예약되었는지를 구하는 문제이다.

`vector<int> evts(n)` 를 선언하고 `B[]` 를 순회하면서 `evts[a-1] += c,
evts[b] -=c` 를 수행한다. 이제 비행기 번호순서대로 좌석수의 오르내림
정보가 모아졌다. 그리고 `int buf` 를 선언하여 `evts` 를 순회한다.
`evts[i]` 를 `buf` 에 반영하고 `ans[i]` 에 `buf` 를 저장한다.

`ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
