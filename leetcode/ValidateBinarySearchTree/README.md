# Problem

	
[Validate Binary Search Tree @ leetcode](https://leetcode.com/problems/validate-binary-search-tree/description/)

# Idea

아래와 같이 다양한 경우를 생각해 보자.

* 노드 `u` 가 NULL 이면 `u` 를 루트로 하는 트리는 BST 를 만족한다.

```
NULL
```

* 노드 `u` 가 NULL 이 아니고 `u->left` 가 NULL 이면 `u->right` 를 루트로 하는 트리가 BST 를 만족한다면 `u` 를 루트로 하는 트리는 BST 를 만족한다.

```
  5
   \
    *
```

* 노드 `u` 가 NULL 이 아니고 `u->left` 가 NULL 이 아니면 `u->left` 를 루트로 하는 트리가 BST 를 만족하고 `u->left->val < u->val` 이고 `u->right` 를 루트로 하는 트리가 BST 를 만족한다면 `u` 를 루트로 하는 트리는 BST 를 만족한다.

```
   5
  / \
 1   *
```

* 노드 `u` 를 6 이라고 가정하자. 6 과 7 의 대소 비교는 노드 7 을 방문할 때 검사한다. 6 을 방문할 때는 6 의 부모의 부모인 5와 비교가 필요하다.

```
    5
   / \
  1   7
     / \
    6   9
```

앞서 언급한 경우를 고려하여 inorder traversal 을 이용하여 재귀적으로 해결해보자. 

* 노드 `u` 를 방문할 때 `u` 가 NULL 이면 `u` 를 루트로 하는 트리는 BST 를 만족 한다.

* 노드 `u` 를 방문하기 전 `u->left` 를 방문할 때 `u` 의 부모를 `p` 에 저장하고 `u->left` 를 방문한다.

* 노드 `u` 를 방문할 때 `u->left != NULL` 이면 `u->left->val < u->val` 이다. `u->left` 를 `p` 에 미리 저장해 두어야 한다.

* 노드 `u` 의 왼쪽 자식들과 `u` 를 방문했다면 `u` 를 `p` 에 저장하고 `u->right` 을 방문한다.

```
    5
   / \
  1   7
     / \
    6   9
```

| n | u | p |
|---|---|---|
| 0 | 1 | NULL |
| 1 | 5 | 1 |
| 2 | 6 | 5 |
| 3 | 7 | 6 |
| 4 | 9 | 7 |

# Implementation

[c++11](a.cpp)

# Complexity

```
O(N) 
O(1)
```