# Problem

[Remove Max Number of Edges to Keep Graph Fully Traversable](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/)

node 의 개수 `n` 과 간선의 모음 `E[]` 가 주어진다.  간선은 총 3 가지
종류가 있다. `E[0]` 은 간선의 종류이다. `1 | 2 | 3` 의 값으로
구성된다. `E[1], E[2]` 은 시작 node, 종료 node 이다.

* 1: Alice 만 지나갈 수 있다.
* 2: Bob 만 지나갈 수 있다.
* 3: Alice, Bob 둘 다 지나갈 수 있다.

최대 개수의 간선을 제거했음에도 모든 node 를 연결해보자.  그때 간선의
최대 개수를 구하라.

# Idea

`DisjointSet dsAlice` 와 `DisjointSet dsBob` 을 선언한다. `int ans` 를
선언하여 제거횟수를 저장한다.

`E[]` 의 `typ == 3` 인 간선들을 순회한다. `u = E[1], v = E[2]` 를
`dsAlice, dsbob` 에 대해 merge 한다. 이때 이미 merge 된 것이 있다면
`ans++` 하여 제거해야할 간선의 개수를 증가한다.

그리고 다시 `E[]` 의 `type == 1 | 2` 인 간선들을 순회한다. `type` 에
따라 `u = E[1], v = E[2]` 를 merge 한다. 만약 이미 merge 된 것이
있다면 `ans++` 하여 제거해야할 간선의 개수를 증가한다.

모든 반복을 마치면 `dsAlice.getSize(), dsBob.getSize()` 는 모두 1
이되야 한다.  `ans` 가 곧 답이다.  그렇지 않으면 `-1` 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(E) O(N)
```
