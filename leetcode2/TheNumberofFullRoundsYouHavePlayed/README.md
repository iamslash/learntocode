# Problem

[The Number of Full Rounds You Have Played](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/)

시간을 나타내는 2 개의 문자열 `startTime, endTime` 이 주어진다. 한
시간에 4 번의 게임을 15 분 동안 할 수 있다. `startTime` 부터 24 시간
동안 `[startTime, endTime]` 에 할 수 있는 게임의 수를
구하라. `startTime > endTime` 이면 하루가 지났다고 계산하자.

# Idea

`int startQuarterMin = 0` 을 선언하여 `startTime` 보다 크고 15 분 단위로
나누어지는 시간을 분으로 저장하자. `int endQuarterMin = 0` 을 선언하여 `endTime`
보다 작고 15 분 단위로 나누어지는 시간을 분으로 저장하자. [previous, next
boundary](doc/number_theory.md#previous-next-boundary) 를 참고하자.

다음과 같은 두가지 경우가 존재한다.

```
0) startQuarterMin <= endQuarterMin

........................
0            s       e 23

duration = e - s

1) startQuarterMin > endQuarterMin

.........................
0            s          23
.........................
      e 
      
duration = 24*60 - s + e
```

# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(1) O(1)
```
