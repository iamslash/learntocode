# Problem

[Split a String Into the Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)

문자열 `s` 가 주어진다. `s` 를 unique substring 으로 분리하라.  unique
substring 의 개수는 최대가 되도록 할 때 그 갯수를 구하라.

# Idea

`dfs(s, substrSet)` 를 정의하여 backtracking 으로 해결할 만 하다.

```
int dfs(substrSet map[string]bool, s string)

   return: max number of unique substring for s
substrSet: set of substring
        s: string to split
```

예를 들어 `s = "aba"` 의 경우를 살펴보자.

```
                    dfs(abc):3
                    /    |    \  
           dfs(bc):2  dfs(c):1 dfs():1
          /   |        |    
   dfs(c):1  dfs():0  dfs():0   
     /
 dfs():0
```

# Implementation

* [go](a.go)

# Complexity

```
O(N^N) O(N)
```
