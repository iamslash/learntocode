# Problem

> [Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/)

수열 `tasks[][]` 가 주어진다. `tasks[i][0]` 은 i-th task 의
시작시간이다. `tasks[i][1]` 은 i-th task 의 종료시간이다.

Single-Threaded CPU 는 `tasks[][]` 를 다음과 같이 실행한다.

* CPU 의 time 은 1초씩 증가한다.
* task 의 시작시간이 CPU 의 time 보다 작거나 같으면 시작할 수 있다.
* CPU 는 가능한 task 들 중 종료시간이 빠른 것을 수행한다.
* CPU 는 task 를 시작하면 종료될 때까지 그 task 만을 수행한다.

CPU 가 처리하는 task 의 순서를 구하라.

# Idea

예를 들어 `tasks = [[1,2],[2,4],[3,2],[4,1]]` 의 경우를 살펴보자.

```
3            4 1
2          3   2
1        2       4
0      1   2

time 0 . . . . 5 . . . . 
     *
```

따라서 답은 `0 2 3 1` 이다.

`task` 의 시작시간이 CPU time 보다 작으면 시작할 수 없음을 유의하자.

`int[] ans` 를 선언하여 답을 저장한다. `int n = tasks.length` 를
선언한다. `int[][] extTasks` 를 선언하여 i-th task 의 `index, start
time, process time` 을 저장한다.

`extTasks[][]` 를 start time 의 오름차순으로 정렬한다.

`PriorityQueue<int[]> pq` 를 선언한다. `process time` 이 작은 것이
우선순위가 높다. `process time` 이 같다면 `index` 가 작은 것이
우선순위가 높다.

`int time = 0` 을 선언하여 CPU time 을 저장하자. `int ansIdx = 0` 을
선언하여 `ans[]` 의 현재 인덱스를 저장한다. `int taskIdx = 0` 을
선언하여 `extTasks[][]` 의 현재 인덱스를 저장한다.

`ansIdx < n` 동안 다음을 반복한다.

* `taskIdx < n` 이고 `extTasks[taskIdx][1] <= time` 이면 시작할 수
  있는 task 를 발견한 것이다. 즉, `pq` 에 `extTasks[taskIdx]` 를
  삽입한다. `taskIdx` 를 하나 증가한다.
* `pq` 가 비어 있다면 가능한 task 를 찾아서 그 task 의 시작시간으로
  CPU time 을 바꾼다. 그리고 반복을 건너뛴다.
* `pq` 에서 task 를 하나 가져온다. `ans[ansIdx]` 에 그 `task` 의
  인덱스를 저장한다. `ansIdx` 를 하나 증가한다. 또한 CPU time 도 task
  의 process time 만큼 증가한다.

모든 반복을 마치면 `ans[]` 가 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
