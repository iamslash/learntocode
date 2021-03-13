# Problem

[valuate Division](https://leetcode.com/problems/evaluate-division/)

간선의 모음 `E[][]`, 비용의 모음 `C[]`, 질의의 모음 `Q[][]` 가
주어진다. `E[i][0] / E[i][1] = C[i]` 와 같다. `E[][], C[]` 를 기반으로
임의의 `Q[u][v]` 에 대하여 `u / v` 의 모음을 구하라. 만약 구할 수
`u / v` 를 구할 수 없다면 `-1.0` 을 답으로 하라.

# Idea

예를 들어 `equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]`
의 경우를 살펴보자.

```
a / b = 2.0
b / c = 3.0

a / c = a / b * b / c = 6.0
b / a = (a / b)^-1 = 1.0 / 2.0 = 0.5
a / e = -1.0
a / a = 1.0
x / x = -1.0
```

따라서 답은 `[6.0,0.5,-1.0,1.0,-1.0]` 이다.

다음과 같은 규칙들을 발견할 수 있다.

> * `a / a == 1.0` 이다.
> * `a / b` 가 주어지고 `b / c` 가 주어지면 `a / c = a / b * b / c` 를 구할 수 있다.
> * `a / b` 가 주어지면 `b / a = (a / b)^-1` 이다.

`E[][], C[]` 를 이용하여 `u, v, c` 에 대한 graph 를 제작한다.


`ans[]` 를 선언하여 답을 저장한다. 인덱스 `i` 를 선언하여 `Q[]` 를 `[0..n)` 동안
순회하며 다음을 반복한다.

* `Q[i][0]` 부터 `Q[i][1]` 까지 [BFS](/fundamentals/graph/bfs/README.md) 를 하여
  지나치게 되는 모든 비용을 곱하여 `Q[i]` 의 답을 구한다.

모든 반복을 마치면 `ans[]` 를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complexity

```
O(NM) O(N)
N: number of E
M: number of Q
```
