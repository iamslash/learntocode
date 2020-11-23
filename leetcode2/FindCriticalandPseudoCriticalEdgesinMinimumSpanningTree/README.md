# Problem

[Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

Given number `n`, edges `E[][]`. `E[i] = [u, v, cost]`.  Find all the
critical edges, pseudo-critical edges in the minimum spanning tree
(MST).

An MST edge whose deletion from the graph would cause the MST weight
to increase is called a critical edge. A pseudo-critical edge, on the
other hand, is that which can appear in some MSTs but not all.

# Idea

Find MST using [kruskal's algorithm](/fundamentals/graph/kruskal/README.md) and let's call MST total weight as `mstTotalWeight`.

Traverse `E[][]` using index `i` and do this.

* If MST total weight increases without i-th edge, `i` is in critical edges.
* If Mst total weight is same with `mstTotalWeight` with i-th edge, `i` is in psedo-critical edges.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(E^2lgE) O(V)
```
