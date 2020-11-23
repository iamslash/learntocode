# Problem

[Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

숫자 `n` 과 간선의 모음 `E[][]`, 문자열 `L` 이 주어진다.  노드 `i` 는
문자 `L[i]` 가 할당되어 있다.  `ans[i]` 는 `L[i]` 가 `i` 번 노드를
포함한 서브트리에 포함된 개수를 의미한다. `ans` 를 구하라.

# Idea

이 것은 트리가 아니다. 그래프이다.

다음과 같은 부분문제 `dfs` 를 선언하여 재귀적으로 해결한다.

```cpp
void dfs(vector<unordered_set>& G, string& L, int cnt[], vector<int>& ans, int u)

  G: graph data structure
  L: label
cnt: count of labels for u's subtree
ans: count of labels for root's subtree
  u: this node
```

제일 먼저 `vector<unordered_set> G` 를 선언하고 `E[][]` 를 이용하여
graph datastructure 를 제작한다.

`ans[u] == 0` 이면 처음 방문을 의미한다. `ans[i] = 1` 하여 다시 
방문하는 일이 업도록 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
