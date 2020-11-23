# Problem

[Path Sum III](https://leetcode.com/problems/path-sum-iii/)

# Idea

You are given `u` root node of binary tree and `sum` sum of integer.
Find the number of paths that sum to given `sum`.

For example, There are `u` and `sum`.

```
sum: 8
  u:
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

output: 3

1. 5-> 3
2. 5->2->1
3. -3->11
```

Define a `dfs(u *TreeNode, sum int) int` function that traverse depth first search. It returns count of path. Eventhough find a path, `dfs` should traverse continuously. One path can include other path because of negative values.

And implement a `pathSum(u *TreeNode, sum int) int` function that returns count of paths. And It does three kinds of cases. 

* `dfs` from `u`
* `pathSum` from `u->Left`
* `pathSum` from `u->Right`

Finally `pathSum` will return count of paths.

# Implementation

* [go](a.go)

# Complexity

```
O(N^2) O(N)
```
