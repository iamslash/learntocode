# Problem

[Eliminate Maximum Number of Monsters](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/)

수열 `dist[], speed[]` 가 주어진다. `dist[i]` 는 i-th monster 가
도시로 부터 떨어진 거리이다. `speed[i]` 는 i-th monster 의 속도이다.

monster 들이 도시로 접근하고 있다. 1 초 마다 한 마리의 monster 를
제거할 수 있다. 한 마리의 monster 라도 도시에 접근하면 도시는
파괴된다.  최대 몇 마리의 monster 를 제거할 수 있는지 구하라.

# Idea

예를 들어 `dist = [1,3,4], speed = [1,1,1]` 의 경우를 살펴보자.

```

time to arrive to the city

0-monster: 0    (dist[0]-1) / speed[0]
1-monster: 2    (dist[1]-1) / speed[1]
2-monster: 3    (dist[2]-1) / speed[2]

i: current time

               i
0-monster: x
1-monster: . x
2-monster: . . x
```

따라서 답은 `3` 이다.
 
# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(NlgN) O(1)
```
