# Problem

[Course Schedule III](https://leetcode.com/problems/course-schedule-iii/)

수열 `courses[][]` 가 주어진다. `courses[i][0]` 은 수업의 기간에
해당하는 날짜를 의미하고 `courses[i][1]` 은 수업을 꼭 들어야할 날짜를
의미한다. 수업을 겹치지 않고 들을 수 있을 때 그 최대 개수를 구하라.

# Idea

예를 들어, `courses = [[100, 200], [200, 1300], [1000, 1250], [2000,
3200]]` 인 경우를 살펴보자.

가장 먼저 `courses[i][1]` 의 오름 차순으로 정렬한다.

```
C: 100,200 1000,1250 200,1300 2000,3200
```

`priority_queue<int> pq` 를 선언하여 `courses[i][0]` 을 저장한다.
`pq.top()` 은 수업의 기간이 가장 긴 것의 날짜를 의미한다. `int bnd`
를 선언하여 수업을 들을 수 있는 날짜를 저장한다.

이제 `courses` 를 `course` 로 순회하면서 다음을 반복한다.

* `pq.push(course[0])` 를 수행한다.
* `bnd += course[0]` 를 수행한다.
* 한계 날짜는 `bnd` 이다. 한계 날짜까지 수업을 들을 수 없을 때 `pq`
  에서 제일 기간이 긴 녀석을 퇴출한다. 즉, `bnd > course[1]` 이면 `bnd
  -= pq.top(); pq.pop()` 을 수행한다.

모든 반복을 마치면 `pq` 에는 들을 수 있는 수업의 기간만 남게
된다. `pq.size()` 가 곧 답이다.

```
                                         i
   C: 100,200 1000,1250 200,1300 2000,3200
  pq: 100 200 1000 
 bnd: 1300
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
