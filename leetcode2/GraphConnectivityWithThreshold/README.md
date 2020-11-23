# Problem

[Graph Connectivity With Threshold](https://leetcode.com/problems/graph-connectivity-with-threshold/)

숫자 `n, threshold` 와 질의의 모음 `Q[]` 가 주어진다.  `n` 개의 node
(1-based) 가 있다. 두 node 의 공약수중 `threshold` 보다 큰 것이 있으면
두 node 는 연결되었다고 하자. `Q[]` 의 질의를 수행한 결과를 구하라.

# Idea

1 부터 n 까지 node 들이 있고 이들을 연결된 것끼리 모아 놓으면 
쉽게 해결할 수 있다. 

[Disjoint Set](/fundamentals/disjointset/checkconnectivity/README.md) 을 이용하여 grouping 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
