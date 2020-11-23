# Problem

[Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/)

# Idea

트리의 루트노드 `u` 가 주어지면 왼쪽 가장자리 노드 잎 노드 오른쪽 가장 자리 노드들의 값을
시계 반대 방향으로 구하는 문제이다.

3 단계로 접근하자. 루트 노드부터 왼쪽 가장 자리들을 수집한다.
그리고 루트노드의 왼쪽 자손들과 오른쪽 자손들의 잎노드들을 수집한다.
마지막으로 루트 노드부터 오른쪽 가장 자리들을 수집한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
