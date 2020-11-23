# Problem

[Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

# Idea

BST 의 루트노드 `u` 와 숫자 `k` 가 주어진다. 트리에서 `k` 번째 수를
찾는 문제이다.

예를 들어 다음과 같은 BST 를 살펴보자.

```
          5
        /   \ 
       3     6
      / \
     2   4 
    /
   1
```

먼저 recursive 하게 풀어보자.  inorder traversal 을 하면서 노드 `u` 를
방문할 때 마다 `k` 를 하나씩 감소하자.  만약 `k` 가 `0` 이면 `u->val` 이 답이다.

`int m_kth` 를 선언하여 `k == 0` 이면 저장한다. 그리고 바로 리턴하여
더이상의 탐색을 하지 말자.

다음은 iterative 하게 풀어보자. inorder traversal 을 하기 위해
`stack<TreeNode*> stck` 를 하나 선언한다. `TreeNode* u = h` 를 선언하여
이번에 방문하는 노드를 저장한다. 

`stck.size() || u` 인 동안 다음을 반복한다. `u` 가 `NULL` 인 경우와
`NULL` 이 아닌 경우를 각각 처리하는 것이 핵심이다.

* `u != NULL` 이면 `u` 를 `stck` 에 저장하고 왼쪽 자식을 탐색하기 위해
  `u = u->left` 를 수행한다.
* `u == NULL` 이면 `u` 의 부모 `v` 를 `stck` 에서 하나 꺼낸다. 
  `k` 를 하나 줄인다. `k == 0` 이면 `v->val` 이 답이다. `k != 0` 이면
  오른쪽 자식을 탐색하기 위해 `u = v->right` 를 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) (1)
```
