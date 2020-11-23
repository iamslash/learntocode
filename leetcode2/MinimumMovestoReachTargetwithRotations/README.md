# Problem

[Minimum Moves to Reach Target with Rotations](https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/)

# Idea

뱀은 2 칸을 차지한다. 현재 수평으로 놓여있는지 수직으로 놓여있는지가
중요하다.

예를 들어 뱀이 현재 수평으로 놓여 있다면 다음과 같은 이동이 가능하다.

* 오른쪽으로 한칸 이동

```
s s 0    0 s s
0 0 0 -> 0 0 0
```

* 아래쪽으로 한칸 이동

```
s s    0 0
0 0 -> s s
```

* 아래쪽으로 방향 전환

```
s s    s 0
0 0 -> s 0
```

뱀이 현재 수직으로 놓여 있다면 다음과 같은 이동이 가능하다.

* 아래쪽으로 한칸 이동

```
s 0    0 0
s 0    s 0
0 0 -> s 0
```

* 오른쪽으로 한칸 이동

```
s 0    0 s
s 0 -> 0 s
```

* 오른쪽으로 방향 전환

```
s 0    s s
s 0 -> 0 0
```

BFS 로 해결할 만 하다. 뱀의 꼬리의 위치를 BFS queue 에 수직여부와 함께
삽입한다. 수직과 수평의 표기는 `G[y][x]` 의 2 번 비트 3 번 비트를
활용한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V+E) O(N)
```
