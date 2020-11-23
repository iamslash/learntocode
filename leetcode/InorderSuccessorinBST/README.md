# Problem

* [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/)

# Idea

트리의 루트노드 `u` 와 특정노드 `p` 가 주어진다.  inorder traversal
햇을 때 `p` 다음에 오는 노드를 찾는 문제이다.

먼저 inorder traversal 이 어떤 것인지 부터 생각해보자.

```
         5
        / \  
       3   6
      / \
     2   4
    /
   1

1 2 3 4 5 6             
```
`p = 1` 이면 답은 `2` 이다.
`p = 2` 이면 답은 `3` 이다.
`p = 3` 이면 답은 `4` 이다. 
`p = 4` 이면 답은 `5` 이다. 
`p = 5` 이면 답은 `6` 이다. 
`p = 6` 이면 답은 `NULL` 이다.

다음과 같은 부분문제를 정의하고 재귀적으로 해결해보자.

```
successor(TreeNode* u, TreeNode* p)
```

* `u` 가 NULL 이면 NULL 을 리턴한다.
* `u->val <= p->val` 이면 목표 노드는 `u` 의 오른쪽 자손중
  하나이다. `successor(u->right, p)` 를 리턴한다.
* `u->val > p->val` 이면 목표 노드는 `u` 의 왼쪽 자손중 하나이거나 `u`
  자신이다. `TreeNode* l = succesor(u->left, p)` 를 수행한다. `l ==
  NULL` 이면 `u` 를 리턴하고 `l != NULL` 이면 `l` 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(lgN)
```
