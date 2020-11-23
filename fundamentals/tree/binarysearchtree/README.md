- [Abstract](#abstract)
- [Data Structure BST](#data-structure-bst)
- [Algorithm Search](#algorithm-search)
  - [Idea](#idea)
  - [Complexity](#complexity)
- [Algorithm Insert](#algorithm-insert)
  - [Idea](#idea-1)
  - [Complexity](#complexity-1)
- [Algorithm Delete](#algorithm-delete)
  - [Idea](#idea-2)
  - [Complexity](#complexity-2)
- [Implementation](#implementation)

-----

# Abstract

이진 검색 트리에 대해 정리한다.

# Data Structure BST

다음과 같은 특성을 갖는 트리를 이진검색 트리라고 한다.

중복된 키값을 갖는 노드는 없다.  특정 노드의 왼쪽 자식노드의 키값은
부모 노드의 키값보다 작다.  특정 노드의 오른쪽 자식노드의 키값은 부모
노드의 키값보다 크다.  특정 노드의 왼쪽 자식 노드를 루트로 하는
서브트리와 오른쪽 자식 노드를 루트로 하는 서브트리는
이진검색트리이어야 한다.

# Algorithm Search

## Idea

다음과 같이 부분문제를 정의하고 재귀적으로 해결한다.

```cpp
Node* search(Node* root, int val) {
  // base condition
  if (root == NULL || root->val == val)
    return root;
  // recursion
  if (root->left)
    return search(root->left, val);
  return search(root->right, val);
}
```

## Complexity

```
O(lgN) O(1)
```

# Algorithm Insert

## Idea

다음과 같이 부분문제를 정의하고 재귀적으로 해결한다.

```cpp
Node* insert(Node* root, int val) {
  // base condition
  if (root == NULL)
    return new Node(val);
  // recursion    
  if (val < root->left)
    root->left = new Node(root->left, val);
  else
    root->right = new Node(root->right, val);
  return root
}
```

## Complexity

```
O(lgN) O(1)
```

# Algorithm Delete

## Idea

다음과 같이 부분문제를 정의하고 재귀적으로 해결하자.

```cpp
Node* delete_node(Node* t, int key)
```

* t 가 NULL 이면 NULL 을 리턴하자.
* key 가 t->val 보다 작다면 `t->left = delete_node(t->left, key)` 를 하자.
* key 가 t->val 보다 크다면 `t->right = delete_node(t->right, key` 를 하자.

* `t->val == key` 인 경우는 다음과 같이 3 가지 경우를 고려할 수 있다. `key` 는 `7` 이라고 하자.

```
    delete 7      delete 7     delete 7
      5             5            5
    /   \         /   \        /   \
   3     7       3     7      3     7
          \           /            / \
           9         6            6   9
                                     /
                                    8
```

* t 가 key 를 가지고 있고 왼쪽 자식이 없다면 t 를 delete 하고 오른쪽 자식을 리턴한다. 이 경우는 t 가 key 를 가지고 있고 양쪽 자식이 없는 경우도 해당한다.
* t 가 key 를 가지고 있고 오른쪽 자식이 없다면 t 를 delete 하고 왼쪽 자식을 리턴한다.
* t 가 key 를 가지고 있고 양쪽 자식이 있다면 오른쪽 자식들중 가장 작은 노드 u 를 t 와 교체한다. 즉 `t->val = u->val` 을 하고 `t->right = delete_node(t->right, u->val)` 를 하자.

## Complexity

```
O(lgN) O(1)
```

# Implementation

* [c++11](a.cpp)