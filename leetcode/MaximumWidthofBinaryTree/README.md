# Problem

* [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)

# Idea

트리가 주어졌을 때 각 레벨의 넓이중 가장 큰 것을 구하는 문제이다.
이때 하나의 레벨을 구성하는 노드가 두개이상일때 첫 노드와 마지막 노드사이의
NULL 노드도 개수에 포함한다.

full binary tree 의 경우 루트 노드를 가 1 번 부터 시작해서 모든 노드에
번호를 붙일 수 잇다고 해보자.  그렇다면 루트 노드의 순서가 `i` 번이면
왼쪽 자식 노드는 `2 * i` 번이고 오른쪽 자식노드는 `2 * i + 1` 번이다.

BFS 를 이용하여 한 레벨을 구성하는 노드들을 처음부터 마지막까지 순회한다.
첫노드의 번호를 `l`, 마지막 노드의 번호를 `r` 이라 하면 `r - l + 1` 이
곧 그 레벨의 넓이이다.

가장큰 레벨의 넓이가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
