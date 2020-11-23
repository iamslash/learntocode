# Problem

[Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/)

수열 `A[]` 가 주어진다. 구성원의 개수가 3 개 이상이고 인접한 원소의
차이가 모두 같은 subsequnce 들의 개수를 구하라.

# Idea

예를 들어 다음과 같이 `A = [2, 4, 6, 8, 10]` 인 경우를 살펴보자.

```
                     i
         A: 2 4 6 8 10
                  j

      diff: 2
        c1: 0
        c2: 4
       ans: 8
cntMaps[0]: 
            
cntMaps[1]: 2
            1            
cntMaps[2]: 2
            3
cntMaps[3]: 2 4 6
            4 1 1
cntMaps[4]: 2 4 6 8
            5 1 1 1
```

It's so difficult to understand.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
