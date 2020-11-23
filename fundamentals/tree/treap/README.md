- [Abstract](#abstract)
- [References](#references)
- [Data Structure Treap](#data-structure-treap)
- [Algorithm Search](#algorithm-search)
  - [Idea](#idea)
  - [Complexity](#complexity)
- [Algorithm Split](#algorithm-split)
  - [Idea](#idea-1)
  - [Complexity](#complexity-1)
- [Algorithm Insert](#algorithm-insert)
  - [Idea](#idea-2)
  - [Complexity](#complexity-2)
- [Algorithm Merge](#algorithm-merge)
  - [Idea](#idea-3)
  - [Complexity](#complexity-3)
- [Algorithm Erase](#algorithm-erase)
  - [Idea](#idea-4)
  - [Complexity](#complexity-4)
- [Implementation](#implementation)

-------------------------------------------------------------------------------

# Abstract

treap 에 대해 정리한다. skewed binary search tree 는 검색
효율이 좋지 않다. 검색 효율을 높이기 위해 BST 를 balanced binary search tree 로 변환 해야 한다. [AVL tree](/fundamentals/tree/avltree/README.md), [red-black tree](/fundamentals/tree/redblacktree/README.md) 는 balanced
tree 이긴 하지만 구현이 복잡하다. treap 은 구현이 간단하다. 그리고 BST 의 특성과 heap 의 특성을 가지고 있어 가능한 균형을 유지한다.

# References

* [Treap Lecture](https://courses.cs.washington.edu/courses/cse326/00wi/handouts/lecture19/sld017.htm)

# Data Structure Treap

treap 은 BST 의 특성과 heap 의 특성을 가지고 있다. treap 의
임의의 노드가 가지고 있는 key 는 그 노드의 왼쪽 자식 노드들이 가지고
있는 key 보다 크고 그 노드의 오른쪽 자식 노드들이 가지고 있는 key 보다
작다. 이것은 BST 의 특성에 해당한다. treap 의 임의의
노드는 우선순위를 가지고 있는데 항상 부모 노드 보다는 우선순위가 낮고
자식 노드 보다는 우선순위가 높다. 우선순위는 노드가 새로 만들어질 때
랜덤하게 부여된다. 랜덤하게 부여된 우선순위가 BST 의 균형을
유지하도록 도와준다.

treap 의 임의의 노드는 priority, key 를 갖는다.

# Algorithm Search

## Idea

BST 의 search 와 같다.

## Complexity

```
O(lgN) O(1)
```

# Algorithm Split

## Idea

트리를 특정 key 을 기준으로 쪼개어 두쌍의 서브트리를 리턴한다. 첫번째 서브 트리는 key 보다 작은 key 를 갖는 노드들의 모음이다. 두번째 서브 트리는 key 보다 큰 key 를 갖는 노드들의 모음이다. Split 은 Insert 에서 이용된다.

다음과 같이 부분문제를 정의하자.

```cpp
NodePair Split(Node* root, KeyType key)
```

다음과 같이 여러가지 경우를 고려해 보자.

* `root` 가 `NULL` 이면 `(NULL,NULL)` 을 리턴한다.

* `root->key` 가 `key` 보다 작은 경우는 다음과 같이 생각해 볼 수 있다. 각 경우에 대한 리턴값도 표기하였다.
  
```
key: 8

    5        5        5         5         5         5
            /          \         \       / \       / \
           3            7         9     3   7     3   9
(5, N)    (5, N)    (5, N)    (5, 9)    (5, N)    (5, 9)
```

다음은 위의 경우를 처리할 수 있는 구현이다.

```cpp
    NodePair rs = Split(root->right, key);
    root->set_right(rs.first);
    return NodePair(root, rs.second);
```    

* `root->key` 가 `key` 보다 큰 경우는 다음과 같이 생각해 볼 수 있다. 각 경우에 대한 리턴값도 표기하였다.

```
key: 2

    5       5          5         5        5         5
             \        /         /        / \       / \
              7      1         3        1   7     3   7
(N, 5)    (N, 5)    (1, 5)    (N, 5)    (1, 5)    (N, 5)
```

다음은 위의 경우를 처리할 수 있는 구현이다.

```cpp
  NodePair ls = Split(root->left, key);
  root->set_left(ls.second);
  return NodePair(ls.first, root);
```

## Complexity

```
O(lgN) O(1)
```

# Algorithm Insert

## Idea

`Node*` 를 `Node*` 에 삽입한다. 다음과 같이 부분 문제를 정의한다.

```cpp
Node* Insert(Node* u, Node* v)
```
다음과 같이 여러가지 경우를 고려해 보자.

* `u` 가 `NULL` 이면 `NULL` 을 리턴한다.

* `u->priority < v->priority` 의 경우는 `v` 가 새로운 루트가 되고 `u` 를 쪼갠 서브트리 둘을 `v` 의 자식으로 한다. 다음과 같이 수행한다.

```cpp
    NodePair splitted = Split(u, node->key);
    v->set_left(splitted.first);
    v->set_right(splitted.second);
    return v;
```

* `u->priority >= v->priority && u->key > v->key` 의 경우는 여전히 `u` 가 루트가 되어야 하고 `u->left` 에 `v` 를 삽입한다. 다음과 같이 수행한다.

```cpp
u->set_left(Insert(u->left, v));
```

* `u->priority >= v->priority && u->key <= v->key` 의 경우는 여전히 `u` 가 루트가 되어야 하고 `u->right` 에 `v` 를 삽입한다. 다음과 같이 수행한다.

```cpp
u->set_right(Insert(u->right, v));
```

## Complexity

```
O(lgN) O(1)
```

# Algorithm Merge

## Idea

두개의 서브트리를 합친다. 다음과 같이 부분문제를 정의한다.

```cpp
Node* Merge(Node* a, Node* b)
```

Erase 에서 사용된다. 특정 서브트리의 루트를 지우면 남게되는 두개의
서브트리가 각각 a, b 이다. a 를 루트로 하는 서브트리의 모든 key 는 b 를 루트로 하는 서브트리의 모든 key 보다 작다. 우선순위를 비교하여
우선순위가 더 높은 노드를 새로운 루트로 설정한다.

다음과 같이 여러가지 경우를 고려해 보자.

* `a == NULL` 인 경우는 `b` 를 리턴한다.
* `b == NULL` 인 경우는 `a` 를 리턴한다.
* `a->priority < b->priority` 인 경우는 다음과 같이 수행한다.

```cpp
    b->set_left(Merge(a, b->left));
    return b;
```

* `a->priority >= b->priority` 인 경우는 다음과 같이 수행한다.

```cpp
  a->set_right(Merge(a->right, b));
  return a;
```

## Complexity

```
O(lgN) O(1)
```

# Algorithm Erase

## Idea

특정 key 를 갖는 노드를 지운다. 다음과 같이 부분문제를 정의한다.

```cpp
Node* Erase(Node* u, KeyType key)
```

다음과 같이 여러가지 경우를 고려해 보자.

* `u == NULL` 이면 `NULL` 를 리턴한다.
* `u->key == key` 이면 다음과 같이 수행한다.

```cpp
    Node* r = Merge(u->left, u->right);
    delete u;
    return r;
```

* `u->key > key` 인 경우는 다음과 같이 수행한다.

```cpp
u->set_left(Erase(root->left, key));
return u;
```

* `u->key < key` 인 경우는 다음과 같이 수행한다.

```cpp
u->set_right(Erase(root->right, key));
return u;
```

## Complexity

```
O(lgN) O(1)
```

# Implementation 

* [c++11](a.cpp)