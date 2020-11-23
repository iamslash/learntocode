# Problem

[All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

# References

* [All Nodes Distance K In A Binary Tree - Performing Bidirectional Search On A Tree Using A Hashtable](https://www.youtube.com/watch?v=nPtARJ2cYrg)
  * BFS 와 함께 Hash 를 이용하여 해결한다.  

# Idea

트리와 숫자 `T, K` 가 주어진다. 트리의 노드들중 `T` 노드로 부터 
`K` 만큼 떨어진 노드들을 구하는 문제이다.

루트부터 탐색을 시작한다. 루트의 왼쪽 자식으로 탐색을 하고 루트의
오른쪽 자식으로 탐색을 해야 한다. `T` 는 분명 둘 중 하나의 서브트리에
있을 것이다. 따라서 두가지 DFS 를 이용하여 해결한다.

첫번째 DFS 는 `T` 를 발견하기 전이다.
두번째 DFS 는 `T` 를 발견후이다.

다음과 같이 두가지 부분문제를 정의한다.

```
int dfs(TreeNode* u)
    u : 이번에 방문하는 노드
return: u 의 부모와 T 의 거리, 만약 없으면 -1

void dfsWithT(TreeNode* u, int dist)
    u : 이번에 방문하는 노드
 dist : T 로 부터의 거리
```

`dfsWithT` 는 구현이 쉽다. 

* `u == NULL` 이면 바로 리턴한다.
* `u->val == m_K` 이면 `m_rslt` 에 추가한다. 그리고 바로 리턴하여
  탐색을 중지한다.
* `dfsWithT(u->left), dfsWithT(u->right)` 를 수행한다.

`dfs` 는 다음과 같이 구현한다.

* `u == NULL` 이면 -1 을 리턴한다.
* `u->val == m_K` 이면 
  * `dfsWithT(u, 0)` 을 수행한다.
  * `u` 의 부모와 `T` 의 거리 1 을 리턴한다.
* `int L = dfs(u->left)` 
* `int R = dfs(u->right)`
* `L != -1` 이면 왼쪽 서브트리에 `T` 가 있다는 의미이다.
  * `L == m_K` 이면 `m_rslt` 에 `u->val` 을 추가한다.
  * `dfsWithT(u->right, L+1)` 를 수행한다.
  * `u` 의 부모와 `T` 의 거리 `L + 1` 을 리턴한다.
* `R != -1` 이면 오른쪽 서브트리에 `T` 가 있다는 의미이다.
  * `R == m_K` 이면 `m_rslt` 에 `u->val` 을 추가한다.
  * `dfsWithT(u->left, R+1)` 을 수행한다.
  * `u` 의 부모와 `T` 의 거리 `R + 1` 을 리턴한다.
* 지금까지 `T` 를 발견 못했다. -1 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
