# Abstract

`C[i][j]` 를 다음과 같은 방법으로 순회해 보자.

```
C[0][n-1]    C[1][n-2]    C[2][n-3]    ...    C[n-1][0]
C[0][n-2]    C[1][n-3]    C[2][n-4]    
...          ...          ...
...          ...          C[2][0]
...          C[1][0]
C[0][0]      
```

예를 들어 `n = 10` 이면 다음과 같이 순회한다.

```
i : j

0 : 9 8 7 6 5 4 3 2 1 0 
1 : 8 7 6 5 4 3 2 1 0 
2 : 7 6 5 4 3 2 1 0 
3 : 6 5 4 3 2 1 0 
4 : 5 4 3 2 1 0 
5 : 4 3 2 1 0 
6 : 3 2 1 0 
7 : 2 1 0 
8 : 1 0 
9 : 0 
```

# Problem

* [Valid Permutations for DI Sequence](/leetcode/ValidPermutationsforDISequence/README.md)

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
