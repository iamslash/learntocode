# Problem

[Campus Bikes II](https://leetcode.com/problems/campus-bikes-ii/)

일꾼들의 좌표의 모음 `W[]`, 자전거들의 좌표의 모음 `B[]` 가 주어진다.
일꾼 하나에 자전거 하나를 짝지워 보자. 일꾼과 자전거까지 거리들의 합이
최소가 되도록 짝을 지워보자. 그때 그 거리의 합을 구하라.

# Idea

모든 경우의 수를 따져보고 overlapping subproblem 은 cache 로 optimize
한다. 

문제의 조건에 의해 `1 <= W.size() <= B.size() <= 10` 이다.  `int bused
= 0` 를 선언하여 사용된 자전거를 bit sequence 로 저장한다. 또한
`vector<vector<int>> C(10, vector<int>(1024))` 를 선언하여 `C[worker
index][used bike indexes] = minimum sum of distances` 를 저장한다.

다음과 같은 부분문제를 정의하고 recursive dynamic programming 으로
해결해보자.

```
int dfs(int widx, int bused)

  widx: worker index
 bused: bike used
return: minimum sum of distances from widx wokers
```

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [python3](a.py)

# Complexity

```
O(WB) O(W)
```
