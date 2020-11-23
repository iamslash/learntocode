# Problem

[Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)

# Idea

트리의 루트노드 `TreeNode* u` 와 삭제할 노드의 값 모음 `int todel[]`
이 주어진다. `u` 에서 `todel` 의 값을 갖는 노드들을 삭제한 컴포넌트의
루트들을 구하는 문제이다.

예를 들어 `u = [1,2,3,4,5,6,7], todel = [3,5]` 인 경우를 살펴보자.

```
           1
        /     \
       2       3
     /   \   /   \ 
    4     5 6     7
```

다음과 같이 부분문제 `dfs` 를 정의하고 재귀적으로 해결하자.

```
TreeNode* dfs(TreeNode* u,
           TreeNode* p,
           std::unordered_set<int>& todel,
           std::vector<TreeNode*>& rslt)
     u: this node
     p: parent node
 todel: nodes to delete
return: NULL or u
```

* `u == NULL` 이면 NULL 을 리턴한다.
* `int bdel` 을 선언하여 `u` 가 삭제대상인지 저장한다.
* `u` 가 삭제 대상이면 자식들을 탐색할 때 `p` 를 `NULL` 로 전달해야 한다. `u` 가 삭제대상이 아니라면 `p` 를 `u` 로 전달한다.
* `u->left = dfs(u->left, p, todel, rslt)`
* `u->rigth = dfs(u->right, p, todel, rslt)`
* return `bdel ? NULL : u;`

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
