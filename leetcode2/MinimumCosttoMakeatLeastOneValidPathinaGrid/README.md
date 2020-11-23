# Problem

[Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

Given 2D array `G[][]`. G's value means like these.

* 1: When left -> right, cost is 0. Otherwise cost is 1.
* 2: When right -> left, cost is 0. Otherwise cost is 1.
* 3: When    up -> down, cost is 0. Otherwise cost is 1.
* 4: When    down -> up, cost is 0. Otherwise cost is 1.

You need to find the valid path from `(0, 0)` to `(h-1, w-1)`.
Find minimum cost.

# Idea

You can solve this using BFS. Because This is a shortst path problem
and weight is 0 or 1.

The item of queue is like `{mixed-position, cost}`.

And you need to use deque instead of queue. When you push the tiem,
depending on the cost, the item must be inserted before or after of
deque.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
