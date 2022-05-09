# Problem

[The Number of the Smallest Unoccupied Chair](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/)

수열 `times[][]`, 숫자 `targetFriend` 가 주어진다. `times[i][0],
times[i][1]` 은 i-th 사람의 각각 착석시간 떠난시간을 의미한다. 의자는
`[0..n-1]` 만큼 있다. 도착한 사람은 가장 작은 인덱스의 의자를
차지한다.  `targetFriend-th` 사람이 앉을 의자를 구하라.

# Idea

사람들에게 발급할 의자의 인덱스를 오름차순으로 정렬하여 가지고 있어야
한다.

`Queue<Integer> availSeatPq = new PriorityQueue<>()` 를 선언하여
의자의 인덱스를 저장한다.

사람들이 떠날 때 마다 앉았던 의자를 반납해야 한다. 

`Queue<int[]> leaveTimePq = new PriorityQueue<>()` 를 선언하여 `[leave
time, avail seat]` 를 저장한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
