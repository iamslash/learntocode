# Problem

* [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)

# Idea

BST 의 루트노드 `u`, 부동소수점수 `tgt`, 정수 `k` 가 주어진다.  `tgt`
와 가까운 `k` 개의 노드들을 구하는 문제이다.

BST 를 inorder traversal 하면 오름차순으로 정렬된 수열을 얻을 수 있다.
예를 들어 BST 가 다음과 같다면 inorder traversal 은 `1 2 3 4 5` 이다.

```
    4
   / \
  2   5
 / \
1   3
```

결과값을 저장할 벡터 `vector<int> m_rslt` 를 선언하고 다음과 같은
부분문제를 정의하여 inorder traversal 로 해결한다.

```
void inorder(TreeNode* u)
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(K)
```
