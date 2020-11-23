# Problem

[Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

# Idea

트리의 루트노드 `u` 가 주어진다. 같은 레벨의 합이 최대일 때 그 레벨을
구하는 문제이다.

BFS 를 이용하여 각 레벨의 합을 구한다. 가장 최대일 때가 곧 답이다.
BFS loop 에서 queue.size() 만큼 다시 loop 을 수행하면 간결한 코드를
만들 수 있다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
