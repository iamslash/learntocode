# Problem

[Dynamic Connectivity | Set 1 (Incremental)](https://www.geeksforgeeks.org/dynamic-connectivity-set-1-incremental/)

입력은 다음과 같다.  첫번째 줄에 정점의 개수 `V` 와 간선의 개수 `E` 가
주어 진다. 그리고 `E` 줄 만큼 수행해야 할 작업의 종류 `T` 와 연결 해야할 두
정점 `X, Y` 가 주어 진다.

이때 `T` 가 `1` 이면 `X` 와 `Y` 가 연결되어 있는지 출력한다. 연결되어 있으면 `Yes`
그렇지 않으면 `No` 를 출력한다. `T` 가 `2` 이면 `X` 와 `Y` 를 연결 한다.

* 입력예

```
7 11
1 0 1
2 0 1
2 1 2
1 0 2
2 0 2
2 2 3
2 3 4
1 0 5
2 4 5
2 5 6
1 2 6
```

* 출력예

```
No
Yes
No
Yes
```

# Idea

[union-find](/fundamentals/disjointset/unionfind/README.md) 를 이용하면 쉽게 해결 할
수 있다.

[DFS](/fundamentals/graph/dfs/README.md) 를 이용해서 해결할 수도 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(alpha(N)) O(N)
```

alpha is [inverse Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function#Inverse)
