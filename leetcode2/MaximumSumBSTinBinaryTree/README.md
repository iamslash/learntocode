# Problem

[Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)

Binary Tree 의 root node `u` 가 주어진다.  `u` 의 BST subtree 들 중
최대 합을 구하라.

# Idea

`int maxSum` 을 member variable 로 선언하여 답을 저장한다.

다음과 같은 부분문제 `dfs` 를 정의하고 post order traversal 로
해결한다. 

```
vector<int> dfs(TreeNode* u)

return: {minNum, maxNum, sum}
     u: node to visit
```

`u->left` 를 root 로 하는 subtree 의 `{minNum, maxNum, sum}` 을 알 수
있다.  `u->right` 를 root 로 하는 subteee 의 `{minNum, maxNum, sum}`
을 알 수 있다.  이제 `u->val` 과 비교하여 `u` 를 root 로 하는 subtree
가 BST 인지 알 수 있다. BST 가 맞다면 maxSum 을 업데이트 한다.

* [c++11](a.cpp)

# Complexity

```
O(N) O(lgN)
```
