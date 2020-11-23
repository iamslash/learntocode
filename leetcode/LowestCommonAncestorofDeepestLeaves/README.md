# Problem

[Lowest Common Ancestor of Deepest Leaves](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)

# Idea

바이너리 트리의 루트 `u` 가 주어진다. 가장 깊이가 큰 노드들의 공통
조상들중 가장 깊이가 작은 노드를 구하는 문제이다.

예를 들어 다음과 같이 깊이가 가장 깊은 노드가 한 개 뿐이라면 언제나
답은 그 노드이다.

```
       1
      / \
     2   3
    /
   4 
```

그러나 다음과 같이 깊이가 가장 깊은 노드가 두개 이상이라면 
가장 깊은 노드들로 부터 루트노드 방향으로 lcs 를 찾아야 한다.

```
lcs:   1             2             1              1
  
       1             1             1              1
      / \          /   \         /   \          /   \
     2   3        2     3       2     3        2     3
                 / \           / \   / \      /       \
                4   5         4   5 6   7    4         7
```

`TreeNode* m_lcs` 를 선언하여 답을 저장한다.  `int m_maxdepth` 를
선언하여 가장 깊은 깊이를 저장하자.  그리고 다음과 같은 부분문제를
정의하고 재귀적으로 해결해보자.

```c
int dfs(TreeNode* u, int d)

     u: this node
     d: this node's depth
return: max depth
```

* `u == NULL` 이면 max depth 는 `d` 이다. `d` 를 리턴하자.
* `m_maxdepth = max(m_maxdepth, depth)` 를 수행하자.
* `int l = dfs(u->left, depth + 1)` 를 수행하자. `l` 은
  `u` 의 왼쪽 자손들중 가장 깊은 깊이를 의미한다.
* `int r = dfs(u->rigth, depth + 1)` 를 수행하자. `r` 은
  `u` 의 오른쪽 자손들중 가장 깊은 깊이를 의미한다.
* `l == m_maxdepth && r == m_maxdepth` 이면 `u` 가 곧 
  lcs 이다. `m_lcs = u` 를 수행한다.
* `max(l, r)` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(lgN)
```
