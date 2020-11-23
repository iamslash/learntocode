# Problem

[Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/)

간선의 모음 `E[][]` 가 주어진다. node 는 `N` 개이고 edge 역시 `N`
개이다. 그래프가 트리가 되도록 간선을 제거해 보자. 제거된 간선을
구하라. 답의 후보가 여러개일 수 있다. 마지막 것을 리턴하자.  하나만
찾으면 된다 ???

# Idea

graph 가 tree 가 되려면 모든 node 의 parent 는 하나이어야 하고 cycle
이 없어야 한다.

예를 들어, `E = [[1,2], [1,3], [2,3]]` 의 경우를 살펴보자.

```
  1
 / \
v   v
2-->3
```

`[2,3]` 을 제거하면 `1` 을 root 로 하는 tree 가 된다.

`vector<int> parent(n+1, 0)` 을 선언하여 `parent[u]` 에 `u` node 의
부모를 저장한다. `vector<int> candA, candB` 를 선언하여 제거대상 후보
간선을 저장한다.

`E[][]` 를 `e[]` 로 순회한다. `u = e[0], v = e[1]` 이라고 하자. 

* `parent[v] == 0` 이면 `v` 의 첫번째 부모는 `u` 이다. `parent[v] = u`
를 수행한다.
* `parent[v] != 0` 이면 `v` 의 추번째 부모는 `u` 이다. `candA =
  {parent[v], v}` 와 `candB = {u, v}` 를 수행한다. `v` 는 나중에
  cycle 탐색에서 제거시키기 위해 `e[1] = 0` 을 수행한다.

이제 cycle 을 탐색해 보자. `parent[i] = i` 로 초기화 한다. 

다시 `E[][]` 를 `e[]` 로 순회한다. `u = e[0], v = e[1]` 이라고
하자. 

* `v == 0` 이면 건너뛴다.
* `u` 의 최고 부모가 `v` 와 같다면 cycle 이다. `candA` 가 곧
  답이다. `candA` 가 비어있다면 `candB` 도 비어있을 것이다. `e` 가 곧
  답이다.

모든 반복을 마치면 `candB` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
