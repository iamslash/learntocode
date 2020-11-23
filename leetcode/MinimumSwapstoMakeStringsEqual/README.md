# Problem

[Minimum Swaps to Make Strings Equal](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/)

# Idea

Given two strings `a, b` which are consisted of just 'x', 'y'. You can switch `a[i]` and `b[j]`. Find the minimum number of swaps required to make `a` and `b` equal. If there is no answer return `-1`.

Let's dive deep to this example. And think with greedy algorithm. `xy` is the count of `a[i]='x', b[i]='y'`. `yx` is the count of `a[i]='y', b[i]='x'`. Everytime you swap, just ignore same characters.

```
a: xxyyxyyx
b: yxxyyxxy
ignore same chars

a: xyxyyx
b: yxyxxy
xy: 3, yx: 3
swap 1 (xy, xy), ignore same chars
 
a: yyyx
b: xxxy
xy: 1, yx: 3
swap 1 (yx, yx), ignore same chars
 
a: yx
b: xy
xy: 1, yx: 1
swap 2 (yx, xy), ignore same chars
 
a: xy
b: xy
```

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
