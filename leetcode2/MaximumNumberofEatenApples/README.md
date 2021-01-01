# Problem

[Maximum Number of Eaten Apples](https://leetcode.com/problems/maximum-number-of-eaten-apples/)

사과 개수의 모음 `apples[]`, 날짜의 모음 `days[]` 가 주어진다.
`apples[i]` 는 `i-th` 날짜에 자라는 사과의 개수를 의미한다.  `days[i]`
는 `i-th` 날짜에 자라는 사과의 유통기한을 의미한다.

하루에 최대 하나의 사과를 먹을 수 있다고 해보자. 최대로 먹을 수 있는
사과의 개수를 구하라.

# Idea

`priority_queue<pair<int,int>, vector<pair<int,int>>,
greater<pair<int,int>>> pq` 를 선언하여 `{end day, count of apple}` 을
저장한다. 즉, `pr = pq.top()` 에서 `pr.first` 날짜 까지 `pr.second` 만큼의
사과를 먹을 수 있다는 의미이다.

`int i = 0` 를 선언하여 `i-th` 날짜를 저장한다. `int ans = 0` 을
선언하여 먹은 사과의 개수를 저장한다.  이제 `i < n && pq.size()` 동안
다음을 반복한다.

* `i + days[i] - 1` 날짜까지 `apples[i]` 만큼의 사과를 먹을 수
  있다. 즉, `i < n && apples[i] > 0` 이면 `{i+days[i]-1, apples[i]}`
  를 `pq` 에 삽입한다.
* `pq` 의 아이템중 `pq.top().first` 가 `i` 날짜 보다 작은 
  사과들은 먹을 수 없다. 모두 제거한다.
* `pq.size()` 이면 사과를 하나 먹을 수 있다. 만약 `pq.top().second >
  1` 이면 `i` 다음날에 먹을 수 있다. `pq` 에 사과의 개수를 하나 줄여서
  저장한다. 그리고 먹은 사과의 개수를 하나 증가하자. 즉, `ans++` 를
  수행한다.
* 날짜를 하나 증가한다. 즉, `i++` 를 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
