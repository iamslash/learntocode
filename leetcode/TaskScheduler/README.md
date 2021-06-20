# Problem

[Task Scheduler](https://leetcode.com/problems/task-scheduler/)

문자의 모음 `tasks[]`, 숫자 `n` 이 주어진다. `tasks[i]` 는 CPU 가
수행할 태스크를 의미한다. 하나의 태스크를 수행하는 데 1 이라는 시간을
소비한다.  같은 태스크를 수행하려면 `n` 만큼 cool time 이 필요하다.
`tasks[]` 를 모두 수행하기 위해 필요한 최소한의 시간을 구하라.

# Idea

예를 들어 `tasks = ["A","A","A","B","B","B"], n = 2` 의 경우를 살펴보자.

```
X means idle

A B X A B X A B
```

따라서 답은 8 이다.

다음과 같은 변수들을 선언한다.

* maxFreq: 가장 횟수가 많은 태스크의 출연 횟수
* unitCnt: `n` 을 고려하여 배치한 태스크 그룹의 개수
* unitLen: `n` 을 고려하여 배치한 태스크 그룹을 구성하는 원소의 개수
* slotCnt: `n` 을 고려하여 배치한 태스크들의 개수

앞서 언급한 예를 살펴보자. 태스크들의 그룹을 unit 이라고 하자. 일정한
길이의 unit 을 반복해서 배치한다. 그리고 마지막에 출현 횟수가 가장 많은
태스크 종류의 개수를 더한 것이 답이다.

```
maxFreq: 3      A A A
unitCnt: 2      A . . A . .
unitLen: 3      A . .
  batch: 6      A . . A . .
         6+2    A . . A . . A B
```

이번에는 `n == 0` 인 경우를 생각해 보자. 예를 들어 `tasks =
["A","A","A","B","B","B"], n = 0` 의 경우를 살펴보자.  idle 은 필요
없다. 따라서 `tasks.length` 가 곧 답이다.

또한 `n == 1` 인 경우를 생각해 보자. idle 없이 배치가 가능하다. 곧, `tasks.length` 가 답이다.

따라서 `batch` 와 `tasks.length` 중 큰 값이 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
