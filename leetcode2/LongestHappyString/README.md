# Problem

[Longest Happy String](https://leetcode.com/problems/longest-happy-string/)

```
Question) You can make a string just using 'a', 'b', 'c'. Given integers `x, y, z`, Make a longest string using 'a' at most 'x' times, 'b' at most 'y' times, 'c' at most 'z' times. But You have to use same character continuously at most 2 times. If there is no such string return the empty string.

Examples)

 Input: x = 1, y = 1, z = 7
Output: "ccaccbcc"

 Input: x = 2, y = 2, z = 1
Output: "aabbc"

 Input: x = 7, y = 1, z = 9
Output: "aabaa"

Entrypoint)

func longestDiverseString(x int, y int, z int) string {
}
```

# Idea

Let's define subproblem dfs like this.

```cpp
string dfs(a, b, c int, x, y, z byte) string

return: concanteated string
     a: the count of ac
     b: the count of bc
     c: the count of cc
     x: the character which is the biggest one  
     y: the character which is the middle one  
     z: the character which is the smallest one  
```

If you keep the order `a >= b >= c`, There 3 cases like this.

* If `b == 0`, return "xx" or "x" or "".
* Else return "xx" or "xxy" or "x" or "xy".

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(N)
```
