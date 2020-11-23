# Problem

[Most Visited Sector in a Circular Track](https://leetcode.com/problems/most-visited-sector-in-a-circular-track/)

# Idea

예를 들어 `n = 4, R = [1, 3, 1, 2]` 가 주어진다.

```   
    A: 1 2 3 4
       -------
       -->

    R: 1 3 1 2
visit: 1 2 3 4 
       1 2
  ans: 1 2  
```

예를 들어 `n = 7, R = [1, 3, 5, 7]` 가 주어진다.

```
    A: 1 2 3 4 5 6 7
       ------------>

R: 1 3 5 7   
visit: 1 2 3 4 5 6 7
  ans: 1 2 3 4 5 6 7
```

예를 들어 `n = 2, R = [2, 1, 2, 1, 2, 1]` 가 주어진다.

```   
    A: 1 2 
         -
       ---
       ---
       >

    R: 2 1 2 1 2 1
visit:   2
       1 2
       1 2
       1
       
  ans: 1 2
```

예를 들어 `n = 7, R = [7, 5, 3, 1]` 가 주어진다.

```
    A: 1 2 3 4 5 6 7
                   -
       -------------
       -------------
       >

    R: 7 5 3 1
visit: 7 1 2 3 4 5 6 7 1 2 3 4 5 6 7 1
  ans: 1 7
```

다음과 같이 규칙을 생각해 볼 수 있다.

```
s: R[0]
e: R[len(R)-1]

if s <= e
  return [s..e]
  
if s > e
  return [1..e] + [s..n]
  
       s -- n
1 --------- n
1 --------- n
1 -- e
  
```

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
