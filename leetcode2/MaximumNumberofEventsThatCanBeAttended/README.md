# Problem

[Maximum Number of Events That Can Be Attended Medium](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)

# Idea

이벤트의 모임 `E[][]` 가 주어진다. `E[i][0], E[i][1]` 은 구간을
표현하고 각각 시작날짜와 종료날짜를 의미한다. 임의의 이벤트는 한번
그리고 단 하루만 참여할 수 있다. 최대한 모든 이벤트를 참석했을 때 그
개수를 구하는 문제이다.

예를 들어, `E[[1,2],[2,3],[3,4]]` 의 경우를 살펴보자.

```

  E:   1 2
         2 3
           3 4
```

`1, 2, 3` 일에 참여하면 최대한 참여할 수 있고 그 개수는 3 이다.
따라서 답은 3 이다.

이벤트를 시작, 종료 시간으로 정렬후 [greedy algorithm](/doc/greedy_proof.md) 을 이용하여
해결할 만하다.

`E` 를 시작, 종료 날짜의 오름차순으로 정렬한다.
`priority_queue<int, vector<int>, greater<int>> pq` 를 선언하여 참여 가능한 이벤트의 종료날짜 를 저장한다. 인덱스 `int i, j` 를 선언하여 각각 이벤트의 번호 및 참가할 날짜를 저장한다. `int n` 을 선언하여 `E.size()` 를 저장한다. `int cnt` 를 선언하여 답을 저장한다.

그리고 `pq.size() || i < n` 동안 다음을 반복한다.

* 참여 하고 싶은 날짜 `j` 를 정한다.
  * `pq` 가 비어있지 않다면 `j` 는 정해져 있을 것이고 `pq` 가 비어있다면 새로 정하기 위해 `E[i][0]` 을 저장한다.
* 참여 가능한 이벤트의 종료날짜를 `pq` 에 삽입한다.
  * `i < n && E[i][0] <= j` 동안 `E[i][1]` 를 삽입한다.
* 이벤트를 하나 참여한다.
  * `pq` 에서 하나 꺼내고 `cnt, j` 를 하나 증가한다.
* 이제 참여 불가능한 이벤트를 `pq` 에서 제거한다.
  * `pq.size() > 0 && pq.top() < j` 인 동안 `pq.pop()` 한다.

모든 반복을 마치면 `cnt` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
