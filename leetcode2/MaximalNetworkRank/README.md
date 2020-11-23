# Problem

[Maximal Network Rank](https://leetcode.com/problems/maximal-network-rank/)

숫자 `n` 과 간선의 모음 `E[]` 가 주어진다. `n` 개의 노드들이 `E[]`
만큼 연결되어 있다.  network rank 는 두개의 서로 다른 node 의 간선
개수의 합을 의미한다. maximal network rank 를 구하라.

# Idea

`vector<unordered_set<int>> G` 를 선언하여 `E[]` 을
저장한다. `vector<int> cnts` 를 선언하여 node 별로 연결된 간선의 수를
저장한다. `int ans = 0` 을 선언하고 maximal network rank 를 저장한다.

인덱스 `i, j` 를 이용하여 node 들의 짝을 순회하고 network rank 를 구한다.
network rank 는 다음과 같이 구한다.

```
network rank of (i, j) = cnts[i] + cnts[j] - (int)(cnts[i].count(j) > 0);
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
