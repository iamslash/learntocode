# Problem

[Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)

# Idea

Given an array `A`. `x` is the number when all elements are
same. `ord` is the answer.  We can make the following
equations. `minA` is the lowest element of A.

```
x * n = sum + ord * (n - 1)
    x = minA + ord
```

Finally, We can make the follwing equation.

```
  (minA + ord) * n = sum + ord * (n - 1)
minA * n + ord * n = sum + ord * n - ord
          minA * n = sum - ord
               ord = sum - minA * n
```

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
