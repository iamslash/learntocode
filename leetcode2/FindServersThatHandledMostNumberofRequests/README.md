# Problem

[https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/submissions/)

숫자 `k`, 수열 `arrival[], load[]` 이 주어진다. `k` 개의 server 가
있다. 그리고 `arrival.size()` 의 job 이 있다.  `arrival[i], load[i]`
는 i-th job 의 시작시간과 수행시간이다. 다음의 규칙에 따라 job 을
server 들에게 분배한다.

* 모든 server 가 busy 하면 job 은 버려진다.
* `i % k` server 가 free 하면 job 을 할당하라.
* `i % k` server 가 free 하지 않으면 `(i+1) % k` 에 할당하라.

가장 많은 job 을 처리한 서버들의 목록을 구하라.

# Idea

문제의 조건에 의해 `arrival[i] + load[i]` 는 종료시간을 의미한다.

`unordered_map<int, int> jobCntMap` 를 선언하여 `{server id : handled
job cnt}` 를 저장한다. `priority_queue<pair<int, int>,
vector<pair<int, int>>, greater<pair<int, int>>> pq;` 를 선언하여
`{job end time : server id}` 를 저장한다. 즉, 현재 처리되고 있는 job
들의 종료시간을 오름차순으로 유지한다.  `set<int> availServerSet` 를
선언하여 i-th job 을 분배할 수 있는 `server id` 를 저장한다.

모든 반복을 마치면 `jobCntMap` 에서 value 가 가장 큰 key 들이
곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```
