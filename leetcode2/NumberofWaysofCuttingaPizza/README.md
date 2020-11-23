# Problem

[Number of Ways of Cutting a Pizza](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/)

Given 2D array `P[][]` which is consisted of `A, .` and number `k`.
Find the number of the way to cut into k pieces.  Whenever you cut the
pizza, give upper, left side to person.

# Idea

Let's take a look `P = ["A..", "AAA", "..."], k = 3`.
At first, make `G[][]`, `G[y][x]` means remained number of apples
at position `P[y][x]`.

```
P: A . .
   A A A
   . . .
   
G: 0 0 0 0    0 0 0 0    0 0 0 0    
   0 0 0 0    0 0 0 0    0 0 0 0    
   0 0 0 0    0 0 0 0    0 0 0 0
   0 0 0 0    0 0 0 0    0 0 0 0
  
   0 0 0 0    0 0 0 0    0 0 0 0    
   0 0 1 0    0 2 1 0    3 2 1 0    
   0 0 0 0    0 0 0 0    0 0 0 0
   0 0 0 0    0 0 0 0    0 0 0 0

   0 0 1 0    0 2 1 0    4 2 1 0    
   3 2 1 0    3 2 1 0    3 2 1 0    
   0 0 0 0    0 0 0 0    0 0 0 0
   0 0 0 0    0 0 0 0    0 0 0 0
```

Now you can solve this problem using dynamic programming.  Let's
define cache `C[y][x][k]`.  This is a dynamic programming equation.

```
 C[y][x][k] =
   sum(C[i][x][k-1]) (i=[y+1..h), G[y][x]-G[i][x] > 0) +
   sum(C[y][j][k-1]) (j=[x+1..w), G[y][x]-G[y][j] > 0)
```

This is a subproblem `dfs`.

```
int dfs(C[][][], G[][], int y, int x, int k)

return: the number of cases
     C: cache
     G: remained counts from P[y][x]
     y: y of position
     x: x of position
     k: remained apples
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(H^2W) O(HWK)
```
