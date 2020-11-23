# Problem

[Reach a Number](https://leetcode.com/problems/reach-a-number/)

# Idea

The number target is given like 3. On each move, you can either go
left or right. During the n-th move (starting from 1), you take n
steps.  Find the minimum number of steps required to reach the target.

These are sequnces for steps.

```
steps arrays
    0 0
    1 -1 1
    2 -2 -1 2 3
    3 -5 -4 -1 0 1 2 5 6
    . ...
```

The maximum value of each array is `previous maximum value + step`.
And maximum value is even, odd, odd, even, odd, odd, ... .



# Implementation

* [go](a.go)

# Complexity

```
```
