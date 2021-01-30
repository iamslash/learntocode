# Problem

[Triangle](https://leetcode.com/problems/triangle/)

이차원 배열 `T[][]` 가 주어진다. `T[0][0]` 부터 아래 혹은 오른쪽
아래로 길을 찾는다. 비용의 합이 최소인 경로를 찾고 그 경로의 합을
구하라.

# Recusive Dynamic Programming

## Idea

```
T[i-1][j] = min(T[i][j], T[i][j+1])
```

## Implementation

* [c++11](recursive.cpp)
* [java8](Solution.java)

## Complexity

```
O(N^2) O(N^2)
```

# Recusive Dynamic Programming

## Idea

`vector<int> C(n, MAX_VAL)` 를 선언한다. 

## Implementation

* [c++11](iterative.cpp)


## Complexity

```
O(N^2) O(N^2)
```
