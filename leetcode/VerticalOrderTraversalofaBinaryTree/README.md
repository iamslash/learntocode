# Problem

[Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

# Idea

트리의 루트노드 `u` 가 주어진다. 트리의 노드들을 2D 좌표위에 놓았을 때
열 단위로 출력하는 문제이다.

맵 `map<int, map<int, set<int>> m_smp` 를 선언하고 트리의 노드들을
모두 방문하면서 좌표별 값을 기록한다. `m_smp` 는 `x, y` 의
오름차순으로 정렬되어 있다. 이때 `x, y` 같을 때의 값은 오름차순이어야
한다.

`m_smp` 를 순회하면서 `x` 별 `y` 의 모음을 답에 추가한다.

# Implementation

* [c++11](a.cpp)
* [java](MainApp.java)

# Complexity

```
O(N) O(N)
```
