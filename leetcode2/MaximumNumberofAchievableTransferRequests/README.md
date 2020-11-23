# Problem

[Maximum Number of Achievable Transfer Requests](https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/)

숫자 `n`, 요청 `reqs[][]` 가 주어진다. 빌딩의 개수가 `n` 개
있다. `reqs[i][j]` 는 i-th 빌딩에서 j-th 빌딩으로 사람을 한명 이동시켜
달라는 요청을 나타낸다.

빌딩에 사람이 동일하게 나가고 동일하게 들어오는 최대 요청들의 개수를
구하라.

# Idea

예를 들어 `n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]` 의
경우를 살펴보자. 

```
         0 1 2 3 4
o -> 1  -1 1
1 -> 0   0 0
0 -> 1  -1 0
1 -> 2    -1 1
2 -> 0   0   0
3 -> 4        -1 1 
```

따라서 `0,1 1,0 0,1 1,2 2,0` 를 선택하면 답은 `5` 이다.

`reqs[]` 를 순회하면서 `reqs[i]` 를 선택했을 때 최대 요청의 개수와
선택하지 않았을 때 최대 요청의 개수중 최대값을 취한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
