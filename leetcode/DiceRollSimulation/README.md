# Problem

[Dice Roll Simulation](https://leetcode.com/problems/dice-roll-simulation/)

# Idea

Given a number `n`, consecutive numbers of every each dice number `rollMax[]`.

Find the number of distinct sequences that can be obtained with exact n rolls with keeping
`rollMax[]`

Let's make the cache `C[][]`. 
`C[i][j]` means the `i`th number of distinct sequences ends with `j+1` dice number.
`C[][6]` means the sum of `C[][0..5]`.

For example, Given `n = 2, [1,1,2,2,2,3]`, This is how to process cache `C`.

```
1 1 1 1 1 1 6    1 1 1 1 1 1 6    1 1 1 1 1 1 6    1 1 1 1 1 1 6
0 0 0 0 0 0 0    5 0 0 0 0 0 5    5 5 0 0 0 010    5 5 6 0 0 016    

1 1 1 1 1 1 6    1 1 1 1 1 1 6    
5 5 6 6 0 022    5 5 6 6 6 634    

34
```

For example, Given `n = 3, [1,1,2,2,2,3]`, This is how to process cache `C`.

```
1 1 1 1 1 1 6    1 1 1 1 1 1 6    1 1 1 1 1 1 6 
0 0 0 0 0 0 0    5 5 6 6 6 634    5 5 6 6 6 634 
0 0 0 0 0 0 0    0 0 0 0 0 0 0   29 0 0 0 0 0 0 

```

Let's assume `i` is the order of trial, `j` is the number of dice. 
Then we can think 3 kinds of cases.

* `i - maxRoll[i] < 0`
  ```cpp
  C[1][2] = C[0][6]
  C[i][j] = C[i-1][6]
  ```
* `i - maxRoll[i] == 0`
  ```cpp
  C[1][0] = C[0][6] - 1
  C[i][j] = C[i-1][6] - 1
  ```
* `i - maxRoll[i] > 0`
  ```cpp
  C[2][0] = C[1][6] - (C[0][6] - C[0][0])
  C[i][j] = C[i-1][6] - (C[i-maxRoll[i]-1][6] - C[i-maxRoll[i]-1][0])
  ```

# Implementation

* [go](a.go)

# Complexity

```
O(N^2) O(N^2)
```
