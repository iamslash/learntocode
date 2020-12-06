# Problem

[Lowest Common Ancestor of a Binary Tree IV](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

`TreeNode* u` 와 `TreeNode*` 들의 모임 `nodes[]` 가 주어진다.
`nodes[]` 의 lcs 를 구하라.

# Idea

[lca @ learntocode](/geeksforgeeks/LowestCommonAncestorInABinaryTree/README.md)
문제는 대부분 DFS 로 해결할 만 하다.

다음과 같은 부분문제 `dfs` 를 정의한다.

```
TreeNode* dfs(TreeNode* u, vector<TreeNode*>& nodes)

return: lcs candidate
     u: the node to visit
 nodes: decendants of lcs
```

`dfs` 는 문제에서 주어진 `lowestCommonAncestor` 와 같다.  `lcs
candidate` 은 `u, u->left, u->right` 중 하나이다. 이들 중 어느 것이
`lcs candidate` 이 될 수 있는지 조건들을 따져보면서 접근해 보자.

* `u == NULL` 이면 `lcs candidate` 은 없다. `NULL` 을 리턴한다.
* `nodes` 를 `TreeNode* v` 로 순회하면서 다음을 반복한다.
  * `v->val == u->val` 이면 `lcs candidate` 을 찾은 것이다. `u` 를
    리턴하라.
* `TreeNode* l = dfs(u->left, nodes), TreeNode* r = dfs(u->right,
  nodes)` 를 수행한다.
* `l && r` 이면 `lcs candidate` 를 찾은 것이다. `u` 를 리턴하라.
* `l` 혹은 `r` 중 `NULL` 이 아닌 것이 `lcs candidate` 이다. `u` 를
  리턴하라.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```
