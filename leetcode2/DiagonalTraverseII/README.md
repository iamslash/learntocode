# Problem

[Diagonal Traverse II](https://leetcode.com/problems/diagonal-traverse-ii/)

Given 2D array `M[][]`, Find diagonal traversed numbers.

![](sample_2_1784.png)

# Idea

y + x of every number on same diagonal line is same.  Let's define
cache `C[]` and save numbers on same diagonal to `C[y+x]`.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
