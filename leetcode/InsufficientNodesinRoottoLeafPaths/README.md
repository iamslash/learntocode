# Problem

[Insufficient Nodes in Root to Leaf Paths](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/)

# Idea

트리의 루트노드 `u` 와 숫자 `lmt` 가 주어진다. 임의의 노드로 부터 leaf
노드 까지의 합이 `lmt` 미만 이면 그 경로에 포함되는 노드들을
삭제한다. 물론 그렇지 않은 경로에도 포함되면 삭제하지 않는다.
노드들을 삭제하고 남은 트리를 구하는 문제이다.

다음과 같은 경우를 살펴보자. `1 2 -5` 는 `-2 < -1` 이므로 삭제할
만하다.  그러나 `1 -3 4` 는 삭제할 필요가 없으므로 `2 -5` 만 삭제한다.

```
lmt: -1

         1              1
        / \              \
       2  -3             -3
      /   /              /
     -5  4              4
```

다음과 같은 부분문제 `dfs` 를 정의하고 재귀적으로 해결해보자.

```
TreeNode* dfs(TreeNode* u, int lmt)

     u: this node
   lmt: limit
return: NULL (to be deleted) or u (not to be deleted)
```

* 문제의 조건에 의해 노드의 개수는 1 보다 크다. 따라서 `u == NULL` 인
  경우를 고려할 필요는 없다.
* `u->left == NULL && u->right == NULL` 이면 leaf node 이다.
  `u->val < lmt` 를 확인해보고 삭제해야 하는지 따져보자.
* `lmt -= u->val` 을 수행한다.
* `u->left = dfs(u->left, lmt)` 을 수행한다.
* `u->right = dfs(u->right` 을 수행한다.
* `u->left == NULL && u->right == NULL` 이면 삭제해야할 경로에
  포함된다는 의미이다. `NULL` 을 리턴한다.
* `u->left != NULL || u->right != NULL` 이면 삭제하지 말아야할 경로에
  포함된다는 의미이다. `u` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(lgN)
```
