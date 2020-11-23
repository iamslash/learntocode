# Problem

다음과 같은 바이너리 트리에서 같은 값을 갖는 서브트리중 가장 큰
서브트리의 원소의 개수를 찾는 문제이다.

```

              0
            /   \
           1     1
          / \   / \
         1   1 2   3   
```

다음과 같은 부분문제를 정의하고 재귀적으로 구현한다.

```cpp
int dfs(TreeNode* u, TreeNode* p)

     u: this node
     p: parent node
return: count of subtree rooted with u 
        which has same value with p
```

* `u == NULL` 이면 0 을 리턴한다.
* `int l` 을 선언하고 `dfs(u->left, u)` 를 저장한다.
* `int r` 을 선언하고 `dfs(u->right, u)` 를 저장한다.
* `int sum` 을 선언하고 `l + r + 1` 를 저장한다.
* `m_maxcnt = max(m_maxcnt, sum)` 를 저장한다.
* `u->val == p->val` 이면 `sum` 을 리턴한다.
* `u->val != p->val` 이면 `0` 을 리턴한다.
