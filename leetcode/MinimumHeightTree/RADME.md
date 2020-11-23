# Problem

[Minimum Height Trees @ leetcode](https://leetcode.com/problems/minimum-height-trees/description/)

# Idea

예를 들어서 다음과 같이 입력이 주어졌다고 해보자.

```
n = 5
edges = [[0, 2], [1, 2], [2, 3], [3, 4]]
```

위의 그래프가 만들어 낼 수 있는 트리의 모양은 다음과 같다.

```
0             1               2            3         4
 \             \             /|\          / \        |
  2             2           0 1 3        2   4       3
 / \           / \              |       / \          |
1   3         0   3             5      0   1         2
    |             |                                 / \
    4             4                                0   1
```

이들 중 높이가 가장 최소인 것은 세번째와 네번째이다.

트리의 정의에 의해 트리는 루트가 하나이다. 따라서 그래프가 주어졌을 때
루트의 후보는 최대 2개 까지 될 수 있다.  만약 루트가 3개가 가능하다고
하면 가운데 루트가 다시 유일한 루트가 되기 때문에 루트는 최대 2개라고
할만 하다.

BFS 전략을 이용하자. 가장 먼저 leaf node 후보들을 추려서 rslt 에
입력한다. leaf node 들은 indegree 가 1 인 녀석들이다. leaf node 를 `u`
라 하고 그 이웃들을 `v` 라고 하자. 간선 `v->u` 를 삭제한다. 이때 `v`
out edge 개수가 1 이면 새로운 leaf node 후보이기 때문에 queue 에
추가한다.

앞서 언급한 순회를 마치고 queue 가 비어 있다면 rslt 가 곧 루트노드들의
모음이다. 그렇지 않으면 rslt 를 q 로 저장하고 다시 반복한다.


# Implementation

[c++11](a.cpp)

# Time complexity

```
O(N)
```

# Space Complexity

```
O(N)
```

# References

* [Roots of a tree which give minimum height @ geeksforgeeks](https://www.geeksforgeeks.org/roots-tree-gives-minimum-height/)
