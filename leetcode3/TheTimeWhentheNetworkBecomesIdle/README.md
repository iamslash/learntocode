# Problem

[The Time When the Network Becomes Idle](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/)

간선의 모음 `edges[][]`, 수열 `patience[]` 가
주어진다. `patience.length` 개수의 노드가 있고 이것을 `n` 이라고
하자. 즉, 노드의 번호는 `[0..n)` 이다. 임의의 노드에서 `0` 번 노드로
메시지를 전송한다. 간선을 하나 지날 때 마다 1 unit 의 시간이 소모된다.

`0` 번 노드를 제외한 모든 노드는 `0` 번 노드로 메시지를 전송한다.  그
메시지는 `0` 번 노드에 도착하면 다시 그것을 전송했던 노드로 돌아온다.

최초 메시지를 전송했던 노드를 `u` 노드라고 하자. `u` 노드는 최초
메시지를 전송후 `patience[u]` 만큼 동안 돌아온 메시지가 없다면
`patience[u]` 시간 부터 매초 메시지를 생성한다.  최초 메시지가
돌아왔다면 그때부터 메시지 생성을 멈춘다. 단, `0` 번 노드는 메시지를
생성하지 않는다.

모든 노드들이 메시지 생성을 멈출 때의 시간을 구하라.

# Idea

예를 들어 `edges = [[0,1],[1,2]], patience = [0,2,1]` 의 경우를 살펴보자.

```

              i
   graph: 0 - 1 - 2
    dist: 0   2   4
patience: 0   2   1
lastInTs: 0   2   7
  idleTs:     3   8
```

마지막에 생성된 메시지가 돌아온 시간이 7 이므로 답은 8 이다.

이번에는 `edges = [[0,1],[1,2]], patience = [0,1,2]` 의 경우를 살펴보자.

```
              i
   graph: 0 - 1 - 2
    dist: 0   2   4
patience: 0   1   2
lastInTs: 0   3   6
  idelTs:     4   7
```

마지막에 생성된 메시지가 돌아온 시간이 6 이므로 답은 7 이다.

이번에는 `edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]` 의 경우를 살펴보자.

```
   graph:
              0
            /   \
           1 --- 2

    dist: 0   2   2
patience: 0  10  10
lastInTs: 0   2   2
  idleTs: 0   3   3
```

마지막에 생성된 메시지가 돌아온 시간이 2 이므로 답은 3 이다.

이것을 기반으로 마지막에 생성된 메시지가 돌아온 시간은 다음과 같이 계산한다.

```
lastInTs = dist + dist - patience          (dist % patience == 0)
lastInTs = dist + dist - (dist % patience) (dist % patience != 0)
```

`u` 노드가 메시지를 생성하지 않게되는 시간은 `lastInTs + 1` 이다.
따라서 모든 노드의 `lastInTs` 를 구하고 나면 `max(lastInTs) + 1` 이
답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(E+V) O(N)
```
