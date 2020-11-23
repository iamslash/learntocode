# Problem

[Count All Possible Routes](https://leetcode.com/problems/count-all-possible-routes/)

위치의 모음 `L[]`, 숫자 `start, finish, fuel` 이 주어진다.  `L[i]` 는
`i` 번 째 도시의 위치이다.  `start` 에서 출발하여 `finish` 까지 도착할
수 있는 경우의 수를 구하라.  이때 `fuel` 을 연료로 가지고
출발한다. 출발 인덱스가 `u` 이고 도착 인덱스가 `v` 일 때 필요한 연료는
`abs(L[u] - L[v])` 이다.

# Idea

한번 방문한 도시를 연료가 남아 있는 한 다시 방문할 수 있음을 유의하자.

다음과 같은 부분문제 `dfs` 를 정의하고 recursive dynamic programming
으로 해결할 만 하다.

```
int dfs(vector<vector<int>>& C, vector<int>& L, 
  int finish, int u, int fuel)
  
return: the number of cases
     C: the number of cases for u, fuel
finish: end index of L
     u: this index of L
  fuel: current fuel
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(LF) O(LF)
```
