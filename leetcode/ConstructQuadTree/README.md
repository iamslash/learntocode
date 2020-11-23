# Problem

[Construct Quad Tree](https://leetcode.com/problems/construct-quad-tree/)

# Idea

`0, 1` 로만 구성된 그래프 `G[][]` 가 주어진다. 쿼드트리를 만들어
`Node*` 를 구하는 문제이다.

예를 들어 다음과 같은 경우를 살펴보자.

```
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
```

위의 그래프를 가지고 쿼드트리를 만들면 다음과 같다.
표기법은 `(isLeaf, val)` 이다. `*`  는 `T, F` 가 섞여 있다는 얘기이다.
```
                    (F, *)
             /     /      \     \
          (T, T) (F, *) (T, T) (F, *)
                    |
           /     /     \     \
       (T, F) (T, F) (T, T) (F, T)               
```

다음과 같은 부분문제를 정의하여 재귀적으로 해결할 수 있다.

```
Node* dfs(vector<vector<int>>& G, int y, int x, int d)

     G: graph
     y: row
     x: column
     d: distance
return: Quad tree node
```

* `d == 1` 이면 leaf node 를 생성하여 return 한다.
* 4 개의 leaf node 가 모두 같은 value 를 가지고 있으면 하나의 leaf node 로 merge 하고 return 한다. 
* 그렇지 않으면 4 개의 leaf node 를 자식으로 갖는 parent node 를 생성하여 return 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
