# Problem

[Flip Binary Tree To Match Preorder Traversal](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/)

# Idea

트리의 루트 `u` 와 숫자의 모음 `V[]` 가 주어진다.  `u` 를 최소의
숫자로 flipping 하여 preorder traversal 이 `V` 와 같아지게 해보자.
flipping 할 때 부모가 되는 노드들을 구하는 문제이다.

예를 들어 다음과 같은 트리의 경우 flipping 이 필요 없으므로 답은 `[-1]` 이다.

```
V: [2, 1]

   1
  /
 2 
```

또한 다음과 같은 트리의 경우 flipping 이 필요하므로 답은 `[1]` 이다.

```
V: [1, 3, 2]

    1
   / \
  2   3
```

트리의 문제는 대부분 재귀적으로 접근해 보자. `int m_i` 를 선언하여 `V`
의 인덱스로 사용하자. `vector<int> m_ans` 를 선언하여 flipping 할 때
부모노드의 값을 저장한다.  

다음과 같이 부분문제 `dfs` 를 정의한다.

```
bool dfs(TreeNode* u, vector<int>& V)

     u: 이번에 방문하는 노드
     V: voyage
return: m_i 까지의 preorder traversal 과 V[..m_i] 가 같은지 여부
```

위의 부분문제를 다음과 같이 구현한다.

* `u == NULL` 이면 비교 대상이 없다. true 를 리턴하자.
* `u->val != V[m_i++]` 이면 preorder traversal 이 `V` 와 같을 수
  없다. `false` 를 리턴하자.
* `u->left != NULL && u->left->val == V[m_i]` 이면 `m_i` 까지의
  preorder traversal 이 `V[..m_i]` 와 같다. `dfs(u->left, V) &&
  dfs(u->right, V)` 를 리턴하자.
* 그렇지 않으면 flipping 이 필요하기 때문에 preorder traversal 을
  오른쪽 자식노드부터 해야 한다. `m_ans.push_back(u->val)` 를 하고
  `dfs(u->right, V) && dfs(u->left, V)` 를 리턴하자.

모든 순회를 마치고 `dfs` 가 리턴하는 값이 `true` 이면 preorder
traversal 이 `V` 와 같다는 의미이므로 `m_ans` 가 답이다. 그렇지 않으면
flipping 해도 preorder traversal 이 `V` 와 같을 수 없으므로 `{-1}` 가
답이다.

다음은 `u = 1 2 3, V = 1 3 2` 의 풀이 과정이다.

```
       1
      / \
     2   3
 
                i          i
  V: 1 3 2    1 3 2    1 3 2
ans:          1        1
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V+E) O(V)
```
