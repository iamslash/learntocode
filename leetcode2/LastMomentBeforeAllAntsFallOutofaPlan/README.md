# Problem

[Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/)

다리가 놓여있다. 왼쪽, 오른쪽 방향으로 개미들이 놓여있다. 개미들은
서로 만나면 반대 방향으로 전진한다. 방향을 바꿀 때 비용은 0 이고 비용
1 에 한칸씩 전진한다. 모든 개미가 다리를 건널 때의 비용을 구하라.

# Idea

예를 들어 다음과 같이 오른쪽 방향으로 `1, 2` 번 개미가 있고
왼쪽 방향으로 `3, 4` 번 개미가 놓여있다고 해보자.

```
 1 2   3 4
 > >   < <
 . . . . .
```

`1` 번개미는 중간에 `4` 번과 만나서 돌아온다. 즉 `1` 번 개비의 전체
이동거리는 `n - 1번 위치` 이다. `4` 번 개미의 전체 이동거리는 `4번
위치` 이다.  둘 중 큰 값이 곧 답이다.

# Implementation

* [go](a.go)

# Complexity

```
O(1) O(1)
```
